#include "lexer.h"

lexer::lexer(std::string& fileName) 
    : _infile(fileName) {
    for (int i = 0; i < __reserved.size(); i++)
        _idTable[__reserved[i]] = re(i);
}

bool lexer::_isFirstIdChar(char c) const {
    if (_isIdChar(c))
        if (!_isDigit(c))
            return true;
    return false;
}

bool lexer::insertNewToken(id const &t) {
    if (_idTable.find(t.val) == _idTable.end()) {
        _idTable[t.val] = t;
        return true;
    } else return false;
}

token lexer::getNextToken() {

}