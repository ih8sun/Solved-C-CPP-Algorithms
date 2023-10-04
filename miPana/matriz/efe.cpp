#include <iostream>
using namespace std;

int matOrder(int numerosAintroay[], int n)
{
    //Creamos nueva matriz con el tamanio de N; (n - numeros de elementos)
    int nuevaMatriz[n][n];


    for (int i = 1; i < n; i++)
        nuevaMatriz[i][i] = 0; //for multiplication with 1 matrix, cost is 0

    for (int nuevoTam = 2; nuevoTam < n; nuevoTam++)
    { 
        for (int i = 1; i < n - nuevoTam + 1; i++)
        {
            int j = i + nuevoTam - 1;
            nuevaMatriz[i][j] = INT_MAX; //set to infinity

            for (int k = i; k <= j - 1; k++)
            {
                //store cost per multiplications
                int q = nuevaMatriz[i][k] + nuevaMatriz[k + 1][j] + numerosAintroay[i - 1] * numerosAintroay[k] * numerosAintroay[j];
                if (q < nuevaMatriz[i][j]) //TAM MAXIMO
                    nuevaMatriz[i][j] = q;
            }
        }
    }

    return nuevaMatriz[1][n - 1];
}


int main()
{
    int numerosAintro[] = {5,89,3};
    int tam = sizeof numerosAintro/sizeof numerosAintro[0];


    cout << "Minimum number of matrix multiplications: " << matOrder(numerosAintro, tam);
}