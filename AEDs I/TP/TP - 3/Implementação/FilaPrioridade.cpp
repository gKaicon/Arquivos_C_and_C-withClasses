#include "FilaPrioridade.hpp"

using namespace std;

void inicializaFila(FilaPrioridadeDinamica *fila){
    fila->inicio = NULL;
    fila->tamanho = 0;
}

bool verificaFilaVazia(FilaPrioridadeDinamica *fila){
    return (fila->inicio == NULL);
}

void enfileira(FilaPrioridadeDinamica *fila, Atendimento item){
    Apontador cel = new Celula;
    cel->item = item; //dentro da célula tem um item
    cel->prox = NULL; //e o apontador da célula acima recebe null
    Apontador anterior = fila->inicio; //guardar a primeira posição que será usada para percorrer a fila
    Apontador atual = fila->inicio; //guardar a primeira posição que será usada para percorrer a fila

    if (verificaFilaVazia(fila)) fila->inicio = cel; //se a fila for vazia, insere na primeira posição
    else{ //se não ele procura onde inserir
        while (atual != NULL && (atual->item.paciente.prioridade <= item.paciente.prioridade)){ 
            //condição acima serve para verificar se a prioridade do item inserido é maior, que os itens já inseridos
            anterior = atual; //se não for, ele troca os valores de anterior e atual, guardando sempre o último de maior prioridade
            atual = atual->prox;
        }

        if (atual == fila->inicio){//se ao sair do while, o atual, for a primeira posição, a inserção é feita
            fila->inicio = cel; //primeira posição recebe a célula criada
            cel->prox = atual;//apontador recebe null
        }
        else{
            anterior->prox = cel; // o valor antes de atual, vai receber como próximo a célula
            cel->prox = atual; //o apontador prox recebe null, para realizar a próxima inserção
        }
    }
    fila->tamanho++;
}

void desenfileira(FilaPrioridadeDinamica *fila, Atendimento *item){
    if (verificaFilaVazia(fila)){
        cout << "Fila vazia!" << endl;
        return;
    }
    //a remoção é feita no inicio da fila
    Apontador aux = fila->inicio;
    *item = aux->item;
    fila->inicio = aux->prox;
    delete aux;
    fila->tamanho--;
}

void esvaziaFila(FilaPrioridadeDinamica *fila){
    Atendimento item;
    while (!verificaFilaVazia(fila)){
        desenfileira(fila, &item);
    }
}

void imprimeFila(FilaPrioridadeDinamica *fila){
    if (verificaFilaVazia(fila)){
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL) {
        cout << "Paciente: " << aux->item.paciente.nome << endl;
        mostraUrgencia(aux->item.paciente);
        cout << "Endereço: " << aux->item.paciente.endereco << endl;
        cout << "Idade: " << aux->item.paciente.idade << endl;
        cout << "Sexo: " << (aux->item.paciente.sexo == 1 ? "Masculino" : "Feminino") << endl;
        cout << "\n";
        aux = aux->prox;
    }
    cout << "\n";
}

void mostraUrgencia(Paciente paciente){
    string urgencia;
    if(paciente.prioridade == 0) urgencia = "Vermelho";
    if(paciente.prioridade == 1) urgencia = "Laranja";
    if(paciente.prioridade == 2) urgencia = "Amarelo";
    if(paciente.prioridade == 3) urgencia = "Verde";
    if(paciente.prioridade == 4) urgencia = "Azul";
    cout << "Urgência: " << urgencia << endl;
}