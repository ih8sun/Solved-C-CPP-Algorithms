

#ifndef EXAMENNUEVO_RECTANGULO_H
#define EXAMENNUEVO_RECTANGULO_H

#include <iostream>
#include "Figura.h"

using namespace std;

class Rectangulo : public Figura{

public:
    double base,altura;

    Rectangulo(int numLados,double base,double altura) : Figura(numLados){
        this->base = base;
        this->altura = altura;
    }

    double CalcularArea(){

        return base*altura;

        return 1;
    }
    double CalcularPerimetro(){

        double final;
        final = 2*base + 2*altura;
        return final;
    }
};


#endif //EXAMENNUEVO_RECTANGULO_H
