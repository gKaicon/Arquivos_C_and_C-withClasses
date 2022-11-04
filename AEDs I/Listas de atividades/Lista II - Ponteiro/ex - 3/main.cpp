#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
 
    int a = 2, b = 3, *max, *ap, *bp;
    ap = &a;
    bp = &b;
    max = (ap > bp) ? ap : bp;
    cout <<"A: "<< ap << "\tB: "<< bp;
    cout << "\nValor do maior endereço: " << *max << "\n";
 
   return 0;
}