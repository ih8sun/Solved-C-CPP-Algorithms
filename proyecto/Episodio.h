//
// Created by alexito on 09/06/2021.
//

#ifndef PROYECTO_EPISODIO_H
#define PROYECTO_EPISODIO_H

#include "Video.h"
#include <iostream>
using namespace std;

class Episodio:public Video{
public:
    Episodio();
    Episodio(int,string,string,int,double,string,int,int);
    void setNumEpisodio(int numEpisodio){this->numEpisodio=numEpisodio;};
    int getNumEpisodio(){return numEpisodio;};
    void setTemporada(int temporada){this->temporada=temporada;};
    int getTemporada(){return temporada;};
    void setNombreSerie(string nombreSerie){this->nombreSerie=nombreSerie;};
    string getNombreSerie(){return nombreSerie;};
    void mostrar();
private:
    int numEpisodio;
    int temporada;
    string nombreSerie;

};

Episodio::Episodio():Video(){
    numEpisodio=0;
}
Episodio::Episodio(int id,string nombre,string gen,int min,double calif,string nombreSerie,int temporada,int numEpisodio):Video(id,nombre,gen,min,calif){
    this->nombreSerie=nombreSerie;
    this->temporada=temporada;
    this->numEpisodio=numEpisodio;
}

void Episodio::mostrar(){
    cout<<"Serie: "<<nombreSerie<<endl;
    cout<<"Temporada: "<<temporada<<endl;
    cout<<"Episodio "<<numEpisodio<<": "<<nombre<<endl;
    cout<<"Genero: "<<gen<<endl;
    cout<<"Duracion: "<<min<<endl;
    cout<<"Calificacion: "<<calif<<endl<<endl;
}

#endif //PROYECTO_EPISODIO_H
