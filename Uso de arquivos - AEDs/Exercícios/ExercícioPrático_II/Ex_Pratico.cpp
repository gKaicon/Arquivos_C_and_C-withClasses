#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    cout << sizeof(char) << "Byte(s)";
    cout << sizeof(int) << "Byte(s)";
    cout << endl;
    // char, short, int, long, float, double, long double
    return 0;
}
