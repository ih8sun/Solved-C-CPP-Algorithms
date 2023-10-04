//
// Created by alexito on 09/06/2021.
//

#ifndef PROYECTO_VIDEO_H
#define PROYECTO_VIDEO_H
#include <iostream>
using namespace std;

class Video{
protected:
    int id;
    string nombre;
    string gen;
    int min;
    double calif;
public:
    Video();
    Video(int,string,string,int,double);
    void setId(int id){this->id=id;};
    int getId(){return id;};
    void setNombre(string nombre){this->nombre=nombre;};
    string getNombre(){return nombre;};
    void setGenero(string gen){this->gen=gen;};
    string getGenero(){return gen;};
    void setDuracion(int min){this->min=min;};
    int getDuracion(){return min;};
    void setCalif(double calif){this->calif=calif;};
    double getCalif(){return calif;};
    virtual void mostrar()=0;

};

Video::Video(){
    id=0;
    nombre="NA";
    gen="NA";
    min=0;
    calif=0;
}

Video::Video(int id,string nombre,string gen,int min, double calif){
    this->id=id;
    this->nombre=nombre;
    this->gen=gen;
    this->min=min;
    this->calif=calif;
}

#endif //PROYECTO_VIDEO_H
