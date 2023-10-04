//Mediana y moda de un vector
#include<iostream>

using namespace std;

int n;

void inicio(){
	inicio:;
	cout<<"Ingresar extension del vector: ";
	cin>>n;
	if(n<=0){
		cout<<"Hay un error, ingresar nuevamente. . ."<<endl<<endl;
		goto inicio;
	}
}

void ingresa_datos(float vector[]){
	for(int i = 0;i < n;i++){
		cout<<"Ingresar numero "<<i+1<<": ";
		cin>>vector[i];
	}
}

void mostrar_datos(float vector[],int t){
	for(int i = 0;i < t;i++){
		cout<<vector[i]<<" ";
	}
	cout<<endl;
}

void quicksort(float vector[],int izq,int der){
	int i,j;
	float pivot,temp;
	i = izq; j = der;
	pivot = vector[(izq+der)/2];
	
	cout<<"pivot: "<<pivot<<endl;
	
	do{
		while((vector[i]<pivot)&&(j<=der))
			i++;
		while((pivot<vector[j])&&(j>izq))
			j--;
		if(i<=j){
			temp = vector[i];
			vector[i] = vector[j];
			vector[j] = temp;
			i++;
			j--;
		}
	}while(i<=j);
	
	mostrar_datos(vector,der);
	
	if(izq<j)
		quicksort(vector,izq,j);
	if(i<der)
		quicksort(vector,i,der);
}

void mediana(float vector[],int n){
	float med;
	
	if(n%2!=0){
		med = vector[n/2];
	} else {
		med = (float)(vector[n/2-1]+vector[n/2])/2;
	}
	
	cout<<"\nLa mediana es: "<<med;
}

void moda(float vector[],int n){
	int cont1,cont2;
	cont1 = cont2 = 0;
	float mod;
	
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(vector[i] == vector[j] && j!=i){
				cont1++;
			}
		}
		
		if(cont1>cont2){
			cont2 = cont1;
			mod = vector[i];
		}
	}
	
	if(cont2>1){
		cout<<"\nLa moda es: "<<mod;
	} else {
		cout<<"\nNo existe moda";
	}
	
}

int main(){
	
	inicio();
	
	float vector[n];
	
	ingresa_datos(vector);
	cout<<"\nVector en orden inicial: "<<endl;
	mostrar_datos(vector,n);
	
	quicksort(vector,0,n-1);
	
	cout<<"\nVector ordenado: "<<endl;
	mostrar_datos(vector,n);
	
	mediana(vector,n);
	cout<<endl;
	moda(vector,n);
}
