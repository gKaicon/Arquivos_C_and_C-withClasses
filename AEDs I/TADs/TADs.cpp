#include <iostream>
#include <windows.h>
 
using namespace std;

typedef struct TipoItem{
    int chave;
};
typedef struct TipoLista{
    TipoItem *item;
};

void CriaListaVazia(TipoLista lista[], int tam){
    lista = new int[tam];
}
void VerificaListaVazia(TipoLista lista){

}
void InsereLista(TipoLista *lista, TipoItem item){

}
void RetiraLista(TipoLista *lista, TipoItem *item){

}
void ImprimeLista(TipoLista *lista){

}