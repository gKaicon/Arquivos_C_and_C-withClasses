#include <iostream>
#include <windows.h>
#include "Pilha.cpp"
 
using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");    

    TipoItem item;
    TipoPilha pilhaPar, pilhaImpar, descarte;    

    FazPilhaVazia(&pilhaPar);
    FazPilhaVazia(&pilhaImpar);
    FazPilhaVazia(&descarte);

    for(int i = 0; i < 10; i++){
        cin >> item.id;
        if(item.id % 2 == 0 && item.id != 0) Empilha(&pilhaPar, item);
        if(item.id % 2 != 0) Empilha(&pilhaImpar, item);
        if(item.id == 0) {
            if(VerificaPilhaVazia(&pilhaImpar)){
                cout << "Pilha Impar Vazia";
            }
            if(!VerificaPilhaVazia(&pilhaImpar)){
                Desempilha(&pilhaImpar, &item);
                Empilha(&descarte, item);
            }
            if(VerificaPilhaVazia(&pilhaPar)){
                cout << "Pilha Par Vazia";
            }
            if(!VerificaPilhaVazia(&pilhaPar)){
                Desempilha(&pilhaPar, &item);
                Empilha(&descarte, item);
            }
        }
    }
    
    cout << "Pilha Par: " << endl;
    ExibePilha(&pilhaPar);
    cout << "Pilha Impar: " << endl;
    ExibePilha(&pilhaImpar);
    cout << "Pilha Descarte: " << endl;
    ExibePilha(&descarte);
    return 0;
}