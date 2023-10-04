#include <iostream>
using namespace std;

int main(){

    int i,n,m,j,col;
    
    cout<<"Ingresa N : ";
    cin>>n;
    cout<<"Ingresa M : ";
    cin >> m;

    int matriz[n][m];
    int total = 0;

    for( i = 0; i < n; i++){
        for(j = 0; j < m ; j++){
            matriz[i][j] = 0;
        }
    }

    for( i = 0; i < n; i++){
        for (j = 0; j < m ;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"Ingresa alguna columna [ 0 - "<<m-1<<" ] : ";
    cin>>col;

    for(j = 0; j < n ;j++){
            cout<<"Ingesa Numero : ";
            cin>>matriz[j][col];
    }


    for( i = 0; i < n; i++){
        for (j = 0; j < m ;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}