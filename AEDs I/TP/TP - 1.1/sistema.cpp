#include "sistema.hpp"

bool carregaArquivo(ListaEncadeada *lista)
{
    ifstream arquivo;
    arquivo.open(NOME_ARQUIVO, fstream::binary); // Abre o arquivo em modo binario, ou cria se não existir

    if (arquivo.fail()) // Se falhar
    {
        arquivo.clear(); // Fecha o arquivo
        return false;
    }
    while (arquivo.peek() != ifstream::traits_type::eof()) // Enquanto o arquivo nao for vazio
    {
        Funcionario *funcionario = new Funcionario;
        arquivo.read((char *)funcionario, sizeof(Funcionario)); // Le a Struct dos funcionarios completos

        InsereListaEncadeadaUltimo(lista, funcionario); // Insere o projeto que pegou do arquivo na lista encadeada
    }
    arquivo.clear();
    return true;
}

void menu()
{
    system("cls");
    cout << "################################################" << endl;
    cout << "#                                              #" << endl;
    cout << "#             Departamento Pessoal             #" << endl;
    cout << "#                                              #" << endl;
    cout << "################################################" << endl;
    cout << "#                                              #" << endl;
    cout << "# 1 - INCLUIR NOVO FUNCIONÁRIO                 #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 2 - INCLUIR NOVOS PROJETOS                   #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 3 - EXCLUIR PROJETOS                         #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 4 - EXCLUIR FUNCIONÁRIOS SEM PROJETOS        #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 5 - CONSULTAR FUNCIONÁRIO                    #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 6 - IMPRIMIR CONTRA-CHEQUE                   #" << endl;
    cout << "#                                              #" << endl;
    cout << "# 7 - SAIR                                     #" << endl;
    cout << "#                                              #" << endl;
    cout << "################################################" << endl;
}

void incluiNovoFuncionario(ListaEncadeada *lista)
{
    Funcionario *funcionario = criaFuncionario();

    if (PesquisaFuncionario(lista, funcionario->id) == NULL) //TRUE se o funcionário não está na lista, FALSE do contrário
    {
        InsereListaEncadeadaUltimo(lista, funcionario); //insere no fim da lista, isso vem lá da listaEncadeada.cpp
        cout << "\nFuncionário incluído com Sucesso!\n" << endl;
        int opcao;
        do
        {
            cout << "Deseja adicionar projetos ao funcionário?" << endl;
            cout << "1 - Sim" << endl;
            cout << "2 - Não" << endl;
            cin >> opcao;
            if (opcao == 1)
            {
                system("cls");
                int quantidade;
                cout << "Quantidade de projetos que deseja adicionar: ";
                cin >> quantidade;
                cin.ignore();
                for (int i = 0; i < quantidade; i++)
                {
                    incluiNovoProjeto(funcionario); //incluir projeto ao funcionario em qualquer situação
                }
            }
            system("cls");
        } while (opcao != 1 && opcao != 2);
    }
    else //caso exista um funcionario com o mesmo ID, que quero inserir
    {
        cout << "\nJá existe funcionário com ID: " << funcionario->id << endl;
        cout << "Adicione novamente com outro ID" << endl;
        delete funcionario; // Apaga o funcionario, visto que não será usado pelo fato de não aceitar o Id passado
        Sleep(1000);
    }
}

Funcionario *criaFuncionario() //função que retorna um funcionario, para que ele possa ser incluido na lista
{
    Funcionario *funcionario = new Funcionario;
    cout << "Cadastro de Novo Funcionário" << endl;
    cout << "ID: ";
    cin >> funcionario->id;
    cin.ignore();
    cout << "Nome: ";
    cin.getline(funcionario->nome, 100);
    cout << "Endereco: ";
    cin.getline(funcionario->endereco, 40);
    cout << "Número de Dependentes: ";
    cin >> funcionario->dependentes;
    cin.ignore();
    CriaListaSequencialVazia(&funcionario->projetos);//cria uma lista só para ele para inserir projetos

    return funcionario;
}

void incluiNovosProjetos(ListaEncadeada *lista)
{
    if (!ListaEncadeadaEstaVazia(lista))
    {
        Funcionario *funcionario = pegaFuncionarioPorID(lista); // Retorna ou o funcionário ou NULL

        if (funcionario != NULL) // Só adiciona se o funcionario existir
        {
            int opcao = 1;
            do
            {
                if (opcao == 1)
                {
                    incluiNovoProjeto(funcionario);
                }
                system("cls");
                cout << "Deseja adicionar outro projeto à esse funcionário?" << endl;
                cout << "1 - Sim" << endl;
                cout << "2 - Não" << endl;
                cin >> opcao;
                system("cls");
            } while (opcao != 2);
        }
        else
        {
            cout << "\nNão existe funcionário com esse Id" << endl;
            Sleep(1000);
        }
    }
    else
    {
        cout << "Erro: Nenhum Funcionário cadastrado" << endl;
        Sleep(1000);
    }
}

Funcionario *pegaFuncionarioPorID(ListaEncadeada *lista)
{
    int idFuncionario;
    cout << "ID do Funcionário: ";
    cin >> idFuncionario;
    cin.ignore();

    Funcionario *funcionario = PesquisaFuncionario(lista, idFuncionario);
    return funcionario;
}

void incluiNovoProjeto(Funcionario *funcionario)
{
    Projeto projeto;
    criaProjeto(&funcionario->projetos, &projeto);
    if (PesquisaProjetoPorID(&funcionario->projetos, projeto.id) == NULL) // TRUE se o projeto não está na lista, FALSE do contrário
    {
        bool inseridoComSucesso = InsereProjeto(&funcionario->projetos, projeto);
        if (inseridoComSucesso)
        {
            cout << "\nProjeto inserido com sucesso" << endl;
        }
        else
        {
            cout << "\nEsse funcionário atingiu o máximo de projetos possíveis (" << MAX_TAM << ")" << endl;
        }
    }
    else
    {
        cout << "\nJá existe Projeto com ID: " << projeto.id << " nesse funcionário." << endl;
        cout << "Adicione novamente com outro ID" << endl;
    }
    Sleep(1000);
}

void criaProjeto(ListaSequencial *lista, Projeto *projeto)
{
    cout << "Cadastro de Novo Projeto" << endl;
    cout << "ID: ";
    cin >> projeto->id;
    cin.ignore();
    cout << "Nome: ";
    cin.getline(projeto->nome, 30);
    cout << "Horas Trabalhadas: ";
    cin >> projeto->horas;
    cin.ignore();
}

void excluiProjetos(ListaEncadeada *lista)
{
    if (!ListaEncadeadaEstaVazia(lista))
    {
        Funcionario *funcionario = pegaFuncionarioPorID(lista); // Retorna ou o funcionário ou NULL

        if (funcionario != NULL) // Só entra se o funcionário existir
        {
            int idProjeto;
            cout << "ID do Projeto: ";
            cin >> idProjeto;
            cin.ignore();

            Projeto *projeto = PesquisaProjetoPorID(&funcionario->projetos, idProjeto);
            if (projeto == NULL)
            {
                cout << "\nProjeto com id igual à " << idProjeto << " não encontrado" << endl;
            }
            else
            {
                bool removeuComSucesso = RemoveProjeto(&funcionario->projetos, *projeto);
                if (removeuComSucesso)
                {
                    cout << "\nProjeto com id: " << idProjeto << " foi removido com sucesso" << endl;
                }
                else
                {
                    cout << "\nErro: Não foi possível excluir projeto com id: " << idProjeto << endl;
                }
            }
        }
        else
        {
            cout << "\nNão existe funcionário com esse Id" << endl;
        }
    }
    else
    {
        cout << "Erro: Nenhum Funcionário cadastrado" << endl;
    }
    Sleep(2000);
}

void excluiFuncionariosSemProjetos(ListaEncadeada *lista)
{
    if (!ListaEncadeadaEstaVazia(lista))
    {
        int opcao;
        do
        {
            system("cls");
            cout << "Deseja excluir apenas UM ou TODOS os funcionários sem projetos?" << endl;
            cout << "1 - Apagar apenas um" << endl;
            cout << "2 - Apagar todos" << endl;
            cout << "3 - Cancelar" << endl;
            cin >> opcao;
        } while (opcao < 1 || opcao > 3);

        switch (opcao)
        {
        case 1:
        {
            Funcionario *funcionario = pegaFuncionarioPorID(lista);
            if (funcionario != NULL)
            {
                if (TamanhoListaSequencial(&funcionario->projetos) == 0)
                {
                    RemoveFuncionario(lista, *funcionario);
                    cout << "\nFuncionário removido com sucesso" << endl;
                }
                else
                {
                    cout << "\nNão foi possível remover esse funcionário, o mesmo possui projetos ativos" << endl;
                }
            }
            else
            {
                cout << "\nNão existe funcionário com esse Id" << endl;
            }
            Sleep(2000);
            break;
        }
        case 2:
        {
            Apontador aux = lista->primeiro->prox;
            Apontador anterior = aux;
            while (aux != NULL && PesquisaFuncionario(lista, aux->item->id) != NULL)
            {
                if (TamanhoListaSequencial(&aux->item->projetos) == 0)
                {
                    RemoveFuncionario(lista, *aux->item);
                    aux = anterior;
                }
                anterior = aux;
                aux = anterior->prox;
            }
            cout << "Todos os funcionário sem projetos foram apagados." << endl;
            Sleep(2000);
            break;
        }
        }
    }
    else
    {
        cout << "Erro: Nenhum Funcionário cadastrado" << endl;
        Sleep(2000);
    }
}

void consultaFuncionario(ListaEncadeada *lista)
{
    if (!ListaEncadeadaEstaVazia(lista))
    {
        Funcionario *funcionario = pegaFuncionarioPorID(lista);

        if (funcionario != NULL) // Só adiciona se o funcionario existir
        {
            ImprimeFuncionario(funcionario);
        }
        else
        {
            cout << "\nNão existe funcionário com esse Id" << endl;
        }
    }
    else
    {
        cout << "Erro: Nenhum Funcionário cadastrado" << endl;
    }
    Sleep(2000);
}

void imprimeContraCheque(ListaEncadeada *lista)
{
    if (!ListaEncadeadaEstaVazia(lista))
    {
        Apontador aux;
        aux = lista->primeiro->prox;

        while (aux != NULL)
        {
            Funcionario *funcionario = aux->item;
            cout << "ID: " << funcionario->id << endl;
            cout << "Nome: " << funcionario->nome << endl;
            int totalHoras = totalHorasSemanais(funcionario->projetos);
            cout << "Total de Horas Semanais: " << totalHoras << endl;

            double salarioBruto = calculaSalarioBruto(funcionario);
            cout << "Salário Bruto: " << salarioBruto << endl;

            double descontoINSS = (8.5 / 100.0) * salarioBruto; // O desconto do INSS é 8.5% do salário bruto
            cout << "Desconto do INSS: " << descontoINSS << endl;

            double descontoIR = (15.0 / 100.0) * salarioBruto; // O desconto do IR é 15% do salário bruto
            cout << "Desconto de Imposto de renda: " << descontoIR << endl;

            double salarioLiquido = salarioBruto - descontoINSS - descontoIR; // Salário líquido é o salário bruto menos os descontos
            cout << "Salário líquido: " << salarioLiquido << endl;
            cout << "\n";

            aux = aux->prox;
        }
    }
    else
    {
        cout << "Erro: Nenhum Funcionário cadastrado" << endl;
    }
    Sleep(2000);
}

int totalHorasSemanais(ListaSequencial lista) // Retorna a soma do número de horas dos projetos
{
    int totalHoras = 0;
    for (int i = 0; i < lista.tamanho; i++)
    {
        Projeto projeto = lista.item[i];
        totalHoras += projeto.horas;
    }
    return totalHoras;
}

double calculaSalarioBruto(Funcionario *funcionario)
{
    double salarioBruto = 0;

    int totalHoras = totalHorasSemanais(funcionario->projetos);
    salarioBruto = (totalHoras * 45) + (35 * funcionario->dependentes);
    return salarioBruto;
}

bool salvaArquivo(ListaEncadeada *lista)
{
    ofstream arquivo;
    arquivo.open(NOME_ARQUIVO, ofstream::trunc | fstream::binary); // Abre arquivo em modo trunc pra deixa-lo vazio e em modo binario

    if (arquivo.fail())
    {
        arquivo.clear();
        return false;
    }

    Apontador aux = lista->primeiro->prox;
    while (aux != NULL)
    {
        Funcionario *funcionario = aux->item;
        arquivo.write((char *)funcionario, sizeof(Funcionario)); // Escreve no arquivo a Struct do funcionario completa
        delete funcionario;
        aux = aux->prox;
    }
    return true;
}