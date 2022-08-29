#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    srand(time(NULL));
    int i, j, result[3] = {0,0,0}, mat[3][3];
    //Preenchendo a matriz de 0 - 99
    for (j = 0; j < 3; j++){
        for (i = 0; i < 3; i++){
            mat[i][j] = rand()%99;
        }
    }
    //Preenchendo o vetor com a soma das colunas
    for (j = 0; j < 3; j++){
        for (i = 0; i < 3; i++){
            result[j] += mat[i][j];
        }
    }
    //Imprimindo a Matriz
    cout << "Matriz:\n";
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
    //Imprimindo o Vetor
    cout << "Vetor de resutados:\n";
    for (i = 0; i < 3; i++){
        cout << result[i] << "\t";
    }
    return 0;
}