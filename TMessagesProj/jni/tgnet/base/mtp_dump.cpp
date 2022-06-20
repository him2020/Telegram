#include <map>
#include <zlib.h>
#include "scheme_flags.h"
#include "mtp_dump.h"
#include "scheme_dump.h"

bool isUtf8Text(const char* str, size_t length) {
    uint32_t bytes = 0;//UFT8可用1-6个字节编码,ASCII用一个字节
    for (size_t i = 0; i < length; ++i) {
        unsigned char chr = *(str + i);
        if (bytes == 0) {//如果不是ASCII码,应该是多字节符,计算字节数
            if (chr >= 0x80) {
                if (chr >= 0xFC && chr <= 0xFD)
                    bytes = 6;
                else if (chr >= 0xF8)
                    bytes = 5;
                else if (chr >= 0xF0)
                    bytes = 4;
                else if (chr >= 0xE0)
                    bytes = 3;
                else if (chr >= 0xC0)
                    bytes = 2;
                else
                    return false;

                bytes--;
            }
        } else if (bytes > 0) {//多字节符的非首字节,应为 10xxxxxx
            if ((chr & 0xC0) != 0x80)
                return false;

            bytes--;
        } else {
            return false;
        }
    }
    if (bytes > 0) {//违返规则,则说明不是UTF-8或ASCII
        return false;
    }

    return true;
}

std::string& replace(std::string& base, std::string src, std::string dst) {
    int32_t pos = 0, srclen = src.size(), dstlen = dst.size();
    while ((pos = base.find(src, pos)) != std::string::npos) {
        base.replace(pos, srclen, dst);
        pos += dstlen;
    }
    return base;
}

std::string bytesToHexString(const char* bytes, uint32_t len, char sep = 0) {
    static const char* hexChar = "0123456789ABCDEF";
    std::string result;
    if (len > 0) {
        if (sep != 0) {
            result.resize(len * 3 - 1);
            char *data = (char *)result.data();
            *data++ = hexChar[(bytes[0] >> 4) & 0x0F];
            *data++ = hexChar[bytes[0] & 0x0F];
            for (uint32_t i = 1; i < len; ++i) {
                *data++ = sep;
                *data++ = hexChar[(bytes[i] >> 4) & 0x0F];
                *data++ = hexChar[bytes[i] & 0x0F];
            }
        } else {
            result.resize(len << 1);
            char *data = (char *)result.data();
            for (uint32_t i = 0; i < len; ++i) {
                *data++ = hexChar[(bytes[i] >> 4) & 0x0F];
                *data++ = hexChar[bytes[i] & 0x0F];
            }
        }
    }
    return result;
}

bool DumpToTextCore(DumpToTextBuffer &to, const mtpPrime *&from, const mtpPrime *end, mtpTypeId cons, uint32_t level, mtpPrime vcons) {
    switch (mtpTypeId(cons)) {
        case mtpc_int: {
            MTPint value;
            if (value.read(from, end, cons)) {
                to.add(value.v).add(" [INT]");
                return true;
            }
        } break;

        case mtpc_long: {
            MTPlong value;
            if (value.read(from, end, cons)) {
                to.add(value.v).add(" [LONG]");
                return true;
            }
        } break;

        case mtpc_int128: {
            MTPint128 value;
            if (value.read(from, end, cons)) {
                to.add(value.h).add(" * 2^64 + ").add(value.l).add(" [LONG]");
                return true;
            }
        } break;

        case mtpc_int256: {
            MTPint256 value;
            if (value.read(from, end, cons)) {
                to.add(value.h.h).add(" * 2^192 + ").add(value.h.l).add("* 2^128 + ").add(value.l.h).add("* 2 ^ 64 + ").add(value.l.l).add(" [INT256]");
                return true;
            }
        } break;

        case mtpc_double: {
            MTPdouble value;
            if (value.read(from, end, cons)) {
                to.add(value.v).add(" [DOUBLE]");
                return true;
            }
        } break;

        case mtpc_string: {
            MTPstring value;
            if (value.read(from, end, cons)) {
                std::string strUtf8 = value.v;
                if (isUtf8Text(strUtf8.data(), strUtf8.size())) {
                    to.add("\"").add(replace(replace(replace(strUtf8, "\\", "\\\\"), "\"", "\\\""), "\n", "\\n")).add("\" [STRING]");
                } else if (strUtf8.size() < 64) {
                    to.add(bytesToHexString(strUtf8.data(), strUtf8.size(), ' ')).add(" [").add(strUtf8.size()).add(" BYTES]");
                } else {
                    to.add(bytesToHexString(strUtf8.data(), 16, ' ')).add("... [").add(strUtf8.size()).add(" BYTES]");
                }
                return true;
            }
        } break;

        case mtpc_vector: {
            if (from < end) {
                int32_t cnt = *(from++);
                to.add("[ vector<0x").add(vcons, 16).add("> (").add(cnt).add(")");
                if (cnt) {
                    to.add("\n").addSpaces(level);
                    for (int32_t i = 0; i < cnt; ++i) {
                        to.add("  ");
                        if (!DumpToTextType(to, from, end, vcons, level + 1)) {
                            return false;
                        }
                        to.add(",\n").addSpaces(level);
                    }
                } else {
                    to.add(" ");
                }
                to.add("]");
                return true;
            }
        } break;

        case mtpc_gzip_packed: {
            MTPstring packed;
            // read packed string as serialized mtp string type
            if (!packed.read(from, end)) {
                return false;
            }

            uint32_t packedLen = packed.v.size(), unpackedChunk = packedLen;
            mtpBuffer result; // * 4 because of mtpPrime type
            result.resize(0);

            z_stream stream;
            stream.zalloc = nullptr;
            stream.zfree = nullptr;
            stream.opaque = nullptr;
            stream.avail_in = 0;
            stream.next_in = nullptr;
            // int res = inflateInit2(&stream, 16 + MAX_WBITS);
            int res = inflateInit2(&stream, 15 + 32);
            if (res != Z_OK) {
                return false;
            }
            stream.avail_in = packedLen;
            stream.next_in = (unsigned char*)packed.v.data();
            stream.avail_out = 0;
            while (!stream.avail_out) {
                result.resize(result.size() + unpackedChunk);
                stream.avail_out = unpackedChunk * sizeof(mtpPrime);
                stream.next_out = (Bytef*)&result[result.size() - unpackedChunk];
                int res = inflate(&stream, Z_NO_FLUSH);
                if (res != Z_OK && res != Z_STREAM_END) {
                    inflateEnd(&stream);
                    return false;
                }
            }
            if (stream.avail_out & 0x03) {
                return false;
            }
            result.resize(result.size() - (stream.avail_out >> 2));
            inflateEnd(&stream);

            if (result.empty()) {
                return false;
            }
            const mtpPrime *newFrom = result.data(), *newEnd = result.data() + result.size();
            to.add("[GZIPPED] ");
            return DumpToTextType(to, newFrom, newEnd, 0, level);
        } break;

        default: {
            for (uint32_t i = 1; i < mtpLayerMaxSingle; ++i) {
                if (cons == mtpLayers[i]) {
                    to.add("[LAYER").add(i + 1).add("] ");
                    return DumpToTextType(to, from, end, 0, level);
                }
            }
            if (cons == mtpc_invokeWithLayer) {
                if (from >= end) {
                    return false;
                }
                int32_t layer = *(from++);
                to.add("[LAYER").add(layer).add("] ");
                return DumpToTextType(to, from, end, 0, level);
            }
        } break;
    }
    return false;
}

std::string DumpToText(const mtpPrime *&from, const mtpPrime *end) {
    DumpToTextBuffer to;
    DumpToTextType(to, from, end, mtpc_core_message);
    std::string result(to.data(), to.size());
    return result;
}
