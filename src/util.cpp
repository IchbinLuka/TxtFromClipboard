#include <iostream>
#include "common.h"

void debugPrint(const char* message) {
    if (DEBUG) {
        std::cout << message << std::endl;
    }
}

inline char getLastChar(std::string s) {
    return s.at(s.length() - 1);
}