#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
using namespace std;


struct Nodo{

    int dato;
    Nodo *sgte;
    Nodo*atras;

};

Nodo *primero = NULL;
Nodo *ultimo = NULL;


void agregar(){

    Nodo *nuevo; 
    nuevo = new Nodo();
    
    if(primero == NULL){

        primero = nuevo;
        primero->sgte = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }else{
        ultimo->sgte = nuevo;
        nuevo->sgte = NULL;
        nuevo->atras = ultimo;
        ultimo = nuevo;
    }


}



int main(){

    return 0;
}