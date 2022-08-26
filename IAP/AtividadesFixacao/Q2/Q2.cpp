#include <iostream>

using namespace std;

int main()
{
    double a, b, soma, div, sub, mult;
    cout << "De o valor de A: ";
    cin >> a;
    cout << "De o valor de B: ";
    cin >> b;
    soma = a+b;
    mult = a*b;
    div = a/b;
    sub = a-b;
    cout<<  "\nA soma de a+b = "<< soma <<
            "\nA subtracao de a-b = "<< sub <<
            "\nA multiplicacao de a*b = "<< mult <<
            "\nA divisao de a/b = "<<div<<"\n\n";
    return 0;
}