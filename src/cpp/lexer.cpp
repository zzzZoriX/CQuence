#include "../incl/lexer.hpp"

const Lexer_ns::LexemeType
Lexer_ns::Lexer::_define_lexeme(
    const std::string& word,
    std::pair<std::string, LexemeType>* last_tok
){
    if(last_tok != nullptr){
        // process for double keywords like "long long" and difficult constructionss like pointer deref.
    }
    
// process for simple keywords
    if(word == "struct")            return Lexer_ns::LexemeType::LEX_STRUCT;
    if(word == "if")                return Lexer_ns::LexemeType::LEX_IF;
    if(word == "else")              return Lexer_ns::LexemeType::LEX_ELSE;
    if(word == "for")               return Lexer_ns::LexemeType::LEX_FOR;
    if(word == "while")             return Lexer_ns::LexemeType::LEX_WHILE;

    if(word == "void")              return Lexer_ns::LexemeType::LEX_VOID_TYPE;
    if(word == "int")               return Lexer_ns::LexemeType::LEX_INT;
    if(word == "short")             return Lexer_ns::LexemeType::LEX_SHORT;
    if(word == "long")              return Lexer_ns::LexemeType::LEX_LONG;
    if(word == "float")             return Lexer_ns::LexemeType::LEX_FLOAT;
    if(word == "double")            return Lexer_ns::LexemeType::LEX_DOUBLE_TYPE;
    if(word == "unsigned")          return Lexer_ns::LexemeType::LEX_UNSIGN;
    
    if(word == "&")                 return Lexer_ns::LexemeType::LEX_POINTER_DEREF;
    
    if(word == "=")                 return Lexer_ns::LexemeType::LEX_ASSIGN;
    if(word == ";")                 return Lexer_ns::LexemeType::LEX_SEMIC;
    if(word == ".")                 return Lexer_ns::LexemeType::LEX_DOT;
    if(word == ",")                 return Lexer_ns::LexemeType::LEX_COMMA;
    
    if(word == "+")                 return Lexer_ns::LexemeType::LEX_PLUS;
    if(word == "-")                 return Lexer_ns::LexemeType::LEX_MINUS;
    if(word == "*")                 return Lexer_ns::LexemeType::LEX_MUL;
    if(word == "/")                 return Lexer_ns::LexemeType::LEX_DIV;
    if(word == "%")                 return Lexer_ns::LexemeType::LEX_REM;

    if(word == ">")                 return Lexer_ns::LexemeType::LEX_G;
    if(word == "<")                 return Lexer_ns::LexemeType::LEX_L;
    if(word == "!")                 return Lexer_ns::LexemeType::LEX_NOT;

    if(word == "(")                 return Lexer_ns::LexemeType::LEX_LPAREN;
    if(word == "{")                 return Lexer_ns::LexemeType::LEX_LFPAREN;
    if(word == "[")                 return Lexer_ns::LexemeType::LEX_LQPAREN;
    if(word == "]")                 return Lexer_ns::LexemeType::LEX_RQPAREN;
    if(word == "}")                 return Lexer_ns::LexemeType::LEX_RFPAREN;
    if(word == ")")                 return Lexer_ns::LexemeType::LEX_RPAREN;

    return Lexer_ns::LexemeType::LEX_UNDEF;
}