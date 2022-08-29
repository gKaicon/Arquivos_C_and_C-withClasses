#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double cat1, cat2, hipo;
    cout << "Dê o valor de cateto adjacente: ";
    cin >> cat1;
    cout << "Dê o valor de cateto oposto: ";
    cin >> cat2;
    hipo = sqrt(pow(cat1,2) + pow(cat2,2));
    
    //explicação passo a passo para o usuario entender
    cout<<"O valor do cateto adjacente é "<<cat1<<", e o valor do cateto oposto é "<<cat2<<".\n";
    cout<<"O teorema de pitagoras é basicamente a hipotenusa ao quadrado é igual a soma dos catetos ao quadrado, o mesmo que a² = b² + c²";
    cout<<"\nLogo, o cateto oposto ao quadrado é: "<<pow(cat2,2)<<", e o cateto adjacente ao quadrado é: "<<pow(cat1,2);
    cout<<"\nResolvendo temos que: \n"<<cat1<<"² + "<<cat2<<"² = "<<hipo<<"²\n"<<pow(cat1,2)<<" + "<<pow(cat2,2)<<" = "<<pow(hipo,2)
    <<"\n"<<(pow(cat1,2)+pow(cat2,2))<<" = "<<pow(hipo,2);

    return 0;
}