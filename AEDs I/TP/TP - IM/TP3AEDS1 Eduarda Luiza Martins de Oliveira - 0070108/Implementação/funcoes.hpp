#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>
#include <windows.h>
#include <time.h>

#define OPCAO_SAIDA 6

using namespace std;

typedef struct
{
    char respostas[18];
} TTriagem;

typedef struct
{
    string nome;
    string endereco;
    unsigned int idade;
    unsigned int sexo;
    TTriagem triagem;
    unsigned int prioridade;
    bool atendido;
} TPaciente;

typedef struct
{
    string nome;
    string especialidade;
    string crm;
    bool disponivel = false;
} TMedico;

typedef struct TAtendimento
{
    TMedico *medico;
    TPaciente paciente;
    tm data_inicio;
    tm data_termino;
} TAtendimento;

typedef struct TCelula_str *TApontador;

typedef struct TCelula_str
{
    TAtendimento item;
    TApontador prox;
} TCelula;

typedef struct TFila
{
    TApontador inicio;
    int tamanho;
} TFila;

typedef struct Hospital
{
    TMedico medicos[5];
    vector<TAtendimento> atendimentos_em_execucao;
    TFila fila_de_espera;
    unsigned int medicos_registrados = 0;
    unsigned int medicos_disponiveis = 0;
    unsigned int pacientes_tratados = 0;
};

void menu();
// Funções TAD
void inicializaFila(TFila *fila);
bool verificaFilaVazia(TFila *fila);
void enfileira(TFila *fila, TAtendimento item);
void desenfileira(TFila *fila, TAtendimento *item);
void esvaziaFila(TFila *fila);
void imprimeFila(TFila *fila);
// Funções Específicas
void mostraUrgencia(TPaciente paciente);
void cadastraMedicos(Hospital *hospital);
void cadastraMedico(Hospital *hospital, string nome, string especialidade, string crm);
void novoAtendimento(Hospital *hospital);
TPaciente cadastraPaciente();
void realizaTriagem(TPaciente *paciente);
void mostraUrgencia(TPaciente paciente);
void mostraPrevisaoAtendimento(TPaciente paciente);
void atualiza(Hospital *hospital);
bool finalizaAtendimentos(Hospital *hospital, chrono::system_clock::time_point data_atual);
bool iniciaAtendimentos(Hospital *hospital);
void exibeAtendimentos(Hospital hospital);
void exibeRelatorio(Hospital hospital);
#endif