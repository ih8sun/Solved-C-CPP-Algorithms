#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define maxLength 100
using namespace std;


struct Infraccion{

    int edad;
    char sexo;
    char distrito;
    char regimen;

};

int generarAleatorio(int,int);
void rellenarInfractores(Infraccion [],int tam);
void imprimirInfractores(Infraccion [],int);
void hallar_Menor(Infraccion [],int);
void porcentaje_regimenes(Infraccion [],int);
void promedioPorDistrito(Infraccion [],int );
void ordenarInfractores(Infraccion [],int );
int main(){

    srand (time(NULL));

    int tam = generarAleatorio(1,50);

    Infraccion *infractores;
    infractores = new Infraccion[tam];
    
    rellenarInfractores(infractores,tam);
    ordenarInfractores(infractores,tam);
    imprimirInfractores(infractores,tam);
    hallar_Menor(infractores,tam);
    porcentaje_regimenes(infractores,tam);
    promedioPorDistrito(infractores,tam);
}


void rellenarInfractores(Infraccion infractor[],int tam){

    int x;


    for(int i = 0; i < tam ;i++){
        infractor[i].edad = generarAleatorio(18,75);
        
        x = generarAleatorio(1,3);
        switch (x)
        {
        case 1:
            infractor[i].distrito = 'M';
            break;
        
        case 2:
            infractor[i].distrito = 'V';
            break;
        
        case 3:
            infractor[i].distrito = 'C';
            break;
        }
        
        x = generarAleatorio(1,2);
        switch (x)
        {
        case 1:
            infractor[i].sexo = 'M';
            break;
        
        case 2:
            infractor[i].sexo = 'F';
            break;

            break;
        }
        
        x = generarAleatorio(1,3);
        switch (x)
        {
        case 1:
            infractor[i].regimen = 'M';
            break;
        
        case 2:
            infractor[i].regimen = 'R';
            break;
        
        case 3:
            infractor[i].regimen = 'N';
            break;
        }

    }
}

int generarAleatorio(int M,int N){

    int tam = rand() % (N-M+1) + M;
    return tam;
}

void imprimirInfractores(Infraccion infractor[],int tam){

    cout<<"\n\n\t\t[ IMPRIMIENDO INFRACTORES ]\n\n";
    for(int i = 0; i < tam; i++){
        cout<<"\nInfractor -> ["<<i<<"]\n";
        cout<<"Edad -> "<<infractor[i].edad<<endl;
        cout<<"Sexo -> "<<infractor[i].sexo<<endl; 
        cout<<"Distrito -> "<<infractor[i].distrito<<endl;
        cout<<"Regimen -> "<<infractor[i].regimen<<endl;
    }
}


void hallar_Menor(Infraccion infractor[],int tam){


    cout<<"\n\n\t\t[ IMPRIMIENDO MENOR EDAD ]\n\n";
    int menor = 999;
    int x = 0;
    for(int i = 0; i < tam; i++){
        if(menor > infractor[i].edad){
            menor = infractor[i].edad;
        }
    }
    cout<<"\nLa Menor Edad fue ->"<<menor<<endl;

    for(int i = 0; i < tam; i++){
        if(menor == infractor[i].edad){
            cout<<"\nInfractor -> ["<<i<<"]\n";
            cout<<"Edad -> "<<infractor[i].edad<<endl;
            cout<<"Sexo -> "<<infractor[i].sexo<<endl; 
            cout<<"Distrito -> "<<infractor[i].distrito<<endl;
            cout<<"Regimen -> "<<infractor[i].regimen<<endl;
        }
    }

}

void porcentaje_regimenes(Infraccion infractor[],int tam){

    int i;
    float porcentaje = 0;
    float porcentajeAux = 0;

    for(i = 0; i < tam; i++){
        if(infractor[i].sexo == 'M' && infractor[i].edad < 25 && infractor[i].regimen == 'R'){
            porcentaje++;
        }   
    }

    porcentaje = (porcentaje/50);
    porcentaje *= 100;
    cout<<"\n\nPorcentaje de Varones - 25 anios en Regimen RER -> %"<<porcentaje<<endl; 

    for(i = 0; i < tam; i++){
        if(infractor[i].edad > 38 && infractor[i].regimen == 'M'){
            porcentajeAux++;
        }   
    }
    porcentajeAux = (porcentajeAux/50);
    porcentajeAux *= 100;
    cout<<"Porcentaje de Varones + 38 anios en Regimen RER -> %"<<porcentajeAux<<endl; 
}

void promedioPorDistrito(Infraccion infractor[],int tam){

    float distritoM = 0,distritoC = 0,distritoV = 0;
    float edadM = 0,edadC = 0,edadV = 0;

    for(int i = 0; i < tam; i++){

        if(infractor[i].distrito == 'M'){
            edadM += infractor[i].edad;
        }

        if(infractor[i].distrito == 'C'){
            edadC += infractor[i].edad;
        }

        if(infractor[i].distrito == 'V'){
            edadV += infractor[i].edad;
        }
    }

    cout<<"\n\n\t\t[ PROMEDIOS ]\n\n";
    cout<<"Promedio de distrito Miraflores-> "<<edadM/tam<<endl;
    cout<<"Promedio de distrito Vitarte-> "<<edadV/tam<<endl;
    cout<<"Promedio de distrito Callao-> "<<edadC/tam<<endl<<endl;

}

void ordenarInfractores(Infraccion infractor [],int tam){

    int auxEdad;
    char auxSexo,auxDistrito,auxRegimen;

    for(int i=0; i < tam; i++){
        for(int j = 0; j < tam-1; j++){

            if(infractor[j].edad > infractor[j+1].edad){
                
                auxEdad = infractor[j].edad;
                infractor[j].edad = infractor[j+1].edad;
                infractor[j+1].edad = auxEdad;

                auxSexo = infractor[j].sexo;
                infractor[j].sexo = infractor[j+1].sexo;
                infractor[j+1].sexo = auxSexo;

                auxDistrito = infractor[j].distrito;
                infractor[j].distrito = infractor[j+1].distrito;
                infractor[j+1].distrito = auxDistrito;

                auxRegimen = infractor[j].regimen;
                infractor[j].regimen = infractor[j+1].regimen;
                infractor[j+1].regimen = auxRegimen;

            }


        }
    }


}