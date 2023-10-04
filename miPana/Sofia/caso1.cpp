#include <iostream>
#include <stdlib.h>
#include "Clases.h"
#include <string.h>
#define max 5
using namespace std;


int main(){

    Protesis *nuevaMaquina;
    nuevaMaquina = new Protesis[max];
    int i,opc;

    Sensor *nuevoSensor;
    nuevoSensor = new Sensor();

    FILE *miArchivo = fopen("Archivo.txt","w");

    string auxS;
    int auxI;
    double auxD;
    char buffer[100];

    
    for(i = 0; i < max; i++){

        miArchivo = fopen("Archivo.txt","a");

        cout<<"Ingresa Codigo de Equipo : ";
        cin>>auxI;
        nuevaMaquina[i].setCodigo(auxI);
        
        fprintf(miArchivo,"%i,",auxI);
    
        fclose(miArchivo);

        miArchivo = fopen("Archivo.txt","a");

        cout<<"Ingresa Marca del Equipo : ";
        fflush(stdin);
        getline(cin,auxS);
        nuevaMaquina[i].setMarca(auxS);

        strcpy(buffer,auxS.c_str());

        fprintf(miArchivo,"%s,",buffer);
        fclose(miArchivo);

        cout<<"Ingresa Precio de Equipo : ";
        cin>>auxD;
        nuevaMaquina[i].setPrecio(auxD);

        miArchivo = fopen("Archivo.txt","a");
        fprintf(miArchivo,"%.2f,",auxD);
        fclose(miArchivo);

        cout<<"\nIngrese Que tipo de Producto es : ";
        cout<<"[1]. Protesis\n[2]. Sensor\n\n[-]. Ingrese opcion : ";
        cin>>opc;

        if(opc == 1){
            miArchivo = fopen("Archivo.txt","a");

            cout<<"Ingresa que Protesis es : ";
            fflush(stdin);
            getline(cin,auxS);

            nuevaMaquina[i].setNombre(auxS);

            strcpy(buffer,auxS.c_str());            
            fprintf(miArchivo,"%s,",buffer);           
            fclose(miArchivo);


            miArchivo = fopen("Archivo.txt","a");

            cout<<"Indique que Componentes trae : ";
            cin>>auxI;
            nuevaMaquina[i].setComponente(auxI);

            strcpy(buffer,auxS.c_str());             
            fprintf(miArchivo,"%i\n",auxI);
            fclose(miArchivo);
        }else{
            
            
            miArchivo = fopen("Archivo.txt","a");
            cout<<"Indique el Tipo de Sensor que trae : ";
            fflush(stdin);
            getline(cin,auxS);
            nuevoSensor->setTipo(auxS);

            
            strcpy(buffer,auxS.c_str());   

            fprintf(miArchivo,"%s,",buffer);
            fclose(miArchivo);
            
            miArchivo = fopen("Archivo.txt","a");
            cout<<"Indique el Tam del Sensor : ";
            cin>>auxI;
            nuevoSensor->setTam(auxI);

            strcpy(buffer,auxS.c_str());   

            fprintf(miArchivo,"%i\n",buffer);
            fclose(miArchivo);
        }

        

    }   

    return 0;
}