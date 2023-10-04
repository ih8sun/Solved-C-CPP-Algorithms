#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**Definicion*/
#define numMax 100      //Total de numero de los items
#define limit 500 //capacidad maxima de la mochica
// #define true 1   //dificion booleana
// #define false 0  //dificion booleana
using namespace std;


/**Declaracion de estructuras*/

struct art{
    int peso;      //weight
    int beneficio; //value
};

struct resultado{
    bool solucion[numMax]; //solucion
    int beneficio;    // beneficio de la solucion
    int peso;         // peso de la solucion
};

void Encontrar_optimo(int Cantidad,int Lim, art producto[],resultado test, int Pos, resultado *optimo)
{ //Parametros que ingresan : solucion actual , posicion empiezaen0 , ubicacion de la solucion optima

    int i;             // loop variable
    int Valorrest = 0; // valor restante

    
    if (Pos >= Cantidad) { //si posiciones es menor a N - esta parte se encarga de buscar todas las busquedas
        if (test.beneficio > optimo->beneficio){
            *optimo = test; //encontrar la mejor solucion
        }
    }

    else
    {
        if (test.peso + producto[Pos].peso <= Lim){       // si el peso  no supera la capacidad de la mochila                                    
                                                   
            test.solucion[Pos] = 1;             //Si el nodo de peso de la mochila es true == 1

            test.beneficio += producto[Pos].beneficio; //se sumaria peso y beneficio de test segun la posicion de la mochila
            test.peso += producto[Pos].peso;

            Encontrar_optimo(Cantidad,Lim,producto,test, Pos + 1, optimo); //recursividad // SYSTEM ("PAUSE");

            test.solucion[Pos] = 0;              //Si el noco de peso de la mochila es false = 0
            test.beneficio -= producto[Pos].beneficio;   // se le resta los valores de  test segun la posicion de la mochila -1
            test.peso -= producto[Pos].peso;
        }

        for (i = Pos + 1; i < Cantidad; i++){ 
            //recupera los elementos restantes de la mochila
            Valorrest += producto[i].beneficio;
        }

        if (optimo->beneficio < test.beneficio + Valorrest)
        {                                            //Si el valor restante actual y el valor de los nodos han superados o aun no superan la solucion optima
            Encontrar_optimo(Cantidad,Lim,producto,test, Pos + 1, optimo); //recursividad
        }

    }

}

void mostrar_solucion(int Cantidad,int Lim,art producto[],resultado *test){
    
    int i;
    
    //IMPRIMIENDO LOS VALORES INICIALES
    printf("\n----------------------\n");
    printf("Todos los items:\n----------------------\n");
    printf("item\t peso\t beneficio\n");
    for (i = 0; i < Cantidad; i++){
        printf("%d\t%dkg\t%d$\n", i + 1, producto[i].peso, producto[i].beneficio);    
    }
    printf("----------------------\n");
    printf("capacidad de la mochila: %dkg\n", Lim);
    printf("----------------------\n");
    
    //IMPRIMIENDO SOLUCION OPTIMA
    printf("\n----------------------\n");
    printf("Solucion optima: \n----------------------\n");
    printf("item\t peso\t beneficio\n\n");
    for (i = 0; i < Cantidad; i++){
        if (test->solucion[i] == true)  //((test->solucion)[i]) 
            printf("%d\t%dkg\t %d$\n",i + 1, producto[i].peso, producto[i].beneficio);
    }
    printf("----------------------\n");
    printf("Total:\t%dkg\t%d$\n", test->peso, test->beneficio);
    
}

void menu(){
    system("cls");
    cout<<"\n\t\tCASO DE LA MOCHILA CON BACKTRACKING\n\n";
    cout<<" 1. INGRESAR DATOS A LA MOCHILA"<<endl;
    cout<<" 2. MOSTRAR CAPACIDAD"<<endl;
    cout<<" 3. SALIR"<<endl;
    cout<<"\n INGRESE OPCION: ";
}

void inicializador(art producto[], resultado &test){
    
    test.beneficio = 0;
    test.peso = 0;
    
    for (int i = 0; i < numMax; i++){
        test.solucion[i] = 0;
    }
    
    for(int i = 0; i < numMax ; i++){
        producto[i].beneficio = 0;
        producto[i].peso = 0;
    }

}

int main(){
    
    //bool nonaloa = true; //1 false // 0;
    bool correcto = false;

    int lim,Cantidad,opc,tam;
    bool salir = false;

    resultado test;

    int inicio = 0;

    art producto[numMax];
    
    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            inicializador(producto,test);
            
            cout<<"\n\n\t\t[ DEFINIR LIMITES Y CAPACIDADES ]\n\n";

            do{
                cout<<"\nIngresa cantidad de objetos en la mochila : ";
                cin>>Cantidad;
                
                if(Cantidad >= 0 && Cantidad <= numMax){
                    correcto = true;
                }else{
                    correcto= false;
                    cout<<"Debe Ingresar numero dentro de rango ["<<numMax<<"]...\n";
                    system("pause");
                }
            } while(correcto != true);


            do{
                cout<<"Ingresa limite de la Mochila : ";
                cin>>lim;
                if(lim >= 0 && lim <= limit){
                    correcto = true;
                }else{
                    correcto= false;
                    cout<<"Debe Ingresar numero dentro de rango ["<<limit<<"]...\n";
                    system("pause");
                }
            }while(correcto != true);


            cout<<"\n\n\t\t[ DEFINIENDO PROBLEMA  DE LA MOCHILA ]\n\n";
    
            for(int i = 0; i < Cantidad; i++){
                cout<<"\nIngresa Peso [ "<<i<<" ] : ";
                cin>>producto[i].peso;
                cout<<"Ingresa Beneficio [ "<<i<<" ] : ";
                cin>>producto[i].beneficio;
            }
    
            Encontrar_optimo(Cantidad,lim,producto,test, inicio, &test);
            cout<<"\n\n";
            system("pause");
            break;

        case 2:
            mostrar_solucion(Cantidad,lim,producto,&test); 
            cout<<"\n\n";
            system("pause");
            break;

        case 3:
            cout<<"\n\n\t\t[ GRACIAS POR USAR EL PROGRAMA ] \n\n";
            salir = true;
            break;
        }
    }while(salir != true);
    
    return 0;    
}