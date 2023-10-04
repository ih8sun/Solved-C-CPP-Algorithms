#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char string[100];

int main()
{

    int i, n;
    string newCadena;
    string cadena;
    char caracter;
    FILE *miArchivo;
    miArchivo = fopen("archivoCreado.txt", "w");



    printf("\n\n\t\t[ DEFINIENDO TAMANIO ]\n\n");
    printf("Ingresa Cuantas Cadenas Ingresara : ");
    scanf("%i", &n);

    printf("\n\n\t\t[ DEFINIENDO CADENAS ]\n\n");

    for (i = 0; i < n; i++)
    {
        fopen("archivoCreado.txt", "a");
        printf("Ingresa Cadena [%i] : ", i);
        fflush(stdin);
        gets(cadena);

        if (i == n - 1)
        {
            fprintf(miArchivo, "%s", cadena);
        }
        else
        {
            fprintf(miArchivo, "%s,", cadena);
        }
        fclose(miArchivo);
    }


    return 0;
}