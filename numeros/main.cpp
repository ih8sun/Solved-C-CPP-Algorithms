#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

class Numero{
public:
    int numero;
public:
    Numero(int numero){
        this->numero = numero;
    }
    virtual void Convertir() = 0;
};

class Binario : public Numero{

protected:
    int binario;
public:
    Binario(int numero) : Numero(numero){
        binario = 0;

    }
    void Convertir(){

        int exp = 0,digito;

        while(numero / 2 != 0){
            digito = numero%2;
            binario = binario + digito * pow(10.0,exp);
            exp++;
            numero = numero/2;

        }

        binario = binario + numero* pow(10.0,exp);
        cout << fixed << setprecision(0);
        cout << "binario: " << binario << endl;

    }

};


class Decimal : public Numero{

protected:
    int decimal;
public:
    Decimal(int numero) : Numero(numero){
        decimal = 0;
    }


    void Convertir(){

        int exp,digito;
        int binario = numero;

        exp=0;
        decimal=0;
        while(((int)(binario/10))!=0)
        {
            digito = (int)binario % 10;
            decimal = decimal + digito * pow(2.0,exp);
            exp++;
            binario=(int)(binario/10);
        }
        decimal=decimal + binario * pow(2.0,exp);
        cout << endl << "Decimal: " << decimal << endl;

    }





};

void operator +(const Binario &p1,const Binario &p2){

    int sum[20];
    int aux = 0;
    int i = 0;
    int aux1 = p1.numero;
    int aux2 = p2.numero;
    while(aux1 != 0 || aux2 != 0){
        sum[i++] = (aux1 % 10 + aux2 % 10  + aux) % 2;
        aux = (aux1 % 10 + aux2 % 10 + aux) / 2;
        aux1 = aux1/10;
        aux2 = aux2/10;
    }

    if(aux != 0){
        sum[i++] = aux;
    }
    --i;

    cout<<"La Suma de los dos binarios fue de : ";
    while(i >= 0)
        cout<<sum[i--];


}

void operator -(const Binario &p1,const Binario &p2){

    int sum[20];
    int aux = 0;
    int i = 0;
    int aux1 = p1.numero;
    int aux2 = p2.numero;
    while(aux1 != 0 || aux2 != 0){
        sum[i++] = (aux1 % 10 - aux2 % 10  - aux) % 2;
        aux = (aux1 % 10 - aux2 % 10 - aux) / 2;
        aux1 = aux1/10;
        aux2 = aux2/10;
    }

    if(aux != 0){
        sum[i++] = aux;
    }
    --i;

    cout<<"La Resta de los dos binarios fue de : ";
    while(i >= 0)
        cout<<sum[i--];


}

int main() {

    Numero *decAbinario;
    int n;
    cout<<"\n\n\t\t[ DECIMAL A BINARIO ] \n\n";
    cout<<"Ingresa Decimal : ";
    cin>>n;
    decAbinario = new Binario(n);

    cout<<"\nSobreCargando...\n";

    Numero *decAbinario2 = new Binario(n);




    decAbinario2->Convertir();

    cout<<"\n\n\t\t[ BINARIO A DECIMAL  ] \n\n";
    cout<<"Ingresa Binario : ";
    Numero *binAdecimal;
    cin>>n;
    binAdecimal = new Decimal(n);

    cout<<"Ingresa Binario 2: ";
    Numero *binAdecimal2;
    cin>>n;
    binAdecimal2 = new Decimal(n);




    return 0;
}
