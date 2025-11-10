#include "../incl/hmain.hpp"

int
main(int c, char** v){
    if(c < 2)
        ErrorHandler::Abort(Error(
            "Too few arguments.",
            "",
            1,
            1,
            -1
        ));

    std::string* scc = Common::ccppts(v, c, SEPARATOR);
    const std::vector<std::string> ccpv = parse_call_command(*scc);

#if CQ_CCP_DEBUG_CYCLE
    for(const auto& c : ccpv)
        std::cout << c.second;
#endif

    for(const auto& file : ccpv){
        pre_processing(file);
    }

    delete scc;

    return 0;
}