#include <iostream>
#include <stdlib.h>
#include <string>
#define maxTam 100
using namespace std;

struct Cine{

    int numCliente;
    string nombreCliente;
    string telefono;
    string fechaInscripcion;

};

void pedirDatos(Cine personas[],int tam){

    for(int i = 0; i < tam; i++){
        cout<<"\nIngresa numero de cliente ["<<i+1<<"]-> ";
        cin>>personas[i].numCliente;
        cout<<"Ingresa Nombre de Cliente ->";
        fflush(stdin);
        getline(cin,personas[i].nombreCliente);
        cout<<"Ingresa Telefonp de Cliente ->";
        fflush(stdin);
        getline(cin,personas[i].telefono);

        cout<<"Fecha de Inscripcion\n";
        cout<<"Ejemplo-> 12/10/2021\n";
        cout<<"Ingresa : ";
        fflush(stdin);
        getline(cin,personas[i].fechaInscripcion);

    }
}

void mostrarDatos(Cine personas[],int tam){

    cout<<"\n\n\t\t[ DESPLEGANDO CLIENTES ]\n\n";
    for(int i = 0; i < tam; i++){
        cout<<"Numero de CLiente -> "<<personas[i].numCliente<<endl;
        cout<<"Nombre de CLiente -> "<<personas[i].nombreCliente<<endl;
        cout<<"Telefono de CLiente -> "<<personas[i].telefono<<endl;
        cout<<"Fecha de Inscripcion -> "<<personas[i].fechaInscripcion<<endl;
        cout<<endl;
    }
}

void buscarCliente(Cine personas [],int tam){
    
    int numAux;
    bool encontrado = false;
    cout<<"\n\n\t\t[ BUSQUEDA DE ALGUN CLIENTE ]\n\n";
    cout<<"Ingresa el numero del cliente -> ";
    cin>>numAux;

    for(int i = 0; i < tam; i++){
        if(numAux == personas[i].numCliente){
            cout<<"\n[ Se encontro a la persona ]\n";
            cout<<"Numero de CLiente -> "<<personas[i].numCliente<<endl;
            cout<<"Nombre de CLiente -> "<<personas[i].nombreCliente<<endl;
            cout<<"Telefono de CLiente -> "<<personas[i].telefono<<endl;
            cout<<"Fecha de Inscripcion -> "<<personas[i].fechaInscripcion<<endl;
            encontrado = true;
            break;
        }
    }

    if(encontrado != true){
        cout<<"No se encontro a la persona a buscar\n\n";
    }
}

int main(){

    Cine personas[maxTam];
    int tam;   
    bool correcto = false;


    cout<<"\n\n\t\t[ DEFINIENDO PERSONAS ]\n\n";

    do{
        cout<<"\nIngrese cantidad de personas [-100] -> ";
        cin>>tam;
        if(tam >= 1 && tam <= 100){
            correcto = true;
        }else{
            correcto = false;
            cout<<"Ingresa una cantidad valida\n";
        }
    }while(correcto != true);

    pedirDatos(personas,tam);
    mostrarDatos(personas,tam);
    buscarCliente(personas,tam);

    return 0;
}