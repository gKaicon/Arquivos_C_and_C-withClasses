#include <iostream>
using namespace std;

int main()
{
    int a, b, max;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    system("pause");
    // exp1 ? exp2 : exp3;
    // condição ?(pergunta se é verdade) exp2(caso seja verdade) : exp3(caso seja falso)
    max = (a > b) ? a : b;
    cout << "Maior: " << max << "\n\n";
    return 0;
}