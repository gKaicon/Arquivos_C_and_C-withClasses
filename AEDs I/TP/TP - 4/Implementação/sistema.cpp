#include "sistema.hpp"

void menuPrincipal(){
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
    cout << "**            0 - SAIR                                **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Opção: ";
}

void menuManutencao(){
        system("cls");
        cout << "********************************************************" << endl;
        cout << "********************************************************" << endl;
        cout << "**                                                    **" << endl;
        cout << "**              MANUTENÇÃO DO PROGRAMA                **" << endl;
        cout << "**                                                    **" << endl;
        cout << "********************************************************" << endl;
        cout << "********************************************************" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           1 - INSERIR UMA LINHA                    **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           2 - INSERIR UMA PARADA                   **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           3 - EDITAR UMA PARADA                    **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           4 - EXCLUIR UMA PARADA                   **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           5 - EXCLUIR UMA LINHA                    **" << endl;
        cout << "**                                                    **" << endl;
        cout << "**           0 - SAIR                                 **" << endl;
        cout << "**                                                    **" << endl;    
        cout << "********************************************************" << endl;
        cout << "********************************************************" << endl;
        cout << "Opção: ";
}

void menuPesquisa(){
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
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout  << "Opção: ";
}

void pesquisaLinhaPorOrigemDestino(TipoLista *lista){
    Apontador aux = lista->primeiro->prox;
    string origem, destino;
    bool procuraLinha = false;

    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**            PROCURA LINHA POR ORIGEM/DESTINO        **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Digite a origem: ";
    getline(cin,origem);
    cin.ignore();
    cout << "Digite o destino: ";
    getline(cin,destino);

    while(aux != NULL){ //percorre a lista de Cidades
        ApontadorL auxP = aux->item.cidades.primeiro->prox; //armazena a lista de paradas(cidades) que estão dentro de uma linha, em auxP
        string chegada, saida;
        bool dest = false, orig = false;
        double valor_real = 0;

        while(auxP != aux->item.cidades.primeiro){//percorre a lista de cidades na ida
            if(auxP->item.nome == destino){ //para achar o destino
                dest = true;
                chegada = auxP->item.saida; //insere o horario da chegada
                while(auxP != aux->item.cidades.primeiro){ //percorre a lista de cidades na volta
                    valor_real += auxP->item.valor_passagem; //soma ao valor da passagem de cidade em cidade
                    auxP = auxP->ant;
                    if(auxP->item.nome == origem){//para achar a origem
                        orig = true;
                        saida = auxP->item.saida; //insere o horario da saida
                        break;
                    }
                }
                break;
            }
            auxP = auxP->prox;
        }
        if(orig && dest == false) cout << "Nenhuma linha foi encontrada!";
        Sleep(1500);
        if(orig && dest) procuraLinha = true;
        if(procuraLinha){//origem e destino foram encontrados, ele mostra
            cout << "ID: " << aux->item.id << endl;
            cout << "Companhia: " << aux->item.companhia << endl;
            cout << "Chegada/Saída: " << chegada << "/" << saida << endl; 
            cout << "Valor da Passagem: " << valor_real << endl;
            system("PAUSE");
        }
        aux = aux->prox;
    }
}

//Pesquisa linhas de acordo com o código.
void pesquisaLinhaPorCodigo(TipoLista *lista){
    string codigo;
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**            PESQUISA DE LINHA POR CÓDIGO            **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Digite o código a ser pesquisado: ";
    cin >> codigo;
    cin.ignore();
    imprimeItem(lista, codigo);
}


//Insere uma nova linha de onibus.
void insereLinha(TipoLista *lista){
    TipoLinha parada;
    TipoRota linha;
    string comp, id;
    char op = 's';
     int i = 0;
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                   CADASTRA LINHA                   **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Digite o id da linha: ";
    getline(cin, id);
    cout << "Digite a companhia: ";
    getline(cin, comp);

    linha.id = id;
    linha.companhia = comp;

    insereListaUltimo(lista, &linha);
    do{
        string nome, hora;
        double valor;

        cout << "Digite o nome da " << i <<"ª parada: ";
        getline(cin,nome);
        
        cout << "Digite o valor da passagem da parada: ";
        cin >> valor;
        cin.ignore();
        cout << "Digite o horário de saida da parada(hh:mm): ";
        getline(cin,hora);

        parada.nome = nome;
        parada.valor_passagem = valor;
        parada.saida = hora;
        parada.id = i + 1;

        cout << "Deseja cadastrar mais paradas?(s/n)";
        cin >> op;
        cin.ignore();
    }while(op == 's');
}

void incluirParada(TipoListaLinha *lista){
    string id;
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                   CADASTRA PARADA                  **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    imprimeLista(lista);
    cout << "Qual o id da linha que deseja incluir uma parada?";
    getline(cin, id);
    Apontador aux = lista->primeiro->prox;
    while(aux != NULL){
        if(aux->item.id == id){
            imprimeListaD(&aux->item.cidades);
            TipoItemD parada;
            string nome, hora, pAnterior;
            double valor;

            cout << "Digite o nome da parada: ";
            getline(cin, nome);
            cout << "Digite o valor da passagem da parada: ";
            cin >> valor;
            cin.ignore();
            cout << "Digite o horário de saida da parada(hh:mm): ";
            getline(cin, hora);
            cout << "Digite o nome da parada antes da que está sendo adicionada: ";
            getline(cin, pAnterior);

            int id =  aux->item.cidades.ultimo->item.id + 1;
            parada.nome = nome;
            parada.valor_passagem = valor;
            parada.saida = hora;
            parada.id = id;

            ApontadorL auxP = aux->item.cidades.primeiro->prox;
            while(auxP != aux->item.cidades.primeiro){
                if(auxP->item.nome == pAnterior){
                    insereItemAposElementoD(&aux->item.cidades,parada,auxP->item.id);
                    cout << "Parada inserida com sucesso";
                    Sleep(1800);
                }
                auxP = auxP->prox;
            }
            cout << "Parada não encontrada!";
            return;
        }
        aux = aux->prox;
    }
    cout << "Linha não encontrada";
    Sleep(1800);
}

void alterarParada(TipoLista *lista){
    Apontador aux = lista->primeiro->prox;
    string id;
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                   EDITAR PARADA                    **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Lista de Linhas" << endl;
    imprimeLista(lista);
    cout << "\nQual o id da linha que deseja alterar uma parada?";
    getline(cin, id);
    
    while(aux != NULL){
        if(aux->item.id == id){
            ApontadorL auxP = aux->item.cidades.primeiro->prox;
            string nome;
            
            imprimeListaD(&aux->item.cidades);
            cout << "Qual o nome da parada que deseja alterar?";
            getline(cin, nome);
            
            while(auxP != aux->item.cidades.primeiro){
                if(auxP->item.nome == nome){
                    cout << "Insira o novo nome da parada: ";
                    getline(cin, auxP->item.nome);
                    cout << "Digite o novo valor da passagem da parada: ";
                    cin >> auxP->item.valor_passagem;
                    cin.ignore();
                    cout << "Digite o novo horário de saida da parada(hh:mm): ";
                    getline(cin, auxP->item.saida);
                    cout << "PARADA ALTERADA COM SUCESSO!";
                    return;
                }
                auxP = auxP->prox;
            }
            cout << "Parada não encontrada!";
            return;
        }
        aux = aux->prox;
    }
    cout << "Linha não encontrada";
}

//Elimina uma parada de uma linha existente.
void eliminarParada(TipoLista *lista){
    Apontador aux = lista->primeiro->prox;
    string id;
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                   EXCLUIR PARADA                   **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Lista de Linhas" << endl;
    imprimeLista(lista);
    cout << "\nQual o id da Linha que deseja excluir uma parada?";
    getline(cin, id);

    while(aux != NULL){
        if(aux->item.id == id){
            ApontadorL auxP = aux->item.cidades.primeiro->prox;
            string nome;

            imprimeListaD(&aux->item.cidades);
            cout << "Qual o nome da parada que deseja excluir?";
            getline(cin, nome);
            
            while(auxP != aux->item.cidades.primeiro){
                if(auxP->item.nome == nome){
                    retiraItemPorIdD(&aux->item.cidades,auxP->item.id);
                    cout << "Parada excluída!";
                    return;
                }
                else cout << "Parada não encontrada";
                auxP = auxP->prox;
            }
        }
        else cout << "Linha não encontrada";
        aux = aux->prox;
    }
}

void eliminarLinha(TipoLista *lista){ //Elimina toda uma linha.
    string id;
    system("cls");
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "**                                                    **" << endl;
    cout << "**                   EXCLUIR LINHA                    **" << endl;
    cout << "**                                                    **" << endl;
    cout << "********************************************************" << endl;
    cout << "********************************************************" << endl;
    cout << "Lista de Linhas" << endl;
    imprimeLista(lista);
    cout << "Qual o id da Linha que deseja excluir?";
    getline(cin, id);
    removeItemPorId(lista, id);
}