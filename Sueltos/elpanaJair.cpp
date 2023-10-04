#include <iostream>
using namespace std;
int main(){

    int i,j;

    float a[10],b[10];
    float c[10];
    int contadorB = 9;

    cout<<"\n\n\t\tINGRESANDO DATOS A ARRAY [A]\n\n"<<endl;
    for(i = 0; i < 10; i++){
        cout<<"Ingrese elemento en pos ["<<i<<"] : ",
        cin>>a[i];
    }
    cout<<"\n\n\t\tINGRESANDO DATOS A ARRAY [B]\n\n";
    for(i = 0; i < 10; i++){
        cout<<"Ingrese elemento en pos ["<<i<<"] : ",
        cin>>b[i];
    }

    for ( i = 0; i < 10; i++) {
        c[i] = a[i] + b[contadorB];
        contadorB--;
    }

    cout<<"\n\n\t\tIMPRIMIENDO ARREGLOS\n\n";
    cout<<"[Arreglo A]\n\n";
    for(i = 0; i < 10; i++){
        cout<<a[i];
        if(i != 9){
            cout<<" - ";
        }
    }
    cout<<"\n\n[Arreglo B]\n\n";
    for(i = 0; i < 10; i++){
        cout<<b[i];
        if(i != 9){
            cout<<" - ";
        }
    }

    cout<<"\n\n[Arreglo C]\n\n";
    for(i = 0; i < 10; i++){
        cout<<c[i];
        if(i != 9){
            cout<<" - ";
        }
    }
    cout<<"\n\n";

    return 0;
}