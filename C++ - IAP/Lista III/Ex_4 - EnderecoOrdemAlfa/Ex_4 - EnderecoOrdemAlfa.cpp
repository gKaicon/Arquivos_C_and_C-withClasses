#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

struct cadastro
{
    char nome[20];
    char endereco[50];
    char telefone[11];
};

int main()
{
    int i;
    struct cadastro c[5];

    for (i = 0; i < 5; i++) {
        cout << "\n Digite seu Nome : ";
        cin.getline(c[i].nome, 20);
        cout << "\n Digite seu Endereco : ";
        cin.getline(c[i].endereco, 50);
        cout << "\n Digite seu Telefone : ";
        cin.getline(c[i].telefone, 11);
    }
    for (i = 0; i < 5; i++)
    {
        printf("\n Nome : %s", c[i].nome);
        printf("\n Endereco : %s", c[i].endereco);
        printf("\n Telefone : %s", c[i].telefone);
        printf("\n\n");
    }
    return 0;
}