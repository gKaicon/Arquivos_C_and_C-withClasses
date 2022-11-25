#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include "FilaPrioridade.cpp"
#define OPCAO_SAIDA 5

using namespace std;

typedef struct Hospital{
    Medico medicos[5];
    vector <Atendimento> atendimentos_em_execucao;
    FilaPrioridadeDinamica fila_de_espera;
    unsigned int medicos_registrados = 0;
    unsigned int medicos_disponiveis = 0;
    unsigned int pacientes_tratados = 0;
};

void iniciaMedicos(Hospital *hospital);
void menu();
Paciente cadastro_Paciente();
void realizarTriagem(Paciente *paciente);
void atualizaMedicoPaciente(Hospital *hospital);
void novoAtendimento(Hospital *hospital);
void exibeAtendimentos(Hospital hospital);
void exibeFilaEspera(Hospital hospital);
void exibeRelatorio(Hospital hospital);

#endif
