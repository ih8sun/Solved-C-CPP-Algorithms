//
// Created by alexito on 09/06/2021.
//

#ifndef PROYECTO_PELICULA_H
#define PROYECTO_PELICULA_H

#include "Video.h"
#include <iostream>
using namespace std;

class Pelicula:public Video{

private:
    string director;

public:
    Pelicula();
    Pelicula(int,string,string,int,double,string);
    void setDirector(string director){this->director=director;};
    string getDirector(){return director;};
    void mostrar();
};

Pelicula::Pelicula():Video(){
    director="NA";
}

Pelicula::Pelicula(int id,string nombre,string gen,int min,double calif,string director):Video(id,nombre,gen,min,calif){
    this->director=director;
}

void Pelicula::mostrar(){
    cout<<"Pelicula: "<<nombre<<endl;
    cout<<"Genero: "<<gen<<endl;
    cout<<"Duracion: "<<min<<endl;
    cout<<"Calificacion: "<<calif<<endl;
    cout<<"Director: "<<director<<endl<<endl;
}

#endif //PROYECTO_PELICULA_H
