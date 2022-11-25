#include "sistema.cpp"

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2); // Define a cor verde para o texto
    srand(time(NULL));

    int opcao;
    Hospital hospital;
    iniciaMedicos(&hospital);
    inicializaFila(&hospital.fila_de_espera);
    do{
        atualizaMedicoPaciente(&hospital);
        menu();
        cin >> opcao;
        cin.ignore();
        system("cls");
        switch (opcao){
            case 1:
                novoAtendimento(&hospital);
                break;
            case 2:
                exibeAtendimentos(hospital);
                break;
            case 3:
                exibeFilaEspera(hospital);
                break;
            case 4:
                exibeRelatorio(hospital);
                break;
            case 5:
                system("cls");
                cout << "Saindo..." << endl;
                Sleep(1000);
                break;
        }
    }while (opcao != OPCAO_SAIDA);
    return 0;
}
