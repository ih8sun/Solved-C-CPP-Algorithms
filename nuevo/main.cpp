#include <iostream>
#include "Ordenar.h"

template <typename T>
void pedirDatos(T *array,int n){
    for(int i = 0; i < n; i++){
        cout<<"Ingresa un numero : ";
        cin>>array[i];
    }
}

template <typename T1>
void mostrarDatos(T1 *array,int n){
    cout<<"\n\n\t\tMOSTRANDO DATOS\n\n";
    for(int i = 0; i < n; i++){
        cout<<"Elemento ["<<i<<"] : "<<array[i]<<endl;
    }
}
int main() {
    int nElementos;

    cout<<"Digite N : ";
    cin>>nElementos;

    int *array = new int[nElementos];

    pedirDatos(array,nElementos);
    ordenarAscendente(array,nElementos);
    mostrarDatos(array,nElementos);





    delete[] array;


    return 0;
}
