#include <iostream>
#include <windows.h>
#include "Pilha.cpp"
#include <time.h>
#include <string.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    system("cls");
    TipoPilha estante;
    TipoItem livro;
    FazPilhaVazia(&estante);
    //inserindo na pilha automaticamente para facilitar os testes
    for(int i = 0; i < 5; i++){
        livro.id = i;
        strcpy(livro.titulo, "titulo " + i);
        strcpy(livro.autor, "Autor" + i);
        livro.ISBN = rand()%900000000;
        livro.numPG = rand()%200;
        livro.anoLanc = rand()%2100;
        Empilha(&estante, livro);
    }
    //inserção à mão
/*
    for(int i = 0; i < 5; i++){
        cout << "Id: ";
        cin >> livro.id;
        cout << "Título: ";
        cin.getline(livro.titulo, 35);
        cout << "Autor: ";
        cin.getline(livro.autor, 35);
        cout << "ISBN: ";
        cin >> livro.ISBN;
        cout << "Número de Páginas: ";
        cin >> livro.numPG;
        cout << "Ano de lançamento: ";
        cin >> livro.anoLanc;
        Empilha(&estante, livro);
    }
*/
    cout << "\n\nEstante \n\n";
    ExibePilha(&estante);
    cout << "\n\n";
    do{
        Desempilha(&estante, &livro);
        cout << "Livro desempilhado: \n";
        cout << "Id: " << livro.id;
        cout << "\tTítulo: " << livro.titulo;
        cout << "\tAutor: " << livro.autor;
        cout << "\tISBN: " << livro.ISBN;
        cout << "\tNúmero de Páginas: " << livro.numPG;
        cout << "\tAno de lançamento: " << livro.anoLanc;
        cout << "\n\n";
    }while(!VerificaPilhaVazia(&estante));

    return 0;
}