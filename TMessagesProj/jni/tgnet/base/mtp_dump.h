#pragma once
#include <inttypes.h>
#include "core_types.h"
#include "../NativeByteBuffer.h"

enum {
    // compatible
    mtpc_account_registerDevice_71 = 0x637ea878,
    mtpc_channels_getMessages_76 = 0x93d7b347,
    mtpc_messages_getStickerSet_134 = 0x2619a90e
};

class DumpToTextBuffer {
public:
    const uint32_t kBufferSize = 256 * 1024; // 256k start size

    DumpToTextBuffer()
            : buffer(new NativeByteBuffer(kBufferSize)){
    }
    ~DumpToTextBuffer() {
        if (buffer != nullptr) {
            delete buffer;
            buffer = nullptr;
        }
    }

    DumpToTextBuffer &add(double v) {
        char number[64];
        int len = std::sprintf(number, "%f", v);
        number[len] = 0;
        return add(number, len);
    }

    DumpToTextBuffer &add(uint64_t v, int32_t bitSize = 10) {
        int len = 0;
        char number[64];
        if (bitSize == 16) {
            len = std::sprintf(number, "%" PRIx64, v);
        }  else {
            len = std::sprintf(number, "%" PRIu64, v);
        }
        number[len] = 0;
        return add(number, len);
    }

    DumpToTextBuffer &add(int64_t v, int32_t bitSize = 10) {
        int len = 0;
        char number[64];
        if (bitSize == 16) {
            len = std::sprintf(number, "%" PRIx64, v);
        }  else {
            len = std::sprintf(number, "%" PRId64, v);
        }
        number[len] = 0;
        return add(number, len);
    }

    DumpToTextBuffer &add(int32_t v, int32_t bitSize = 10) {
        int len = 0;
        char number[64];
        if (bitSize == 16) {
            len = std::sprintf(number, "%x", v);
        }  else {
            len = std::sprintf(number, "%d", v);
        }
        number[len] = 0;
        return add(number, len);
    }

    DumpToTextBuffer &add(uint32_t v, int32_t bitSize = 10) {
        int len = 0;
        char number[64];
        if (bitSize == 16) {
            len = std::sprintf(number, "%x", v);
        }  else {
            len = std::sprintf(number, "%u", v);
        }
        number[len] = 0;
        return add(number, len);
    }

    DumpToTextBuffer &add(const std::string &data) {
        return add(data.c_str(), data.length());
    }

    DumpToTextBuffer &add(const char *data, int32_t len = -1) {
        if (len < 0) len = strlen(data);
        if (!len) return (*this);

        ensureLength(len);
        buffer->writeBytes((uint8_t*)data, len);
        return (*this);
    }

    DumpToTextBuffer &addSpaces(int32_t level) {
        int32_t len = level * 2;
        if (!len) return (*this);

        ensureLength(len);
        for (int32_t i=0; i < len; i++) {
            buffer->writeByte(' ');
        }
        return (*this);
    }

    DumpToTextBuffer &error(const char *problem = "could not decode type") {
        return add("[ERROR] (").add(problem).add(")");
    }

    DumpToTextBuffer &error(mtpTypeId type, const char *problem = "could not decode type") {
        return add("[ERROR] (").add(problem).add(" 0x").add(type, 16).add(")");
    }

    const char* data() {
        if (buffer == nullptr) {
            return nullptr;
        }

        return (const char*)buffer->data();
    }

    uint32_t size() {
        if (buffer == nullptr) {
            return 0;
        }

        return buffer->size();
    }

    void ensureLength(uint32_t add) {
        if (buffer->position() + add <= buffer->limit()) return;

        uint32_t newsize = buffer->position() + add;
        if (newsize % kBufferSize) {
            newsize += kBufferSize - (newsize % kBufferSize);
        }
        NativeByteBuffer *b = new NativeByteBuffer(newsize);
        b->writeBytes(buffer);
        delete buffer;
        buffer = b;
    }

private:
    NativeByteBuffer* buffer;
};

bool DumpToTextCore(DumpToTextBuffer &to, const mtpPrime *&from, const mtpPrime *end, mtpTypeId cons, uint32_t level, mtpPrime vcons);
