

#ifndef EXAMENNUEVO_TRAPECIO_H
#define EXAMENNUEVO_TRAPECIO_H
#include <iostream>
#include "Figura.h"

using namespace std;

class Trapecio : public Figura{

public:
    double base,altura;

    Trapecio(int numLados,double b,double h) : Figura(numLados){
        base = b;
        altura =h;
    }
    double CalcularArea(){

        double final;
        final = (base+altura)/2;
        return final;
    }
    double CalcularPerimetro(){

        double final = base+base / 2;
        final *= altura;

        return final;
    }
};

#endif //EXAMENNUEVO_TRAPECIO_H
