#pragma once

#include <iostream>

#define LOG(x) std::cout << x << std::endl 
#define DEBUG(x) std::cout << #x << " " << x << std::endl
#define ERROR(x) std::cout << "[ERROR]" << x << std::endl  
#define VARNAME(x) #x