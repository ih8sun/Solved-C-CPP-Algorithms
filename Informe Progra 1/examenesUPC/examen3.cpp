#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define maxLength 10
using namespace std;

void rellenarMatriz(char [][maxLength]);
int generarAleatorio(int,int);
void imprimirMatriz(char [][maxLength]);
int main(){

    char matriz[maxLength][maxLength];
    rellenarMatriz(matriz);
    imprimirMatriz(matriz);


    return 0;
}


int generarAleatorio(int M,int N){

    int tam = rand() % (N-M+1) + M;
    return tam;
}


void rellenarMatriz(char matriz[][maxLength]){


    int i,j,aux;

    string diccionario = "QWERTYUIOPASDFGHJKLZXCVBNM";

    cout<<"\n\n\t\t[ IMPRIMIENDO MATRIZ ]\n\n";
    for(i = 0; i < maxLength; i++){
        for(j = 0; j < maxLength; j++){
            aux =generarAleatorio(0,25); 
            matriz[i][j] = diccionario[aux];
        }
    }

}

void imprimirMatriz(char matriz[][maxLength]){

    for(int i = 0; i < maxLength; i++){
        for(int j = 0;j < maxLength; j++){
            cout<<matriz[i][j]<<"   ";
        }
        cout<<endl;
    }
}