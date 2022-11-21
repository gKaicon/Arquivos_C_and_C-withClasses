#include <iostream>
#include <windows.h>
#include <time.h> 
#include <string.h>

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int um, zero1, zero2, menosUm;
    char t1[30] = {"Cruzeiro"}, t2[30] = {"Atletico"}, t4[30] = {"Atletico"}, t3[30] = {"Cruzeiro"};
    um = strcmp(t1, t2);
    zero1 = strcmp(t1, t3);
    zero2 = strcmp(t2, t4);
    menosUm = strcmp(t4, t3);
    cout << "1: " << um << endl; //argumento 1 é depois do argumento 2
    cout << "0: " << zero1 << endl; //igual
    cout << "0: " << zero2 << endl; //igual
    cout << "-1: " << menosUm << endl; //argumento 1 é antes do argumento 2
    cout << endl;
    return 0;
}