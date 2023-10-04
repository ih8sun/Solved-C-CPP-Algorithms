#include<iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#define _maxSize 20


using namespace std;

struct tool{

    int registro;
    char nombre[20];
    int cantidad;
    float precio;
};


void menu(){
    system("cls");
    cout<<"\n\n\t\t[ MENU DE CREACION Y MANEJO DE ARCHIVOS ]\n\n";
    cout<<"[1]. Creacion del archivo y/o cargue del archivo\n";
    cout<<"[2]. Ingresar Herramienta\n";
    cout<<"[3]. Mostrar Herramientas\n";
    cout<<"[4]. Guardar Cambios - Salir\n";
    cout<<"\nIngresa opcion : ";
}

void IngresarHerramientas(struct tool [],int ,bool &);
void mostrarHerramientras(struct tool [],int );

tool lineToStruct(string texto)
{   
    
    char *cad;
    strcpy(cad,texto.c_str());

    int nElementos=0,count=1;
    int tam=strlen(cad);
    tool herramienta;
    char *aux,*ptr,delim[]=",";
    
    for(int i=0;i<tam;i++)
        if(cad[i]==',')
            nElementos++;
    ptr=strtok(cad,delim);
    herramienta.registro=atoi(ptr);
    while((ptr=strtok(NULL,delim))!=NULL)
    {
        if(count==1)
            strcpy(herramienta.nombre,ptr);
        else if(count==2)
            herramienta.cantidad=atoi(ptr);
        else if(count==3)
            herramienta.precio=atof(ptr);
        count++;
    }
    return herramienta;
}

int main(){

        //* ITERADOR PRINCIPAL
    int i = 0;
    
    int j,decidir,opc;
    bool creado = false,salir = false,salir2 = false;
    struct tool herramienta[_maxSize];
    bool entro = false;
    //Manejo de Archivos
    ofstream miArchivo;
    ifstream miArchivoLectura;
    
    string texto;
    int lineas;

    bool cargar = false;

    //ERRORES DE WHILE
    int solucion = 0;

    do{
        system("cls");
        cout<<"\n\n\t\t [ BIENVENIDO AL ARCHIVO ]\n\n";
        cout<<"->  Cargar el inventario existente en el archivo al sistema\n";
        cout<<"\n[1]. Si\n[2]. No\n\n[=]. Ingresa una opcion : ";
        cin>>opc;

        if(opc == 1){
            salir2 = true;


            miArchivoLectura.open("miPrimerArchivo.txt",ios::in);

            cout<<"\n\n\t\t BUSCANDO DATOS \n\n";
            lineas = 0;


            if(miArchivoLectura.fail()){
                cout<<"\n\nNO SE ENCONTRARON NINGUN REGISTRO...\n\n";
                exit(1);
            }else{

            while(!miArchivoLectura.eof()){
                lineas++;
                getline(miArchivoLectura,texto);
                herramienta[i] = lineToStruct(texto);
                creado = true;
                i++;
                cargar = true;
            }



            miArchivoLectura.close();

            cout<<"\n\n\t[ SE CARGARON LOS DATOS CORRECTAMENTE ]\n"<<endl;
            cout<<"\nTotal de Datos Cargados -> "<<lineas<<endl<<endl;
            }
            system("pause");



        }
        if(opc == 2){
            salir2 = true;
            miArchivo.open("miPrimerArchivo.txt",ios::out);
            miArchivo.close();
        }

    }while(salir2 != true);


    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            if(!miArchivo.fail() and creado == false){
                creado = true;
                miArchivo.open("miPrimerArchivo.txt",ios::out);
                printf("\n[ Acabas de crear el TXT ]\n\n");
            }else{
                cout<<"\n\n\t\t[EL ARCHIVO YA FUE CREADO ]\n\n";
            }
            system("pause");
            break;



        case 2:
                if(creado && i < _maxSize){
                    if(entro == false && cargar == true){
                        
                    miArchivo.open("miPrimerArchivo.txt",ios::app);
                    entro = true;
                    }
                    IngresarHerramientas(herramienta,i,entro);
                    miArchivo<<herramienta[i].registro<<",";
                    miArchivo<<herramienta[i].nombre<<",";
                    miArchivo<<herramienta[i].cantidad<<",";
                    miArchivo<<herramienta[i].precio;
                    
                    i++;
                    cout<<"\n\n\t\t[ SE INTRODUJERON LOS VALORES ]\n\n";
                    miArchivo.close();
                    
                    system("pause");
                    miArchivo.open("miPrimerArchivo.txt",ios::app);
                    
                    
                }else{
                    cout<<"\n\n\t\t[ AUN NO SE CREO EL ARCHIVO ]\n\n";
                    system("pause");
                }
            break;


        case 3:
            mostrarHerramientras(herramienta,i);
            break;

        case 4:


            cout<<"\n\n\t\t[ ARCHIVO GUARDADO Y CERRADO CORRECTAMENTE ]\n\n";
            cout<<"REVISE DOCUMENTO PORFAVOR...\n\n";
            miArchivo.close();
            salir = true;

            break;

        }

    }while(salir != true);



}


void IngresarHerramientas(struct tool herramienta[],int i,bool &entro){

    cout<<"\n\n\t\t[ INGRESO DE HERRAMIENTA N. -> "<<i<<" ]\n\n";

    ofstream miArchivo;

    herramienta[i].registro = i;
    
    cout<<"Ingresa el nombre de herramienta : ";
    fflush(stdin);
    gets(herramienta[i].nombre);
    
    cout<<"Ingresa la cantidad : ";
    cin>>herramienta[i].cantidad;

    cout<<"Ingresa el valor : ";
    cin>>herramienta[i].precio;

    miArchivo.open("miPrimerArchivo.txt",ios::app);
    miArchivo<<endl;

}

void mostrarHerramientras(struct tool herramienta[],int max){

    int i;

    cout<<endl;

    if(max != 0){
        
        cout<<"\n\n\t\t[ MOSTRANDO REGISTROS ]\n\n";
        for(i = 0; i < max; i++){

            cout<<"[txtos de Registro -> "<<i+1<<"]\n";
            cout<<"Numero de Registro : "<<herramienta[i].registro<<endl;
            cout<<"Nombre de Herramienta : "<<herramienta[i].nombre<<endl;
            cout<<"Cantidad Exacta : "<<herramienta[i].cantidad<<endl;
            cout<<"Precio Total  : "<<herramienta[i].precio<<endl<<endl;
            

        }

    }else{
        cout<<"\n\n\t\t[ NO SE ENCUENTRAN REGISTROS ]\n\n";
    }
    cout<<"\n";
    system("pause");
}