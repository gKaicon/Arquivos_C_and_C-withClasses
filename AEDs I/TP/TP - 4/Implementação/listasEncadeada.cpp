#include "cabecListasEncadeada.hpp"

using namespace std;

/*_______________________________________________________________________________________________________________________________________________________________________________ 
                                                                                    LISTA ENCADEADA
  _______________________________________________________________________________________________________________________________________________________________________________*/
void CriaListaVazia(TipoListaLinha *lista){
    lista->primeiro = new Elemento;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
}

bool verificaListaVazia(TipoListaLinha lista){
    return (lista.primeiro->prox == lista.ultimo->prox);
}

void atualizaUltimo(TipoListaLinha *lista){
    Apontador ant = lista->primeiro;
    while(ant->prox != NULL) ant = ant->prox;
    lista->ultimo=ant;
}

void insereListaPrimeiro(TipoListaLinha *lista, TipoRota *item){
    Apontador aux;
    aux = lista ->primeiro->prox;
    lista->primeiro->prox = new Elemento;
    lista -> primeiro -> prox->prox = aux;
    lista -> primeiro ->prox-> item = *item;
    lista->tamanho++;
    atualizaUltimo(lista);
}

void insereListaUltimo(TipoListaLinha *lista, TipoRota *item){
    lista->ultimo->prox = new Elemento;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox=NULL;
    lista->ultimo->item=*item;
    lista->tamanho++;
}

void insereListaAposElemento(TipoListaLinha *lista, TipoRota *item, string id){
    Apontador aux, pAux, x;
    bool find = false;
    pAux = lista->primeiro->prox;
    while (pAux != NULL){
        if (pAux->item.id == id){
            find = true;
            x = pAux;
            aux = x->prox;
            x->prox = new Elemento;
            x->prox->prox = aux;
            x->prox->item = *item;
            break;
        }
        pAux = pAux->prox;
    }
    if (find){
        atualizaUltimo(lista);
        lista->tamanho++;
    }
    else cout << "Elemento anterior não encontrado na lista.";
}

void imprimeLista(TipoListaLinha *lista){
    Apontador anterior = lista->primeiro->prox;
    do{
        cout << anterior->item.id << endl;
        anterior = anterior->prox;
    }while(anterior != NULL);
}

string pesquisaItem(TipoListaLinha *lista, string id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            return aux->item.id;
        }
        aux = aux->prox;
    }
    return "-1";
}

void imprimeItem(TipoListaLinha *lista, string id){
    Apontador aux;
    aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item.id == id){
            cout << "Companhia: " << aux->item.companhia << endl;
            cout << "Paradas: " << endl;
            imprimeListaD(&aux->item.cidades);
            break;
        }
        aux = aux->prox;
    }
}

void removeListaPrimeiro(TipoListaLinha *lista){
    if (verificaListaVazia(*lista)) return;
    Apontador aux;
    aux = lista->primeiro->prox;
    lista->primeiro->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

void removeListaUltimo(TipoListaLinha *lista){
    if (verificaListaVazia(*lista))return;

    Apontador aux, atual;
    atual = lista->primeiro->prox;
    aux = lista->ultimo;
    while (atual->prox != lista->ultimo) atual = atual->prox;
    atual->prox = NULL;
    lista->ultimo = atual;
    delete aux;
    lista->tamanho--;
}

void removeItemPorId(TipoListaLinha *lista, string id){
    if (verificaListaVazia(*lista))return;
    Apontador aux, anterior, x;
    x = lista->primeiro;
    while (x != NULL){
        if (x->prox->item.id == id){
            anterior = x;
            break;
        }
        x = x->prox;
    }
    aux = anterior->prox;
    anterior->prox = aux->prox;
    delete aux;
    lista->tamanho--;
}

/*_______________________________________________________________________________________________________________________________________________________________________________ 
                                                                LISTA DUPLAMENTE ENCADEADA
  _______________________________________________________________________________________________________________________________________________________________________________*/


void criaListaVaziaD(TipoListaRota *lista){
    lista->primeiro = new ElementoL;
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = lista->ultimo;
    lista->ultimo->ant = lista->ultimo;
    lista->tamanho = 0;
}

bool listaVaziaD(TipoListaRota *lista){
    if (lista->tamanho == 0 && lista->ultimo == lista->primeiro) return true;
    return false;
}

void insereItemUltimoD(TipoListaRota *lista, TipoLinha item){
    lista->ultimo->prox = new ElementoL;
    lista->ultimo->prox->ant = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = lista->primeiro;
    lista->primeiro->ant = lista->ultimo;
    lista->tamanho++;
}

void insereItemPrimeiroD(TipoListaRota *lista, TipoLinha item){
    ApontadorL inserido = new ElementoL;
    inserido->item = item;
    inserido->prox = lista->primeiro->prox;
    inserido->ant = lista->primeiro;
    lista->primeiro->prox->ant = inserido;
    lista->primeiro->prox = inserido;
    lista->tamanho++;
}

ApontadorL localizaItemPorIdD(TipoListaRota *lista, int id){
    ApontadorL aux = lista->primeiro->prox;
    while (aux != lista->primeiro){
        if (aux->item.id == id) return aux;
        aux = aux->prox;
    }
    return NULL;
}

void insereItemAposElementoD(TipoListaRota *lista, TipoLinha item, int id){
    ApontadorL atual = localizaItemPorIdD(lista, id);    
    ApontadorL inserido = new ElementoL;
    inserido->item = item;

    if (atual == NULL){
        cout << "Id inexistente!" << endl;
        return;
    }
    if (atual == lista->ultimo){
        insereItemUltimoD(lista, item);
    }
    else{
        inserido->prox = atual->prox;
        inserido->ant = atual;
        inserido->prox->ant = inserido;
    }
    atual->prox = inserido;
    lista->tamanho++;
}

TipoLinha retiraItemPorIdD(TipoListaRota *lista, int id){
    ApontadorL atual = localizaItemPorIdD(lista, id);
    TipoLinha retorno;
    retorno.id = -1;

    if (listaVaziaD(lista)) return retorno;
    if (atual != lista->primeiro){
        atual->ant->prox = atual->prox;
        if (atual == lista->ultimo){
            lista->ultimo = atual->ant;
            lista->primeiro->ant = lista->ultimo;
        }
        else atual->prox->ant = atual->ant;
        retorno = atual->item;
        delete atual;
    }
    lista->tamanho--;
    return retorno;
}

void imprimeItemD(TipoLinha item){
    if (item.id == -1){
        cout << "Item inexistente!" << endl;
        return;
    }
    cout << "\tID: " << item.id << endl;
    cout << "\tCidade: " << item.nome << endl;
    cout << "\tHorario de Saida: " << item.saida << endl;
    cout << "\tPreco da passagem: " << item.valor_passagem << endl << endl;
}

void imprimeListaD(TipoListaRota *lista){
    ApontadorL aux = lista->primeiro->prox;
    while (aux != lista->primeiro){
        imprimeItemD(aux->item);
        aux = aux->prox;
    }
    system("PAUSE");
}

void imprimeListaReversaD(TipoListaRota *lista){
    ApontadorL aux = lista->ultimo;
    while (aux != lista->primeiro){
        imprimeItemD(aux->item);
        aux = aux->ant;
    }
}