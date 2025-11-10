#pragma once

#include <iostream>
#include <string>

// Error struct
typedef struct
e {
private:
    std::string msg, rcode;
    unsigned long long row, column;
    int code;
    
public: 
    e(
        const std::string m,
        const std::string rc,
        const unsigned long long r,
        const unsigned long long c,
        const int code
    ) : msg(m), rcode(rc), row(r), column(c), code(code) {}

    int
    get_code(void){ return code; }

// make output error string with a row, a column, a msg and a row of code
    std::string&
    Moet(void){
        std::string& oes = msg; 

        if(code < 0) return oes;
    
        oes += ":\n";
        char buffer[256];

        itoa(row, buffer, 10);
        oes += buffer;
        oes += ": " + rcode + "\n";

        std::string columnPrinter = "~~~";
        for(long long i = 0; i < column - 1; ++i)
            columnPrinter += "~";

        columnPrinter += "^";
        oes += columnPrinter;

        return oes;
    }
} Error;

// static class for handle an errors
class ErrorHandler {
public:
    [[noreturn]] static void
    Abort(Error e){
        std::cerr << e.Moet() << std::endl;
        std::exit(e.get_code());
    }

    static void
    PrintWarn(Error e){
        std::cout << e.Moet() << std::endl;
    }
};