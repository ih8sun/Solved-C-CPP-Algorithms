#include <iostream>
using namespace std;


class Equipo{

    public:
        int Codigo;
        string marca;
        double precio;
    public:
        Equipo(int cod,string mar,double pr){
            Codigo = cod;
            marca = mar;
            precio = pr;
        }
        Equipo(){}
        int getCodigo(){
            return Codigo;
        }
        string getMArca(){
            return marca;
        }
        double getPrecio(){
            return precio;
        }
        void setCodigo(int c){
            Codigo = c;
        }
        void setMarca(string s){
            marca = s;
        } 
        void setPrecio(double d){
            precio = d;
        }



};

class Protesis : public Equipo{

    public:
        int Componentes;
        string nombre;
    public:

        Protesis(){

        }
        Protesis(int cod,string mar,double pr, int com,string n) : Equipo(cod,mar,pr){

            Componentes = com;
            nombre = n;
        }

        int getComponente(){
            return Componentes;
        }
        string getNombre(){
            return nombre;
        }
        void setComponente(int s){
            Componentes = s;
        }
        void setNombre(string s){
            nombre = s;
        }

};

class Sensor : public Equipo{

        public:
            string tipo;
            int tam;
        public: 

            Sensor(){

            }
            Sensor(int cod,string mar,double pr,string tp,int tam) : Equipo( cod, mar, pr){

                tipo = tp;
                this->tam = tam;
            }
            string getTipo(){
                return tipo;
            }
            int getTam(){
                return tam;
            }
            void setTipo(string t){
                tipo = t;
            }
            void setTam(int t){
                tam = t;
            }
};
