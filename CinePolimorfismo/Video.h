
#ifndef EM_VIDEO_H
#define EM_VIDEO_H
#include <iostream>
using namespace std;

class Video{

protected:
    string tipoVideo;
    string nombreVideo;
    string genero;
    int calificacion;
    int anioLanzamiento;
    int duracion;
public:

    Video(string tpVideo,string nombreVideo,string gen,int calif,int anio,int dur){
        this->tipoVideo = tpVideo;
        this->nombreVideo = nombreVideo;
        this->genero = gen;
        this->calificacion = calif;
        this->anioLanzamiento = anio;
        this->duracion = dur;
    }

    Video(string tpVideo,string nombreVideo,string gen,int anio,int dur){
        this->tipoVideo = tpVideo;
        this->nombreVideo = nombreVideo;
        this->genero = gen;
        this->calificacion = 0;
        this->anioLanzamiento = anio;
        this->duracion = dur;
    }

    Video(){}

    string getNombreVideo();
    void calificarVideo(int);

    virtual void muestraDatos() = 0;
};

string Video::getNombreVideo(){
    return nombreVideo;
}

void Video::calificarVideo(int calif){
    calificacion = calif;
}
#endif //EM_VIDEO_H
