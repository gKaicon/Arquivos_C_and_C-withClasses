#include <iostream>
#include <windows.h>

using namespace std;


typedef struct Habitante{
    double salario;
    int idade;
    int numFilho;
    char sexo;
};

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    double somaSa, somaFi, mediaSa, mediaFi, maiorSa, percMulher;
    Habitante h[20];
    for(int i = 0; i < 20; i++){
        cout << "Informe o salário: R$ ";
        cin >> h[i].salario;
        cout << "Informe a idade: ";
        cin >> h[i].idade;
        cout << "Informe a quantidade de filhos: ";
        cin >> h[i].numFilho;
        cout << "Informe o sexo: ";
        cin >> h[i].sexo;
    }
    //média de salário da população
    for(int i = 0; i < 20; i++){
        somaSa = somaSa + h[i].salario;
    }
    mediaSa = somaSa/20;

    //média de número de filhos da população
    for(int i = 0; i < 20; i++){
        somaFi = somaFi + h[i].numFilho;
    }
    mediaSa = somaFi/20;
    
    //média de número de mulheres com salário abaixo de 1000
    for(int i = 0; i < 20; i++){
        if(h[i].sexo == 'F' || h[i].sexo == 'f' && h[i].salario <= 1000){
            //comente
        }
    }
    return 0;
}
