#include <iostream>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

void PreencheeEImprimeVet(int vet[], int n){
    srand(time(NULL));
    //preenche
    for(int i = 0; i < n; i++){
        vet[i] = rand()%10;
    }
}
void imprimeVet(int vet[], int n){
    //Imprime
    cout << "Vetor: \n";
    for(int i = 0; i < n; i++){
        cout << vet[i] << "\t";
    }
}
void PreencheeMat(int mat[5][5], int n){
    srand(time(NULL));
    //preenche
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = rand()%10;
        }
    }
}
void imprimeMat(int n, int mat[5][5]){
    //Imprime
    cout << "Matriz\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}
void imprimeMatQuad(int n, int mat[5][5], double exp){
    //Imprime
    cout << "Matriz Quad\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << pow(mat[i][j], exp) << "\t";
        }
        cout << "\n";
    }
}
void calcDiagPrin(int n, int mat[5][5]){
    int soma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j){
                soma = soma + mat[i][j];
            } 
        }
        cout << "\n";
    }
    cout << "Soma diagonal Principal: " << soma;
}
void FuncMaior(int vet[], int qtd){
    double maior;
    for(int i = 0; i < qtd; i++){
        if(vet[i] > maior)maior = vet[i];
    }
    cout << " maior: " << maior;
}
void FuncMenor(int vet[], int qtd){
    double menor;
    menor = vet[0];
    for(int i = 0; i < qtd; i++){
        if(vet[i] < menor)menor = vet[i];
    }
    cout << " menor: " << menor;
}
