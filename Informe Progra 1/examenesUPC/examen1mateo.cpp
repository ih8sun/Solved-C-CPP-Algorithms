#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define maxLength 100
using namespace std;

int generarAleatorio(int ,int );
void llenarArreglo(int [],int );
void imprimirArreglo(int [],int );
void determinarPrimoYAs(int [],int,int &);
void determinarCapicua(int [],int,int &);
bool esPrimo(int n);
bool devolverCapicua(int );

    

int main(){

    srand (time(NULL));
    int secuencia[maxLength],i;
    int tam = generarAleatorio(12,45);
    int totalPrimoAsc = 0;
    int capicua = 0;
    int numSecuencia = 0;
    char opc;
    do{

        llenarArreglo(secuencia,tam);
        imprimirArreglo(secuencia,tam);
        determinarPrimoYAs(secuencia,tam,totalPrimoAsc);
        determinarCapicua(secuencia,tam,capicua);

        cout<<"\nIngresa T para Salir\nC continuar...\n\n";
        cout<<"Ingrese : ";
        cin>>opc;

        if(opc != 'T'){
            numSecuencia++;
        }

    }while(opc != 'T');

    cout<<"\n\n\t\t[ RESULTADOS ]\n\n";
    cout<<"Numero de secuencias : "<<numSecuencia<<endl;
    cout<<"Numero de Capicuas : "<<capicua<<endl;
    cout<<"Numero de PosAlternaPrimo y Asc : "<<totalPrimoAsc<<endl<<endl;
    return 0;
}

bool esPrimo(int numero) {
    // Casos especiales
    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
    }
return true;
}

int generarAleatorio(int M,int N){

    int tam = rand() % (N-M+1) + M;
    return tam;
}

void llenarArreglo(int arreglo[],int max){

    int i,tam;

    for(i = 0; i < max; i++){
        arreglo[i] = generarAleatorio(1,9);
    }


}


void imprimirArreglo(int arreglo[],int max){

    cout<<"\n\n\t\t[ IMPRIMIENDO ARREGLO ]\n\n";
    for(int i = 0; i < max;i++){
        cout<<"Numero en pos ["<<i<<"] -> "<<arreglo[i]<<endl;

    }

}

void determinarPrimoYAs(int arreglo[],int max,int &cantidad){

    int i = 0;

    for(i = 0; i < max; i++){//COMRPOBANDO SI ES PRIMO
        if(esPrimo(arreglo[i]) && esPrimo(arreglo[i+2]) && esPrimo(arreglo[i+4])){
            //COMPROBANDO SI ES ASCE
            if(arreglo[i] < arreglo[i+2] && arreglo[i+2] < arreglo[i+4]){
                cout<<arreglo[i]<<" - "<<arreglo[i+2]<<" - "<<arreglo[i+4]<<endl;
                cout<<endl;
                cantidad++;
            }
        }
    }

    
}

void determinarCapicua(int arreglo[],int max,int &cantidad){

    int num;

    for(int i = 0; i < max; i++){
        num = arreglo[i]*1000+arreglo[i+1]*100+arreglo[1+2]*10+arreglo[i+3];
        if(devolverCapicua(num)){
            cantidad++;
        }
    }

}

bool devolverCapicua(int num){

    int numX = num;
    int aux = numX;
    int resto,numInv = 0;

    while(aux > 0){
        resto = aux%10;
        aux = aux/10;
        numInv= numInv*10+resto;
    }

    if(numInv == numX){
        cout<<"Capicua -> "<<numInv<<endl;
        return true;
    }
    else    
        return false;

}