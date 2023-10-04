#include <iostream>
using namespace std;


int restarNumeros(int n1,int n2,int n3){
    return n1-n2-n3;
}


void imprimir(int r){
    cout<<"\nEl resultado fue de -> "<<r<<endl;
}

void pedirDatos(){

    int n1,n2,n3,r;

    cout<<"\n\n\t\t[ PIDIENDO NUMEROS ]\n\n";
    cout<<"Ingresa Numero 1 -> ";
    cin>>n1;
    cout<<"Ingresa Numero 2 -> ";
    cin>>n2;
    cout<<"Ingresa Numero 3 -> ";
    cin>>n3;


    r = restarNumeros(n1,n2,n3);

    imprimir(r);
}




int main(){

    pedirDatos();


    return 0;
}