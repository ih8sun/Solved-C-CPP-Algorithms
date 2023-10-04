//
// Created by alexito on 21/06/2021.
//

#ifndef EXAMENNUEVO_TRIANGULO_H
#define EXAMENNUEVO_TRIANGULO_H
#include <iostream>
#include "Figura.h"

using namespace std;

class Triangulo : public Figura{
public:
    double base,altura;
    Triangulo(int numLados,double b,double h) : Figura(numLados){
        base = b;
        altura = h;
    }
    double CalcularArea(){

        double final;
        final = (base*altura)/2;
        return final;
    }
    double CalcularPerimetro(){
        return numLados+numLados+numLados;
    }
};

#endif //EXAMENNUEVO_TRIANGULO_H
