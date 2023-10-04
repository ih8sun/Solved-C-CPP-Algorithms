#include <iostream>
#include <conio.h>
using namespace std;
// aca creamos las variables e inicalizamos 
int Array[100]={0};
int c[]={1,10,100,1000,10000,100000,1000000};
int a[8]={0};
int a1[8]={0};
int b[8]={0};
int b1[8]={0};
int cont=0;
int a_cant=1;
int b_cant=1;
int resultante[100]={0};

// aca creamos la funcion suma_valor donde ingresamos como parametros
// int q y int w 
void suma_valor(int q, int w){
	int val1=0;// aca igualamos la variable val1=0
	int val2=0;// aca igaulamos la variable val2=0
	int resultado;// creamos la varible rsutlado pra mostrar el resultado 
	int tmp=0;// aca creamos un archivo temporal y lo igualamos a cero 
	// creamos un for para hacer el bucle 
	for(int z1=0;z1<8;z1++){
		for(int z2=0;z2<8;z2++){
			resultante[tmp]=a1[z1]*b1[z2];// aca mostramos la resultante del archivo temporal que es igual a la multiplicacion de los dos arrays
			tmp++;// aca acumulamos el archivo temporal 
		}
	}
	// aca creamos un for de y y mostramos el resultado que es igual al resultado +el resultante de arrary y 
	for(int y=0;y<100;y++){
		resultado=resultado+resultante[y];
	}// luego aca mostramos las 3 datos de q w y el resultado final 
	cout<<"el valor de q es : "<<q<<endl;
	cout<<"el valor de w es : "<<w<<endl;
	cout<<"el resultado es :"<<resultado<<endl;
}

// aca creamos una funcion de la multiplicacion 
void multiplicacion(int q, int w){// aca ingresamos como parametro el q y w 
	
	if(q>=10){// si q es mayor igual q 10 entonces 
		a[cont]=q/c[(a_cant-1)];// aca sera a =  q entre c y dentro de ello colocamos el inicalizamos que es 100
		a1[cont]=a[cont]*c[a_cant-1];
		q=q-a[cont]*c[a_cant-1];
	}

	if(w>=10){// si w es mayor igual a 10 entonces mostrara 
		b[cont]=w/c[b_cant-1];
		b1[cont]=b[cont]*c[b_cant-1];
		w=w-b[cont]*c[b_cant-1];
	}
	// si q es menor que 10 y w es menor que 10 entonces 
	if(q<10 & w<10){
		cont++;// se colocara un contador 
		a1[cont]=q;// luego aca inicializaremos en q
		b1[cont]=w;// luego aca inicializaremos en w 
		return suma_valor(q,w);// y aca retornamos a suma_valor de q y w 
	}
	cont++;// aca mostramos el contador 
	a_cant--;// tambien llamamos a varible a_cant
	b_cant--;// tambien llamamos a variable b_cant
	multiplicacion(q,w);// y llamamos a multiplicacion q y w 
	
}
// aava creamos el procedimiento de contador de cifras
void contador_cifras(int a,int b){// ingresmos como parametro a y b 
	while(a >=10){// mientras que a sea mayor igual q 10 
		a=a/10;// aca seria a = a entre 10 
		a_cant++;// aca colocamos el a_cant
	}
	while(b >=10){// mientras que b sea mayor igual a 10 
		b=b/10;// aca seria b = b entre 10 
		b_cant++;// aca coloacmos el b_cant
	}
}
// aca seria la cabecera principal
int main(){
	int a0,b0;// creamos variables a0 y b0 
	// ingresmos las varibles 1 y 2 de numero grandes
	cout<<"Ingrese numero 1: ";
	cin>>a0;
	cout<<"Ingrese numero 2: ";
	cin>>b0;

	//multiplicacion de numero enteros
	contador_cifras(a0,b0);
	cout<<"la cantidad de cifras del primer numero es : "<<a_cant<<endl; 
	cout<<"la cantidad de cifras del segundo numero es : "<<b_cant<<endl; 
	multiplicacion(a0,b0);
	// aca creamos un bucle para mostrar la posicion a1  y b1
	for(int l=0;l<8;l++){
       cout<<"array a1 en posicion " <<l<<" : "<<a1[l]<<endl;
       cout<<"array b1 en posicion " <<l<<" : "<<b1[l]<<endl;
  	}
  	cout<<"--------------------------------------"<<endl;
  	for(int l1=0;l1<8;l1++){
       cout<<"array a en posicion " <<l1<<" : "<<a[l1]<<endl;
       cout<<"array b en posicion " <<l1<<" : "<<b[l1]<<endl;
  	}
}
