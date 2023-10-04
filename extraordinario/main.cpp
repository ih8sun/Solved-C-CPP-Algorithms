#include <iostream>
#include "Factorial.h"
#include "Operaciones.h"
#include "Primo.h"
using namespace std;

int main() {

    cout<<"\n\n\t\t [ INGRESO DE ALGUN NUMERO ]\n\n";
    int x;
    cout<<"Ingrese algun numero : ";
    cin>>x;

    Factorial *ob1 = new Factorial(x);


    ob1->leernum(x);
    ob1->imprimir();
    ob1->calculo();







    return 0;
}
