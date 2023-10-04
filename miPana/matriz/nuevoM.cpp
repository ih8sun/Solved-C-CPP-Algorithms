#include <iostream>
using namespace std;
int multi(int array[], int n)
{
    int minivalor[n][n];
    for (int i = 1; i < n; i++)
        minivalor[i][i] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            minivalor[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = minivalor[i][k] + minivalor[k + 1][j] + array[i - 1] * array[k] * array[j];
                if (q < minivalor[i][j])
                    minivalor[i][j] = q;
            }
        }
    }
    return minivalor[1][n - 1];
}
int main()
{
    int size;
    cout << "ingresar el numero de matrices :";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "ingresar el peso [" << i << "] de la matriz : ";
        cin >> arr[i];
    }

    cout << "el minimo valor de la multiplicacion: " << multi(arr, size);
}