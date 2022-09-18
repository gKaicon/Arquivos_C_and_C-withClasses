#include <iostream>
#include <windows.h>
using namespace std;

double soma(double a, double b){
    return (a+b);
}
double sub(double a, double b){
    return (a-b);
}
double mult(double a, double b){
    return (a*b);
}
double divi(double a, double b){
    return (a/b);
}
double moduloAB(double x){
    if(x<0)return x*(-1);
    if(x>0)return x;
}
