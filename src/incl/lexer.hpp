#pragma once

#include <fstream>
#include <string>
#include <list>
#include "ehandler.hpp"

namespace Lexer_ns {

enum class LexemeType {
    LEX_STRUCT,

    LEX_IF,
    LEX_ELIF,
    LEX_ELSE,
    LEX_FOR,
    LEX_WHILE,

    LEX_PTR_TYPE,
    LEX_VOID_TYPE,
    LEX_DOUBLE_TYPE,
    LEX_SHORT,
    LEX_INT,
    LEX_LONG,
    LEX_LONG_LONG_TYPE,
    LEX_CHAR,
    LEX_FLT,
    LEX_UNSIGN,

    LEX_POINTER_DEREF,
    LEX_GET_ADDR,

    LEX_ASSIGN,
    LEX_ADD_ASSIGN,
    LEX_REDUCE_ASSIGN,
    LEX_MUL_ASSIGN,
    LEX_DIV_ASSIGN,
    LEX_REM_ASSIGN,

    LEX_SEMIC,
    LEX_DOT,
    LEX_COMMA,
    
    LEX_COMMENT_START,
    LEX_COMMENT_END,
    
    LEX_PLUS,
    LEX_MINUS,
    LEX_MUL,
    LEX_DIV,
    LEX_REM,

    LEX_LE,
    LEX_L,
    LEX_EQ,
    LEX_GE,
    LEX_G,
    LEX_NEQ,
    LEX_NOT,
    LEX_AND,
    LEX_OR,
    LEX_BIT_AND,
    LEX_BIT_OR,
    LEX_BIT_XOR,

    LEX_INC,
    LEX_DEC,

    LEX_LPAREN,
    LEX_RPAREN,
    LEX_LQPAREN,
    LEX_RQPAREN,
    LEX_LFPAREN,
    LEX_RFPAREN,

    LEX_NULL_VALUE,
    LEX_OBJ_NAME,

    LEX_DIGIT,
    LEX_FLOAT,
    LEX_CHAR_VAL,
    LEX_HEX_VAL,
    LEX_BIN_VAL,

    LEX_STRING,
    LEX_END,

    LEX_UNDEF = -1,
    LEX_CHANGE_LAST_TOK = -2
};

class Lexer {
private:
    std::ifstream ifp;

    const LexemeType
    _define_lexeme(const std::string&, std::pair<std::string, LexemeType>*);

    const bool
    _is_data_lex(const LexemeType lt){
        return
            lt == LexemeType::LEX_INT ||
            lt == LexemeType::LEX_CHAR ||
            lt == LexemeType::LEX_FLOAT ||
            lt == LexemeType::LEX_DOUBLE_TYPE ||
            lt == LexemeType::LEX_SHORT ||
            lt == LexemeType::LEX_LONG ||
            lt == LexemeType::LEX_LONG_LONG_TYPE ||
            lt == LexemeType::LEX_PTR_TYPE
        ;
    }

public:
    Lexer(const std::string& ifn) noexcept {
        ifp.open(ifn);
        if(!ifp.is_open())
            ErrorHandler::Abort(Error(
                std::string("Can't open a file - ") + ifn,
                "",
                0,
                0,
                -1
            ));
    }

    const std::list<std::pair<std::string, LexemeType>>
    Tokinize(void) noexcept;
};
};