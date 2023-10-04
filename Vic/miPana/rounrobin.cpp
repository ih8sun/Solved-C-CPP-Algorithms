#include<stdio.h>

int main(int n, char **args) {
	printf("Round Robin");

	int np=11, procesos[10], quantum = 0, nq = 0;
	double tp = 0;// tiempo promedio.
	int finalizado = 0;

	
		printf("\nNumero de procesos(%d): ", np);
		scanf("%d", &np);




	for(int i=0; i<np; i++) {
		printf("\nInserte el proceso %d :", i+1);
		scanf("%d", &procesos[i]);
	}
	
	while (quantum <= 0) {
		printf("Tamaño de quantum:");
		scanf("%d", &quantum);
	}
	// Algoritmo RR
	while(finalizado == 0) {
		finalizado = 1;// Sí finalizado
		for(int i=0; i<np; i++) {
			if(procesos[i] > 0) {
				procesos[i] -= quantum;
				nq++;
				printf("\nQuantum[%d] proceso %d",nq, i+1);
				if (procesos[i]>0) {
					finalizado = 0; //No finalizado
				} else {
					tp += nq*quantum;
				}
			}
		}
	}
	tp = tp / np;
	printf("\nTiempo promedio RR %f:", tp);
	return 0;
}