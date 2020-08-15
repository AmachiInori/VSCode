#ifndef _ACB_H_
#define _ACB_H_

#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

typedef short tokenType;
static const tokenType _NUM = 0;
static const tokenType _FLO = 1;
static const tokenType _STR = 2;
static const tokenType _CHA = 3;
static const tokenType _EQUA = 4;
static const tokenType _OPER = 5;
static const tokenType _ID = 6;
static const tokenType _RE = 7;
static const tokenType _SP = 8;

const static std::vector<std::string> __reserved = {
    "true", "false", "main", "if", "else", "goto", "switch", "while", "for",
    "do", "continue", "break", "return", "int", "float", "char", "long", "short",
    "double", "unsigned", "signed", "void", "const"
};

static std::unordered_map<char, bool> __separator = {
    {'(', true}, {')', true}, {'[', false}, {']', false}, {'{', true}, {'}', true}
};

static std::unordered_map<char, bool> __operator = {
    {'+', true}, {'-', true}, {'*', false}, {']', false}, {'{', true}, {'}', true}
};

namespace ACError {
    const static int _UNKONWN_ERROR = -1;
    const static int _LEXICAL_ERROR = 0;
    const static int _NO_MODE_MARCHED = 1;
    const static int _UNKNOWN_CHAR = 2;
}

#endif