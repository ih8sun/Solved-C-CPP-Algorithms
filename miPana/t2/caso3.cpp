#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <cmath>
#include <string.h>
#include <algorithm>
#define MayorFinal 999999
#define maxSize 100
using namespace std;

int matrizFinal[maxSize][maxSize];
 
int SecuenciaDeElementos(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (matrizFinal[i][j] != -1)
    {
        return matrizFinal[i][j];
    }

    matrizFinal[i][j] = MayorFinal;

    for (int k = i; k < j; k++)
    {
        matrizFinal[i][j] = min(matrizFinal[i][j], SecuenciaDeElementos(p, i, k) + SecuenciaDeElementos(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    
    return matrizFinal[i][j];

}
int SecuenciaInicializada(int* p, int n)
{
    int i = 1, j = n - 1;
    return SecuenciaDeElementos(p, i, j);
}
 
// Driver Code
int main()
{

    int n;
    
    
    cout<<"\n\n\t\t[ DEFINICION DIMENSION DE MATRIZ ]\n\n";
    cout<<"Ingresa n : ";
    cin>>n;

    int array[n];

    cout<<"\n\n\t\t[ ENTRADA DE PESOS ]\n\n";
    for(int i = 0; i < 3; i++){
        cout<<"Ingresa Peso ["<<i<<"] : ";
        cin>>array[i];
    }

    //Inicializamos valores
    memset(matrizFinal, -1, sizeof matrizFinal);
 
    int final = SecuenciaInicializada(array,n);
    cout<<"\n\n\t\t[ RESULTADO FINAL ]\n";
    cout<<"\nNumero minimo de multiplicaciones es -> "<<final<<endl<<endl;
    getch();
}