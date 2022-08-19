#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls");
    int num, i1 = 0, i2 = 1, aux, i = 0, soma = 0;
    cout<<"Digite a posição: ";
    cin>>num;      
    while (i < num) { //laço de repetição
        i++;//incremento do laço
        soma = soma + i1;//soma depois do incremento, pois o i1 = i1 + i2, vai dar errado.
        cout<<i1<<" ";//imprimir o i1(0 na primeira vez, depois 1, depois 1, depois 2)
        aux = i1;//guardar o i1 em aux
        i1 = i1 + i2; //sobrescrever o i1 com o valor do i1+i2, para imprimir no inicio do próximo loop
        i2 = aux; //o i2 recebe o valor de aux        
    }
    cout<<"\n\nSoma: "<<soma<<"\n\n";
    return 0;
}