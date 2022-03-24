#include <iostream>
#include <Windows.h>
#include <fstream>
#include "clipboardUtil.cpp"
#include <time.h>

void writeTextFile(char* content, char* path) {
    std::ofstream out;
    out.open(path);
    out.write(content, strlen(content));
    out.flush();
    out.close();
}

int main(int argc, char* argv[]) {
    std::string path = argv[1];
    
    // Get time string
    time_t currentTime;
    time (&currentTime);
    std::string timestr = ctime(&currentTime);
    int length = timestr.length();
    // Replace ':' with '-' and ' ' with '_'
    for (int i = 0; i < length; i++) {
        if (timestr[i] == ':') {
            timestr[i] = '-';
        } else if (timestr[i] == ' ') {
            timestr[i] = '_';
        }
    }
    char last = getLastChar(path);
    if (last == '"') {
        path = path.substr(0, path.length() - 1);
        last = getLastChar(path);
    }
    if (last != '/' && last != '\\') {
        path.append("/");
    }
    path.append("clipboard_");
    path.append(timestr.substr(4, length - 5));
    path.append(".txt");
    debugPrint(path.c_str());
    writeTextFile(
        getClipboardText(), 
        (char*) path.c_str()
    );
    return 0;
}
