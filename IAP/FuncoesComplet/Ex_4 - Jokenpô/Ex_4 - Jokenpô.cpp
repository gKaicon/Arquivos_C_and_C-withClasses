#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

boolean Jogo(int, int);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    srand(time(NULL));

    int pC = 0, pV = 0, v, vC, perg;
    string nV, nC, nome;
    boolean jogo;

    cout << "Digite seu nome: ";
    cin >> nome;
    nome = "Káicon";
    do{
        system("cls");
        cout << "\t\t\t******JOKENPÔ******\n\n\nPlacar\n\n" << nome << ": " << pV << "\t\tComputador: " << pC;
        cout << "\n\n\nOpções:\n\n0 - pedra \n2 - tesoura \n5 - Papel \n\nSua escolha: ";
        cin >> v;

        //Escolha do Pedra, Papel, Tesoura
        while (v != 2 && v != 0 && v != 5){
            cout << "Escolha dentre as opções válidas \n0 - pedra \n2 - tesoura \n5 - Papel \nOpção: ";
            cin >> v;
        }

        // restringindo por meio de um laço, aos valores 0, 2, 5
        vC = rand() % 5;
        while (vC != 2 && vC != 0 && vC != 5)vC = rand() % 5;

        //Impressão da escolha
        if(v == 0)nV = "Pedra";
        if(v == 2)nV = "Tesoura";
        if(v == 5)nV = "Papel";
        if(vC == 0)nC = "Pedra";
        if(vC == 2)nC = "Tesoura";
        if(vC == 5)nC = "Papel";

        // só vai jogar pra função, se forem diferentes, pra evitar lixo de memória
        if(v == vC){
            cout << "\nEmpatou";
            pC++;
            pV++;
        }
        if(v != vC){
        jogo = Jogo(v, vC);
            if (jogo == true){
                cout << "\n\nGanhou.";
                pV++;
            }
            else{
                cout << "\n\nPerdeu.";
                pC++;
            }
        }

        cout << "\n\n\nVocê pôs:  " << nV << "\t\tComputador pôs:  " << nC;
        cout << "\n\nSe deseja continuar pressione 1, se não, pressione 0: ";
        cin >> perg;
    }while(perg == 1);
    system("cls");
    cout << "\t\t\t******JOKENPÔ******\n\n\nPlacar\n\n" << nome << ": " << pV << "\t\tComputador: " << pC << "\n\n";
    return 0;
}
boolean Jogo(int v, int C){

    //pedra
    if(v == 0 && C == 2)return true;
    if(v == 0 && C == 5)return false;
    
    //tesoura
    if(v == 2 && C == 5)return true;
    if(v == 2 && C == 0)return false;
    
    //papel
    if(v == 5 && C == 0)return true;
    if(v == 5 && C == 2)return false;
}