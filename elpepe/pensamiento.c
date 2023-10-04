#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef char string[100];

int main(){

    
    string pensamientos[5];         
    int i;
    bool salir = false;
    int opc;

    int n;
    string pes;
    strcpy(pensamientos[0],"tengo Hambre");
    strcpy(pensamientos[1],"Que buen dia");
    strcpy(pensamientos[2],"Me vengooo");
    strcpy(pensamientos[3],"La vida es Dura");
    strcpy(pensamientos[4],"Fuerza Colombia");

    do{
    	system("cls");
        n = rand () % 5+0;//Numero random entre el 0 y 4
        fflush(stdin);
        strcpy(pes,pensamientos[n]);
        printf("\n\n\t\t[ PENSAMIENTOS ]\n\n");
        printf("Pensamiento : [ %s ] \n\n",pes);
        printf("\nDesea Salir del programa ? \n");
        printf("[1]. Si\n");
        printf("[2]. No\n");
        printf("\n[-]Ingrese opcion : ");
        scanf("%i",&opc);
        
        if(opc == 1){
            salir = true;
        }

    }while(salir != true);


}