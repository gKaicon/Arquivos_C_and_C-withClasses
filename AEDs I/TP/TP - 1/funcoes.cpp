#include <iostream>
#include <windows.h>
#include "TADs.hpp"
 
using namespace std;

#define MAXTAM 5

void menu(){
    cout << "CADASTRO\n\n";
    cout << "1. Projeto\n";
    cout << "2. Funcionario\n";
    cout << "0. Sair\n";
}

void menuProjeto(){
    cout << "1.1 Incluir na lista projeto\n";
    cout << "1.2 Listar projetos\n";
    cout << "1.3 Pesquisar projeto por id\n";
    cout << "1.4 Retirar projeto\n";
    cout << "1.5 Voltar\n";
}
void menuFuncionario(){
    cout << "2.1 Incluir funcionario\n";
    cout << "2.2 Incluir projeto ao funcionário\n";
    cout << "2.3 Excluir funcionário sem projeto\n";
    cout << "2.4 Excluir projeto do funcionário\n";
    cout << "2.5 Excluir funcionário por ID\n";
    cout << "2.6 Listar funcionários\n";
    cout << "2.7 Quantidade de funcionários\n";
    cout << "2.8 Pesquisa Funcionario\n";
    cout << "2.9 Imprimir todos os Contra-Cheque\n";
    cout << "2.10 Voltar\n";
}

//Projeto
void criaListaProj(ListaSequencialProjeto *lista){
    if(!listaProjectCriada){
        lista->tamanho = 0;
        lista->primeiro = 0; //usa o ponteiro para apontar para um membro da estrutura
        lista->ultimo = lista->primeiro;
        cout << "Lista de projetos criada com sucesso!\n";
        listaProjectCriada = true;
    }
    else cout << "Lista de Projetos já existe";
    Sleep(2000);
}
bool verificalistaVaziaProj(ListaSequencialProjeto *lista){
    return (lista->primeiro == lista->ultimo);
}
bool verificaListaCheiaProj(ListaSequencialProjeto *lista){
    return (lista->ultimo == MAXTAM);
}
bool incluirNaListaProjeto(ListaSequencialProjeto *lista, Projeto item){
    if (verificaListaCheiaProj(lista)){
        cout << "Lista de Projetos cheia!\n";
        return false;
    }
    else{
        lista->itemProjeto[lista->ultimo].codigo = item.codigo;
        strcpy(lista->itemProjeto[lista->ultimo].nome, item.nome);
        lista->itemProjeto[lista->ultimo].horas = item.horas;
        lista->tamanho++;
        lista->ultimo++;
        return true;
    }
}
void listaDeProjetos(ListaSequencialProjeto lista){
    if(listaProjectCriada){
        int aux;
        for (aux = lista.primeiro; aux <= (lista.ultimo-1); aux++){
            cout << "Código do Projeto: " << lista.itemProjeto[aux].codigo; // codigo do projeto
            cout << "Nome do projeto: " << lista.itemProjeto[aux].nome;
            cout << "Horas Trabalhadas: " << lista.itemProjeto[aux].horas;
            cout << "\n";
        }
        Sleep(3000);
    }
    else{
        cout << "Lista de projetos não foi criada.";
    }
}
bool pesquisaProjeto(ListaSequencialProjeto lista, int chave){
    for(int i = lista.primeiro; i < lista.ultimo; i++){
        if(chave == lista.itemProjeto[i].codigo){
            cout << "Código do Projeto: " << lista.itemProjeto[i].codigo; // codigo do projeto
            cout << "Nome do projeto: " << lista.itemProjeto[i].nome;
            cout << "Horas Trabalhadas: " << lista.itemProjeto[i].horas;
            cout << "\n";
            return true;
        }
        Sleep(3000);
    }
    return false;
}
void retiraProjeto(ListaSequencialProjeto *lista, ApontadorLE a, Projeto *item){
    int aux;
    if (verificalistaVaziaProj(lista) || lista->ultimo < a){
        cout << "Erro: Posição não existe na lista\n";
        return;
    }
    *item = lista->itemProjeto[a];

    for (aux = a; aux <= lista->ultimo; aux++){
        lista->itemProjeto[aux] = lista->itemProjeto[aux + 1];
    }
    lista->ultimo--;
    lista->tamanho--;
}

//Funcionario

void CriaListaFunc(ListaEncadeadaFuncionario *lista){
    if (!listaFuncionarioCriada){ //se não está criada, ele cria
        lista->primeiro = new Celula; //primeira posição da LISTA recebe um novo ELEMENTO
        lista->ultimo = lista->primeiro; //e o ultimo recebe o primeiro, pois se trata se uma lista vazia
        lista->ultimo->prox = NULL; //o apontador de struct prox recebe nulo, para que seja possível a próxima inserção
        cout << "Lista de funcionários criada com sucesso!\n";
        listaFuncionarioCriada = true; //lista foi criada
    }
    else{
        cout << "Lista já existe!";
    }
    Sleep(1500);//comando de espera em milisegundos
}

int VerificaListaVazia(ListaEncadeadaFuncionario *lista){
    return (lista->primeiro == lista->ultimo);
}

int qtdFunc(ListaEncadeadaFuncionario *lista){
    return lista->tamanho;
}

void incluirFunc(ListaEncadeadaFuncionario *lista, Funcionario *item){ //insere sempre após o ultimo
    lista->ultimo->prox = new Celula ; //última posição da LISTA, apontando para a última posição recebe um novo ELEMENTO
    lista->ultimo = lista->ultimo->prox; // a última posição da LISTA, recebe o apontador da última posição
    lista->ultimo->prox = NULL; //o apontador da última posição da lista recebe null recebe null
    lista->ultimo->item = *item;
    lista->tamanho++;
}

void listaDeFunc(ListaEncadeadaFuncionario lista){ //lista toda
    if(VerificaListaVazia(&lista)){ //verifica se o endereço da lista é true
        cout << "Lista Vazia";
        Sleep(1000);
        return ;
    }
    Apontador aux;
    aux = lista.primeiro->prox; //recebe o apontador de próximo, depois do pirmeiro
    while(aux != NULL){ //enquanto não for nulo, ele imprime
        cout << "Número: " << aux->item.numero << endl;
        cout << "Nome: " << aux->item.nome << endl;
        cout << "Endereço: " << aux->item.endereco << endl;
        cout << "Dependente: " << aux->item.dependentes << endl;
        cout << "Projetos: " << "\n";
        for(int i = 0; i < 5; i++){
            cout << "\t" << i+1 << "° Projeto: ";
            cout << "\t\tCódigo: " << aux->item.projeto[i].itemProjeto->codigo << endl;
            cout << "\t\tNome: " << aux->item.projeto[i].itemProjeto->nome << endl;
            cout << "\t\tHoras: " << aux->item.projeto[i].itemProjeto->horas << endl;
            cout << "\n";
        }
        aux = aux->prox;//aux sendo 'incrementado'
    }
}

void pesquisaFunc(ListaEncadeadaFuncionario *lista, int numero){ //elemento da lista
    Apontador aux;
    aux = lista->primeiro->prox; //ele pega a variavel auxiliar e compara a chave dela, com a chave digitada
    while (aux != NULL){
        if (aux->item.numero == numero){
            cout << "Número: " << aux->item.numero << endl;
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereço: " << aux->item.endereco << endl;
            cout << "Dependente: " << aux->item.dependentes << endl;
            cout << "Projetos: " << "\n";
            for(int i = 0; i < 5; i++){
                cout << "\t" << i+1 << "° Projeto: ";
                cout << "\t\tCódigo: " << aux->item.projeto[i].itemProjeto->codigo << endl;
                cout << "\t\tNome: " << aux->item.projeto[i].itemProjeto->nome << endl;
                cout << "\t\tHoras: " << aux->item.projeto[i].itemProjeto->horas << endl;
                cout << "\n";
            }
        aux = aux->prox;
        }
    }
}

void RemoveItemPorId(ListaEncadeadaFuncionario *lista, int numero){
    if (VerificaListaVazia(lista))  return; //verifica se o endereço da lista é true

    Apontador aux, anterior, x;
    x = lista->primeiro; //guarda no x o primeiro lugar da lista
    while (x != NULL){
        if (x->prox->item.numero == numero){ //quando for encontrado
            anterior = x; //anterior vai receber ele
            break;
        }
        x = x->prox; //incremento do while
    }
    aux = anterior->prox; //quando sair do while, o aux vai receber o último valor(último porque estou apontando para o próximo depois do antepenúltimo)
    anterior->prox = aux->prox; 
    delete aux; //deleta o auxiliar
    lista->tamanho--; //diminuindo a lista
}

void removeFuncionarioSemProjeto(ListaEncadeadaFuncionario *lista){
    int chave;
    Apontador aux;
    aux = lista->primeiro->prox;
    while(aux !=  NULL){
        for(int i = 0; i < 5;i++){
            if(aux->item.projeto[i].itemProjeto->codigo == NULL){ // fazer função para apagar, sugestão qtd de projeyo
                chave = aux->item.numero;
                RemoveItemPorId(lista, chave);
            }
        }
        aux = aux->prox;
    }
}

void ImprimirContraCheque(ListaEncadeadaFuncionario lista){
    if (VerificaListaVazia(&lista))return;

    int somaHoras = 0, salarioBruto;
    double horaSemanal, inss, ir, salarioLiquido;
    Apontador aux;
    aux = lista.primeiro->prox; //recebe o apontador de próximo, depois do pirmeiro

    while(aux != NULL){ //percorrendo os funcionários
        for(int i = 0; i < 5; i++) somaHoras += aux->item.projeto[i].itemProjeto->horas; //soma de horas
        horaSemanal = somaHoras/4; //Hora semanal, levando em consideração que um mês tem em média 4 semana
        salarioBruto = somaHoras * 45 + aux->item.dependentes * 35; //calculando o salário bruto
        inss = 8.5/100 * salarioBruto; //desconto Inss
        ir = 15/100 * salarioBruto; //desconto receita federal
        salarioLiquido = salarioBruto - ir - inss; //salario liquido
    //impressão
            cout << "Número: " << aux->item.numero << endl;
            cout << "Nome: " << aux->item.nome << endl;
            cout << "Endereço: " << aux->item.endereco << endl;
            cout << "Dependente: " << aux->item.dependentes << endl;
            cout << "Projetos: " << "\n";
            for(int i = 0; i < 5; i++){
                cout << "\t" << i+1 << "° Projeto: ";
                cout << "\t\tCódigo: " << aux->item.projeto[i].itemProjeto->codigo << endl;
                cout << "\t\tNome: " << aux->item.projeto[i].itemProjeto->nome << endl;
                cout << "\t\tHoras: " << aux->item.projeto[i].itemProjeto->horas << endl;
                cout << "\n";
            }
            cout << "Total de horas trabalhadas(mensal)" << somaHoras << endl;
            cout << "Total de horas trabalhas(semanal)" << horaSemanal << endl;
            cout << "Salário Bruto: " << salarioBruto << endl;
            cout << "Salário Líquido" << salarioLiquido << endl;
            cout << "\n\n";
    //zerando os valores para a próxima repetição do laço
            salarioLiquido = 0;
            salarioBruto = 0;
            horaSemanal = 0;
            somaHoras = 0;
            inss = 0;
            ir = 0;
    //incremento do laço
            aux = aux->prox;
    }
}