#include<iostream>
using namespace std;
 
void bidi(int n)
{
    int arr[n][n];
    for (int l = 0; l <= n; l++)
    {
        for (int i = 0; i <= l; i++)
        {
        if (l == i || i == 0)
            arr[l][i] = 1;
        else
            arr[l][i] = arr[l - 1][i - 1] + arr[l - 1][i];
        cout << arr[l][i] << " ";
        }
        cout << "\n";
    }
}
 
int main()
{
    int n;
	cout<<" Ingrese el coeficiente binomial : "<<endl;
	cin>>n;
	cout<<"------------------------------------triangulo de pascal ----------------"<<endl;
    bidi(n);
    return 0;
}


int pascal(int row, int col) {
  if (col == 0 || col == row) {
    return 1;
  } else {
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
  }
}