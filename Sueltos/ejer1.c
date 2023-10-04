#include <stdio.h>

int main(){

    int multi = 1;
    int i;

    printf("\n\n\t\t[ IMPRIMIENDO IMPARES ]\n\n");
    for(i = 7; i < 32;i++){
        if(i % 2 != 0){
            printf("%i * %i = %i \n",i,i,i*i);

        }
    }


    return 0;
}