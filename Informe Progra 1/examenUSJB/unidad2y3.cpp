#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct Pelicula{

    string nombre;
    int duracion;
};

void menu(){
    system("cls");
    cout<<"\n\n\t\t[ PELICULAS ]\n\n";
    cout<<"[1]. Alquilar una Pelicula\n";
    cout<<"[2]. Comprar una pelicula\n";
    cout<<"[3]. Salir\n\n[?]. Ingresa una opcion : ";

}

void rentarPelicula(Pelicula *);
void ventaPelicula(Pelicula *);
int generarAleatorio(int ,int );
void inicializar(Pelicula *a){

    a->duracion = 0;
    a->nombre = "";
}


int main(){

    bool salir = false;
    int opc;

    Pelicula *pelicula = new Pelicula();

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            inicializar(pelicula);
            rentarPelicula(pelicula);
            break;
        
        case 2:
            inicializar(pelicula);
            ventaPelicula(pelicula);
            break;

        case 3:
            cout<<"\n\n\t\t[ GRACIAS POR USAR EL PROGRAMA ]\n\n";
            salir = true;
            break;

        }


    }while(!salir);

    return 0;
}

int generarAleatorio(int M,int N){

    int tam = rand() % (N-M+1) + M;
    return tam;
}

void rentarPelicula(Pelicula *peli){

    float precio = generarAleatorio(1,100);
    bool salir = false;
    float preciouser;


    cout<<"\n\n\t\t[ RENTA DE PELICULA ]\n\n";

    cout<<"Ingresa el nombre de la Pelicula : ";
    fflush(stdin);
    getline(cin,peli->nombre);
    cout<<"Ingresa el duracion [Minutos] de la Pelicula : ";
    cin>>peli->duracion;


    cout<<"\n\n\t\t[ Precio de la Pelicula en renta ] -> "<<precio<<" Pesos."<<endl;
    do{

        cout<<"\nIngresa dinero : ";
        cin>>preciouser;

        if(preciouser >= precio){
            if(preciouser == precio){
                cout<<"\n\n\t\t [ SE REALIZO LA RENTA ]\n\n";
                salir = true;
                break;

            }else{
                cout<<"\n\n\t\t [ SE REALIZO LA RENTA ]\n\n";
                cout<<"Precio User -> "<<preciouser<<endl;
                cout<<"Precio Renta -> "<<precio<<endl;
                cout<<"Recoja su vuelto -> "<<preciouser-precio<<endl;
                salir = true;
                break;

            }
        }else{
            cout<<"Debe Ingresar un precio Correcto\n";
            salir = false;
        }


    }while(!salir);

    cout<<endl<<endl;
    system("pause");
}

void ventaPelicula(Pelicula *peli){

    float precio = generarAleatorio(150,420);
    bool salir = false;
    float preciouser;


    cout<<"\n\n\t\t[ VENTA DE PELICULA ]\n\n";

    cout<<"Ingresa el nombre de la Pelicula : ";
    fflush(stdin);
    getline(cin,peli->nombre);
    cout<<"Ingresa el duracion [Minutos] de la Pelicula : ";
    cin>>peli->duracion;


    cout<<"\n\n\t\t[ Precio de la Pelicula en venta ] -> "<<precio<<" Pesos."<<endl;
    do{

        cout<<"\nIngresa dinero : ";
        cin>>preciouser;

        if(preciouser >= precio){
            if(preciouser == precio){
                cout<<"\n\n\t\t [ SE REALIZO LA VENTA ]\n\n";
                salir = true;
                break;

            }else{
                cout<<"\n\n\t\t [ SE REALIZO LA VENTA ]\n\n";
                cout<<"Precio User -> "<<preciouser<<endl;
                cout<<"Precio Renta -> "<<precio<<endl;
                cout<<"Recoja su vuelto -> "<<preciouser-precio<<endl;
                salir = true;
                break;

            }
        }else{
            cout<<"Debe Ingresar un precio Correcto\n";
            salir = false;
        }


    }while(!salir);

    cout<<endl<<endl;
    system("pause");
}