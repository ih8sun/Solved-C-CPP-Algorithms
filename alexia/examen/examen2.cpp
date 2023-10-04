#include <iostream>
#include <cstdlib>
#define _MaxSize 100
using namespace std;

class telefono{

    private:
        string marca;
        int tipo;
        double precio;
    public:
        telefono(){}
        telefono(string marca,int tipo,double precio){
            this->marca = marca;
            this->tipo = tipo;
            this->precio = precio;
        }
        string getMarca(){
            return marca;
        }
        double getPrecio(){
            return precio;
        }
        int getTipo(){
            return tipo;
        }
        void setMarca(string as){
            marca = as;
        }
        void setTipo(int s){
            tipo = s;
        }
        void setPrecio(double p){
            precio = p;
        }
        void mostrarTelefono(){
            cout<<"Marca : "<<marca<<endl;
            cout<<"Tipo : "<<tipo<<endl;
            cout<<"Precio : "<<precio<<endl;
        }
};

class Empresa{

    private:
        string nombre;
        string direccion;
        string numTelefono;
    public:
        Empresa(){}
        Empresa(string nombre,string direccion,string numTelefono){
            this->nombre = nombre;
            this->direccion = direccion;
            this->numTelefono = numTelefono;
        }
        string getNombre(){
            return nombre;
        }
        string getDireccion(){return direccion;}
        string getNumTelefono(){return numTelefono;}

        void setDireccion(string s){
            direccion = s;
        }
        void setNombre(string s){
            nombre = s;
        }
        void setNumTelefono(string a){
            numTelefono = a;
        }
        void mostrarEmpresa(){
            cout<<"Nombre empresa : "<<nombre<<endl;
            cout<<"Direccion empresa : "<<direccion<<endl;
            cout<<"Num telefono empresa : "<<numTelefono<<endl;
        }

};

class Plan : public telefono, public Empresa{

    private:
        string nomPlan;
        int plazo;
        double costo;
    public:
        friend void buscarPlan(Plan [],int );
        friend void Modificar(Plan [],int );
        Plan(){}
        void leerPlan(){
            cout<<"Ingresa nombre de plan :  ";
            fflush(stdin);
            getline(cin,nomPlan);

            cout<<"Ingresa plazo (en meses) de plan : ";
            cin>>plazo;

            cout<<"Ingresa Costo de plan : ";
            cin>>costo;
        }

        void mostrarPlan(){
            cout<<"\n\n\t\t[ MUESTRA TOTAL DE PEDIDO ] \n\n";
            mostrarTelefono();
            mostrarEmpresa();
            cout<<"Nombre de plan : "<<nomPlan<<endl;
            cout<<"Plazo de Plan (en meses) : "<<plazo<<endl;
            cout<<"Costo de Plan : "<<costo<<endl;
        }

        void setNomplan(string n){
            nomPlan = n;
        }
        void setPlazo(int p){
            plazo = p;
        }
        void setCosto(int c){
            costo = c;
        }


};

void buscarPlan(Plan plan[],int max){

    string nombreDePlan;
    bool encontrado = false;
    int i;
    cout<<"\nIngresa nombre de Plan a buscar : ";
    fflush(stdin);
    getline(cin,nombreDePlan);

    for(i = 0; i < max; i++){
        if(plan[i].nomPlan.compare(nombreDePlan)==0){
            
            plan[i].mostrarPlan();
            encontrado = true;
        }
    }

    if(encontrado == false){
        cout<<"\nNo se encontro el plan "<<nombreDePlan<<endl;
    }

    system("pause");
}

void Modificar(Plan plan[],int max){

    
    string nombreDePlan,varString;
    int varInt;
    double varDouble;
    bool encontrado = false;
    int i;

    cout<<"\nIngresa nombre de Plan a modificar : ";
    fflush(stdin);
    getline(cin,nombreDePlan);

    for(i = 0; i < max; i++){
        if(plan[i].nomPlan.compare(nombreDePlan)==0){
            
            cout<<"Ingresa marca de telefono : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setMarca(varString);

            cout<<"Ingresa Tipo de telefono : ";
            cin>>varInt;
            plan[i].setTipo(varInt);

            cout<<"Ingresa precio de telefono : ";
            cin>>varDouble;
            plan[i].setPrecio(varDouble);

            cout<<"Ingresa nombre de empresa : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setNombre(varString);

            cout<<"Ingresa direccion de empresa : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setDireccion(varString);

            cout<<"Ingresa num de telefono de empresa : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setNumTelefono(varString);

            cout<<"Ingresa nombre de Plan : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setNomplan(varString);

            cout<<"Ingresa plazo de plan : ";
            cin>>varInt;
            plan[i].setPlazo(varInt);
            
            cout<<"Ingresa costo de plan : ";
            fflush(stdin);
            cin>>varDouble;
            plan[i].setCosto(varDouble);

            cout<<"\nDatos Actualizados con exito!!\n";
            encontrado = true;


        }
    }

    if(encontrado == false){
        cout<<"\nNo se encontro plan a modificar \n";
    }
    system("pause");
}

void menu(){
    system("cls");
    cout<<"\n\n\t\t[ PLANES - EL PEPE ]\n\n";
    cout<<"[1]. Ingresar o registrar plan\n";
    cout<<"[2]. Buscar un plan\n";
    cout<<"[3]. Modificar un plan\n";
    cout<<"[4]. Ver registros\n";
    cout<<"[5]. Salir\n";
    cout<<"\n[=]. Ingresa opcion : ";

}

int main(){
    
    Plan plan[_MaxSize];
    string varString;
    int varInt;
    double varDouble;
    int i = 0;
    bool salir = false;
    int opc;
    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"\n\n\t\tINGRESO DE DATOS\n\n";
            cout<<"\nIngresa marca de telefono : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setMarca(varString);

            cout<<"Ingresa Tipo de telefono : ";
            cin>>varInt;
            plan[i].setTipo(varInt);

            cout<<"Ingresa precio de telefono : ";
            cin>>varDouble;
            plan[i].setPrecio(varDouble);

            cout<<"Ingresa nombre de empresa : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setNombre(varString);

            cout<<"Ingresa direccion de empresa : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setDireccion(varString);

            cout<<"Ingresa num de telefono de empresa : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setNumTelefono(varString);

            cout<<"Ingresa nombre de Plan : ";
            fflush(stdin);
            getline(cin,varString);
            plan[i].setNomplan(varString);

            cout<<"Ingresa plazo de plan : ";
            cin>>varInt;
            plan[i].setPlazo(varInt);
            
            cout<<"Ingresa costo de plan : ";
            fflush(stdin);
            cin>>varDouble;
            plan[i].setCosto(varDouble);

            cout<<"\n\n[ PLAN REGISTRADO CORRECTAMENTE ] \n\n";
            i++;
            system("pause");
            break;
        case 2:
            buscarPlan(plan,i);
            break;
        case 3:
            Modificar(plan,i);
            break;

        case 4:
            for(int j = 0; j < i; j++){
                plan[j].mostrarPlan();
                cout<<"\n";
            }
            cout<<"\n";
            system("pause");
            break;
        case 5:
            cout<<"\n\n\t\tGRACIAS POR USAR EL PROGRAMA\n\n";
            salir = true;
            break;

        }


    }while(salir != true);

    return 0;
}