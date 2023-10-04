
#ifndef EXAMENNUEVO_FIGURA_H
#define EXAMENNUEVO_FIGURA_H
#include <iostream>
using namespace std;

class Figura{

protected:
    int numLados;
    double *lados;
public:
    Figura(int numLados){
        this->numLados = numLados;
        lados = new double [ numLados];

    }

    virtual double CalcularPerimetro() = 0;
    virtual double CalcularArea() = 0;

};


#endif //EXAMENNUEVO_FIGURA_H
