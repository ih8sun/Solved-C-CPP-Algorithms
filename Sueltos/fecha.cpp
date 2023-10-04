#include <iostream>
using namespace std;

class Fecha{

private:
    int mes;
    int dia;
    int anio;
public:
    Fecha(int mes,int dia,int anio){
        this->mes = mes;
        this->dia = dia;
        this->anio = anio;
    }
    int getMes(){
        return mes;
    }
    int getDia(){
        return dia;
    }
    int getAnio(){
        return anio;
    }
    void setMes(int x){

        bool correcto = false;
        do{
            if(x >= 1 && x <= 12 ){
                mes = x;
                correcto = true;
            }else{
                mes = 1;
                correcto = true;
            }

        }while(!correcto);
    }

    void setDia(int x){
        bool correcto = false;
        do{
            if(x >= 1 && x <= 31 ){
                dia = x;
                correcto = true;
            }else{
                dia = 1;
                correcto = true;
            }

        }while(!correcto);
    }
    void setAnio(int x){
        bool correcto = false;
        do{
            if(x >= 1000 && x <= 2021 ){
                anio = x;
                correcto = true;
            }else{
                anio = 1000;
                correcto = true;
            }

        }while(!correcto);
    }

    void MostrarFecha(){
        cout<<"\n\n\t\t[ IMPRIMIENDO FECHA ]\n";
        cout<<"\nFecha Introducida : "<<mes<<"/"<<dia<<"/"<<anio<<endl<<endl;
    }
};

int main() {

    int x;
    Fecha *fecha = new Fecha(10,2,3);
    fecha->MostrarFecha();

    cout<<"\n\nFECHA INTRODUCIDA POR USUARIO\n\n";
    cout<<"Ingresa Dia : ";
    cin>>x;
    fecha->setDia(x);
    cout<<"Ingresa Mes : ";
    cin>>x;
    fecha->setMes(x);
    cout<<"Ingresa Anio : ";
    cin>>x;
    fecha->setAnio(x);

    fecha->MostrarFecha();
    return 0;
}
