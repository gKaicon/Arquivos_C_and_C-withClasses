#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "lista.hpp"

#define MAXTAM 5

using namespace std;

void menu( ) {    
     system("color 0B");
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        �                     DEPARTAMENTO PESSOAL                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 1 - INCLUIR NOVO FUNCIONÁRIO                                 �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 2 - INCLUIR NOVO PROJETO                                     �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 3 - CONSULTAR FUNCIONÁRIO                                    �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 4 - EXCLUIR PROJETO                                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 5 - EXCLUIR TODOS FUNCIONARIOS SEM PROJETO                   �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 6 - EXCLUIR FUNCIONARIO SEM PROJETO                          �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 7 - IMPRIMIR TODOS OS CONTRA-CHEQUES                         �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 8 - IMPRIMIR UM CONTRA-CHEQUE                                �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        � 9 - SALVAR E SAIR                                            �";
     cout<<"  \n        �                                                              �";
     cout<<"  \n        ����������������������������������������������������������������\n\n";
}

void CriaListaVazia(TListaEncadeada * lista) {
    lista->Primeiro = new TCelula;
    lista->Ultimo = lista->Primeiro;
    lista->Primeiro->prox = NULL;
}

int VerificaListaVazia(TListaEncadeada lista) {
    return (lista.Primeiro == lista.Ultimo);
}

void Insere(TFuncionario f, TListaEncadeada *lista) {
    lista->Ultimo->prox = new TCelula;
    lista->Ultimo = lista->Ultimo->prox;
    lista->Ultimo->Item = f;
    lista->Ultimo->prox = NULL;
}

void InsereProjeto(TFuncionario f, TListaEncadeada *lista) {
    int ret;
    TApontador p;
    ret = Pesquisa(f.codFuncionario, *lista, &p);
    p->prox->Item.codProjeto[f.projetos-1] = f.codProjeto[f.projetos-1];
    p->prox->Item.projetos = f.projetos;

}
//Carregamento automatico dos projetos do .bin
void InsereProjetoI(int contu, TFuncionario f, TListaEncadeada *lista) {
    int ret;
    TApontador p;
    ret = Pesquisa(f.codFuncionario, *lista, &p);
    p->prox->Item.codProjeto[contu] = f.codProjeto[contu];
    p->prox->Item.projetos = f.projetos;

}

void CadastraFuncionario(TListaEncadeada *lista) {
    TFuncionario f;
    Logo(1);
    codFun++;
    f.codFuncionario = codFun;
    cin.ignore();
    int re=0;
    char testa[40];
    char testa2[40];
    while(true){
        re=0;
        for(int i=0;i<40;i++){
            testa[i]=false;
        }
        cout << "Nome: ";
        fgets(testa, MAXTAM,stdin );
        for(int i=0;i<40;i++){
            f.nomeFuncionario[i]=testa[i];
            
        }
        f.nomeFuncionario[40]=false;

        for(int i=0;i<40;i++){
            if(f.nomeFuncionario[i] == '*' || f.nomeFuncionario[i] == '#' || f.nomeFuncionario[i] == '$'){
                cout << endl << "Por favor, não utilize os caracteres '#', '*' e '$'." << endl << endl; 
                re=1;
                break;
            }
        }
        if(re==0){
            break;
        }
        for(int i=0;i<40;i++){
            f.nomeFuncionario[i]=false;
            testa[i]=false;
        }
    }
    for(int i=0;i<40;i++){
        testa[i]=false;
        testa2[i]=false;
    }
    while(true){
        re=0;
        cout << "Endereço: ";
        fgets(testa2 ,MAXTAM,stdin );
        for(int i=0;i<40;i++){
            f.endereco[i]=testa2[i];
        }
        f.endereco[40]=false;
        for(int i=0;i<40;i++){
            if(f.endereco[i] == '*' || f.endereco[i] == '#' || f.endereco[i] == '$'){
                cout << endl << "Por favor, não utilize os caracteres '#', '*' e '$'." << endl << endl; 
                re=1;
                break;
            }
        }
        if(re==0){
            break;
        }
        for(int i=0;i<40;i++){
            f.endereco[i]=false;
            testa2[i]=false;
        }
    }
    
    
    // Verifica se o valor de entrada corresponde ao tipo esperado
    while ((cout << "Número de Dependentes: ") && !(cin >> f.numDependentes)) {
        // Exibe mensagem em caso de divergência encontrada
        cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
        // Apaga o sinalizador de erro cin para que futuras operações funcionem corretamente
        cin.clear(); 
        // Pula para a próxima linha ignorando caracteres para o buffer de entrada
        cin.ignore(); 
    }
    f.projetos=0;
    
    Insere(f, lista);
    cout << "\nFuncionário cadastrado com sucesso!\n\n";
    Sleep(1000);
    system("cls");
}
//Cadastramento automático dos funcionarios do .bin
void CadastraFuncionarioI(char nomef[40],char ender[40],int codf,int dep,int proj,TListaEncadeada *lista) {
    TFuncionario f;
    f.codFuncionario = codf;
    for(int i=0;i<40;i++){
        f.nomeFuncionario[i]= nomef[i];
        f.endereco[i]=ender[i];
    }
    f.numDependentes=dep;
    f.projetos=proj;
    Insere(f, lista);
}

void CadastraProjeto(TListaEncadeada *lista) {
    int t=0, cod;
    TApontador p;
    TFuncionario f;
    char testa[40];
    Logo(2);
    int tp;        
    tp = Listagem(lista);  
    if(tp==1){
        while ((cout << "Digite o código de um funcionário: ") && !(cin >> cod)) {
            cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
            cin.clear(); 
            cin.ignore();
        }
        system("cls");
        Logo(2);
        t = Pesquisa(cod, *lista, &p);
        if(t==0){
            cout << "Funcionário não encontrado." << endl << endl;
            system("pause");
            system("cls");
        }else{
            f = p->prox->Item;
            if(f.projetos<5){
                codProj++;
                f.codProjeto[f.projetos].codProjeto = codProj;
                cin.ignore();
                int re=0;
                while(true){
                    re=0;
                    cout << "Nome: ";
                    for(int i=0;i<40;i++){
                        testa[i]=false;
                    }
                    fgets(testa, MAXTAM,stdin );
                    for(int i=0;i<40;i++){
                        f.codProjeto[f.projetos].nomeProjeto[i]=testa[i];
                    }
                    f.codProjeto[f.projetos].nomeProjeto[40]=false;
                    for(int i=0;i<40;i++){
                        if(f.codProjeto[f.projetos].nomeProjeto[i] == '*' || f.codProjeto[f.projetos].nomeProjeto[i] == '#' || f.codProjeto[f.projetos].nomeProjeto[i] == '$'){
                            cout << endl << "Por favor, não utilize os caracteres '#', '*' e '$'." << endl << endl; 
                            re=1;
                            break;
                        }
                    }
                    if(re==0){
                        break;
                    }
                    for(int i=0;i<40;i++){
                        f.codProjeto[f.projetos].nomeProjeto[i]=false;
                        testa[i]=false;
                    }
                }
                while ((cout << "Número de Horas Semanais: ") && !(cin >> f.codProjeto[f.projetos].numHoras)) {
                    cout << endl << "Você inseriu um valor não numerico." << endl; 
                    cin.clear(); 
                    cin.ignore();
                }
                f.projetos++;
                InsereProjeto(f, lista);
                cout << "\nProjeto cadastrado com sucesso!\n\n";
            }else {
                cout << "Número máximo de projetos atingido.";
            }
            Sleep(1000);
            system("cls");
        }
    }
}
//Cadastramento automático dos projetos do .bin
void CadastraProjetoI(int codf,int codp,int htrab,char nomep[40],int contu,TListaEncadeada *lista) {
    int t=0, cod;
    TApontador p;
    TFuncionario f;
    cod=codf;
    t = Pesquisa(cod, *lista, &p);
    f = p->prox->Item;
    f.codProjeto[contu].codProjeto = codp;
    for(int i=0;i<40;i++){
        f.codProjeto[contu].nomeProjeto[i]=false;
        f.codProjeto[contu].nomeProjeto[i]=nomep[i];
    }
    f.codProjeto[contu].numHoras=htrab;
    InsereProjetoI(contu, f, lista);
    
}


int Pesquisa(TChave cod, TListaEncadeada lista, TApontador *p) {
    TApontador aux = lista.Primeiro;
    while (aux->prox != NULL) {
        if (aux->prox->Item.codFuncionario == cod) {
            *p = aux;
            return 1;
        } else {
            aux = aux->prox;
            *p = aux;
        }
    }
    return 0;
}
//Listagem de todos os contra-cheques
void ListaCheque(TListaEncadeada *lista) {
    TApontador aux = lista->Primeiro->prox;

    aux = lista->Primeiro->prox;

    system("cls");
    Logo(6);
    if(!aux){
        cout << "Não existe funcionarios." << endl << endl;
    }

    while (aux) {  
        cout << "\nCódigo: " << aux->Item.codFuncionario;
        cout << "\nNome: " << aux->Item.nomeFuncionario;
        int horasTotal=0;
        for (int i = 0; i < aux->Item.projetos; i++)
        {
            horasTotal+=aux->Item.codProjeto[i].numHoras;
        }
        cout << "\nTotal de horas semanais: " << horasTotal;
        double salarioBruto=0;
        salarioBruto=horasTotal * 45.00;
        salarioBruto+=35.00 * aux->Item.numDependentes;
        cout << "\nSalário Bruto: R$" ;
        printf("%.2f",salarioBruto);
        cout << "\nDesconto do INSS: R$" ;
        printf("%.2f",(salarioBruto * 0.085));
        cout << "\nDesconto do IR: R$";
        printf("%.2f",(salarioBruto * 0.15));
        salarioBruto-=((salarioBruto * 0.085) + (salarioBruto * 0.15));
        cout << "\nSalário Líquido: R$" ;
        printf("%.2f",salarioBruto);
        cout << "" << endl << endl;
        aux = aux->prox;
    }

    system("pause");
    system("cls");
}
//Listagem de 1 contra-cheque
void ListaCheque1(TListaEncadeada *lista) {

    Logo(9);
    int to;
    to = Listagem(lista);
    if(to==1){
        int cod, ret;
        TApontador p;
        while ((cout << "Digite o código de um funcionário: ") && !(cin >> cod)) {
            cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
            cin.clear(); 
            cin.ignore();
        }
        system("cls");
        Logo(9);
        ret = Pesquisa(cod, *lista, &p);
        if(ret==1){
            cout << "\nCódigo: " << p->prox->Item.codFuncionario;
            cout << "\nNome: " << p->prox->Item.nomeFuncionario;
            int horasTotal=0;
            for (int i = 0; i < p->prox->Item.projetos; i++)
            {
                horasTotal+=p->prox->Item.codProjeto[i].numHoras;
            }
            cout << "\nTotal de horas semanais: " << horasTotal;
            double salarioBruto=0;
            salarioBruto=horasTotal * 45.00;
            salarioBruto+=35.00 * p->prox->Item.numDependentes;
            cout << "\nSalário Bruto: R$" ;
            printf("%.2f",salarioBruto);
            cout << "\nDesconto do INSS: R$" ;
            printf("%.2f",(salarioBruto * 0.085));
            cout << "\nDesconto do IR: R$";
            printf("%.2f",(salarioBruto * 0.15));
            salarioBruto-=((salarioBruto * 0.085) + (salarioBruto * 0.15));
            cout << "\nSalário Líquido: R$" ;
            printf("%.2f",salarioBruto);
            cout << "" << endl << endl;
        }else {
            cout << "\nFuncionário não encontrado.\n"<< endl;
        }
        
        system("pause");
        system("cls");
    }
    
}

void ConsultaFuncionario(TListaEncadeada *lista) {
    TChave cod;
    TApontador p;
    int ret;
    Logo(3);
    int to;
    to = Listagem(lista);
    if(to==1){
        while ((cout << "Digite o código de um funcionário: ") && !(cin >> cod)) {
            cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
            cin.clear(); 
            cin.ignore();
        }
        system("cls");
        Logo(3);
        ret = Pesquisa(cod, *lista, &p);

        if (ret == 1) {
            cout << "\nCódigo: " << p->prox->Item.codFuncionario;
            cout << "\nNome: " << p->prox->Item.nomeFuncionario;
            cout << "\nEndereço: " << p->prox->Item.endereco;
            cout << "\nNumero de Dependentes: " << p->prox->Item.numDependentes << endl << endl;
            cout << "Projetos: "<< endl;
            for (int i = 0; i < p->prox->Item.projetos; i++)
            {
                cout << "\nCódigo: " << p->prox->Item.codProjeto[i].codProjeto;
                cout << "\nNome: " << p->prox->Item.codProjeto[i].nomeProjeto;
                cout << "\nNúmero de Horas Semanais: " << p->prox->Item.codProjeto[i].numHoras << endl;
            }
            
        } else {
            cout << "\nFuncionário não encontrado.\n"<< endl;
        }
        cout << "" << endl;
        system("pause");
        system("cls");
    }
}

void ApagaFuncionario(TApontador x, TListaEncadeada *lista, TFuncionario *f) {
    TApontador q;

    if ((VerificaListaVazia(*lista)) || (x == NULL) || (x->prox == NULL)) {
        cout << "Erro. Lista vazia";
    } else {
        q = x->prox;
        *f = q->Item;
        x->prox = q->prox;
        if (x->prox == NULL) {
            lista->Ultimo = x;
        }
        delete q;
    }
}
//Apaga todos os funcionarios sem projetos
void ExcluiFuncionario(TListaEncadeada *lista) {
    
    TFuncionario f;
    TApontador x = lista->Primeiro;
    int cont=0;
    Logo(5);
    if(x->prox == NULL){
        cout << "Não existe funcionarios." << endl << endl;
        system("pause");
        system("cls");
    }else{  
        do{
            // Verifica se funcionário não possui projetos
            
            if(x->prox->Item.projetos==0){
                ApagaFuncionario(x, lista, &f);
                cont ++;
            }
            x= x->prox;
            
        }while (x->prox != NULL) ;
        system("cls");
        Logo(5);
        cout << "\n" << cont << " funcionário(s) sem projetos excluído(s) com sucesso!\n\n";
        system("pause");
        system("cls");
    }
        
}
//Apaga um funcionario especifico sem projeto
void Exclui1Funcionario(TListaEncadeada *lista) {
    
    TFuncionario f;
    TApontador p;
    Logo(7);
    int ti;
    ti = Listagem(lista);
    if(ti==1){
        int cod;
        while ((cout << "Digite o código de um funcionário: ") && !(cin >> cod)) {
            cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
            cin.clear(); 
            cin.ignore();
        }
        int ret,cont=0;
        ret = Pesquisa(cod, *lista, &p);
        system("cls");
        Logo(7);
        if (ret == 1) {
            if(p->prox->Item.projetos==0){
                ApagaFuncionario(p, lista, &f);
                cont ++;
            }else {
                cout << "Funcionário ainda possui projeto(s)." << endl << endl;
            }
            cout << "\n" << cont << " funcionário sem projetos excluído com sucesso!\n\n";
        } else {
            cout << "\nFuncionário não encontrado.\n"<< endl<<endl;
        }
        system("pause");
        system("cls");
    }
        
}
void ExcluiProjeto(TListaEncadeada *lista) {
    int cont=0;
    int cod, ret,teste=0;
    TApontador p;
    Logo(4);
    int to;
    to = Listagem(lista);
    if(to==1){
        while ((cout << "Digite o código de um funcionário: ") && !(cin >> cod)) {
            cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
            cin.clear(); 
            cin.ignore();
        }
        system("cls");
        Logo(4);
        ret = Pesquisa(cod, *lista, &p);
        int tr;
        if(ret == 1){
            tr=ListagemP(cod, lista);
            if(tr==1){
                while ((cout << "Digite o código de um projeto: ") && !(cin >> cod)) {
                    cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
                    cin.clear(); 
                    cin.ignore();
                }
                system("cls");
                Logo(4);
                for (int i = 0; i < p->prox->Item.projetos; i++)
                {
                    if(cod==p->prox->Item.codProjeto[i].codProjeto){
                        teste=1;
                    }
                }
                if(teste==1){
                    p->prox->Item.projetos--;
                    cont++;
                }else{
                    cout << "Projeto não encontrado." << endl << endl;
                    system("pause");
                }
            }else if(tr==0){
                system("pause");
            }
            
        }else{
            cout << "Funcionário não encontrado." << endl << endl;
            system("pause");
        }
        
        
        
        system("cls");
        Logo(4);
        cout << "\n" << cont << " projeto(s) excluído(s) com sucesso!\n\n";
        system("pause");
        system("cls");
    }
        
}
//Armazena titulos para serem utilizados
void Logo(int escolha){
    switch(escolha){
        case 1:
            cout << "*******************************************\n";
            cout << "*        CADASTRO DE FUNCIONÁRIO          *\n";
            cout << "*******************************************\n\n";
            break;
        case 2:
            cout << "*******************************************\n";
            cout << "*          CADASTRO DE PROJETO            *\n";
            cout << "*******************************************\n\n";
            break;
        case 3:
            cout << "*******************************************\n";
            cout << "*        CONSULTA DE FUNCIONÁRIO          *\n";
            cout << "*******************************************\n\n";
            break;
        case 4:
            cout << "*******************************************\n";
            cout << "*           EXCLUSÃO DE PROJETO           *\n";
            cout << "*******************************************\n\n";
            break;
        case 5:
            cout << "*******************************************\n";
            cout << "*        EXCLUSÃO DE FUNCIONÁRIOS         *\n";
            cout << "*******************************************\n\n";
            break;
        case 6:
            cout << "*******************************************\n";
            cout << "*      CONTRA-CHEQUES DE FUNCIONÁRIOS      *\n";
            cout << "*******************************************\n\n";
            break;
        case 7:
            cout << "*******************************************\n";
            cout << "*         EXCLUSÃO DE FUNCIONÁRIO         *\n";
            cout << "*******************************************\n\n";
            break;
        case 8:
            cout << "*******************************************\n";
            cout << "*              VOLTE SEMPRE               *\n";
            cout << "*******************************************\n\n";
            break;
        case 9:
            cout << "*******************************************\n";
            cout << "*      CONTRA-CHEQUE DE FUNCIONÁRIO      *\n";
            cout << "*******************************************\n\n";
            break;
        case 10:
            cout << "*******************************************\n";
            cout << "*             SEJA BEM VINDO              *\n";
            cout << "*******************************************\n\n";
            Sleep(1500);
            system("cls");
            break;
        default:
            break;
    }
}
//Listagem de funcionarios com codigo e nome
int Listagem (TListaEncadeada *lista){
    TApontador aux = lista->Primeiro->prox;

    aux = lista->Primeiro->prox;
    if(!aux){
        cout << "Não existe funcionarios.";
        cout << "" << endl << endl;
        system("pause");
        system("cls");
        return 0;
    }
    cout << "Lista de Funcionarios:" <<endl ;
    while (aux) {  
        cout << "\nCódigo: " << aux->Item.codFuncionario;
        cout << "  -  Nome: " << aux->Item.nomeFuncionario;
        aux = aux->prox;
    }
    cout << "" << endl << endl;
    return 1;
}
//Listagem de projetos com codigo e nome
int ListagemP (int cod, TListaEncadeada *lista){
    TApontador p;
    int ret;
    ret = Pesquisa(cod, *lista, &p);
    if(p->prox->Item.projetos == 0){
        cout << "Não existe projetos.";
        cout << "" << endl << endl;
        return 0;
    }
    cout << "Lista de Projetos:" <<endl ;
    if(ret==1){
        for(int i=0;i < p->prox->Item.projetos;i++){
            cout << "\nCódigo: " << p->prox->Item.codProjeto[i].codProjeto;
            cout << "  -  Nome: " << p->prox->Item.codProjeto[i].nomeProjeto;
        }
        cout << "" << endl << endl;
    }
    return 1;
}
char nomef[40];
int contini=0;
//Carrega nome do funcionario do .bin
void IniciacaoFunNom(char ch){
    if(ch!='*'){
        nomef[contini]=ch;
        contini++;
    }else if(ch == '*'){
        contini = 0;
    }
}
char ender[40];
//Carrega endereco do funcionario do .bin
void IniciacaoFunEnd(char ch){
    if(ch!='$'){
        ender[contini]=ch;
        contini++;
    }else if(ch == '$'){
        contini = 0;
    }
}
int codf, dep, proj, codp, htrab;
//Carrega os int do funcionario e projeto do .bin
void IniciacaoFunProj(int conty, int it,TListaEncadeada *lista){
    switch(conty){
        case 1:
            codf=it;
            break;
        case 2:
            dep=it;
            break;
        case 3:
            proj=it;
            //Cadastra funcionario do .bin
            CadastraFuncionarioI(nomef, ender, codf, dep, proj, lista);
            break;
        case 4:
            codp=it;
            break;
        case 5:
            htrab=it;
            break;
    }
}
char nomep[40];
int contu=0;
//Carrega nome do projeto do .bin
void IniciacaoCharProj(char ch, TListaEncadeada *lista){
    if(ch!='$'){
        nomep[contini]=ch;
        contini++;
    }else if(ch == '$'){
        contini = 0;
        //cadastra projeto do .bin
        CadastraProjetoI(codf, codp, htrab, nomep, contu, lista);
        contu++;
        if(contu==proj){
            //Reiniciam as variaveis de repassagem para salvamento
            for(int i=0;i<40;i++){
                nomef[i]=false;
                ender[i]=false;
                nomep[i]=false;
            }
            codf=0;
            dep=0;
            proj=0;
            codp=0;
            htrab=0;
            contu=0;
        }
    }
}
//Salva os dados resultantes da utilização do usuario de forma que o programa consiga carregar.
void Salvar(TListaEncadeada *lista){
    ofstream sarquivo;
    sarquivo.open("funcionarios.bin");
    sarquivo << codFun << endl <<
    codProj << endl;

    TApontador aux = lista->Primeiro->prox;

    aux = lista->Primeiro->prox;

    while (aux) {  
        sarquivo << aux->Item.nomeFuncionario << "*"<< endl <<
        aux->Item.endereco << "$"<< endl <<
        aux->Item.codFuncionario << endl <<
        aux->Item.numDependentes << endl <<
        aux->Item.projetos << endl;
        for(int i=0;i< aux->Item.projetos;i++){
            sarquivo << aux->Item.codProjeto[i].codProjeto << endl <<
            aux->Item.codProjeto[i].numHoras << endl <<
            aux->Item.codProjeto[i].nomeProjeto << "$" << endl;
        }
        aux = aux->prox;
    }
    sarquivo <<"#";
    Logo(8);
    cout << "Dados salvos com sucesso."<< endl << endl;
    cout << "Trabalho de Algoritimos e Estrutura de Dados,"<< endl;
    cout << "Turma SI 211, Novembro de 2021."<< endl << endl;
    cout << "Obrigado por ter utilizado."<< endl << endl;
    cout << "By Enzo Alves Dupin e Edmilson M B Filho"<< endl << endl;


}