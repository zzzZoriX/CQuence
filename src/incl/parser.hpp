#pragma once

#include "lexer.hpp"

namespace Parser_ns {
enum class AST_Type {
    AST_LIT_CNST,
    
    AST_PLUS,
    AST_MINUS,
    AST_MULTI,
    AST_DIV,
    AST_REM,
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

class Node {
public:
using uc = unsigned char;
using us = unsigned short;
using ui = unsigned;
using ul = unsigned long;
using ull = unsigned long long;

    Node
        * op1,
        * op2,
        * op3
    ;

    union {
        struct {
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
        } LiteralConstant;
    } value;

    AST_Type type;

    Node() = default;

// make binary operation
    Node(const Node&, const Node&, const std::string&) noexcept;
// make unary opearation
    Node(const Node&, const std::string&) noexcept;

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
    Node(const Lexer_ns::LexemeType, const Node&, const Node&, const Node&); // if-else
    Node(const Lexer_ns::LexemeType, const Node&, const Node&);              // do-while
    Node(const Node&, const Node&, const Node&);                             // for
    Node(const Node&, const Node*, const int, const Node&);                  // function
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