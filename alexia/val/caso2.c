#include <stdio.h>
int main(){

    int matrizA[4][5],matrizB[3][5];
    int i,j;
    int auxA,auxB;
    int igual = 1;

    printf("\n\n\t\tPIDIENDO DATOS DE MATRIZ A\n\n");
    for(i = 0; i < 3; i++){
        for(j = 0 ; j < 5; j++){
            printf("Ingrese num para pos [%i][%i] : ",i,j);
            scanf("%i",&matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\t\tPIDIENDO DATOS DE MATRIZ B\n\n");
    for(i = 0; i < 3; i++){
        for(j = 0 ; j < 5; j++){
            printf("Ingrese num para pos [%i][%i] : ",i,j);
            scanf("%i",&matrizB[i][j]);
        }
        printf("\n");
    }

    for (int x = 0; x < 3; x++) {

        for (int y = 0; y < 5; y++) {
            auxA = matrizA[x][y];
            auxB = matrizB[x][y];

            if (auxA != auxB) {
                igual = 0;
            }
        }
    }

    printf("\n\n\t\t[ DEFINIENDO IGUALDADES ]\n\n");
    if(igual == 1){
        printf("\nLas matrices A Y B son iguales\n");
    }else{
        printf("\nLas matrices A Y B son diferentes\n");
    }

    return 0;
}