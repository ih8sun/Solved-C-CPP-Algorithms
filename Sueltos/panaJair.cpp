#include <iostream>

using namespace std;

int main()

{

    int arreglos[4][4];

    const int cantidadFilas = 4;

    const int cantidadColumnas = 4;

    int mayor = 0;

    int menor = 0;

    int columna1 = 1, columna2 = 2, columna3 = 3, columna4 = 4;

    int fila1 = 1, fila2 = 2, fila3 = 3, fila4 = 4;

    int i, j;

    for (int j = 0; j < cantidadFilas; j++)

    {

        for (int i = 0; i < cantidadColumnas; i++)

        {

            cout << "Introduzca elemento [" << j << "][" << i << "]: ";

            cin >> arreglos[j][i];
        }

        cout << endl;
    }

    for (int i = 0; i < cantidadFilas; i++)

    {

        for (int j = 0; j < cantidadColumnas; j++)

        {

            cout << arreglos[i][j] << ' ';
        }

        cout << endl;
    }

    for (int i = 0; i < 4; i++)

    {

        for (int j = 0; j < 4; j++)

        {

            if (j == 0)
            {

                mayor = arreglos[j][i];

                columna1 = j;
            }

            if (arreglos[j][i] > mayor)

            {

                mayor = arreglos[j][i];

                columna1 = j;
            }

            if (j == 0)

            {

                mayor = arreglos[j][i];

                columna2 = j;
            }

            if (arreglos[j][i] > mayor)

            {

                mayor = arreglos[j][i];

                columna2 = i;
            }

            if (j == 0)

            {

                mayor = arreglos[j][i];

                columna3 = j;
            }

            if (arreglos[j][i] > mayor)

            {

                mayor = arreglos[j][i];

                columna3 = j;
            }

            if (j == 0)

            {

                mayor = arreglos[j][i];

                columna4 = j;
            }

            if (arreglos[j][i] > mayor)

            {

                mayor = arreglos[j][i];

                columna4 = j;
            }
        }

        if (i == 0)
        {

            menor = arreglos[j][i];

            fila1 = i;
        }

        if (arreglos[j][i] > menor)

        {

            menor = arreglos[j][i];

            fila1 = i;
        }

        if (i == 0)

        {

            menor = arreglos[j][i];

            fila2 = i;
        }

        if (arreglos[j][i] < menor)

        {

            menor = arreglos[j][i];

            fila2 = i;
        }

        if (i == 0)

        {

            menor = arreglos[j][i];

            fila3 = i;
        }

        if (arreglos[j][i] < menor)

        {

            menor = arreglos[j][i];

            fila3 = i;
        }

        if (i == 0)

        {

            menor = arreglos[j][i];

            fila4 = i;
        }

        if (arreglos[j][i] < menor)

        {

            menor = arreglos[j][i];

            fila4 = i;
        }
    }

    cout << "LA FILA CON EL VALOR MENOR ES: \t[" << fila4 << "]"
         << "\t" << menor << "\t" << endl;

    cout << "LA COLUMNA CON EL VALOR MAYOR ES: \t[" << columna4 << "]"
         << "\t" << mayor << "\t" << endl;

    return 0;
}