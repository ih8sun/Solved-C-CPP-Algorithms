//
// Created by alexito on 10/06/2021.
//

#ifndef CINE_EPISODIO_H
#define CINE_EPISODIO_H

#include <iostream>
#include "video.h"
using namespace std;


class Episodio:public Video{
private:
    string nombreSerie;
    int numEpisodio;
    int temporada;
public:
    Episodio();
    Episodio(char,int,string,string,string,string,double,int  ,string,int,int);

    void setNumEpisodio(int numEpisodio){this->numEpisodio=numEpisodio;}
    int getNumEpisodio(){return numEpisodio;}
    void setTemporada(int temporada){this->temporada=temporada;}
    int getTemporada(){return temporada;}
    void setNombreSerie(string nombreSerie){this->nombreSerie=nombreSerie;}
    string getNombreSerie(){return nombreSerie;}

    void mostrar(){
        cout<<"Serie : "<<nombreSerie<<endl;
        cout<<"Temporada : "<<temporada<<endl;
        cout<<"Episodio : "<<numEpisodio<<": "<<nombre<<endl;
        cout<<"Genero : "<<gen<<endl;
        cout<<"Formato : "<<formato<<endl;
        cout<<"Duracion : "<<min<<endl;
        cout<<"Calificacion : "<<calif<<endl;
        cout<<"Estrellas : "<<estrellas<<endl<<endl;
    }


};

Episodio::Episodio() : Video(){
    numEpisodio=0;
}

Episodio::Episodio(char tipo,int id,string nombre,string gen,
                   string formato,string min,double estrellas,int calif,string nombreSerie,
                   int numEpisodio,
                   int temporada) : Video(tipo,id,nombre,
                                          gen,formato,min,estrellas,calif){

    this->nombreSerie=nombreSerie;
    this->temporada=temporada;
    this->numEpisodio=numEpisodio;
}


#endif //CINE_EPISODIO_H
