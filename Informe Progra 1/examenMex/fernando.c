#include <stdio.h>
#include <string.h>
typedef char cadenas[50];
#define maximoTamanio 10

cadenas Estudiante[maximoTamanio];
char sexo[maximoTamanio];
int edadAlumno[maximoTamanio];


void registrar(){

    int i;
    char varAux[100];
    
    for(i = 0; i < maximoTamanio ;i++){
        
        printf("Ingresa Nombre %i : ",i+1);
        fflush(stdin);
        gets(varAux);
        strcpy(Estudiante[i],varAux);

        printf("Ingresa Sexo m/o : " );
        scanf("%c",&sexo[i]);

        printf("Ingresa edadAlumno : ");
        scanf("%i",&edadAlumno[i]);
        printf("\n");
    }

}

void contarSexo(){

    int hombre = 0,mujeres = 0,i;

    for(i = 0; i < maximoTamanio ;i++){
        if(sexo[i] == 'm' || sexo[i] == 'M'){
            hombre++;
        }else{
            mujeres++;
        }
    }
    printf("\nResultados\n");
    printf("Hombres : %i\n",hombre);
    printf("Mujeres : %i\n",mujeres);
}

void hombresMayores(){

    int i;
    printf("\n\n\t\tMAYORES DE EDAD HOMBRES\n\n");
    
    for(i = 0; i < maximoTamanio ;i++){
        
        if(edadAlumno[i] >= 18 && (sexo[i] == 'm' || sexo[i] == 'M')){
            printf("\nPERSONA [%i]\n",i+1);
            printf("Nombre : %s\n",Estudiante[i]);
            printf("Sexo : %c\n",sexo[i]);
            printf("edadAlumno : %i\n",edadAlumno[i]);
        }
    }
}

int main(){

    printf("\nRegistrando datos\n\n");
    registrar();
    hombresMayores();
    contarSexo();

}