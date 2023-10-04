//
// Created by alexito on 15/06/2021.
//

#ifndef NUEVOCINE_EPISODIO_H
#define NUEVOCINE_EPISODIO_H

#include <iostream>
#include <string.h>
#include "video.h"

using namespace std;




class Episodio:public Video{
private:
    string nombreSerie;
    int numEpisodio;
    int temporada;

    ofstream binarioSerie;
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
        cout<<"Estrellas : "<<estrellas<<endl;
        //cout<<"Resena : ";coment.mostrarComentario();
        cout<<endl;
    }

    void guardarBinarioS(){
        
        binarioSerie.open("SoloSeries.bin",ios::app | ios::binary);

        char aux[50];
        char aux2[50];

        strcpy(aux,nombreSerie.c_str());
        strcpy(aux2,nombre.c_str());

        if (binarioSerie.is_open()){
            
            for(int i = 0; i < strlen(aux); i++){
                binarioSerie.put(aux[i]);
            }
            binarioSerie<<" - ";

            
            for(int i = 0; i < strlen(aux2);i++){
                binarioSerie.put(aux2[i]);
            }

            binarioSerie<<"\n";
        }else {
            cout << "Error de apertura de archivo." << endl;
        }

        binarioSerie.close();
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


#endif //NUEVOCINE_EPISODIO_H
