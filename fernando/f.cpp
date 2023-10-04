#include <iostream>
using namespace std;

class Barco{

    private:
        string nombre;
        double peso;
    public:
        Barco(string nombre, double peso){
            this->peso = peso;
            this->nombre = nombre;
        }
        
        ~Barco(){}
        void imprimir(){
            cout<<"\n\n\t\tIMPRIMIENDO BARCO\n";
            cout<<"\nNombre de Barco : "<<nombre<<endl;
            cout<<"Peso de Barco : "<<peso<<endl;

        }
};  

class Carguero : public Barco{
    private:
        double carga;
    public:
        Carguero(string nombre, double peso, double carga) : Barco(nombre,peso){
                this->carga = carga;
        }
        void imprimirCarguero(){
            imprimir();
            cout<<"Carga de Barco : "<<carga<<endl;
        }

};

class Acorazado : public Barco{
    private:
        int numArmas;
        int numSoldados;
    public:
        Acorazado(string nombre,double peso,int nA, int nS) : Barco(nombre,peso){
            numArmas = nA;
            numSoldados = nS;
        }
        void imprimirCarguero(){
            imprimir();
            cout<<"Numero de Armas : "<<numArmas<<endl;
            cout<<"Numero de Soldados : "<<numSoldados<<endl;
        }
};

int main(){

    Carguero* barquito = new Carguero("Elpepe",15,59);
    Acorazado* barquitoGuerrero = new Acorazado("ElBravo",32,1150,700);

    barquito->imprimirCarguero();
    barquitoGuerrero->imprimirCarguero();

    return 0;
}