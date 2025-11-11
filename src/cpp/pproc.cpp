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
    while(!ifp.eof())
        buffer += ifp.get();

    buffer.replace(buffer.length() - 1, 1, "\0");


    ifp.close();


    std::string res;
    size_t pos = 0, last_pos = 0;

    if(buffer.find('#', last_pos) != std::string::npos)
        do {
            res.append(buffer.begin() + last_pos, buffer.begin() + pos);
            
            size_t end_dir = buffer.find_first_not_of(SUCCESS_OBJ_NAME_SYMBOLS, pos + 1) + 1;
            std::string directive = buffer.substr(pos, end_dir);

            res.append(process_directive(directive, buffer, &pos, "", ifn));
            
            last_pos = pos;

        } while((pos = buffer.find("#", last_pos) != std::string::npos));

    if(last_pos < buffer.length())
        res.append(buffer.begin() + last_pos, buffer.end());

    std::ofstream tofp(tfn);
    if(!tofp.is_open())
        ErrorHandler::Abort(Error(
            "Can't create a temp file",
            "",
            0,
            0,
            -2
        ));

    tofp << res;


    tofp.close();

    return tfn;
}

std::string
process_directive(const std::string& d, const std::string& buffer, size_t* off, const std::string& from, const std::string& cur){
    if(d == "#include"){
        size_t 
            start_name = buffer.find('"', *off) + 1,
            end_name = buffer.find_first_not_of(SUCCESS_FILE_NAME_SYMBOLS, start_name) + 1
        ;

        *off = end_name;
        std::string fn = buffer.substr(start_name, end_name - start_name - 1);
        if(fn == from || fn == cur)
            ErrorHandler::Abort(Error(
                "Recursive include directive",
                d + " <" + fn + ">",
                0,
                11,
                1
            ));

        return ppd_include(fn, cur);
    }

    return "";
}

std::string
ppd_include(const std::string& infn, const std::string& from){
    std::ifstream iifp(infn);
    if(!iifp.is_open())
        ErrorHandler::Abort(Error(
            std::string("Can't open an input file - ") + infn,
            "",
            0,
            0,
            -2
        ));

    char c;
    std::string buffer = "";
    while(!iifp.eof())
        buffer += iifp.get();

    buffer.replace(buffer.length() - 1, 1, "\0");


    iifp.close();


    std::string res;
    size_t pos = 0, last_pos = 0;

    if(buffer.find('#', last_pos) != std::string::npos)
        do {
            res.append(buffer.begin() + last_pos, buffer.begin() + pos);
            
            size_t end_dir = buffer.find_first_not_of(SUCCESS_OBJ_NAME_SYMBOLS, pos + 1) + 1;
            std::string directive = buffer.substr(pos, end_dir);

            res.append(process_directive(directive, buffer, &pos, from, infn));
            
            last_pos = pos;

        } while((pos = buffer.find("#", last_pos) != std::string::npos));


    res.append(buffer.begin() + last_pos, buffer.end());

    return res;
}