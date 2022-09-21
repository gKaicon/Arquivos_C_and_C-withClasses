#include <iostream>
#include <windows.h>
#include <fstream>
#include "lista.hpp"

void menu()
{
    cout << "  \n        ****************************************************************";
    cout << "  \n        *                                                              *";
    cout << "  \n        *              DEPARTAMENTO PESSOAL - BIGDATA                  *";
    cout << "  \n        *                                                              *";
    cout << "  \n        ****************************************************************";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 1 - INCLUIR NOVO FUNCIONÁRIO                                 *";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 2 - INCLUIR NOVOS PROJETOS                                   *";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 3 - EXCLUIR PROJETOS                                         *";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 4 - EXCLUIR FUNCIONÁRIOS SEM PROJETO                         *";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 5 - CONSULTAR FUNCIONÁRIO                                    *";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 6 - IMPRIMIR CONTRA-CHEQUE                                   *";
    cout << "  \n        *                                                              *";
    cout << "  \n        * 7 - SAIR                                                     *";
    cout << "  \n        *                                                              *";
    cout << "  \n        ****************************************************************" << endl << endl;
}

void CriaListaVaziaEncadeada(TListaEncadeada *listaE)
{
    listaE->Primeiro = new TCelula;
    listaE->Ultimo = listaE->Primeiro;
    listaE->Primeiro->prox = NULL;
}

bool VerificaListaVaziaEncadeada(TListaEncadeada listaE)
{
    return (listaE.Primeiro == listaE.Ultimo);
}

void InserirEncadeada(TFuncionario fun, TListaEncadeada *listaE)
{
    listaE->Ultimo->prox = new TCelula;
    listaE->Ultimo = listaE->Ultimo->prox;
    listaE->Ultimo->item = fun;
    listaE->Ultimo->prox = NULL;
}

void CriaListaVaziaSequencial(TListaSequencial *listaS)
{
    listaS->primeiro = INICIO;
    listaS->ultimo = listaS->primeiro;
}

bool VerificaListaVaziaSequencial(TListaSequencial listaS)
{
    if (listaS.ultimo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void InsereSequencial(TProjeto proj, TListaSequencial *listaS)
{
    if (listaS->ultimo == MAXTAM)
    {
        cout << "Lista Cheia!" << endl;
      //  sleep(5);
    }
    else
    {
        listaS->item[listaS->ultimo] = proj;
        listaS->ultimo++;
    }
}

void CadastraFuncionario(TListaEncadeada *listaE) // Função para realizar o cadastro de funcionários
{
    TFuncionario fun;
    TApontador x = listaE->Primeiro;

    cout << "*******************************************" << endl;
    cout << "*    TELA DE  CADASTRO DE FUNCIONÁRIO     *" << endl;
    cout << "*******************************************" << endl;
    cout << "Informe um Código para o Funcionário: ";
    cin >> fun.numero;

    // Verificação se já existe funcionário com o mesmo código digitado
    while (x->prox != NULL)
    {
        if (x->prox->item.numero == fun.numero)
        {
            cout << "O Código já existe, favor digitar outro: ";
            cin >> fun.numero;
            x = listaE->Primeiro;
        }
        else
        {
            x = x->prox;
        }
    }
    cin.ignore();
    fflush(stdin);
    cout << "Digite o nome do funcionário: ";
    cin >> fun.nome; //mudei aqui
    cout << "Digite o endereço do funcionário: ";
    cin >> fun.endereco;//mudei aqui

    while ((cout << "Infome o número de dependentes: ") && !(cin >> fun.dependentes))
    {
        cout << "Você inseriu um valor não numérico." << endl;
        cin.clear();
        cin.ignore();
    }

    CriaListaVaziaSequencial(&fun.projetos);

    InserirEncadeada(fun, listaE);

    cout << endl << "Funcionário cadastrado com sucesso!" << endl << endl;
  //  sleep(5);
    system("cls");
}
void ConsultaFuncionario(TListaEncadeada *listaE)
{
    TChave cod;
    TApontador ptr;
    system("cls");
    int ret;

    cout << "*******************************************" << endl;
    cout << "*     TELA DE CONSULTA DE FUNCIONÁRIO     *" << endl;
    cout << "*******************************************" << endl << endl;
    cout << "Informe o código do funcionário: ";
    cin >> cod;
    system("cls");

    ret = PesquisaListaEncadeada(cod, *listaE, &ptr);

    if (ret == 1)
    {
        cout << "Código: " << ptr->prox->item.numero << endl;
        cout << "Nome: " << ptr->prox->item.nome << endl;
        cout << "Endereço: " << ptr->prox->item.endereco << endl;
        cout << "Dependentes: " << ptr->prox->item.dependentes << endl;

        cout << endl << "Projetos do Funcionário: " << endl;
       
        ImprimeProjetos(ptr->prox->item.projetos);
       
        system("pause");
        system("cls");
    
        cout << endl;
    }
    else
    {
        cout << endl << "Funcionário não encontrado!" << endl << endl;
        system("pause");
        system("cls");
    }
    
}
void ExcluiFuncionario(TListaEncadeada *listaE) // Função para excluir funcionário
{
    TFuncionario fun;
    TApontador x = listaE->Primeiro;
    int cont = 0, ret_proj;

    while (x->prox != NULL)
    {
        ret_proj = QuantProjetos(x->prox->item.projetos);

        if (ret_proj == 0)
        {
            DeletaFuncionario(x, listaE, &fun);
            cont++;
        }
        else
        {
            x = x->prox;
        }
    }
    system("cls");
    cout << "*******************************************" << endl;
    cout << "*    TELA DE EXCLUSÃO DE FUNCIONÁRIOS     *" << endl;
    cout << "*******************************************" << endl << endl;
    cout << endl << cont << " Funcionário(s) excluído(s) com sucesso!" << endl << endl;
    //sleep(5);
    system("cls");
}

void DeletaFuncionario(TApontador x, TListaEncadeada *listaE, TFuncionario *fun)
{
    TApontador q;

    if ((VerificaListaVaziaEncadeada(*listaE)) || (x == '\0') || (x->prox == '\0'))
    {
        cout << "Lista vazia!";
    }
    else
    {
        q = x->prox;
        *fun = q->item;
        x->prox = q->prox;
        if (x->prox == NULL)
        {
            listaE->Ultimo = x;
        }
        delete q;
    }
}

void DadosFuncionario(TChave cod, TListaEncadeada *listaE)
{
    TApontador ptr;
    int ret;

    ret = PesquisaListaEncadeada(cod, *listaE, &ptr);

    if (ret == 1)
    {
        cout << "Código: " << ptr->prox->item.numero << endl;
        cout << "Nome: " << ptr->prox->item.nome << endl;
        cout << "Endereço: " << ptr->prox->item.endereco << endl;
        cout << "Dependentes: " << ptr->prox->item.dependentes << endl;

        cout << endl << "Projetos atualmente com o funcionário: " << endl;

        ImprimeProjetos(ptr->prox->item.projetos);
    }
    else
    {
        cout << endl << "Funcionário não encontrado." << endl << endl;
    }

}

int PesquisaListaEncadeada(TChave cod, TListaEncadeada listaE, TApontador *ptr)
{
    TApontador aux = listaE.Primeiro;
    while (aux->prox != NULL)
    {
        if (aux->prox->item.numero == cod)
        {
            *ptr = aux;
            return 1;
        }
        else
        {
            aux = aux->prox;
            *ptr = aux;
        }
    }
    return 0;
}

void CadastraProjetos(TListaEncadeada *listaE) // Função para realizar o cadastro dos projetos
{
    TProjeto proj;
    TApontador ptr;
    TChave cod;
    int ret;
    cout << "*******************************************" << endl;
    cout << "*       TELA DE CADASTRO DE PROJETOS      *" << endl;
    cout << "*******************************************" << endl << endl;

    cout << "Informe o código do funcionário: ";
    cin >> cod;
    
    cout << endl;

    ret = PesquisaListaEncadeada(cod, *listaE, &ptr);

    if (ret == 1)
    {
        DadosFuncionario(cod, listaE);
        cout << endl;
        cout << "Informe o código do projeto: ";
        cin >> proj.codigo;
        cin.ignore();
        fflush(stdin);
        cout << "Informe o nome do projeto: ";
         fgets(proj.nome, MAXTAM, stdin);//mudei aqui

        while ((cout << "Horas trabalhadas: ") && !(cin >> proj.horas))
        {
            cout << "Você inseriu um valor não numérico." << endl;
            cin.clear();
            cin.ignore();
        }

        InsereSequencial(proj, &(ptr->prox->item.projetos));

        cout << endl << "Projeto cadastrado com sucesso!" << endl<< endl;
       // sleep(5);
    }
    else
    {
        cout << endl << "Funcionário não encontrado." << endl << endl;
    }
}

void ImprimeProjetos(TListaSequencial listaS)
{
    for (int i = 0; i < listaS.ultimo; i++)
    {
        cout << endl << "Código do Projeto: " << listaS.item[i].codigo;
        cout << endl << "Nome do Projeto: " << listaS.item[i].nome;
        cout << endl << "Horas Trabalhadas: " << listaS.item[i].horas << endl;
    }
}

int QuantProjetos(TListaSequencial listaS)
{
    int cont = 0;
    for (int i = 0; i < listaS.ultimo; i++)
    {
        if (listaS.item[i].codigo != '\0' && listaS.item[i].nome != '\0' && listaS.item[i].horas != '\0')
        {
            cont++;
        }
    }
    return cont;
}

void ImprimeContraCheque(TListaEncadeada *listaE) // Função para realizar a impressão do contra-cheque
{
    if (VerificaListaVaziaEncadeada(*listaE))
    {
        cout << "Não existe funcionários cadastrados!" << endl << endl;
    }
    else
    {

        TApontador x = listaE->Primeiro;

        int numero_projetos = 0, horasSemanais = 0;
        float salarioBruto = 0, inss = 0, impostoRenda = 0, salarioLiquido = 0;

        while (x->prox != NULL)
        {
            numero_projetos = QuantProjetos(x->prox->item.projetos);

            cout << "*******************************************" << endl;
            cout << "*        CONTRA-CHEQUE DO FUNCIONÁRIO     *" << endl;
            cout << "*******************************************" << endl << endl;

            cout << "Código: " << x->prox->item.numero << endl;
            cout << "Nome do funcionário: " << x->prox->item.nome << endl;

            if (numero_projetos != 0)
            {
                horasSemanais = CalculaHorasSemanais(x->prox->item.projetos);
                cout << "Total de Horas Semanais: " << horasSemanais << endl;

                salarioBruto = CalculaSalarioBruto(horasSemanais, x);
                cout << "Salário Bruto: R$ " << salarioBruto << endl;

                impostoRenda = (salarioBruto * 0.15);
                cout << "Desconto de IR: R$ " << impostoRenda << endl;

                inss = (salarioBruto * 0.085);
                cout << "Desconto de INSS: R$ " << inss << endl;

                salarioLiquido = (salarioBruto - inss - impostoRenda);
                cout << "Salário Líquido: R$ " << salarioLiquido << endl << endl;
            }
            else
            {
                cout << endl << "O funcionario não trabalha em nenhum projeto! " << endl <<endl;
            }
            x = x->prox;
        }
    }
    system("pause");
    system("cls");
}

int CalculaHorasSemanais(TListaSequencial listaS)
{
    int horas = 0;
    for (int i = 0; i < listaS.ultimo; i++)
    {
        horas += listaS.item[i].horas;
    }
    return horas;
}

float CalculaSalarioBruto(int TotaldeHoras, TApontador x)
{
    float salario = (((45 * TotaldeHoras) * 4) + (35 * x->prox->item.dependentes));
    return salario;
}

void ExcluiProjetos(TListaEncadeada *listaE)
{

    TProjeto proj;
    TChave cod;
    TApontador ptr;

    int ret, codigo_projeto, op, numero_projeto;

    cout << "*******************************************" << endl;
    cout << "*      TELA DE EXCLUSÃO DE PROJETO        *" << endl;
    cout << "*******************************************" << endl << endl;

    cout << "Informe o código do funcionário: ";
    cin >> cod;

    cout << endl;

    ret = PesquisaListaEncadeada(cod, *listaE, &ptr);

    if (ret == 1)
    {
        DadosFuncionario(cod, listaE);
       
        do
        {
            numero_projeto = QuantProjetos(ptr->prox->item.projetos);
            if (numero_projeto > 0)
            {
                cout << endl;
                cout << "Informe o código do projeto que queira excluí-lo: ";
                cin >> codigo_projeto;

                ApagaProjeto(ptr, &ptr->prox->item.projetos, codigo_projeto, &proj);

                cout << "Deseja excluir mais algum projeto? Digite: 1-SIM 2-NÃO: ";
                cin >> op;
                system("cls");
            }
            else
            {
                cout << "O funcionário não possui mais projetos!" << endl;
                break;
            }

        } while (op != 2);
    }
    else
    {
        cout << endl << "O código informado não retornou nenhum funcionário!" << endl << endl;
    }
}

int PesquisaListaSequencial(TListaSequencial *listaS, TChave cod)
{
    for (int i = 0; i < listaS->ultimo; i++)
    {
        if (cod == listaS->item[i].codigo)
        {
            return i;
        }
        else
        {
        return -1;
        }
    } 
}

void ApagaProjeto(TApontador ptr, TListaSequencial *listaS, TChave cod, TProjeto *proj)
{
    int indice;

    indice = PesquisaListaSequencial(&ptr->prox->item.projetos, cod);

    if (indice >= 0)
    {
        *proj = listaS->item[indice];
        for (int i = indice; i < listaS->ultimo - 1; i++)
        {
            listaS->item[i] = listaS->item[i + 1];
        }
        listaS->ultimo--;
        cout << "O projeto informado foi removido com sucesso do sistema!" << endl << endl;
        //sleep(5);
    }
    else
    {
        cout << "O projeto informado não consta na lista!" << endl << endl;
        //sleep(5);
    }
}