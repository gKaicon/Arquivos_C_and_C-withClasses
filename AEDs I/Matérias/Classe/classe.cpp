#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

class Pessoa{

private:
    string nome;
    int idade;
    double altura;

public:
    Pessoa(){

    }
    Pessoa(string nome, int idade, double altura){
        this->nome = nome;
        this->idade = idade;
        this->altura = altura;
    }
    string getNome(){
        return nome;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    int getIdade(){
        return idade;
    }

    void setIdade(int idade){
        this->idade = idade;
    }

    double getAltura(){
        return altura;
    }

    void setAltura(double altura){
        this->altura = altura;
    }
    void mostrarDaddos(){
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Altura: " << altura << endl;
        cout << endl << endl;
    }
};