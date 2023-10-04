#include<iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define _maxSize 100

using namespace std;

struct herramienta{
    int registro;
    char nombre[20];
    int cantidad;
    float valor;
};

void menu(){
    system("cls");
    cout<<"\n\n\t\t[ MENU DE CREACION Y MANEJO DE ARCHIVOS ]\n\n";
    cout<<"[1]. Creacion del archivo y/o cargue del archivo\n";
    cout<<"[2]. Cargar el inventario existente en el archivo al sistema\n";
    cout<<"[3]. Ingresar herramienta\n";
    cout<<"[4]. Calcular valor inventario\n";
    cout<<"[5]. Guardar Cambios\n";
    cout<<"[6]. Salir\n";
    cout<<"\nIngresa opcion : ";
}

void ingresarHerramienta(struct herramienta [],int);
void calcularValorInventario(struct herramienta [],int);

int main(){
    int opc, i  = 0;   
    herramienta tools[_maxSize];
    bool salir = false;
    int arreglo[2];

    struct herramienta aux;

    FILE *f;

    do{
        menu();
        cin>>opc;
        switch (opc){
            case 1: 
                f = fopen("herramientas.txt","a");
                break;
            case 2:
                break;
            case 3:         
                if(f){       
                ingresarHerramienta(tools,i);
                aux = tools[i];
                cout<<aux.nombre<<endl;
                fprintf(f,"Nombre---> %s\n",aux.nombre);
                
                i++;
                }else{
                    cout<<"choiriuzon\n";
                }
                system("pause");
                break;
            case 4:
                calcularValorInventario(tools,i);
                
                break;
            case 5:
                break;
            case 6:
                cout<<"Gracias por usar el programa\n\n";
                system("pause");
                break;
        }

    }while(salir != true);


}

void ingresarHerramienta(struct herramienta tools[],int i){

    cout<<"\n\n\t\t[ INGRESO DE HERRAMIENTA N. -> "<<i<<" ]\n\n";

    cout<<"Ingresa registro de  herramienta: ";
    cin>>tools[i].registro;
    
    cout<<"Ingresa el nombre: ";
    fflush(stdin);
    gets(tools[i].nombre);
    
    cout<<"Ingresa la cantidad: ";
    cin>>tools[i].cantidad;

    cout<<"Ingresa el valor: ";
    cin>>tools[i].valor;

}

void calcularValorInventario(struct herramienta tool[],int max){

    int i = 0;  
    int cantidad = 0,valor = 0;

    for(i = 0; i < max; i++){
        cantidad += tool[i].cantidad;
    }

    for(i = 0; i < max; i++){
        valor += tool[i].valor;
    }

    cout<<"\n\n\t\t[ CANTIDAD TOTAL DE HERRRAMIENTAS ] \n\n";
    cout<<"Cantidad de herramientas actuales -> "<<cantidad<<endl<<endl;
    cout<<"Valor actual que se tiene en la empresa -> "<<valor<<endl<<endl;
    system("pause");

}
