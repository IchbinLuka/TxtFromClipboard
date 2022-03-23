#include <iostream>
#include <Windows.h>
#include <util.cpp>

char* getClipboardText() {
    HWND hwnd = GetClipboardOwner();
    if (OpenClipboard(hwnd)) {
        HANDLE handle = GetClipboardData(CF_TEXT);
        if (handle != NULL) {
            char* clipboard = (char*) handle;
            debugPrint(clipboard); 
            return clipboard;
        } else {
            debugPrint("Clipboard is empty");
        }
        
    } else {
        debugPrint("Unable to open Clipboard");
    }
    CloseClipboard();
    return nullptr_t;
}