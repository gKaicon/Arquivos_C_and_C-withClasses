#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int *numero, num = 5;

    *numero = num;
    cout << "numero"<< numero << "\t*numero: "<< *numero << "\t&num: "<< &num << "\tnum" << num;;

    cout << endl;

    return 0;
}