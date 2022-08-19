#include <iostream>
#include <windows.h>

using namespace std;

// todas as funções, passam a matriz como parametro, pois ela será verificada dentro deles

void ImprimeJogo(char jogo[3][3]){
    // utilizado para imprimir o jogo no ínicio, preenchendo com espaços
    int linha, coluna;
    for (linha = 0; linha < 3; linha++){
        for (coluna = 0; coluna < 3; coluna++){
            jogo[linha][coluna] = ' ';
        }
    }
}

void ImprimeJogoCoo(char jogo[3][3]){
    int l, c;
    //imprimir o jogo ao longo das inserções, deixando as coordenadas visíveis para facilitar o jogo
    cout << "\n\n\t 0   1   2\n\n"; //imprimir as coordenadas das colunas
    for(l = 0; l < 3; l++){
        for(c = 0; c < 3; c++){
            if(c == 0){
                printf("\t"); //quando estiver na coluna 0 sempre vai dar uma tabulação, para sempre imprimir o | na posição certa
            }
            printf(" %c ", jogo[l][c]); // imprimir o jogo como ele está, depois de ser feita a alteração
            if(c < 2){ //sempre que a coluna for menor que 2, ele vai colocar o |
                printf("|");
            }
            if(c == 2){ //sempre que for igual a dois, vai ser imprimida a coordenada das linhas na frente
                printf("  %d", l);
            }
        }
        if(l < 2){ //Após percorrer o laço de colunas, se a linha for abaixo de 2, ele vai imprimir a linha que divide as linhas
            printf("\n\t-----------");
        }
        printf("\n");
    }
}

boolean vitoriaLinha(char jogo[3][3]){
    if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||   //1ª linha
       jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||   //2ª linha
       jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){    //3ª linha
        return true; //o true é para a vitória do jogador 1
    }
    
    if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||   //1ª linha
       jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||   //2ª linha
       jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){    //3ª linha
        return false; //o false é para a vitória do jogador 2
    }    
}

boolean vitoriaColuna(char jogo[3][3]){
    if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||   //1ª linha
       jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||   //2ª linha
       jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){    //3ª linha
       return true; //o true é para a vitória do jogador 1
    }
    
    if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||   //1ª linha
       jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||   //2ª linha
       jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){    //3ª linha
       return false; //o false é para a vitória do jogador 2
    }
}

boolean diagonalPrincipal(char jogo[3][3]){
    if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){    //diagonal Principal
        return true; //o true é para a vitória do jogador 1
    }
    
    if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){    //diagonal Principal
        return false; //o false é para a vitória do jogador 2
    }
}

boolean diagonalSecundaria(char jogo[3][3]){
    if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){    //diagonal secundária
        return true; //o true é para a vitória do jogador 1
    }
    
    if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){    //diagonal secundária
        return false; //o false é para a vitória do jogador 2
    }
}