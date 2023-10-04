#include <iostream>
using namespace std;

class Transporte{

    private:
        string tipoTransporte;
        double precioBoleto;
        int numBoleto;
        string origen;
        string destino;

    public:
        Transporte(){}
        Transporte(string tipoTransporte,double precioBoleto,int numBoleto, string origen, string destino){
            this->tipoTransporte = tipoTransporte;
            this->precioBoleto = precioBoleto;
            this->numBoleto = numBoleto;
            this->origen = origen;
            this->destino = destino;
        }

        void setTipoTransporte(string TT){
            tipoTransporte = TT;
        }
        void setprecioBoleto(double PB){
            precioBoleto = PB;
        }
        void setNumBoleto(int NB){
            numBoleto =NB;
        }
        void setOrigen(string orig){
            origen = orig;
        }
        void setdestino(string des){
            destino = des;
        }
        
        string getTipoTransporte(){
            return tipoTransporte;
        }
        double getprecioBoleto(){
            return precioBoleto;
        }
        int getnumBoleto(){
            return numBoleto;
        }
        string getorigen(){
            return origen;
        }
        string getdestino(){
            return destino;
        }

        void mostrarDatos(){
            cout<<"Tipo de Transporte   :  "<<tipoTransporte<<endl;
            cout<<"Precio del Boleto    :  "<<precioBoleto<<endl;
            cout<<"Numero del Boleto    :  "<<numBoleto<<endl;
            cout<<"Ciudad de Origen     :  "<<origen<<endl;
            cout<<"Ciudad de Destino    :  "<<destino<<endl;
        }
};

class Hotel{

    private:
        string tipoHabitacion;
        int numHabitacion;
        double precioHabitacion;
        int numNoches;
    public:
        Hotel(){}
        Hotel(string tipoHabitacion,int numHabitacion,double precioHabitacion,int numNoches){
            this->tipoHabitacion = tipoHabitacion;
            this->numHabitacion = numHabitacion;
            this->precioHabitacion = precioHabitacion;
            this->numNoches = numNoches;
        }

        void settipoHabitacion(string TH){
            tipoHabitacion = TH;
        }
        void setnumHabitacion(int NH){
            numHabitacion = NH;
        }
        void setprecioHabitacion(double PH){
            precioHabitacion = PH;
        }
        void setnumNoches(int NN){
            numNoches = NN;
        }

        string gettipoHabitacion(){
            return tipoHabitacion;
        }
        int getnumHabitacion(){
            return numHabitacion;
        }
        double getprecioHabitacion(){
            return precioHabitacion;
        }
        int getnumNoches(){
            return numNoches;
        }

        void mostrarDatos(){
            cout<<"Tipo de Habitacion   :  "<<tipoHabitacion<<endl;
            cout<<"Num de Habitacion    :  "<<numHabitacion<<endl;
            cout<<"Precio de Habitacion :  "<<precioHabitacion<<endl;
            cout<<"Numero de Noches     :  "<<numNoches<<endl;

        }
};


class PaqueteVacacional : public Hotel,public Transporte{

    private:
        string descripcion;
    public:
        PaqueteVacacional(){}
        PaqueteVacacional(string tipoTransporte,double precioBoleto,int numBoleto, 
        string origen, string destino,string tipoHabitacion,int numHabitacion,
        double precioHabitacion,int numNoches,string descripcion){
            this->descripcion = descripcion;
        }

        string getDescripcion(){
            return descripcion;
        }
        void setDescripcion(string DES){
            descripcion = DES;
        }

        void mostrarDatos(){
            cout<<"\n\n\t\t[ PAQUETE VACACIONAL ] \n\n";
            Transporte::mostrarDatos();
            Hotel::mostrarDatos();
            cout<<"\nDescripcion Final    : "<<descripcion<<endl<<endl;
        }
};

int main(){

    PaqueteVacacional *Elpepe = new PaqueteVacacional();
    Elpepe->setTipoTransporte("Avion");
    Elpepe->setprecioBoleto(250);
    Elpepe->setNumBoleto(543584);
    Elpepe->setOrigen("Nueva Leon, Mexico");
    Elpepe->setdestino("Lima, Peru");
    
    Elpepe->settipoHabitacion("Premiun");
    Elpepe->setnumHabitacion(12);
    Elpepe->setnumNoches(15);
    Elpepe->setprecioHabitacion(214);

    Elpepe->setDescripcion("Buenas Vacaciones!");
    Elpepe->mostrarDatos();

    return 0;
}