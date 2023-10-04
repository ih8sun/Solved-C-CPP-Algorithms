#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>

#define AZUL 1
#define NEGRO 0
#define VERDE	2
#define CELESTE 3
#define ROJO 4
#define NARANJA 14
#define AMARILLO 6
#define BLANCO 7

using namespace std;

void colorear(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

struct nodo{

    string fecha;
    string cod_hospital;
    string numero_de_cama;
	nodo* siguiente;
} *primero, *ultimo;

struct listaSinDuplicar{

    string fechaSD;
    string cod_hospitalSD;
    string numero_de_camaSD;
	listaSinDuplicar* siguienteSD;

}*primeroListaNueva,*ultimoListaNueva;



void insertarNodo();
void desplegarLista();
nodo lineToStruct(string );
void leeProcesa(ifstream &);
void nuevaListaSinDuplicados();
void insertarListaAuxDuplicado(listaSinDuplicar * );
void imprimirListaCamas();
void camasOcupadas();

void menu(){
    system("cls");
    colorear(BLANCO);
    cout<<"\n\n\t\t[ MINISTERIO DE SALUD MENU ]\n\n";
    cout<<"[1]. Crear Lista desde Archivo\n";
    cout<<"[2]. Crear Lista sin Duplicados\n";
    cout<<"[3]. Crear Lista de un Hospital\n";
    cout<<"[4]. Mostrar Estadisticas de numero de Camas por Hospital\n";
    cout<<"[5]. Cantidad de Camas ocupadas por fecha especificada\n";
    cout<<"[6]. Eliminar Registros de camas de un Hospital\n";
    cout<<"[7]. Salir\n";
    cout<<"\n[-]. Ingresa una opcion : ";

}

int main(){

    bool salir = false;
    int opc;
    ofstream archivo;
    ifstream archivoLectura;
    string texto;
    archivo.open("camas_ocupadas.csv",ios::app);


    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            leeProcesa(archivoLectura);
            desplegarLista();
            break;

        case 2:
            nuevaListaSinDuplicados();
            break;

        case 3:
            break;
        case 4:
            imprimirListaCamas();
            break;
        case 5:
            camasOcupadas();
            break;
        case 6:
            break;
        case 7:
            salir = true;
            break;        
        }
    
    }while(salir != true);



    return 0;
}

void insertarNodo(){
	nodo* nuevo = new nodo();
	
	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}

void insertarListaAuxDuplicado(listaSinDuplicar *n){

	listaSinDuplicar* nuevo = new listaSinDuplicar();
    nuevo = n;
	
	if(primeroListaNueva == NULL){
		primeroListaNueva = ultimoListaNueva;
		primeroListaNueva->siguienteSD = NULL;
		ultimoListaNueva = nuevo;
	}else{
		ultimoListaNueva->siguienteSD = nuevo;
		nuevo->siguienteSD = NULL;
		ultimoListaNueva = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}

void desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
    int i = 0;
	if(primero != NULL){
		
		while(actual != NULL){
            
            colorear(VERDE);
            cout<<i++;
            colorear(NEGRO);
            cout<<" - ";
            colorear(ROJO);
			cout<<actual->fecha;
            colorear(NEGRO);
            cout<<" - ";
            colorear(BLANCO);
            cout<<actual->cod_hospital;
            colorear(NEGRO);            
            cout<<" - ";
            colorear(CELESTE);
            cout<<actual->numero_de_cama<<endl;
			actual = actual->siguiente;
            
		}
		
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}

    cout<<"\n\n";
    colorear(BLANCO);
    system("pause");
}

void leeProcesa(ifstream &miArchivo){

    miArchivo.open("camas_ocupadas.csv",ios::app);
    string texto;
    int lineas = 0;
    //nodo* nuevo = new nodo();

    while(!miArchivo.eof()){

        nodo* nuevo = new nodo();
            
            getline(miArchivo,texto);
            *nuevo = lineToStruct(texto);

            if(primero == NULL){
                primero = nuevo;
                primero->siguiente = NULL;
                ultimo = nuevo;
            }else{
                ultimo->siguiente = nuevo;
                nuevo->siguiente = NULL;
                ultimo = nuevo;
            }
    }
}

nodo lineToStruct(string texto){

    char *cad;
    strcpy(cad,texto.c_str());

    int nElementos=0,count=1;
    int tam=strlen(cad);
    nodo herramienta;
    char *aux,*ptr,delim[]=",";
    
    for(int i=0;i<tam;i++)
        if(cad[i]==',')
            nElementos++;
    ptr=strtok(cad,delim);

    //CHAR//strcpy(herramienta.fecha,ptr);
    //INT//herramienta.fecha = atoi(ptr);
    stringstream ss1;
    stringstream ss2;
    stringstream ss3;
    ss1<<ptr;

    ss1>>herramienta.fecha;

    while((ptr=strtok(NULL,delim))!=NULL)
    {
        if(count==1){
            //herramienta.cod_hospital=atoi(ptr);
            ss2<<ptr;
            ss2>>herramienta.cod_hospital;
        }else if(count==2){
            //herramienta.numero_de_cama=atoi(ptr);
            ss3<<ptr;
            ss3>>herramienta.numero_de_cama;
        }
        count++;
    }
    return herramienta;

}

void nuevaListaSinDuplicados(){

    //NODO CON DATOS REPETIDOS
    nodo *actual = new nodo(); 
    actual = primero;

    //NODO NUEVO
    listaSinDuplicar *nuevo = new listaSinDuplicar();
    int i = 0,j,k;
    int tam = 0;

    while(actual != NULL){
        tam++;
        actual = actual->siguiente;
        //cout<<i<<endl;
    }

    int x = 0;
    string array[tam];
    string texto = "";


    actual = primero;

    while(actual != NULL){

        texto = "";
        texto.append(actual->fecha);
        texto.append(actual->cod_hospital);
        texto.append(actual->numero_de_cama);
        array[x] = texto;
        cout<<x<<" - "<<array[x]<<endl;
        x++;


        actual = actual->siguiente;
    }



    system("pause");
}   

void imprimirListaCamas(){

    nodo *actual = new nodo();
    string cod;
    actual = primero;
    int i = 0;
    cout<<"\n\n\t\t[ IMRIMIENDO HOSPITALES ]\n\n";

    cout<<"Ingrese algun codigo de Hospital : ";
    fflush(stdin);
    getline(cin,cod);

    cout<<"\n\n\t\t[ LECTURA DE DATOS ]\n\n";
    while(actual != NULL){
        if(actual->cod_hospital.compare(cod)==0){
            colorear(VERDE);
            cout<<i++;
            colorear(NEGRO);
            cout<<" - ";
            colorear(ROJO);
			cout<<actual->fecha;
            colorear(NEGRO);
            cout<<" - ";
            colorear(BLANCO);
            cout<<actual->cod_hospital;
            colorear(NEGRO);            
            cout<<" - ";
            colorear(CELESTE);
            cout<<actual->numero_de_cama<<endl;
        }

        actual = actual->siguiente;
    }

    cout<<"\n\n";
    system("pause");
}

void camasOcupadas(){

    nodo *actual = new nodo();

    actual = primero;
    string texto;
    int i = 0;
    cout<<"Ingresa una fecha (aaaammdd) : ";
    fflush(stdin);
    getline(cin,texto);

    cout<<"\n\n\t\t[ MOSTRANDO FECHAS ]\n\n";
    while(actual != NULL){
        if(actual->fecha.compare(texto)==0){

            colorear(VERDE);
            cout<<i++;
            colorear(NEGRO);
            cout<<" - ";
            colorear(ROJO);
			cout<<actual->fecha;
            colorear(NEGRO);
            cout<<" - ";
            colorear(BLANCO);
            cout<<actual->cod_hospital;
            colorear(NEGRO);            
            cout<<" - ";
            colorear(CELESTE);
            cout<<actual->numero_de_cama<<endl;

        }


        actual = actual->siguiente;
    }
    cout<<"\n\nNumero de camas : "<<i<<endl<<endl;
    system("pause");

}