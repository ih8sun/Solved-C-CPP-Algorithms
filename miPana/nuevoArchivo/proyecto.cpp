#include <iostream>
#include <stdio.h>
#include <fstream>
#include <io.h>
#include <stdlib.h>
#include <direct.h>
#include <windows.h>
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

void menu()
{
    system("cls");
    colorear(VERDE);
    Sleep(60);
    cout << "\n\n\n\n\n\n\t\t\t\t[ MENU PRINCIPAL ]\n\n";
    Sleep(60);
    cout << "\t\t************************************************\n";
    Sleep(60);
    cout << "\n\t\t[1]. Crear Archivo\n";
    Sleep(60);
    cout << "\t\t[2]. Leer Archivo Especifico\n";
    Sleep(60);
    cout << "\t\t[3]. Consultar Contenido de Carpeta\n";
    Sleep(60);
    cout << "\t\t[4]. Modificar Archivo\n";
    Sleep(60);
    cout << "\t\t[5]. Renombrar Archivo\n";
    Sleep(60);
    cout << "\t\t[6]. Eliminar un Archivo\n";
    Sleep(60);
    cout << "\t\t[7]. Salir del Programa\n\n";
    colorear(ROJO);
    Sleep(60);
    cout << "\t\t************************************************\n\n";
    Sleep(60);
    cout << "\t\t[8]. Necesitas Ayuda ?\n";
    Sleep(60);
    cout << "\t\t[9]. Creador del Proyecto\n\n";
    Sleep(60);
    cout << "\t\t************************************************\n";
    colorear(BLANCO);
    Sleep(60);
    cout << "\n\t\t[?]. Ingresa una opcion : ";
}

void listaDir(char *carpeta)
{   
    colorear(AMARILLO);
    struct _finddata_t archivo;
    long listo = _findfirst("*.*", &archivo);
    
    cout<<"\n\n[ Archivos dentro de esta Carpeta ] \n\n";

    if (listo)
    {
        if (archivo.attrib == _A_SUBDIR)
            cout << "<DIR>" << archivo.name << endl;
            
        else
            cout << "-> " << archivo.name << endl;

        while (!_findnext(listo, &archivo))
        {
            if (archivo.attrib == _A_SUBDIR)
                cout << "<DIR>" << archivo.name << endl;
            else
                cout << "-> "  << archivo.name << endl;
        }
    }
    cout<<"\n";
}


void modificarArchivo(ofstream &,char []); 
void crearArchivo(ofstream &,char []);
void lecturaArchivo(ifstream &,char []);
void renombrar(char []);
void eliminar(char []);
void ayuda();
void acercaDe();

int main()
{

    //VARIABLE DE MENU
    bool salir = false;
    int opc;
    
    //MANEJO DE ARCHIVO
    char carpeta[50];
    ofstream archivoTexto;
    ifstream archivoTextoLectura;

    //VARIABLES STRINGS 
    string name,linea,txt,nuevo,antiguo;
    getcwd(carpeta,50);
    _chdir(carpeta);

    //variables contraErrores - DESPEDIDA
    int resultado;
    string adios = "GRACIAS POR USAR EL PROGRAMA";

    do
    {
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            system("cls");
            crearArchivo(archivoTexto,carpeta);
            break;

        case 2:
            system("cls");
            lecturaArchivo(archivoTextoLectura,carpeta);
            break;


        case 3:
            system("cls");
            colorear(VERDE);
            cout<<"\n\n\t\tCONSULTANDO....\n";
            listaDir(carpeta);
            cout<<endl;
            system("pause");
            break;
        case 4:
            system("cls");
            modificarArchivo(archivoTexto,carpeta);
            break;
        case 5:
            system("cls");
            renombrar(carpeta);

            break;
        case 6:
            system("cls");
            eliminar(carpeta);
            break;

        case 7:
            cout<<"\n\n\n\t\t\t";
            for(int i = 0; i < adios.length(); i++){
                colorear(VERDE);
                Sleep(60);
                cout<<adios[i];
            }
            cout<<"\n\n\n";
            salir = true;
            break;

        case 8:
            system("cls");
            ayuda();
            break;
        case 9:
            acercaDe();
            break;
        }

    } while (salir != true);

    return 0;
}


void modificarArchivo(ofstream &archivo,char carpeta[]){
    
    string nameAr,texto;
    int opc;


    cout<<"\n\n\t\tMODIFICACION DE ALGUN ARCHIVO\n\n";
    listaDir(carpeta);
    cout<<"Ingrese el nombre del archivo a modificar : ";
    fflush(stdin);
    getline(cin,nameAr);


    
    colorear(VERDE);
    cout<<"\n\t[ OPCIONES DE MODIFICACION ]\n\n";
    colorear(BLANCO);
    cout<<"[1]. Agregar Contenido\n";
    cout<<"[2]. Reemplazar Contenido\n";
    cout<<"[3]. Limpiar Archivo\n\n";
    cout<<"[?]. Ingresa opcion : ";
    cin>>opc;

    switch (opc)
    {
    case 1:

        archivo.open(nameAr.c_str(),ios::app);
        if(!archivo.fail()){
            cout<<"Ingresa texto a Agregar : ";
            fflush(stdin);
            getline(cin,texto);

            
            archivo<<texto<<endl;
            cout<<"[ CONTENIDO AGREGADO AL ARCHIVO ]\n";

        }else{
            cout<<"\nNo se encontro archivo a modificar..\n\n";
        }
        archivo.close();
        break;
    
    case 2:

        archivo.open(nameAr.c_str(),ios::out);
        if(!archivo.fail()){
            archivo.clear();
            cout<<"Ingresa texto a Agregar : ";
            fflush(stdin);
            getline(cin,texto);

            archivo<<texto<<endl;
            archivo.close();
            cout<<"[ CONTENIDO MODIFICADO AL ARCHIVO ]\n";
        }else{
            cout<<"\nNo se encontro archivo a modificar..\n\n";
        }
        archivo.close();
        break;

    case 3:
        archivo.open(nameAr.c_str(),ios::out);

        if(!archivo.fail()){
            archivo.clear();
            cout<<"[ SE HIZO LA LIMPIEZA AL ARCHIVO ]\n";
        }else{
            cout<<"\nNo se encontro archivo a modificar..\n\n";
        }
        archivo.close();
        break;
    
    default:
        cout<<"\nSe debio ingresar una opcion valida..\n";
        break;
    }

    system("pause");
} 

void crearArchivo(ofstream &archivoTexto,char carpeta[]){

    string name;


    cout<<"\n\n\t\t[ CREACION DE UN ARCHIVO TXT ]\n\n";
    listaDir(carpeta);

    colorear(BLANCO);

    cout<<"Ejemplo : nuevo.txt\n";
    cout<<"\nIngrese nombre de archivo : ";
    fflush(stdin);
    getline(cin,name);
    archivoTexto.open(name.c_str(),ios::out);

    cout<<"\n\n\t\t[ SE CREO EL TXT -> "<<name<<" ]\n\n";
    system("pause");
    archivoTexto.close();
}

void lecturaArchivo(ifstream &archivoTextoLectura,char carpeta[]){

    string name,linea;

    cout<<"\n\n\t\t[ LECTURA DE ARCHIVOS ]\n\n";
    listaDir(carpeta);
    
    colorear(BLANCO);
    cout<<"\nIngresa Nombre de archivo a leer : ";
    fflush(stdin);
    getline(cin,name);
    cout<<endl;
    archivoTextoLectura.open(name.c_str(),ios::in);

    if(archivoTextoLectura.fail()){
        cout<<"No se encontro ningun archivo TXT con el nombre -> "<<name<<endl;  
    }else{
        while(!archivoTextoLectura.eof()){
            getline(archivoTextoLectura,linea);
            cout<<linea<<endl;
        }
    }
    cout<<endl;
    archivoTextoLectura.close();
    system("pause");
    
}

void renombrar(char carpeta[]){

    string antiguo,nuevo;
    int resultado;

    cout<<"\n\n\t\t[ RENOMBRAR ARCHIVO ]\n\n";
    listaDir(carpeta);
    
    colorear(BLANCO);
    cout<<"\nEjemplo : antiguo.txt  |+| nuevo.txt";

    cout<<"\n\n\t[ RENOMBRANDO ]\n";
    cout<<"\nIngresa Nombre antiguo txt : ";
    fflush(stdin);
    getline(cin,antiguo);
    cout<<"Ingresa Nombre nuevo txt : ";
    fflush(stdin);
    getline(cin,nuevo);

    resultado = rename(antiguo.c_str(),nuevo.c_str());
    if(resultado == 0){
        cout<<"\nArchivo Renombrado Exitosamente!!\n";
    }else{
        cout<<"\nHubo un error al Renombrar el archivo\n";
    }

    cout<<endl;
    system("pause");
}

void eliminar(char carpeta[]){

    string txt;


    cout<<"\n\n\t\t[ ELIMINAR ALGUN ARCHIVO ]\n\n";
    listaDir(carpeta);
    
    colorear(BLANCO);
    cout<<"Ejemplo : nuevo.txt";
    cout<<"\nIngresa nombre de archivo a Eliminar : ";
    fflush(stdin);
    getline(cin,txt);
    if(remove(txt.c_str())!= 0){
        cout<<"No se encontro el documento\n";
    }else{
        cout<<"\t\tArchivo Eliminado Correctamente!!\n\n";
    }
    system("pause");

}

void ayuda(){

    colorear(BLANCO);
    cout<<"\n\n\t\t[ QUE HACE CADA FUNCION ? ] \n\n";
    
    colorear(VERDE);
    cout<<"Funcion -> Crear Archivo :\n";
    colorear(BLANCO);
    cout<<"La funcion que tiene es la de crear un archivo cualquiera\n";
    cout<<"Obviamente lo apropiado es que cree solo de tipo TXT\n";
    cout<<"Pero tambien soporta extensiones CPP/CSV\n";

    colorear(CELESTE);
    cout<<"\nFuncion -> Lectura de Archivo: \n";
    colorear(BLANCO);
    cout<<"La funcion que tiene es de leer desde la primera linea del archivo\n";
    cout<<"Hasta que encuentro un EOF que significa FINAL DEL ARCHIVO\n";

    colorear(ROJO);
    cout<<"\nFuncion -> Modificar Archivo\n";
    colorear(BLANCO);
    cout<<"Modificara el archivo a escoger(obviamente si existe) ya sea\n ";
    cout<<"Agregando texto al archivo, borrando todo e insertando nuevo texto\n";
    cout<<"o limpiando totalmente el archivo dejandolo sin ningun tipo de char\n";

    colorear(NARANJA);
    cout<<"\nFuncion -> Renombrar\n";
    colorear(BLANCO);
    cout<<"Renombra el archivo gracias a funciones de windows donde utilizaremos\n";
    cout<<"Un parametro antiguo (el nombre original) y uno nuevo\n";

    colorear(AMARILLO);
    cout<<"\nFuncion -> Eliminar\n";
    colorear(BLANCO);
    cout<<"Eliminar el archivo gracias a funciones de windows donde utilizaremos\n";
    cout<<"El nombre del archivo a eliminar, sino existe pues bota una alerta\n";

    colorear(AZUL);
    cout<<"\nFuncion -> ListaDir\n";
    colorear(BLANCO);
    cout<<"Funcion encargada de traer los documentos de la carpeta actual en donde\n";
    cout<<"Nos encontremos, aplicando una serie de comandos ofrecidos por Windows\n";

    colorear(VERDE);
    cout<<"\nEspero Puedas Comprender El Uso Del Programa :)\n\n";
    system("pause");

}

void acercaDe(){

  
    system("cls");
    colorear(VERDE);
    Sleep(60);
    cout << "\n\n\n\n\n\n\t\t\t\t[ AUTOR DEL PROYECTO ]\n\n";
    colorear(ROJO);
    Sleep(60);
    cout << "\t\t************************************************\n";
    colorear(AZUL);
    Sleep(60);
    cout << "\n\t\tNOMBRE : AXEL ANTONIO BARAHONA MONTOYA\n";
    colorear(AMARILLO);
    Sleep(60);
    cout << "\t\tCARNE : 9976-18-12537\n";
    colorear(CELESTE);
    Sleep(60);
    cout << "\t\tCARRERA : INGENIERIA INDUSTRIAL\n";
    colorear(VERDE);
    Sleep(60);
    cout << "\t\tSEMESTRE : 1\n";
    colorear(BLANCO);
    Sleep(60);
    cout << "\t\tUNIVERSIDAD MARIANO GALVEZ DE GUATEMALA\n\n\n";
    colorear(ROJO);
    Sleep(60);
    cout << "\t\t************************************************\n\n\n";

    Sleep(70);
    colorear(AMARILLO);
    system("pause");
}