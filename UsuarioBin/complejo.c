#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{

    float real;
    float imaginaria;

}Complejo;

void suma(Complejo a, Complejo b, Complejo *res){


    printf("[ SUMA DE DOS COMPLEJOS ]\n\n");

    printf("\nComplejo[1]\n");

    printf("Ingresa parte real : ");
    scanf("%f",&a.real);  

    printf("Ingresa parte imaginaria : ");
    scanf("%f",&a.imaginaria);




    printf("\nComplejo[2]\n");
    printf("Ingresa parte real : ");
    scanf("%f",&b.real);   

    printf("Ingresa parte imaginaria : ");
    scanf("%f",&b.imaginaria);

    printf("\n\n-> Resultado\n");

    res->imaginaria = a.imaginaria + b.imaginaria;
    res->real = a.real + b.real;

    printf("La Suma de los numeros Complejos es de : %.0f + %.0fj",
    res->real,res->imaginaria);

    printf("\n\n");

}


void multiplicacion(Complejo a, Complejo b, Complejo *res){

    printf("[ MULTIPLICACION DE DOS COMPLEJOS ]\n\n");

    printf("\nComplejo[1]\n");

    printf("Ingresa parte real : ");
    scanf("%f",&a.real); 

    printf("Ingresa parte imaginaria : ");
    scanf("%f",&a.imaginaria);




    printf("\nComplejo[2]\n");
    
    printf("Ingresa parte real : ");
    scanf("%f",&b.real);  

    printf("Ingresa parte imaginaria : ");
    scanf("%f",&b.imaginaria);




    printf("\n\n-> Resultado\n");

    res->imaginaria = a.imaginaria * b.imaginaria;
    res->real = a.real * b.real;

    printf("La multiplicacion de los numeros Complejos es de : %.0f * %.0fj",
    res->real,res->imaginaria);



    printf("\n\n");
}

void menu(){
    system("cls");
    printf("\n\n\t\t[ OPERACIONES CON COMPLEJOS ]\n\n");
    printf("[1]. Sumar Dos numeros Complejos \n");
    printf("[2]. Multiplicar Dos numeros Complejos\n");
    printf("[3]. Salir\n\n[?]. Ingresa opcion : ");

}

int main(){


    Complejo a,b, resp;
    int opc;

    do{
        menu();
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:
            suma(a,b,&resp);
            system("pause");
            break;
        
        case 2:
            multiplicacion(a,b,&resp);
            system("pause");
            break;
        }

    }while(opc != 3);


    


    return 0;
}