#include <iostream>
#include <windows.h>

using namespace std;

   int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");

  return 0;
}