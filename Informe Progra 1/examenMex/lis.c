#include <stdio.h>
#include <string.h>
#define tamMax 5
typedef char cadenas[50];


void registrar(cadenas n1[],char s1[],int edad[],int total){

    int i;
    char nombreComple[100];
    
    for(i = 0; i < total ;i++){
        
        printf("Ingresa Nombre %i : ",i+1);
        fflush(stdin);
        gets(nombreComple);
        strcpy(n1[i],nombreComple);

        printf("Ingresa Sexo [ M - F] : " );
        scanf("%c",&s1[i]);

        printf("Ingresa Edad : ");
        scanf("%i",&edad[i]);
        printf("\n");
    }

}

void contarSexo(cadenas n1[],char s1[],int edad[],int total){

    int hombre = 0,mujeres = 0,i;

    for(i = 0; i < total ;i++){
        if(s1[i] == 'm' || s1[i] == 'M'){
            hombre++;
        }else{
            mujeres++;
        }
    }
    printf("Hombres : %i\n",hombre);
    printf("Mujeres : %i\n",mujeres);
}

void hombresMayores(cadenas n1[],char sexo[],int edad[],int tam){

    int i;
    printf("\n\n\t\tMAYORES DE EDAD HOMBRES\n\n");
    
    for(i = 0; i < tam ;i++){
        
        if(edad[i] >= 18 && (sexo[i] == 'm' || sexo[i] == 'M')){
            printf("\nPERSONA [%i]\n",i+1);
            printf("Nombre : %s\n",n1[i]);
            printf("Sexo : %c\n",sexo[i]);
            printf("Edad : %i\n",edad[i]);
        }
    }
}

int main(){


    cadenas Estudiante[tamMax];
    char sexo[tamMax];
    int edad[tamMax];


    registrar(Estudiante,sexo,edad,tamMax);
    hombresMayores(Estudiante,sexo,edad,tamMax);
    contarSexo(Estudiante,sexo,edad,tamMax);


    return 0;
}

