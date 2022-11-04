#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int num, *n;
    char sx, *s;
    double dec, *d;

    n = &num;
    s = &sx;
    d = &dec;

    *d = 5.21;
    *s = 'M';
    *n = 2;

    cout << "Num: " << num << "\tChar: " << sx << "\tDecimal: " << dec;
    cout << endl;

    return 0;
}