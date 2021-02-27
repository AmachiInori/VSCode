# pragma once
# ifndef __AMI_PM__
# define __AMI_PM__

# include "../Lexical/Lexical_main.hpp"
# include "Parser_production.hpp"

AMIC_NAMESPACE_START

class Parser {
public:
    T_node::tree_node* get_parser_tree();
private:
    Lexical_analyzer* lexical;
    token::token* current_token;
    void error_handle();
    void delete_null_edge(T_node::tree_node* rt);
    
    std::stack<T_node::tree_node*> all_node;
    void delete_all_node();
private:
    bool match(token::token_type t_type);
    T_node::tree_node* root();
    T_node::tree_node* expr();
    T_node::tree_node* root_right();
    T_node::tree_node* factor();
    T_node::tree_node* expr_right();
    T_node::tree_node* element();
    T_node::tree_node* para();
    T_node::tree_node* para1();
public:
    explicit Parser(Lexical_analyzer* _lex);
    ~Parser();
};


Parser::Parser(Lexical_analyzer* _lex) : lexical(_lex) { 
    current_token = lexical->get_next_token();
}

void Parser::error_handle() {
    std::cout << "(Ami002) Syntax Error:";
    unsigned int errloca = lexical->loca_error();
    current_token->printToken();
    std::cout << "\n";
    throw AMICAL_ERROR(2, errloca);
}

void Parser::delete_null_edge(T_node::tree_node* rt) {
    while (!rt->childs.empty() && rt->childs.back() == nullptr) rt->childs.pop_back();
    for (unsigned int i = 0; i < rt->childs.size(); i++) delete_null_edge(rt->childs[i]);
}

Parser::~Parser() {
    delete_all_node();
}

void Parser::delete_all_node() {
    while (!all_node.empty()) {
        delete all_node.top();
        all_node.pop();
    }
}

T_node::tree_node* Parser::get_parser_tree() {
    T_node::tree_node* ret;
    try {
        ret = root();
        delete_null_edge(ret);
    } catch (...) {
        throw;
    }
    return ret;
}

bool Parser::match(token::token_type t_type) {
    if (current_token->getTokenType() == t_type) {
        current_token = lexical->get_next_token();
        return true;
    } else {
        error_handle();
        return false;
    }
}

T_node::tree_node* Parser::root() {
    T_node::root_node* ret = new T_node::root_node();
    all_node.push(ret);
    if (current_token->getTokenType() == token::sub) {
        ret->set_negative();
        match(token::sub);
        T_node::tree_node* left = expr();
        T_node::tree_node* right = root_right();
        ret->childs.push_back(left);
        ret->childs.push_back(right);
    } else if (production::in_first_set(production::Expr, current_token->getTokenType())) {
        T_node::tree_node* left = expr();
        T_node::tree_node* right = root_right();
        ret->childs.push_back(left);
        ret->childs.push_back(right);
    } else error_handle();
    return ret;
}

T_node::tree_node* Parser::root_right() {
    T_node::rootright_node* ret = nullptr;
    if (current_token->getTokenType() == token::add) {
        ret = new T_node::rootright_node();
        all_node.push(ret);
        match(token::add);
        T_node::tree_node* left = expr();
        T_node::tree_node* right = root_right();
        ret->childs.push_back(left);
        ret->childs.push_back(right);
    } else if (current_token->getTokenType() == token::sub) {
        ret = new T_node::rootright_node();
        ret->set_negative();
        all_node.push(ret);
        match(token::sub);
        T_node::tree_node* left = expr();
        T_node::tree_node* right = root_right();
        ret->childs.push_back(left);
        ret->childs.push_back(right);
    } else if (production::in_follow_set(production::RootRight, current_token->getTokenType())) {
        return ret;
    } else error_handle();
    return ret;
}

T_node::tree_node* Parser::expr() {
    T_node::expr_node* ret = new T_node::expr_node();
    all_node.push(ret);
    T_node::tree_node* fac = factor();
    T_node::tree_node* expr_r = expr_right();
    ret->childs.push_back(fac);
    ret->childs.push_back(expr_r);
    return ret;
}

T_node::tree_node* Parser::expr_right() {
    T_node::exprright_node* ret = nullptr;
    if (current_token->getTokenType() == token::muitl) {
        match(token::muitl);
        ret = new T_node::exprright_node('*');
        all_node.push(ret);
        T_node::tree_node* fac = factor();
        T_node::tree_node* Er = expr_right();
        ret->childs.push_back(fac);
        ret->childs.push_back(Er);
    } else if (current_token->getTokenType() == token::div) {
        match(token::div);
        ret = new T_node::exprright_node('/');
        all_node.push(ret);
        T_node::tree_node* fac = factor();
        T_node::tree_node* Er = expr_right();
        ret->childs.push_back(fac);
        ret->childs.push_back(Er);
    } else if (current_token->getTokenType() == token::int_div) {
        match(token::int_div);
        ret = new T_node::exprright_node('\\');
        all_node.push(ret);
        T_node::tree_node* fac = factor();
        T_node::tree_node* Er = expr_right();
        ret->childs.push_back(fac);
        ret->childs.push_back(Er);
    } else if (current_token->getTokenType() == token::reme) {
        match(token::reme);
        ret = new T_node::exprright_node('%');
        all_node.push(ret);
        T_node::tree_node* fac = factor();
        T_node::tree_node* Er = expr_right();
        ret->childs.push_back(fac);
        ret->childs.push_back(Er);
    } else if (production::in_follow_set(production::ExprRight, current_token->getTokenType())) return ret;
    else error_handle();
    return ret;
}

T_node::tree_node* Parser::factor() {
    T_node::factor_node* ret = nullptr;
    if (production::in_first_set(production::Element, current_token->getTokenType())) {
        ret = new T_node::factor_node();
        all_node.push(ret);
        T_node::tree_node* elem = element();
        ret->childs.push_back(elem);
    } else if (current_token->getTokenType() == token::function) {
        ret = new T_node::factor_node (
            static_cast<token::function_token*>(current_token)->value(), 
            lexical->get_now_loca()
        );
        all_node.push(ret);
        match(token::function);
        match(token::left);
        T_node::tree_node* pa = para();
        ret->childs.push_back(pa);
        match(token::right);
    } else error_handle();
    return ret;
}

T_node::tree_node* Parser::element() {
    T_node::element_node* ret = nullptr;
    if (current_token->getTokenType() == token::left) {
        match(token::left);
        ret = new T_node::element_node();
        all_node.push(ret);
        T_node::tree_node* rt = root();
        ret->childs.push_back(rt);
        match(token::right);
        return ret;
    } else if (current_token->getTokenType() == token::inter) {
        ret = new T_node::element_node(static_cast<token::int_token*>(current_token)->value());
        all_node.push(ret);
        match(token::inter);
        return ret;
    } else if (current_token->getTokenType() == token::flo) {
        ret = new T_node::element_node(static_cast<token::float_token*>(current_token)->value());
        all_node.push(ret);
        match(token::flo);
        return ret;
    } else error_handle();
    return ret;
}

T_node::tree_node* Parser::para() {
    T_node::para_node* ret = new T_node::para_node();
    all_node.push(ret);
    if (production::in_first_set(production::Root, current_token->getTokenType())) {
        T_node::tree_node* left = root();
        T_node::tree_node* right = para1();
        ret->childs.push_back(left);
        ret->childs.push_back(right);
    } else if (production::in_follow_set(production::Para, current_token->getTokenType())) return ret;
    else error_handle();
    return ret;
}

T_node::tree_node* Parser::para1() {
    T_node::para_node* ret = nullptr;
    if (current_token->getTokenType() == token::comma) {
        ret = new T_node::para_node();
        all_node.push(ret);
        match(token::comma);
        T_node::tree_node* left = root();
        T_node::tree_node* right = para1();
        ret->childs.push_back(left);
        ret->childs.push_back(right);
        return ret;
    } else if (production::in_follow_set(production::Para1, current_token->getTokenType())) return ret;
    else error_handle();
    return ret;
}

AMIC_NAMESPACE_END

# endif