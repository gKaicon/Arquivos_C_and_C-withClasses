#include <iostream>
#include <windows.h>
 
using namespace std;

void ordena(int *p, int *q, int *r){

    if(*p < *q && *q < *r){
        return;
    }

    if(*p < *q){
        int aux;

        aux = *p;
        *q = *p;
        *q = aux;
    }

    if(*r < *p){
        int aux;

        aux = *q;
        *r = *q;
        *q = aux;
    }
}
 
int main(){
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
   int a = 2, b = 1, c =3;

   int *p, *q, *r;
   return 0;
}