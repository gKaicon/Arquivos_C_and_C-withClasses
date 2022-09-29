#include "sistema.cpp"

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2); // Define a cor verde para o texto


    ListaEncadeada listaEncadeada;
    CriaListaEncadeadaVazia(&listaEncadeada);

    bool carregouComSucesso = carregaArquivo(&listaEncadeada);

    if (!carregouComSucesso){
        cout << "Houve problemas ao carregar os funcionarios do arquivo: " << fileName;
        system("pause");
    }

    int opcao;
    do{
        menu();
        cout << "Opção: ";
        cin >> opcao;
        system("cls");

        switch (opcao){
        case 1:
            incluiNovoFuncionario(&listaEncadeada);
            break;
        case 2:
            ImprimeListaFunc(&listaEncadeada);
            incluiNovosProjetos(&listaEncadeada);
            break;
        case 3:
            ImprimeListaFunc(&listaEncadeada);
            excluiProjetos(&listaEncadeada);
            break;
        case 4:
            excluiFuncionariosSemProjetos(&listaEncadeada);
            break;
        case 5:
            consultaFuncionario(&listaEncadeada);
            break;
        case 6:
            imprimeContraCheque(&listaEncadeada);
            break;
        case 7:
            ImprimeListaFunc(&listaEncadeada);
        }

    }while (opcao != OPCAO_SAIDA);

    bool salvouComSucesso = salvaArquivo(&listaEncadeada);

    if (!salvouComSucesso){
        cout << "Houve problemas ao salvar os funcionarios no arquivo: " << fileName;
    }
    cout << "Saindo...";
    Sleep(2000);
    return 0;
}