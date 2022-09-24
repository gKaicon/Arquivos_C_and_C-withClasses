#include <iostream>
#include <windows.h>
 
using namespace std;

void soma(int *a, int b){
    *a = *a + b;
}

int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
    int a = 5, b = 8;
    soma(&a, b);
    cout << "A: " << a << "\tB: " << b;
   return 0;
}