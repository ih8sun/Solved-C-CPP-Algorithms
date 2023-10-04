//ARBOL BINARIO//BUSCANDO ELEMENTOS EN COMUN ENTRE DOS ARBOLES BINARIOS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#define max_size 100
using namespace std;

struct Nodo1
{
    int dato;
    Nodo1 *derecha;
    Nodo1 *izquierda;
};

struct Nodo2
{
    int dato;
    Nodo2 *derecha;
    Nodo2 *izquierda;
};

typedef struct Nodo1 *Arbol1;
typedef struct Nodo2 *Arbol2;

//FUNCION PARA CREAR UN NUEVO NODO PARA ARBOL 1
Nodo1 *crearNodo1(int n)
{
    Nodo1 *nuevo_nodo = new Nodo1();
    nuevo_nodo->dato = n;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;

    return nuevo_nodo;
}

//FUNCION PARA CREAR UN NUEVO NODO PARA ARBOL 2
Nodo2 *crearNodo2(int n)
{
    Nodo2 *nuevo_nodo = new Nodo2();
    nuevo_nodo->dato = n;
    nuevo_nodo->derecha = NULL;
    nuevo_nodo->izquierda = NULL;

    return nuevo_nodo;
}

//FUNCION PARA ALMACENAR EN EL ARBOL 1
void insertarNodo1(Nodo1 *&arbol1, int n)
{
    if (arbol1 == NULL)
    {
        Nodo1 *nuevo_nodo = crearNodo1(n); //el *nuevo_nodo es un apuntador que apunta a la funcion crear nodo
        arbol1 = nuevo_nodo;
    }
    else
    {
        int valorRaiz = arbol1->dato;
        if (n == valorRaiz)
        {
            return;
        }
        if (n < valorRaiz)
        {
            insertarNodo1(arbol1->izquierda, n);
        }
        else
        {
            insertarNodo1(arbol1->derecha, n);
        }
    }
}

//FUNCION PARA MOSTRAR ARBOL 1
void mostrarArbol1(Nodo1 *arbol1, int contador)
{
    if (arbol1 == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol1(arbol1->derecha, contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "   ";
        }
        cout << arbol1->dato << endl;
        mostrarArbol1(arbol1->izquierda, contador + 1);
    }
}

//FUNCION PARA ALMACENAR EN EL ARBOL 2
void insertarNodo2(Nodo2 *&arbol2, int n)
{
    if (arbol2 == NULL)
    {
        Nodo2 *nuevo_nodo = crearNodo2(n); //el *nuevo_nodo es un apuntador que apunta a la funcion crear nodo
        arbol2 = nuevo_nodo;
    }
    else
    {
        int valorRaiz = arbol2->dato;
        if (n == valorRaiz)
        {
            return;
        }
        if (n < valorRaiz)
        {
            insertarNodo2(arbol2->izquierda, n);
        }
        else
        {
            insertarNodo2(arbol2->derecha, n);
        }
    }
}

//FUNCION PARA MOSTRAR ARBOL 2
void mostrarArbol2(Nodo2 *arbol2, int contador)
{
    if (arbol2 == NULL)
    {
        return;
    }
    else
    {
        mostrarArbol2(arbol2->derecha, contador + 1);
        for (int i = 0; i < contador; i++)
        {
            cout << "   ";
        }
        cout << arbol2->dato << endl;
        mostrarArbol2(arbol2->izquierda, contador + 1);
    }
}

void menu()
{
    Arbol1 arbol1 = NULL;     //inicializo arbol 1
    Arbol2 arbol2 = NULL;     //inicializo arbol2
    int dato1, dato2, opcion; //dato1 para arbol1 y dato2 para arbol2
    int contador = 0;
    int listaRepetidos[max_size];
    int i = 0, j = 0, iter = 0;

    bool igual = false;
    int tam1 = 0, tam2 = 0;
    int listaArbol1[max_size];
    int listaArbol2[max_size];
    int datoRepetido;

    do
    {
        cout << "\t.Menu Arbol Binario." << endl
             << endl;
        cout << "1. Insertar un nuevo nodo en Arbol 1" << endl;
        cout << "2. Insertar un nuevo nodo en Arbol 2" << endl;
        cout << "3. Mostrar el arbol 1 completo" << endl;
        cout << "4. Mostrar el arbol 2 completo" << endl;
        cout << "5. Mostrar Elementos en Comun entre los dos arboles" << endl;
        cout << "6. Salir" << endl;
        cout << endl;
        cout << "Opcion:  ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Digite el numero a guardar en Arbol 1: ";
            cin >> dato1;
            insertarNodo1(arbol1, dato1);
            cout << "\n";
            listaArbol1[i] = dato1;
            i++;
            system("pause");
            break;
        case 2:
            cout << "\nDigite numero a guardar en Arbol 2: ";
            cin >> dato2;
            insertarNodo2(arbol2, dato2);
            cout << "\n";
            listaArbol2[j] = dato2;
            j++;
            system("pause");
            break;
        case 3:
            cout << "\nMostrando el arbol 1:\n\n ";
            mostrarArbol1(arbol1, contador);
            cout << "\n";
            system("pause");
            break;
        case 4:
            cout << "\nMostrando el arbol 2:\n\n ";
            mostrarArbol2(arbol2, contador);
            cout << "\n";
            system("pause");
            break;
        case 5:
            if(i == j and i != 0 and j != 0){
                cout<<"\n\n\t\tCOMPARANDO ARBOLES\n\n";
                for(int x = 0; x < i; x++){
                    datoRepetido = listaArbol1[x];

                    for(int y = 0; y < j; y++){
                        if(datoRepetido == listaArbol2[y]){
                            listaRepetidos[iter] = datoRepetido;
                            iter++;
                            igual = true;
                        }
                    }
                }

            if(igual == true){
                for(int b = 0; b < iter; b++){
                    cout<<"\t"<<listaRepetidos[b];
                }
                cout<<"\n\nTotal de elementos Repetidos  ->  "<<iter<<endl<<endl;
            }else{
                cout<<"No se encontro ningun elemento igual..\n\n";
            }

            }else{
                cout<<"\n\nArboles con Diferentes Tamanio o valor 0..\n";
                cout<<"Tamanio..Arbol 1 -> "<<i<<endl;
                cout<<"Tamanio..Arbol 2 -> "<<j<<endl;
            }

            //Reiniciando Valores para un proximo ingreso
            for(int b = 0; b < max_size; b++){
                listaRepetidos[b] = 0;
            }
            iter = 0;

            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 6);
}

int main()
{   

    menu();
    return 0;
    system("pause");
}