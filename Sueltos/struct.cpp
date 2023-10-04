#include <iostream>
#include <cstdlib>
#include <complex>
using namespace std;

struct Complejo{

    float real,imaginaria;

}z1,z2;

void pedirDatos();
Complejo suma(Complejo,Complejo);

void muestra(Complejo x){

    cout<<"Parte Real  : "<<x.real<<endl;
    cout<<"Parte Imaginaria : "<<x.imaginaria<<endl;


}
int main(){

    pedirDatos();
    Complejo x = suma(z1,z2);
    muestra(x);
    
    return 0;
}

void pedirDatos(){

    cout<<"Digite los datos para el primer numero complejo"<<endl;
    cout<<"Parte Real : ";cin>>z1.real;
    cout<<"Parte Imaginaria : ";cin>>z1.imaginaria;
    

    cout<<"Digite los datos para el primer numero complejo"<<endl;
    cout<<"Parte Real : ";cin>>z2.real;
    cout<<"Parte Imaginaria : ";cin>>z2.imaginaria;
}

Complejo suma(Complejo z1,Complejo z2){

    z1.real += z2.real;
    z1.imaginaria +=z1.imaginaria;

    return z1;
}