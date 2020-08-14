#include <string>
#include <iostream>
#ifndef _TOKEN_H_
#define _TOKEN_H_

typedef short tokenType;
static const tokenType _NUM = 0, _FLO = 1, _STR = 2, _CHA = 3;
static const tokenType _EQUA = 4, _COMP = 5;
static const tokenType _ID = 6, _RE = 7, _SP = 8;

class token {
public:
    tokenType tags;
    explicit token(tokenType _type) : tags(_type) {};
    virtual void printToken() { std::cout << (int)tags; }
};

class num : public token { //整形字面量
public:
    int value;
    explicit num(int _number) : token(_NUM), value(_number) {}
    void printToken() override { std::cout << "NUM " << value; }
};
class flo : public token { //浮点字面量
public:
    float value;
    explicit flo(float _number) : token(_FLO), value(_number) {}
    void printToken() override { std::cout << "FLO " << value; }
};
class str : public token { //字符串字面量
public:
    std::string value;
    explicit str(std::string const &_val) : token(_STR), value(_val) {}
    void printToken() override { std::cout << "STR " << value; }
};
class cha : public token { //字符字面量
public:
    char value;
    explicit cha(char _val) : token(_CHA), value(_val) {}
    void printToken() override { std::cout << "CHA " << value; }
};

class equa : public token { //赋值运算符 = += -=等
public:
    int type;
    explicit equa(int _type) : token(_EQUA), type(_type) {}
    void printToken() override { std::cout << "EQUA " << type; }
};
class comp : public token { //一般运算符
public:
    int type;
    explicit comp(int _type) : token(_COMP), type(_type) {}
    void printToken() override { std::cout << "COMP " << type; }
};

class id : public token { //一般标识符
public:
    std::string val;
    explicit id(std::string const &_str) : token(_ID), val(_str) {}
    void printToken() override { std::cout << "ID " << val; }
};
class re : public token { //保留字
public:
    int type;
    explicit re(int _type) : token(_RE), type(_type) {}
    void printToken() override { std::cout << "RE " << type; }
};
class sp : public token { //分隔符
public:
    char type;
    explicit sp(char _type) : token(_SP), type(_type) {}
    void printToken() override { std::cout << "SP " << type; }
};

#endif