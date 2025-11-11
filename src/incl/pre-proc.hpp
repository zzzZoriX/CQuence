#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ehandler.hpp"
#include "common.hpp"

/**
 * @brief process all pre-processor directives in input file
 * 
 * @return const std::string 
 */
const std::string
pre_processing(const std::string&);

/**
 * @brief take a directive and select suitable process
 * 
 * @return std::string 
 */
std::string
process_directive(
    const std::string&, 
    const std::string&, 
    size_t*, 
    const std::string&,
    const std::string&
);

/**
 * @brief process an include directives by using recursive
 * 
 * @return std::string 
 */
std::string
ppd_include(const std::string&, const std::string&);