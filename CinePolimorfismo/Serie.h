

#ifndef EM_SERIE_H
#define EM_SERIE_H
#include <iostream>
#include "Video.h"
using namespace std;

class Serie : public Video{

protected:
    int temporada;
    int capitulo;
public:

    Serie(string tpVideo,string nombreVideo,string gen,int calif,int anio,int dur,int cap,int temp) :Video (tpVideo, nombreVideo, gen, calif, anio, dur){
        this->tipoVideo = tpVideo;
        this->nombreVideo = nombreVideo;
        this->genero = gen;
        this->calificacion = calif;
        this->anioLanzamiento = anio;
        this->duracion = dur;
        this->capitulo = cap;
        this->duracion = dur;
        this->temporada = temp;
    }

    Serie(string tpVideo,string nombreVideo,string gen,int anio,int dur,int cap,int temp) : Video (tpVideo, nombreVideo, gen , anio, dur){
        this->tipoVideo = tpVideo;
        this->nombreVideo = nombreVideo;
        this->genero = gen;
        this->calificacion = 0;
        this->anioLanzamiento = anio;
        this->duracion = dur;
        this->capitulo = cap;
        this->duracion = dur;
        this->temporada = temp;
    }

    void muestraDatos(){
        cout<<"\n\n\t\t[ SERIE ]\n\n";
        cout<<"Tipo de Video -> "<<tipoVideo<<endl;
        cout<<"Nombre de Capitulo -> "<<nombreVideo<<endl;
        cout<<"Genero de Video -> "<<genero<<endl;
        cout<<"Calificacion -> "<<calificacion<<endl;
        cout<<"Anio de Lanzamiento -> "<<anioLanzamiento<<endl;
        cout<<"Duracion del Capitulo [minutos] -> "<<duracion<<endl;
        cout<<"Numero de Capitulo -> "<<capitulo<<endl;
        cout<<"Numero de Temporada -> "<<temporada<<endl<<endl;
    }
};
#endif //EM_SERIE_H
