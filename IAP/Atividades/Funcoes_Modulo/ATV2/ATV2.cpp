#include <iostream>
#include <windows.h>
#include "cabec.hpp"

using namespace std;
 
int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);

   int cartelaAposta[15], cartelaResult[15], op, perg;

   PreencherResult(cartelaResult);

   do{
      system("cls");
      do{
         Menu();
         cin >> op;
      }while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5);

         if(op == 1){

            int v;

            for(int i = 0; i < 15; i++){
               cout << "\nLaço " << i << "\n";
               cout << "Digite apenas valores entre 0-25\t" << (i+1) << "° valor: ";
               cin >> v;
               while(v > 25 || v < 0){
                  cout << "\nLaço " << i << "\n";
                  cout << "Digite apenas valores entre 0-25\t" << (i+1) << "° valor: ";
                  cin >> v;
               }
               if(v < 25 && v > 0){
                  while(encontrouValor(cartelaAposta, v )){
                        cout << "\nLaço " << i << "\n";
                        cout << "Digite apenas valores entre 0-25 e não repita\t" << (i+1) << "° valor: ";
                        cin >> v;
                  }
                  cartelaAposta[i] = v;
                  v = NULL;
               }
            }
         }
         if(op == 2)PreencherAposta(cartelaAposta);
         if(op == 3)cmpVetor(cartelaResult, cartelaAposta);
         if(op == 4)ordenaResult(cartelaResult);
         if(op == 5)ordenaResult(cartelaAposta);
         
         cout << "\n\nDigite 1 para sim\nDigite 0 para não\nDeseja escolher mais uma opção?";
         cin >> perg;
   }while(perg == 1);   
   return 0;
}