/*Leer arbitrariamente un numero de proverbios del teclado y los almacene en la memoria de forma
dinamica, es decir, que se vayan generando los registros conforme el usuario ingrese los proverbios.
Al terminar de ingresar los proverbios, al menos 5 o 7, el programa debe mostrar en pantalla
los proverbios en una lista ordenada por longitud de caracteres, tal que el primero en mostrar sea 
el mas corto y el utlimo el mas largo*/
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){

    string *proverbios;

    proverbios = new string[5];
    int opc,i = 1;
    bool salir = true;
    string prov;
    int j = 0;

    
    do{
        system("cls");
        cout<<"\n\n\t\tPROVERBIOS\n\n";
        cout<<"Ingresa Cadena a Registrar : ";
        fflush(stdin);
        getline(cin,prov);  
        
        
        proverbios[j] = prov;        


        cout<<"\nDesea Colocar mas cadenas? \n";
        cout<<"[1]. Si\n";
        cout<<"[2]. No\n";
        cout<<"\n[-]Ingrese opcion : "; cin>>opc;
        

        if(opc != 2){
            i++;
            j++;
        }

    }while(opc != 2);

    cout<<"\n\nLista de Proverbios\n\n";

    for(int x = 0; x < i ; x++){
        cout<<"Proverbio "<<x<<" : "<<proverbios[x]<<endl;

    }   

    return 0;
}