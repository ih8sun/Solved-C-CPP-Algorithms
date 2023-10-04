//
// Created by alexito on 10/06/2021.
//

#ifndef CINE_VIDEO_H
#define CINE_VIDEO_H
#include <iostream>
using namespace std;

class Video{

protected:
    char tipo;
    int id;
    string nombre;
    string gen;
    string formato;
    string min;
    double estrellas;
    int calif;
public:
    Video();
    Video(char ,int,string,string,string,string,double,int );

    void setId(int id){
        this->id=id;
    };
    void setTipo(char c){
        this->tipo = c;
    }

    char getTipo(){
        return tipo;
    }

    int getId(){
        return id;
    }

    string getFormato(){
        return formato;
    }

    double getEstrellas(){
        return estrellas;
    }

    void setEstrellas(double x){
        this->estrellas = x;
    }

    void setFormato(string t){
        formato = t;
    }

    void setNombre(string nombre){
        this->nombre=nombre;
    }

    string getNombre(){
        return nombre;
    }

    void setGenero(string gen){
        this->gen=gen;
    }
    string getGenero(){
        return gen;
    }

    void setDuracion(string min){
        this->min=min;
    }

    string getDuracion(){
        return min;
    }

    void setCalif(int calif){
        this->calif=calif;
    }
    int getCalif(){
        return calif;
    }

    virtual void mostrar()=0;



};

Video::Video(){
    id=0;
    nombre="NA";
    gen="NA";
    min="0";
    estrellas = 0;
    calif=0;
}

Video::Video(char tipo,int id,string nombre,string gen,
             string formato,string min,double estrellas, int calif){
    this->tipo = tipo;
    this->id=id;
    this->nombre=nombre;
    this->gen=gen;
    this->min=min;
    this->calif=calif;
    this->formato = formato;
    this->estrellas =estrellas;
}

#endif //CINE_VIDEO_H
