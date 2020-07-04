#include <string>
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
    token(int t) : tag(t){};
    token(token &w) : tag(w.tag){}
};
class num : public token { 
public:
    const int value;
    num(int v) : value(v), token(NUM){};
};
class word : public token {
public:
    const string lexeme;
    word(int t, string S) : lexeme(S), token(t){};
};
class floa : public token {
public:
    float value;
    floa(int first, int second) : token(FLOAT) {
        float temp = second;
        while(temp >= 1) temp /= 10;
        temp += first;
        value = temp;
    };
};
class doubleOp : public token {
public:
    const char first;
    const char second;
    doubleOp(char fi, char sec) : first(fi), second(sec), token(DOUOP){};
};

#endif