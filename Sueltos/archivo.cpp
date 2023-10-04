#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){

    string variablesString;
    int edad;
    float salario;

    int opc;

    bool salir = false;
    bool correcto = false;

    ofstream miArchivo;


    cout<<"\n\n\t\t[ EMPRESA PEPITO .SAC ]\n\n";
    do{
        miArchivo.open("Registros",ios::app);
        
        do{
            cout<<"\nIngresa Nombre de la empresa : ";
            fflush(stdin);
            getline(cin,variablesString);

            if(variablesString.length() > 30){
                cout<<"No debe pasar de 30 caracteres\n";
                correcto = false;
            }else{
                correcto = true;
                miArchivo<<variablesString<<" - ";
            }
        }while(correcto != true);


        do{
            cout<<"\nIngresa direccion de la empresa : ";
            fflush(stdin);
            getline(cin,variablesString);

            if(variablesString.length() > 40){
                cout<<"No debe pasar de 40 caracteres\n";
                correcto = false;
            }else{
                correcto = true;
                miArchivo<<variablesString<<" - ";
            }
        }while(correcto != true);

        do{
            cout<<"\nIngresa codigo Postal de la empresa : ";
            fflush(stdin);
            getline(cin,variablesString);

            if(variablesString.length() > 6){
                cout<<"No debe pasar de 6 caracteres\n";
                correcto = false;
            }else{
                correcto = true;
                miArchivo<<variablesString<<" - ";
            }
        }while(correcto != true);

        cout<<"\nIngresa edad : ";
        cin>>edad;
        miArchivo<<edad<<" - ";

        cout<<"\nIngresa Salario : ";
        cin>>salario;
        miArchivo<<salario<<" - ";   

        do{
            cout<<"\nIngresa Telefono de la empresa : ";
            fflush(stdin);
            getline(cin,variablesString);

            if(variablesString.length() > 10){
                cout<<"No debe pasar de 10 caracteres\n";
                correcto = false;
            }else{
                correcto = true;
                miArchivo<<variablesString;
            }
        }while(correcto != true);

        cout<<"\n\n\t [ REGISTRO GUARDADO CORRECTAMENTE ]\n\n";
        do{
            cout<<"\n\nDesea agregar otro registro?\n[1]. Si\n[2]. No\n";
            cout<<"Ingrese opcion : ";
            cin>>opc;
            switch (opc)
            {
            case 1:
                salir = false;
                miArchivo<<endl;
                correcto = true;
                break;
            
            case 2:
                salir = true;
                correcto = true;
                break;

            default:
                correcto = false;
                cout<<"\n\tSe debe elegir una opcion correcta\n";
                break;

            }
        }while(correcto != true);

        miArchivo.close();
    }while(salir != true);

    return 0;
}