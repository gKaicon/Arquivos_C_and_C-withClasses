#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <windows.h>
#include <time.h>
#include "FilaPrioridadeDinamica.cpp"

using namespace std;

#define OPCAO_SAIDA 6

typedef struct Hospital
{
    Medico medicos[5];
    vector<Atendimento> atendimentos_em_execucao;
    FilaPrioridadeDinamica fila_de_espera;
    unsigned int medicos_registrados = 0;
    unsigned int medicos_disponiveis = 0;
    unsigned int pacientes_tratados = 0;
};

void cadastraMedicos(Hospital *hospital);

void menu();

Paciente cadastro_Paciente();
void novoAtendimento(Hospital *hospital);

void realizarTriagem(Paciente *paciente);
void mostraUrgencia(Paciente paciente);
void mostraPrevisaoAtendimento(Paciente paciente);

void atualizaMedicoPaciente(Hospital *hospital);

void exibeAtendimentos(Hospital hospital);

void exibeRelatorio(Hospital hospital);
#endif