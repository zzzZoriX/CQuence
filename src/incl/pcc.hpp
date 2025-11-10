#pragma once

#include <string>
#include <vector>
#include "ehandler.hpp"

#define SEPARATOR " "

/**
 * @brief spliting a call command string for a file names and flags
 * 
 * @return const std::vector<std::pair<ccp_type, std::string>> 
 */
const std::vector<std::string>
parse_call_command(std::string&);