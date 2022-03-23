#include <iostream>
#include <Windows.h>
#include <fstream>
#include "clipboardUtil.cpp"

int main(int argc, char* argv[]) {
    std::string path = argv[0];
    path += "/clipboard.txt";
    writeTextFile(
        getClipboardText(), 
        (char*) path.c_str()
    );
    return 0;
}

void writeTextFile(char* content, char* path) {
    std::ofstream out;
    out.open(path);
    out.write(content, strlen(content));
    out.flush();
    out.close();
}