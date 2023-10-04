

#ifndef EXTRAORDINARIO_PRIMO_H
#define EXTRAORDINARIO_PRIMO_H
#include "Operaciones.h"
#include <iostream>
#include <math.h>

class Primo : public Operaciones{

public:
    Primo(int num1) : Operaciones(num1){

    }
    ~Primo(){}

    void calculo(){

        bool band = true;

        for(int i =2 ;i < sqrt(num1) && band; i++){
            if(num1 % i == 0) band = false;
        }

        cout<<(band ? "Es un Numero primo" : "No es numero primo")<<endl;

    }
};

#endif //EXTRAORDINARIO_PRIMO_H
