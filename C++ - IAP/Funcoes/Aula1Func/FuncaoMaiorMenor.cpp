#include <iostream>
#include <windows.h>

using namespace std;

double MaiorMenor(double, double);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double maior, x, y;
    cout<<"Digite o valor de x: ";
    cin >> x;
    cout<<"Digite o valor de y: ";
    cin >> y;
    maior = MaiorMenor(x, y);
    if (maior == 0){
        cout << "Números iguais.";
    }
    cout <<"Maior: "<< maior;
    return 0;
}
double MaiorMenor(double x, double y)
{
    if (y > x)
    {
        return y;
    }
    if (x > y)
    {
        return y;
    }
    return 0;
}