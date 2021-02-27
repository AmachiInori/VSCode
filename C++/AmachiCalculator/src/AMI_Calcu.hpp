# pragma once
# ifndef __AMI_CALCU__
# define __AMI_CALCU__

# include "Pre_p/Pre_process.hpp"
# include "Tree_Process/Tree_Process_main.hpp"
# include "Parser/Parser_main.hpp"
# include <sstream>

AMIC_NAMESPACE_START

double __main_process(const std::string& _expr) {
    switch (1) {
    case 1:
        std::string after_pp;
        after_pp = AMIC_NAMESPACE::pre_processer::pre_process(_expr); 
        AMIC_NAMESPACE::Lexical_analyzer le_ana(after_pp);
        if (!le_ana.pre_process()) break;
        AMIC_NAMESPACE::Parser par_test(&le_ana);
        AMIC_NAMESPACE::T_node::tree_node* target_tree;
        if (!(target_tree = par_test.get_parser_tree()))
            break;
        double result = AMIC_NAMESPACE::calcu_tree_value(target_tree);
        return result;
    }
    char flag = ' ';
    return nan(&flag);
}

AMICAL_ERROR get_expection(const std::string& _expr) {
    try { __main_process(_expr); }
    catch (const AMIC_NAMESPACE::AMICAL_ERROR &err) { return err; }
    return AMIC_NAMESPACE::AMICAL_ERROR(0, -1);
}

AMIC_NAMESPACE_END

namespace AmiCal {

void insert_function(const std::string &id, double(*f)(const std::vector<double>&));
void insert_macro(const std::string &macro, const std::string &value);
int get_error_code(const std::string& _expr);
int get_error_loca(const std::string& _expr);
double etolf(const std::string& _expr);
float etof(const std::string& _expr);
int32_t etoi(const std::string& _expr);
int print_token(const std::string& _expr);
std::string get_error_info(const std::string& _expr);

};


namespace AmiCal {

void insert_function(const std::string &id, double(*f)(const std::vector<double>&)) {
    return AMIC_NAMESPACE::__insert_function(id, f);
}

void insert_macro(const std::string &macro, const std::string &value) {
    return AMIC_NAMESPACE::__insert_macro(macro, value);
}

int get_error_code(const std::string& _expr) {
    return AMIC_NAMESPACE::get_expection(_expr).get_ecode();
}

int get_error_loca(const std::string& _expr) {
    return AMIC_NAMESPACE::get_expection(_expr).get_eloca();
}

double etolf(const std::string& _expr) {
    try { return AMIC_NAMESPACE::__main_process(_expr); } 
    catch (...) {
        char flag = ' ';
        return nan(&flag);
    }
}

float etof(const std::string& _expr) {
    char flag = ' ';
    double pre_res = etolf(_expr);
    if (isnan(pre_res)) return nanf(&flag);
    else return static_cast<float>(pre_res);
}

int32_t etoi(const std::string& _expr) {
    double pre_res = etolf(_expr);
    if (isnan(pre_res)) return 0;
    else return static_cast<int32_t>(pre_res);
}

int print_token(const std::string& _expr) {
    AMIC_NAMESPACE::Lexical_analyzer l_ana(_expr);
    AMIC_NAMESPACE::token::token* current;
    while (static_cast<int>((current = l_ana.get_next_token())->getTokenType()) >= 0) {
        current->printToken();
    }
    return current->getTokenType() == AMIC_NAMESPACE::token::end ? 0 : 1; // complete -> 0 | error -> 1
}

std::string get_error_info(const std::string& _expr) {
    AMIC_NAMESPACE::AMICAL_ERROR err = AMIC_NAMESPACE::get_expection(_expr);
    std::stringstream SS;
    switch (err.get_ecode()) {
    case 0:
        return "Ami000 - Complete";
        break;
    case 1:
        SS << "Ami001 - Lexical error";
        break;
    case 2:
        SS << "Ami002 - Syntax error";
        break;
    case 3:
        SS << "Ami003 - Math error";
        break;
    case 4:
        SS << "Ami004 - Preprocesser error: undefined macro";
        break;
    case 5:
        SS << "Ami005 - Preprocesser error: unclosed macro";
        break;
    case 6:
        SS << "Ami006 - Lexical error: out of range, add \".0\" to transfer to float token";
        break;
    case 100:
        SS << "Ami100 - Inner error";
        break;
    }
    SS << " at char " << err.get_eloca();
    return SS.str();
}

};

# endif