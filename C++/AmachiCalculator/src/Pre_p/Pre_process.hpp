# pragma once
# include "../Include/Overall.h"
# ifndef __AMI_PREP__
# define __AMI_PREP__

AMIC_NAMESPACE_START

class macro_finder {
    static std::unordered_map<std::string, std::string> macro_table;
public:
    friend bool is_in_macro_table(const std::string &_str);
    friend std::string get_expand(const std::string &_str);
    friend void __insert_macro(const std::string &_macro, const std::string &_value);
};
std::unordered_map<std::string, std::string> macro_finder::macro_table = {
    {"e", "(2.718281828)"}, {"pi", "(3.141592654)"}
};
bool is_in_macro_table(const std::string &_str) {
    return macro_finder::macro_table.find(_str) != macro_finder::macro_table.end();
}
std::string get_expand(const std::string &_str) {
    return macro_finder::macro_table[_str];
}
void __insert_macro(const std::string &_macro, const std::string &_value) {
    macro_finder::macro_table[_macro] = _value;
}

class pre_processer {
private:
    static std::string __delete_enter(const std::string &_str) {
        std::string ret;
        for (size_t i = 0; i < _str.size(); i++) {
            if (_str[i] >= 32 && _str[i] <= 122) ret.push_back(_str[i]);
            else ret.push_back(' ');
        }
        return ret;
    }
    static std::string __expand_macro(const std::string &_str) {
        std::string ret;
        bool in_macro_state = false;
        std::string now_macro;
        for (size_t i = 0; i < _str.size(); i++) {
            if (!in_macro_state) {
                if (_str[i] == '#') {
                    in_macro_state = true;
                    continue;
                } else {
                    ret.push_back(_str[i]);
                }
            } else {
                if (_str[i] == '#') {
                    in_macro_state = false;
                    if (!is_in_macro_table(now_macro)) {
                        std::cout << "(Ami004) Preprocesser error: undefined macro: " << now_macro << "\n";
                        throw AMICAL_ERROR(4, i);
                    }
                    std::string transformed_string = get_expand(now_macro);
                    now_macro.clear();
                    ret += transformed_string;
                } else {
                    now_macro.push_back(_str[i]);
                }
            }
        }
        if (in_macro_state) {
            std::cout << "(Ami005) Preprocesser error: unclosed macro: " << now_macro << "\n";
            throw AMICAL_ERROR(5, _str.length() - 1);
        }
        return ret;
    }
public:
    static std::string pre_process(const std::string &_str) {
        return pre_processer::__expand_macro(pre_processer::__delete_enter(_str));
    }
};

AMIC_NAMESPACE_END

# endif
