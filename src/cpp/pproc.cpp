#include "../incl/pre-proc.hpp"

const std::string
pre_processing(const std::string& ifn){
    const std::string tfn = ifn + "t";

    std::ifstream ifp(ifn);
    if(!ifp.is_open())
        ErrorHandler::Abort(Error(
            std::string("Can't open an input file - ") + ifn,
            "",
            0,
            0,
            -2
        ));

    char c;
    std::string buffer = "";
    while(!ifp.eof()){
        ifp >> c;
        buffer += c;
    }

    std::string res;
    size_t pos, last_pos = 0;

    do {
        res.append(buffer.begin() + last_pos, buffer.begin() + pos);
        
        std::string directive = "#";
        size_t end_dir = buffer.find_first_not_of(SUCCESS_OBJ_NAME_SYMBOLS, pos);

    } while((pos = buffer.find("#", last_pos) != std::string::npos));

    return tfn;
}