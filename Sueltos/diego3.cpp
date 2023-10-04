#include <iostream>
#include <stdlib.h>
using namespace std;

char digitos[2];

int convertirNumero(){

    int x;

    x = atoi(digitos);

    return x;
}

void comprobarMultiplo(int x){

    if(x % 8 == 0){
        cout<<x<<" es multiplo de 8"<<endl;
    }else{
        cout<<x<<" no es multiplo de 8"<<endl;

    }

}

int main(){

    cout<<"\n\n\t\t[ DOS DIGITOS ]\n\n";
    cout<<"Ingresa Numero : ";
    fflush(stdin);
    cin>>digitos;

    int x = convertirNumero();


    comprobarMultiplo(x);


    return 0;
}
