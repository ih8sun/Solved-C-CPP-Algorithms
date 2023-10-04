#include <stdio.h>
#include <stdlib.h>

struct objeto{
	float peso;
	float valor;
	float usado;
	float valorpeso;
};

struct objeto* ReservadeMemoria(int n);
void algoritmoVoraz(struct objeto objetitos[], int n, float w);
int seleccionVorazPeso(struct objeto objetitos[], int n);

int main(){
	
	struct objeto *objetitos;
	int n,i;
	float w;
	printf("\nIngrese la cantidad de objetos: ");
	scanf("%d", &n);
	printf("\nIngrese la capacidad maxima de la mochila: ");
	scanf("%d", &w);
	objetitos = ReservadeMemoria(n);
	for(i = 0; i<n; i++){
		printf("\nIngrese el peso del objeto: ");
		scanf("%f", & objetitos[i].peso);
		printf("\nIngrese el valor del objeto: ");
		scanf("%f", &objetitos[i].valor);
		//objetitos[i].valorpeso=objetitos[i].valor/objetitos[i].peso;
		objetitos[i].usado = 0;		
	}
	algoritmoVoraz(objetitos,n,w);
	return 0;
}

struct objeto* ReservadeMemoria(int n){
	struct objeto *a;
	a=(struct objeto *)malloc(sizeof(struct objeto)*n);
	return a;
}

void algoritmoVoraz(struct objeto objetitos[], int n, float w){
	int i,id;
	float suma = 0, sumavalor = 0;
	while (suma < w){
		i = seleccionVorazPeso(objetitos,n);
		if(suma+objetitos[i].peso<w){
			suma += objetitos[i].peso;
			objetitos[i].usado = 1;
		}else{
			objetitos[i].usado=(w-suma)/objetitos[i].peso;
			suma=w;
		}
		
	}
	for(i=0; i<n ; i++){
		if(objetitos[i].usado){
			printf("\n %.2f - %.2f - %.2f",objetitos[i].usado, objetitos[i].peso, objetitos[i].valor);
			sumavalor+=objetitos[i].valor;
		}
	}
	printf("\nLa suma total es: %.2f",sumavalor);
}

int seleccionVorazPeso(struct objeto objetitos[], int n){
	int i,id;
	float mayor =9999;
	for(i = 0; i<n; i++){
		if (objetitos[i].peso<mayor && !objetitos[i].usado){
			mayor = objetitos[i].peso;
			id = i;
		}	
	}
	return id;
}