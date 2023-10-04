#include <iostream>

using namespace std;

class Conjunto{

    private:
        double num;
    public:
        Conjunto(double num){
            this->num = num;
        }
        void operator+(double x){
            Conjunto::num += x;
        }
        void operator-(){

            double x,y;

            cout<<"Ingrese un numero A : ";
            cin>>x;
            cout<<"Ingrese un numero B : ";
            cin>>y;            
            Conjunto *a = new Conjunto(x);
            Conjunto *b = new Conjunto(y);

            cout<<"La diferencia entre A y B es de "<<a->num-b->num<<endl;
            
        }
            
        void operator*(){

            double x,y;

            cout<<"Ingrese un numero A : ";
            cin>>x;
            cout<<"Ingrese un numero B : ";
            cin>>y; 

            Conjunto *a = new Conjunto(x);
            Conjunto *b = new Conjunto(y);

            cout<<"La Interseccion entre A y B es de "<<a->num*b->num<<endl;
            
        }

        void mostrarNum(){
            cout<<num<<endl;
        }

};

int main(){

    double a,b;
    cout<<"\n\n\t\tOPERADORES SOBRECARGADOS\n\n";

    cout<<"Ingrese un numero A : ";
    cin>>a;
    cout<<"Ingrese un numero B : ";
    cin>>b;

    Conjunto *conjunto1 = new Conjunto(a);

    cout<<"\n\n\t\tSUMA SOBRECARGADA\n\n";
    conjunto1->operator+(b);
    cout<<"La suma sobrecargada es : ";
    conjunto1->mostrarNum();
    
    cout<<"\n\n\t\tRESTA SOBRECARGADA\n\n";
    conjunto1->operator-();

    cout<<"\n\n\t\tMULTIPLICACION SOBRECARGADA\n\n";
    conjunto1->operator*();
    return 0;
}