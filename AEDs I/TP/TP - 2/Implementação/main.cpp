#include "sistema.hpp"
#include "sistema.cpp"
#include "funcoesTADs.cpp"

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2); // Define a cor verde para o texto

    ListaSequencial lista;
    CriaListaVazia(&lista);
    Pilha mochila;
    InicializaPilha(&mochila);

    int op;
    bool carregouComSucesso = carregaArquivo(&lista);
    if (!carregouComSucesso){
        cout << "ERRO ao carregar os Pedidos do arquivo: " << NOME_ARQUIVO;
        system("pause");
    }

    do{
        Menu();
        cin >> op;
        cin.ignore();
        system("cls");
        switch (op){
            case 1:
                incluirPedido(&lista);
                break;
            case 2:
                listarPedidos(lista);
                break;
            case 3:
                verCardapio();
                break;
            case 4:
                consultarPedido(lista);
                break;
            case 5:
                imprimirListaEntrega(&mochila, lista);
                break;
            case 6:
                lancarEntrega(&mochila, &lista);
                break;
        }
        system("cls");
    } while (op != OPCAO_SAIDA);

    bool salvouComSucesso = salvaArquivo(&lista);
    if (!salvouComSucesso)cout << "ERRO ao salvar os pedidos no arquivo: " << NOME_ARQUIVO;
    cout << "Saindo...";
    Sleep(2000);
    return 0;
}
