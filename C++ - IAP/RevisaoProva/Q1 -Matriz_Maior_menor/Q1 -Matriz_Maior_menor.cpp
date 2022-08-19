#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    srand(time(NULL));
    int maior = 0, menor = 0, m[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            m[i][j] = rand()%99;
            if(m[i][j] >= maior){
                maior = m[i][j];
            }
            if(m[i][j] <= menor){
                menor = m[i][j];
            }

        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout << "Maior: "<<maior<<"\n";
    cout << "Menor: "<<menor<<"\n";
    return 0;
}