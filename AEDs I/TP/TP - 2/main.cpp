#include "funcoes.cpp"
 
int main(){
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
   cout << endl; 
   return 0;
}