#ifndef LISTA_H
#define LISTA_H

using namespace std;

//Projeto
#define MAXTAM 5

typedef int ApontadorLE;

typedef struct Projeto{
    int codigo; // codigo do projeto
    char nome[40];        // nome do projeto
    int horas;            // numero de horas trabalhas no projeto
};
typedef struct ListaSequencialProjeto{
    Projeto itemProjeto[MAXTAM];
    ApontadorLE primeiro, ultimo;
    int tamanho;
};

//Funcionário
typedef struct Funcionario{
    int numero;             // codigo do funcionario
    char nome[40];          // nome do funcionario
    char endereco[40];      // endereco do funcionario
    int dependentes;        // numero de dependentes do funcionario
    ListaSequencialProjeto projeto[5]; // Lista Sequencial que guarda os projetos nos quais o funcionario trabalha
} Funcionario;


typedef struct Celula *Apontador;
typedef struct Celula{
    Funcionario item;
    Apontador prox;
};

typedef struct ListaEncadeadaFuncionario{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho;
};

bool listaProjectCriada = false;
bool listaFuncionarioCriada = false;

//Menus
void menu();
void menuProjeto();
void menuFuncionario();
void menuinclusao();

//Projeto
void criaListaProj(ListaSequencialProjeto *lista);                                  
bool verificalistaVaziaProj(ListaSequencialProjeto *lista);                         
bool verificaListaCheiaProj(ListaSequencialProjeto *lista);                         
bool incluirNaListaProjeto(ListaSequencialProjeto *lista, Projeto item);            //1.1 incluirNaListaProjeto
void listaDeProjetos(ListaSequencialProjeto lista);                                 //1.2 listaDeProjetos
bool pesquisaProjeto(ListaSequencialProjeto *lista, int chave);                     //1.3 pesquisaProjeto
void retiraProjeto(ListaSequencialProjeto *lista, ApontadorLE a, Projeto *item);    //1.4 retiraProjeto

//Funcionario
void CriaListaFunc(ListaEncadeadaFuncionario *lista);
int VerificaListaVazia(ListaEncadeadaFuncionario *lista);
void incluirFunc(ListaEncadeadaFuncionario *lista, Funcionario *item);              //2.1 incluirFunc
void listaDeFunc(ListaEncadeadaFuncionario lista);                                    //2.2 listaFuncionario
int qtdFunc(ListaEncadeadaFuncionario *lista);                                      //2.3 qtdFunc
void pesquisaFunc(ListaEncadeadaFuncionario *lista, int numero);                    //2.4 pesquisaFunc
void ImprimirContraCheque(ListaEncadeadaFuncionario lista);                         //2.5 imprimirContraCheque

void RemoveItemPorId(ListaEncadeadaFuncionario *lista, int numero);                 //2.1.5 removePorID




/*
2.3 incluirFunc
    2.3.1 incluirProjetoFunc
    2.3.2 verificaFuncProjeto
    2.3.3 excluirFuncSemProjeto
    2.3.4 excluirProjetoDoFunc
*/
#endif