#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string>

#define libros 100
using namespace std;

typedef struct{

    char titulo[40];
    char autor[20];
    float numCatalogo;
    int anioPublic;
    int nroCopia;
    char fechaPrestamo[20];
    char fechaDevolucion[20];

}TLibro;

void agregarLibro(TLibro libro[],int i){

    cout<<"\n\n\t\t[ AGREGANDO LIBROS ]\n\n";

    cout<<"Ingresa el titulo : ";
    fflush(stdin);
    gets(libro[i].titulo);

    cout<<"Ingresa el autor : ";
    fflush(stdin);
    gets(libro[i].autor);

    cout<<"Ingresa numero de catalogo : ";
    cin>>libro[i].numCatalogo;
    cout<<"Ingresa Anio de publicacion : ";
    cin>>libro[i].anioPublic;
    cout<<"Ingresa numero de copia : ";
    cin>>libro[i].nroCopia;

    strcpy(libro[i].fechaPrestamo,"No hay Registro");
    strcpy(libro[i].fechaDevolucion,"No hay Registro");

    cout<<"\n\n\t\t[ NUEVO LIBRO AGREGADO ]\n\n";
    system("pause");
}
void buscarlibroTitulo(TLibro libro[],int max){

    char auxiliar[40];

    cout<<"\n\n\t\t[ BUSCANDO LIBRO - TITULO ]\n\n";
    cout<<"Ingresa Titulo de libro : ";
    fflush(stdin);
    gets(auxiliar);

    int i;

    for(i = 0; i < max; i++){
        if(strcmp(auxiliar,libro[i].titulo)== 0){
        cout<<"Numero de Libro -> "<<i+1<<endl;
        cout<<"Titulo : "<<libro[i].titulo<<endl;
        cout<<"Autor : "<<libro[i].autor<<endl;
        cout<<"Numero de Catalogo : "<<libro[i].numCatalogo<<endl;
        cout<<"Anio de Publicacion : "<<libro[i].anioPublic<<endl;
        cout<<"Nro  de Copia : "<<libro[i].nroCopia<<endl;
        cout<<"Fecha de Prestamo : "<<libro[i].fechaPrestamo<<endl;
        cout<<"Fecha de Devolucion : "<<libro[i].fechaDevolucion<<endl<<endl;
        }
    }

    cout<<endl;
    system("pause");
}

void buscarlibroAutor(TLibro libro[],int max){

    char auxiliar[40];

    cout<<"\n\n\t\t[ BUSCANDO LIBRO - AUTOR ]\n\n";
    cout<<"Ingresa Autor de libro : ";
    fflush(stdin);
    gets(auxiliar);

    int i;

    for(i = 0; i < max; i++){
        if(strcmp(auxiliar,libro[i].autor)== 0){
        cout<<"Numero de Libro -> "<<i+1<<endl;
        cout<<"Titulo : "<<libro[i].titulo<<endl;
        cout<<"Autor : "<<libro[i].autor<<endl;
        cout<<"Numero de Catalogo : "<<libro[i].numCatalogo<<endl;
        cout<<"Anio de Publicacion : "<<libro[i].anioPublic<<endl;
        cout<<"Nro  de Copia : "<<libro[i].nroCopia<<endl;
        cout<<"Fecha de Prestamo : "<<libro[i].fechaPrestamo<<endl;
        cout<<"Fecha de Devolucion : "<<libro[i].fechaDevolucion<<endl<<endl;
        }
    }

    cout<<endl;
    system("pause");
}


void modificarNombreLibro(TLibro libro[],int max){

    int auxiliar;

    cout<<"\n\n\t\t[ BUSCANDO LIBRO - AUTOR ]\n\n";
    cout<<"Ingresa numero de Catalogo de libro : ";
    fflush(stdin);
    cin>>auxiliar;
    bool entro = false;
    int i;

    for(i = 0; i < max; i++){
        if(auxiliar == libro[i].numCatalogo){

            cout<<"Numero de Libro -> "<<i+1<<endl;
            cout<<"Titulo : "<<libro[i].titulo<<endl;
            cout<<"Autor : "<<libro[i].autor<<endl;
            cout<<"Numero de Catalogo : "<<libro[i].numCatalogo<<endl;
            cout<<"Anio de Publicacion : "<<libro[i].anioPublic<<endl;
            cout<<"Nro  de Copia : "<<libro[i].nroCopia<<endl;
            cout<<"Fecha de Prestamo : "<<libro[i].fechaPrestamo<<endl;
            cout<<"Fecha de Devolucion : "<<libro[i].fechaDevolucion<<endl<<endl;

            cout<<"\nIngresa nuevo nombre de Libro : ";
            fflush(stdin);
            gets(libro[i].titulo);
            entro = true;
            break;  
        }
    }

    if(!entro)
        cout<<"\n\n\t\t[ NO SE ENCONTRO EL LIBRO A MODIFICAR ]\n\n";
    cout<<endl;
    system("pause");
}

void registrarFechaPrestamo(TLibro libro[],int max){


    cout<<"\n\n\t\t[ FECHA DE PRESTAMO ]\n\n";
    int auxiliar;
    cout<<"Ingresa numero de Catalogo de libro : ";
    fflush(stdin);
    cin>>auxiliar;
    bool entro = false;
    int i;

    for(i = 0; i < max; i++){
        if(auxiliar == libro[i].numCatalogo){

            cout<<"Numero de Libro -> "<<i+1<<endl;
            cout<<"Titulo : "<<libro[i].titulo<<endl;
            cout<<"Autor : "<<libro[i].autor<<endl;
            cout<<"Numero de Catalogo : "<<libro[i].numCatalogo<<endl;
            cout<<"Anio de Publicacion : "<<libro[i].anioPublic<<endl;
            cout<<"Nro  de Copia : "<<libro[i].nroCopia<<endl;
            cout<<"Fecha de Prestamo : "<<libro[i].fechaPrestamo<<endl;
            cout<<"Fecha de Devolucion : "<<libro[i].fechaDevolucion<<endl<<endl;

            cout<<"\nFecha de Prestamo de Libro ";
            cout<<"Ejemplo -> 12/02/2020\nIngresa : ";
            fflush(stdin);
            gets(libro[i].fechaPrestamo);
            entro = true;
            break;  
        }
    }

    if(!entro)
        cout<<"\n\n\t\t[ NO SE ENCONTRO EL LIBRO A MODIFICAR ]\n\n";
    cout<<endl;
    system("pause");
}

void registrarFechaDevolucion(TLibro libro[],int max){


    cout<<"\n\n\t\t[ FECHA DE DEVOLUCION ]\n\n";
    int auxiliar;
    cout<<"Ingresa numero de Catalogo de libro : ";
    fflush(stdin);
    cin>>auxiliar;
    bool entro = false;
    int i;

    for(i = 0; i < max; i++){
        if(auxiliar == libro[i].numCatalogo){

            cout<<"Numero de Libro -> "<<i+1<<endl;
            cout<<"Titulo : "<<libro[i].titulo<<endl;
            cout<<"Autor : "<<libro[i].autor<<endl;
            cout<<"Numero de Catalogo : "<<libro[i].numCatalogo<<endl;
            cout<<"Anio de Publicacion : "<<libro[i].anioPublic<<endl;
            cout<<"Nro  de Copia : "<<libro[i].nroCopia<<endl;
            cout<<"Fecha de Prestamo : "<<libro[i].fechaPrestamo<<endl;
            cout<<"Fecha de Devolucion : "<<libro[i].fechaDevolucion<<endl<<endl;

            cout<<"\nFecha de Devolucion de Libro ";
            cout<<"Ejemplo -> 12/02/2020\nIngresa : ";
            fflush(stdin);
            gets(libro[i].fechaDevolucion);
            entro = true;
            break;  
        }
    }

    if(!entro)
        cout<<"\n\n\t\t[ NO SE ENCONTRO EL LIBRO A MODIFICAR ]\n\n";
    cout<<endl;
    system("pause");
}

void desplegarCatalogo(TLibro libro[],int max){
    int i;

    cout<<"\n\n\t\t[ DESPLEGANDO CATALOGO ]\n\n";
    for(i = 0; i < max; i++){
        cout<<"Numero de Libro -> "<<i+1<<endl;
        cout<<"Titulo : "<<libro[i].titulo<<endl;
        cout<<"Autor : "<<libro[i].autor<<endl;
        cout<<"Numero de Catalogo : "<<libro[i].numCatalogo<<endl;
        cout<<"Anio de Publicacion : "<<libro[i].anioPublic<<endl;
        cout<<"Nro  de Copia : "<<libro[i].nroCopia<<endl;
        cout<<"Fecha de Prestamo : "<<libro[i].fechaPrestamo<<endl;
        cout<<"Fecha de Devolucion : "<<libro[i].fechaDevolucion<<endl<<endl;
    }

    cout<<endl;
    system("pause");
}

void eliminarLibro(TLibro libro[],int &max){

    int auxiliar,i;
    if(max != 0){
        
        cout<<"\n\n\t\t[ ELIMINAR UN LIBRO ]\n\n";
        cout<<"Ingresa numero de Catalogo de Libro : ";
        cin>>auxiliar;

        for( i = 0; i < max; i++){

            if(auxiliar == libro[i].numCatalogo){

                while( i < max-1){
                    libro[i]= libro[i+1];
                    i++;
                }
                break;
            }

        }

        max = max - 1;

        cout<<"\n\n\t [LIBRO ELIMINADO]\n\n";

    }else{
        cout<<"\n\n\t\t[ Aun no hay registros de Libro ]\n\n";
    }

    cout<<endl;
    system("pause");

}
void menu(){
    system("cls");
    cout<<"\n\n\t\t[ BIBLIOTECA ]\n\n";
    cout<<"[1]. Agregar Nuevo libro\n";
    cout<<"[2]. Buscar Libro por Titulo\n";
    cout<<"[3]. Buscar Libro por Autor\n";
    cout<<"[4]. Modificar Nombre de Libro\n";
    cout<<"[5]. Dar de Baja a un Libro\n";
    cout<<"[6]. Registrar fecha de Prestamo de un libro\n";
    cout<<"[7]. Registrar fecha de devolucion de un libro\n";
    cout<<"[8]. Listar el Catalogo de libros de la Biblioteca\n";
    cout<<"[9]. Salir\n\n";
    cout<<"[?]. Ingresa una opcion : ";
}

int main(){

    TLibro nuevoLibro[libros];

    int i = 0;
    bool salir = false;
    int opc;
    
    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            agregarLibro(nuevoLibro,i);
            i++;
            break;
        
        case 2:     
            buscarlibroTitulo(nuevoLibro,i);
            break;
        
        case 3:
            buscarlibroAutor(nuevoLibro,i);
            break;
        
        case 4:
            modificarNombreLibro(nuevoLibro,i);
            break;
        
        case 5:
            eliminarLibro(nuevoLibro,i);
            break;
        case 6:
            registrarFechaPrestamo(nuevoLibro,i);
            break;
        case 7:
            registrarFechaDevolucion(nuevoLibro,i);
            break;
        case 8:
            desplegarCatalogo(nuevoLibro,i);
            break;
        case 9: 
            salir = true;
            break;

        }

    }while(!salir);

    return 0;
}