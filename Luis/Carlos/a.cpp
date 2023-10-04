#include <string>
#include <iostream>
using namespace std;

bool esPrimo(int numero)
{
    // Casos especiales
    if (numero == 0 || numero == 1 || numero == 4)
        return false;
    for (int x = 2; x < numero / 2; x++)
    {
        if (numero % x == 0)
            return false;
    }
    // Si no se pudo dividir por ninguno de los de arriba, sí es primo
    return true;
}

int main()
{

    int min = 18;
    int max = 40;
    int tam = 0;
    bool ultimo = false;
    for (int i = min; i <= max; i++)
        if (i % 2 == 0)
            tam++;
    int *arreglo = new int[tam];
    int j = 0;

    for (int i = min; i < max; i++)
        if (i % 2 == 0)
        {
            arreglo[j] = i;
            j++;
        }

    
    

    return 0;
}