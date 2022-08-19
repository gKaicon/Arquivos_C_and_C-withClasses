#include <iostream>  // Biblioteca necessária para escrevermos códigos em C++
#include <windows.h> // Biblioteca necessária para chamar a função Sleep e alterar cores
#include <iomanip>   // Biblioteca que oferece diversas funções

using namespace std;

/*TABELA DE CORES DA FONTE
Preto	        0
Azul            1
Verde	        2
Ciano	        3
Vermelho	    4
Magenta	        5
Marrom	        6
Cinza claro	    7
Cinza escuro	8
Azul claro	    9
Verde claro	    10
Ciano claro	    11
Vermelho claro	12
Magenta claro	13
Amarelo         14
Branco	        15
*/

/* TABELA DE CORES DO FUNDO
1	Blue	9	Light Blue
2	Green	0	Black
3	Aqua	A	Light Green
4	Red	    B	Light Aqua
5	Purple	C	Light Red
6	Yellow	D	Light Purple
7	White	E	Light Yellow
8	Gray	F	Bright White*/

int main()
{
    // system("COLOR 8F"); // Cores do fundo
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colors, 2); // Define a cor verde para o texto

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    // setbase = base: decimal, hexadecimal, octal
    cout << "1. Utilize setbase quando desejar converter algum número para outra base.\n\n";
    cout << setbase(16); // Indica que o próximo número será em base hexadecimal
    cout << "10 em Hexadecimal: " << 10 << endl
         << endl;
    cout << setbase(10); // Retorna para a base decimal

    system("pause");

    // setw = largura do campo
    cout << "\n2. Utilize setw quando desejar definir a largura do campo.\n\n";
    cout << "Palmeiras" << setw(10) << "5 x 0" << setw(16) << "Corinthians" << endl;
    cout << "Palmeiras" << setw(10) << "3 x 0" << setw(11) << "Santos" << endl;
    cout << "Palmeiras" << setw(10) << "4 x 0" << setw(17) << "São Paulo\n\n";

    system("pause");

    cout << "\n3. Utilize Sleep para pausar o programa e setfill para preencher o restante do campo.\n\n";
    cout << "Este é um exemplo simples de loading:\n\n";
    Sleep(500); // Faz uma pausa de 500 milissegundos

    cout << "Buscando produtos. Aguarde um instante ";
    for (int i = 0; i < 10; i++)
    {
        Sleep(500);
        cout << ". ";
    }

    // setfill = preenchimento com o que quiser
    cout << "\n\nOvo caipira:" << setw(35) << setfill('.') << "R$ 12,00" << endl;
    cout << "Linguiça Mineira (kg):" << setw(25) << setfill('.') << "R$ 25,00" << endl;
    cout << "Lombo defumado:" << setw(32) << setfill('.') << "R$ 28,00" << endl;
    cout << "Coca-cola 350ml:" << setw(33) << setfill('.') << "R$  5,00\n\n";

    system("pause");

    cout << "\n4. Utilize setprecision para definir a quantidade de casas decimais.\n\n";
    // setprecision = número de casas decimais
    double const PI = 3.14159265358979323846;
    cout << "PI: " << setprecision(3) << PI << endl;

    return 0;
}