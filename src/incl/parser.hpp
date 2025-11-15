#pragma once

#include "lexer.hpp"

namespace Parser_ns {
enum class AST_Type {

};

class Node {
private:
    Node
        * op1,
        * op2,
        * op3
    ;

    union {
// TODO: write a structures for AST_Node values
    } value;

    AST_Type type;

public:
using uc = unsigned char;
using us = unsigned short;
using ui = unsigned;
using ul = unsigned long;
using ull = unsigned long long;
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