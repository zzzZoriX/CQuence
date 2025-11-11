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
    std::cout << ccpv.size() << std::endl;

    for(const auto& c : ccpv)
        std::cout << c << std::endl;
#endif

    for(const auto& file : ccpv){
        const std::string tfn = pre_processing(file); // make a pre-processor file

        
    }

    delete scc;

    return 0;
}