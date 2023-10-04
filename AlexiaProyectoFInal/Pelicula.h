//
// Created by alexito on 15/06/2021.
//

#ifndef NUEVOCINE_PELICULA_H
#define NUEVOCINE_PELICULA_H
#include <string.h>
#include "video.h"
#include <iostream>
#include <fstream>

class Pelicula:public Video{

private:
    string director;
    ofstream binarioPelicula;

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
        
        coment.inicializar();
        cout<<"Pelicula : "<<nombre<<endl;
        cout<<"Genero : "<<gen<<endl;
        cout<<"Formato : "<<formato<<endl;
        cout<<"Duracion : "<<min<<endl;
        cout<<"Director : "<<director<<endl;
        cout<<"Calificacion : "<<calif<<endl;
        cout<<"Estrellas : "<<estrellas<<endl;
        cout<<"Resena : "<<coment.comentario<<endl;


        cout<<endl;
    }

    void guardarBinario(){
        
        binarioPelicula.open("SoloPeliculas.bin",ios::app | ios::binary);

        char aux[40];
        char aux2[40];

        strcpy(aux,nombre.c_str());

        if (binarioPelicula.is_open()){
            
            for(int i = 0; i < strlen(aux); i++){
                binarioPelicula.put(aux[i]);
            }
            binarioPelicula<<"\n";


        }else {
            cout << "Error de apertura de archivo." << endl;
        }

        binarioPelicula.close();
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


#endif //NUEVOCINE_PELICULA_H
