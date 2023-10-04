#include <fstream>
#include <iostream>
#include "Episodio.h"
#include "Pelicula.h"
using namespace std;


int main(){

    string nombre,gen,director,nombreSerie;
    int id,duracion,temporada,numEpisodio,opcion;
    int cont=0;

    double calif,califMin,califMax;
    fstream datos;
    char tipoVideo;
    char arrTipos[30];
    Video *arrVideos[30];
    datos.open("datos.txt");


    while(datos>>tipoVideo){
        if(tipoVideo=='p'){
            datos>>id>>nombre>>gen>>duracion>>calif>>director;
            arrVideos[cont]=new Pelicula(id,nombre,gen,duracion,calif,director);
            arrTipos[cont]=tipoVideo;
            cont++;
        }
        else{
            datos>>id>>nombre>>gen>>duracion>>calif>>nombreSerie>>temporada>>numEpisodio;
            arrVideos[cont]=new Episodio(id,nombre,gen,duracion,calif,nombreSerie,temporada,numEpisodio);
            arrTipos[cont]=tipoVideo;
            cont++;
        }
    }

    do{
        cout<<"Menu"<<endl;
        cout<<"1.Mostrar la lista de peliculas"<<endl;
        cout<<"2.Mostrar la lista de series"<<endl;
        cout<<"3.Mostrar los videos en general con una cierta calificacion"<<endl;
        cout<<"4.Mostrar los videos en general de un cierto genero"<<endl;
        cout<<"5.Mostrar los episodios de una determinada serie con sus calificaciones"<<endl;
        cout<<"6.Mostrar las peliculas con cierta calificacion"<<endl;
        cout<<"0.Salir"<<endl;
        cout<<"Seleccione una opcion: ";

        cin>>opcion;
        cout<<endl;

        switch (opcion)
        {
            case 1:
                for(int i=0;i<cont;i++){
                    if(arrTipos[i]=='p'){
                        arrVideos[i]->mostrar();
                    }
                }
                break;

            case 2:
                for(int i=0;i<cont;i++){
                    if(arrTipos[i]=='s'){
                        arrVideos[i]->mostrar();
                    }
                }
                break;

            case 3:
                cout<<"maximo de calificacion: ";
                cin>>califMin;
                cout<<endl<<"Maximo de calificacion: ";
                cin>>califMax;
                cout<<endl;
                for(int i=0;i<cont;i++){
                    if(arrVideos[i]->getCalif()>=califMin && arrVideos[i]->getCalif()<=califMax){
                        arrVideos[i]->mostrar();
                    }
                }
                break;

            case 4:
                cout<<"Genero deseado: ";
                cin>>gen;
                cout<<endl;
                for(int i=0;i<cont;i++){
                    if(arrVideos[i]->getGenero()==gen){
                        arrVideos[i]->mostrar();
                    }
                }
                break;

            case 5:
                cout<<"Nombre de la serie: ";
                cin>>nombreSerie;
                cout<<endl;
                for(int i=0;i<cont;i++){
                    if(arrTipos[i]=='s'){
                        Episodio *epTemporal;
                        epTemporal = (Episodio *) arrVideos[i];
                        if(epTemporal->getNombreSerie()==nombreSerie){
                            epTemporal->mostrar();
                        }
                    }
                }
                break;

            case 6:
                cout<<"Calificacion minima: ";
                cin>>califMin;
                cout<<endl<<"Calificacion maxima: ";
                cin>>califMax;
                cout<<endl;

                for(int i=0;i<cont;i++){
                    if(arrVideos[i]->getCalif()>=califMax && arrVideos[i]->getCalif()<=califMax && arrTipos[i]=='p'){
                        arrVideos[i]->mostrar();
                    }
                }
                break;
        }
    }while(opcion!=0);
}