#include <stdio.h>

int main(){

    int matrizA[5][6];
    int arregloX[5],arregloZ[5];
    int c,r;

    printf("\n\n\t\tMANDANDO DATOS A MATRIZ A\n\n");
    for(r = 0; r <= 4; r++){
        for(c = 0; c <= 5; c++){
            printf("Ingrese elemento para pos [%i][%i] : ",r,c);
            scanf("%i",&matrizA[r][c]);
        }
        printf("\n");
    }
    printf("\n\n\t\tMANDANDO DATOS A ARREGLO R\n\n");
        for(r = 0; r <= 4; r++){
            printf("Ingrese elemento para pos [%i]: ",r);
            scanf("%i",&arregloX[r]);
    }

    for(r = 0; r <= 4; r++){
        arregloZ[r] = 0;
        for(c = 0; c <= 5; c++){
            arregloZ[r] = arregloZ[r] + (matrizA[r][c]*arregloX[r]);
        }
    }

    printf("\n\n\t\nMOSTRANDO RESULTADOS FINALES\n\n");
    for(r = 0; r <= 4; r++){
        for(c = 0; c <= 5; c++){
            printf("%i\t",matrizA[r][c]);
        }
        printf(" | %i =>\t%i\n",arregloX[r],arregloZ[r]);
    }

    return 0;
}