# pragma once
# include "../Overall.h"

AMIC_NAMESPACE_START

template <class key, class value>
using hash = std::unordered_map<key, value>;

template <class key>
using set = std::set<key>;

class functions {
    static hash<std::string, double(*)(double)> func_table;
    static inline double sin(double x) { return std::sin(x); }
    static inline double cos(double x) { return std::cos(x); }
};
hash<std::string, double(*)(double)> functions::func_table = {
    {"sin", functions::sin}, {"cos", functions::cos}
};

class Lexical_base {
    static set<char> oper_char_table;
    static inline bool is_digit(char _c) { return _c >= '0' && _c <= '9'; }
    static inline bool is_alpha(char _c) { return _c >= 'a' && _c <= 'z'; }
};
set<char> Lexical_base::oper_char_table = {'+', '-', '*', '/', '%', '(', ')'};



namespace token {

enum token_type {error = -1, end = 0, num = 1, flo = 2, oper = 3, function = 4};

class token {
protected:
    token_type type;
public:
    explicit token(token_type tt = token_type(0)) : type(tt) {}; 
    inline token_type getTokenType() { return type; }
    virtual void printToken() { std::cout << (int)type << ' ' << "baseToken\n"; }
};

class intToken final: public token {
    int64_t value = 0;
    bool isGoodNumber = true;
public:
    explicit intToken(const std::string &_exV) : token(num) {
        for (size_t i = (_exV.front() == '-' || _exV.front() == '+') ? 1 : 0; i < _exV.length(); i++) {
            if (value > LLONG_MAX / 10.0) isGoodNumber = false;
            value *= 10;
            value += _exV[i] - '0';
        }
        if (_exV.front() == '-') value *= -1;
    }
    explicit intToken(const int64_t _int) : value(_int) { }

    void printToken() override { 
        if (!isGoodNumber) std::cout << "warning: overflow ";
        std::cout << (int)type << ' ' << (int)value << ' ' << value << ' ' << "intToken\n"; 
    }
    inline int64_t getValueNum() { 
        if (isGoodNumber) {
            return value;
        } else {
            
        }
    }
};

class floatToken final : public token {
    double_t value = 0;
    bool isGoodNumber = true;
public:
    explicit floatToken(const std::string &_exV) : token(flo) { // 词法分析器保证传入这一token的串一定有句点
        double_t res = 0;
        double_t floatRes = 0;
        size_t dotLoca = 0;
        int32_t eLoca = -1;
        for (size_t i = 0; i < _exV.length(); i++) { // 此模块未做溢出修正
            if (_exV[i] == '.') {
                dotLoca = i;
            } else if (_exV[i] == 'e' || _exV[i] == 'E') {
                eLoca = i;
            }
        }
        for (size_t i = (_exV.front() == '-' || _exV.front() == '+') ? 1 : 0; i < dotLoca; i++) {
            if (value > DBL_MAX / 10.0) isGoodNumber = false;
            res *= 10;
            res += _exV[i] - '0';
        }
        for (size_t i = ((eLoca == -1) ? _exV.size() : eLoca) - 1; i > dotLoca; i--) {
            floatRes += _exV[i] - '0';
            floatRes /= 10;
        }
        res += floatRes;
        if (eLoca != -1) { // E后的文法规约是整数
            int32_t indexRes = 0;
            for (size_t i = eLoca + ((_exV[eLoca + 1] == '+' || _exV[eLoca + 1] == '-') ? 2 : 1); i < _exV.size(); i++) {
                indexRes *= 10;
                indexRes += _exV[i] - '0';
            }
            if (_exV[eLoca + 1] == '-') indexRes *= -1;
            if (res > DBL_MAX / pow(10, std::max(indexRes, 1))) isGoodNumber = false;
            res = res * pow(10, indexRes);
        }
        value = res;
    }
    void printToken() override { 
        if (!isGoodNumber) std::cout << "warning: overflow ";
        std::cout << (int)type << ' ' << value << ' ' << "fltToken\n"; 
    }
    inline double_t getValueNum() { 
        if (isGoodNumber) {
            return value;
        } else {
            
        }
    }
};

};//namespace token 

AMIC_NAMESPACE_END