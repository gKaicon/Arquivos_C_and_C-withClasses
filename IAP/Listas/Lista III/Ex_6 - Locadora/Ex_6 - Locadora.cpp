#include <iostream>
#include <string.h>

using namespace std;

typedef struct Filme {
    char titulo[30];
    char genero[30];
    int duracao;
    int ano;
};

void imprimeComedia(Filme f[]) {
    for(int i = 0; i < 5; i++) {
        if(strcmp(f[i].genero,"Comedia") == 0) {
            cout << f[i].titulo << endl;
        }
    }
}

int main() {
    Filme f[5];
    for(int i = 0; i < 5; i++) {
        cin.getline(f[i].titulo,30);
        cin.getline(f[i].genero,30);
        cin >> f[i].duracao;
        cin >> f[i].ano;
        cin.ignore();
    }
    imprimeComedia(f);

    return 0;
}