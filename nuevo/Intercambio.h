//
// Created by alexito on 09/06/2021.
//

#ifndef NUEVO_INTERCAMBIO_H
#define NUEVO_INTERCAMBIO_H

#include <iostream>
using namespace std;

template <typename T>

void intercambiar(T &dato1, T &dato2){

    T aux;

    aux = dato2;
    dato2 = dato1;
    dato1 = aux;

}
#endif //NUEVO_INTERCAMBIO_H
