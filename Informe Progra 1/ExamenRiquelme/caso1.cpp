#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Vehiculo{
    protected:
        string numSerie;
        string marca;
        int anio;
        float precio;
    public:
        Vehiculo(string numSerie,string marca,int anio,float precio){
            this->numSerie = numSerie;
            this->marca = marca;
            this->anio = anio;
            this->precio = precio;
        }

        void mostrarVehiculo(){
            cout<<"Numero de Serie : "<<numSerie<<endl;
            cout<<"Marca : "<<marca<<endl;
            cout<<"Anio de Salida : "<<anio<<endl;
            cout<<"Precio de venta : "<<precio<<endl;
        }

};

class Vagoneta : public Vehiculo{

    private:
        int numPasajeros;
    public:
        Vagoneta(string numSerie,string marca,int anio,float precio,int n) : Vehiculo(numSerie,marca,anio,precio){
            numPasajeros = n;
        }

        void mostrarVagoneta(){
            
            cout<<"\n\n\t\t[ VAGONETA ]\n\n";
            cout<<"Numero de Pasajeros : "<<numPasajeros<<endl;
            mostrarVehiculo();
        }

};

class Compacto : public Vehiculo{

    private:
        int numPasajeros;
    public:
        Compacto(string numSerie,string marca,int anio,float precio,int n) : Vehiculo(numSerie,marca,anio,precio){
            numPasajeros = n;
        }
        void mostrarCompacto(){
            
            cout<<"\n\n\t\t[ AUTO COMPACTO ]\n\n";
            cout<<"Numero de Pasajeros : "<<numPasajeros<<endl;
            mostrarVehiculo();
        }


};

class DeLujo : public Vehiculo{

    private:
        int numPasajeros;
        bool hibrido;
    public:
        DeLujo(string numSerie,string marca,int anio,float precio,int n,bool h) : Vehiculo(numSerie,marca,anio,precio){
            numPasajeros = n;
            hibrido = h;
        }

        void mostrarDelujo(){
            
            cout<<"\n\n\t\t[ AUTO DE LUJO ]\n\n";
            cout<<"Numero de Pasajeros : "<<numPasajeros<<endl;
            if(hibrido == false){
                
                cout<<"Es Hibrido? : No"<<endl;
            }else{
                
                cout<<"Es Hibrido? : Si"<<endl;
            }
            mostrarVehiculo();
        }

};

class Camioneta : public Vehiculo{

    private:
        float kgs;
        int Cantidad;
    public:
        Camioneta(string numSerie,string marca,int anio,float precio,float n,int h) : Vehiculo(numSerie,marca,anio,precio){
            kgs = n;
            Cantidad = h;
        }

        void mostrarCamioneta(){

            cout<<"\n\n\t\t[ CAMIONETA ]\n\n";
            cout<<"Soporte de Kilos : "<<kgs<<endl;
            cout<<"Cantidad de ejes : "<<Cantidad<<endl;
            mostrarVehiculo();

        }

};


int main(){

    Vagoneta *vagoneta = new Vagoneta("A1 Equinox","Nissan",1992,15000,5);

    vagoneta->mostrarVagoneta();

    Compacto *compacto = new Compacto("B1 Fmxias","Kia",2016,42000,7);

    compacto->mostrarCompacto();

    DeLujo *delujo = new DeLujo("Ferr12am","Ferrari",2020,100000,2,true);
    delujo->mostrarDelujo();

    Camioneta *camioneta = new Camioneta("Ferr12am","Ferrari",2020,12320,50,6);
    camioneta->mostrarCamioneta();
    return 0;
}