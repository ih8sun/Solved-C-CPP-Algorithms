#include <iostream>
#include "Figura.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "Trapecio.h"

using namespace std;

int main() {

    Figura *obj1;
    double num,base,h;



    cout<<"\n\n\t\t[ CUADRADO ]\n\n";
    cout<<"Ingrese el valor del los lados del cuadrado : ";
    cin>>num;
    obj1 = new Cuadrado(1,num);

    cout<<"El area del cuadrado es : "<<obj1->CalcularArea()<<endl;
    cout<<"\nEl perimetro del cuadrado es : "<<obj1->CalcularPerimetro()<<endl;

    cout<<"\n\n\t\t[ RECTANGULO ]\n\n";
    Figura *obj2;
    cout<<"\nIngrese La Base del rectangulo : ";
    cin>>base;
    cout<<"Ingrese La Altura del rectangulo : ";
    cin>>h;
    obj2 = new Rectangulo(1,base,h);
    cout<<"\nEl area del rectangulo es : "<<obj2->CalcularArea()<<endl;
    cout<<"\nEl perimetro del rectangulo es : "<<obj2->CalcularPerimetro()<<endl;

    cout<<"\n\n\t\t[ TRIANGULO ]\n\n";
    Figura *obj3;
    obj2 = new Rectangulo(1,base,h);

    cout<<"\nIngrese La Base del triangulo : ";
    cin>>base;
    cout<<"Ingrese La Altura del triangulo : ";
    cin>>h;
    obj2 = new Triangulo(3,base,h);
    cout<<"\nEl area del triangulo es : "<<obj3->CalcularArea()<<endl;
    cout<<"\nEl perimetro del triangulo es : "<<obj3->CalcularPerimetro()<<endl;

    cout<<"\n\n\t\t[ TRAPECIO ]\n\n";
    Figura *obj4;

    cout<<"\nIngrese La Base del trapecio : ";
    cin>>base;
    cout<<"Ingrese La Altura del trapecio : ";
    cin>>h;
    obj2 = new Triangulo(1,base,h);
    cout<<"\nEl area del trapecio es : "<<obj4->CalcularArea()<<endl;
    cout<<"\nEl perimetro del trapecio es : "<<obj4->CalcularPerimetro()<<endl;



    return 0;
}
