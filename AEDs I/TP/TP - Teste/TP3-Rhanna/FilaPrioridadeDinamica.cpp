#include "FilaPrioridadeDinamica.hpp"

using namespace std;

void inicializaFila(FilaPrioridadeDinamica *fila)
{
    fila->inicio = NULL;
    fila->tamanho = 0;
}

bool verificaFilaVazia(FilaPrioridadeDinamica *fila)
{
    return (fila->inicio == NULL);
}

void enfileira(FilaPrioridadeDinamica *fila, Atendimento item)
{
    Apontador novo = new Celula;
    novo->item = item;
    novo->prox = NULL;

    Apontador anterior = fila->inicio;
    Apontador atual = fila->inicio;

    if (verificaFilaVazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        while (atual != NULL && atual->item.paciente.prioridade <= item.paciente.prioridade)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == fila->inicio)
        {
            fila->inicio = novo;
            novo->prox = atual;
        }
        else
        {
            anterior->prox = novo;
            novo->prox = atual;
        }
    }

    fila->tamanho++;
}

void desenfileira(FilaPrioridadeDinamica *fila, Atendimento *item)
{
    if (verificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    *item = aux->item;
    fila->inicio = aux->prox;
    delete aux;
    fila->tamanho--;
}

void esvaziaFila(FilaPrioridadeDinamica *fila)
{
    Atendimento item;
    while (!verificaFilaVazia(fila))
    {
        desenfileira(fila, &item);
    }
}

void imprimeFila(FilaPrioridadeDinamica *fila)
{
    if (verificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    Apontador aux = fila->inicio;
    while (aux != NULL)
    {
        cout << "Paciente: " << aux->item.paciente.nome << endl;
        mostraUrgencia(aux->item.paciente);
        cout << "Endereço: " << aux->item.paciente.endereco << endl;
        cout << "Idade: " << aux->item.paciente.idade << endl;
        cout << "Sexo: " << (aux->item.paciente.sexo == 1 ? "Masculino" : "Feminino") << endl;
        cout << "\n";
        aux = aux->prox;
    }
    cout << endl;
}

void mostraUrgencia(Paciente paciente)
{
    string urgencia;
    switch (paciente.prioridade)
    {
    case 0:
        urgencia = "Vermelho";
        break;

    case 1:
        urgencia = "Laranja";
        break;

    case 2:
        urgencia = "Amarelo";
        break;

    case 3:
        urgencia = "Verde";
        break;

    case 4:
        urgencia = "Azul";
        break;
    }

    cout << "Urgência: " << urgencia << endl;
}