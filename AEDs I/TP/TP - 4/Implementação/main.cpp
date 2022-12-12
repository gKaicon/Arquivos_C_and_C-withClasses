#include "sistema.cpp"

int main(){
    UINT CPAGE_UTF8 = 65001;     
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();     
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2); // Define a cor verde para o texto
    
    TipoListaLinha linhas;
    string senha, senhaC = "12345";
    int op, pesq, man;

    CriaListaVazia(&linhas);
    cadastraLinhasTeste(&linhas);
    cin.clear();

    do{    
        menuPrincipal();
        cin >> op;
        cin.ignore();
        switch (op){
            case 1:
                menuPesquisa();
                cin >> pesq;
                cin.ignore();
                if(pesq == 1)pesquisaLinhaPorOrigemDestino(&linhas);
                if(pesq == 2)pesquisaLinhaPorCodigo(&linhas);
                break;
            case 2:
                cout << "Insira a senha de administrador: ";
                getline(cin, senha);
                if(senha == senhaC){
                    do{
                        menuManutencao();
                        cin >> man;
                        switch (man){
                            case 1:
                                cin.ignore();
                                insereLinha(&linhas);
                                break;
                            case 2:
                                cin.ignore();
                                incluirParada(&linhas);
                                break;
                            case 3:
                                cin.ignore();
                                alterarParada(&linhas);
                                break;
                            case 4:
                                cin.ignore();
                                eliminarParada(&linhas);
                                break;
                            case 5:
                                cin.ignore();
                                eliminarLinha(&linhas);
                                break;
                        }
                    }while(man != 0);
                }
                else cout << "Senha incorreta";
                break;
            case 0:
                Sleep(1300);
                cout << "Saindo...";
                break;
        }
    }while(op != 0);
}