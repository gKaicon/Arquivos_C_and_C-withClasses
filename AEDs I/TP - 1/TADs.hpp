#ifndef LISTA_H
#define LISTA_H

#define MAXTAM 5

typedef int Chave_Project;
typedef int ApontadorLE;

typedef struct CelulaApontadorLD *Apontador;

//Projeto
typedef struct Projeto{
    Chave_Project codigo; // codigo do projeto
    char nome[30];        // nome do projeto
    int horas;            // numero de horas trabalhas no projeto
};
typedef struct ListaSequencialProjeto{
    Projeto itemProjeto[MAXTAM];
    ApontadorLE primeiro, ultimo;
    int tamanho;
};

//funcionario
typedef struct Funcionario{
    int numero;             // codigo do funcionario
    char endereco[40];      // endereco do funcionario
    int dependentes;        // numero de dependentes do funcionario
    ListaSequencialProjeto projeto[5]; // Lista Sequencial que guarda os projetos nos quais o funcionario trabalha
} Funcionario;

typedef struct Celula{
    Funcionario item;
    Apontador prox;
};

typedef struct ListaEncadeadaFuncionario{
    Apontador primeiro;
    Apontador ultimo;
};

bool listaProjectCriada = false;
bool listaFuncionarioCriada = false;

/* Funções 
1. menuProjeto
2. menufuncionario

1.1 criaListaProj
1.2 verificalistaVaziaProj
1.3 verificaListaCheiaProj
1.4 incluirNaListaProjeto
1.5 listaDeProjetos
1.6 pesquisaProjeto
1.7 retiraProjeto

2.1 crialistaFunc
2.2 verificaListaVazia
2.3 incluirFunc
    2.3.1 incluirProjetoFunc
    2.3.2 verificaFuncProjeto
    2.3.3 excluirFuncSemProjeto
    2.3.4 excluirProjetoDoFunc
2.4 pesquisaCodIgual
2.5 listaFuncionario
2.6 qtdFunc
2.7 imprimirContraCheque


*/
#endif