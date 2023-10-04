#include <iostream>
#include <stdio.h>
#include <stdlib.h>//con esta libreria funciona el new y delete;
using namespace std;
//prototipos
void ingresarNumeros();
void ordenarBurbuja(int, int *);
//variable global
void mostrarNumeros(int, int *);
int n, *num;

int main(){
    ingresarNumeros();
	ordenarBurbuja(n,num);
	mostrarNumeros(n,num);	
	
	delete [] num;//libera la memoria
	return 0;
}
void ingresarNumeros(){
	cout<<"Ingrese la Cantidad de Numeros: ";
	cin>>n;
	//num: elemnto 5: 5 6 8 4 1
	num=new int[n];//crear arreglo dinamico, --se reserva la memoria necesaria
	for(int i=0; i<n;i++){
		cout<<"Ingrese los num o elementos: ";
		cin>>*(num+i);//
	}	
}

void ordenarBurbuja(int n, int *num){
	int aux;
	for(int i=0; i<n;i++){
		for(int j=0; j<n-1;j++){
			if((num+j)>(num+j+1)){//num[j]>num[j+1]
				aux= *(num+j);
			    *(num+j)=*(num+j+1);
				*(num+j+1)=aux;
			}
		}
	}
}
void mostrarNumeros(int n, int *num){
	cout<<"Mostrar numeros o elementos:\n ";
	for(int i=0; i<n;i++){
		cout<<"["<<*(num+i)<<"]-";//num[i]
	}
}