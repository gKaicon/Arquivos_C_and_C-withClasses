#include "sistema.hpp"
//------------------------------------------TADs Pilha---------------------------------------------------
void InicializaPilha(Pilha *pilha){
    pilha->topo = 0;
}

bool PilhaVazia(Pilha pilha){
    return pilha.topo == 0;
}

bool PilhaCheia(Pilha pilha){
    return pilha.topo == MAX_ENTREGA;
}

void Empilha(Pilha *pilha, Pedido pedido){
    if (!PilhaCheia(*pilha)){
        pilha->pedidos[pilha->topo] = pedido;
        pilha->topo++;
    }
}

bool Desempilha(Pilha *pilha){
    if (!PilhaVazia(*pilha)){
        pilha->topo--;
        return true;
    }
    return false;
}

void imprimePilha(Pilha pilha){
    for (int i = pilha.topo - 1; i >= 0; i--){
        Pedido pedido = pilha.pedidos[i];
        imprimePedido(pedido);
    }
}

void imprimePedido(Pedido pedido){
    cout << "Código pedido: " << pedido.codigo << endl;
        cout << "\tProdutos: \n";
        for (int i = 0; i < pedido.totalprodutos; i++){
            int codigoProduto = pedido.codprodutos[i];
            Produto produto = menu[codigoProduto - 1];
            cout << "\t\tCódigo: " << produto.codigo << endl;
            cout << "\t\tNome: " << produto.nome << endl;
            cout << "\t\tValor do produto: " << produto.valor << endl;
            cout << '\n';
        }
    cout << "Valor total do pedido: R$" << pedido.valorPedido << endl;
    cout << "Distância: " << pedido.distancia << " km\n";
}

int TamanhoPilha(Pilha pilha){
    return pilha.topo;
}

Pilha OrdenaPilha(Pilha pilha){ //vou chamar essa pilha do paramentro de parametroPilha nos comentários
    Pilha auxPilha;
    InicializaPilha(&auxPilha);

    while (!PilhaVazia(pilha)){
        Pedido pedido = TopoPilha(pilha); //pega o topo da parametroPilha e armazena na variavel pedido
        Desempilha(&pilha); //desempilha da parametroPilha

        //enquanto o topo da auxPilha tiver a distancia menor que a distancia do pedido da parametroPilha
        while (!PilhaVazia(auxPilha) && TopoPilha(auxPilha).distancia < pedido.distancia){
            Empilha(&pilha, TopoPilha(auxPilha)); //empilha na pilhaparametro o que tá no topo da pilha auxiliar
            Desempilha(&auxPilha);//removo o ultimo item da pilha auxiliar
        }//não vai sair do laço enquanto, o pedido for maior que o topo da auxiliar
        Empilha(&auxPilha, pedido); //quando sair significa que achou um valor maior, aí no meio do laço os itens menores são empilhados novamente
    }
    return auxPilha;
}

Pedido TopoPilha(Pilha pilha){
    return pilha.pedidos[pilha.topo - 1];
}

//------------------------------------------TADs Lista-----------------------------------------------------
void CriaListaVazia(ListaSequencial *lista){
    if (!lista->listaCriada){
        lista->listaCriada = true;
        lista->tamanho = 0;
    }
}

bool VerificaListaVazia(ListaSequencial lista){
    return lista.tamanho == 0;
}

bool VerificaListaCheia(ListaSequencial lista){
    return lista.tamanho == MAX_ENTREGA;
}

bool inserirLista(ListaSequencial *lista, Pedido pedido){
    if (!lista->listaCriada || VerificaListaCheia(*lista)) return false;
    lista->pedidos[lista->tamanho] = pedido;
    lista->tamanho++;
    return true;
}

void imprimeLista(ListaSequencial lista){
    for (int i = 0; i < lista.tamanho; i++){
        Pedido pedido = lista.pedidos[i];
        imprimePedido(pedido);
    }
}

bool RemoveIdLista(ListaSequencial *lista, int id){
    if (VerificaListaVazia(*lista))return false;
    for (int i = id; i < lista->tamanho; i++)lista->pedidos[i] = lista->pedidos[i + 1];
    lista->tamanho--;
    return true;
}

bool ListaRemove(ListaSequencial *lista, Pedido pedido){
    if (VerificaListaVazia(*lista)){
        cout << "Erro: Lista está vazia\n";
        return false;
    }
    int indice = procuraIndice(*lista, pedido);
    if (indice == -1)return false;
    return RemoveIdLista(lista, indice);
}

int procuraIndice(ListaSequencial lista, Pedido pedido){
    for (int i = 0; i < lista.tamanho; i++){
        if (lista.pedidos[i].codigo == pedido.codigo) return i;
    }
    return -1;
}

int TamanhoLista(ListaSequencial lista){
    return lista.tamanho;
}