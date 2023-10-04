#include<iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define _maxSize 3

using namespace std;

struct tool{

    int registro;
    char nombre[20];
    int cantidad;
    float precio;
};


void menu(){
    system("cls");
    cout<<"\n\n\t\t[ MENU DE CREACION Y MANEJO DE ARCHIVOS ]\n\n";
    cout<<"[1]. Creacion del archivo y/o cargue del archivo\n";
    cout<<"[2]. Cargar el inventario existente en el archivo al sistema\n";
    cout<<"[3]. Ingresar Herramienta\n";
    cout<<"[4]. Mostrar Herramientas\n";
    cout<<"[5]. Guardar Cambios - Salir\n";
    cout<<"\nIngresa opcion : ";
}

void IngresarHerramientas(struct tool [],int );
void mostrarHerramientras(struct tool [],int );

int main(){


    //* ITERADOR PRINCIPAL
    int i = 0;
    
    int j,decidir,opc;
    bool creado = false,salir = false;

    FILE *miArchivo;    
    struct tool herramienta[_maxSize];
    
    //*CARGA DE ARCHIVOS..

    char *line;
    string texto;
    size_t len = 0;
    int lineas;

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            if(!creado){
                creado = true;
                miArchivo = fopen("miPrimerArchivo.txt","w");
                printf("\n[ Acabas de crear el TXT ]\n\n");
            }else{
                cout<<"\n\n\t\t[EL ARCHIVO YA FUE CREADO ]\n\n";
            }
            system("pause");
            break;

        case 2:
            lineas = 0;
            while(feof(miArchivo) == 0){
                    lineas++;
            }
            cout<<"\n\n\t\t[ EN TOTAL HAY "<<lineas<<"lineas"<<endl;
            system("pause");
            break;


        case 3:
                if(creado && i < _maxSize){
                    fopen("miPrimerArchivo.txt","a");
                    IngresarHerramientas(herramienta,i);
                    fprintf(miArchivo,"%i,",herramienta[i].registro);
                    fprintf(miArchivo,"%s,",herramienta[i].nombre);
                    fprintf(miArchivo,"%i,",herramienta[i].cantidad);
                    fprintf(miArchivo,"%.2f\n",herramienta[i].precio);
                    i++;
                    cout<<"\n\n\t\t[ SE INTRODUJERON LOS VALORES ]\n\n";
                    
                    fclose(miArchivo);
                    
                }else{
                    cout<<"\n\n\t\t[ AUN NO SE CREO EL ARCHIVO ]\n\n";
                }
                system("pause");
            break;


        case 4:
            mostrarHerramientras(herramienta,i);
            break;

        case 5:
            cout<<"\n\n\t\t[ ARCHIVO GUARDADO Y CERRADO CORRECTAMENTE ]\n\n";
            cout<<"REVISE DOCUMENTO PORFAVOR...\n\n";
            fclose(miArchivo);
            salir = true;
            break;

        }

    }while(salir != true);



    return 0;
}


void IngresarHerramientas(struct tool herramienta[],int i){

    cout<<"\n\n\t\t[ INGRESO DE HERRAMIENTA N. -> "<<i<<" ]\n\n";


    herramienta[i].registro = i;
    
    cout<<"Ingresa el nombre de herramienta : ";
    fflush(stdin);
    gets(herramienta[i].nombre);
    
    cout<<"Ingresa la cantidad : ";
    cin>>herramienta[i].cantidad;

    cout<<"Ingresa el valor : ";
    cin>>herramienta[i].precio;

}

void mostrarHerramientras(struct tool herramienta[],int max){

    int i;

    cout<<endl;

    if(max != 0){
        
        cout<<"\n\n\t\t[ MOSTRANDO REGISTROS ]\n\n";
        for(i = 0; i < max; i++){

            cout<<"[txtos de Registro -> "<<i+1<<"]\n";
            cout<<"Numero de Registro : "<<herramienta[i].registro<<endl;
            cout<<"Nombre de Herramienta : "<<herramienta[i].nombre<<endl;
            cout<<"Cantidad Exacta : "<<herramienta[i].cantidad<<endl;
            cout<<"Precio Total  : "<<herramienta[i].precio<<endl<<endl;
            

        }

    }else{
        cout<<"\n\n\t\t[ NO SE ENCUENTRAN REGISTROS ]\n\n";
    }
    cout<<"\n";
    system("pause");
}