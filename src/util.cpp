#include <iostream>
#include "common.h"

inline void debugPrint(const char* message) {
    #if DEBUG
    std::cout << message << std::endl;
    #endif
}

inline char getLastChar(std::string s) {
    return s.at(s.length() - 1);
}