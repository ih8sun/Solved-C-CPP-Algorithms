#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#define tam 10
using namespace std;

void MostrarDatos(float arrayAleatorios[]){

    for(int i = 0; i < tam; i++){

        arrayAleatorios[i] = 20 + rand() % (100+1-20);
    }

    cout<<"\n\n\t\t[ MOSTRANDO DATOS GENERADOS ]\n\n";
    for(int i = 0; i < tam; i++){
        cout<<"   "<<arrayAleatorios[i];
    }

    cout<<"\n\n";
    
}

float Promedio(float arrayAleatorios[]){


    float prom = 0;

    for(int i = 0; i < tam; i++){
        prom += arrayAleatorios[i];
    }
    
    prom /= tam;

    cout<<"\nEl promedio de los [ "<<tam<<" ] numeros es "<<prom<<endl;
    return prom;

}

float DesEstandar(float arrayAleatorios[]){

    float dif,cuad,total = 0,var;
    float media = 0;
    float desvEstand;

    for(int i = 0; i < tam; i++){
        media += arrayAleatorios[i];
    }

    media /= tam;

    for(int i = 0; i < tam; i++){

        dif = arrayAleatorios[i] - media;
        cuad = dif * dif;
        total += cuad;
    }
    var = total/10;
    desvEstand = sqrt(var);

    cout<<"\n\nLa desviacion estandar es de  :"<<desvEstand<<endl<<endl;
    return desvEstand;
}

int main(){ 

    srand (time(NULL));
    system("cls");
    float arrayAleatorios [tam];
    float prom = 0;

    MostrarDatos(arrayAleatorios);

    prom = Promedio(arrayAleatorios);
    
    DesEstandar(arrayAleatorios);




    return 0;
}