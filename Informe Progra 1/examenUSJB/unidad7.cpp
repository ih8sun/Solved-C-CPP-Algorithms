#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    fstream archivo;
    string txt;
    int opc;
    cout<<"\n\n\t\t [DEFINIENDO NOMBRE DE ARCHIVO]\n\n";

    cout<<"Ingresa nombre de archivo (ejemplo -> elPepe.txt) : ";
    fflush(stdin);
    getline(cin,txt);

    archivo.open(txt.c_str(),ios::out);
    archivo.close();

    if(archivo.fail()){
        cout<<"\nNo se pudo abrir el archivo\n";
        exit(1);
    }

    archivo.open(txt.c_str(),ios::app);
    
    do{
        cout<<"Ingresa texto : ";
        fflush(stdin);
        getline(cin,txt);

        archivo<<txt<<endl;
        cout<<"Desea Seguir Escribiendo en el archivo? [1]. Si [otro] No\n";
        cout<<"Ingrese: ";
        cin>>opc;

        


    }while(opc != 1);


    return 0;
}