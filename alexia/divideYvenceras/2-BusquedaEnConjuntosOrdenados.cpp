#include <iostream>

using namespace std;

void ingresar_datos(int ar[], int t){

	for(int i=0; i<t; i++){

  	cout<<"ingrse numero "<<i+1<<": ";
  	cin>>ar[i];
	}
}

void quicksort(int ar[],int izq, int der){

	int i, j, pivot, tmp;

	i=izq;

	j=der;

	pivot=ar[(izq+der)/2];

	do{
		while((ar[i]<pivot) && (j<=der)){
			i++;
		}

		while((pivot<ar[j]&&(j>i))){
			j--;
		}

		if(i<=j){
			tmp=ar[i];
			ar[i]=ar[j];
			ar[j]=tmp;
			i++;
			j--;
		}

	}while(i<=j);

	if(izq<j){
		quicksort(ar,izq,j);

	}

	if(i<der){
		quicksort(ar,i,der);
	}
}

void mostrar_datos(int ar[], int t){

	for(int i=0; i<t; i++){
		cout<<ar[i]<<"\t";
	}

	cout<<endl;
}

int busqueda_binaria_recur(int A[], int ini, int fin, int num){
	
	int	mitad = (ini+fin)/2;
	
	while((ini <= fin) && (A[mitad] != num)){

		if(num < A[mitad]){
			fin = mitad-1;
			busqueda_binaria_recur(A, ini, fin, num);

		}else{
			ini = mitad+1;
			busqueda_binaria_recur(A, ini, fin, num);
		}
		mitad=(ini+fin)/2;
	}
	return mitad;
}

int main(){

  int n; 

	cout<<"ingrese cantidad: ";
	cin>>n;
	
	int A[n];

	ingresar_datos(A,n);
	quicksort(A, 0, n-1);//ordenamiento quicksort
	mostrar_datos(A,n);
	
	//Busqueda
	int num;
	int ini=0;
	
	cout<<"\nIngrese el numero que desea buscar: ";
	cin>>num;
	
	int com=busqueda_binaria_recur(A, ini, n, num);
	if(A[com] == num){
		cout<<"\nEl numero "<<num<<" se encuentra en la posicion "<<com+1;

	}else{
		cout<<"\nEl numero no se encontro en el arreglo "<<endl;
	}
	
}

