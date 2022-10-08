#include "pilha.hpp"

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

void imprimePilha(Pilha pilha, bool imprimirProdutos){
    for (int i = pilha.topo - 1; i >= 0; i--){
        Pedido pedido = pilha.pedidos[i];
        imprimePedido(pedido, imprimirProdutos);
    }
}

void imprimePedido(Pedido pedido){
    cout << "Cód. Pedido: " << pedido.codigo << endl;
        cout << "\tProdutos: " << endl;
        for (int i = 0; i < pedido.total_produtos; i++){
            int codigoProduto = pedido.produtos[i];
            Produto produto = menu[codigoProduto - 1];
            cout << "\t\tCód. Produto: " << produto.codigo << endl;
            cout << "\t\tNome: " << produto.nome << endl;
            cout << "\t\tValor do Produto: " << produto.valor_produto << endl;
            cout << '\n';
        }
    cout << "Valor Total do Pedido: R$" << pedido.valor_pedido << endl;
    cout << "Distância: " << pedido.distancia << " m\n";
}


Pilha OrdenaPilha(Pilha pilha){
    Pilha auxPilha;
    InicializaPilha(&auxPilha);

    while (!PilhaVazia(pilha)){
        Pedido pedido = TopoPilha(pilha); //pega o topo da pilha dada como parametro
        Desempilha(&pilha); //desempilha da pilha dada como paramentro
        while (!PilhaVazia(auxPilha) && TopoPilha(auxPilha).distancia < pedido.distancia){ 
//o pedido do topo da pilha auxiliar tiver a distancia menor que a distancia do pedido da lista dada como parametro
            Empilha(&pilha, TopoPilha(auxPilha)); //empilha na pilhaparametro o que tá no topo da pilha auxiliar
            Desempilha(&auxPilha);//removo o ultimo item da pilha auxiliar
        }
        Empilha(&auxPilha, pedido);
    }
    return auxPilha;
}

Pedido TopoPilha(Pilha pilha){
    return pilha.pedidos[pilha.topo - 1];
}

int TamanhoPilha(Pilha pilha){
    return pilha.topo;
}














void Lista_Inicializa(ListaSequencial *lista){
    if (!lista->listaCriada){
        lista->listaCriada = true;
        lista->tamanho = 0;
    }
}

bool Lista_Vazia(ListaSequencial lista){
    return lista.tamanho == 0;
}

bool Lista_Cheia(ListaSequencial lista){
    return lista.tamanho == MAX_ENTREGA;
}

bool Lista_Insere(ListaSequencial *lista, Pedido pedido){
    if (!lista->listaCriada || Lista_Cheia(*lista)){
        return false;
    }
    lista->pedidos[lista->tamanho] = pedido;
    lista->tamanho++;
    return true;
}

void Lista_Imprime(ListaSequencial lista){
    for (int i = 0; i < lista.tamanho; i++){
        Pedido pedido = lista.pedidos[i];
        imprimePedido(pedido, true);
    }
}

bool Lista_Remove_Id(ListaSequencial *lista, int id){
    if (Lista_Vazia(*lista)){
        return false;
    }

    for (int i = id; i < lista->tamanho; i++){
        lista->pedidos[i] = lista->pedidos[i + 1];
    }

    lista->tamanho--;
    return true;
}

bool Lista_Remove(ListaSequencial *lista, Pedido pedido){
    if (Lista_Vazia(*lista)){
        cout << "Erro: Lista está vazia" << endl;
        return false;
    }

    int indice = IndeceDe(*lista, pedido);

    if (indice == -1){
        return false;
    }

    return Lista_Remove_Id(lista, indice);
}

int IndeceDe(ListaSequencial lista, Pedido pedido){
    for (int i = 0; i < lista.tamanho; i++){
        if (lista.pedidos[i].codigo == pedido.codigo){
            return i;
        }
    }
    return -1;
}

int Lista_Tamanho(ListaSequencial lista){
    return lista.tamanho;
}