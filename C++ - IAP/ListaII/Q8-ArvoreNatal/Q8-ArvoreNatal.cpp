#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("color 0a");
    system("cls");

    int n, i, j;
    cout << "Digite o tamanho da árvore: ";
    cin>>n;
    cout<<"\n";
    
    //   ÁRVORE

    i=1;//começa em 1
    while(i <= n){// vai de 1 até o tamanho da árvore
        for(j = (n-i); j >= 1 ; j--){//for de espaços
            //o laço vai decrescer até chegar em 1, para imprimir os espaços, de acordo com os asteriscos
            cout<<" ";
        }
        for(j = 1 ; j <= i; j++){//for de asteriscos
            //logo após o fim do laço acima, será imprimido 1 asterisco
            cout<<"*";
            if(i>j){
            //se no laço o número de asteriscos for maior que o anterior, sempre irá imprimir um a mais, exceto na primeira vez
                cout<<"*";
            }
        }
        cout<<"\n";
        i++; //incremento
    }

    //   CAULE

    for(i = 1 ; i <= (n/2); i++){//for do caule, onde será imprimido os asteriscos
        for(j = 1; j <= (n-1) ; j++){//for de espaços, onde será imprimido a mesma quantidade de espaços, e de asteriscos
            cout<<" ";
        }
        cout<<"*";            
        cout<<"\n";
    }
    return 0;
}