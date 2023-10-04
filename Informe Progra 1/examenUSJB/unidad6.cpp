#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void invermat(int n, double **a, double **ainv, double &determ);

int main()
{

    system("cls");

    ifstream label1("datos.in");


    int i, j, n;

    label1 >> n;

    double **a, **ainv, determ;

    a = new double *[n], ainv = new double *[n];

    for (j = 0; j < n; j++)
    {

        a[j] = new double[n], ainv[j] = new double[n];
    }


    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {

            label1 >> a[i][j];
        }
    }

    cout << "Imprime la matriz de origen\n\n";



    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {

            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;

    invermat(n, a, ainv, determ);

    if (determ != 0)
    {

        cout << "Imprime la matriz Adjunta\n\n";


        cout.setf(ios::fixed);
        cout.precision(6);

        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {

                cout << setw(10) << ainv[i][j] << " ";
            }

            cout << endl;
        }
    }

    else
        cout << "La matriz no tiene Adjunta\n\n";

    delete a;

    return 0;
}

void invermat(int n, double **a, double **ainv, double &determ)
{


    int i, j, k;

    double factor;

    double **L, *D, *X;

    X = new double[n];
    D = new double[n];

    L = new double *[n];

    for (j = 0; j < n; j++)

        L[j] = new double[n];

    for (k = 0; k < n - 1; k++)
    {

        for (i = k + 1; i < n; i++)
        {

            factor = a[i][k] / a[k][k];

            for (j = k + 1; j < n + 1; j++)
            {

                a[i][j] = a[i][j] - factor * a[k][j];
            }
        }
    }


    determ = 1.;

    for (i = 0; i < n; i++)
    {

        determ = determ * a[i][i];
    }

    if (determ != 0)
    {



        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {

                if (i > j)
                {

                    L[i][j] = a[i][j] / a[j][j];

                    a[i][j] = 0;
                }
            }
        }

        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {

                L[j][j] = 1;
            }
        }


        for (k = 0; k < n; k++)
        {


            for (i = 0; i < n; i++)
            {

                if (i == k)
                    L[i][n] = 1;

                else
                    L[i][n] = 0;
            }



            double sum;

            D[0] = L[0][n];

            for (i = 1; i < n; i++)
            {

                sum = 0;

                for (j = 0; j < i; j++)
                {

                    sum = sum + L[i][j] * D[j];
                }

                D[i] = L[i][n] - sum;
            }


            for (i = 0; i < n; i++)
            {

                a[i][n] = D[i];
            }


            X[n - 1] = a[n - 1][n] / a[n - 1][n - 1];


            for (i = n - 2; i > -1; i--)
            {

                sum = 0;

                for (j = i + 1; j < n; j++)
                {

                    sum = sum + a[i][j] * X[j];
                }

                X[i] = (a[i][n] - sum) / a[i][i];
            }


            for (i = 0; i < n; i++)
            {

                ainv[i][k] = X[i];
            }

        } 

    }

    delete L, D, X;
}
