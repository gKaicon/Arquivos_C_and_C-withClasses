#include <iostream>
#include <windows.h>

using namespace std;

typedef struct Livro
{
    char titulo[30];
    char categoria[15];
    char autor[20];
    char editora[15];
    int numPag;
    char ano;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    Livro livros[5];
    char proc[30], title[30];

    for (int i = 0; i < 5; i++){
        system("cls");
        cout << "Digite o titulo do livro: ";
        cin.getline(livros[i].titulo, 30);
        cout << "Digite a categoria do livro: ";
        cin.getline(livros[i].categoria, 15);
        cout << "Digite o autor do livro: ";
        cin.getline(livros[i].autor, 20);
        cout << "Digite o nome da editora: ";
        cin.getline(livros[i].editora, 15);
        cout << "Digite a quantidade de paginas tem no livro: ";
        cin >> livros[i].numPag;
        cout << "Digite o ano do livro: ";
        cin >> livros[i].ano;
    }

    system("cls");
    cout << "Digite o titulo do livro que deseja: ";
    cin.getline(proc,30);

    for (int i = 0; i < 5; i++){
        title[i] = livros[i].titulo;
        if(title[i] == proc[i]) {
            cout << "O titulo do livro é: " << livros[i].titulo;
            cout << "A categoria do livro é: " << livros[i].categoria;
            cout << "O autor do livro é: " << livros[i].autor;
            cout << "O nome da editora é: " << livros[i].editora;
            cout << "A quantidade de paginas é de: " << livros[i].numPag << " paginas.";
            cout << "O ano do livro é: " << livros[i].ano;
        }
    }

    return 0;
}
