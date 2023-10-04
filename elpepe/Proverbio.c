#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];

int main(){

    string *pensamientos;
    pensamientos = (string *)malloc(7*sizeof(string));
    int i = 0,j;
    bool salir = false;
    int opc;
    int band = 1;

    int n = 0;
    string pes,aux;

    do{
    	system("cls");
        fflush(stdin);

        printf("\n\n\t\t[ Proverbios ]\n\n");
        printf("\nIngresa proverbios : ");
        fflush(stdin);
        gets(pes);

        strcpy(pensamientos[n],pes);


        printf("\nDesea Agregar Otra Cadena ? \n");
        printf("[1]. Si\n");
        printf("[2]. No\n");
        printf("\n[-]Ingrese opcion : ");
        scanf("%i",&opc);
        
        if(opc == 2){
            salir = true;
            n++;
        }else{
            n++;
        }

    }while(salir != true);

    printf("\n\n\t\tMOSTRANDO PROVERBIOS\n\n");
    for(i = 0; i < n ; i++ ){
        printf("Cadena  : %s\n",pensamientos[i]);
    }

    for(i = 0; i < n-1 && band == 1; i++){
        band = 0;
        for(j = 0 ; j < n-1; j++){

            if(strlen(pensamientos[j]) > strlen(pensamientos[j+1])){
                band = 1;
                strcpy(aux,pensamientos[j]);
                strcpy(pensamientos[j],pensamientos[j+1]);
                strcpy(pensamientos[j+1],aux);
            }

        }
    }

    printf("\n\n\t\tMOSTRANDO PROVERBIOS ORDENADOS\n\n");
    for(i = 0; i < n ; i++ ){
        printf("Cadena  : %s\n",pensamientos[i]);
    }

    printf("\n");
    system("pause");
}
