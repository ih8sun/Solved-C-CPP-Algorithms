#include <stdio.h>
#include <math.h>
void menu(){
    system("cls");
    printf("\n\n\t\t[ -> CALCULO DE VOLUMEN <-]\n\n");
    printf("[1]. Calcular Volumen de Cubo\n");
    printf("[2]. Calcular Volumen de Paralelepipedo\n");
    printf("[3]. Calcular Volumen de Piramidee\n");
    printf("[4]. Calcular Volumen de Cilindro\n");
    printf("[5]. Calcular Volumen de Cono\n");
    printf("[6]. Calcular Volumen de Esfera\n");
    printf("[7]. Salir\n");
    printf("[-]. Ingresa opcion : ");
}



int main(){



    return 0;
}


float volumenCubo(){

    float volumen;

    printf("Ingrese Arista del cubo : ");
    scanf("%i",&volumen);

    volumen = pow(volumen,3);

    return volumen;
}

float volumenParalelepipedo(){

    float paral;

    

    return paral;
}