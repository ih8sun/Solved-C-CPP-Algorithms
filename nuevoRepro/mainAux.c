#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN	2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LIGHTBLUE 9
#define COLOR_LIGHTGREEN 10
#define COLOR_LIGHTCYAN 11
#define COLOR_LIGHTRED 12
#define COLOR_LIGHTMAGENTA 12
#define COLOR_YELOW 14
#define COLOR_WHITE 15
#define COLOR_BLINK 128
#define MAX_LENGTH 256
#define COLOR_LIGHTGRAY 8

typedef struct Nodo{

    char codID[19];
    char nombreAlbum[150];
    char artista[150];
    float duracion;
    char titulo[150];
    int anio;
    struct Nodo *siguiente;
    struct Nodo *atras;

}Nodo;

typedef struct datosAux{

    char codID[19];
    char nombreAlbum[150];
    char artista[150];
    float duracion;
    char titulo[150];
    int anio;

}datosAux;

Nodo *primero = NULL;
Nodo *ultimo = NULL;

void colorear(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void agregar();
void desplegarLista();
void CargarDatos(FILE *);
void auxCargar(datosAux );
void buscarCancion();
void desplegarOrdenado();
void eliminarCancionPorID();
void eliminarCancionPorTitulo();
void retornarCancion(char []);
int totalCanciones();
datosAux lineToStruct(char*);
void menu();
void submenu();
void menuEliminar();
void menuOrdenar();
void submenuReproducir(char *cad, int intento);
void structAmayus();
void textoAmayus(char cadena[]);
//FUNCIONES PARA QUICKSORT  Y BUSQUEDA BINARIA
void intercambio(int *a, int *a2,float *b, float *b2,char c[],char c2[],
        char d[],char d2[],char e[],char e2[],char f[],char f2[])
{
    int aAux = *a;
    *a = *a2;
    *a2 = aAux;

    float bAux = *b;
    *b = *b2;
    *b2 = bAux;

    char cAux[150];

    strcpy(cAux,c);
    strcpy(c,c2);
    strcpy(c2,cAux);

    char dAux[150];

    strcpy(dAux,d);
    strcpy(d,d2);
    strcpy(d2,dAux);

    char eAux[150];

    strcpy(eAux,e);
    strcpy(e,e2);
    strcpy(e2,eAux);

    char fAux[19];

    strcpy(fAux,f);
    strcpy(f,f2);
    strcpy(f2,fAux);
}

struct Nodo *ultimoNodo(Nodo *root)
{
    while (root && root->siguiente)
        root = root->siguiente;
    return root;
}

Nodo *divideYvenceras(Nodo *prim, Nodo *h,int opc)
{

    int xAnio = h->anio;
    float xDuracion = h->duracion;
    
    char xCodID[19];
    strcpy(xCodID,h->codID);

    char xTitulo[150];
    strcpy(xTitulo,h->titulo);

    char xAlbum[150];
    strcpy(xAlbum,h->nombreAlbum);

    //! OPC => 1 ANIO
    //todo OPC => 2 ID
    //*OPC => 3 ALBUM
    //?OPC => 4 TITULO

    Nodo *i = prim->atras;
    Nodo *j;
    int result;

    if(opc == 1){
        for (j = prim; j != h; j = j->siguiente)
        {
            if (j->anio <= xAnio)
            {

                i = (i == NULL) ? prim : i->siguiente;

                intercambio(&(i->anio), &(j->anio), &(i->duracion),&(j->duracion),
                i->artista,j->artista,i->titulo,
                j->titulo,i->nombreAlbum,j->nombreAlbum,i->codID,j->codID);
            }
        }
        i = (i == NULL) ? prim : i->siguiente; 
        intercambio(&(i->anio), &(h->anio),&(i->duracion),&(h->duracion),
        i->artista,h->artista,i->titulo,
        h->titulo,i->nombreAlbum,h->nombreAlbum,i->codID,h->codID);
        return i;

    }
    
    if(opc == 2){

        for (j = prim; j != h; j = j->siguiente)
        {
            result = strcmp(j->codID,xCodID);

            if (result <= 0) // j->anio <= xAnio
            {

                i = (i == NULL) ? prim : i->siguiente;

                intercambio(&(i->anio), &(j->anio), &(i->duracion),&(j->duracion),
                i->artista,j->artista,i->titulo,
                j->titulo,i->nombreAlbum,j->nombreAlbum,i->codID,j->codID);
            }
        }
        i = (i == NULL) ? prim : i->siguiente; 
        intercambio(&(i->anio), &(h->anio),&(i->duracion),&(h->duracion),
        i->artista,h->artista,i->titulo,
        h->titulo,i->nombreAlbum,h->nombreAlbum,i->codID,h->codID);
        return i;

    }
    
    if(opc == 3){

        for (j = prim; j != h; j = j->siguiente)
        {   
            result = strcmp(j->nombreAlbum,xAlbum);

            if (result <= 0) // j->anio <= xAnio
            {

                i = (i == NULL) ? prim : i->siguiente;

                intercambio(&(i->anio), &(j->anio), &(i->duracion),&(j->duracion),
                i->artista,j->artista,i->titulo,
                j->titulo,i->nombreAlbum,j->nombreAlbum,i->codID,j->codID);
            }
        }
        i = (i == NULL) ? prim : i->siguiente; 
        intercambio(&(i->anio), &(h->anio),&(i->duracion),&(h->duracion),
        i->artista,h->artista,i->titulo,
        h->titulo,i->nombreAlbum,h->nombreAlbum,i->codID,h->codID);
        return i;

    }
    
    if(opc == 4){

        for (j = prim; j != h; j = j->siguiente)
        {   
            result = strcmp(j->titulo,xTitulo);

            if (result <= 0)
            {

                i = (i == NULL) ? prim : i->siguiente;

                intercambio(&(i->anio), &(j->anio), &(i->duracion),&(j->duracion),
                i->artista,j->artista,i->titulo,
                j->titulo,i->nombreAlbum,j->nombreAlbum,i->codID,j->codID);
            }
        }
        i = (i == NULL) ? prim : i->siguiente; 
        intercambio(&(i->anio), &(h->anio),&(i->duracion),&(h->duracion),
        i->artista,h->artista,i->titulo,
        h->titulo,i->nombreAlbum,h->nombreAlbum,i->codID,h->codID);
        return i;

    }
    
    return i;
}

void _quickSort(struct Nodo *prim, struct Nodo *cabeza,int opc)
{
    
    //! OPC => 1 ANIO
    //todo OPC => 2 ID
    //*OPC => 3 TITULO

    if (cabeza != NULL && prim != cabeza && prim != cabeza->siguiente)
    {
        struct Nodo *p = divideYvenceras(prim, cabeza,opc);
        _quickSort(prim, p->atras,opc);
        _quickSort(p->siguiente, cabeza,opc);
    }
}

void quickSort(struct Nodo *cabeza,int opc)
{

    //! OPC => 1 ANIO
    //todo OPC => 2 ID
    //*OPC => 3 TITULO

    struct Nodo *h = ultimoNodo(cabeza);

    _quickSort(cabeza, h,opc);
}


void busquedaBinaria(Nodo **primero, char codID[])
{

    Nodo *actual = *primero;

    int pos = 0;

    while (strcmp(actual->codID,codID) != 0 && actual->siguiente != NULL)
    {
        pos++;
        actual = actual->siguiente;
    }

    if (strcmp(actual->codID,codID) != 0){
        colorear(COLOR_LIGHTRED);
        printf("\n\n[ No se encontro la cancion ]\n");
        colorear(COLOR_WHITE);
    }else{ 

        printf("\n\n\t\t[ CANCION ENCONTRADA ]\n\n");

        colorear(COLOR_WHITE);
        printf("%s",actual->codID);

        printf(" - ");

        colorear(COLOR_LIGHTRED);
        printf("%s",actual->nombreAlbum);

        printf(" - ");

        colorear(COLOR_LIGHTCYAN);
        printf("%s",actual->artista);
        
        printf(" - ");

        colorear(COLOR_LIGHTGRAY);
        printf("%.4f",actual->duracion);

        printf(" - ");

        colorear(COLOR_LIGHTGREEN);
        printf("%s",actual->titulo);

        printf(" - ");

        colorear(COLOR_YELOW);
        if(actual->anio == 0){
            printf("NULL\n");
        }else{
            printf("%i\n",actual->anio);
        }

    }

    colorear(COLOR_WHITE);

}


int main()
{

    FILE *playlist;
    Nodo *auxiliar;
    int opc;
    char aux[MAX_LENGTH],cad[150],codAux[19];
    int y = 0;
    bool salir = false,salirSubmenu = false,salirReproducir = false;
    bool eliminarSubmenu = false,ordenMenu = false;
    CargarDatos(playlist);
    bool binario = true;

    structAmayus();

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
                eliminarSubmenu = false;
                do{
                    menuEliminar();
                    scanf("%i",&opc);
                    switch (opc)
                    {
                    case 1:
                        eliminarCancionPorID();
                        break;
                    
                    case 2:
                        eliminarCancionPorTitulo();
                        break;

                    case 3:
                        eliminarSubmenu = true;
                        break;
                    }

                }while(eliminarSubmenu != true);
                break;

            case 3:
                ordenMenu = false;
                do{ 
                    menuOrdenar();
                    scanf("%i",&opc);
                    switch (opc)
                    {
                    case 1:
                        binario = false;
                        quickSort(primero,opc);
                        desplegarLista();
                        break;
                    
                    case 2:
                        binario = false;
                        quickSort(primero,opc);
                        desplegarLista();
                        break;

                    case 3:
                        binario = false;
                        quickSort(primero,opc);
                        desplegarLista();
                        break;

                    case 4:
                        binario = false;
                        quickSort(primero,opc);
                        desplegarLista();
                        break;

                    case 5:
                        ordenMenu = true;
                        break;
                    }

                }while(ordenMenu != true);
                
                printf("\n\n");

                break;

            case 4:
                desplegarLista();
                break;
            case 5:
                auxiliar = primero;
                if(binario == true){
                    printf("\n[ BUSQUEDA BINARIA ] -> LISTA DESORDENADA\n\n");
                    printf("Ingresa codID de la cancion : ");
                    fflush(stdin);
                    gets(codAux);

                    busquedaBinaria(&auxiliar,codAux);                    
                    printf("\n");

                }else{
                    buscarCancion();
                }

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


void menu(){
    system("cls");
    colorear(COLOR_CYAN);
    printf("\n\n\t\t[ REPRODUCTOR : MENU PRINCIPAL ]\n\n");
    printf("[1]. Editar Lista de Reproduccion\n");
    printf("[2]. Reproducir\n");
    printf("[3]. Salir\n");
    printf("\n[?]. Ingresa esa opcion : ");
}

void submenu(){
    colorear(COLOR_WHITE);
    system("cls");
    printf("\n\n\t\t[ REPRODUCTOR : MENU EDITAR LISTA ]\n\n");
    printf("[1]. Agregar una cancion\n");
    printf("[2]. Eliminar una cancion\n");
    printf("[3]. Ordenar lista de reproduccion\n");
    printf("[4]. Mostrar lista de reproduccion\n");
    printf("[5]. Buscar una cancion por Titulo\n");
    printf("[6]. Regresar al menu principal\n");
    printf("\n[?]. Ingresa esa opcion : ");
}

void menuEliminar(){
    colorear(COLOR_WHITE);
    system("cls");
    printf("\n\n\t\t[ ELIMINAR ALGUNA CANCION ]\n\n");
    printf("\n\nCanciones Actuales -> %i\n\n",totalCanciones());
    printf("[1]. Eliminar por posicion[ID]\n");
    printf("[2]. Eliminar por Titulo\n");
    printf("[3]. Volver al Menu\n");
    printf("\n[?]. Ingresa una opcion : ");
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
        colorear(COLOR_WHITE);
        printf("\n\n\t\t[ REPRODUCTOR : MENU REPRODUCIR ]\n\n");
        colorear(COLOR_LIGHTGREEN);
        printf("Reproduciendo -> %s\n\n",cad);
        colorear(COLOR_CYAN);
        printf("[1]. Reproducir [ PLAY ]\n");
        colorear(COLOR_YELOW);
        printf("[2]. Siguiente\n");
        colorear(COLOR_LIGHTRED);
        printf("[3]. Anterior\n");
        colorear(COLOR_MAGENTA);
        printf("[4]. Regresar al menu principal\n");
        colorear(COLOR_WHITE);
        printf("\n[?]. Ingresa esa opcion : ");
    }
}

void agregar(){

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    char aux[150];
    bool correcto = true;
    

    printf("\n\n\t\t[ INGRESO DE ALGUNA CANCION ]\n\n");


    do{
        printf("\nIngresa codID [18] -> ");
        fflush(stdin);
        gets(aux);

        if(strlen(aux) == 18){
            correcto = true;
            textoAmayus(aux);
            strcpy(nuevo->codID,aux);
        }else{
            correcto = false;
            printf("El codigo debe ser de 18 digitos\n");
            system("pause");
        }


    }while(correcto != true);


    printf("\nIngresa nombre de Album -> ");
    fflush(stdin);
    gets(aux);
    textoAmayus(aux);
    strcpy(nuevo->nombreAlbum,aux);

    printf("\nIngresa nombre de Artista -> ");
    fflush(stdin);
    gets(aux);
    textoAmayus(aux);
    strcpy(nuevo->artista,aux);

    printf("\nDuracion de la cancion Minutos\n");
    printf("Ejemplo : 260.25\nIngresa Duracion ->");
    scanf("%f",&nuevo->duracion);

    printf("\nIngresa nombre de Titulo -> ");
    fflush(stdin);
    gets(aux);
    textoAmayus(aux);
    strcpy(nuevo->titulo,aux);


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

        colorear(COLOR_WHITE);
        printf("%s",actual->codID);

        printf(" - ");

        colorear(COLOR_LIGHTRED);
        printf("%s",actual->nombreAlbum);

        printf(" - ");

        colorear(COLOR_LIGHTCYAN);
        printf("%s",actual->artista);
        
        printf(" - ");

        colorear(COLOR_LIGHTGRAY);
        printf("%.4f",actual->duracion);

        printf(" - ");

        colorear(COLOR_LIGHTGREEN);
        printf("%s",actual->titulo);

        printf(" - ");

        colorear(COLOR_YELOW);
        if(actual->anio == 0){
            printf("NULL\n");
        }else{
            printf("%i\n",actual->anio);
        }

        actual = actual->siguiente;
        Sleep(1);
    }

    printf("\n\n");
    colorear(COLOR_WHITE);
    printf("CODIGO ID - ");
    colorear(COLOR_LIGHTRED);
    printf("ALBUM - ");
    colorear(COLOR_LIGHTCYAN);
    printf("ARTISTA - ");
    colorear(COLOR_LIGHTGRAY);
    printf("DURACION - ");
    colorear(COLOR_LIGHTGREEN);
    printf("TITULO - ");
    colorear(COLOR_YELOW);
    printf("ANIO");
    
    colorear(COLOR_WHITE);
    printf("\n\nCanciones Actuales -> %i\n\n",totalCanciones());
    system("pause");

}

void CargarDatos(FILE *playlist){


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

void buscarCancion(){

    Nodo* actual;
    actual = primero;
    char aux[150];
    bool entro = false;
    int microsegundos = 1000000;


    printf("\n\n\t\t[ BUSQUEDA DE ALGUNA CANCION ] -> LISTA ORDENADA\n\n");

    printf("Ingresa el titulo de la cancion : ");
    fflush(stdin);
    gets(aux);



    while(actual != NULL){

        if(strcmp(aux,actual->titulo) == 0){
        
        colorear(COLOR_LIGHTRED);
        printf("\n\n\t\t[ CANCION ENCONTRADA ]\n\n");

        colorear(COLOR_WHITE);
        printf("%s",actual->codID);

        printf(" - ");

        colorear(COLOR_LIGHTRED);
        printf("%s",actual->nombreAlbum);

        printf(" - ");

        colorear(COLOR_LIGHTCYAN);
        printf("%s",actual->artista);
        
        printf(" - ");

        colorear(COLOR_LIGHTGRAY);
        printf("%.4f",actual->duracion);

        printf(" - ");

        colorear(COLOR_LIGHTGREEN);
        printf("%s",actual->titulo);

        printf(" - ");

        colorear(COLOR_YELOW);
        if(actual->anio == 0){
            printf("NULL\n");
        }else{
            printf("%i\n",actual->anio);
        }
            break;
        }
        actual = actual->siguiente;
    }

    if(entro == false){
        colorear(COLOR_LIGHTRED);
        printf("\n\n\t\t[ NO SE ENCONTRO LA CANCION A BUSCAR ]\n\n");
    }
    colorear(COLOR_WHITE);
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

void eliminarCancionPorID(){
    
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	Nodo* anterior = (Nodo*)malloc(sizeof(Nodo));
	anterior = NULL;
	char nodoBuscado[150];
    int encontrado = 0;

    printf("\nCanciones Actuales -> %i\n\n",totalCanciones());

	printf("Ingrese el codigo de la cancion a Buscar para Eliminar [18 digitos]: ");
    fflush(stdin);
	gets(nodoBuscado);
    char cancion[150];
    char album[150];
    char artista[150];

	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			//actual->dato == nodoBuscado
			if(strcmp(actual->codID,nodoBuscado)==0){
				
                strcpy(cancion,actual->titulo);
                fflush(stdin);
                strcpy(album,actual->nombreAlbum);
                fflush(stdin);
                strcpy(artista,actual->artista);
                fflush(stdin);

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

                colorear(COLOR_LIGHTRED);
                printf("\t\t%s",album);

                printf(" - ");

                colorear(COLOR_LIGHTCYAN);
                printf("%s",artista);


                printf(" - ");

                colorear(COLOR_LIGHTGREEN);
                printf("%s\n\n",cancion);

                printf(" - ");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\nNo se encontro la cancion a buscar\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La PlayList se encuentra vacia\n\n");
	}
    colorear(COLOR_LIGHTGRAY);
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
    char actualmusica[150];
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

                    strcpy(actualmusica ,actual->titulo);
                    //actual = actual->siguiente;
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

                if(actual->siguiente == NULL){
                    actual = primero;
                    strcpy(actualmusica,actual->titulo);
                    actual = actual->siguiente;
                }else{
                    
                actual = actual->siguiente;
                strcpy(actualmusica ,actual->titulo);
                }
                break;

            case 3:
                if(actual->atras == NULL){
                    
                    actual = ultimo;
                    strcpy(actualmusica,actual->titulo);
                    actual = actual->atras;
                }else{
                    actual = actual->atras;
                    strcpy(actualmusica ,actual->titulo);
                }
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

int totalCanciones(){

    Nodo * actual;
    actual = primero;
    int i = 0;
    while(actual != NULL){
        i++;
        actual = actual->siguiente;
    }

    return i;
}

void eliminarCancionPorTitulo(){
    
	Nodo* actual = (Nodo*)malloc(sizeof(Nodo));
	actual = primero;
	Nodo* anterior = (Nodo*)malloc(sizeof(Nodo));
	anterior = NULL;
	char nodoBuscado[150];
    int encontrado = 0;

    printf("\nCanciones Actuales -> %i\n\n",totalCanciones());

	printf("Ingrese el titulo de la cancion a Buscar para Eliminar : ");
    fflush(stdin);
	gets(nodoBuscado);
    textoAmayus(nodoBuscado);
    char cancion[150];
    char album[150];
    char artista[150];

	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			//actual->dato == nodoBuscado
			if(strcmp(actual->titulo,nodoBuscado)==0){
				
                strcpy(cancion,actual->titulo);
                fflush(stdin);
                strcpy(album,actual->nombreAlbum);
                fflush(stdin);
                strcpy(artista,actual->artista);
                fflush(stdin);

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

                colorear(COLOR_LIGHTRED);
                printf("\t\t%s",album);

                printf(" - ");

                colorear(COLOR_LIGHTCYAN);
                printf("%s",artista);


                printf(" - ");

                colorear(COLOR_LIGHTGREEN);
                printf("%s\n\n",cancion);

                printf(" - ");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\nNo se encontro la cancion a buscar\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La PlayList se encuentra vacia\n\n");
	}
    colorear(COLOR_LIGHTGRAY);
    system("pause");
}

void menuOrdenar(){
    system("cls");
    printf("\n\n\t\t[ MENU DE ORDENAMIENTO ]\n\n");
    printf("[1]. Ordenar por Anio\n");
    printf("[2]. Ordenar por ID\n");
    printf("[3]. Ordenar por Album\n");
    printf("[4]. Ordenar por titulo\n");
    printf("[5]. Salir\n\n");
    printf("[?]. Ingresa una opcion : ");
}

void textoAmayus(char cadena[]){

    char c;
    int i;
    
    for(i = 0; i < strlen(cadena); i++){
        
        if(isalpha(cadena[i])){
            
            if(islower(cadena[i])){
                cadena[i] = toupper(cadena[i]);
            }
        }
    }

}

void structAmayus(){

    int i;
    char c;

    Nodo *nuevo;

    nuevo = primero;


    while(nuevo != NULL){

        for(i = 0; i < strlen(nuevo->nombreAlbum); i++){

            if(isalpha(nuevo->nombreAlbum[i])){
                
                if(islower(nuevo->nombreAlbum[i])){
                    nuevo->nombreAlbum[i] = toupper(nuevo->nombreAlbum[i]);
                }
            }
        }

        nuevo = nuevo->siguiente;
    }


    nuevo = primero;

    while(nuevo != NULL){

        for(i = 0; i < strlen(nuevo->titulo); i++){

            if(isalpha(nuevo->titulo[i])){
                
                if(islower(nuevo->titulo[i])){
                    nuevo->titulo[i] = toupper(nuevo->titulo[i]);
                }
            }
        }

        nuevo = nuevo->siguiente;
    }

    nuevo = primero;

    while(nuevo != NULL){

        for(i = 0; i < strlen(nuevo->artista); i++){

            if(isalpha(nuevo->artista[i])){
                
                if(islower(nuevo->artista[i])){
                    nuevo->artista[i] = toupper(nuevo->artista[i]);
                }
            }
        }

        nuevo = nuevo->siguiente;
    }
}