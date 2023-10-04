#include <iostream>
#include <windows.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo* siguiente;
} *primero;

void insertarNodo(int );
void vaciarPila(int &);

int main(){

    int i,x;
    int max = 22;

    cout<<"\n***LLENANDO PILA***\n\n";
    for(i = 1; i <= max; i++){
        if(i % 3 == 0){
            insertarNodo(i);
        }
    }

    cout<<"\n***VACIANDO PILA***\n\n";
    while(primero != NULL){
        vaciarPila(x);
    }

    cout<<"\n";
    system("pause");
	return 0;
}


void insertarNodo(int x){
	Nodo* nuevo = new Nodo();

	nuevo->dato = x;
	
	nuevo->siguiente = primero;
	primero = nuevo;
	
	cout <<" Se ha Insertado en la pila el numero "<<x<<endl;
}

void vaciarPila(int &n){
    Nodo *aux = primero;
    n = aux->dato;

    primero = aux->siguiente;
    delete aux;

    cout<<"Se ha sacado de la pila el valor : "<<n<<endl;
}