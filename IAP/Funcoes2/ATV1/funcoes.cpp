#include <iostream>
#include <windows.h>

using namespace std;

void int_Bi(int n){
    if(n == 0)cout << n << " ";
    else{
        int_Bi(n/2);
        cout << n % 2 << " ";
    }
}