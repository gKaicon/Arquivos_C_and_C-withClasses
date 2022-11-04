#ifndef LISTA_H
#define LISTA_H

#define MAXTAM 5

typedef int TipoApontador;

typedef struct TipoItemAluno{
    char nome[35];
    int matricula;
    char turma;
    double n1, n2, n3;
};

typedef struct TipoListaTurma{
    TipoItemAluno Item[MAXTAM]; //vetor de alunos
    TipoApontador Primeiro, Ultimo;//Apontador para?
    int tamanho;
};

bool listaCriada = false;

void Menu();
void CriaTurmaVazia(TipoListaTurma *lista);                                     // Cria uma lista vazia
int VerificaListaVazia(TipoListaTurma *lista);                                  // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
int VerificaListaCheia(TipoListaTurma *lista);                                  // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
int InsereItem(TipoListaTurma *lista, TipoItemAluno item);                      // Insere ITEM (chave) na lista TipoLista
void ImprimeLista(TipoListaTurma lista);                                        // Imprime a lista
int PesquisaItem(TipoListaTurma *lista, int chave);                             // Pesquisa um ITEM (chave) na lista TipoLista
void RetiraItem(TipoApontador p, TipoListaTurma *lista, TipoItemAluno *item);   // Remove um item da lista pela sua posição
int TamanhoLista(TipoListaTurma *lista);                                        // Retorna o número de itens da lista

#endif