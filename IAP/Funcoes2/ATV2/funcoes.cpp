#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;
 
void Menu(){
    cout << "\nMENU PRINCIPAL\n";
    cout << "\n1 - Preencher cartela de aposta";
    cout << "\n2 - Preencher cartela de aposta aleatoriamente";
    cout << "\n3 - Comparar e mostrar Resultado";
    cout << "\n4 - Mostrar cartela da Lotafácil";
    cout << "\n5 - Mostrar a minha cartela";
    cout << "\nEscolha uma opção: ";
}

boolean encontrouValor(int apost[], int v){
    for(int i = 0; i < 15; i++){
        if(apost[i] == v)return true;
        if(apost[i] != v)return false;
    }
}

void sorteio(int vet[]){
    srand(time(NULL));
    int sort;
    for(int i = 0; i < 15; i++){
        sort = rand()%25;
        while(encontrouValor(vet, sort)){
            sort = rand()%25;
        }
        vet[i] = sort;
    }    
}

void PreencherResult(int result[]){
    sorteio(result);
}

void PreencherAposta(int apost[]){
    sorteio(apost);
}

void ordenaResult(int result[]){
    int aux;
    for (int i = 0; i < 15 ; i++){
        for (int j = i+1; j < 15 ; j++){
            if(result[i] > result[j]){
                aux = result[i];
                result[i] = result[j];
                result[j] = aux;
            }
        }
    }
    for (int i = 0; i < 15 ; i++){
            cout << result[i] << "\t";
    }
}

void cmpVetor(int result[], int apost[]){
    int cont = 0, aux;
    //ordenar antes 
    for (int i = 0; i < 15 ; i++){
        for (int j = i+1; j < 15 ; j++){
            if(result[i] > result[j]){
                aux = result[i];
                result[i] = result[j];
                result[j] = aux;
            }
        }
    }

    for (int i = 0; i < 15 ; i++){
        for (int j = i+1; j < 15 ; j++){
            if(apost[i] > apost[j]){
                aux = apost[i];
                apost[i] = apost[j];
                apost[j] = aux;
            }
        }
    }

    //contador de acertos
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            if(result[i] == apost[j])cont = cont + 1;
            else cont = cont + 0;
        }
    }

    //impressão
    cout << "\n\nAcertos: "<< cont <<"\n\n";

    cout << "\nResultado: ";
    for(int i = 0; i < 15; i++){
        cout << result[i] << "\t";
    }

    cout << "\nAposta:    ";
    for(int i = 0; i < 15; i++){
        cout << apost[i] << "\t";
    }

}