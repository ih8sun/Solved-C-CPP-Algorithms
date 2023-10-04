//
// Created by alexito on 15/06/2021.
//

#ifndef NUEVOCINE_VIDEO_H
#define NUEVOCINE_VIDEO_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Resena{

    public:
    string comentario;
    string alea[10];
    public:
        Resena(){

        }
        void inicializar(){
            int x;

            alea[0] = "Un gran contenido para toda la familia";
            alea[1] = "Gran perfomance de la actriz";
            alea[2] = "No esta muy recomendable";
            alea[3] = "Valio totalmente la pena";
            alea[4] = "La banda sonora estuvo de lujo";
            alea[5] = "No hay comparacion con esta pelicula";
            alea[6] = "Pudo estar mejor, no lo negare";
            alea[7] = "Los Efectos estuvieron geniales!";
            alea[8] = "La trama estuvo super interesante";
            alea[9] = "Hubiera preferido menos efectos de sonido";


            x = 1 + rand()%(11-1);
            comentario = alea[x];
        }
        string getComentario(){

            return comentario;
        }

        void setComentario(string x){
            comentario = x;
        }
};

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
    Resena coment;
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

#endif //NUEVOCINE_VIDEO_H
