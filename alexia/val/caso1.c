#include <stdio.h>

int main(){

    int matriz[4][5];
    int i,j;

    printf("\n\n\t\tPIDIENDO DATOS DE MATRIZ\n\n");
    for(i = 0; i < 4; i++){
        for(j = 0 ; j < 5; j++){
            printf("Ingrese num para pos [%i][%i] : ",i,j);
            scanf("%i",&matriz[i][j]);
        }
    }

    printf("\n\n\t\tIMPRIMIENDO MATRIZ\n\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\t\tIMPRIMIENDO MATRIZ TRANSPUESTA\n\n");


    for(i = 0;i < 5;i++){
        for(j = 0;j < 4;j++){
            printf("%i ", matriz[j][i]);
            }
        printf("\n");
    }

    return 0;
}