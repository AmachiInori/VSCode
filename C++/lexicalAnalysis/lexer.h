#include "token.h"
#ifndef _LEXER_H_
#define _LEXER_H_

class lexer {
private:
    unsigned int _line = 1;
    std::unordered_map<std::string, token> _idTable;
    std::ifstream _infile;

    bool _isFirstIdChar(char c) const;
    bool _isIdChar(char c) const { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_'); }
    bool _isDigit(char c) const { return c >= '0' && c <= '9'; }
    bool _isSpera(char c) const { return __separator.find(c) != __separator.end() && __separator[c] == true; }
    bool _isCalcu(char c) const { 
        return c == '+' || c == '-' || c == '*' || c == '/' ||
        c == '%' || c == '>' || c == '<' || c == '=' || c == '!'; 
        }
    bool insertNewToken(token t);
public:
    explicit lexer(std::string fileName);
    unsigned int getLine() const { return _line; }
    std::unordered_map<std::string, token> getIdTable() const { return _idTable; }

    token getNextToken();
};

#endif