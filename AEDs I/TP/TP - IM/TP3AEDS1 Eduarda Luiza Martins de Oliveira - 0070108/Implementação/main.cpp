#include "funcoes.cpp"

int main(int argc, char const *argv[])
{
    UINT UTF8 = 65001;
    SetConsoleOutputCP(UTF8);

    srand(time(NULL));

    Hospital hospital;
    cadastraMedicos(&hospital);
    inicializaFila(&hospital.fila_de_espera);

    int opcao;
    do
    {
        menu();
        cin >> opcao;
        cin.ignore();

        system("cls");

        switch (opcao)
        {
        case 1:
            novoAtendimento(&hospital);
            break;

        case 2:
            atualiza(&hospital);
            break;

        case 3:
            exibeAtendimentos(hospital);
            break;

        case 4:
            exibeFilaEspera(hospital);
            break;

        case 5:
            exibeRelatorio(hospital);
            break;
        }
    } while (opcao != OPCAO_SAIDA);

    return 0;
}
