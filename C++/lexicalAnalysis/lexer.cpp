#include "token.h"
#include <unordered_map>
#include <iostream>

class lexer {
private:
    char peek = ' ';
    int line = 1;
    std::unordered_map<string, token> hash;
    string inFileName;
public:
    lexer() { //预留字构造
        reserve(word(TRUE, "true"));
        reserve(word(FALSE, "false"));
    }
    void reserve(word w) {hash.insert({w.lexeme, w});}
    token scan() {
        std::ifstream()
    }
};