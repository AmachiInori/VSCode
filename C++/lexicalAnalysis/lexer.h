#ifndef _LEXER_H_
#define _LEXER_H_
#include "token.h"
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class lexer {
private:
    char peek = ' ';
    int line = 1;
    unordered_map<string, token> hash;
    vector<token> res;
    string inFileName;
    void reserve(word w) { hash.insert({w.lexeme, w}); }
    bool isDigit(char c) { return (c >= '0' && c <= '9'); }
    bool isLetter(char c) { return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'); }
    bool isOperator(char c) { return (c == '=' || c == '>' || c == '<' || c == '+' || 
        c == '-' || c == '*' || c == '/' || c == '!'); }
public:
    lexer(string fileName) : inFileName(fileName) { //预留字构造
        hash = *new unordered_map<string, token>;
        res = *new vector<token>;
        reserve(word(TRUE, "true"));
        reserve(word(FALSE, "false"));
    }
    void scan() {
        ifstream ifs(inFileName);
        while(!ifs.eof()) {
            while (peek = ifs.get()) { //至少执行一次
                if (peek == ' ' || peek == '\t') continue;
                else if (peek == '\n') line++;
                else if (peek == '/' && ifs.peek() == '/') {
                    while (peek = ifs.get()) {
                        if (peek == '\n') {
                            ifs.get();
                            break;
                        }
                        else continue;
                    }
                }
                else if (peek == '/' && ifs.peek() == '*') {
                    peek = ifs.get();
                    while (peek = ifs.get()) {
                        if (peek == '*' && ifs.peek() == '/') {
                            for (int i = 0; i < 2; i++) ifs.get();
                            break;
                        }
                        else continue;
                    }
                }
                else break;
            }
            if (isDigit(peek)) {
                int value = peek - '0';
                while (peek = ifs.get()) {
                    if (isDigit(peek)) {
                        value *= 10;
                        value += peek - '0';
                    }else if (peek == '.') {
                        int secondValue = 0;
                        while (peek = ifs.get()) {
                            if (isDigit(peek)) {
                                secondValue *= 10;
                                secondValue += peek - '0';
                            }else break;
                        }
                        floa* tempF = new floa(value, secondValue);
                        res.push_back(*tempF);
                    }else {
                        num* tempN = new num(value);
                        res.push_back(*tempN);
                    }
                }
            }
            if (isLetter(peek)) {
                stringstream stringBuffer;
                while (isLetter(peek) || isDigit(peek)) {
                    stringBuffer << peek;
                    peek = ifs.get();
                }
                if (hash.find(stringBuffer.str()) != hash.end()) res.push_back(hash[stringBuffer.str()]);
                else {
                    word* tempW = new word(ID, stringBuffer.str());
                    res.push_back(*tempW);
                    reserve(*tempW);
                }
            }
            if (isOperator(peek)) {
                if (ifs.peek() == '=') {
                    doubleOp* tempDO = new doubleOp(peek, ifs.peek());
                    for (int i = 0; i < 2; i++) ifs.get();
                    res.push_back(*tempDO);
                }else {
                    token* tempT = new token(peek);
                    res.push_back(*tempT);
                    ifs.get();
                }
            }
        }
    }
    void printRes() { for (int i = 0; i < res.size(); i++) res[i].print(); }
};

#endif