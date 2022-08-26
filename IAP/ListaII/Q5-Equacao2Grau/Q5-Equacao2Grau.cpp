#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double a, b, c, x1, x2, delta, rDelta;
    cout<<"Dê o valor correspondente a posição A: ";
    cin>> a;
    cout<<"Dê o valor correspondente a posição B: ";
    cin>> b;
    cout<<"Dê o valor correspondente a posição C: ";
    cin>>c;
    delta = (pow(b, 2.0) - (4 * a * c)); // cálculo de delta
    rDelta = sqrt(delta);// armazenando a raiz de delta pra usar dentro do "if"
    if (rDelta >= 0){
      //cálculos do x' e x''
      x1 = ((-(b) + (rDelta)) / 2 * a);
      x2 = ((-(b) - (rDelta)) / 2 * a);
      cout<<"As raízes da equação "<<a<<"x² + " <<b<<"x + "<<c<<" = 0,  são: \nx' = "<<x1<<"\nx'' = "<<x2;
    }
    if (rDelta < 0){
      cout << ("\nNão possui raiz real.");
    }
}