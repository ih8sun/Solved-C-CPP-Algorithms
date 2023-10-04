#include <iostream>
using namespace std;

int main(){

    int n,m,j;
    cout<<"Ingresa N : ";
    cin>>n;
    cout<<"Ingresa M : ";
    cin >> m;

    int matriz[n][m];
    int total = 0;

    for(int i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cout<<"Ingesa Numero en pos ["<<i<<"]["<<j<<"] : ";
            cin>>matriz[i][j];
        }
        cout<<endl;
    }

    for(int i = 0; i < n; i++){
        for(j = 0; j < m ; j++){
            total += matriz[i][j];
        }
    }

    cout<<"\nLa suma total de los elementos es de : "<<total<<endl;

    return 0;
}