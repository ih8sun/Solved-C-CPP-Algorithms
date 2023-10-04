#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define  SIZE 20

using namespace std;

int numeroMayor(int Datos[]){
	int mayor;
	for(int i = 0; i<SIZE; i++){ 
		if(i == 0) mayor = Datos[i];
		if(Datos[i] > mayor) mayor = Datos[i];
	}
	return mayor;
}

int main(){

	int Datos[SIZE];
	int num,mitad, ini=0,fin=SIZE-1;
	int count = 0;
	int mayor=0;
	
	cout<<"\n";
	for(int i = 0; i<SIZE; i++){ //Ingresamos los datos
	 	cout<<" Ingrese numero "<<i+1<<" : ";
		cin>>Datos[i];
	}
	
	system("cls"); //Se limpia la pantalla
	cout<<"\n";
	for(int i = 0; i<SIZE; i++){ //Se muestra los datos ingresados
		cout<<"   "<<Datos[i]<<" "; 
	}
	cout<<endl<<endl;

	cout<<" Numero a buscar: ";cin>>num;	// Ingresamos número a buscar
	
	mitad= (ini+fin)/2;		//Dividimos el arreglo		
		
	while((ini <= fin) && (Datos[mitad] != num)){
		if(num < Datos[mitad]){  
			fin = mitad-1;
		}else{
			ini = mitad+1;
		}
		
		mitad = (ini+fin)/2;
		count++;
		
	}	
	
	cout<<" Numero iteraciones: "<<count+1<<endl;
	
	if(Datos[mitad] == num){
		cout<<" Numero encontrado en la posicion: "<<mitad+1<<endl;
	}else{
		cout<<" No se encontro el numero en el arreglo";
	}
	
	cout<<"\n Numero mayor : "<<numeroMayor(Datos)<<endl;

}
