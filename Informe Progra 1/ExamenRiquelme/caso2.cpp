#include <iostream>
#include <stdlib.h>
#include <string>
#define valorFijo 200
using namespace std;

class Barco {

protected:
    int largo;
    int dias;
    string nombre;
public:
    Barco(int largo, int dias, string nombre) {
        this->largo = largo;
        this->dias = dias;
        this->nombre = nombre;
    }

    void pideNombre() {
        cout << "Ingresa Nombre de Barco : ";
        fflush(stdin);
        getline(cin, nombre);
    }

    void pideDias() {
        cout << "Ingresa dias : ";
        cin >> dias;
    }

    float Alquiler(){
        float x;

        x = dias * ((10*largo)*valorFijo);

        return x;
    }

};

class Velero : Barco {

private:
    int mastiles;
public:

    Velero(int largo, int dias, string nombre, int mastiles) : Barco(largo, dias, nombre) {
        this->mastiles = mastiles;
    }


    void pideMastiles() {
        cout << "Ingresa mastiles : ";
        cin >> mastiles;
    }
};

class Deportivo : Barco {


private:
    int potencia;
public:

    Deportivo(int largo, int dias, string nombre, int potencia) : Barco(largo, dias, nombre) {
        this->potencia = potencia;
    }



    void pidePotencia() {
        cout << "Ingresa Potencia : ";
        cin >> potencia;
    }

};

class Yate : Barco {

private:
    int potencia;
    int camarotes;
public:
    Yate(int largo, int dias, string nombre, int potencia, int camarotes) : Barco(largo, dias, nombre) {
        this->potencia = potencia;
        this->camarotes = camarotes;
    }



    void pidePotencia() {
        cout << "Ingresa Potencia : ";
        cin >> potencia;
    }

    void pideCamarotes() {
        cout << "Ingresa Camarotes : ";
        cin >> camarotes;
    }

    float alquilerYate(){
        return Alquiler();
    }

    void pideDiasYate(){
        pideDias();
    }

};

void menu() {

    system("cls");
    cout << "\n\n\t\t [ PUERTO LOS CABOS ]\n\n" << endl;
    cout << "[1]. Hacer presupuesto para Velero\n";
    cout << "[2]. Hacer presupuesto para Deportivo\n";
    cout << "[3]. Hacer presupuesto para Yate\n";
    cout << "[4]. Salir\n\n[?]. Ingresa una opcion : ";
}

int main() {

    int opc;

    Velero *velero = new Velero(0,0," ",0);
    Deportivo *deportivo = new Deportivo(0,0," ",0);
    Yate *yate = new Yate(0,0," ",0,0);

    float alquiler;

    do {
        menu();
        cin >> opc;
        switch (opc) {
            case 1:
                
                
                break;
            case 2:
                break;
            case 3:
                yate->pideDiasYate();

                alquiler = yate->alquilerYate();
                break;
        }

    } while (opc != 4);
}