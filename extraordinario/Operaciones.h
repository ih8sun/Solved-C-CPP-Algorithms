
#ifndef EXTRAORDINARIO_OPERACIONES_H
#define EXTRAORDINARIO_OPERACIONES_H
#include <iostream>

class Operaciones{

protected:
    int num1;
public:
    Operaciones(int num1){
        this->num1 = num1;
    }
    ~Operaciones(){}

    void leernum(int x){
        num1 = x;
    }
    void imprimir(){
        std::cout<<"El Numero es "<<num1<<std::endl;
    }

};



#endif //EXTRAORDINARIO_OPERACIONES_H
