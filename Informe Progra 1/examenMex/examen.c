#include <stdio.h>
#include <string.h>
#define max_nombre 100
#define tamMax 5
typedef char string[max_nombre];


void ingresandoDatos(string nombres[],char sexo[],int edad[],int tam){

    int i;
    char aux[100];
    printf("\n\n\t\t[ DETERMINANDO PERSONAS ]\n\n");
    for(i = 0; i < tam ;i++){
        
        printf("Persona -> %i\n",i+1);
        printf("Ingresa Nombre : ");
        fflush(stdin);
        gets(aux);
        strcpy(nombres[i],aux);

        printf("Ingresa Sexo [ M - F] : " );
        scanf("%c",&sexo[i]);

        printf("Ingresa Edad : ");
        scanf("%i",&edad[i]);
        printf("\n");
    }

}

void hombres_mujeres(string nombres[],char sexo[],int edad[],int tam){

    int hombre = 0,mujeres = 0,i;

    for(i = 0; i < tam ;i++){
        if(sexo[i] == 'm' || sexo[i] == 'M'){
            hombre++;
        }else{
            mujeres++;
        }
    }
    printf("\n PERSONAS POR SEXO\n");
    printf("Numero de Hombres -> %i\n",hombre);
    printf("Numero de Mujeres -> %i\n",mujeres);
}

void desplegarMayores(string nombres[],char sexo[],int edad[],int tam){

    int i;
    printf("\n\n\t\t[ PERSONAS MAYORES DE EDAD ( HOMBRES ) ]\n\n");
    
    for(i = 0; i < tam ;i++){
        
        if(edad[i] >= 18 && (sexo[i] == 'm' || sexo[i] == 'M')){
            printf("\nPERSONA [%i]\n",i+1);
            printf("Nombre : %s\n",nombres[i]);
            printf("Sexo : %c\n",sexo[i]);
            printf("Edad : %i\n",edad[i]);
        }
    }
}



int main(){



    string Nom_personas[tamMax];
    char sexo[tamMax];
    int edad[tamMax];
    ingresandoDatos(Nom_personas,sexo,edad,tamMax);
    desplegarMayores(Nom_personas,sexo,edad,tamMax);
    hombres_mujeres(Nom_personas,sexo,edad,tamMax);


    return 0;
}

