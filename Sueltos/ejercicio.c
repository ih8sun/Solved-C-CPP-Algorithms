#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void LeerExpresion(char expresion[]){

    printf("\nIngrese : ");
    fflush(stdin);
    gets(expresion);
}

void notaciionPostFija(char expresion []){

    char expresionPost[15];
    int i;

    for(i = 0 ; i < 15; i++){
        expresionPost[i] = '\0';
    }
    int tam = strlen(expresion);
    tam--;
    int j = 0;
    while(tam >= 0){

        if(expresion[tam] == '+'){
            expresionPost[j] = expresionPost[j] = '+';
            j++;
        }
        
        if(expresion[tam] == '-'){
            expresionPost[j] = expresionPost[j] = '-';
            j++;
        }
        
        if(expresion[tam] == '/'){
            expresionPost[j] = expresionPost[j] = '/';
            j++;
        }
        
        if(expresion[tam] == '*'){
            expresionPost[j] = expresionPost[j] = '*';
            j++;
        }
        tam--;
    }
    tam = strlen(expresion);

    while(tam >= 0){

        if(isdigit(expresion[tam])){
            expresionPost[j] = expresion[tam];
            j++;
        }
        
        tam--;
    }

    printf("%s\n",expresionPost);

}

int main(){

    char expresionAl[15];

    printf("\n\n\t\t[PIDIENDO NOTACION INFIJA ]\n");
    LeerExpresion(expresionAl);
    notaciionPostFija(expresionAl);
    return 0;
}