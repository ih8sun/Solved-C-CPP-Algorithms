#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct nodo{

    int DNI;
    string telefono;
    string nombre;
    int edad;
    nodo *hoja_izq;
    nodo *hoja_der;
    nodo *Padre;

};

void agregar_hoja(nodo *&, int ,string ,string ,int ,nodo *);
void en_orden(nodo *&);
void mostrar_arbol(nodo *&,int);
bool comprobar(nodo *,int );
void eliminarNodo(nodo *&,int );
nodo* reparararHoja(nodo *, nodo *);

void menu()
{
    system("cls");
    cout << "\n\n\t[ LISTA DE CONTACTOS -> FILA A ] \n\n";
    cout<<" [1]. Agregar Contacto\n";
    cout<<" [2]. Eliminar Contacto\n";
    cout<<" [3]. Mostrar en-Orden\n";
    cout<<" [4]. Mostrar Arbol de Edades\n [5]. Salir\n\n";
    cout<<" [?]. Ingresa opcion : ";
}

int main(){

    bool salir;
    int opc;
    bool correcto = false;
    nodo *raiz = new nodo();
    raiz = NULL;
    int auxDNI,auxEdad;
    string auxTelf,auxNombre;



    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            
            cout<<"\n\n\t\t[ Ingreso de Datos ]\n\n";

            do{ 
            cout<<"\nIngresa DNI : ";
            cin>>auxDNI;

            if(comprobar(raiz,auxDNI)){
                correcto = false;
                cout<<"Este DNI ya ha sido ingresado\n";
            }else{
                correcto = true;
            }   
            }while(!correcto);
            
            
            cout<<"Ingresa nombre : ";
            fflush(stdin);
            getline(cin,auxNombre);

            cout<<"Ingresa Telefono : ";
            fflush(stdin);
            cin>>auxTelf;

            cout<<"Ingresa Edad : ";
            cin>>auxEdad;

            agregar_hoja(raiz,auxDNI,auxTelf,auxNombre,auxEdad,NULL);
            cout<<endl;
            system("pause");
        break;
        
        case 2:
            cout<<"Ingresa DNI a eliminar : ";
            cin>>auxDNI;
            eliminarNodo(raiz,auxDNI);   
            break;

        case 3:
            cout<<endl;
            en_orden(raiz);
            cout<<endl;
            system("pause");
            break;
        
        case 4:
            system("cls");
            cout<<"MOSTRANDO ARBOL\n\n";

            mostrar_arbol(raiz,0);
            cout<<endl;
            system("pause");
            break;
        
            break;
        case 5:
            salir = true;
            break;
        }


    }while(!salir);


    return 0;
}

void agregar_hoja(nodo *&raiz,int dni,string tlf,string nmb,int ed,nodo *padre)
{

    if (raiz == NULL)
    {
        nodo *tmp = new nodo;
        tmp->DNI = dni;
        tmp->edad = ed;
        tmp->nombre = nmb;
        tmp->telefono = tlf;
        tmp->hoja_izq = NULL;
        tmp->hoja_der = NULL;
        tmp->Padre = padre;
        raiz = tmp;
    }
    else
    {
        if (raiz->DNI < dni)
        {
            agregar_hoja(raiz->hoja_der, dni,tlf,nmb,ed,padre);
        }
        else
        {
            if (raiz->DNI > dni)
                agregar_hoja(raiz->hoja_izq,dni,tlf,nmb,ed,padre);
        }
    }
}

void en_orden(nodo *&raiz)
{
    if (raiz != NULL)
    {
        en_orden(raiz->hoja_izq);
        cout << raiz->DNI << " - "<<raiz->telefono << " - "<<raiz->nombre << " - "<<raiz->edad<<endl;
        en_orden(raiz->hoja_der);
    }
}



void mostrar_arbol(nodo *&raiz, int n)
{

    if (raiz != NULL)
    {
        mostrar_arbol(raiz->hoja_der, n + 1);
        for (int i = 0; i < n; i++)
        {
            cout << "  ";
        }
        cout << raiz->edad << endl;
        mostrar_arbol(raiz->hoja_izq, n + 1);
    }
}

bool comprobar(nodo *raiz,int DNI){

    if(raiz == NULL){
        return false;
    }else if(raiz->DNI == DNI){
        return true;
    }else if(DNI < raiz->DNI){
        return comprobar(raiz->hoja_izq,DNI);
    }
    else{
        return comprobar(raiz->hoja_der,DNI);
    }

}

nodo* reparararHoja(nodo *izq, nodo *der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    nodo* centro = reparararHoja(izq->hoja_der, der->hoja_izq);
    izq->hoja_der = centro;
    der->hoja_izq = izq;
    return der;
}

void eliminarNodo(nodo *&arbol,int x){

    if(arbol==NULL) return;

    if(x<arbol->DNI)
        eliminarNodo(arbol->hoja_izq, x);

    else if(x >arbol->DNI)
        eliminarNodo(arbol->hoja_der, x);

    else
    {
        nodo *p = arbol;
        arbol = reparararHoja(arbol->hoja_izq, arbol->hoja_der);
        delete p;
    }

}