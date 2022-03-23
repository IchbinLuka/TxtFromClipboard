#include <iostream>
#include <common.h>

void debugPrint(char* message) {
    if (DEBUG) {
        std::cout << message << std::endl;
    }
}