#include "listaSequencial.hpp"

void CriaListaSequencialVazia(ListaSequencial *lista)
{
    if (!lista->listaCriada)
    {
        lista->listaCriada = true; //lista recebe true
        lista->tamanho = 0; //por se tratar de uma espécie de "vetor", basta inicar em 0
    }
}

bool ListaSequencialEstaVazia(ListaSequencial *lista)
{
    return lista->tamanho == 0; //verifica se ela está vazia
}

bool ListaSequencialEstaCheia(ListaSequencial *lista)
{
    return lista->tamanho == MAX_TAM; //verifica se ela está cheia, caso o tamanho tenha atingido seu limite
}

bool InsereProjeto(ListaSequencial *lista, Projeto projeto)
{
    if (!lista->listaCriada || ListaSequencialEstaCheia(lista))//se a lista não foi criada ou está cheia
    {
        return false; //return false
    }
    lista->item[lista->tamanho] = projeto; //insere o projeto na última posição, ou seja no tamanho atual dela
    lista->tamanho++; //e aumenta o tamanho para que possa ser realizada uma nova inserção.
    return true;
}

void ImprimeListaSequencial(ListaSequencial *lista)
{
    for (int i = 0; i < lista->tamanho; i++)//percorre todos os projetos já inseridos
    {
        Projeto projeto = lista->item[i];
        ImprimeProjeto(projeto); //imprime por meio de uma função escrita abaixo
    }
}

Projeto *PesquisaProjetoPorID(ListaSequencial *lista, int id)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (id == lista->item[i].id)
        {
            return &lista->item[i]; // Retorna o endereço na memória do item(Projeto) encontrado
        }
    }
    return NULL; // se não for encontrado retorna NULL, pois o projeto não existe.
}

void ImprimeProjeto(Projeto projeto) //impressão básica
{
    cout << "ID: " << projeto.id << endl;
    cout << "Nome: " << projeto.nome << endl;
    cout << "Horas Trabalhadas: " << projeto.horas << endl;
    cout << "\n";
}

bool RemoveProjetoPorId(ListaSequencial *lista, int id)
{
    if (ListaSequencialEstaVazia(lista)) //se a lista estuiver vazia ele não executa
    {
        return false;
    }

    for (int i = id; i < lista->tamanho; i++)//percorre a lista buscando esse id
    {
        lista->item[i] = lista->item[i + 1];//o projeto é sobrescrito pelo proximo projeto
    }
    lista->tamanho--;//lista diminui de tamanho

    return true;
}

bool RemoveProjeto(ListaSequencial *lista, Projeto projeto) //valida se o indice foi achado para só assim executar a exclusão
{
    if (ListaSequencialEstaVazia(lista))
    {
        cout << "Erro: Lista está vazia" << endl;
        return false;
    }

    int indice = IndeceDe(lista, projeto);//o indice encontrado é armazenado na variável "indice"

    if (indice == -1)
    {
        return false;
    }

    return RemoveProjetoPorId(lista, indice); //indice utilizado para remover de fato o projeto
}

int IndeceDe(ListaSequencial *lista, Projeto projeto) //procura o indice
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        if (lista->item[i].id == projeto.id)
        {
            return i; //retorna o indice em que o projeot está
        }
    }
    return -1;
}


int TamanhoListaSequencial(ListaSequencial *lista)
{
    return lista->tamanho;
}
