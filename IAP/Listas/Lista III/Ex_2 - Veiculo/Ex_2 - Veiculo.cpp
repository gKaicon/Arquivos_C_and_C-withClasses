#include <iostream>
#include <windows.h>

using namespace std;

typedef struct Carro{
     string marca; 
     int ano;
     double preco;
     char nome[45];
};

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    Carro car[5];
    double orc;
    for(int i = 0; i < 5; i++){
        system("cls");
        cout << "Carro " << i+1;
        cout << "\nMarca do carro: ";
        cin >> car[i].marca;
        cout << "Nome: ";
        for(int j = 0; j < 2; j++)cin.getline(car[i].nome, 45);
        cout << "Ano do carro: ";
        cin >> car[i].ano;
        cout << "Preço do carro: R$";
        cin >> car[i].preco;
    }
    system("cls");
    cout << "Informe o orçamento: R$ ";
    cin >> orc;
    for(int i = 0; i < 5; i++){
        if(orc >= car[i].preco){
            cout << "Marca do carro: " << car[i].marca << "\tAno: " << car[i].ano << "\nPreço: R$  " << car[i].preco << "\n";
        }
    }
  //cout << endl;
  return 0;
}