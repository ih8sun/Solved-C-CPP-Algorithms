//
// Created by alexito on 22/06/2021.
//

#ifndef EXTRAORDINARIO_FACTORIAL_H
#define EXTRAORDINARIO_FACTORIAL_H
#include <iostream>
#include "Operaciones.h"
using namespace std;

class Factorial : public Operaciones{

public:
    Factorial(int num1) : Operaciones(num1){

    }
    ~Factorial(){}

    void calculo(){

        int fact = 1;

        for(int i =1 ; i <= num1; i++){
            fact = fact*i;
        }
        cout<<"Factorial de "<<num1<<" es -> "<<fact<<endl;
    }

};

#endif //EXTRAORDINARIO_FACTORIAL_H
