/*
 * This is the source code of tgnet library v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Nikolai Kudashov, 2015-2018.
 */

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "base/assertion.h"
#include "FileLog.h"
#include "ConnectionsManager.h"

#ifdef ANDROID
#include <android/log.h>
#endif

#ifdef DEBUG_VERSION
bool LOGS_ENABLED = true;
bool NETWORK_LOGS_ENABLED = true;
#else
bool LOGS_ENABLED = false;
bool NETWORK_LOGS_ENABLED = false;
#endif

static void log(const char *message, const char *file, int line) {
    if (LOGS_ENABLED) DEBUG_D("%s %s %d", message, file, line);
}

FileLog &FileLog::getInstance() {
    static FileLog instance;
    return instance;
}

FileLog::FileLog() {
    pthread_mutex_init(&mutex, NULL);
    base::assertion::init(log);
}

void FileLog::init(std::string path) {
    pthread_mutex_lock(&mutex);
    if (path.size() > 0 && logFile == nullptr) {
        logFile = fopen(path.c_str(), "w");
    }
    pthread_mutex_unlock(&mutex);
}

void FileLog::close() {
    pthread_mutex_lock(&mutex);
    if (logFile != nullptr) {
        fclose(logFile);
        logFile = nullptr;
    }
    pthread_mutex_unlock(&mutex);
}

void FileLog::reset(std::string path) {
    pthread_mutex_lock(&mutex);
    if (logFile != nullptr) {
        fclose(logFile);
        logFile = nullptr;
    }
    if (path.size() > 0) {
        logFile = fopen(path.c_str(), "w");
    }
    pthread_mutex_unlock(&mutex);
}

std::string FileLog::h(uint8_t* bytes, uint32_t len, char sep) {
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

void FileLog::e(const char *message, ...) {
    if (!LOGS_ENABLED) {
        return;
    }
    va_list argptr;
    va_start(argptr, message);
    time_t t = time(0);
    struct tm *now = localtime(&t);
#ifdef ANDROID
    __android_log_vprint(ANDROID_LOG_ERROR, "tgnet", message, argptr);
    va_end(argptr);
    va_start(argptr, message);
#else
    printf("%d-%d %02d:%02d:%02d error: ", now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
    vprintf(message, argptr);
    printf("\n");
    fflush(stdout);
    va_end(argptr);
    va_start(argptr, message);
#endif
    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d error: ", now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    
    va_end(argptr);
}

void FileLog::w(const char *message, ...) {
    if (!LOGS_ENABLED) {
        return;
    }
    va_list argptr;
    va_start(argptr, message);
    time_t t = time(0);
    struct tm *now = localtime(&t);
#ifdef ANDROID
    __android_log_vprint(ANDROID_LOG_WARN, "tgnet", message, argptr);
    va_end(argptr);
    va_start(argptr, message);
#else
    printf("%d-%d %02d:%02d:%02d warning: ", now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
    vprintf(message, argptr);
    printf("\n");
    fflush(stdout);
    va_end(argptr);
    va_start(argptr, message);
#endif
    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d warning: ", now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    
    va_end(argptr);
}

void FileLog::d(const char *message, ...) {
    if (!LOGS_ENABLED) {
        return;
    }
    va_list argptr;
    va_start(argptr, message);
    time_t t = time(0);
    struct tm *now = localtime(&t);
#ifdef ANDROID
    __android_log_vprint(ANDROID_LOG_DEBUG, "tgnet", message, argptr);
    va_end(argptr);
    va_start(argptr, message);
#else
    printf("%d-%d %02d:%02d:%02d debug: ", now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
    vprintf(message, argptr);
    printf("\n");
    fflush(stdout);
    va_end(argptr);
    va_start(argptr, message);
#endif
    FILE *logFile = getInstance().logFile;
    if (logFile) {
        fprintf(logFile, "%d-%d %02d:%02d:%02d debug: ", now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
        vfprintf(logFile, message, argptr);
        fprintf(logFile, "\n");
        fflush(logFile);
    }
    
    va_end(argptr);
}
