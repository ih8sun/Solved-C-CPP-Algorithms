#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

typedef struct Nodo{

    char codID[15];
    char nombreAlbum[30];
    char artista[30];
    char duracion[10];
    int anio;
    struct Nodo *siguiente;
    struct Nodo *atras;

}Nodo;


Nodo *primero = NULL;
Nodo *ultimo = NULL;

void agregar();
void CargarDatos();

int main()
{

    

    return 0;
}


void agregar(){


    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    

    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->atras = ultimo;
        ultimo = nuevo;
    }

}

void CargarDatos(char codID[],char nombreAlbum[],
                    char artista[],char duracion[],int anio){


    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    

    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->atras = ultimo;
        ultimo = nuevo;
    }

}