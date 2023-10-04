#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define nroLibros 100

typedef struct{

    char titulo[40];
    char autor[20];
    float numCatalogo;
    int anioPublic;
    int nroCopia;
    char fechaPrestamo[20];
    char fechaDevolucion[20];
}Tlibro;

void agregarLibro(Tlibro nuevoLibro[],int i){

    printf("\n\n\t\t[ Agregando Libro ]\n\n");
    printf("Ingresa Titulo de libro : ");
    fflush(stdin);
    gets(nuevoLibro[i].titulo);
    printf("Ingresa Autor de libro : ");
    fflush(stdin);
    gets(nuevoLibro[i].autor);
    printf("Ingresa numero de Catalogo de libro : ");
    scanf("%f",&nuevoLibro[i].numCatalogo);
    printf("Ingresa anio de publicacion : ");
    scanf("%i",&nuevoLibro[i].anioPublic);
    printf("Ingresa numero de copia de libro : ");
    scanf("%i",&nuevoLibro[i].nroCopia);

    strcpy(nuevoLibro[i].fechaPrestamo,"Sin registro");
    strcpy(nuevoLibro[i].fechaDevolucion,"Sin registro");
}

void imprimirLibro(Tlibro libro[],int max){

    printf("\n\n\t\t[ Imprimiendo Libros ]\n\n");
    int i;

    for(i = 0; i < max; i++){
        printf("Titulo de Libro -> %s\n",libro[i].titulo);
        printf("Autor de Libro -> %s\n",libro[i].autor);
        printf("numero de Catalogo de Libro -> %.2f\n",libro[i].numCatalogo);
        printf("Anio de publicacion de Libro -> %i\n",libro[i].anioPublic);
        printf("Numero de copias de Libro -> %i\n",libro[i].nroCopia);
        printf("Fecha de Prestamo -> %s\n",libro[i].fechaPrestamo);
        printf("Fecha de Devolucion -> %s\n",libro[i].fechaDevolucion);
        printf("\n");
    }
    system("pause");
}


void buscarLibroTitulo(Tlibro libro [],int max){

    char titulo[40];
    int i;
    printf("Ingresa titulo de libro : ");
    fflush(stdin);
    gets(titulo);


    for(i = 0; i < max; i++){
        if(strcmp(titulo,libro[i].titulo)==0){
        printf("Titulo de Libro -> %s\n",libro[i].titulo);
        printf("Autor de Libro -> %s\n",libro[i].autor);
        printf("numero de Catalogo de Libro -> %.2f\n",libro[i].numCatalogo);
        printf("Anio de publicacion de Libro -> %i\n",libro[i].anioPublic);
        printf("Numero de copias de Libro -> %i\n",libro[i].nroCopia);
        printf("Fecha de Prestamo -> %s\n",libro[i].fechaPrestamo);
        printf("Fecha de Devolucion -> %s\n",libro[i].fechaDevolucion);
        printf("\n");           
        }
    }
    
    system("pause");
}

void buscarLibroAutor(Tlibro libro [],int max){

    char Autor[40];
    int i;
    printf("Ingresa Autor de libro : ");
    fflush(stdin);
    gets(Autor);


    for(i = 0; i < max; i++){
        if(strcmp(Autor,libro[i].titulo)==0){
        printf("Titulo de Libro -> %s\n",libro[i].titulo);
        printf("Autor de Libro -> %s\n",libro[i].autor);
        printf("numero de Catalogo de Libro -> %.2f\n",libro[i].numCatalogo);
        printf("Anio de publicacion de Libro -> %i\n",libro[i].anioPublic);
        printf("Numero de copias de Libro -> %i\n",libro[i].nroCopia);
        printf("Fecha de Prestamo -> %s\n",libro[i].fechaPrestamo);
        printf("Fecha de Devolucion -> %s\n",libro[i].fechaDevolucion);
        printf("\n");           
        }
    }
    
    system("pause");
}
void menu(){
    system("cls");
    printf("\n\n\t\t[ LIBROS ]\n\n");
    printf("[1]. Agregar nuevo Libro\n");
    printf("[2]. Buscar Libro por titulo\n");
    printf("[3]. Buscar Libro por Autor\n");
    printf("[4]. Modificar el nombre del libro\n");
    printf("[5]. Dar de baja algun libro\n");
    printf("[6]. Registrar fecha prestamo de libro\n");
    printf("[7]. Registrar fecha devolucion de libro\n");
    printf("[8]. Listar catalogo de libros\n");
    printf("[9]. Salir\n\n[?]. Ingresa opcion : ");
}

int main(){

    int i = 0;
    Tlibro libros[nroLibros];
    int opc;
    do{
        menu();
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:
            agregarLibro(libros,i);
            i++;
            break;
        
        case 2:
            break;
        case 3:
            
            break;
        
        case 4:
            break;

        case 5:
            
            break;
        
        case 6:
            break;

        case 7:
            
            break;
        
        case 8:
            imprimirLibro(libros,i);
            break;

        }


    }while(opc != 9);



    return 0;
}