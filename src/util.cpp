#include <iostream>
#include "common.h"

void debugPrint(const char* message) {
    if (DEBUG) {
        std::cout << message << std::endl;
    }
}