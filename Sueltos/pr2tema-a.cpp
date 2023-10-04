#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int tamMatriz = 10;

void genera_y_muestra_matriz(char matriz[tamMatriz][tamMatriz])
{
    srand(time(NULL));
    const char letrasMayusculas[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < tamMatriz; ++i)
    {
        for (int j = 0; j < tamMatriz; ++j)
        {
            matriz[i][j] = letrasMayusculas[rand() % (sizeof(letrasMayusculas) - 1)];
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}


string genera_palindromo()
{
    string palindromo;
    int tamano = rand() % 3 + 3; 

    for (int i = 0; i < tamano / 2; ++i)
    {
        char letra = 'A' + rand() % 26; 
        palindromo += letra;
    }

    
    if (tamano % 2 != 0)
    {
        char letra = 'A' + rand() % 26;
        palindromo += letra;
    }

    
    for (int i = palindromo.size() - 2; i >= 0; --i)
    {
        palindromo += palindromo[i];
    }

    return palindromo;
}

void frecuencia_cantidad_veces(const char matriz[tamMatriz][tamMatriz], const string &palindromo)
{
    int frecuencias[26] = {0};

    for (int i = 0; i < tamMatriz; ++i)
    {
        for (int j = 0; j < tamMatriz; ++j)
        {
            char letra = matriz[i][j];
            for (char c : palindromo)
            {
                if (c == letra)
                {
                    frecuencias[letra - 'A']++;
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i)
    {
        if (frecuencias[i] > 0)
        {
            cout << "Carácter " << char('A' + i) << " aparece = " << frecuencias[i] << " veces" << endl;
        }
    }
}

void palindromo_en_matriz(const char matriz[tamMatriz][tamMatriz], const string &palindromo)
{
    int apariciones_totales = 0;

    cout << "Los puntos donde aparece el palindromo en forma vertical son:" << endl;

    for (int i = 0; i <= tamMatriz - palindromo.size(); ++i)
    {
        for (int j = 0; j < tamMatriz; ++j)
        {
            bool encontrado = true;
            int apariciones = 0;
            for (int k = 0; k < palindromo.size(); ++k)
            {
                if (matriz[i + k][j] != palindromo[k])
                {
                    encontrado = false;
                    break;
                }
                apariciones++;
            }
            if (encontrado)
            {
                apariciones_totales += apariciones;
                cout << "• Fila: " << i << ", Columna: " << j << endl;
            }
        }
    }

    cout << "Total de apariciones: " << apariciones_totales << endl;
}

int main()
{
    char matriz[tamMatriz][tamMatriz];
    string palindromo;

    genera_y_muestra_matriz(matriz);
    cout << endl;

    palindromo = genera_palindromo();
    cout << "El tamanio del palindromo: " << palindromo.size() << endl;
    cout << "El palindromo generado: " << palindromo << endl;
    cout << endl;

    frecuencia_cantidad_veces(matriz, palindromo);
    cout << endl;

    palindromo_en_matriz(matriz, palindromo);

    return 0;
}
