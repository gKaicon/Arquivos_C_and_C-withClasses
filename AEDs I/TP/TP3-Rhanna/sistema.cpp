#include "sistema.hpp"

void cadastraMedicos(Hospital *hospital)
{
    Medico medico;
    medico.disponivel = true;

    medico.nome = "Paulo Muzy";
    medico.especialidade = "Cardiologia";
    medico.crm = "623146242-42";
    hospital->medicos[0] = medico;

    medico.nome = "Lucca Godinho";
    medico.especialidade = "Dermatologia";
    medico.crm = "823517331-94";
    hospital->medicos[1] = medico;

    medico.nome = "Mauro Silva";
    medico.especialidade = "Cardiologia";
    medico.crm = "742417418-33";
    hospital->medicos[2] = medico;

    medico.nome = "Humberto Gonçalvez";
    medico.especialidade = "Infectologia";
    medico.crm = "423123701-14";
    hospital->medicos[3] = medico;

    medico.nome = "Leandro Pena";
    medico.especialidade = "Geriatria";
    medico.crm = "140134505-51";
    hospital->medicos[4] = medico;

    hospital->medicos_registrados = 5;
    hospital->medicos_disponiveis = 5;
}

void menu()
{
    system("cls");
    cout << "########################################" << endl;
    cout << "#                                      #" << endl;
    cout << "#         Registro de Hospital         #" << endl;
    cout << "#                                      #" << endl;
    cout << "########################################" << endl;
    cout << "#                                      #" << endl;
    cout << "#         1 - Novo Atendimento         #" << endl;
    cout << "#                                      #" << endl;
    cout << "#         2 - Atualiza                 #" << endl;
    cout << "#                                      #" << endl;
    cout << "#         3 - Exibir Atendimentos      #" << endl;
    cout << "#                                      #" << endl;
    cout << "#         4 - Exibir Fila              #" << endl;
    cout << "#                                      #" << endl;
    cout << "#         5 - Exibir Relatório         #" << endl;
    cout << "#                                      #" << endl;
    cout << "#         6 - Sair                     #" << endl;
    cout << "#                                      #" << endl;
    cout << "########################################" << endl;
}

void novoAtendimento(Hospital *hospital)
{
    vector<Paciente> lista_pacientes; // Lista de pacientes para realizar atendimento
    int opcao;
    do
    {
        system("cls");
        cout << "########################################" << endl;
        cout << "#                                      #" << endl;
        cout << "#           Novo Atendimento           #" << endl;
        cout << "#                                      #" << endl;
        cout << "########################################" << endl;

        Paciente novo_paciente = cadastraPaciente();
        realizaTriagem(&novo_paciente);
        lista_pacientes.push_back(novo_paciente); // Adiciona o novo paciente na lista
        system("cls");
        mostraUrgencia(novo_paciente);
        mostraPrevisaoAtendimento(novo_paciente);
        cout << "\n";

        do
        {
            cout << "Deseja realizar um novo atendimento?" << endl;
            cout << "1-Sim" << endl;
            cout << "2-Não" << endl;
            cin >> opcao;
            cin.ignore();
        } while (opcao != 1 && opcao != 2);
    } while (opcao == 1);

    for (Paciente paciente : lista_pacientes) // Percorre a lista de pacientes
    {
        Atendimento novo_atendimento;
        novo_atendimento.paciente = paciente;
        enfileira(&hospital->fila_de_espera, novo_atendimento);
    }
    atualiza(hospital);
}

Paciente cadastraPaciente() // Cria um novo paciente
{
    Paciente paciente;
    cout << "Nome do Paciente: ";
    getline(cin, paciente.nome);
    cout << "Endereço: ";
    getline(cin, paciente.endereco);
    cout << "Idade: ";
    cin >> paciente.idade;
    cin.ignore();
    do
    {
        cout << "Sexo: " << endl;
        cout << "1-Masculino" << endl;
        cout << "2-Feminino" << endl;
        cin >> paciente.sexo;
    } while (paciente.sexo != 1 && paciente.sexo != 2);
    cin.ignore();
    system("cls");
    return paciente;
}

void realizaTriagem(Paciente *paciente)
{
    cout << "########################################" << endl;
    cout << "#                                      #" << endl;
    cout << "#               Triagem                #" << endl;
    cout << "#                                      #" << endl;
    cout << "########################################" << endl;

    Triagem triagem;

    cout << "1: Comprometimento das vias aérias?\n";
    cout << "2: Respiração Ineficaz?\n";
    cout << "3: Choque?\n";
    cout << "4: Não responde a estímulos?\n";
    cout << "5: Em convulção?\n";
    cout << "6: Dor severa?\n";
    cout << "7: Grande hemorragia incontrolavel?\n";
    cout << "8: Alteração do estado de consiencia?\n";
    cout << "9: Temperatura maior ou igual a 39°C?\n";
    cout << "10: Trauma craniano severo?\n";
    cout << "11: Dor moderada?\n";
    cout << "12: Pequena hemorragia incontrolável?\n";
    cout << "13: Vômito percistente?\n";
    cout << "14: Temperatura entre 38°C  e 39°C?\n";
    cout << "15: Idoso ou grávida?\n";
    cout << "16: Dor leve?\n";
    cout << "17: Náusea?\n";
    cout << "18: Temperatura entre 37°C e 38°C?\n";

    cout << "Dado o menu anterior responda as perguntas a seguir respondendo S para sim e N para não na ordem correta\n\n";

    bool urgencia_encontrada = false;
    for (int i = 1; i <= 18; i++)
    {
        cout << "Pergunta " << i << " ";
        cin >> triagem.respostas[i - 1];
        if (triagem.respostas[i - 1] == 'S' || triagem.respostas[i - 1] == 's')
        {
            urgencia_encontrada = true;
        }

        if (urgencia_encontrada && (i % 5 == 0 || i == 18))
        {
            paciente->prioridade = (i == 18 ? i / 5 : i / 5 - 1); // Operador ternário para fazer o calculo correto pra cada situação
            break;
        }
    }

    if (!urgencia_encontrada)
    {
        paciente->prioridade = 4;
    }

    paciente->triagem = triagem;
}

void mostraPrevisaoAtendimento(Paciente paciente)
{
    string previsao_de_atendimento;
    switch (paciente.prioridade)
    {
    case 0:
        previsao_de_atendimento = "Atendimento Imediato";
        break;

    case 1:
        previsao_de_atendimento = "Atendimento em até 10 minutos";
        break;

    case 2:
        previsao_de_atendimento = "Atendimento em até 60 minutos";
        break;

    case 3:
        previsao_de_atendimento = "Atendimento em até 120 minutos";
        break;

    case 4:
        previsao_de_atendimento = "Atendimento em até 240 minutos";
        break;
    }
    cout << "Previsão de Atendimento: " << previsao_de_atendimento << endl;
}

void atualiza(Hospital *hospital)
{
    chrono::system_clock::time_point data_atual = chrono::system_clock::now(); // Pega a data atual do sistema

    for (int i = 0; i < hospital->atendimentos_em_execucao.size(); i++) // Finaliza os Atendimentos
    {
        Atendimento atendimento = hospital->atendimentos_em_execucao.at(i);
        chrono::system_clock::time_point data_termino_atendimento = chrono::system_clock::from_time_t(mktime(&atendimento.data_termino)); // Transforma a data de termino para time_point para poder comparar as datas

        if (data_atual >= data_termino_atendimento)
        {
            atendimento.paciente.atendido = true;
            atendimento.medico->disponivel = true;
            hospital->medicos_disponiveis++;
            hospital->pacientes_tratados++;

            hospital->atendimentos_em_execucao.erase(hospital->atendimentos_em_execucao.begin() + i);
            cout << "Atendimento Do Paciente " << atendimento.paciente.nome << " foi finalizado." << endl;
            cout << "Médico " << atendimento.medico->nome << " está disponível para atendimento." << endl;
            system("pause");
        }
    }

    while (hospital->medicos_disponiveis > 0 && !verificaFilaVazia(&hospital->fila_de_espera)) // Inicia os Atendimentos
    {
        for (Medico &medico : hospital->medicos)
        {
            if (medico.disponivel)
            {
                Atendimento atendimento;
                desenfileira(&hospital->fila_de_espera, &atendimento);
                medico.disponivel = false;
                atendimento.medico = &medico;
                hospital->medicos_disponiveis--;

                time_t data_atual = chrono::system_clock::to_time_t(chrono::system_clock::now());
                atendimento.data_inicio = *localtime(&data_atual); // Data de inicio recebe a data atual na forma da struct tm
                unsigned int tempo_atendimento;

                switch (atendimento.paciente.prioridade) // Calcula o tempo de atendimento baseano na urgencia
                {
                case 0:
                    tempo_atendimento = 50 + (rand() % 21) - 10;
                    break;

                case 1:
                    tempo_atendimento = 20 + (rand() % 11) - 5;
                    break;

                case 2:
                    tempo_atendimento = 15 + (rand() % 11) - 5;
                    break;

                case 3:
                    tempo_atendimento = 10 + (rand() % 5) - 2;
                    break;

                case 4:
                    tempo_atendimento = 5 + (rand() % 7) - 3;
                    break;
                }

                time_t data_termino = data_atual + (60 * tempo_atendimento);
                atendimento.data_termino = *localtime(&data_termino);

                hospital->atendimentos_em_execucao.push_back(atendimento); // Adiciona o atendimento na lista de atendimentos em execução
                system("cls");
                cout << "Paciente: " << atendimento.paciente.nome << endl;
                cout << "Comparecer ao consultório do Médico: " << medico.nome << endl;
                system("pause");
                break;
            }
        }
    }
}

void exibeAtendimentos(Hospital hospital)
{
    if (hospital.atendimentos_em_execucao.size() > 0)
    {
        for (Atendimento atendimento : hospital.atendimentos_em_execucao)
        {
            cout << "Médico: " << atendimento.medico->nome << endl;
            cout << "Paciente: " << atendimento.paciente.nome << endl;
            mostraUrgencia(atendimento.paciente);
            cout << "Início: " << put_time(&atendimento.data_inicio, "%d/%m/%Y %H:%M:%S") << endl;               // Transforma a struct tm em string
            cout << "Previsão de Término: " << put_time(&atendimento.data_termino, "%d/%m/%Y %H:%M:%S") << endl; // Transforma a struct tm em string
            cout << "\n";
        }

        system("pause");
    }
    else
    {
        cout << "Nenhum atendimento em execução" << endl;
        Sleep(1000);
    }
}

void exibeFilaEspera(Hospital hospital)
{
    cout << "########################################" << endl;
    cout << "#                                      #" << endl;
    cout << "#            Fila de Espera            #" << endl;
    cout << "#                                      #" << endl;
    cout << "########################################" << endl;

    imprimeFila(&hospital.fila_de_espera);
    system("pause");
}

void exibeRelatorio(Hospital hospital)
{
    cout << "########################################" << endl;
    cout << "#                                      #" << endl;
    cout << "#              Relatório               #" << endl;
    cout << "#                                      #" << endl;
    cout << "########################################" << endl;

    cout << "Atendimentos em execução: " << hospital.atendimentos_em_execucao.size() << endl;
    cout << "Médicos Registrados: " << hospital.medicos_registrados << endl;
    cout << "Médicos Disponíveis: " << hospital.medicos_disponiveis << endl;
    cout << "Pacientes Tratados: " << hospital.pacientes_tratados << endl;
    cout << "Pacientes Em Espera: " << hospital.fila_de_espera.tamanho << endl;
    system("pause");
}
