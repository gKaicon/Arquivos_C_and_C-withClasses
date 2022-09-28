#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <windows.h>
#define fileName "listaDeFuncionarios.bin"
#define OPCAO_SAIDA 8
#define MAX_TAM 5 //tamanho máximo de projetos

using namespace std;

/////////////////////////////////// LISTA SEQUENCIAL ///////////////////////////////////////
typedef struct Projeto{
    int id;        // codigo do projeto
    char nome[30]; // nome do projeto
    int horas;     // numero de horas trabalhas no projeto
};

typedef struct ListaSequencial{
    Projeto item[MAX_TAM]; //vetor de tamanho máximo de projetos
    int tamanho; //tamanho(que sempre é menor ou igual a 5)
    bool listaSequencialCriada = false; //variavel booleana para criação de listas
};


/////////////////////////////////// LISTA ENCADEADA ///////////////////////////////////////
typedef struct Funcionario{
    int id;                    //id do funcionário
    char nome[100];            //nome do funcionário
    char endereco[40];         //endereço do funcionário
    int dependentes;           //numero de dependentes do funcionário
    ListaSequencial projetos;  //Lista de Projetos alocados em um campo de funcionário
};

typedef struct Celula *Apontador; //"construtor" da celula

typedef struct Celula{
    Funcionario *item; //funcionario que é colocado dentro da celula
    Apontador prox; //Apontador para a proxima célula
};

typedef struct ListaEncadeada{ //Lista de encadeada
    Apontador primeiro; //apontador da primeira posição
    Apontador ultimo;   //apontador da última posição
    int tamanho = 0;    //tamanho da lista
    bool listaEncadeadaCriada = false; //variavel booleana para indicar se a lsita foi criada ou não
};


void menu();

// FUNÇÕES DA LISTA SEQUENCIAL

void CriaListaSequencialVazia(ListaSequencial *lista);
bool ListaSequencialEstaVazia(ListaSequencial *lista);
bool ListaSequencialEstaCheia(ListaSequencial *lista);
bool InsereProjeto(ListaSequencial *lista, Projeto projeto);
void ImprimeProjeto(Projeto projeto);
void ImprimeListaSequencial(ListaSequencial *lista);
Projeto *PesquisaProjetoPorID(ListaSequencial *lista, int id);
bool RemoveProjetoPorId(ListaSequencial *lista, int id);
bool RemoveProjeto(ListaSequencial *lista, Projeto projeto);
int IndiceDeProjeto(ListaSequencial *lista, Projeto projeto);
int TamanhoListaSequencial(ListaSequencial *lista);
// FUNÇÕES DA LISTA ENCADEADA

void CriaListaEncadeadaVazia(ListaEncadeada *lista);
bool ListaEncadeadaEstaVazia(ListaEncadeada *lista);
void InsereListaEncadeadaUltimo(ListaEncadeada *lista, Funcionario *funcionario);
void ImprimeFuncionario(Funcionario *funcionario);
Funcionario *PesquisaFuncionario(ListaEncadeada *lista, int id);
void RemoveFuncionario(ListaEncadeada *lista, Funcionario funcionario);
void AtualizaUltimo(ListaEncadeada *lista);
int TamanhoListaEncadeada(ListaEncadeada *lista);

// FUNÇÕES DO SISTEMA 
void incluiNovoFuncionario(ListaEncadeada *lista);
Funcionario *criaFuncionario();
void incluiNovosProjetos(ListaEncadeada *lista);
Funcionario *FuncionarioPorID(ListaEncadeada *lista);
void incluiNovoProjeto(Funcionario *funcionario);
void criaProjeto(ListaSequencial *lista, Projeto *projeto);
void excluiProjetos(ListaEncadeada *lista);
void excluiFuncionariosSemProjetos(ListaEncadeada *lista);
void ImprimeListaFunc(ListaEncadeada *lista);
void consultaFuncionario(ListaEncadeada *lista);
int totalHorasSemanais(ListaSequencial lista);
double calculaSalarioBruto(Funcionario *funcionario);
void imprimeContraCheque(ListaEncadeada *lista);


// FUNÇÕES DE MANIPULAÇÃO DE ARQUIVOS
bool carregaArquivo(ListaEncadeada *lista);
bool salvaArquivo(ListaEncadeada *lista);

/*
void ImprimeProjeto(Projeto projeto);
void CriaListaSequencialVazia(ListaSequencial *lista);         // Cria uma lista vazia
bool ListaSequencialEstaVazia(ListaSequencial *lista);         // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
bool ListaSequencialEstaCheia(ListaSequencial *lista);         // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
bool InsereProjeto(ListaSequencial *lista, Projeto projeto);   // Insere Projeto na lista ListaSequencial
void ImprimeListaSequencial(ListaSequencial *lista);           // Imprime a lista
Projeto *PesquisaProjetoPorID(ListaSequencial *lista, int id); // Pesquisa um Projeto via ID na lista ListaSequencial
bool RemoveProjetoPorId(ListaSequencial *lista, int id);       // Remove um Projeto da lista via ID
bool RemoveProjeto(ListaSequencial *lista, Projeto projeto);   // Remove um Projeto da lista
int IndeceDe(ListaSequencial *lista, Projeto projeto);         // Retorna o indice do projeto na lista, -1 se não tiver o projeto
int TamanhoListaSequencial(ListaSequencial *lista);            // Retorna o número de itens da lista


void ImprimeFuncionario(Funcionario *funcionario);
void CriaListaEncadeadaVazia(ListaEncadeada *lista); //sem retorno, apenas cria uma lista vazia com uma celula
bool ListaEncadeadaEstaVazia(ListaEncadeada *lista); //true = lista com celula sem item, e false = lista com uma celula com item
void InsereListaEncadeadaUltimo(ListaEncadeada *lista, Funcionario *funcionario); //sem retorno, apenas inserir no final da lista
Funcionario *PesquisaFuncionario(ListaEncadeada *lista, int id); //retorna um funcionario, de acordo com o id informado
void RemoveFuncionario(ListaEncadeada *lista, Funcionario funcionario); //remover o funcionario, que é passado no parametro
void AtualizaUltimo(ListaEncadeada *lista); //atualiza o apontador ultimo na lista
int TamanhoListaEncadeada(ListaEncadeada *lista); //retorna a quantidade de funcionarios inseridos até o momento



bool carregaArquivo(ListaEncadeada *lista); //carregar e inserir na lista os funcionários cadastrados anteriormente
void menu(); //menu criado
void incluiNovoFuncionario(ListaEncadeada *lista);//feito para adicionar o funcionario retornado na função criaFuncionario
Funcionario *criaFuncionario();//exibe um menu de criação de funcionário, que retorna um funcionario
void incluiNovosProjetos(ListaEncadeada *lista); //incluir mais projetos para o funcionario
Funcionario *pegaFuncionarioPorID(ListaEncadeada *lista); //retorna um funcionario de acordo com o ID
void incluiNovoProjeto(Funcionario *funcionario); //inclui ao funcionario o projeto
void criaProjeto(ListaSequencial *lista, Projeto *projeto); //adiciona projetos na lista sequencial
void excluiProjetos(ListaEncadeada *lista); //exclui projetos de um funcionario
void excluiFuncionariosSemProjetos(ListaEncadeada *lista); //exclui funcionarios sem projetos
void consultaFuncionario(ListaEncadeada *lista); //procura funcionario na lista
void imprimeContraCheque(ListaEncadeada *lista); //imprime o contracheque com os os descontos já realizados
int totalHorasSemanais(ListaSequencial lista); //retorna as horas semanais
double calculaSalarioBruto(Funcionario *funcionario); //retorna o salário bruto sem os descontos
bool salvaArquivo(ListaEncadeada *lista); //salva o arquivo ao fim das operações
*/

#endif