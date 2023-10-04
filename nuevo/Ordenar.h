//
// Created by alexito on 09/06/2021.
//

#ifndef NUEVO_ORDENAR_H
#define NUEVO_ORDENAR_H

#include <iostream>
#include "Intercambio.h"

using namespace std;
template <class nuevoOrden>

void ordenarAscendente(nuevoOrden *arreglo,int n){

    int i,j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(arreglo[j] > arreglo[j+1]){
                intercambiar(arreglo[j],arreglo[j+1]);
            }
        }
    }

}
template <class nuevoOrdenA>
void ordenarDescendente(nuevoOrdenA *arreglo,int n){

    int i,j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n-1; j++){
            if(arreglo[j] < arreglo[j+1]){
                intercambiar(arreglo[j],arreglo[j+1]);
            }
        }
    }

}
#endif //NUEVO_ORDENAR_H
