#include <iostream>
#include <stdlib.h>


using namespace std;

struct nodo
{
    int dato;
    nodo *hoja_izq;
    nodo *hoja_der;
};

void agregar_hoja(nodo *&, int);
void mostrar_arbol(nodo *&, int);
void en_orden(nodo *&);
void pre_orden(nodo *&);
void post_orden(nodo *&);
int mayorHoja(nodo *&);

void menu()
{
    system("cls");
    cout << "\n\n\t[ ARBOL BINARIO ]\n\n";
    cout << "[1]. Agregar\n";
    cout << "[2]. Mostrar Arbol\n";
    cout << "[3]. En orden\n";
    cout << "[4]. Pre Orden\n";
    cout << "[5]. Post Orden\n";
    cout << "[6]. Numero Mayor\n";
    cout << "[7]. Salir\n";
    cout << "\n[?]. Ingresar opcion -> ";
}

int main()
{

    nodo *raiz = new nodo();
    raiz = NULL;
    bool salir = false;
    int opc, dato;
    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "\nIngresa numero : ";
            cin >> dato;
            agregar_hoja(raiz, dato);

            break;

        case 2:
            cout << endl;
            mostrar_arbol(raiz, 0);

            break;

        case 3:
            cout << endl;
            en_orden(raiz);
            break;

        case 4:
            cout << endl;
            pre_orden(raiz);
            break;

        case 5:
            cout << endl;
            post_orden(raiz);
            break;

        case 6:
            cout<<"El Numero mayor en el arbol es : "<<mayorHoja(raiz)<<endl;
            break;

        case 7:
            salir = true;
            break;
        }
        cout << endl;
        system("pause");
    } while (!salir);
    return 0;
}

void agregar_hoja(nodo *&raiz, int dato)
{

    if (raiz == NULL)
    {
        nodo *tmp = new nodo;
        tmp->dato = dato;
        tmp->hoja_izq = NULL;
        tmp->hoja_der = NULL;
        raiz = tmp;
    }
    else
    {
        if (raiz->dato < dato)
        {
            agregar_hoja(raiz->hoja_der, dato);
        }
        else
        {
            if (raiz->dato > dato)
                agregar_hoja(raiz->hoja_izq, dato);
        }
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
        cout << raiz->dato << endl;
        mostrar_arbol(raiz->hoja_izq, n + 1);
    }
}

void en_orden(nodo *&raiz)
{
    if (raiz != NULL)
    {
        en_orden(raiz->hoja_izq);
        cout << raiz->dato << " ";
        en_orden(raiz->hoja_der);
    }
}

void pre_orden(nodo *&raiz)
{
    
    if (raiz != NULL)
    {
        cout << raiz->dato << " ";
        en_orden(raiz->hoja_izq);
        en_orden(raiz->hoja_der);
    }
}

void post_orden(nodo *&raiz)
{
    if (raiz != NULL)
    {
        post_orden(raiz->hoja_izq);
        post_orden(raiz->hoja_der);
        cout << raiz->dato << " ";
    }
}

int mayorHoja(nodo *&raiz)
{   
    nodo *temp;
    temp = NULL;
    temp = raiz;

    int mayor;
    while (temp->hoja_der != NULL)
        temp = temp->hoja_der;
    mayor = temp->dato;
    return mayor;
}