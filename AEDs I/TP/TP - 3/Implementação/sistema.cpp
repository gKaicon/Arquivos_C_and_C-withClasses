#include "sistema.hpp"

void iniciaMedicos(Hospital *hospital){
    Medico medico;
    hospital->medicos_registrados = 5;
    hospital->medicos_disponiveis = 5;
    medico.disponivel = true;

    medico.nome = "Paulo Muzy";
    medico.especialidade = "Cardiologia";
    medico.crm = "783856242-42";
    hospital->medicos[0] = medico;

    medico.nome = "Renato Cariani";
    medico.especialidade = "Nutrição";
    medico.crm = "156717331-94";
    hospital->medicos[1] = medico;

    medico.nome = "Marco Antônio";
    medico.especialidade = "Clinico Geral";
    medico.crm = "853217418-33";
    hospital->medicos[2] = medico;

    medico.nome = "Pedro Braga";
    medico.especialidade = "Infectologia";
    medico.crm = "145723701-14";
    hospital->medicos[3] = medico;

    medico.nome = "Antônio Augusto";
    medico.especialidade = "Neurologia";
    medico.crm = "856234505-51";
    hospital->medicos[4] = medico;  
}

void menu(){
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**              UNIDADE DE PRONTO ATENDIMENTO         **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**               1 - Novo Atendimento                 **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**               2 - Exibir Atendimentos              **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**               3 - Exibir Fila de Espera            **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**               4 - Exibir Relatório                 **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**               5 - Sair                             **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Opção: ";
}

Paciente cadastro_Paciente(){ // perguntas para criação um novo paciente
    Paciente paciente;
    cout << "Nome do Paciente: ";
    getline(cin, paciente.nome);
    cout << "Endereço: ";
    getline(cin, paciente.endereco);
    cout << "Idade: ";
    cin >> paciente.idade;
    cin.ignore();
    do{
        cout << "Opções: \n1 - Masculino\n2 - Feminino\nSexo: ";
        cin >> paciente.sexo;
        cin.ignore();
    }while (paciente.sexo != 1 && paciente.sexo != 2);
    system("cls");
    return paciente; //retorna o "objeto" paciente
}

void realizarTriagem(Paciente *paciente){
    Triagem triagem;
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl;
    cout << "**                                                     **" << endl;
    cout << "**                      TRIAGEM                        **" << endl;
    cout << "**                                                     **" << endl;
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl;
    cout << "**                                                     **" << endl;
    cout << "**   01 - Comprometimento das vias aérias?             **" << endl;
    cout << "**   02 - Respiração ineficaz?                         **" << endl;
    cout << "**   03 - Choque?                                      **" << endl;
    cout << "**   04 - Não responde a estímulos?                    **" << endl;
    cout << "**   05 - Em convulção?                                **" << endl;
    cout << "**   06 - Dor severa?                                  **" << endl;
    cout << "**   07 - Grande hemorragia incontrolável?             **" << endl;
    cout << "**   08 - Alteração do estado de consciência?          **" << endl;
    cout << "**   09 - Temperatura maior ou igual a 39°C?           **" << endl;
    cout << "**   10 - Trauma craniano severo?                      **" << endl;
    cout << "**   11 - Dor moderada?                                **" << endl;
    cout << "**   12 - Pequena hemorragia incontrolável?            **" << endl;
    cout << "**   13 - Vômito percistente?                          **" << endl;
    cout << "**   14 - Temperatura entre 38°C  e 39°C?              **" << endl;
    cout << "**   15 - É idoso ou grávida?                          **" << endl;
    cout << "**   16 - Dor leve?                                    **" << endl;
    cout << "**   17 - Náusea?                                      **" << endl;
    cout << "**   18 - Temperatura entre 37°C e 38°C?               **" << endl;
    cout << "**                                                     **" << endl;
    cout << "*********************************************************" << endl;
    cout << "*********************************************************" << endl;
    cout << "Dado o menu acima responda as perguntas apenas com S(sim) e N(não) de acordo com o número da pergunta.\n\n";

    bool urgencia_encontrada = false;

    for (int i = 1; i <= 18; i++){
        cout << "Pergunta " << i << ": ";
        cin >> triagem.respostas[i - 1];
        if (triagem.respostas[i - 1] == 'S' || triagem.respostas[i - 1] == 's'){ //se alguma das perguntas for sim, a urgencia é encontrada
            urgencia_encontrada = true;
        }
        if (urgencia_encontrada && (i % 5 == 0 || i == 18)){ //if que vai definir o nível da urgência
            paciente->prioridade = (i == 18 ? i / 5 : (i / 5) - 1); // Operador ternário para fazer o calculo correto pra cada situação
            break;
        }
    }
    if (!urgencia_encontrada){
        paciente->prioridade = 4; //ser não foi encontrada nenhuma urgencia, ele espera mais tempo
    }
    paciente->triagem = triagem; //respostas inseridas nos dados do usuario
}

void atualizaMedicoPaciente(Hospital *hospital){

    // parte em que são encerrados os atendimentos
    chrono::system_clock::time_point data_atual;
    data_atual = chrono::system_clock::now(); // Pega a data atual do sistema

    for (int i = 0; i < hospital->atendimentos_em_execucao.size(); i++){ // For para finalizar os Atendimentos
        Atendimento atendimento = hospital->atendimentos_em_execucao.at(i); 
        chrono::system_clock::time_point data_termino_atendimento;
        data_termino_atendimento = chrono::system_clock::from_time_t(mktime(&atendimento.data_termino)); // Converte a data_termino para time_point para comparar

        if (data_atual >= data_termino_atendimento){ //se já passou da hora de acabar, significa que acabou
            atendimento.paciente.atendido = true;
            atendimento.medico->disponivel = true;
            hospital->medicos_disponiveis++; //número de médicos disponíveis sobe
            hospital->pacientes_tratados++; //número de pacientes atendidos sobe
            hospital->atendimentos_em_execucao.erase(hospital->atendimentos_em_execucao.begin() + i);//remove o atendimento que já foi realizado
            cout << "Atendimento do paciente " << atendimento.paciente.nome << " foi finalizado.\n";
            cout << "Médico " << atendimento.medico->nome << " está disponível para atendimento.\n";
            system("pause");
        }
    }
    // parte em que são iniciados os atendimentos da fila de espera
    while (hospital->medicos_disponiveis > 0 && !verificaFilaVazia(&hospital->fila_de_espera)){ // inicia os atendimentos, se houver médicos disponíveis
        for (Medico &medico : hospital->medicos){ //percorre os médicos do hospital pelo Forrange
            if (medico.disponivel){
                Atendimento atendimento;
                desenfileira(&hospital->fila_de_espera, &atendimento); //tira da fila de espera
                medico.disponivel = false;
                atendimento.medico = &medico;
                hospital->medicos_disponiveis--;

                time_t data_atual = chrono::system_clock::to_time_t(chrono::system_clock::now());
                atendimento.data_inicio = *localtime(&data_atual); // Data de início recebe a data atual na forma da struct tm
                unsigned int tempo_atendimento;
                // Cálculo do tempo de atendimento com a variação, com base na urgência
                if(atendimento.paciente.prioridade == 0) tempo_atendimento = 50 + (rand() % 21) - 10;
                if(atendimento.paciente.prioridade == 1) tempo_atendimento = 20 + (rand() % 11) - 5;
                if(atendimento.paciente.prioridade == 2) tempo_atendimento = 15 + (rand() % 11) - 5;
                if(atendimento.paciente.prioridade == 3) tempo_atendimento = 10 + (rand() % 5) - 2;
                if(atendimento.paciente.prioridade == 4) tempo_atendimento = 5 + (rand() % 7) - 3;
                time_t data_termino = data_atual + (60 * tempo_atendimento); //prevendo a data de término
                atendimento.data_termino = *localtime(&data_termino); //Data de término recebe a data termino na forma da struct tm
                hospital->atendimentos_em_execucao.push_back(atendimento); // Adiciona o atendimento na lista de atendimentos em execução
                system("cls");
                cout << "Paciente: " << atendimento.paciente.nome << endl;
                cout << "Comparecer ao consultório do Médico: " << medico.nome << endl << endl;
                Sleep(2900);
                break;
            }
        }
    }
}

void novoAtendimento(Hospital *hospital){
    vector<Paciente> lista_pacientes; // Lista de pacientes utlizada dentro do laço para realizar atendimento, caso seja feito mais de 1
    int opcao;
    do{
        system("cls");
        cout << "*******************************************************" << endl;
        cout << "*******************************************************" << endl;
        cout << "**                                                   **" << endl;
        cout << "**                   Novo Atendimento                **" << endl;
        cout << "**                                                   **" << endl;
        cout << "*******************************************************" << endl;
        cout << "*******************************************************" << endl;

        Paciente paciente = cadastro_Paciente();
        realizarTriagem(&paciente);
        lista_pacientes.push_back(paciente); // Adiciona o novo paciente na lista
        system("cls");
        if(paciente.prioridade == 0) cout << "Urgência: Vermelho \tPrevisão de Atendimento Imediato\n";
        if(paciente.prioridade == 1) cout << "Urgência: Laranja \tPrevisão de Atendimento em até 10 minutos\n";
        if(paciente.prioridade == 2) cout << "Urgência: Amarelo \tPrevisão de Atendimento em até 60 minutos\n";
        if(paciente.prioridade == 3) cout << "Urgência: Verde \tPrevisão de Atendimento em até 120 minutos\n";
        if(paciente.prioridade == 4) cout << "Urgência: Azul \tPrevisão de Atendimento em até 240 minutos\n";
        system("pause");
        system("cls");
        do{
            system("cls");
            cout << "\nDeseja realizar um novo atendimento?\n1 - Sim\n2 - Não\nOpção: ";
            cin >> opcao;
            cin.ignore();
        }while(opcao != 1 && opcao != 2);
    }while (opcao == 1);
 
    for (Paciente p : lista_pacientes){ // Percorre a lista de pacientes, pelo conteúdo existente
        Atendimento novoAte; //cria um novo atendimento
        novoAte.paciente = p; //coloca o paciente no atendimento
        enfileira(&hospital->fila_de_espera, novoAte);//enfileira esse paciente cadastrado lá na fila de espera
    }
    atualizaMedicoPaciente(hospital); //insere os pacientes que estão na fila de espera, e atualiza os atendimentos
}

void exibeAtendimentos(Hospital hospital){
    if (hospital.atendimentos_em_execucao.size() > 0){
        for (Atendimento atendimento : hospital.atendimentos_em_execucao){
            cout << "\nMédico: " << atendimento.medico->nome;
            cout << "\nPaciente: " << atendimento.paciente.nome << endl;
            if(atendimento.paciente.prioridade == 0) cout << "Urgência: Vermelho\n";
            if(atendimento.paciente.prioridade == 1) cout << "Urgência: Laranja\n";
            if(atendimento.paciente.prioridade == 2) cout << "Urgência: Amarelo\n";
            if(atendimento.paciente.prioridade == 3) cout << "Urgência: Verde\n";
            if(atendimento.paciente.prioridade == 4) cout << "Urgência: Azul\n"; 
            cout << "\nInício: " << put_time(&atendimento.data_inicio, "%d/%m/%Y %H:%M:%S");               // converte a struct tm em string
            cout << "\nPrevisão de Término: " << put_time(&atendimento.data_termino, "%d/%m/%Y %H:%M:%S") << endl << endl; // converte a struct tm em string
        }
        system("pause");
    }
    else cout << "Nenhum atendimento em execução." << endl;
    Sleep(1500);
}

void exibeFilaEspera(Hospital hospital){
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                     Fila de Espera                 **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    imprimeFila(&hospital.fila_de_espera);
    system("pause");
}

void exibeRelatorio(Hospital hospital){
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                      Relatório                     **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "\nQuantidade de atendimentos em andamento: " << hospital.atendimentos_em_execucao.size();
    cout << "\nQuantidade de médicos registrados: " << hospital.medicos_registrados;
    cout << "\nQuantidade de médicos disponíveis: " << hospital.medicos_disponiveis;
    cout << "\nQuantidade de pacientes atendidos e tratados: " << hospital.pacientes_tratados;
    cout << "\nQuantidade de pacientes em espera: " << hospital.fila_de_espera.tamanho;
    system("pause");
}