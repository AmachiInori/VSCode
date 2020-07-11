#include <string>
#include <iostream>
#ifndef _TOKEN_H_
#define _TOKEN_H_
#define NUM 256
#define ID 257
#define TRUE 258
#define FALSE 259
#define FLOAT 260
#define DOUOP 261

using std::string;

class token {
public:
    const int tag;
    explicit token(int t = 0) : tag(t){};
    virtual void print() const { cout << tag << '\t' << "TOKEN" << '\t' << (char)tag << endl; };
};
class num : public token { 
public:
    const int value;
    explicit num(int v) : value(v), token(NUM){};
    void print() const override { cout << tag << '\t' << "INTGE" << '\t' << value << endl; }
};
class word : public token {
public:
    const string lexeme;
    explicit word(int t, string S) : lexeme(S), token(t){};
    void print() const override { cout << tag << '\t' << "WORDS" << '\t' << lexeme << endl; }
};
class floa : public token {
public:
    float value;
    floa(int first, int second) : token(FLOAT) {
        float temp = second;
        while(temp >= 1) temp /= 10;
        temp += first;
        value = temp;
    }
    void print() const override { cout << tag << '\t' << "FLOAT" << '\t' << value << endl; }
};
class doubleOp : public token {
public:
    const char first;
    const char second;
    doubleOp(char fi, char sec) : first(fi), second(sec), token(DOUOP){};
    void print() const override { cout << tag << '\t' << "DOUOP" << '\t' << first << second << endl; }
};

#endif