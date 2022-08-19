#include <iostream>
#include <windows.h>

using namespace std;

int main(){
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls");
  int numPed, i = 1, quatQ = 1, inic;
  double tamLado;
  cout<<"Qual o tamanho da barra de chocolate em centimetros(cm): ";
  cin>>tamLado;
  do{
    inic = quatQ;  //tamanho de quadrados iniciais
    tamLado = tamLado/2; //tamanho de cada lado do quadradinho
    quatQ = quatQ * 4;  //após a divisão por dois, devo saber quantos quadradinhos tem
    numPed = quatQ;  //Numero de pedaços se possível
    //Depuração em código...
    //cout<<"Laço "<<i<<"\tN° de pedaços iniciais: "<<inic<<"\tN° de pedaços após divisão: "<<numPed<<" com "<<tamLado<<"cm cada\n"; i++;
  }while(tamLado>=2);
  cout << "Tem "<<numPed<<" pedaços com "<<tamLado<<"cm cada.";
  return 0;
}