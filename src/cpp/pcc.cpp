#include "../incl/pcc.hpp"

const std::vector<std::string>
parse_call_command(std::string& cc){
    std::vector<std::string> ccp_vector;
    size_t pos, last_pos = 5;

    do{
        ccp_vector.push_back(cc.substr(last_pos, pos - last_pos + 1));
        last_pos = pos + 1;

    } while((pos = cc.find(SEPARATOR, last_pos)) != std::string::npos);

    return ccp_vector;
}