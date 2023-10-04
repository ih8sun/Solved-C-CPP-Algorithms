#include <iostream>
#include <math.h>
#include <time.h> 
#include <stdlib.h>

using namespace std;
// aca creamos la funcion potencia e ingresamos como aprametro a x e y 
int potencia(int x, int y) {
	if(y == 0){// si y es igual a cero 
		return 1;	// entonces retonar a 1 
	}
	// si es todo lo contrario 	
	else if (y == 1){// y es igual a 1 
		return x;// entonces retorna a x 
	}
		// sino 
	else{
		return(x * potencia(x, y-1));// aca retorna a x por potencia dentro de 
		// ello ingreso como parametros a x e y-1 
	}
}
// aca creamos la funcion de digitos
int Digitos (int n, int dig) {// ingresamos como parametro a n y dig 
	if(n < 10){// si n es menor a 10 
		return (dig+1);// entonces retorna a dig +1 
	}	
	// sino 
	else {
		dig++;// aca acum la varible dig 
		return(Digitos(n/10, dig));// aca hacemo retornar digitos y dentro de ello ingresamos a n/10 y dig 
	}
}
// cremos la funcion rigth y colocamos como parametro digi y numero 
int right(int digitos, int numero) {
	return numero % potencia(10, digitos);// aca retonamos 
}
// creamos la funcion left e ingresmoa parametro como dig y numero
int left(int digitos, int numero) {
	return numero/potencia(10, digitos);// aca retornamos 
}
 // aca creamos una funcion long que es un entero largo 
long long int multiplicar(int u, int v) {// ingresamos como parametro el u y v
	long long int dig1=0, dig2=0, p, q, r, numDigitos;
  	
	numDigitos = max(Digitos(u, dig1), Digitos(v, dig2));
    //  aca vemos si el numerodedigitos es menor igual a 1 	
	if (numDigitos <= 1){
		return u*v;// entonces aca retorna a u x v 
	}
	// aca el numerodigitos seria igual a la suma de los dos datos 
	numDigitos = (numDigitos / 2) + (numDigitos % 2);
	
	int w = left(numDigitos, u);
	int x = right(numDigitos, u);
	int y = left(numDigitos, v);
	int z = right(numDigitos, v);
	
	p = multiplicar(w, y);
	q = multiplicar(x, z);
	r = multiplicar(w+x, y+z);
	
	return potencia(10, 2*numDigitos)*p+potencia(10, numDigitos)*(r-p-q)+q;
}
// cabecera principal del programa 
int main(){
	// aca creamos un long para que se ingrese enteros largos como 
	// 32 bits que es igual a 4 bits 
	long long int a,b;
	// aca ingresamos los datos a pedir al usuario 
	cout<<"\n\tMULTIPLICACION DE NUMEROS GRANDES";
	cout<<"\n\nDigite los numeros a multiplicar";
	cout<<"\n\n[numero 1]: ";
	cin>>a;
	cout<<"[numero 2]: ";
	cin>>b;
	// aca mostramos los datos de la multiplicacion de los numeros 
	cout<<"\n[resultado]: "<<multiplicar(a,b);
}
