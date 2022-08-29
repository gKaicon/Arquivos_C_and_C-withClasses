#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

void RaizQuad(double, double, double);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double a, b, c, calc;
    cout<<"Dê o valor de A: ";
    cin>>a;
    cout<<"Dê o valor de B: ";
    cin>>b;
    cout<<"Dê o valor de C: ";
    cin>>c;
    RaizQuad(a, b, c);
    return 0;
}
void RaizQuad(double a, double b, double c){
        double delta;
        delta = pow(b,2) - 4*a*c;
        if(delta<0){
            cout<<"Não existe raiz real";
        }
        if(delta>0){
            double x1, x2;
            x1 = (-b + (sqrt(delta)))/2*a;
            x2 = (-b - (sqrt(delta)))/2*a;
            cout<<"x': "<<x1<<"\tx'': "<<x2;
        }
}