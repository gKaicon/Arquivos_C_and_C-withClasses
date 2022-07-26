#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    
    int i, j;
    double troca, dist[5], menor, maior, media, qtd = 5, 
    tabela[3][8] = {{4.76, 4.76, 3.12, 4.76, 5.45, 4.57, 3.12, 4.76},
                    {4.76, 3.12, 4.76, 4.87, 4.76, 4.454, 3.12, 4.87},
                    {3.12, 4.76, 4.76, 4.23, 4.76, 4.326, 3.12, 5.45}};
    string prata, ouro, bronze, cabecalho[9] = {"Nome", "1°", "2°", "3°", "4°", "5°", "Méd", "Menor", "Maior"}, nome[3] = {"Gabriel", "Nociak", "Kaicon"};
    for (i = 0; i < 9; i++)cout<<cabecalho[i]<<"\t";
    cout<<"\n";
    for (i = 0; i < 3 ; i++){
        cout<<nome[i]<<"\t";
        for (j = 0; j < 8; j++){
            cout<<tabela[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for (i = 0; i < 3 ; i++){
        if(i==2)j--;
        for (j = i+1; j < 3 ; j++){
            if(tabela[i][5] > tabela[j][5]){
                //nome
                aux = nome[i];
                nome[i] = nome[j];
                nome[j] = aux;
                //valor
                /*troca = tabela[i][5];
                tabela[i][5] = tabela[j][5];
                tabela[j][5] = troca;*/
            }
        }
    }
    
    for (i = 0; i < 3 ; i++){
        cout<<nome[i]<<"\n";
    }

    return 0;
}