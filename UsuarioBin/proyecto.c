#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define tamMax 100
#define true 1
#define false 0


typedef struct{

    char INE[20];
    char nombre[40];
    float transporte;
    float comida;
    float servicios;
    float entretenimiento;
    float compras;
    float variados;
    float total;

}Persona;

void menu(){

    system("cls");
    printf("\n\n\t\t[ BIENVENIDO A YOUR SENIORS ]\n\n");
    printf("[1]. Ingresar algun registro de Senior\n");
    printf("[2]. Desplegar lista completa de Seniors\n");
    printf("[3]. Buscar algun Senior\n");
    printf("[4]. Eliminar algun registro\n");
    printf("[5]. Salir\n\n[?]. Ingresa una opcion : ");

}

void ingresarPersona(Persona [], int );
void listarPersonas(Persona [], int );
void buscarSenior(Persona [],int );
void eliminarPersona(Persona [], int *);
int main(){

    system("pause");
    int opc;
    int salir = false;

    Persona personas[tamMax];
    int i = 0;

    do{
        menu();
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:
            ingresarPersona(personas,i);
            i++;
            break;
        
        case 2:
            listarPersonas(personas,i);
            break;

        case 3:
            buscarSenior(personas,i);
            break;

        case 4: 
            eliminarPersona(personas,&i);
            break;

        case 5:
            printf("\n\n\t\t[ Gracias por usar nuestro Software ]\n\n");
            salir = true;
            break;
        
        }

    }while(salir != true);


    return 0;
}


void ingresarPersona(Persona persona[], int i){


    int correcto = false;
    int opc,aux;
    char auxINE[20];
    float x = 0;

    printf("\n\n\t\t[ INGRESO DE ALGUN SENIOR ]\n\n");


    do{
        printf("\nIngresa el codigo INE del senior : ");
        fflush(stdin);
        gets(auxINE);

        if(strlen(auxINE) == 18){
            correcto = true;
            strcpy(persona[i].INE,auxINE);
        }else{
            correcto = false;
            printf("El INE debe tener 18 digitos de largo..\n");
            
        }

    }while(correcto != true);

    printf("Ingresa el nombre del senior : ");
    gets(persona[i].nombre);

    printf("Ingresa el gasto del senior en [ transporte ] : ");
    scanf("%f",&persona[i].transporte);
    x += persona[i].transporte;
    
    printf("Ingresa el gasto del senior en [ comida ] : ");
    scanf("%f",&persona[i].comida);
    x += persona[i].comida;
    
    printf("Ingresa el gasto del senior en [ Servicios ] : ");
    scanf("%f",&persona[i].servicios);
    x += persona[i].servicios;
        
    printf("Ingresa el gasto del senior en [ Entretenimiento ] : ");
    scanf("%f",&persona[i].entretenimiento);
    x += persona[i].entretenimiento;
        
    printf("Ingresa el gasto del senior en [ Compras ] : ");
    scanf("%f",&persona[i].compras);
    x += persona[i].compras;
        
    printf("Ingresa el gasto del senior en [ Variados ] : ");
    scanf("%f",&persona[i].variados);
    x += persona[i].variados;

    persona[i].total = x;

    printf("\n\n\t\t[ SENIOR REGISTRADO CON EXITO ]\n\n");
    system("pause");
}

void listarPersonas(Persona persona[], int max){

    int i;

    if(max != 0){

        printf("\n\n\t\t[ LISTANDO SENIORS ]\n\n");
        
        for(i = 0 ; i < max; i++){
            printf("\nSenior -> %i\n",i+1);
            printf("INE -> %s\n",persona[i].INE);
            printf("Nombre -> %s\n",persona[i].nombre);
            printf("Transporte -> %.2f\n",persona[i].transporte);
            printf("Comida -> %.2f\n",persona[i].comida);
            printf("Servicios -> %.2f\n",persona[i].servicios);
            printf("Entretenimiento -> %.2f\n",persona[i].entretenimiento);
            printf("Compras -> %.2f\n",persona[i].compras);
            printf("Variados -> %.2f\n",persona[i].variados);
            printf("Gasto Final -> %.2f\n",persona[i].total);

        }
    }else{
        printf("\n\n\t\t[ AUN NO HAY NINGUN SENIOR REGISTRADO ]\n\n");
    }
    printf("\n");
    system("pause");

}

void buscarSenior(Persona persona[],int max){


    char codigoOPC[20];
    int entro = false;
    int i;

    if(max != 0){
        printf("Ingresa el INE de la persona a buscar : ");
        fflush(stdin);
        gets(codigoOPC);

        for(i = 0 ; i < max; i++){
            if(strcmp(persona[i].INE,codigoOPC)==0){
                
                printf("\n\n\t\t[ SENIOR ENCONTRADO ]\n\n");
                printf("INE -> %s\n",persona[i].INE);
                printf("Nombre -> %s\n",persona[i].nombre);
                printf("Transporte -> %.2f\n",persona[i].transporte);
                printf("Comida -> %.2f\n",persona[i].comida);
                printf("Servicios -> %.2f\n",persona[i].servicios);
                printf("Entretenimiento -> %.2f\n",persona[i].entretenimiento);
                printf("Compras -> %.2f\n",persona[i].compras);
                printf("Variados -> %.2f\n",persona[i].variados);
                printf("Gasto Final -> %.2f\n",persona[i].total);

                entro = true;
            }
        }


        if(entro == false){
            printf("\n\n\t\t [ No se encontro al Senior buscado ]\n\n");
        }

    }else{
        printf("\n\n\t\t[ Los registros aun estan vacios ]\n\n");
    }

    printf("\n");
    system("pause");

}

void eliminarPersona(Persona persona[], int *n){


    char codigoOPC[20];
    int entro = false;
    int i,j;

    int max = *n;
    if(max != 0){
        printf("\n\n\t\t[ ELIMINAR ALGUN SENIOR DEL REGISTRO ] \n\n");
        printf("Ingresa el INE de la persona a buscar : ");
        fflush(stdin);
        gets(codigoOPC);

        for(i = 0; i < max; i++){
            if(strcmp(persona[i].INE,codigoOPC)==0){
                printf("\n\n\t\t[ Eliminado Senior ... ]\n\n");
                while(i < max-1){
                    persona[i] = persona[i+1];
                    i++;
                }
                entro = true;
                break;
            }
        }   
        
        if(entro == true){
            *n = *n-1;
        }


        if(entro == false){
            printf("\n\n\t\t [ No se encontro al Senior buscado ]\n\n");
        }

    }else{
        printf("\n\n\t\t[ Los registros aun estan vacios ]\n\n");
    }

    printf("\n");
    system("pause");



}