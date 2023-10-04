#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;
// La función para integrar
double funcion(double x)
{
    double denom = sqrt(x);
    return denom;
}
double obtenerAleatorioDecimal(double r1, double r2)
{

    double decimal;
    int x = (int)r1;
    int y = (int)r2;
    srand((unsigned)time(NULL));

    decimal = (float)(rand() % (x - y)) + y;
    return decimal;
}
int main()
{
    // Declara constantes locales
    int x1, x2, y1, y2, n;
    int contador = 0;
    double area, areat, x, y, w, r, r2, w2;
    cout << "ingrese las acotaciones :" << endl;
    cout << "x1:";
    cin >> x1;
    cout << "\nx2:";
    cin >> x2;
    cout << "\ny1:";
    cin >> y1;
    cout << "\ny2:";
    cin >> y2;
    cout << "ingrese la cantidad n:";
    cin >> n;
    area = (x2 - x1) * (y2 - y1);
    srand((unsigned)time(NULL));

    // Se repite el número de veces indicado
    for (int i = 0; i < n; i++)
    {

        //  x =obtenerAleatorioDecimal (x2,x1);
        //y = obtenerAleatorioDecimal(y2,y1);
        r = rand() % (999) + 1;
        w = r / 1000;
        r2 = rand() % (999) + 1;
        w2 = r2 / 1000;
        x = (rand() % (x2 - x1) + x1) + w;
        y = (rand() % (y2 - y1) + y1) + w2;
        //cout<<x<<"* "<<y<<endl;//todos los puntos que se coge
        // Comprueba si los puntos son adecuados
        if (y <= funcion(x))
        {
            //cout<<x<<"- "<<y<<endl; //se fija de los puntos que estan dentro de la funcion raiz
            contador++;
        }
        //sum += funcion(x,y);
    }
    areat = area * contador / n;
    cout << "El resultado es " << areat << endl;
    cout << "los valores optimos son " << contador << endl;
}