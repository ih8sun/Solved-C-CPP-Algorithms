 #include <iostream>
 #include <stdlib.h>
using namespace std;

struct nodo{
    int nro;
    struct nodo *sgte;
};
 
struct cola{
    nodo *frente;
    nodo *atras  ;
};

void encolar(cola &q, int valor ){
      nodo *aux = new(nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.frente == NULL)
         q.frente = aux;
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;  
     
}

int desencolar( struct cola &q ){
     int num ;
     struct nodo *aux ;
     
     aux = q.frente; 
     num = aux->nro;
     q.frente = (q.frente)->sgte;
     delete(aux);        
     
     return num;
}

void muestraCola( struct cola q ){
     struct nodo *aux;
     
     aux = q.frente;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}

void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.frente != NULL)
     {
            aux = q.frente;
            q.frente = aux->sgte;
            delete(aux);
     }
     q.frente = NULL;
     q.atras   = NULL;
     
}

struct nodoDePila{
    int nro;
    struct nodo *sgte;
};

void pushPila(nodo *&p, int valor )
{
     nodo * aux;
     aux = new(struct nodo);  
     aux->nro = valor;
     
     aux->sgte = p ;
     p = aux ;
}

void invertirCola( nodo *p, struct cola &Cola)
{
     nodo* aux;
     aux = p;
     
     while( aux !=NULL )
     {
            encolar(Cola,aux->nro);
            aux = aux->sgte;
     }    
}


int main(){

    struct cola Cola;
    nodo *pila = NULL;
    Cola.frente = NULL;
    Cola.atras   = NULL;

    encolar(Cola,5);
    pushPila(pila,5);

    encolar(Cola,6);
    pushPila(pila,6);

    encolar(Cola,7);
    pushPila(pila,7);

    encolar(Cola,9);
    pushPila(pila,9);

    encolar(Cola,10);
    pushPila(pila,10);

    cout<<"\n\n\t\t[ COLA NORMAL ]\n\n";
    muestraCola(Cola);
    cout<<"\n";
    vaciaCola(Cola);
    invertirCola(pila,Cola);

    system("pause");
    
    cout<<"\n\n\t\t[ COLA INVERTIDA ]\n\n";
    muestraCola(Cola);
    return 0;
}