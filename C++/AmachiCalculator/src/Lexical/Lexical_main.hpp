# pragma once
# ifndef __AMI_LM__
# define __AMI_LM__

# include "Lexical_base.hpp"

AMIC_NAMESPACE_START

class Lexical_analyzer {
public:
    token::token* get_next_token();
private:
    enum DFS_state {
        START = 0, FIRST_NUM_IN = 1, INT_WAIT_DIGIT = 2, FLT_DOT_IN = 3, FLT_WAIT_DIGIT = 4, 
        OPERATOR_IN = 5, ID_WAIT_ALPHA = 6
    } current_state = START;
    std::string origin_string;
    inline char get_next_char();

    size_t next_loca = 0;
    size_t begin_loca = 0;
    size_t last_confirmed = 0; // 上次确认的开始，定位错误用

    bool state_trans();
    inline void new_segment();

    std::stack<token::token*> all_token;
    void delete_all_token();
    void error_handle();
public:
    explicit Lexical_analyzer(const std::string& _str);
    ~Lexical_analyzer();
    bool pre_process();
    int loca_error();
    inline int get_now_loca() const { return last_confirmed; };
};

Lexical_analyzer::Lexical_analyzer(const std::string& _str) : origin_string(_str) { 
    while (origin_string.back() == ' ') origin_string.pop_back();
}

token::token* Lexical_analyzer::get_next_token() {
    token::token* ret;
    if (next_loca == origin_string.size()) {
        ret = new token::token(token::end);
        all_token.push(ret);
        return ret;
    } // 句子结束
    while (this->state_trans()) { // 这东西返回false表示[begin_loca, next_loca)之间的全是正确串
        if (current_state == OPERATOR_IN) {// 立即规约运算符
            ret = new token::operator_token(
                std::string(&origin_string[begin_loca], &origin_string[next_loca]));
            this->new_segment();
            all_token.push(ret);
            return ret;
        } 
    }
    // 规约以及报错
    try {
        std::string accept_str(&origin_string[begin_loca], &origin_string[next_loca]);
        DFS_state accept_state = current_state;
        if (accept_state == FIRST_NUM_IN || accept_state == INT_WAIT_DIGIT) ret = new token::int_token(accept_str);
        else if (accept_state == FLT_WAIT_DIGIT) ret = new token::float_token(accept_str);
        else if (accept_state == ID_WAIT_ALPHA) {
            if (is_function(accept_str)) ret = new token::function_token(accept_str);
            else ret = new token::error_token(accept_str, begin_loca);
        }
        else ret = new token::error_token(accept_str, begin_loca); //其他情况
        all_token.push(ret);
        if (ret->getTokenType() == token::error) this->error_handle();
    } catch (const std::out_of_range& any) { 
        std::cout << "(Ami006) Lexical error: out of range,  add \".0\" to transfer to float token\n";
        throw AMICAL_ERROR(6, begin_loca); 
    }
    this->new_segment();
    return ret;
}

void Lexical_analyzer::error_handle() { // 恐慌模式错误恢复
    std::string _wrong_str = std::string(&origin_string[begin_loca], &origin_string[next_loca]);
    this->new_segment();
    std::cout << "(Ami001) Lexical error: ";
    this->loca_error();
    std::cout << "String:" << _wrong_str << "\n";
    next_loca++;
    throw AMICAL_ERROR(1, get_now_loca());
}

char Lexical_analyzer::get_next_char() {
    if (next_loca >= origin_string.size()) return 0;
    char current = origin_string[next_loca];
    while (next_loca < origin_string.size() && current_state == START && current == ' ') {
        begin_loca++;
        next_loca++;
        current = origin_string[next_loca];
    }
    if (next_loca == origin_string.size()) return 0;
    return current;
}

void Lexical_analyzer::new_segment() {
    last_confirmed = begin_loca;
    begin_loca = next_loca;
    current_state = START;
}

bool Lexical_analyzer::state_trans() {
    char current = get_next_char();
    if (current_state == START) {
        if (is_digit(current)) {
            current_state = FIRST_NUM_IN;
            next_loca++;
            return true;
        } else if ('.' == current) {
            current_state = FLT_DOT_IN;
            next_loca++;
            return true;
        } else if (is_oper_char(current)) {
            current_state = OPERATOR_IN;
            next_loca++;
            return true;
        } else if (is_alpha(current)) { // 顺序很重要，保证数字不会被加入idtoken中
            current_state = ID_WAIT_ALPHA;
            next_loca++;
            return true;
        } else return false; // 可直接扔语法错误
    } 
    else if (current_state == FIRST_NUM_IN) {
        if (is_digit(current)) {
            current_state = INT_WAIT_DIGIT;
            next_loca++;
            return true;
        } else if ('.' == current) {
            current_state = FLT_DOT_IN;
            next_loca++;
            return true;
        } else return false;
    } 
    else if (current_state == INT_WAIT_DIGIT) {
        if (is_digit(current)) {
            current_state = INT_WAIT_DIGIT;
            next_loca++;
            return true;
        } else if (current == '.') {
            current_state = FLT_WAIT_DIGIT;
            next_loca++;
            return true;
        }
        else return false;
    }
    else if (current_state == FLT_DOT_IN) {
        if (is_digit(current)) {
            current_state = FLT_WAIT_DIGIT;
            next_loca++;
            return true;
        } else return false;
    }
    else if (current_state == ID_WAIT_ALPHA) {
        if (is_alpha(current)) {
            current_state = ID_WAIT_ALPHA;
            next_loca++;
            return true;
        } else return false;
    }
    else if (current_state == FLT_WAIT_DIGIT) {
        if (is_digit(current)) {
            current_state = FLT_WAIT_DIGIT;
            next_loca++;
            return true;
        } else return false;
    }
    else return false;
}

void Lexical_analyzer::delete_all_token() {
    current_state = START;
    last_confirmed = 0;
    next_loca = 0;
    begin_loca = 0;
    while (!all_token.empty()) {
        delete all_token.top();
        all_token.pop();
    }
}

Lexical_analyzer::~Lexical_analyzer() {
    this->delete_all_token();
}

bool Lexical_analyzer::pre_process() {
    size_t error = 0;
    token::token* temp;
    while ((temp = this->get_next_token())->getTokenType() != token::end) {
        if (temp->getTokenType() == token::error) {
            error++;
        }
    }
    delete_all_token();
    return error == 0;
}

int Lexical_analyzer::loca_error() {
    std::cout << "\n" << origin_string << "\n";
    for (size_t i = 0; i < last_confirmed; i++) putchar(' ');
    putchar('^');
    putchar('\n');
    return last_confirmed;
}

AMIC_NAMESPACE_END

# endif