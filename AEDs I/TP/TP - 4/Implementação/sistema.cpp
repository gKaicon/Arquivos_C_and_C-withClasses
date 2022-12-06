#include "sistema.hpp"

void Menu(){
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**            LINHAS DE ÔNIBUS INTERMUNICIPAL         **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**            1 - PROCURA LINHA DE ÔNIBUS             **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**            2 - MANUTENÇÃO NO SISTEMA               **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**            3 - SAIR                                **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Opção: ";
}

void Pesquisa(){
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**              PROCURA LINHA DE ÔNIBUS               **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**              1 - PESQUISAR POR CIDADE              **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**              2 - PESQUISAR POR CÓDIGO              **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**              0 - VOLTAR                            **" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
}


void MenuRemocao()
{
     cout << "  \n        �������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        �                      2 - EXCLUIR ROTA                        �";
     cout << "  \n        �                                                              �";
     cout << "  \n        �������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        � 1 - PRIMEIRO DA LISTA                                        �";
     cout << "  \n        �                                                              �";
     cout << "  \n        � 2 - ÚLTIMO DA LISTA                                          �";
     cout << "  \n        �                                                              �";
     cout << "  \n        � 3 - POR CÓDIGO                                               �";
     cout << "  \n        �                                                              �";
     cout << "  \n        � 4 - VOLTAR                                                   �";
     cout << "  \n        �                                                              �";
     cout << "  \n        �������������������������������������\n\n";
}

void CabecalhoEditar()
{
     cout << "  \n        �������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        �                      3 - EDITAR ROTA                         �";
     cout << "  \n        �                                                              �";
     cout << "  \n        �������������������������������������";
}


void CabecalhoListagemCompleta()
{
     cout << "  \n        �������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        �                    ROTAS CADASTRADAS                     �";
     cout << "  \n        �                                                              �";
     cout << "  \n        ��������������������������������������\n\n";
}

void CabecalhoRemocaoPorCodigo()
{
     cout << "  \n        �������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        �                    EXCLUSÃO DE ROTAS                         �";
     cout << "  \n        �                                                              �";
     cout << "  \n        �������������������������������������\n";
}

void CabecalhoPesquisaPorCodigo()
{
     cout << "  \n        �������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        �                    PESQUISA POR CÓDIGO                       �";
     cout << "  \n        �                                                              �";
     cout << "  \n        �������������������������������������";
}

void CabecalhoPesquisaPorNome()
{
     cout << "  \n        ��������������������������������������";
     cout << "  \n        �                                                              �";
     cout << "  \n        �                    PESQUISA POR NOME                         �";
     cout << "  \n        �                                                                �";
     cout << "  \n        ��������������������������������������";
}


int CadastraRota(TipoLista *lista){
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                   CADASTRA ROTA                    **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    TipoItem item;
    cout << "\n\n1. Código da rota: ";
    cin >> item.id;
    cin.ignore();
    cout << "2. Nome Companhia: ";
    cin.getline(item.companhia, 20);
    cout << "3. Quntidade de cidades presentes na rota: ";
    cin >> item.quantCidades;

    for (int i = 0; i < item.quantCidades; i++){
        cout << "ID cidade: ";
        cin >> item.paradas.idCidade;
        cout << "Nome cidade: ";
        cin >> item.paradas.Nomeparada;
        cout << "Hora chegada: ";
        item.paradas.hora_chegada = valor;
        cout << "Hora saida: ";
        item.paradas.hora_saida = valor;
        cout << "Valor Passagem: ";
        cin >> item.paradas.valorPassagem;
        InsereListaUltimo(lista, &item);
    }
    InsereListaUltimo(lista, &item);
    cout << "\nRota cadastrada com sucesso!\n\n";
    system("pause");
}

void Edicao(TipoLista *lista, TipoItem item){
    int escolher;
    do{
        char companhia[30], parada[40];
        system("cls");
        cout << "********************************************************" << endl;
        cout << "********************************************************" << endl;
        cout << "**                                                    **" << endl;
        cout << "**             MANUTENÇÃO DO PROGRAMA                 **" << endl;
        cout << "**                                                    **" << endl;
        cout << "********************************************************" << endl;
        cout << "********************************************************" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           1 - CADASTRAR                            **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           2 - EXCLUIR ROTA                         **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           3 - EDITAR ROTA                          **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           0 - SAIR                                 **" << endl;
        cout << "**                                                    **" << endl;    
        cout << "********************************************************" << endl;
        cout << "********************************************************" << endl;
        cout << "Opção: ";
        cin >> escolher;
        switch (escolher){
            case 1:
                cout << "\nCompanhia: " << item.companhia << " -> ";
                cin >> companhia;
                Atualiza(lista, item, companhia, 1);
                cout << "\nCompanhia atualizada com sucesso!\n";
                system("PAUSE");
                break;
            case 2:
                cout << "\nParada\n";
                cout << "Parada: " << item.paradas.Nomeparada << " -> ";
                cin >> parada;
                AtualizaParada(lista, item, parada);
                cout << "\nParada de aniversário atualizada com sucesso!\n";
                system("PAUSE");
                break;
            default:
                break;
        }
    } while (escolher != 0);
}