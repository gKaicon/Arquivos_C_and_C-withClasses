#include <iostream>
#include <windows.h>
 
using namespace std;

double FuncMenor(double*, int);
double FuncMaior(double*, int);
double FuncMedia(double*);

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int i, j;
    double dist[5], menor, maior, media, qtd = 5, tabela[3][8], placar[3];
    string aux, nome[3] = {"Gabriel", "Amanda", "Bia"}, cabecalho[9] = {"Nome", "1°", "2°", "3°", "4°", "5°", "Méd", "Menor", "Maior"};

    /*
    for(i = 0 ; i < 3 ; i++){
        cout<<"Escreva o "<<i+1<<"° nome: ";
        cin>>nome[i];
    }*/
    system("cls");
    for(j = 0 ; j < 3 ; j++){
        cout<<"\nAtleta: "<<nome[j]<<"\n";
        for(int i = 0; i < 5; i++){
            cout<<"Escreva o "<<i+1<<"° salto: ";
            cin>>dist[i];
            tabela[j][i] = dist[i];

            media = FuncMedia(dist);
            tabela[j][5] = media;

            menor = FuncMenor(dist, qtd);
            tabela[j][6] = menor;

            maior = FuncMaior(dist, qtd);
            tabela[j][7] = maior;

            
        }
    }
    system("cls");
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
    //pódio
    //faz com String ouro, prata, bronze, mesmo esquema do jokempo
    /*
    for (i = 0; i < 3 ; i++){
        if(tabela[i][5] > tabela[i][5]){
            FuncMaior(tabela[i], 7)
        }
    }*/
    
    for (i = 1; i < 3 ; i++){
        cout<<nome[i]<<"\n";
    }


    return 0;
}

double FuncMenor(double distsalto[], int qtd){
    double menor;
    menor = distsalto[0];
    for(int i = 0; i < qtd; i++){
        if(distsalto[i] < menor){
            menor = distsalto[i];
        }
    }
    return menor;
}
double FuncMaior(double distsalto[], int qtd){
    double maior;
    maior = distsalto[0];
    for(int i = 0; i < qtd; i++){
        if(distsalto[i] > maior){
            maior = distsalto[i];
        }
    }
    return maior;
}
double FuncMedia(double distsalto[]){
    double media, soma;
    for(int i = 0; i < 5; i++){
        soma = soma + distsalto[i];
    }
    soma = soma - FuncMenor(distsalto,5);
    media = soma/4;
    return media;
}