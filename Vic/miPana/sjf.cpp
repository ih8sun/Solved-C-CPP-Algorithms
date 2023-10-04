#include <stdio.h>

int main(int n, char **args)
{
    printf("SJF: SHORTEST JOB FIRST");
    // cada proceso contiene dos elementos:
    //  – Posición 0 el tiempo del trabajo
    // 	– Posición 1 la posición original del proceso.
    int np = 11, procesos[10][2];
    double tf = 0, tp; // tiempo promedio.
    while (np > 10 || np <= 0)
    {
        printf("\nNumero de procesos: ");
        scanf("%d", &np);
    }
    //para i=0, mientras i<np, hacer:…
    // pedimos el tamaño de cada proceso.
    for (int i = 0; i < np; i++)
    {
        printf("\nInserte el proceso %d :", i + 1);
        scanf("%d", &procesos[i][0]);
        procesos[i][1] = i + 1;
    }
    // Algoritmo SJF
    // ordenamos de menor a mayor
    for (int i = 0; i < np - 1; i++)
    {
        for (int j = i + 1; j < np; j++)
        {
            if (procesos[j][0] < procesos[i][0])
            {
                int aux[2] = {procesos[j][0], procesos[j][1]};
                procesos[j][0] = procesos[i][0];
                procesos[j][1] = procesos[i][1];
                procesos[i][0] = aux[0];
                procesos[i][1] = aux[1];
            }
        }
    }
    for (int i = 0; i < np; i++)
    {
        tf += procesos[i][0];
        tp = tp + tf;
        printf("\nProceso %d, concluye en %2.1f", procesos[i][1], tf);
    }
    printf("\n——————————-");
    printf("\nLa suma de los procesos %2.1f", tp);
    tp = tp / np;
    printf("\n\nTiempo promedio en SJF fue de: %2.2f:", tp);
    return 0;
}