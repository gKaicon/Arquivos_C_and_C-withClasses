#include <iostream>
#include <windows.h>
 
using namespace std;

void imprime(int *v){
    for(int i = 0; i < 5; i++) cout << *v++ << "\t";
}
int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
   int v[5];
   v[0] = 2;
   v[1] = 5;
   v[2] = 9;
   v[3] = 6;
   v[4] = 8;
   imprime(v);
   return 0;
}