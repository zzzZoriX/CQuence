#pragma once

#include "lexer.hpp"

namespace Parser_ns {
using uc = unsigned char;
using us = unsigned short;
using ui = unsigned;
using ul = unsigned long;
using ull = unsigned long long;

enum class AST_Type {
    AST_LIT_CNST,
    
    AST_PLUS,
    AST_MINUS,
    AST_MULTI,
    AST_DIV,
    AST_REM,
    AST_BIT_OR,
    AST_BIT_AND,
    AST_BIT_XOR,
    AST_ASSIGN,
    
    AST_INC_PREF,
    AST_INC_POST,
    AST_DEC_PREF,
    AST_DEC_POST,
    AST_DEREF,
    AST_GET_ADDR,
    
    AST_EXPR,
    
    AST_EQ,
    AST_NEQ,
    AST_LE,
    AST_L,
    AST_G,
    AST_GE,
    AST_AND,
    AST_OR,
    
    AST_IF,
    AST_ELSE_IF,
    AST_ELSE,
    
    AST_WHILE,
    AST_FOR,
    AST_DO_WHILE,
    
    AST_RETURN,
    AST_FUNCTION,
    
    AST_UNDEF = -1
};

typedef struct lc {
    const std::string dtype;
    const std::string name;

    union {
        char char_v;
        short short_v;
        int int_v;
        long long_v;
        long long ll_v;
        float flt_v;
        double dbl_vl;  
    
        uc uc_v;
        us us_v;
        ui ui_v;
        ul ul_v;
        ull ull_v;
    };
    lc(void) = default;

    lc(const std::string&, const char, const bool);       // char
    lc(const std::string&, const short, const bool);      // short
    lc(const std::string&, const int, const bool);        // int
    lc(const std::string&, const long, const bool);       // long
    lc(const std::string&, const long long, const bool);  // long long

    lc(const std::string&, const uc, const bool);         // unsigned char
    lc(const std::string&, const us, const bool);         // unsigned short
    lc(const std::string&, const ui, const bool);         // unsigned int
    lc(const std::string&, const ul, const bool);         // unsigned long
    lc(const std::string&, const ull, const bool);        // unsigned long long
    
    lc(const std::string&, const float, const bool);      // float
    lc(const std::string&, const double, const bool);     // double
} LiteralConstant;

class Node {
public:
    const Node
        * op1,
        * op2,
        * op3
    ;

    LiteralConstant lc;

    AST_Type type;

    Node(void) noexcept 
    : op1(nullptr), op2(nullptr), op3(nullptr), 
      type(AST_Type::AST_UNDEF) {}


// make binary operation
    Node(const Node*, const Node*, const std::string&) noexcept;
// make unary opearation
    Node(const Node*, const std::string&) noexcept;

// for literal constants
    Node(const std::string&, const char, const bool);       // char
    Node(const std::string&, const short, const bool);      // short
    Node(const std::string&, const int, const bool);        // int
    Node(const std::string&, const long, const bool);       // long
    Node(const std::string&, const long long, const bool);  // long long

    Node(const std::string&, const uc, const bool);         // unsigned char
    Node(const std::string&, const us, const bool);         // unsigned short
    Node(const std::string&, const ui, const bool);         // unsigned int
    Node(const std::string&, const ul, const bool);         // unsigned long
    Node(const std::string&, const ull, const bool);        // unsigned long long
    
    Node(const std::string&, const float, const bool);      // float
    Node(const std::string&, const double, const bool);     // double

// for node of commands(like if-else, cycles and other)
    Node(const Lexer_ns::LexemeType, const Node*, const Node*);              // do-while / if-else
    Node(const Node*, const Node*, const Node*);                             // for
    Node(const Node*, const Node*, const int, const Node*);                  // function

// static functions
    static AST_Type
    define_bin_op_type(const std::string& s) noexcept{
        if(s == "+")        return AST_Type::AST_PLUS;
        if(s == "-")        return AST_Type::AST_MINUS;
        if(s == "*")        return AST_Type::AST_MULTI;
        if(s == "/")        return AST_Type::AST_DIV;
        if(s == "%")        return AST_Type::AST_REM;
        if(s == "=")        return AST_Type::AST_ASSIGN;
        
        if(s == "|")        return AST_Type::AST_BIT_OR;
        if(s == "&")        return AST_Type::AST_BIT_AND;
        if(s == "^")        return AST_Type::AST_BIT_XOR;

        if(s == "<")        return AST_Type::AST_L;
        if(s == ">")        return AST_Type::AST_G;
        if(s == "<=")       return AST_Type::AST_LE;
        if(s == ">=")       return AST_Type::AST_GE;
        if(s == "==")       return AST_Type::AST_EQ;
        if(s == "!=")       return AST_Type::AST_NEQ;
        if(s == "||")       return AST_Type::AST_AND;
        if(s == "&&")       return AST_Type::AST_OR;

        return AST_Type::AST_UNDEF;
    }

    static AST_Type
    define_un_op_type(const std::string& s) noexcept{
        if(s == "++")       return AST_Type::AST_INC_PREF;
        if(s == "--")       return AST_Type::AST_DEC_PREF;

        return AST_Type::AST_UNDEF;
    }
};

class Parser {
private:
    const Lexer_ns::Token htok;
    Node head;

public:
    Parser(const Lexer_ns::Token htok) noexcept
    : htok(htok) {}

    const Node
    Parse(void) noexcept;
};
}