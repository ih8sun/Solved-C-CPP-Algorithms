#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <cstring>

#define ASCENDENTE 1
#define DESCENDENTE 0

typedef struct _nodo {
   int valor;
   char nombre[20]; //deberia de aceptar un nombre
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v, char nom);
void Borrar(Lista *l, int v);
bool BuscarIzq(Lista&, int, int&);
bool BuscarDer(Lista&, int, int&);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);

int main() {
   Lista lista = NULL;
   pNodo p;
   int opcion = 0;
   int opcion2 = 0;
   int v,n,pos;
   string nom;
   bool r;
   
   do {
   		printf("\n1.- Insertar elemento en la lista.");
        printf("\n2.- Listar elementos de la lista.");
        printf("\n3.- Buscar elemento en la lista (Izquierda a derecha).");
        printf("\n4.- Buscar elemento en la lista (Derecha a izquierda).");
        printf("\n5.- Borrar elemento de la lista.");
        printf("\n0.- Salir del programa.");
        printf("\n=====================================");
        printf("\nOpcion ...: ");
        scanf(" %d",&opcion);
        switch(opcion) {
        	case 1:
        		system("cls");
				printf("Teclee el numero de valores que desea ingresar: ");
        		scanf("%i", &n);
                for(int i=0;i<n;i++) {
                	printf("\n\nIngrese la edad: ");
                	scanf("%i", &v);
                	fflush(stdin);
                	printf("\nIngrese el nombre: ");
                	scanf("%c", &nom);
                	 fflush( stdin );
                	Insertar(&lista, v, nom);
				}
				/*Insertar(&lista, 20);
   				Insertar(&lista, 10);
   				Insertar(&lista, 40);
   				Insertar(&lista, 30);*/
               break;

          case 2:
          	   system("cls");
               MostrarLista(lista, ASCENDENTE);
   			   MostrarLista(lista, DESCENDENTE);
               break;
            
          case 3:
          	   system("cls");
          	   printf("Ingrese valor a buscar: ");
         	   scanf("%i", &v);
         	   r = BuscarIzq(lista,v,pos);
         	   if(r==true) {
					printf("El valor buscado es: %i", v);
          			printf("\nPosicion: %i", pos);
          			getch();
          		} else {
				  	printf("Valor buscado es: %i", v);
          			printf("\nPosicion no encontrada");
          		}
         	   break;
         	   
          case 4:
          	   system("cls");
          	   printf("Ingrese valor a buscar: ");
         	   scanf("%i", &v);
         	   r = BuscarDer(lista,v,pos);
         	   if(r==true) {
					printf("El valor buscado es: %i", v);
          			printf("\nPosicion: %i", pos);
          			system("pause");
          		} else {
				  	printf("Valor buscado es: %i", v);
          			printf("\nPosicion no encontrada");
          		}
         	   break;
               
          case 5:
               printf("\n(0) Volver Menu Anterior.");
               printf("\n(1) Borrar");
               printf("\n.... ");
               scanf(" %d",&opcion2);

               switch(opcion2) {

                 case 1:

                      printf("Ingrese el valor que desea eliminar: ");
                      scanf("%i", &v);
                      Borrar(&lista, v);
					  /*Borrar(&lista, 10);
                      Borrar(&lista, 15);
                      Borrar(&lista, 45);
                      Borrar(&lista, 30);*/
                      break;
               }
               break;
        }
    } while(opcion!=0);
  system("PAUSE");
  BorrarLista(&lista);
  
  return 0;
}

void Insertar(Lista *lista, int v, char nom) {
   pNodo nuevo, actual;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   nuevo->nombre[20]= nom;

   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
   /* Si la lista está vacía o el primer miembro es mayor que el nuevo */
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(actual->siguiente &&actual->siguiente->valor <= v)
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void Borrar(Lista *lista, int v) {
   pNodo nodo;

   /* Buscar el nodo de valor v */
   nodo = *lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v) return;

   /* Borrar el nodo */
   /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if(nodo == *lista)
     if(nodo->anterior) *lista = nodo->anterior;
     else *lista = nodo->siguiente;

   if(nodo->anterior) /* no es el primer elemento */
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) /* no es el último nodo */
      nodo->siguiente->anterior = nodo->anterior;
   free(nodo);
}

bool BuscarIzq(Lista &lista, int v, int&pos) { //Falla dependiendo de los valores que se ingresen
	pNodo nodo = lista;
    pos=0;
    while(nodo!=NULL) {
    	if(nodo->valor==v) {
    		return true;
		}
    	nodo = nodo->siguiente;
    	pos++;
    }
    return false;
}

bool BuscarDer(Lista &lista, int v, int&pos) { //Esta fallando xd
	pNodo aux = lista;
	pNodo ultimo = lista;
    pos=0;
    if(aux->siguiente==NULL) {
    	ultimo = aux;
    }
    while(ultimo!=NULL) {
    	if(ultimo->valor==v) {
    		return true;
		}
    	ultimo = ultimo->siguiente;
    	pos++;
    }
    return false;
}

void BorrarLista(Lista *lista) {
   pNodo nodo, actual;

   actual = *lista;
   while(actual->anterior) actual = actual->anterior;

   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      free(nodo);
   }
   *lista = NULL;
}

void MostrarLista(Lista lista, int orden) {
   pNodo nodo = lista;

   if(!lista) printf("Lista vacía");

   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      printf("Orden ascendente: ");
      while(nodo) {
         printf("%d %c  ->  ", nodo->valor,nodo->nombre);
         nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      printf("Orden descendente: ");
      while(nodo) {
         printf("%d %c  ->  ", nodo->valor,nodo->nombre);
         nodo = nodo->anterior;
      }
   }

   printf("\n");
}
