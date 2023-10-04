#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

template <typename M>
class Datos{

    private:
        int fila;
        int columna;
        M** arr; 
    public:
    Datos(int fila,int columna){
        this->fila = fila;
        this->columna = columna;

        arr = new M*[fila];

        for(int i = 0; i < fila;i++){
            arr[i] = new M[columna];
        }
    }
    Datos(){
        

        arr = new M*[fila];

        for(int i = 0; i < fila;i++){
            arr[i] = new M[columna];
        }
    }
    void llenar(){

        cout<<"\n\n\t\t[ INGRESO DE DATOS ]\n\n";
        for(int i = 0; i < fila; i++){
            for(int j = 0; j < columna; j++){
                cout<<"Ingrese Dato para pos ["<<i<<"]["<<j<<"] : ";
                cin>>arr[i][j];
                fflush(stdin);
            }
            cout<<endl;
        }

    }
    void imprimir(){

        cout<<"\n\n\t\t[ IMPRIMIENDO DATOS ] \n\n";

        for(int i = 0; i < fila ; i++){
            for(int j = 0; j < columna; j++){
                cout<<arr[i][j]<<"  ";
            }
            cout<<endl;
        }
    }
    void imprimir2(){


        M *b,aux;
        int n = 0;
        int j = 0;
        int k = 0;
        int i = 0;

        b = new M[fila*columna];

        for(int i = 0;i < fila; i++){
            for(int j = 0; j < columna; j++){
                b[n] = arr[i][j];
                n++;
            }
        }

        cout<<"\n\n\t\t[ MOSTRANDO DATOS SIN REPETIR ]\n\n";


        for (i = 0; i < n; i++)
            for (j = i + 1; j < n; j++)
                if (b[i] == b[j])
                {
                    for (k = j; k < n - 1; k++)
                        b[k] = b[k + 1];
                    n = n - 1;
                    j = i;
                }


        for(int i = 0; i < n; i++){
            cout<<b[i]<<"  ";
        }

    }


};



int main(){

    cout<<"\n\n[ UTILIZANDO DATOS CHAR ]\n\n";
    Datos <char> obj1(3,3);


    obj1.llenar();
    obj1.imprimir();
    obj1.imprimir2();


    cout<<"\n\n[ UTILIZANDO DATOS ENTEROS ]\n\n";    
    Datos <int> obj2(5,5);
    obj2.llenar();
    obj2.imprimir();
    obj2.imprimir2();

    cout<<"\n\n[ UTILIZANDO DATOS FLOAT ]\n\n";    
    Datos <float> obj3(3,3);
    obj3.llenar();
    obj3.imprimir();
    obj3.imprimir2();

    return 0;
}