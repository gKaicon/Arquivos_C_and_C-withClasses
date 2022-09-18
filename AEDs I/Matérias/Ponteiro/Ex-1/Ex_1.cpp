#include <iostream>
#include <windows.h>
#include <time.h>
 
using namespace std;
 
int main(){
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
   srand(time(NULL));

//Variaveis
   float num[10];

//Ponteiros
   float *p;
   p = &num[10];
//Code   
   for(int i=0; i<10;i++){
      num[i] = rand()%10;
   }
   
   for(int i=0; i<10;i++){
      cout << p++ << " - " << num[i] << "\n";
   }
   return 0;
}