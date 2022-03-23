
#include <Windows.h>

int main() {
    HANDLE handle = GetClipboardData(CF_DSPTEXT);
    return 0;
}