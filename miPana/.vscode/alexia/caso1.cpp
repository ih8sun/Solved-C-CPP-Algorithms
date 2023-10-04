//agregar al template de clase Matriz
//la sobrecarga de los operadores+ y * para matrices: (próximaclase)
//use de referencia este codigo

#include <iostream>
#include <iomanip>
#define tam 10
using namespace std;

template <class G>

class Matriz
{
    G a[tam][tam];
    int n; //tamaño de filas (<10)
    int m; //tamaño de las columnas (<10)
public:
    Matriz()
    {
        n = m = 0;
    }
    Matriz(int filas, int columnas)
    {
        n = filas;
        m = columnas;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
    }

Matriz operator +(Matriz &x){

    int F;
    cout<<"\nIngrese Numero para sobrecargar(+) matriz : ";
    cin>>F;

    for(int i = 0; i < x.n; i++){
        for(int j = 0; j < x.m; j++){
            a[i][j] += F;
        }
    }

    cout<<"\n\nMatriz SobreCargada\n";
    return x;

}

Matriz operator *(Matriz &x){

    int F;
    cout<<"\nIngrese Numero para sobrecargar(*) matriz : ";
    cin>>F;

    for(int i = 0; i < x.n; i++){
        for(int j = 0; j < x.m; j++){
            a[i][j] *= F;
        }
    }

    cout<<"\n\nMatriz SobreCargada\n";
    return x;

}

    void leer()
    {
        cout << endl;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout<<"Ingresa Dato ["<<i<<"]["<<j<<"] : ";
                cin >> a[i][j];
            }
            cout<<endl;
        }
    }
    void ver()
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << setw(8) << a[i][j];
            cout << endl;
        }
    }


};

int main()
{
    Matriz<int> A(3, 5);

    cout<<"\n\n\t\t[ LECTURA DE DATOS ]\n\n";

    A.leer();
    cout<<"\n\n\t\t[ MUESTRA DE DATOS ]\n\n";
    A.ver();

    A = A.operator+(A);
    
    A.ver();


    Matriz<double> B(2, 2);
    
    cout<<"\n\n\t\t[ LECTURA DE DATOS ]\n\n";

    B.leer();
    cout<<"\n\n\t\t[ MUESTRA DE DATOS ]\n\n";
    B.ver();

    B = B.operator*(B);
    B.ver();




    return 0;
}