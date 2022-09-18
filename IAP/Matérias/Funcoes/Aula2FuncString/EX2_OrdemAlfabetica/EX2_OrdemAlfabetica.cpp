#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    char nome[3][20] = {{"Pedro"}, {"Ana"}, {"Maria"}}, aux[20];
    for (int i = 1; i < 3; i++)
    { // palavra
        for (int j = 1; j < 3; j++)
        { // caracter por caracter
            if ((strcmp(nome[j - 1], nome[j])) > 0)
            {
                strcpy(aux, nome[j - 1]);
                strcpy(nome[j - 1], nome[j]);
                strcpy(nome[j], aux);
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << nome[i] << "\n";
    }
    return 0;
}
