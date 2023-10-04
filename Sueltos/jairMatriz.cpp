
#include <iostream>
#define fila 4
#define col 4
using namespace std;

int main(){ 
    int i = 0,j=0,matriz[fila][col], numFila,numCol;
    int numMayor = 0,numMenor;
    cout<<"\n\n\t\t[ INGRESO DE DATOS MATRIZ ] \n\n";

    for(i = 0; i < fila ;i++){
        for(j = 0; j < col ;j++){
            cout<<"Ingresa elemento en pos ["<<i<<"]["<<j<<"] : ";
            cin>>matriz[i][j];
        }
        cout<<"\n";
    }


    
    cout<<"\n\n\t[ MATRIZ IMPRESA ] \n\n";
    for(i = 0; i < fila; i++){
        cout<<"\t"<<i;
    }
    cout<<endl<<endl;
    for(i = 0 ; i < fila ; i++){
        cout<<i<<"->\t";
        for(j = 0; j < col ; j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<"\n";
    } 

    
    numMenor = matriz[0][0];

    for(i = 0 ; i < fila ; i++){
        for(j = 0; j < col ; j++){
            if(numMenor >= matriz[i][j]){
                numMenor = matriz[i][j];
                numFila = i;
            }
        }
    }

    for(i = 0 ; i < fila ; i++){
        for(j = 0; j < col ; j++){
            if(numMayor < matriz[i][j]){
                numMayor = matriz[i][j];
                numCol = j;
            }
        }
    }
    cout<<"\n\nRESULTADOS\n\n";
    cout<<"Numero Mayor : "<<numMayor<<endl;
    cout<<"Numero de Columna :"<<numCol<<endl<<endl;
    cout<<"Numero Menor : "<<numMenor<<endl;
    cout<<"Numero de Fila : "<<numFila<<endl<<endl;
    return 0;
}