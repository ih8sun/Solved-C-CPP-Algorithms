
#include <iostream>
using namespace std;

void genera_y_muestra_matriz(char matriz[10][10])
{

    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            matriz[i][j] = static_cast<char>(rand() % 26 + 65);
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

string generarPalindromo()
{
    string palindromo;

    srand(time(0));
    int longitud = rand() % 3 + 3;

    for (int i = 0; i < longitud / 2; i++)
    {
        char letra = 'A' + rand() % 26;
        palindromo += letra;
    }

    if (longitud % 2 == 1)
    {
        char letra = 'A' + rand() % 26;
        palindromo += letra;
    }

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
    int frecuencia[26] = {0};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (char c : palindromo)
            {
                if (matriz[i][j] == c)
                {
                    frecuencia[c - 'A']++;
                }
            }
        }
    }

    for (int i = 0; i < palindromo.size(); i++)
    {
        cout << "El caracter " << palindromo[i] << " aparece " << frecuencia[palindromo[i] - 'A'] << " veces." << endl;
    }
}

void palindromo_en_matriz(char matriz[][10], string palindromo)
{
    int contadorTotal = 0;

    for (int j = 0; j <= 10 - palindromo.size(); j++)
    {
        bool encontrado = true;
        for (int k = 0; k < palindromo.size(); k++)
        {
            if (matriz[2][j + k] != palindromo[k])
            {
                encontrado = false;
                break;
            }
        }
        if (encontrado)
        {
            contadorTotal++;
        }
    }

    if (contadorTotal > 0)
    {
        cout << "Palíndromo encontrado en la fila 2 en las siguientes posiciones:" << endl;
        for (int j = 0; j <= 10 - palindromo.size(); j++)
        {
            bool encontrado = true;
            for (int k = 0; k < palindromo.size(); k++)
            {
                if (matriz[2][j + k] != palindromo[k])
                {
                    encontrado = false;
                    break;
                }
            }
            if (encontrado)
            {
                cout << "(" << 2 << ", " << j << ")" << endl;
            }
        }
        cout << "Total de apariciones del palíndromo: " << contadorTotal << endl;
    }
    else
    {
        cout << "El palíndromo no se encuentra en la fila 2 de la matriz." << endl;
    }
}

void muestra_matriz(char matriz[][10], string palindromo)
{

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
}

int main()
{
    char matriz[10][10];
    string palindromo = generarPalindromo();
    genera_y_muestra_matriz(matriz);
    insertarMatriz(matriz, palindromo);
    system("cls");
    muestra_matriz(matriz, palindromo);

    frecuencia_cantidad_veces(matriz, palindromo);

    palindromo_en_matriz(matriz, palindromo);

    return 0;
}
