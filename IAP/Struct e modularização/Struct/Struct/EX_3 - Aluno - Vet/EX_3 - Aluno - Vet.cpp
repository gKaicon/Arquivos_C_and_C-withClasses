#include <iostream>
#include <windows.h>

using namespace std;

typedef struct Aluno{
    char nome[45];
    int RA;
    char curso[45];
};

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    struct Aluno vet_Aluno[5];
    
    for (int i = 0; i < 5; i++){
        system("cls");
        vet_Aluno[i].RA = 48600 + i;
        cout << "Nome do " << (i+1) << "° aluno : ";
        cin.getline(vet_Aluno[i].nome, 45);
        cout << "Curso do aluno " << (i+1) << ": ";
        cin.getline(vet_Aluno[i].curso, 45);
    }
    system("cls");

    for (int i = 0; i < 5; i++){
        cout << "Registro Acadêmico:" << vet_Aluno[i].RA;
        cout << "\t\tNome: " << vet_Aluno[i].nome;
        cout << "\tCurso: " << vet_Aluno[i].curso;
        cout << "\n\n";
    }

    return 0;
}