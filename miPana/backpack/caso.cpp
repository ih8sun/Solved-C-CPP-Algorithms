#include <stdio.h>
#include <iostream>
#include <stdlib.h>

/**Definicion*/
#define numMax 5      //Total de numero de los items
#define limit 12 //capacidad maxima de la mochica
// #define true 1   //dificion booleana
// #define false 0  //dificion booleana
using namespace std;


/**Declaracion de estructuras*/

typedef struct{
    int peso;      //weight
    int beneficio; //value
} art; //item


typedef struct{
    bool solucion[numMax]; //solucion
    int beneficio;    // beneficio de la solucion
    int peso;         // peso de la solucion
} resultado;          //resultados

/**Variable*/
art producto[numMax] = {{2, 6}, {2, 3}, {6, 5}, {4, 4}, {5, 6}}; //Items

/*Backtracking recursiva*/

void Encontrar_optimo(resultado test, int Pos, resultado *optimo)
{ //Parametros que ingresan : solucion actual , posicion empiezaen0 , ubicacion de la solucion optima

    int i;             // loop variable
    int Valorrest = 0; // valor restante

    
    if (Pos >= numMax) 
    { //si posiciones es menor a N - esta parte se encarga de buscar todas las busquedas
        if (test.beneficio > optimo->beneficio){
            *optimo = test; //encontrar la mejor solucion
        }
    }

    else
    {
        if (test.peso + producto[Pos].peso <= limit){       // si el peso  no supera la capacidad de la mochila                                    
                                                   
            test.solucion[Pos] = 1;             //Si el nodo de peso de la mochila es true == 1

            test.beneficio += producto[Pos].beneficio; //se sumaria peso y beneficio de test segun la posicion de la mochila
            test.peso += producto[Pos].peso;

            Encontrar_optimo(test, Pos + 1, optimo); //recursividad // SYSTEM ("PAUSE");

            test.solucion[Pos] = 0;              //Si el noco de peso de la mochila es false = 0
            test.beneficio -= producto[Pos].beneficio;   // se le resta los valores de  test segun la posicion de la mochila -1
            test.peso -= producto[Pos].peso;
        }

        for (i = Pos + 1; i < numMax; i++){ 
            //recupera los elementos restantes de la mochila
            Valorrest += producto[i].beneficio;
        }

        if (optimo->beneficio < test.beneficio + Valorrest)
        {                                            //Si el valor restante actual y el valor de los nodos han superados o aun no superan la solucion optima
            Encontrar_optimo(test, Pos + 1, optimo); //recursividad
        }

    }

}
/**Funcion para mostrar resultados*/

void mostrar_solucion(resultado *test)
{

    int i;
    
    //IMPRIMIENDO LOS VALORES INICIALES


    printf("\n----------------------\n");
    printf("Todos los items:\n----------------------\n");

    printf("item\t peso\t beneficio\n");
    for (i = 0; i < numMax; i++){
        printf("%d\t%dkg\t%d$\n", i + 1, producto[i].peso, producto[i].beneficio);
    }
    printf("----------------------\n");
    printf("capacidad de la mochila: %dkg\n", limit);
    printf("----------------------\n");
    
    

    printf("\n----------------------\n");
    printf("Solucion optima: \n----------------------\n");
    printf("item\t peso\t beneficio\n\n");

    //IMPRIMIENDO SOLUCION OPTIMA -> SOLO LOS QUE TIENEN SOLUCION O SOLUCION[I] == TRUE OR 1
    for (i = 0; i < numMax; i++){
        if (test->solucion[i] == true)  //((test->solucion)[i])
            printf("%d\t%dkg\t%d$\n",i + 1, producto[i].peso, producto[i].beneficio);
    }
    printf("----------------------\n");
    printf("Total:\t%dkg\t%d$\n", test->peso, test->beneficio);

}

int main(){

    resultado test = {{0}, 0, 0};


    int inicio = 0;

    Encontrar_optimo(test, inicio, &test); //BackTracking

    mostrar_solucion(&test);//Mostrando Solucion

    return 0;
}