#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){

    cout<<"\n\n\t\t [ VENTAS ANUALES ]\n\n";
    int i,mayor = 0,pos;
    int meses[12];

    for(i = 0; i < 12; i++){
        cout<<"Ingresa total ventas en mes ["<<i+1<<"] -> ";
        cin>>meses[i];

    }

    for(i = 0; i < 12; i++){
        cout<<i+1<<". "<<meses[i]<<endl;
    }
    
    for(i = 0; i < 12; i++){
        if(mayor < meses[i]){
            mayor = meses[i];
            pos = i;
        }
    }

    cout<<"\n\n\t\t[ RESULTADOS ]\n\n";
    cout<<"El Monto Mayor recaudado fue de -> "<<mayor<<endl;
    cout<<"Este monto se registro en el mes "<<pos+1<<endl;
    cout<<"\n[Desplegando Meses]\n\n";
    for(i = 0; i < 12; i++){
        cout<<i+1<<". "<<meses[i]<<endl;
    }

    return 0;
}