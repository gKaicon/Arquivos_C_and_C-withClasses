#include <iostream>
#include <windows.h>
 
using namespace std;

typedef struct DadosPessoais{
    char nome[45];
    int idade;
    char sexo;
    char cpf[14];
    char dataNasc[10];
};

typedef struct Dadosfuncionais{
    DadosPessoais func; //func é a variavel que vai chamar a outra struct(dados pessoais)
    int idSetor;
    char cargo[45];
    double salario;
};


int main(){
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");

    Dadosfuncionais fu; //fu é a variavel que vai "chamar" a struct(dados funcionais)

    //cadastro do funcionario
    cout<<"Insira a nome do Funcionário: ";
    cin.getline(fu.func.nome, 45); 
    //cin.getline = serve para ler todo o vetor de caracteres , 
    //fu(variavel de dados funcionais).func(variavel de dados pessoais).nome(variavel nome de dados pessoais, que é um vetor de tipo char), 45(tamanho do vetor))

    do{
        cout<<"Insira a Idade do Funcionário(0-99): ";
        cin>>fu.func.idade;
    }while(fu.func.idade > 99 || fu.func.idade < 1);// do- while não precisa, eu pus pra restringir os valores, mas sem ele também da certo


    cout<<"Insira o sexo do funcionário(m, f): ";
    cin>>fu.func.sexo;//fu(variavel de dados funcionais).func(variavel de dados pessoais).sexo(a variavel sexo)


    cout<<"Informe o CPF do Funcionário(formato: xxx.xxx.xxx-xx): ";
    for (int i = 0 ; i < 14; i++)cin.getline(fu.func.cpf, 14);

    cout<<"Informe a data de Nascimento do Funcionário(formato; __/__/____):";
    for (int i = 0 ; i < 10; i++)cin.getline(fu.func.dataNasc, 10);

    do{
        cout<<"Informe o id do Setor em que o funcionário está alocado(0-99): ";
        cin>>fu.idSetor; // aqui tá faltando o func, porém o func é pra chamar as variaveis de dados pessoais, e idSetor é de dados funcionais, logo o func, não é necessário, e causa erros.
    }while(fu.idSetor > 99 || fu.idSetor < 0); // do- while não precisa, eu pus pra restringir os valores, mas sem ele também da certo

    cout<<"Informe o cargo do funcionário: ";
    for (int i = 0 ; i < 45; i++)cin.getline(fu.cargo, 45);

    cout<<"Informe o sálario do Funcionário: R$";
    cin>>fu.salario;

    //Impressão dos dados padrão
    system("cls");
    cout<<"Nome: " << fu.func.nome;
    cout<<"\tIdade: " << fu.func.idade;    
    cout<<"\tSexo: " << fu.func.sexo;
    cout<<"\nCPF: " << fu.func.cpf;
    cout<<"\tData de Nascimento:" << fu.func.dataNasc;
    cout<<"\nId do Setor: " << fu.idSetor;
    cout<<"\tCargo: "<< fu.cargo;
    cout<<"\tSalário: R$ ";
    cin>>fu.salario;

   return 0;
}