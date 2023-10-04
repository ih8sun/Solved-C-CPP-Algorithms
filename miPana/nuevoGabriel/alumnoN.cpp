#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <conio.h>

using namespace std;


int main(){

    int n;
    int j = 1;
    cout<<"Ingresa cantidad : ";
    cin>>n;

    string cadena[n];

    cout<<"\n\n\t\tINTRODUCIENDO NUMEROS\n\n";
    


    for(int i = 0; i < n-1; i++){
        fflush(stdin);
        getline(cin,cadena[i]);
    }

    cout<<endl;
    for(int i = 0; i < n-1; i++){
        if(cadena[i] != to_string(i+1)){
            cout<<i+1<<endl;
            break;
        }else{
            continue;
        }
    }



}