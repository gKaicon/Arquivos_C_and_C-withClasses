#include <iostream>
#include <windows.h>
#include <time.h> 
#include <iomanip>
#include "Semaforo.cpp"
using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    Semaforo s1;
    s1.corSemaforo(s1.setColor(0));
    Sleep(1500);
    s1.corSemaforo(1);
    Sleep(1500);
    s1.corSemaforo(2);
    Sleep(1500);
    cout << endl;
    return 0;
}