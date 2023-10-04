#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


class Transporte{

    protected:
        string marca;
        int numPasajero;
    public:
        Transporte(string marca,int numPasajero){
            this->marca = marca;
            this->numPasajero = numPasajero;
        }


        virtual void modelo()=0;

};

class transporte : public Transporte{

    public:
        transporte(string marca,int numPasajero) : Transporte(marca,numPasajero){}

        void modelo(){
            
            cout<<"\n\n\t\t[ Mostrando Transporte ]\n\n";
            cout<<"Marca de Transporte -> "<<marca<<endl;
            cout<<"Transporta hasta -> "<<numPasajero<<" pasajeros"<<endl;
        }
    
};

class Moto : public Transporte{

    protected:
        float precio;
    public:
        Moto(string marca,int numPasajero,float precio) : Transporte(marca,numPasajero){
            this->precio = precio;
        }

        void modelo(){
            
            cout<<"\n\n\t\t[ Mostrando Vehiculo Motorizado ]\n\n";
            cout<<"Marca de moto -> "<<marca<<endl;
            cout<<"Transporta hasta -> "<<numPasajero<<" pasajeros"<<endl;
            cout<<"Precio de la moto es -> "<<precio<<endl;
        }

};

class Camion : public Transporte{

    protected:
        float tonelada;
    public:
        Camion(string marca,int numPasajero,float tonelada) : Transporte(marca,numPasajero){
            this->tonelada = tonelada;
        }

        void modelo(){
            
            cout<<"\n\n\t\t[ Mostrando Camion ]\n\n";
            cout<<"Marca de Camion -> "<<marca<<endl;
            cout<<"Transporta hasta -> "<<numPasajero<<" pasajeros"<<endl;
            cout<<"El Camion puede transportar hasta -> "<<tonelada<<" toneladas"<<endl;
        }

};

int main(){

    Transporte *vehiculo[3];


    vehiculo[0] = new Moto("Honda",2,35000);
    vehiculo[1] = new Camion("Isuzu",3,1);
    vehiculo[2] = new transporte("BMW",4);


    for(int i = 0; i < 3; i++){
        vehiculo[i]->modelo();
    }


    return 0;
}