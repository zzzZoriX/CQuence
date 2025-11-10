#pragma once

#include <string>

#define SUCCESS_OBJ_NAME_SYMBOLS \
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdifghijclmnopqrstuvwxyz_1234567890"

class Common {
public:
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
};