#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define _MaxSize 100

using namespace std;


struct herramient{

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
    cout<<"[3]. Ingresar Herramienta\n";
    cout<<"[4]. Calcular valor inventario\n";
    cout<<"[5]. Mostrar Herramientas\n";
    cout<<"[6]. Guardar Cambios - Salir\n";
    cout<<"\nIngresa opcion : ";
}

void IngresarHerramientas(struct herramient [],int );
void mostrarHerramientras(struct herramient [],int );
void calcularValorInventario(struct herramient [],int );

int main(){

    int i = 0,decidir,opc;
    bool creado = false,salir = false;
    FILE *miArchivo;// = fopen("miPrimerArchivo.txt","a");
    struct herramient Tool[_MaxSize];

    int j;

    long medida;
    char *texto;
    char nombre[15];

    
    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            if(!creado){
                creado = true;
                miArchivo = fopen("miPrimerArchivo.txt","a");
                printf("\n[ Acabas de crear el TXT ]\n\n");
            }else{
                cout<<"\n\n\t\t[EL ARCHIVO YA FUE CREADO ]\n\n";
            }
            system("pause");
            break;

        case 2:
            miArchivo = fopen("miPrimerArchivo.txt","r");

            fseek(miArchivo,0,SEEK_END);
            medida = ftell(miArchivo);
            rewind(miArchivo);

            texto = (char *) malloc(sizeof(char)*medida);
            fread(texto,medida+1,1,miArchivo);
            
            cout<<"\n\n\t\t[ ARCHIVO CARGADO CON EXITO ]\n\n";
            
            cout<<texto<<endl;
            system("pause");

            break;


        case 3:
                fopen("miPrimerArchivo.txt","a");
                IngresarHerramientas(Tool,i);
                fprintf(miArchivo,"%i\n",Tool[i].registro);
                fprintf(miArchivo,"%s\n",Tool[i].nombre);
                fprintf(miArchivo,"%i\n",Tool[i].cantidad);
                fprintf(miArchivo,"%.2f\n",Tool[i].valor);
                i++;
                cout<<"\n\n\t\t[ SE INTRODUJERON LOS VALORES ]\n\n";
                system("pause");
                fclose(miArchivo);
            break;

        case 4:
            if(i != 0){
                calcularValorInventario(Tool,i);
            }else{
                cout<<"\n\n\t\t[ AUN NO HAY REGISTROS ]\n\n";
                system("pause");
            }
            break;

        case 5:
            mostrarHerramientras(Tool,i);
            break;

        case 6:
            cout<<"\n\n\t\t[ ARCHIVO GUARDADO Y CERRADO CORRECTAMENTE ]\n\n";
            cout<<"REVISE DOCUMENTO PORFAVOR...\n\n";
            fclose(miArchivo);
            salir = true;
            break;

        }

    }while(salir != true);

    return 0;
}

void IngresarHerramientas(struct herramient tools[],int i){

    cout<<"\n\n\t\t[ INGRESO DE HERRAMIENTA N. -> "<<i<<" ]\n\n";

    cout<<"Ingresa registro de  Tool: ";
    cin>>tools[i].registro;
    
    cout<<"Ingresa el nombre: ";
    fflush(stdin);
    gets(tools[i].nombre);
    
    cout<<"Ingresa la cantidad: ";
    cin>>tools[i].cantidad;

    cout<<"Ingresa el valor: ";
    cin>>tools[i].valor;

}

void mostrarHerramientras(struct herramient tools[],int max){

    int i;
    cout<<endl;
    if(max != 0){
        
        cout<<"\n\n\t\t[ MOSTRANDO REGISTROS ]\n\n";
        for(i = 0; i < max; i++){

            cout<<"[Datos de Registro -> "<<i+1<<"]\n";
            cout<<"Numero de Registro : "<<tools[i].registro<<endl;
            cout<<"Nombre de Herramienta : "<<tools[i].nombre<<endl;
            cout<<"Cantidad Exacta : "<<tools[i].cantidad<<endl;
            cout<<"Precio Total  : "<<tools[i].valor<<endl<<endl;
            

        }
    }else{
        cout<<"\n\n\t\t[ NO SE ENCUENTRAN REGISTROS ]\n\n";
    }
    cout<<"\n";
    system("pause");
}

void calcularValorInventario(struct herramient tool[],int max){

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
