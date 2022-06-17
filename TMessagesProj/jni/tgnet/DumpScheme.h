// WARNING! All changes made in this file will be lost!
// Created from 'mtproto.tl', 'api.tl' by 'generate.py'
//
#pragma once

#include <inttypes.h>
#include <vector>
#include "base/core_types.h"
#include "NativeByteBuffer.h"

std::string DumpToText(const mtpPrime *&from, const mtpPrime *end);

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

    DumpToTextBuffer &add(uint64_t v) {
        char number[32];
        int len = std::sprintf(number, "%" PRIu64, v);
        number[len] = 0;
        return add(number, len);
    }

    DumpToTextBuffer &add(uint64_t v, int32_t bitSize) {
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

    DumpToTextBuffer &add(const std::string &data) {
        return add(data.c_str(), data.length());
    }

    DumpToTextBuffer &add(const char *data, int32_t len = -1) {
        if (len < 0) len = strlen(data);
        if (!len) return (*this);

        ensureLength(len);
        memcpy(buffer->bytes() + buffer->position(), data, sizeof(uint8_t) * len);
        buffer->position(buffer->position() + len);
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
        b->writeByteArray(buffer);
        delete buffer;
        buffer = b;
    }

private:
    NativeByteBuffer* buffer;
};

bool DumpToTextCore(DumpToTextBuffer &to, const mtpPrime *&from, const mtpPrime *end, mtpTypeId cons, uint32_t level, mtpPrime vcons = 0);
bool DumpToTextType(DumpToTextBuffer &to, const mtpPrime *&from, const mtpPrime *end, mtpPrime cons = 0, uint32_t level = 0, mtpPrime vcons = 0);
