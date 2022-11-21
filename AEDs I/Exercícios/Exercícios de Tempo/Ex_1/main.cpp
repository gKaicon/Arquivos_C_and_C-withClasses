#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void numPrimos(int num){
    int j, i, cont = 0;
    for(i = 2; i <= num; i++){
        for(j = 2; j <= i; j++){
            if(i%j == 0) break;
        }
        if(i == j){
            cout << "N°: " << i << endl;
            cont++;
        }
    }
    cout << "Qtd de número primo: " << cont << endl;
}


int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    time_t t1 = time(NULL);
    numPrimos(200000);
    Sleep(1000);
    time_t t2 = time(NULL);

    cout << "Tempo de execução em segundos: " << difftime(t2, t1) << endl;
    return 0;
}