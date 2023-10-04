#include <iostream>
using namespace std;

class Hombre{

    private:
        string nombre;
        int edad;
        string ocupacion;
    public:
        Hombre(string nombre,int edad,string ocupacion){
            this->nombre = nombre;
            this->edad = edad;
            this->ocupacion = ocupacion;
        }
        void MostrarDatos(){
            cout<<"Nombre      :  "<<nombre<<endl;
            cout<<"Edad        :  "<<edad<<endl;
            cout<<"Ocupacion   :  "<<ocupacion<<endl;
        }

};

class Arania{

    private:
        string especie;

    public:
        Arania(string especie){
            this->especie = especie;
        }

        void MostrarDatos(){
            cout<<"Especie     :  "<<especie<<endl;
        }
};

class HombreArania : public Hombre,public Arania{

    private:
        string habilidades;
    public:
        HombreArania(string nombre, int edad,string ocupacion, string especie,string habilidades) : Hombre(nombre,edad,ocupacion), Arania(especie){ 
            this->habilidades = habilidades;
        }
        void mostrarDatos(){
            Hombre::MostrarDatos();
            Arania::MostrarDatos();
            cout<<"Habilidades :  "<<habilidades<<endl;
        }
};

int main(){

    HombreArania *Mutiverso = new HombreArania("Peter Parker",20,"Estudiante","Aracnus Mercanus","Telarania");
    Mutiverso->mostrarDatos();

    return 0;
}