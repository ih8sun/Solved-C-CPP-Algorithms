#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};

void push(nodo *&p, int valor )
{
     nodo * aux;
     aux = new(struct nodo);  
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
}

void pop( nodo *&p )
{
     int num ;
     nodo *aux;
     
     aux = p ;
     num = aux->nro; 
     
     p = aux->sgte ;
     delete(aux);
     
}

void mostrar_pila( nodo *p )
{
     nodo* aux;
     aux = p;
     
     while( aux !=NULL )
     {
            cout<<"\t"<< aux->nro <<endl;
            aux = aux->sgte;
     }    
}

int main(){

    cout<<"\n\n\t\t[ INGRESO DE DATOS A PILA ]\n\n";
    nodo *pila = NULL;
    nodo *pila2 = NULL;
    int i;


    for(i = 1; i < 100; i++){

        if(i % 2 == 0){
            if(i % 6 == 0){
                pop(pila);
            }else{
                push(pila,i);
            }   
        }else{
            if(i % 7 == 0){
                pop(pila2);
            }else{
                push(pila2,i);
            }
        }

    }

    cout<<"\nMUESTRA DE PILA [1]\n\n";
    mostrar_pila(pila);

    cout<<"\nMUESTRA DE PILA [2]\n\n";
    mostrar_pila(pila2);
    
    return 0;
}