#include <iostream>
#include <windows.h>

using namespace std;

typedef struct Horario{
    int hora;
    int min;
};

typedef struct Data{
    int dia;
    int mes;
    int ano;
};

typedef struct Compromisso{
    char descricao[100];
    Data dt;
    Horario hr;
};

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    struct Compromisso compromisso1;

    cout << "Descrição: ";
    cin.getline(compromisso1.descricao, 100);
    cout << "Data: ";
    cin >> compromisso1.dt.dia >> compromisso1.dt.mes >> compromisso1.dt.ano;
    cout << "Horário: ";
    cin >> compromisso1.hr.hora >> compromisso1.hr.min;

    cout << "Compromisso\n Descrição: " << compromisso1.descricao;
    cout << "\n Data: " << compromisso1.dt.dia << "/" << compromisso1.dt.mes << "/" << compromisso1.dt.ano;
    cout << "\n Horário: " << compromisso1.hr.hora << " : " << compromisso1.hr.min;

    return 0;
}