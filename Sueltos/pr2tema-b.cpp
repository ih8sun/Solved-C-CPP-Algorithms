#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void genera_y_muestra_matriz(char matriz[10][10])
{
    // Semilla para la generación de números aleatorios
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Genera un número aleatorio entre 65 y 90 (código ASCII para letras mayúsculas)
            matriz[i][j] = static_cast<char>(rand() % 26 + 65);
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

string generarPalindromo()
{
    string palindromo;

    // Generar un número aleatorio entre 3 y 5 para la longitud del palíndromo
    srand(time(0));
    int longitud = rand() % 3 + 3;

    // Generar los caracteres aleatorios en mayúscula
    for (int i = 0; i < longitud / 2; i++)
    {
        char letra = 'A' + rand() % 26;
        palindromo += letra;
    }

    // Agregar el caracter del medio si la longitud es impar
    if (longitud % 2 == 1)
    {
        char letra = 'A' + rand() % 26;
        palindromo += letra;
    }

    // Agregar los caracteres en orden inverso para que sea un palíndromo
    for (int i = longitud / 2 - 1; i >= 0; i--)
    {
        palindromo += palindromo[i];
    }

    return palindromo;
}

void insertarMatriz(char matriz[10][10], string palindromo)
{
    srand(time(NULL));

    int fila = 2;
    int columna = rand() % 6;
    for (int i = 0; i < palindromo.size(); i++)
    {
        matriz[fila][columna++] = palindromo[i];
    }
}

void frecuencia_cantidad_veces(char matriz[][10], string palindromo)
{
    int frecuencia[26] = {0}; // Inicializar todas las frecuencias a 0

    // Calcular la frecuencia de cada carácter del palíndromo en la matriz
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (char c : palindromo)
            {
                if (matriz[i][j] == c)
                {
                    frecuencia[c - 'A']++; // Incrementar la frecuencia del carácter encontrado
                }
            }
        }
    }

    // Mostrar la cantidad de veces que aparece cada carácter
    for (int i = 0; i < palindromo.size(); i++)
    {
        cout << "El caracter " << palindromo[i] << " aparece " << frecuencia[palindromo[i] - 'A'] << " veces." << endl;
    }
}
void palindromo_en_matriz(char matriz[][10], string palindromo)
{
    int contadorTotal = 0;

    // Buscar el palíndromo fila por fila en la matriz
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= 10 - palindromo.size(); j++)
        {
            bool encontrado = true;
            for (int k = 0; k < palindromo.size(); k++)
            {
                if (matriz[i][j + k] != palindromo[k])
                {
                    encontrado = false;
                    break;
                }
            }
            if (encontrado)
            {
                contadorTotal++;
                cout << "Palíndromo encontrado en la fila " << i << ", columna de inicio: " << j << endl;
            }
        }
    }

    // Mostrar la cantidad total de apariciones del palíndromo
    if (contadorTotal > 0)
    {
        cout << "Total de apariciones del palíndromo: " << contadorTotal << endl;
    }
    else
    {
        cout << "El palíndromo no se encuentra en la matriz." << endl;
    }
}

int main()
{
    char matriz[10][10];
    string palindromo = generarPalindromo();
    genera_y_muestra_matriz(matriz);
    insertarMatriz(matriz, palindromo);

    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << palindromo << endl;

    frecuencia_cantidad_veces(matriz, palindromo);

    palindromo_en_matriz(matriz, palindromo);

    return 0;
}
