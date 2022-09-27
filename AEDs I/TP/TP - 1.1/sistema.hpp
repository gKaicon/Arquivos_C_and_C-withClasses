#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include "listaSequencial.cpp"
#include "listaEncadeada.cpp"

#define NOME_ARQUIVO "funcionarios.bin"
#define OPCAO_SAIDA 7

using namespace std;

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

#endif