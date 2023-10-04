
#ifndef EXAMENNUEVO_CUADRADO_H
#define EXAMENNUEVO_CUADRADO_H
#include <iostream>
#include "Figura.h"
using namespace std;
class Cuadrado : public Figura{

public:
    double ladoSuma;

    Cuadrado(int numLados,double ladoSuma) : Figura(numLados){
        this->ladoSuma = ladoSuma;
    }
    double CalcularArea(){

        return ladoSuma*ladoSuma;
    }

    double CalcularPerimetro(){
        return ladoSuma+ladoSuma+ladoSuma+ladoSuma;
    }

};


#endif //EXAMENNUEVO_CUADRADO_H
