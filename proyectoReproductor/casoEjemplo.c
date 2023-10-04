#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodo{

    char codeID[20];
    char albumName[50];
    char artistName[50];
    double duration;
    char titulo[50];
    int year;

};

int main(){

    struct Nodo obj1;
    

    char s1[] = "SOVLGJY12A8C13FBED,Call of the Mastodon,Mastodon,280.21506,Deep Sea Creature,2001";
    char delimitador[] = ",\n\t";
    int i = 0,len;
    char *aux;

    aux = strtok(s1,delimitador);

    strcpy(obj1.codeID,aux);
    
    while( ( aux = strtok(NULL,delimitador)) != NULL ){

        if(i == 0)
            strcpy(obj1.albumName,aux);
        if (i == 1)
            strcpy(obj1.artistName,aux);
        if (i == 2)
            obj1.duration = atof(aux);
        if (i == 3)
            strcpy(obj1.titulo,aux);
        if (i == 4)
            obj1.year = atoi(aux);

        i++;
    }

    printf("%s\n",obj1.codeID);
    printf("%s\n",obj1.albumName);
    printf("%s\n",obj1.artistName);
    printf("%.3f\n",obj1.duration);
    printf("%s\n",obj1.titulo);
    printf("%i\n",obj1.year);


    return 0;


}
