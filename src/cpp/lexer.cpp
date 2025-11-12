#include "../incl/lexer.hpp"
using namespace Lexer_ns;

const LexemeType
Lexer::_define_lexeme(
    const std::string& word,
    std::pair<std::string, LexemeType>* last_tok
){
    if(last_tok != nullptr){
        if(word == "long" && last_tok->second == LexemeType::LEX_LONG){
            last_tok->first += " " + word;
            last_tok->second = LexemeType::LEX_LONG_LONG_TYPE;
        }
        else if(word == "*" && last_tok->second == LexemeType::LEX_DIV){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_COMMENT_START;
        }
        else if(word == "/" && last_tok->second == LexemeType::LEX_MUL){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_COMMENT_END;
        }
        else if(word == "=" && last_tok->second == LexemeType::LEX_PLUS){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_ADD_ASSIGN;
        }
        else if(word == "=" && last_tok->second == LexemeType::LEX_MINUS){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_REDUCE_ASSIGN;
        }
        else if(word == "=" && last_tok->second == LexemeType::LEX_MUL){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_MUL_ASSIGN;
        }
        else if(word == "=" && last_tok->second == LexemeType::LEX_DIV){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_DIV_ASSIGN;
        }
        else if(word == "=" && last_tok->second == LexemeType::LEX_REM){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_REM_ASSIGN;
        }
        else if(word == "+" && last_tok->second == LexemeType::LEX_PLUS){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_INC;
        }
        else if(word == "-" && last_tok->second == LexemeType::LEX_MINUS){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_DEC;
        }
        else if(word == "&" && last_tok->second == LexemeType::LEX_BIT_AND){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_AND;
        }
        else if(word == "|" && last_tok->second == LexemeType::LEX_BIT_OR){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_OR;
        }
        else if(word == "*" && _is_data_lex(last_tok->second)){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_PTR_TYPE;
        }
        else if(Common::isdigits(word) && last_tok->second == LexemeType::LEX_MINUS){
            last_tok->first += word;
            last_tok->second = LexemeType::LEX_DIGIT;
        }
        else if(word == "_" && last_tok->second == LexemeType::LEX_OBJ_NAME)
            last_tok->first += word;

        else if(
            Common::isdigits(word) && 
            (
                last_tok->second == LexemeType::LEX_OBJ_NAME ||
                last_tok->second == LexemeType::LEX_DIGIT
            )
        )
            last_tok->first += word;

        return LexemeType::LEX_CHANGE_LAST_TOK;
    }
    
// process for simple keywords
    if(word == "struct")            return LexemeType::LEX_STRUCT;
    if(word == "if")                return LexemeType::LEX_IF;
    if(word == "else")              return LexemeType::LEX_ELSE;
    if(word == "for")               return LexemeType::LEX_FOR;
    if(word == "while")             return LexemeType::LEX_WHILE;
    if(word == "return")            return LexemeType::LEX_RETURN;

    if(word == "void")              return LexemeType::LEX_VOID_TYPE;
    if(word == "int")               return LexemeType::LEX_INT;
    if(word == "short")             return LexemeType::LEX_SHORT;
    if(word == "long")              return LexemeType::LEX_LONG;
    if(word == "float")             return LexemeType::LEX_FLOAT;
    if(word == "double")            return LexemeType::LEX_DOUBLE_TYPE;
    if(word == "unsigned")          return LexemeType::LEX_UNSIGN;
    
    if(word == "&")                 return LexemeType::LEX_BIT_AND;
    if(word == "|")                 return LexemeType::LEX_BIT_OR;
    if(word == "^")                 return LexemeType::LEX_BIT_XOR;
    
    if(word == "=")                 return LexemeType::LEX_ASSIGN;
    if(word == ";")                 return LexemeType::LEX_SEMIC;
    if(word == ".")                 return LexemeType::LEX_DOT;
    if(word == ",")                 return LexemeType::LEX_COMMA;
    
    if(word == "+")                 return LexemeType::LEX_PLUS;
    if(word == "-")                 return LexemeType::LEX_MINUS;
    if(word == "*")                 return LexemeType::LEX_MUL;
    if(word == "/")                 return LexemeType::LEX_DIV;
    if(word == "%")                 return LexemeType::LEX_REM;

    if(word == ">")                 return LexemeType::LEX_G;
    if(word == "<")                 return LexemeType::LEX_L;
    if(word == "!")                 return LexemeType::LEX_NOT;
    
    if(word == "(")                 return LexemeType::LEX_LPAREN;
    if(word == "{")                 return LexemeType::LEX_LFPAREN;
    if(word == "[")                 return LexemeType::LEX_LQPAREN;
    if(word == "]")                 return LexemeType::LEX_RQPAREN;
    if(word == "}")                 return LexemeType::LEX_RFPAREN;
    if(word == ")")                 return LexemeType::LEX_RPAREN;

    if(Common::isdigits(word))  return LexemeType::LEX_DIGIT;
    if(Common::is_valid_obj_name(word)) return LexemeType::LEX_OBJ_NAME;

    return Lexer_ns::LexemeType::LEX_UNDEF;
}

const std::list<std::pair<std::string, LexemeType>>
Lexer::Tokenize(void) noexcept {
    std::list<std::pair<std::string, LexemeType>> tokens;
    std::pair<std::string, LexemeType>* last_token = nullptr;
    std::string word;
    char c;

    while((c = ifp.get()) != ifp.eof()){
        if(Common::isspec(c) || c == ' '){
            LexemeType lt = _define_lexeme(word, last_token);

            // заменить "" на строку кода
            if(lt == LexemeType::LEX_UNDEF)
                ErrorHandler::Abort(Error(
                    "Unknown word",
                    "",
                    0,
                    0,
                    -1
                ));

            if(lt != LexemeType::LEX_CHANGE_LAST_TOK){
                std::pair<std::string, LexemeType> token(word, lt);

                tokens.push_back(token);
                last_token = &token;
            }

            word = {c, '\0'};
            lt = _define_lexeme(word, last_token);

            // заменить "" на строку кода
            if(lt == LexemeType::LEX_UNDEF)
                ErrorHandler::Abort(Error(
                    "Unknown word",
                    "",
                    0,
                    0,
                    -1
                ));

            if(lt != LexemeType::LEX_CHANGE_LAST_TOK){
                std::pair<std::string, LexemeType> token(word, lt);

                tokens.push_back(token);
                last_token = &token;
            }

            word.clear();
            continue;
        }
        word += c;
    }

    tokens.push_back(std::pair<std::string, LexemeType>("", LexemeType::LEX_END));
    last_token = nullptr;

    return tokens;
}