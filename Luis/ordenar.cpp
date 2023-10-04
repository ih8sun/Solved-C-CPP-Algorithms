#include <iostream>
#include <stdlib.h>
using namespace std;

void ingresarNumeros(int *&,int &);
void imprimir(int *,int);
void ordenarBurbuja(int *,int);
void ordenamientoInsercion(int *,int);
void ordenamientoSeleccion(int *,int );

int main(){


    
    int n, *num,opc;

    ingresarNumeros(num,n);
    bool salir = false;

    do{ system("cls");
        cout<<"\n\n\t\t[ MENU DE ORDENAMIENTO ]\n\n";
        cout<<"[1]. Ordenar por Burbuja\n";
        cout<<"[2]. Ordenar por Insercion\n";
        cout<<"[3]. Ordenar por Seleccion\n";
        cout<<"[?]. Ingresa : ";
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"\n\n\t\t [ ARREGLO SIN ORDENAR ]\n\n";
            imprimir(num,n);
            ordenarBurbuja(num,n);
            salir = true;
            break;
        
        case 2:
            cout<<"\n\n\t\t [ ARREGLO SIN ORDENAR ]\n\n";
            imprimir(num,n);
            ordenamientoInsercion(num,n);
            salir = true;
            break;

        case 3:
            cout<<"\n\n\t\t [ ARREGLO SIN ORDENAR ]\n\n";
            imprimir(num,n);
            ordenamientoSeleccion(num,n);
            salir = true;
            break;
        default:
            salir = false;
            break;
        }
    }while(!salir);
	
	delete [] num;//libera la memoria


    return 0;
}

void ingresarNumeros(int *&num,int &tam){


    cout<<"\n\n\t\t[ INGRESO DE DATOS ]\n\n";
    cout<<"Ingresa tamanio de num : ";
    cin>>tam;

    num = new int[tam]; // Creando num dinamico

    int i;
    cout<<endl;
    for(i = 0; i < tam; i++){
        cout<<"Ingresa numero en pos ["<<i<<"] -> ";
        cin>>num[i];
    }

}

void ordenarBurbuja(int *num,int n){

    int i,j,aux;

    for(i = 0; i < n ; i++)
        for(j = 0; j < n-1; j++)
            if(num[j] > num[j+1]){

                aux = num[j];
                num[j] = num[j+1];
                num[j+1] = aux;
            }
        
    


    cout<<"\n\n\t\t[ ARREGLO ORDENADO POR BURBUJA ]\n\n";

    imprimir(num,n);
    cout<<endl;
}

void ordenamientoInsercion(int *num,int tam){

    int aux,i,j;

	for (i = 1; i < tam; i++){	   
		aux = *(num+i);
		j = i-1;
		while (j >= 0 && *(num+j) > aux){
			*(num+j+1) = *(num+j);
			j = j-1;
		}
		*(num+j+1) = aux;
	}    

    cout<<"\n\n\t\t[ ARREGLO ORDENADO POR INSERCION ]\n\n";
    imprimir(num,tam);

}

void ordenamientoSeleccion(int *num,int tam){

    int minimo=0,i,j;
    int aux;

    for(i=0 ; i<tam-1 ; i++)
    {
        minimo=i;
        for(j=i+1 ; j<tam ; j++){
            if (num[minimo] > num[j]) 
            minimo=j;
        }
        aux=num[minimo];
        num[minimo]=num[i];
        num[i]=aux;
    }
    
    cout<<"\n\n\t\t[ ARREGLO ORDENADO POR SELECCION ]\n\n";
    imprimir(num,tam);

}

void imprimir(int *num,int n){

    for(int i = 0; i < n; i++){
        cout<<num[i]<<"   ";
    }
}