#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    time_t t1 = time(NULL);        // Registro do tempo inicial
    Sleep(3000);                   // Espera de 3 segundos
    time_t t2 = time(NULL);        // Registro do tempo final
    cout << "t1 = " << t1 << endl; // Timestamp
    cout << "t2 = " << t2 << endl; // Timestamp
    cout << "\nDiferença de tempo em minutos: " << difftime(t2, t1) / 60 << endl;
    cout << "Diferença de tempo em segundos: " << difftime(t2, t1) << endl;
    cout << "Diferença de tempo em milisegundos: " << difftime(t2, t1) * 1000 << endl;

    if (difftime(t2, t1) >= 3)
        cout << "\nO tempo de espera foi de pelo menos 3 segundos.\n";
    else
        cout << "\nO tempo de espera foi menor que 3 segundos.\n";

    struct tm *data_hora_atual;
    time_t segundos; // vari´avel do tipo time_t para armazenar o tempo11 time(&segundos); // obtendo o tempo em segundos

    // convertendo de segundos para o tempo local
    data_hora_atual = localtime(&segundos);
    // Acessando dados convertidos para a struct data_hora_atual
    cout << "\nDia..........: " << data_hora_atual->tm_mday;
    // para retornar o m^es corretamente devemos adicionar +1
    cout << "\nMes..........: " << data_hora_atual->tm_mon + 1;
    cout << "\nAno..........: " << data_hora_atual->tm_year + 1900;
    cout << "\nDia do ano...: " << data_hora_atual->tm_yday; // dia do26 cout << "\nDia da semana: " << data_hora_atual->tm_wday; // dia da27
    // retornando hora, minuto e segundos
    cout << "\nHora ........: " << data_hora_atual->tm_hour; // hora
    cout << ":" << data_hora_atual->tm_min;                  // minuto
    cout << ":" << data_hora_atual->tm_sec;                  // segundo32
    // retornando dia, m^es e ano
    cout << "\nData ........: " << data_hora_atual->tm_mday; // dia
    cout << "/" << data_hora_atual->tm_mon + 1;              // m^es
    cout << "/" << data_hora_atual->tm_year + 1900;          // ano
    
    return 0;
}