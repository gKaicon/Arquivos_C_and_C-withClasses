#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include "lista.hpp"
#include "funcoes.cpp"

using namespace std;

int main() {
    Logo(10);
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    TListaEncadeada lista;
    CriaListaVazia(&lista);
    int opcao;
    //Carregando dados salvos
    ifstream arquivo;
    ofstream InicializaArq;
    //Abre o .bin
    while(true){
        arquivo.open("funcionarios.bin");
        if(!arquivo){
            //Cria o arquivo .bin se ele nao existir
            InicializaArq.open("funcionarios.bin");
            InicializaArq << 0 << endl << 0 << endl << '#' << endl;
        }else{
            break;
        }
    }
    
    arquivo >> codFun;
    arquivo >> codProj;
    char ch;
    int tt=0;
    int it, conty, j;
    //(#,*,$) forma de ler o arquivo, sabendo onde é o fim do arquivo, o fim do nome e endereço, sendo char.
    while(true){
        tt=0;
        arquivo >> ch;
        if(ch=='#'){
            break;
        }
        //inserção dos dados char de funcionario no programa
        IniciacaoFunNom(ch);
        while(true){
            arquivo >> ch;
            if(ch=='*'){
                tt=1;
                IniciacaoFunNom(ch);
            }
            if(ch =='$'){
                IniciacaoFunEnd(ch);
                break;
            }
            if(tt==0){
                IniciacaoFunNom(ch);
            }else if(tt==2){
                IniciacaoFunEnd(ch);
            }else if(tt==1){
                tt=2;
            }
            
        }
        //inserção dos dados int de funcionario no programa
        conty=0;
        while(true){
            conty++;
            arquivo >> it;
            IniciacaoFunProj(conty, it, &lista);
            if(conty==3){
                break;
            }
        }
        j =it;
        //inserção dos dados char e int de projeto no programa
        for (int i = 0; i < j; i++)
        {
            conty=3;
            conty++;
            arquivo >> it;
            IniciacaoFunProj(conty, it, &lista);
            conty++;
            arquivo >> it;
            IniciacaoFunProj(conty, it, &lista);
            while(true){
                arquivo >> ch;
                IniciacaoCharProj(ch, &lista);
                if(ch =='$'){
                    break;
                }
                
            }
        }
    }


    
    int ty;
    //repetição do menu com opções
    do {
        menu();
        while ((cout << "Escolha a opção: ") && !(cin >> opcao)) {
            cout << endl << "Você inseriu um valor não numerico." << endl << endl; 
            cin.clear(); 
            cin.ignore();
        }
        system("cls");
        switch(opcao) {
            case 1:
                CadastraFuncionario(&lista);
                break;
            case 2:
                CadastraProjeto(&lista);
                break;
            case 3: 
                ConsultaFuncionario(&lista);
                break;
            case 4:
                ExcluiProjeto(&lista);
                break;
            case 5:
                ExcluiFuncionario(&lista);
                break;
            case 6:
                Exclui1Funcionario(&lista);
                break;
            case 7:
                ListaCheque(&lista);
                break;
            case 8:
                ListaCheque1(&lista);
                break;
        }
    } while(opcao != 9);
    Salvar(&lista);
    return 0;
}