#include <stdio.h>//Libreria de entrada y salida de datos con formato
#include <iostream>
#include <stdlib.h>//libreria de manejo d consola y manejo de nuevas funciones
#include <time.h>//liberria usado para variables ramdoms
using namespace std;

//Variables Globales para poder usarlas en todas las funciones
int procesos[10], quantum = 0, np = 11, nq = 0, finalizado = 0, p[10][2];
float tiempoFinal = 0, tiempoPromedio;

//prototipo de funciones para poder usarlas luego
void MenuPrincipal(), IngresarDatos(), Fifo(), Sjf(), RoundRobin(), prioridad();

//Funcion principal donde importaremos el menu principal
int main()
{
    //importamos menu principal para poder usar las funciones 
    MenuPrincipal();
    return 0;
}
//Menu principal
void MenuPrincipal()
{
    //variable opcion
    int Op;

    do
    {//Hara esto hasta que opcion sea igual de 6;
        system("Cls");//limpiara pantalla
        printf("\n\n\t\t[ MENU DE OPCIONES ]\n\n");
        printf("[1] .Entrada de datos\n");
        printf("[2] .FIFO\n");
        printf("[3] .SJF\n");
        printf("[4] .Round Robin\n");
        printf("[5] .Prioridad\n");
        printf("[6] .Salir\n");
        printf("Ingresa una opcion: ");
        cin>>Op;//pedira una opcion y la buscara en el switch

        switch (Op)//Depende de la opcion entrara a un case
        {
        //Cada caso tendra una opcion diferente
        case 1:
            IngresarDatos();
            break;

        case 2:
            Fifo();
            system("pause");
            break;

        case 3:
            Sjf();
            system("pause");
            break;

        case 4:
            RoundRobin();
            system("pause");
            break;

        case 5:
            prioridad();
            system("pause");
            break;
        }

    } while (Op != 6);//repetira el proceso mientras que OP sea diferente de 6
}


void IngresarDatos()//Funcion de ingreso de Datos
{   

    //Pedira numero de procesos
    printf("\n\nIngresa Numero de procesos : ");
    scanf("%d", &np);

    cout<<endl;
    //Rellenara los valores de los procesos a cada espacio del array
    for (int i = 0; i < np; i++)
    {
        printf("Inserte Valor de la prioridad [%d] :", i + 1);
        scanf("%d", &procesos[i]);
    }
}

void Fifo()
{

    //Funcion FIFO donde encontrara el mejor tiempo promedio
    for (int i = 0; i < np; i++)//repetira el proceso desde 0 hasta np-1;
    {
        tiempoFinal += procesos[i];//aumentara el tiempoFinal por cada iteracion
        tiempoPromedio = tiempoPromedio + tiempoFinal;//e ira sumando con el tiempo final
        printf("Tiempo [%d] concluye en -> %2.1f", i + 1, tiempoFinal);//mientras ira mostrando los resultados obtenidos
    }

    printf("\n");//Por ultimo imprimira los resultados finales
    printf("\nLa suma de los procesos %2.1f", tiempoPromedio);
    tiempoPromedio = tiempoPromedio / np;
    printf("\n\nTiempo promedio en FIFO fue de: %2.2f", tiempoPromedio);
}

void Sjf()
{
    //Algoritmo SJF 

    for (int i = 0; i < np; i++)
    {//Hara un for de 0 hasta np-1
        printf("Inserte  el Valor %d:", i + 1);
        scanf("%d", &p[i][0]);//pedira los valores y los guardare en la matriz
        p[i][1] = i + 1;//e ira iterando las posiciones
    }
    //aumentando matriz

    for (int i = 0; i < np - 1; i++)//ira desde 0 hasta np-2
    {
        for (int j = i + 1; j < np; j++)//ira desde 1 hasta np-1
        {
            if (p[j][0] < p[i][0])//si p[j][0] es menor al p [i][0]
            {
                int aux[2] = {p[j][0], p[j][1]};//entonces creara una variable aux 
                p[j][0] = p[i][0];//para poder guardar resultados y poder pasar datos 
                p[j][1] = p[i][1];//de i a j
                p[i][0] = aux[0];//y de aux a i
                p[i][1] = aux[1];
            }
        }
    }

    //ira deasde 0 hasta np -1

    for (int i = 0; i < np; i++)
    {//aumentara el tiempofinal cada que se itere con el p[i][0]
        tiempoFinal += p[i][0];
        //mientras que tambien se estara aumentando el tiempo promedio
        tiempoPromedio = tiempoPromedio + tiempoFinal;//e ira imprimiendo por
        printf("Tiempo %d, concluye en %2.1f", p[i][1], tiempoFinal);//cada iteracion
    }
    printf("\n");//Por ultimo mostrara los procesos
    printf("\nLa suma de los procesos %2.1f", tiempoPromedio);
    tiempoPromedio = tiempoPromedio / np;
    printf("\n\nTiempo promedio en SJF fue de: %2.2f", tiempoPromedio);
}

void RoundRobin()
{

    while (quantum <= 0)
    {//pedira el quantum hasta que ingrese un valor mayor a 0
        printf("Ingresa el tamaño del quantium:");
        scanf("%d", &quantum);
    }
    while (finalizado == 0)
    {//entrara y cambiara el estado de finalizado a 1
        finalizado = 1;
        for (int i = 0; i < np; i++)
        {//hara un for desde 0 hasta np-1
            if (procesos[i] > 0)//si el proceso[i] es mayor a 0
            {
                procesos[i] -= quantum;//entonces se restara con el cuantum
                nq++;//e iterara el nq 
                printf("\n Quantium[%d]proceso %d", nq, i + 1);
                if (procesos[1] > 0)//mientras que imprimira el resultado
                {//si el proceso [1] es mayor a 0
                    finalizado = 0;//finalizado sera 0 y volvera  ahacer el while
                }
                else
                {//mientras que sino el tiempo promedio sera aumentado con el nq por el quantum
                    tiempoPromedio += nq * quantum;
                }
            }
        }
    }
    //una ultima iteracion seria de 0 hasta np-1 
    for (int i = 0; i < np; i++)
    {
        tiempoFinal += procesos[i];//y hara lo mismo que las anteriores funciones
        tiempoPromedio = tiempoPromedio + tiempoFinal;
        printf("\nTiempo %d concluye en %2.1f", i + 1, tiempoFinal);
    }
    printf("\n");//por ultimo imprimira el proceso
    printf("\nLa suma de los procesos %2.1f", tiempoPromedio);
    tiempoPromedio = tiempoPromedio / np;
    printf("\n\nTiempo promedio en RR fue de: %2.2f", tiempoPromedio);
}

void prioridad()
{
    while (quantum <= 0)
    {//pedira el quantum hasta que sea mayor a 0
        printf("Ingrese el tamaño del quantium:");
        scanf("%d", &quantum);
    }

    for (int i = 0; i < np - 1; i++)
    {//hara un for de 0 hasta  np-1 
        for (int j = i + 1; j < np; j++)
        {//y aqui de 1 hasta np
            if (p[j][0] < p[i][0])//hara la comparacion de procesos
            {//para poder hallar el que tiene una mayor prioridad
                int aux[2] = {p[j][0], p[j][1]};//creara un aux e intercambiara
                p[j][0] = p[i][0];//los valores en una especia de burbuja
                p[j][1] = p[i][1];
                p[i][0] = aux[0];
                p[i][1] = aux[1];
            }
        }
    }
    for (int i = 0; i < np; i++)
    {//por ultimo hara un for para poder hallar el valor del quantum y el mejor tiempo final
        tiempoFinal += p[i][0];
        tiempoPromedio = tiempoPromedio + tiempoFinal;
        printf("Tiempo %d, concluye en %2.1f", p[i][1], tiempoFinal);
        printf("\nQuantum[%d]proceso %d", nq, i + 1);
        if (procesos[i] > 0)//si el proceso en la pos actual es mayor a 0 pasara 
        {//a poner finalizado en 0
            finalizado = 0;
        }
        else
        {//mientras que sino el tiempo promedio sera la suma del nq * el quantum
            tiempoPromedio += nq * quantum;
        }
    }//por ultimo imprimira los procesos con el printf
    printf("\n");
    printf("\nLa suma de los procesos %2.1f", tiempoPromedio);
    tiempoPromedio = tiempoPromedio / np;
    printf("\n\nTiempo promedio en Prioridad fue de: %2.2f", tiempoPromedio);
}
//UTILIZAMOS PRINTF EN VEZ DE COUT, ya que algunas veces nos saldra un resultado
//de 0 con decimales, y gracias al printf podemos imprimri con un formato mas preciso
//y con los decimales que querramos.