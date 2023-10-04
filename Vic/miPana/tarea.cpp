#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define tamMax 100
using namespace std;


void menu(){

    system("Cls");

    cout<<"\n\n\t\t[ MANEJO DE DATOS ]\n\n";
    cout<<"[1]. Entrada de datos\n";
    cout<<"[2]. FIFO\n";
    cout<<"[3]. SJF\n";
    cout<<"[4]. Round Robin\n";
    cout<<"[5]. Prioridad\n";
    cout<<"[6]. Salir\n";
    cout<<"\n[?]. Ingresa una opcion: ";

}

void cargarDatos(int [],int &);
void RoundRobin(int [], int &);

int main(){

    bool salir = false;
    int opc;
    int procesos[tamMax];
    int tamUtilizado;

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            cargarDatos(procesos,tamUtilizado);
            break;
        
        case 2:
            break;

        case 3:
            break;

        case 4:
            RoundRobin(procesos,tamUtilizado);
            break;

        case 5:
            break;

        case 6:
            salir = true;
            break;
        }
    }while(salir != true);


    return 0;

}

void cargarDatos(int procesos[],int &x){

    cout<<"\n\n\t\t[ ENTRADA DE DATOS ]\n\n";

    cout<<"\nIngresa Numero de Procesos : ";
    cin>>x;

    cout<<endl;

    for(int i = 0; i < x; i++){
        cout<<"Ingresa contenido de proceso ["<<i+1<<"] : ";
        cin>>procesos[i];
    }

}

void RoundRobin(int procesos[], int &x){


    int quantum;
    bool finalizado = false;
    int nq = 0;
    float tf = 0,tp;


    while (quantum <= 0)
    {
        printf("Ingresa el tamanio del quantium:");
        scanf("%d", &quantum);
    }
    while (finalizado == 0)
    {
        finalizado = 1;
        for (int i = 0; i < x; i++)
        {
            if (procesos[i] > 0)
            {
                procesos[i] -= quantum;
                nq++;
                printf("\n Quantium[ %d ] proceso -> %d", nq, i + 1);
                if (procesos[1] > 0)
                {
                    finalizado = 0;
                }
                else
                {
                    tp += nq * quantum;
                }
            }
        }
    }

    for (int i = 0; i < x; i++)
    {
        tf += procesos[i];
        tp = tp + tf;
        printf("\nTiempo %d concluye en %.2f", i + 1, tf);
    }
    printf("\n");
    printf("\nLa suma de los procesos %.2f", tp);
    tp = tp / x;
    printf("\n\nTiempo promedio en RR fue de: %.2f\n\n", tp);

    system("pause");
}