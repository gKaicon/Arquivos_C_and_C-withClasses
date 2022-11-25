#include "funcoes.hpp"

using namespace std;

void menu()
{
    system("cls");
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#              Registro de Hospital              #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#              1 - Novo Atendimento              #" << endl;
    cout << "#                                                #" << endl;
    cout << "#              2 - Atualiza Atendimentos         #" << endl;
    cout << "#                                                #" << endl;
    cout << "#              3 - Exibir Atendimentos           #" << endl;
    cout << "#                                                #" << endl;
    cout << "#              4 - Exibir Fila de Espera         #" << endl;
    cout << "#                                                #" << endl;
    cout << "#              5 - Exibir Relatório              #" << endl;
    cout << "#                                                #" << endl;
    cout << "#              6 - Sair                          #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
}

void inicializaFila(TFila *fila)
{
    fila->inicio = NULL;
    fila->tamanho = 0;
}

bool verificaFilaVazia(TFila *fila)
{
    return (fila->inicio == NULL);
}

void enfileira(TFila *fila, TAtendimento item)
{
    TApontador novo = new TCelula;
    novo->item = item;
    novo->prox = NULL;

    TApontador anterior = fila->inicio;
    TApontador atual = fila->inicio;

    if (verificaFilaVazia(fila))
    {
        fila->inicio = novo;
    }
    else
    {
        while (atual != NULL && item.paciente.prioridade >= atual->item.paciente.prioridade)
        {
            anterior = atual;
            atual = atual->prox;
        }

        if (atual == fila->inicio)
        {
            fila->inicio = novo;
            novo->prox = atual;
        }
        else
        {
            anterior->prox = novo;
            novo->prox = atual;
        }
    }

    fila->tamanho++;
}

void desenfileira(TFila *fila, TAtendimento *item)
{
    if (verificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    TApontador aux = fila->inicio;
    *item = aux->item;
    fila->inicio = aux->prox;
    delete aux;
    fila->tamanho--;
}

void esvaziaFila(TFila *fila)
{
    TAtendimento item;
    while (!verificaFilaVazia(fila))
    {
        desenfileira(fila, &item);
    }
}

void imprimeFila(TFila *fila)
{
    if (verificaFilaVazia(fila))
    {
        cout << "Fila vazia!" << endl;
        return;
    }
    TApontador aux = fila->inicio;
    cout << "Pacientes:" << endl;
    while (aux != NULL)
    {
        cout << "\tNome: " << aux->item.paciente.nome << endl;
        cout << "\t";
        mostraUrgencia(aux->item.paciente);
        cout << "\tEndereço: " << aux->item.paciente.endereco << endl;
        cout << "\tIdade: " << aux->item.paciente.idade << endl;
        cout << "\tSexo: " << (aux->item.paciente.sexo == 1 ? "Masculino" : "Feminino") << endl;
        cout << "\n";
        aux = aux->prox;
    }
    cout << endl;
}

void cadastraMedicos(Hospital *hospital)
{
    cadastraMedico(hospital, "Deide Costa", "Geriatria", "885104256-12");
    cadastraMedico(hospital, "Miguel Lopes", "Infectologia", "952143102-87");
    cadastraMedico(hospital, "Maria Ferreira", "Oftalmologia", "184501041-27");
    cadastraMedico(hospital, "Gael Pereira", "Ortopedia", "570104492-76");
    cadastraMedico(hospital, "Helena Souza", "Cardiologia", "261053174-33");
}

void cadastraMedico(Hospital *hospital, string nome, string especialidade, string crm)
{
    if (hospital->medicos_registrados < 5)
    {
        hospital->medicos[hospital->medicos_registrados].nome = nome;
        hospital->medicos[hospital->medicos_registrados].especialidade = especialidade;
        hospital->medicos[hospital->medicos_registrados].crm = crm;
        hospital->medicos[hospital->medicos_registrados].disponivel = true;
        hospital->medicos_registrados++;
        hospital->medicos_disponiveis++;
    }
    else
    {
        cout << "Máximo de médicos registrados atingido" << endl;
        system("pause");
        system("cls");
    }
}

void mostraUrgencia(TPaciente paciente)
{
    string urgencia;
    switch (paciente.prioridade)
    {
    case 0:
        urgencia = "Vermelho";
        break;

    case 1:
        urgencia = "Laranja";
        break;

    case 2:
        urgencia = "Amarelo";
        break;

    case 3:
        urgencia = "Verde";
        break;

    case 4:
        urgencia = "Azul";
        break;
    }

    cout << "Urgência: " << urgencia << endl;
}

void novoAtendimento(Hospital *hospital)
{
    vector<TPaciente> lista_pacientes; // Lista de pacientes para realizar atendimento
    int opcao;
    do
    {
        system("cls");
        cout << "##################################################" << endl;
        cout << "#                                                #" << endl;
        cout << "#                Novo Atendimento                #" << endl;
        cout << "#                                                #" << endl;
        cout << "##################################################" << endl;

        TPaciente novo_paciente = cadastraPaciente();
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

    for (TPaciente paciente : lista_pacientes) // Percorre a lista de pacientes
    {
        TAtendimento novo_atendimento;
        novo_atendimento.paciente = paciente;
        enfileira(&hospital->fila_de_espera, novo_atendimento);
    }
    atualiza(hospital);
}

TPaciente cadastraPaciente()
{
    TPaciente paciente;
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

void realizaTriagem(TPaciente *paciente)
{
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                    Triagem                     #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;

    TTriagem triagem;

    cout << "1: Comprometimento das vias aérias?" << endl;
    cout << "2: Respiração Ineficaz?" << endl;
    cout << "3: Choque?" << endl;
    cout << "4: Não responde a estímulos?" << endl;
    cout << "5: Em convulção?" << endl;
    cout << "6: Dor severa?" << endl;
    cout << "7: Grande hemorragia incontrolavel?" << endl;
    cout << "8: Alteração do estado de consiencia?" << endl;
    cout << "9: Temperatura maior ou igual a 39°C?" << endl;
    cout << "10: Trauma craniano severo?" << endl;
    cout << "11: Dor moderada?" << endl;
    cout << "12: Pequena hemorragia incontrolável?" << endl;
    cout << "13: Vômito percistente?" << endl;
    cout << "14: Temperatura entre 38°C  e 39°C?" << endl;
    cout << "15: Idoso ou grávida?" << endl;
    cout << "16: Dor leve?" << endl;
    cout << "17: Náusea?" << endl;
    cout << "18: Temperatura entre 37°C e 38°C?" << endl;

    cout << "Dado o menu anterior responda as perguntas a seguir respondendo S para sim e N para não na ordem correta\n"
         << endl;

    unsigned int resposta = -1;
    for (int i = 1; i <= 18; i++)
    {
        cout << "Pergunta " << i << " ";
        cin >> triagem.respostas[i - 1];
        if (triagem.respostas[i - 1] == 'S' || triagem.respostas[i - 1] == 's')
        {
            resposta = i;
        }

        if (resposta != -1 && (i % 5 == 0 || i == 18)) // Verifica se a pessoa respondeu 'S' apenas no final de cada grupo de questões (5, 10, 15, 18)
        {
            int prioridade;
            if (i <= 5)
            {
                prioridade = 0;
            }
            else if (i <= 10)
            {
                prioridade = 1;
            }
            else if (i <= 15)
            {
                prioridade = 2;
            }
            else
            {
                prioridade = 3;
            }
            paciente->prioridade = prioridade;
            break;
        }
    }

    if (resposta == -1)
    {
        paciente->prioridade = 4;
    }

    paciente->triagem = triagem;
}

void mostraPrevisaoAtendimento(TPaciente paciente)
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
    chrono::system_clock::time_point data_atual = chrono::system_clock::now(); // Data atual do sistema

    bool finalizado = finalizaAtendimentos(hospital, data_atual);
    bool iniciado = iniciaAtendimentos(hospital);

    if (!finalizado && !iniciado)
    {
        cout << "Nenhuma informação nova." << endl;
        Sleep(1000);
    }
}

bool finalizaAtendimentos(Hospital *hospital, chrono::system_clock::time_point data_atual)
{
    bool atendimento_finalizado = false;
    for (int i = 0; i < hospital->atendimentos_em_execucao.size(); i++)
    {
        TAtendimento atendimento = hospital->atendimentos_em_execucao.at(i);
        chrono::system_clock::time_point data_termino_atendimento = chrono::system_clock::from_time_t(mktime(&atendimento.data_termino)); 
                                                                                                    // Transforma a data de termino em time_point

        if (data_atual >= data_termino_atendimento)
        {
            atendimento.paciente.atendido = true;
            atendimento.medico->disponivel = true;
            hospital->medicos_disponiveis++;
            hospital->pacientes_tratados++;

            hospital->atendimentos_em_execucao.erase(hospital->atendimentos_em_execucao.begin() + i); // Remove o atendimento da lista
            cout << "Atendimento Do Paciente " << atendimento.paciente.nome << " foi finalizado." << endl;
            cout << "Médico(a) " << atendimento.medico->nome << " está disponível para atendimento." << endl;
            atendimento_finalizado = false;
            system("pause");
        }
    }
    return atendimento_finalizado;
}

bool iniciaAtendimentos(Hospital *hospital)
{
    bool atendimento_iniciado = false;
    while (hospital->medicos_disponiveis > 0 && !verificaFilaVazia(&hospital->fila_de_espera))
    {
        for (TMedico &medico : hospital->medicos)
        {
            if (medico.disponivel)
            {
                TAtendimento atendimento;
                desenfileira(&hospital->fila_de_espera, &atendimento);
                medico.disponivel = false;
                atendimento.medico = &medico;
                hospital->medicos_disponiveis--;

                time_t data_atual = chrono::system_clock::to_time_t(chrono::system_clock::now());
                atendimento.data_inicio = *localtime(&data_atual); // Data de inicio recebe a data atual na forma da struct tm
                unsigned int tempo_atendimento;

                switch (atendimento.paciente.prioridade) // Calcula o tempo de atendimento com base na prioridade
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

                time_t data_termino = data_atual + (60 * tempo_atendimento); // Transformando o tempo de atendimento em minutos e adicionando à hora atual
                atendimento.data_termino = *localtime(&data_termino);

                hospital->atendimentos_em_execucao.push_back(atendimento); // Adiciona na lista de atendimentos em execução
                system("cls");
                cout << atendimento.paciente.nome << ", favor comparecer ao consultório do(a) médico(a) " << medico.nome << endl;
                atendimento_iniciado = true;
                system("pause");
                break;
            }
        }
    }
    return atendimento_iniciado;
}

void exibeAtendimentos(Hospital hospital)
{
    if (!hospital.atendimentos_em_execucao.empty())
    {
        for (TAtendimento atendimento : hospital.atendimentos_em_execucao)
        {
            cout << "Médico(a): " << atendimento.medico->nome << endl;
            cout << "Paciente: " << atendimento.paciente.nome << endl;
            mostraUrgencia(atendimento.paciente);
            cout << "Início: " << put_time(&atendimento.data_inicio, "%H:%M:%S") << endl;               // Transforma a struct tm em string
            cout << "Previsão de Término: " << put_time(&atendimento.data_termino, "%H:%M:%S") << endl; // Transforma a struct tm em string
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
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                 Fila de Espera                 #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;

    imprimeFila(&hospital.fila_de_espera);
    system("pause");
}

void exibeRelatorio(Hospital hospital)
{
    cout << "##################################################" << endl;
    cout << "#                                                #" << endl;
    cout << "#                   Relatório                    #" << endl;
    cout << "#                                                #" << endl;
    cout << "##################################################" << endl;
    cout << "\n";
    cout << "Atendimentos em execução: " << hospital.atendimentos_em_execucao.size() << endl;
    cout << "Médicos Registrados: " << hospital.medicos_registrados << endl;
    cout << "Médicos Disponíveis: " << hospital.medicos_disponiveis << endl;
    cout << "Pacientes Tratados: " << hospital.pacientes_tratados << endl;
    cout << "Pacientes Em Espera: " << hospital.fila_de_espera.tamanho << endl;
    system("pause");
}
