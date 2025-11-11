#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ehandler.hpp"
#include "common.hpp"

const std::string
pre_processing(const std::string&);

std::string
process_directive(const std::string&, const std::string&, size_t*);

std::string
ppd_include(const std::string&);