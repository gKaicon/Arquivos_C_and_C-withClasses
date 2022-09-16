#include <stdio.h>
#include <stdlib.h>
#include "cabec.hpp"

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    int linha, coluna, jogador = 1, jogadas = 0, op, j1 = 0, j2 = 0;
    char jogo[3][3];
    boolean ganhou = false;

    do{
        // laço para jogar novamente
        jogadas = 0; //jogadas inicializadas em 0, para que o laço de jogadas possa ser finalizado, caso não haja vencedor
        ImprimeJogo(jogo); 
        do{ 
            // repete até alguém ganhar ou atingir 9 jogadas e dar empate
            do{
            // ler coordenadas
                system("cls");
                cout << "___Jogo da Velha___\n\n\t\tPlacar\n\nJogador 1: " << j1 << "\t\tJogador 2: " << j2;
                ImprimeJogoCoo(jogo);
                cout << "\n JOGADOR 1 = 0\n JOGADOR 2 = X \n";
                cout << "\n JOGADOR " << jogador << " \nDigite a linha dê um espaço digite a coluna que deseja jogar: ";
                scanf("%d%d", &linha, &coluna);
            //Laço que impede de digitar números maiores que as coordenadas, com uma mensagem diferente
                while(linha >= 3 || coluna >= 3){
                    system("cls");
                    cout << "___Jogo da Velha___\n\n\t\tPlacar\n\nJogador 1: " << j1 << "\t\tJogador 2: " << j2;
                    ImprimeJogoCoo(jogo);
                    cout << "\n JOGADOR 1 = 0\n JOGADOR 2 = X \n";
                    cout << "\n JOGADOR " << jogador << " \nDigite a linha dê um espaço digite a coluna que deseja jogar(valores entre 0 e 2): ";
                    scanf("%d%d", &linha, &coluna);
                }
            }while((linha < 0 || linha > 2) || (coluna < 0 || coluna > 2) || (jogo[linha][coluna] != ' '));

            // inserção de coordenadas
            if(jogador == 1){
                jogo[linha][coluna] = '0';
                jogador++; //incremento para ser o jogador 2
            }
            else{
                jogo[linha][coluna] = 'X';
                jogador = 1; //retornar para 1, para ser o jogador 1
            }
            jogadas++;  //incremento de jogadas, pois com 9 jogadas acaba
            system("cls");
    //Verificação de vitórias
        // alguém ganhou por linha
            if(vitoriaLinha(jogo) == true){
                cout << "\nO jogador 1 venceu por linha!\n";
                j1++;
                ganhou = true;
            }
            if(vitoriaLinha(jogo) == false){
                cout << "\nO jogador 2 venceu por linha!\n";
                j2++;
                ganhou = true;
            }
        // alguém ganhou por coluna
            if(vitoriaColuna(jogo) == true){
                cout << "\nO jogador 1 venceu por coluna!\n";
                j1++;
                ganhou = true;
            }
            if(vitoriaColuna(jogo) == false){
                cout << "\nO jogador 2 venceu por coluna!\n";
                j2++;
                ganhou = true;
            }
        // alguém ganhou na diagonal principal
            if(diagonalPrincipal(jogo) == true){
                cout << "\nO jogador 1 venceu na diagonal. principal!\n";
                j1++;
                ganhou = true;
            }
            if(diagonalPrincipal(jogo) == false){
                cout << "\nO jogador 2 venceu na diagonal. principal!\n";
                j2++;
                ganhou = true;
            }
        // alguém ganhou na diagonal secundária
            if(diagonalSecundaria(jogo) == true){
                cout << "\nO jogador 1 venceu na diagonal Secundária!\n";
                j1++;
                ganhou = true;
            }
            if(diagonalSecundaria(jogo) == false){
                cout << "\nO jogador 2 venceu na diagonal Secundária!\n";
                j2++;
                ganhou = true;
            }
        }while(ganhou == false && jogadas < 9);

    // imprimir jogo final
        cout << "___Jogo da Velha___\n\n\t\tPlacar\n\nJogador 1: " << j1 << "\t\tJogador 2: " << j2;
        ImprimeJogoCoo(jogo);
    //caso de empate
        if(ganhou == false){
            cout << "\nO jogo finalizou sem gamhador!\n";
        }

        cout << "\nDigite 1 para jogar novamente: \n";
        cin >> op;
    }while(op == 1); // fim do laço para jogar novamente
    return 0;
}