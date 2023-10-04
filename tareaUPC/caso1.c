#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LONGITUD_MAXIMA_CADENA 1000


int main(){


    FILE *diccionario;
    char caracter;



    int i = 0;
    diccionario = fopen("words.txt","r");
    char bufer[LONGITUD_MAXIMA_CADENA];    


    while (fgets(bufer, LONGITUD_MAXIMA_CADENA, diccionario))
    {
        // Aquí, justo ahora, tenemos ya la línea. Le vamos a remover el salto
        strtok(bufer, "\n");
        // La imprimimos, pero realmente podríamos hacer cualquier otra cosa
        printf("%i. La linea es: '%s'\n",i, bufer);

        strcpy(cadena[i],bufer);
        i++;
    }




    return 0;
}