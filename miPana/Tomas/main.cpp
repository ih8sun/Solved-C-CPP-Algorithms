#include<stdio.h>
#include <string>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

struct tool{

    int registro;
    char nombre[50];
    int cantidad;
    float precio;
};
tool lineToStruct(char*cad)
{
    int nElementos=0,count=1;
    int tam=strlen(cad);
    tool herramienta;
    char *aux,*ptr,delim[]=",";
    
    for(int i=0;i<tam;i++)
        if(cad[i]==',')
            nElementos++;
    cout<<"El numero de datos es:"<<nElementos++<<endl;
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


void impTool(tool herramienta)
{
    cout<<"Numero de Registro : "<<herramienta.registro<<endl;
    cout<<"Nombre de Herramienta : "<<herramienta.nombre<<endl;
    cout<<"Cantidad Exacta : "<<herramienta.cantidad<<endl;
    cout<<"Precio Total  : ";
    cout<<setprecision(2)<<herramienta.precio<<endl<<endl;
    //printf("Precio Total : %f\n\n",herramienta.precio);
}
int nLineas(char*nombre)
{
    FILE *stream;
    size_t len =0;
    int nlineas=0;
    string line;
    stream=fopen(nombre,"r");
    while((getline(line, &len, stream)) != -1)
        nlineas++;
    return nlineas;
}

int main()
{
    char *line,nombreArch[]="Datos.txt";
    FILE *stream;
    string linea;
    size_t len = 0;
    tool *AllTool;
    int elementos=nLineas("Datos.txt"),i=0;
    AllTool=new tool[elementos];
    stream=fopen("Datos.txt","r");
    while((getline(linea)) != -1)
    {
        AllTool[i]=lineToStruct(line);
        i++;
    }
    for(int l=0;l<elementos;l++)
        impTool(AllTool[l]);

    cout<<"Adios.";
    free(line);
    delete[] AllTool;
    return 0;
}
    

