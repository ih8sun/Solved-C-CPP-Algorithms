//
// Created by alexito on 10/06/2021.
//

#ifndef CINE_PELICULA_H
#define CINE_PELICULA_H

#include "video.h"

class Pelicula:public Video{

private:
    string director;

public:
    Pelicula();
    Pelicula(char,int,string,string,string,string,double,int,  string);

    void setDirector(string d){
        this->director=d;
    }

    string getDirector(){
        return director;
    }
    void mostrar(){
        cout<<"Pelicula : "<<nombre<<endl;
        cout<<"Genero : "<<gen<<endl;
        cout<<"Formato : "<<formato<<endl;
        cout<<"Duracion : "<<min<<endl;
        cout<<"Director : "<<director<<endl;
        cout<<"Calificacion : "<<calif<<endl;
        cout<<"Estrellas : "<<estrellas<<endl;
    }

};

Pelicula::Pelicula():Video(){
    director="NA";
}

Pelicula::Pelicula(char tipo,int id,string nombre,
                   string gen,string formato,string min, double estrellas, int calif,
                   string director):Video(tipo,id,nombre,
                                          gen,formato,min,estrellas,calif){
    this->director=director;
}

#endif //CINE_PELICULA_H
