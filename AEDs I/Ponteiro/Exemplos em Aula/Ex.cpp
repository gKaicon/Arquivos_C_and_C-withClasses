#include <iostream>
#include <windows.h>
#include <time.h>
 
using namespace std;

void preencheVetor(int vet[], int tam, int fx){
    for(int i = 0; i < tam; i++) vet[i] = rand()%fx;
}

int pesquisa(int vet[], int tam, int num){
    for(int i = 0; i < tam; i++){    
        if(num == vet[i]) return 1;
    }
    return 0; 
}

void exibeVetor(int vet[], int tam){
    cout << "\n\n Vetor: \n";
    for(int i = 0; i < tam; i++) cout << vet[i] << " - " << &vet[i] << "\n";
}
 
int main(){
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
   srand(time(NULL));
   
   int tam, num, fx, *vet;
   string posi;
   
   cout <<  "Digite o tamanho do Vetor: ";
   cin >> tam;

   vet = new int[tam];

   cout << "Digite a faixa de valores a ser sorteado: ";
   cin >> fx;   

   cout << "Digite um número para ser pesquisado no Vetor: ";
   cin >> num;
    
   preencheVetor(vet, tam, fx);
   exibeVetor(vet, tam);
   if(pesquisa(vet, tam, num) == 1) cout << "Encontramos o valor";
   else cout << "Não encontramos o valor. ";
  
   return 0;
}