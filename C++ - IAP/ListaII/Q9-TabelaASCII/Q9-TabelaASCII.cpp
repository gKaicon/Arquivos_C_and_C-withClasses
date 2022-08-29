#include <iostream>
#include <windows.h>
using namespace std;

void TabelaASCII(int, int);

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int i;
    printf("\n\nASCII de 33 até 127\n");
    printf("Decimal\tHexadecimal\tCaracter\n");
    for (i = 33; i <= 127; i++){
        printf("%d \t%x \t\t%c", i, i, i);
        printf("\n");
    }
    return 0;
}
