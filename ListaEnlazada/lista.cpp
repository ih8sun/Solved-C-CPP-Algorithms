#include <iostream>
#include <stdlib.h>

using namespace std;

class Nodo
{

public:
    int dato;
    Nodo *siguiente;
    Nodo(int dato)
    {
        this->dato = dato;
        this->siguiente = NULL;
    }
};

class Lista
{

private:
    void agregarRecursivo(Nodo *n, int dato)
    {
        if (n->siguiente == NULL)
        {
            n->siguiente = new Nodo(dato);
        }
        else
        {
            this->agregarRecursivo(n->siguiente, dato);
        }
    }

    void imprimirRecursivo(Nodo *n)
    {
        if (n != NULL)
        {
            std::cout << "Tenemos " << n->dato << std::endl;
            this->imprimirRecursivo(n->siguiente);
        }
    }

    void eliminarRecursivo(Nodo *n, int dato)
    {
        if (n == NULL)
        {
            return;
        }
        if (n->dato == dato && n == this->cabeza)
        {
            Nodo *temporal = this->cabeza;
            if (this->cabeza->siguiente != NULL)
            {
                this->cabeza = this->cabeza->siguiente;
                delete temporal;
            }
            else
            {
                this->cabeza = NULL;
            }
            return;
        }
        if (n->siguiente != NULL && n->siguiente->dato == dato)
        {
            Nodo *temporal = n->siguiente;
            if (n->siguiente != NULL)
            {
                n->siguiente = n->siguiente->siguiente;
            }
            delete temporal;
        }
        else
        {
            this->eliminarRecursivo(n->siguiente, dato);
        }
    }
    bool existeRecursivo(Nodo *n, int dato)
    {
        if (n == NULL)
        {
            return false;
        }
        if (n->dato == dato)
        {
            return true;
        }
        return this->existeRecursivo(n->siguiente, dato);
    }

public:
    Nodo *cabeza;
    void copiaSinDuplicados(Lista *l)
    {
        Nodo *temporal = this->cabeza;
        while (temporal != NULL)
        {
            if (!l->existe(temporal->dato))
            {
                l->agregar(temporal->dato);
            }
            temporal = temporal->siguiente;
        }
    }
    void eliminar(int dato)
    {
        this->eliminarRecursivo(this->cabeza, dato);
    }
    void agregar(int dato)
    {
        if (this->cabeza == NULL)
        {
            this->cabeza = new Nodo(dato);
        }
        else
        {
            this->agregarRecursivo(this->cabeza, dato);
        }
    }
    void imprimir()
    {
        std::cout << "Imprimiendo " << std::endl;
        this->imprimirRecursivo(this->cabeza);
    }
    bool existe(int dato)
    {
        return this->existeRecursivo(this->cabeza, dato);
    }
};


void quicksort(Nodo ** begin, Nodo ** end) // actual sort function
{
    if (*begin == *end)
        return;

    Nodo * pivot = *begin;
    Nodo * temp = *begin;
    temp = temp->siguiente; // for pointing to next element

    while (temp != *end)
    {
        if (temp->data < pivot->dato)
        {
            Nodo * temp1 = *begin;  // swapping the two nodes if less than pivot
            *begin = temp;
            temp = temp->siguiente;
            (*begin)->siguiente = temp1;
        }
        else
            temp = temp->siguiente;
    }
    quicksort(begin,&pivot); // calling for remaining elements (first half)
    quicksort(&(pivot->siguiente),end); 
} 


int main(){

    Lista *l = new Lista();

    l->agregar(2);
    l->agregar(5);

    l->imprimir();


    return 0;
}