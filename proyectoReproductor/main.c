#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_LENGTH 256

typedef struct Nodo{

    char codID[19];
    char nombreAlbum[50];
    char artista[50];
    float duracion;
    char titulo[50];
    int anio;
    struct Nodo *siguiente;
    struct Nodo *atras;

}Nodo;

typedef struct datosAux{

    char codID[19];
    char nombreAlbum[50];
    char artista[50];
    float duracion;
    char titulo[50];
    int anio;

}datosAux;

Nodo *primero = NULL;
Nodo *ultimo = NULL;

void agregar();
void desplegarLista();
void CargarDatos(FILE *);
void auxCargar(datosAux );
void buscarCancion();
void desplegarOrdenado();
void eliminarCancion();
void retornarCancion(char []);

datosAux lineToStruct(char*);

void menu(){
    system("cls");
    printf("\n\n\t\t[ REPRODUCTOR : MENU PRINCIPAL ]\n\n");
    printf("[1]. Editar Lista de Reproduccion\n");
    printf("[2]. Reproducir\n");
    printf("[3]. Salir\n");
    printf("\n[?]. Ingresa esa opcion : ");
}

void submenu(){
    system("cls");
    printf("\n\n\t\t[ REPRODUCTOR : MENU EDITAR LISTA ]\n\n");
    printf("[1]. Agregar una cancion\n");
    printf("[2]. Eliminar una cancion\n");
    printf("[3]. Mostrar lista de reproduccion\n");
    printf("[4]. Mostrar lista de reproduccion ordenada\n");
    printf("[5]. Buscar una cancion por Titulo\n");
    printf("[6]. Regresar al menu principal\n");
    printf("\n[?]. Ingresa esa opcion : ");
}

void submenuReproducir(char *cad, int intento){
    system("cls");

    if(intento == 0){
        printf("\n\n\t\t[ REPRODUCTOR : MENU REPRODUCIR ]\n");
        printf("Reproduciendo -> Ninguna cancion\n\n");
        printf("[1]. Reproducir [ PLAY ]\n");
        printf("[2]. Siguiente\n");
        printf("[3]. Anterior\n");
        printf("[4]. Regresar al menu principal\n");
        printf("\n[?]. Ingresa esa opcion : ");
    }else{
        printf("\n\n\t\t[ REPRODUCTOR : MENU REPRODUCIR ]\n\n");
        printf("Reproduciendo -> %s\n\n",cad);
        printf("[1]. Reproducir [ PLAY ]\n");
        printf("[2]. Siguiente\n");
        printf("[3]. Anterior\n");
        printf("[4]. Regresar al menu principal\n");
        printf("\n[?]. Ingresa esa opcion : ");
    }
}

int main()
{

    FILE *playlist;

    int opc;
    char aux[MAX_LENGTH];
    int y = 0;
    bool salir = false;
    bool salirSubmenu = false;
    bool salirReproducir = false;
    
    CargarDatos(playlist);
    char cad[50];

    do{
        menu();
        scanf("%i",&opc);
        switch (opc)
        {
        
        case 1:
            salirSubmenu = false;
            do{
            submenu();
            scanf("%i",&opc);
            switch (opc)
            {
            case 1:
                agregar();
                printf("\n");
                system("pause");
                break;
            
            case 2:
                eliminarCancion();
                break;

            case 3:
                desplegarLista();
                system("pause");
                break;

            case 4:
                desplegarOrdenado();
                break;
            case 5:
                buscarCancion();
                system("pause");
                break;
            case 6:
                salirSubmenu = true;
                break;
            }
            }while(salirSubmenu != true);

            break;
        
        case 2:
            retornarCancion(cad);

            break;

        case 3:
            salir = true;
            printf("\n\n\t\t[ SALIENDO DE SPOTIMEX.. ]\n\n");
            break;
        }


    }while(salir != true);

    system("pause");
    return 0;
}


void agregar(){

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    char aux[20];
    bool correcto = true;
    

    printf("\n\n\t\t[ INGRESO DE ALGUNA CANCION ]\n\n");


    do{
        printf("\nIngresa codID [17] -> ");
        fflush(stdin);
        gets(aux);

        if(strlen(aux) == 17){
            correcto = true;
            strcpy(nuevo->codID,aux);
        }else{
            correcto = false;
            printf("El codigo debe ser de 17 digitos\n");
            system("pause");
        }


    }while(correcto != true);

    strcpy(nuevo->nombreAlbum,aux);

    printf("\nIngresa nombre de Album -> ");
    fflush(stdin);
    gets(nuevo->nombreAlbum);

    printf("\nIngresa nombre de Artista -> ");
    fflush(stdin);
    gets(nuevo->artista);

    printf("\nDuracion de la cancion Minutos\n");
    printf("Ejemplo : 260.25\nIngresa Duracion ->");
    scanf("%f",&nuevo->duracion);

    printf("\nIngresa nombre de Titulo -> ");
    fflush(stdin);
    gets(nuevo->titulo);


    printf("\nIngresa anio de la cancion -> ");
    scanf("%i",&nuevo->anio);

    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->atras = ultimo;
        ultimo = nuevo;
    }

    printf("\n\n\t\t[ CANCION AGREGADA A LA PLAYLIST CORRECTAMENTE ]\n\n");
}


void desplegarLista(){

    Nodo * actual;
    
    actual = primero;

    printf("\n\n\t\t[ MOSTRANDO PLAYLIST ]\n\n");
    while(actual != NULL){
        printf("%s - %s - %s - %.2f - %s - %i\n",actual->codID,
        actual->nombreAlbum,actual->artista,actual->duracion,
        actual->titulo,actual->anio);

        actual = actual->siguiente;
        Sleep(1);
    }


}

void CargarDatos(FILE *playlist){


/*
        printf("%s - %s - %s - %.2f - %s - %i\n",auxEstructura.codID,
        auxEstructura.nombreAlbum,auxEstructura.artista,
        auxEstructura.duracion,auxEstructura.titulo,auxEstructura.anio);
*/

    datosAux auxEstructura;
    playlist = fopen("playlist2.txt","r");

    char aux[MAX_LENGTH];

    while(fgets(aux,MAX_LENGTH,playlist)){
        //printf("%s",aux);
        auxEstructura = lineToStruct(aux);

        auxCargar(auxEstructura);

    }    

    fclose(playlist);


}

void auxCargar(datosAux a){

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

        strcpy(nuevo->codID,a.codID);
        strcpy(nuevo->nombreAlbum,a.nombreAlbum);
        strcpy(nuevo->artista,a.artista);
        nuevo->duracion = a.duracion;
        strcpy(nuevo->titulo,a.titulo);
        nuevo->anio = a.anio;

    if(primero == NULL){
        primero = nuevo;
        primero->siguiente = NULL;
        primero->atras = NULL;
        ultimo = primero;
    }else{
        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->atras = ultimo;
        ultimo = nuevo;
    }

}

datosAux lineToStruct(char*cad){

    int nElementos=0,count=1;
    int tam=strlen(cad);
    datosAux herramienta;
    int x,i;
    char *ptr,delim[]=",";

    // for(i=0;i<tam;i++)
    //     if(cad[i]==',')
    //         nElementos++;

            
    ptr=strtok(cad,delim);
    strcpy(herramienta.codID,ptr);
    while((ptr=strtok(NULL,delim))!=NULL)
    {
        
        if(count==1){
            
            strcpy(herramienta.nombreAlbum,ptr); 
            fflush(stdin);
        }
        else if(count==2){
            strcpy(herramienta.artista,ptr);
            fflush(stdin);
        }
        else if(count==3){
            herramienta.duracion=atof(ptr);
            fflush(stdin);
        }
        else if(count==4){
            strcpy(herramienta.titulo,ptr);
            fflush(stdin);
        }
        else if(count==5){
            herramienta.anio=atoi(ptr);
            fflush(stdin);
        }


        
        count++;
    }
    return herramienta;

}

/*

    for(x = 0 ; x <= 17; x++){
        codIDAUX[x] = ptr[x];
    }

    codIDAUX[strlen(codIDAUX)-1] = '\0';
*/

void buscarCancion(){

    Nodo* actual;
    actual = primero;
    char aux[40];
    bool entro = false;
    int microsegundos = 1000000;


    printf("\n\n\t\t[ BUSQUEDA DE ALGUNA CANCION ]\n\n");

    printf("Ingresa el titulo de la cancion : ");
    fflush(stdin);
    gets(aux);



    while(actual != NULL){

        if(strcmp(aux,actual->titulo) == 0){
            printf("\n\n\t\t[ CANCION ENCONTRADA ]\n\n");
            printf("%s - %s - %s - %.2f - %s - %i\n\n",actual->codID,
            actual->nombreAlbum,actual->artista,actual->duracion,
            actual->titulo,actual->anio);
            entro = true;
            break;
        }
        actual = actual->siguiente;
    }

    if(entro == false){
        printf("\n\n\t\t[ NO SE ENCONTRO LA CANCION A BUSCAR ]\n\n");
    }
}

void desplegarOrdenado(){

    Nodo *actual , *siguiente;
    int t;


    
    actual = primero;
    while(actual->siguiente != NULL)
    {
        siguiente = actual->siguiente;
        
        while(siguiente!=NULL)
        {
            if(actual->anio > siguiente->anio)
            {
                t = siguiente->anio;
                siguiente->anio = actual->anio;
                actual->anio = t;
                printf("%i \n",actual->anio);
            }
            siguiente = siguiente->siguiente;                    
        }    
        actual = actual->siguiente;
        siguiente = actual->siguiente;
        
    }
    printf("\n\n\t\t [ LISTA ORDENADA ]\n\n");
}

void eliminarCancion(){
    
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	Nodo* anterior = (Nodo*)malloc(sizeof(Nodo));
	anterior = NULL;
	char nodoBuscado[20];
    int encontrado = 0;
	printf(" Ingrese el codigo de la cancion a Buscar para Eliminar [17 digitos]: ");
    fflush(stdin);
	gets(nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			//actual->dato == nodoBuscado
			if(strcmp(actual->codID,nodoBuscado)==0){
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n\nCancion Eliminada de la PlayList\n\n");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n No se encontro la cancion a buscar\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La PlayList se encuentra vacia\n\n");
	}

    system("pause");
}

void retornarCancion(char cancionActual[]){

    Nodo *actual;
    actual = primero;
    int y = 0;
    int opc;
    bool salirReproducir = false;
    bool entro = false;
    int pausar = 0;
    char actualmusica[50];
    while(actual != NULL){
        
        do{
            submenuReproducir(actualmusica,y);
            y++;
            scanf("%i",&opc);
            switch (opc)
            {
            case 1:
                if(entro == false){
                    printf("\n\t[ Ahora se esta reproduciento la playlist ]\n\n");

                    actual = actual->siguiente;
                    strcpy(actualmusica ,actual->titulo);
                    entro = true;
                }else{
                    if(pausar == 0){
                        printf("\n\t[ Se pauso la playlist ]\n\n");
                        pausar = 1;
                    }else{
                        printf("\n\t[ le dio play a la playlist ]\n\n");
                        pausar = 0;
                    }

                }
                break;
            
            case 2:
                actual = actual->siguiente;
                strcpy(actualmusica ,actual->titulo);
                break;

            case 3:
                actual = actual->atras;
                strcpy(actualmusica ,actual->titulo);
                break;

            case 4:
                salirReproducir = true;
                actual = NULL;
                break;
            }
            printf("\n");
            system("pause");
        }while(salirReproducir != true);
        
    }



}
