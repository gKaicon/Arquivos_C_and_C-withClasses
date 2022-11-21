#include "sistema.hpp"

void menu(){
    system("cls");
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*             Departamento Pessoal             *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
    cout << "*                                              *" << endl;
    cout << "*  1 - INCLUIR NOVO FUNCIONÁRIO                *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  2 - INCLUIR NOVOS PROJETOS                  *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  3 - EXCLUIR PROJETOS                        *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  4 - EXCLUIR FUNCIONÁRIOS SEM PROJETOS       *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  5 - CONSULTAR FUNCIONÁRIO                   *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  6 - IMPRIMIR CONTRA-CHEQUE                  *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  7 - LISTA DE FUNCIONÁRIOS                   *" << endl;
    cout << "*                                              *" << endl;
    cout << "*  8 - SAIR                                    *" << endl;
    cout << "*                                              *" << endl;
    cout << "************************************************" << endl;
}

//////////////////////////////////////////LISTA SEQUENCIAL////////////////////////////////////////////

void CriaListaSequencialVazia(ListaSequencial *lista){
    if (!lista->listaSequencialCriada){
        lista->listaSequencialCriada = true; //lista existe agora, e possui valor true
        lista->tamanho = 0; //o tamanho da lista(vetor) é 5, o tamanho serve para verificar se está cheia ou não
    }
}

bool ListaSequencialEstaVazia(ListaSequencial *lista){
    return lista->tamanho == 0; //verifica se ela está vazia
}

bool ListaSequencialEstaCheia(ListaSequencial *lista){
    return lista->tamanho == MAX_TAM; //verifica se ela está cheia
}

bool InsereProjeto(ListaSequencial *lista, Projeto projeto){
    //se a lista não foi criada ou está cheia
    if (!lista->listaSequencialCriada || ListaSequencialEstaCheia(lista))return false;

    lista->item[lista->tamanho] = projeto; //insere o projeto na última posição(tamanho atual)
    lista->tamanho++; //e aumenta o tamanho para que possa ser realizada uma nova inserção.
    return true;
}

void ImprimeProjeto(Projeto projeto){ //impressão básica
    cout << "\tId: " << projeto.id << endl;
    cout << "\tNome: " << projeto.nome << endl;
    cout << "\tHoras Trabalhadas: " << projeto.horas << endl;
    cout << "\n";
}

void ImprimeListaSequencial(ListaSequencial *lista){
    for (int i = 0; i < lista->tamanho; i++){ //percorre todos os projetos
        Projeto projeto = lista->item[i];
        cout << i+1 << "° Projeto\n";
        ImprimeProjeto(projeto);
        cout << "\n";
    }
}

Projeto *PesquisaProjetoPorID(ListaSequencial *lista, int id){
    for (int i = 0; i < lista->tamanho; i++){
        if (id == lista->item[i].id){
            return &lista->item[i]; // Retorna o endereço na memória do Projeto
        }
    }
    return NULL; // se não for encontrado retorna NULL, pois o projeto não existe.
}

bool RemoveProjetoPorId(ListaSequencial *lista, int id){
    if (ListaSequencialEstaVazia(lista)) return false;

    for (int i = id; i < lista->tamanho; i++)lista->item[i] = lista->item[i + 1];
    lista->tamanho--;//lista diminui de tamanho
    return true;
}

bool RemoveProjeto(ListaSequencial *lista, Projeto projeto){ //valida se o indice foi achado para só assim executar a exclusão
    if (ListaSequencialEstaVazia(lista)){
        cout << "Erro: Lista está vazia" << endl;
        return false;
    }

    int indice = IndiceDeProjeto(lista, projeto);//o indice encontrado é armazenado na variável "indice"

    if (indice == -1)return false;

    return RemoveProjetoPorId(lista, indice); //indice utilizado para remover de fato o projeto
}

int IndiceDeProjeto(ListaSequencial *lista, Projeto projeto){//procura o indice
    for (int i = 0; i < lista->tamanho; i++){
        if (lista->item[i].id == projeto.id) return i; //retorna o indice em que o projeto está
    }
    return -1;//não foi encontrado
}

int TamanhoListaSequencial(ListaSequencial *lista){
    return lista->tamanho;
}

//////////////////////////////////////////LISTA ENCADEADA////////////////////////////////////////////

void CriaListaEncadeadaVazia(ListaEncadeada *lista){
    if (!lista->listaEncadeadaCriada){//se a lista não foi criada
        lista->primeiro = new Celula; //no apontador primeiro recebe uma nova Celula
        lista->ultimo = lista->primeiro; //o primeiro apontador recebe o último, pois trata-se de uma lista vazia
        lista->ultimo->prox = NULL; //o apontador prox do apontador ultimo, recebe null
        lista->listaEncadeadaCriada = true; //e a lista foi criada
    }
    else{
        cout << "Lista já foi criada" << endl;
        Sleep(1000);
    }
}

bool ListaEncadeadaEstaVazia(ListaEncadeada *lista){
    return (lista->primeiro == lista->ultimo); //se o primeiro é igual ao último significa que não há nada entre os dois
}

void InsereListaEncadeadaUltimo(ListaEncadeada *lista, Funcionario *funcionario){//insere no último
    lista->ultimo->prox = new Celula; //o apontador prox do apontador ultimo, recebe uma nova célula
    lista->ultimo = lista->ultimo->prox; //o apontador ultimo, recebe o apontador da celula dentro dele já alterado
    lista->ultimo->item = funcionario;//aloca o funcionario na celula
    lista->ultimo->prox = NULL; //o apontador prox do apontador ultimo, recebe null, após as trocas
    lista->tamanho++;//lista aumenta de tamanho
}

void ImprimeFuncionario(Funcionario *funcionario){
    cout << "ID: " << funcionario->id << endl;
    cout << "Nome: " << funcionario->nome << endl;
    cout << "Endereço: " << funcionario->endereco << endl;
    cout << "Número de Dependentes: " << funcionario->dependentes << endl;
    cout << "\nLista de Projetos: " << endl;
    ImprimeListaSequencial(&funcionario->projetos); //lista de projetos dele
}

Funcionario *PesquisaFuncionario(ListaEncadeada *lista, int id){
    Apontador aux = lista->primeiro->prox;
    while (aux != NULL){
        if (aux->item->id == id)return aux->item;
        aux = aux->prox;//percorrer o while
    }
    return NULL; // Retorna NULL caso o funcionário procurado não esteja na lista
}

void RemoveFuncionario(ListaEncadeada *lista, Funcionario funcionario){
    if (!ListaEncadeadaEstaVazia(lista)){
        Apontador aux, anterior, x;
        x = lista->primeiro;
        while (x != NULL){
            if (x->prox->item->id == funcionario.id){
                anterior = x;//salva o anterior a x, para ser passada para a variavel auxiliar(aux)
            }
            x = x->prox; //incremento do laço para encontrar o funcionario desejado
        }
        aux = anterior->prox; //aux recebe o próximo valor após o anterior(último valor)
        anterior->prox = aux->prox; //anterior->prox recebe o último
        delete aux; // desloca o auxiliar da memória
        lista->tamanho--;//diminui da lista
        AtualizaUltimo(lista);//atualiza após a remoção
    }
}

void AtualizaUltimo(ListaEncadeada *lista){
    Apontador aux, anterior;
    aux = lista->primeiro;
    anterior = aux;
    while (aux != NULL){
        anterior = aux; //salva o anterior ao aux->prox na variavel anterior
        aux = aux->prox; //incrementa o laço
    }
    lista->ultimo = anterior;
}

int TamanhoListaEncadeada(ListaEncadeada *lista){
    return lista->tamanho;
}

///////////////////////////////////// SISTEMA ///////////////////////////////////////////
void incluiNovoFuncionario(ListaEncadeada *lista){
    Funcionario *funcionario = criaFuncionario();

    if (PesquisaFuncionario(lista, funcionario->id) == NULL){
        InsereListaEncadeadaUltimo(lista, funcionario); //insere no fim da lista, isso vem lá da listaEncadeada.cpp
        cout << "\nFuncionário incluído com Sucesso!\n" << endl;
        int opcao;
        do{
            cout << "Deseja adicionar projetos ao funcionário?" << endl;
            cout << "1 - Sim" << endl;
            cout << "2 - Não" << endl;
            cin >> opcao;
            if (opcao == 1){
                system("cls");
                int quantidade;
                cout << "Quantidade de projetos que deseja adicionar: ";
                cin >> quantidade;
                for (int i = 0; i < quantidade; i++) incluiNovoProjeto(funcionario);
            }
            system("cls");
        } while (opcao != 1 && opcao != 2);
    }
    else{ //caso exista um funcionario com o mesmo ID, que quero inserir
        cout << "\nJá existe funcionário com ID: " << funcionario->id << endl;
        cout << "Adicione novamente com outro ID" << endl;
        delete funcionario; // desloca o funcionario da memória, já que ele não será usado
        Sleep(1000);
    }
}

Funcionario *criaFuncionario(){
        Funcionario *funcionario = new Funcionario;
        cout << "Cadastro Funcionário" << endl;
        cout << "ID: ";
        cin >> funcionario->id;
        cin.ignore();
        cout << "Nome: ";
        cin.getline(funcionario->nome, 100);
        cout << "Endereço: ";
        cin.getline(funcionario->endereco, 40);
        cout << "Número de Dependentes: ";
        cin >> funcionario->dependentes;
        CriaListaSequencialVazia(&funcionario->projetos);
        return funcionario;
}

void incluiNovosProjetos(ListaEncadeada *lista){
    if (!ListaEncadeadaEstaVazia(lista)){
        Funcionario *funcionario = FuncionarioPorID(lista);

        if (funcionario != NULL){ // Só adiciona se o funcionario existir
            int opcao = 1;
            do{
                if (opcao == 1)incluiNovoProjeto(funcionario);
                system("cls");
                cout << "Deseja adicionar outro projeto para esse funcionário?\n";
                cout << "1-Sim" << endl;
                cout << "2-Não" << endl;
                cin >> opcao;
                system("cls");
            }while (opcao != 2);
        }
        else{
            cout << "\nNão existe funcionário com esse id";
            Sleep(1000);
        }
    }
    else{
        cout << "Erro: Funcionário não cadastrado!" << endl;
        Sleep(1000);
    }
}

void criaProjeto(ListaSequencial *lista, Projeto *projeto){
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

void incluiNovoProjeto(Funcionario *funcionario){
    Projeto projeto;
    criaProjeto(&funcionario->projetos, &projeto);
    if (PesquisaProjetoPorID(&funcionario->projetos, projeto.id) == NULL){ // TRUE se o projeto não está na lista, FALSE do contrário
        bool inseridoComSucesso = InsereProjeto(&funcionario->projetos, projeto);
        if (inseridoComSucesso) cout << "\nProjeto inserido com sucesso" << endl;
        else cout << "\nEsse funcionário atingiu o máximo de projetos possíveis";
    }
    else cout << "\nJá existe Projeto com ID: " << projeto.id << " nesse funcionário.\nAdicione novamente com outro ID" << endl;
    Sleep(1000);
}

Funcionario *FuncionarioPorID(ListaEncadeada *lista){
    int idFuncionario;
    cout << "ID do Funcionário: ";
    cin >> idFuncionario;
    Funcionario *funcionario = PesquisaFuncionario(lista, idFuncionario);
    return funcionario;
}

void excluiProjetos(ListaEncadeada *lista){
    if (!ListaEncadeadaEstaVazia(lista)){
        Funcionario *funcionario = FuncionarioPorID(lista); // Retorna ou o funcionário ou NULL

        if (funcionario != NULL){
            int idProjeto;
            cout << "ID do Projeto: ";
            cin >> idProjeto;

            Projeto *projeto = PesquisaProjetoPorID(&funcionario->projetos, idProjeto);
            if (projeto == NULL) cout << "\nProjeto com id igual à " << idProjeto << " não encontrado" << endl;
            else{
                bool removeuComSucesso = RemoveProjeto(&funcionario->projetos, *projeto);
                if (removeuComSucesso) cout << "\nProjeto com id: " << idProjeto << " foi removido com sucesso" << endl;
                else  cout << "\nErro: Não foi possível excluir projeto com id: " << idProjeto << endl;
            }
        }
        else cout << "\nNão existe funcionário com esse Id" << endl;
    }
    else  cout << "Erro: Nenhum Funcionário cadastrado na lista" << endl;
    Sleep(2000);
}

void excluiFuncionariosSemProjetos(ListaEncadeada *lista){
    if (!ListaEncadeadaEstaVazia(lista)){
        Apontador aux = lista->primeiro->prox;
        Apontador anterior = aux;
        while (aux != NULL && PesquisaFuncionario(lista, aux->item->id) != NULL){
            if (TamanhoListaSequencial(&aux->item->projetos) == 0){
                RemoveFuncionario(lista, *aux->item);
                aux = anterior;
            }
            anterior = aux;
            aux = anterior->prox;
        }
        cout << "Todos os funcionário sem projetos foram apagados." << endl;
        Sleep(2000);
        }
    else  cout << "Erro: Nenhum Funcionário cadastrado" << endl;
    Sleep(2000);
}

void ImprimeListaFunc(ListaEncadeada *lista){
    if(ListaEncadeadaEstaVazia(lista)){ //verifica se o endereço da lista é true
        cout << "Lista Vazia";
        Sleep(1000);
        return ;
    }
    Apontador aux;
    aux = lista->primeiro->prox; //recebe o apontador de próximo, depois do primeiro
    while(aux != NULL){ //enquanto não for nulo, ele imprime
        ImprimeFuncionario(aux->item);
        aux = aux->prox;//aux sendo 'incrementado'
    }
    Sleep(10000);
}

void consultaFuncionario(ListaEncadeada *lista){
    if (!ListaEncadeadaEstaVazia(lista)){
        Funcionario *funcionario = FuncionarioPorID(lista);

        if (funcionario != NULL) ImprimeFuncionario(funcionario);
        else cout << "\nNão existe funcionário com esse Id";
    }
    else cout << "Erro: Nenhum Funcionário cadastrado" << endl;
    Sleep(5000);
}

int totalHorasSemanais(ListaSequencial lista){
    int totalHoras = 0;
    for (int i = 0; i < lista.tamanho; i++){
        Projeto projeto = lista.item[i];
        totalHoras += projeto.horas;
    }
    return totalHoras;
}

double calculaSalarioBruto(Funcionario *funcionario){
    double salarioBruto = 0;
    int totalHoras = totalHorasSemanais(funcionario->projetos);
    salarioBruto = (totalHoras * 45) + (35 * funcionario->dependentes);
    return salarioBruto;
}

void imprimeContraCheque(ListaEncadeada *lista){
    if (!ListaEncadeadaEstaVazia(lista)){
        Apontador aux;
        aux = lista->primeiro->prox;

        while (aux != NULL){
            Funcionario *funcionario = aux->item;
            int totalHoras;
            double descontoINSS, salarioBruto, descontoIR, salarioLiquido;
            salarioBruto = calculaSalarioBruto(funcionario);
            descontoINSS = (8.5 / 100.0) * salarioBruto;
            descontoIR = (15.0 / 100.0) * salarioBruto;
            salarioLiquido = salarioBruto - descontoINSS - descontoIR;
            totalHoras = totalHorasSemanais(funcionario->projetos);
            //impressão
            cout << "Id: " << funcionario->id;
            cout << "\nNome: " << funcionario->nome;
            cout << "\nTotal de Horas Semanais: " << totalHoras;
            cout << "\nSalário Bruto: " << salarioBruto;
            cout << "\nDesconto do INSS: " << descontoINSS;
            cout << "\nDesconto de Imposto de renda: " << descontoIR;
            cout << "\nSalário líquido: " << salarioLiquido;
            cout << "\n\n";
            aux = aux->prox;
        }
    }
    else  cout << "Erro: Nenhum Funcionário cadastrado" << endl;
    Sleep(5000);
}

////////////////////////////// MANIPULAÇÃO DE ARQUIVOS /////////////////////////////////////////
bool carregaArquivo(ListaEncadeada *lista){
    ifstream arquivo;
    arquivo.open(fileName, fstream::binary); // Abre o arquivo em modo binario, ou cria se não existir

    if (arquivo.fail()){ // Se falhar
        arquivo.clear(); // Fecha o arquivo
        return false;
    }
    while (arquivo.peek() != ifstream::traits_type::eof()){ // Enquanto o arquivo nao for vazio
        Funcionario *funcionario = new Funcionario;
        arquivo.read((char *)funcionario, sizeof(Funcionario)); // Le a Struct dos funcionarios completos
        InsereListaEncadeadaUltimo(lista, funcionario); // Insere o projeto que pegou do arquivo na lista encadeada
    }
    arquivo.clear();
    return true;
}

bool salvaArquivo(ListaEncadeada *lista){
    ofstream arquivo;
    arquivo.open(fileName, ofstream::trunc | fstream::binary); // Abre arquivo em modo trunc pra deixa-lo vazio e em modo binario

    if (arquivo.fail()){
        arquivo.clear();
        return false;
    }

    Apontador aux = lista->primeiro->prox;
    while (aux != NULL){
        Funcionario *funcionario = aux->item;
        arquivo.write((char *)funcionario, sizeof(Funcionario)); // Escreve no arquivo a Struct do funcionario completa
        delete funcionario;
        aux = aux->prox;
    }
    return true;
}