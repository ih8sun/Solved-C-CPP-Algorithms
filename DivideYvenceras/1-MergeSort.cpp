#include <iostream>
#define size 100

using namespace std;

//Arreglos globales
int vec[size];
int tmp[size];

void MergeSort(int ini , int fin){
	
	//Si inicio es igual a final significa que solo tengo un elemento y el vector ya esta ordenado
	if(ini == fin){
		return;
	}
	
	//definir medio
	int medio = (ini + fin)/2;
	
	//dividiendo el trabajo
	MergeSort(ini , medio);
	MergeSort(medio+1 , fin);
	
	//Valriables apuntando a los primeros vectores
	int p1 = ini;
	int p2 = medio +1;
	
	//Puntero que maneja cual es la siguiente posicion a guardar en el vetor ordeado
	int pos = ini;
	
	//Mientras los 2 vectores sigan teniendo elementos
	while(p1 <= medio && p2 <= fin){
		if(vec[p1] < vec[p2]){
			tmp[pos] = vec[p1];
			p1++;
		}else{
			tmp[pos] = vec[p2];
			p2++;
		}
		pos++;
	}
	//Si p1 o p2 se han acabado los datos
	//Copiamos el contenido del vector que tiene datos en el vector de respuesta
	while(p1 <= medio){
		tmp[pos++] = vec[p1++];
	}
	while(p2 <= fin){
		tmp[pos++] = vec[p2++];
	}
	
	//Igualando valores del vector ordenado
	for(int i=ini ; i<=fin ; i++){
		vec[i] = tmp[i];
	}
}

void MostrarOrden(int n){
	for(int i=0 ; i < n ; i++){
		cout<<vec[i]<<" ";
	}
}

int main(){
	int n;
	
	//Ingresar la cantidad de numeros a ordenar
	cout<<"Ingrese cantidad: ";
	cin>>n;
	
	//Ingresando números
	for(int i=0 ; i < n ; i++){
		cin>>vec[i];
	}
	
	cout<<endl<<"Desordenado: "<<endl;
	MostrarOrden(n);//Mostrar orden
	
	MergeSort(0 , n-1);//Ordenamiento Mergesort
	
	cout<<endl<<endl<<"Ordenado: "<<endl;
	MostrarOrden(n);//Mostrar orden
	cout<<endl<<endl;
	
	system("pause");
	
	return 0;
}
