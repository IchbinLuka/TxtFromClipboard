#include <iostream>
#include <Windows.h>
#include <fstream>
#include "clipboardUtil.cpp"

void writeTextFile(char* content, char* path) {
    std::ofstream out;
    out.open(path);
    out.write(content, strlen(content));
    out.flush();
    out.close();
}

int main(int argc, char* argv[]) {
    std::string path = argv[1];
    path.append("/clipboard.txt");
    debugPrint(path.c_str());
    writeTextFile(
        getClipboardText(), 
        (char*) path.c_str()
    );
    return 0;
}
