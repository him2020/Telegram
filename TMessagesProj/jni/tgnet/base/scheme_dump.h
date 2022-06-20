// WARNING! All changes made in this file will be lost!
// Created from 'mtproto.tl', 'api.tl' by 'generate.py'
//
#pragma once

#include <string>
#include "types.h"

class DumpToTextBuffer;

bool DumpToTextType(DumpToTextBuffer &to, const mtpPrime *&from, const mtpPrime *end, mtpPrime cons = 0, uint32 level = 0, mtpPrime vcons = 0);
std::string DumpToText(const mtpPrime *&from, const mtpPrime *end);
