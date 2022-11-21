#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h> 

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    vector<int>v1;
    for(int i  = 0; i < 20; i++) v1.push_back(rand()%10);
    for(int i  = 0; i < 20; i++) cout << v1[i] << "\t";
    cout << "\nTamanho: " << v1.size();
    for(int j = 0; j < v1.size(); j ++){
        if(v1[j]%2 == 0){
            v1.erase(v1.begin() + j);
            j--;
        }
        else v1[j] *= v1.size();
    }
    cout << endl ;
    for(int i  = 0; i < 20; i++) cout << v1[i] << "\t";
    
    return 0;
}

/*
Para cada elemento do vetor, come¸cando do primeiro elemento:
se for par, remova esse elemento;
se for ´ımpar, multiplique pelo tamanho do vetor.

*/