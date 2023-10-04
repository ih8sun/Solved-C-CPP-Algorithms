#include<stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define max_Tam 50
typedef char string[100];



int main(){

    string s1;
    char s2[]=",";
    char *ptr;

    FILE *miArchivo;
    FILE *miArchivoVolteado;

    int i,j=1;
    miArchivo = fopen("archivoCreado.txt", "r");
    miArchivoVolteado = fopen("archivoVolteado.txt", "w");

    string aux[max_Tam];

    while ((fgets(s1,100,miArchivo)) != NULL)
    {
        fputs(s1,miArchivo);
    }

    fclose(miArchivo);

    ptr = strtok(s1,s2);

    strcpy(aux[0],ptr);
    
    while((ptr = strtok(NULL,s2))!= NULL){
        strcpy(aux[j],ptr);
        j++;
    }

    printf("\n\n\t\t[ ARCHIVO LEIDO ] \n\n");

    for(i = 0; i < j; i++){
        printf("%s\n",aux[i]);
    }


    printf("\n\n\t\t[ VOLTEANDO TEXTO ] \n\n");

    for(i = j-1 ; i >= 0; i--){
        printf("%s\n",aux[i]);

        if (i == 0 + 1)
        {
            fprintf(miArchivoVolteado, "%s ", aux[i]);
        }
        else
        {
            fprintf(miArchivoVolteado, "%s ", aux[i]);
        }
    }


    fclose(miArchivoVolteado);
    return 0;
}