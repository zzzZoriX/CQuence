#pragma once

#include <string>

#define SUCCESS_OBJ_NAME_SYMBOLS \
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdifghijclmnopqrstuvwxyz_1234567890"

#define SUCCESS_FILE_NAME_SYMBOLS \
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijclmnopqrstuvwxyz_1234567890-./"

namespace Common {
/**
 * @brief convert array of char* to single string
 * 
 * @param words array of char*
 * @param count size of array
 * @param separator symbol between words
 * @return std::string* 
 */
static std::string*
ccppts(char** words, const int count, const std::string& separator){
    std::string* res = new std::string(*words);

    for(int i = 1; i < count; ++i)
        *res += separator + words[i];

    return res;
}

static bool
isdigits(const std::string& s){

    for(const char a : s)
        if(!std::isdigit(a)) return false;

    return true;
}

static bool
is_valid_obj_name(const std::string& s){
    if(s[0] != '_' && std::isalpha(s[0])) return false;

    for(const char c : s)
        if(
            !std::isdigit(c) &&
            !std::isalpha(c) &&
            c != '_'
        ) return false;
    
    return true;
}

static bool
isspec(const char c){
    return
        c == ';' ||
        c == '(' ||
        c == ')' ||
        c == '{' ||
        c == '}' ||
        c == '[' ||
        c == ']' ||
        c == '!' ||
        c == '>' ||
        c == '<' ||
        c == '=' ||
        c == ',' ||
        c == '&' ||
        c == '|' ||
        c == '^' ||
        c == '+' ||
        c == '-' ||
        c == '*' ||
        c == '/'
    ;
}
};