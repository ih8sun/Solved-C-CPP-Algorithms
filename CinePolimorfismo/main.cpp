#include <iostream>
#include <cstdlib>
#include "Serie.h"
#include "Pelicula.h"
using namespace std;

void entrada(){
    system("cls");
    cout<<"\n\n\t\n=====> CINEMEX <======\n\n";
    cout<<"[1]. Consultar Video\n";
    cout<<"[2]. Mostrar todos los Videos\n";
    cout<<"[3]. Calificar Video\n";
    cout<<"[4]. Salir\n\n";
    cout<<"[-]. Ingresa : ";
}

void consultarPelicula(Video *nuevoVideos[]){

    cout<<"\n\n\t\t[ CONSULTAR PELICULA ]\n\n";
    string x;

    cout<<"Ingresa nombre de Pelicula/Serie a buscar : ";
    fflush(stdin);
    getline(cin,x);
    bool entro = false;
    for(int i = 0; i < 5; i++){
        if(nuevoVideos[i]->getNombreVideo().compare(x)==0){
            nuevoVideos[i]->muestraDatos();
            entro = true;
        }
    }

    if(!entro)
        cout<<"\n\n\t\t [ No se encontraron los datos de esa pelicula :( ]\n\n";
    system("pause");
}
void calificarVideo(Video *nuevosVideos[]){
    string x;
    int cal;
    cout<<"\n\n\t\t[ Calificar algun Video ]\n\n";
    cout<<"Ingresa nombre de Pelicula/Serie : ";
    fflush(stdin);
    getline(cin,x);

    for(int i = 0; i < 5; i++){
        if(nuevosVideos[i]->getNombreVideo().compare(x)==0){

            nuevosVideos[i]->muestraDatos();
            cout<<"\nIngresa Nueva Calificacion : ";
            cin>>cal;

            cout<<"\n\nDatos Actualizados...";
            nuevosVideos[i]->calificarVideo(cal);
            nuevosVideos[i]->muestraDatos();
        }
    }

    cout<<endl;
    system("pause");
}
void mostrarVideos(Video *nuevosVideos[]){

    for(int i = 0; i < 5; i++){
        nuevosVideos[i]->muestraDatos();
    }
}
int main() {

    Video *tipoObj1[5];

    tipoObj1[0] = new Pelicula("Pelicula", "Nacho Libre", "Mexicana", 2012, 240, "Hector Hugarte");
    tipoObj1[1] = new Pelicula("Pelicula", "Sin Limites", "Accion", 5, 2021, 320, "Ken Astrick");
    tipoObj1[2] = new Serie("Serie", "La Casa de Papel", "Accion", 5, 2019, 80, 6, 3);
    tipoObj1[3] = new Serie("Serie", "Elite", "Juvenil", 2017, 50, 12, 1);
    tipoObj1[4] = new Serie("Serie", "Pucca", "Amor", 2001, 15, 1, 4);


    int opc;
    do{
        entrada();
        cin>>opc;
        switch (opc) {
            case 1:
                consultarPelicula(tipoObj1);
                break;
            case 2:
                mostrarVideos(tipoObj1);
                system("pause");
                break;
            case 3:
                calificarVideo(tipoObj1);
                break;
            case 4:
                break;
        }

    }while(opc != 4);

    system("pause");
    return 0;
}
