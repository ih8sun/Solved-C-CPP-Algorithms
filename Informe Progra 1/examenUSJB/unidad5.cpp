#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void menu(){
    system("cls");
    cout<<"\n\n\t\t[ LONGITUD DE POLIGONOS ]\n\n";
    cout<<"[1]. Pentagonos\n";
    cout<<"[2]. Circulos\n";
    cout<<"[3]. Triangulos\n";
    cout<<"[4]. Cuadrados\n";
    cout<<"[5]. Rectangulo\n";
    cout<<"[6]. Salir\n\n[?]. Ingresa una opcion : ";

}

int main(){

    bool salir = false;
    int opc,lg = 0;
    float radio,pi = 3.141516;
    int Pentagono[5],cuadrado[4],h;
    int aux;
    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            lg = 0;
            cout<<"\n\n\t\t[ PENTAGONOS == 5 lados ]\n\n";
            for(int i = 0; i < 5; i++){
                cout<<"Ingresa Lado [ "<<i+1<<" ] -> ";
                cin>>Pentagono[i];
            }

            for(int i = 0; i < 5; i++){
                lg += Pentagono[i];
            }
            cout<<"\nLa Longitud del Pentagono es -> "<<lg<<endl<<endl;
            system("pause");
            break;
        
        case 2:
            lg = 0;
            cout<<"\n\n\t\t[ CIRCULOS ]\n\n";
            cout<<"Ingresa Radio -> ";
            cin>>radio;


            cout<<"\nLa Longitud del Circulo es -> "<<radio*2*pi<<endl<<endl;
            system("pause");
            break;  

        case 3:
            lg = 0;
            cout<<"\n\n\t\t[ TRIANGULO EQUILATERO ]\n\n";
            cout<<"Ingresa Lado : ";
            cin>>aux;

            lg = 3*aux;
            cout<<"\n\n\t\tLa longitud del Tranquilo E. es -> "<<lg<<endl<<endl;
            system("pause");
            
            break;

        case 4:
            lg = 0;
            cout<<"\n\n\t\t[ CUADRADO  ]\n\n";
            for(int i = 0; i < 4; i++){
                cout<<"Ingresa Lado [ "<<i+1<<" ] -> ";
                cin>>cuadrado[i];
            }

            for(int i = 0; i < 4; i++){
                lg += cuadrado[i];
            }
            cout<<"\nLa Longitud del Cuadrado es -> "<<lg<<endl<<endl;
            system("pause");
            break;
        
        case 5:
            lg = 0;
            cout<<"\n\n\t\t[ CUADRADO  ]\n\n";
            cout<<"Ingresa Lado B -> ";
            cin>>aux;
            cout<<"Ingresa Lado H -> ";
            cin>>h;

            lg = 2*(aux+h);
            cout<<"\nLa Longitud del Rectangulo es -> "<<lg<<endl<<endl;
            system("pause");

            break;
        case 6:
            cout<<"\n\n\t\t[ GRACIAS POR USAR EL PROGRAMA ]\n\n";
            salir = true;
            break;

        }


    }while(!salir);


    return 0;
}