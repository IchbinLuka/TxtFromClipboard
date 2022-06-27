#include <iostream>
#include <Windows.h>
#include "util.cpp"

std::string getClipboardText() {
    HWND hwnd = GetClipboardOwner();
    if (OpenClipboard(hwnd)) {
        HANDLE handle = GetClipboardData(CF_TEXT);
        if (handle != NULL) {
            char* clipboard = (char*) handle;
            std::string foo = std::string(clipboard);
            for (int i = 0; i < foo.length(); i++) {
                std::cout << std::hex << (int8_t) foo.at(i);
            }
            debugPrint(clipboard); 
            return clipboard;
        } else {
            debugPrint("Clipboard is empty");
        }
        
    } else {
        debugPrint("Unable to open Clipboard");
    }
    CloseClipboard();
    return nullptr;
}