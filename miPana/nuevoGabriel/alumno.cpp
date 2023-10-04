#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <ctype.h>
#include <sstream>
using namespace std;



int main(){

    int cantidad,i,j;
    bool correcto = false;
    srand (time(NULL));
    char k;
    string aux;


    cout<<"\n\n\t\t[ ALUMNO TRAVIESO ]\n\n";
    do{
    cout<<"Ingresa Tam : ";
    cin>>cantidad;

    if(cantidad >= 2 && cantidad <= 100){
        correcto = true;
    }else{
        cout<<"Ingresa un numero en el rango indicado [ 2-100 ]\n\n";
    }

    }while(correcto != true);

    string cadenaDigitos = "";
    int numAl = 2 + rand() % (cantidad+1-2);

    for(i = 1; i <= cantidad; i++){
        if(i == numAl){
            continue;
        }else{

            aux = to_string(i);
            cadenaDigitos += aux;

        }
    }
    
    cout<<"\n"<<cadenaDigitos<<endl;
    

    cout<<"Numero Faltante : "<<numAl<<endl;
    // if(cantidad < 10){
    //     for(i = 1 ; i <= cantidad; i++){
            
    //         k = '0' + i;

    //         if(cadenaDigitos[i] == k){
    //             cout<<"\n"<<k<<endl;
    //         }else{
    //             continue;
    //         }
    //     }
    // }

    return 0;
}