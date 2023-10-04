
#ifndef EM_PELICULA_H
#define EM_PELICULA_H
using namespace std;

class Pelicula : public Video{

protected:
    string director;
public:
    Pelicula(string tpVideo,string nombreVideo,string gen,int calif,int anio,int dur,string direc): Video(tpVideo,nombreVideo,gen,calif,anio,dur){
        this->tipoVideo = tpVideo;
        this->nombreVideo = nombreVideo;
        this->genero = gen;
        this->calificacion = calif;
        this->anioLanzamiento = anio;
        this->duracion = dur;
        this->director = direc;
    }

    Pelicula(string tpVideo,string nombreVideo,string gen,int anio,int dur,string direc): Video(tpVideo,nombreVideo,gen,anio,dur){
        this->tipoVideo = tpVideo;
        this->nombreVideo = nombreVideo;
        this->genero = gen;
        this->calificacion = 0;
        this->anioLanzamiento = anio;
        this->duracion = dur;
        this->director = direc;
    }

    void muestraDatos(){
        cout<<"\n\n\t\t[ PELICULA ]\n\n";
        cout<<"Tipo de Video -> "<<tipoVideo<<endl;
        cout<<"Nombre de Pelicula -> "<<nombreVideo<<endl;
        cout<<"Genero de Pelicula -> "<<genero<<endl;
        cout<<"Calificacion -> "<<calificacion<<endl;
        cout<<"Anio de Lanzamiento -> "<<anioLanzamiento<<endl;
        cout<<"Duracion de la Pelicula [minutos] -> "<<duracion<<endl;
        cout<<"Director de la Pelicula -> "<<director<<endl<<endl;
    }
};
#endif //EM_PELICULA_H
