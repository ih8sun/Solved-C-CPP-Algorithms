#include <iostream>
#include <stdlib.h>
using namespace std;

char pedirCaracter(){
    char c;

    cout<<"Ingresa el caracter : ";
    cin>>c;

    return c;
}

void comprobarNumero(char n){

    if (n=='0'||n=='1'||n=='2'||n=='3'||n=='4'||n=='5'||n=='6'||n=='7'||n=='8'||n=='9')
        cout<<"El Caracter es un numero"<<endl;
    else    
        cout<<"El Caracter no es un numero"<<endl;

}

int main(){

    char c;

    c = pedirCaracter();

    comprobarNumero(c);



    return 0;
}