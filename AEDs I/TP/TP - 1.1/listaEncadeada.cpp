#include "listaEncadeada.hpp"

void CriaListaEncadeadaVazia(ListaEncadeada *lista)
{
    if (!lista->foiCriada)//se a lista não foi criada
    {
        lista->primeiro = new Celula; //no apontador primeiro recebe uma nova Celula
        lista->ultimo = lista->primeiro; //o primeiro apontador recebe o último, pois trata-se de uma lista vazia
        lista->ultimo->prox = NULL; //o apontador prox do apontador ultimo, recebe null
        lista->foiCriada = true; //e a lista foi criada
    }
    else
    {
        cout << "Lista já foi criada" << endl;
        Sleep(1000);
    }
}

bool ListaEncadeadaEstaVazia(ListaEncadeada *lista)
{
    return (lista->primeiro == lista->ultimo); //se o primeiro é igual ao último significa que não há nada entre os dois
}

void InsereListaEncadeadaUltimo(ListaEncadeada *lista, Funcionario *funcionario)//insere no último
{
    lista->ultimo->prox = new Celula; //o apontador prox do apontador ultimo, recebe uma nova célula
    lista->ultimo = lista->ultimo->prox; //o apontador ultimo, recebe o apontador da celula dentro dele já alterado
    lista->ultimo->item = funcionario;//aloca o funcionario na celula
    lista->ultimo->prox = NULL; //o apontador prox do apontador ultimo, recebe null, após as trocas
    lista->tamanho++;//lista aumenta de tamanho
}

void ImprimeFuncionario(Funcionario *funcionario)
{
    //impressão do funcionario
    cout << "ID: " << funcionario->id << endl;
    cout << "Nome: " << funcionario->nome << endl;
    cout << "Endereço: " << funcionario->endereco << endl;
    cout << "Número de Dependentes: " << funcionario->dependentes << endl;
    cout << "\nLista de Projetos: " << endl;
    ImprimeListaSequencial(&funcionario->projetos); //impressão da lista de projetos atribuídos a ele
}

Funcionario *PesquisaFuncionario(ListaEncadeada *lista, int id)
{
    Apontador aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        if (aux->item->id == id)
        {
            return aux->item; // Retorna o local da memória do funcionario caso o id do mesmo seja o passado como parâmetro
        }
        aux = aux->prox;//percorrer o while
    }
    return NULL; // Retorna NULL caso o funcionário procurado não esteja na lista
}

void RemoveFuncionario(ListaEncadeada *lista, Funcionario funcionario)
{
    if (!ListaEncadeadaEstaVazia(lista))
    {
        Apontador aux, anterior, x;

        x = lista->primeiro;

        while (x != NULL)
        {
            if (x->prox->item->id == funcionario.id)
            {
                anterior = x;//salva o anterior a x, para ser passada para a variavel auxiliar(aux)
                break;
            }
            x = x->prox; //incremento do laço para encontrar o funcionario desejado
        }
        aux = anterior->prox; //aux recebe o próximo valor após o anterior(último valor)
        anterior->prox = aux->prox; //anterior->prox recebe o último
        delete aux; // desaloca o auxiliar da memória
        lista->tamanho--;//diminui da lista
        AtualizaUltimo(lista);//atualiza após a remoção
    }
}

void AtualizaUltimo(ListaEncadeada *lista)
{
    Apontador aux, anterior;
    aux = lista->primeiro;
    anterior = aux;

    while (aux != NULL)
    {
        anterior = aux; //salva o anterior ao aux->prox na variavel anterior
        aux = aux->prox; //incrementa o laço
    }

    lista->ultimo = anterior;
}

int TamanhoListaEncadeada(ListaEncadeada *lista)
{
    return lista->tamanho;
}