#include <iostream>
#include <windows.h>
#include <math.h>
#define PI 3.14

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int angulo;
    double anguloRad, Sen, Cos, Tng;
    cout<<"Digite o ângulo inteiro: ";
    cin>>angulo;
    //anguloInteiro * PI /180
    anguloRad = (angulo * PI /180);
    Sen = sin(anguloRad);
    Cos = cos(anguloRad);
    Tng = tan(anguloRad);
    cout<<"\nSeno: "<<Sen;
    cout<<"\nCosseno: "<<Cos;
    cout<<"\nTangente: "<<Tng;
    return 0;
}