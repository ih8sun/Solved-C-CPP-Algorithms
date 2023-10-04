#include <iostream>
#include <math.h>
#include <stdlib.h>
typedef float real, img;
typedef char operacion;

using namespace std;

class Complejo{

    private:
        real x;
        img y;
        operacion z;
    public:

        Complejo(){
            x = 0;
            y = 0;
            z = '?';
        }
        Complejo(real x,real y){
            this->x = x;
            this->y = y;
            this->z = '?';
        }
        Complejo(real x, real y,operacion z){

            this->x = x;
            this->y = y;   
            this->z = z;        
        }

        void setX(real op){
            x = op;
        }
        void setY(real op){
            y = op;
        }

        real getX(){
            return x;
        }
        real getY(){
            return y;
        }
        char getZ(){
            return z;
        }
        void imprimir(){
            cout<<x<<"x "<<z<<" "<<y<<"y";
        }
        void elevar(real num){
            // * METODO ELEVAR, 1 PARAMETRO, ELEVARA TODO A LAPOTENCIA
            // * QUE ESTA COMO ARGUMENTO
            x = pow(x,num);
            y = pow(y,num);
        }
        void elevar(real num, real num2){
            // * METODO ELEVAR, SOBRECARGADO, ELEVARA TODO X A NUM
            // * Y ELEVARA Y A NUM 2;
            x = pow(x,num);
            y = pow(y,num2);
        }

        void escalar(real num){
            // * METODO ELEVAR, 1 PARAMETRO, MULYIPLICARA TODO AL ESCALAR
            // * QUE ESTA COMO ARGUMENTO
            x *= num;
            y *= num;
        }
        void escalar(real num, real num2){
            // * METODO ELEVAR, SOBRECARGADO, ELEVARA TODO X A NUM
            // * Y ELEVARA Y A NUM 2;
            x *= num;
            y *= num2;
        }       
        
        Complejo resolver(Complejo &oper1,Complejo &oper2, int opc){
            
            Complejo operResul(0,0);

            switch (opc)
            {
            case 1:
                operResul.x = oper1.x + oper2.x;
                operResul.y = oper1.y + oper2.y;
                operResul.z = '+';
                break;
            
            case 2:
                operResul.x = oper1.x - oper2.x;
                operResul.y = oper1.y - oper2.y;
                operResul.z = '-';
                break;
            
            case 3:
                operResul.x = oper1.x * oper2.x;
                operResul.y = oper1.y * oper2.y;
                operResul.z = '*';
                break;
            
            case 4:
                operResul.x = oper1.x / oper2.x;
                operResul.y = oper1.y / oper2.y;
                operResul.z = '/';
                break;
            }

            return operResul;
        }   

        ~Complejo(){
        }
};

void menu(){
    system("cls");
    cout<<"\n\n\t\t[ MENU DE COMPLEJOS ] \n\n";
    cout<<"[1]. Ingresar numeros Complejos\n";
    cout<<"[2]. Elevar Complejos\n";
    cout<<"[3]. Multiplicar Complejos\n";
    cout<<"[4]. Imprimir Complejos\n";
    cout<<"[5]. Realizar Alguna operacion\n";
    cout<<"[6]. Salir\n\n";
    cout<<"[-]. Ingresa una opcion : ";
}

int main()
{
    bool salir = false;
    int opc,x,y;

    Complejo *num1 = new Complejo();
    Complejo *num2 = new Complejo();
    Complejo numFinal(0,0);

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"\n\n\t\t[ ASIGNANDO X - Y PARA NUM COMPLEJO 1 ]\n\n";
            cout<<"Ingresa X : ";
            cin>>x;
            cout<<"Ingresa Y : ";
            cin>>y;

            num1->setX(x);
            num1->setY(y);

            cout<<"\n\n\t\t[ ASIGNANDO X - Y PARA NUM COMPLEJO 2 ]\n\n";
            cout<<"Ingresa X : ";
            cin>>x;
            cout<<"Ingresa Y : ";
            cin>>y;

            num2->setX(x);
            num2->setY(y);


            break;
        
        case 2:
            
            cout<<"\n\n\t\tELEVAR NUMERO COMPLEJO\n\n";
            cout<<"[1]. Elevar Complejo 1\n";
            cout<<"[2]. Elevar Complejo 2\n\n";
            cout<<"[-]. Ingresa una opcion : ";
            cin>>opc;
            switch (opc)
            {
                
                case 1:
                    cout<<"\n\n\t\t[ ELEVAR NUMERO COMPLEJO 1 ]\n\n";
                    cout<<"[1]. ELEVAR X/Y por un numero \n";
                    cout<<"[2]. ELEVAR X/Y por diferentes numeros\n";
                    cout<<"\n[-]. Ingresa una opcion : ";
                    cin>>opc;
                    switch (opc)
                    {
                    case 1:
                        cout<<"Ingresa Escalar : ";
                        cin>>x;
                        num1->elevar(x);
                        break;
                    
                    case 2:
                        cout<<"Ingresa Escalar X : ";
                        cin>>x;
                        cout<<"Ingresa Escalar Y : ";
                        cin>>y;
                        num1->elevar(x,y);
                        break;
                    }
                break; 

                case 2:
                    cout<<"\n\n\t\t[ ELEVAR NUMERO COMPLEJO 2 ]\n\n";
                    cout<<"[1]. ELEVAR X/Y por un numero \n";
                    cout<<"[2]. ELEVAR X/Y por diferentes numeros\n";
                    cout<<"\n[-]. Ingresa una opcion : ";
                    cin>>opc;
                    switch (opc)
                    {
                    case 1:
                        cout<<"Ingresa Escalar : ";
                        cin>>x;
                        num2->elevar(x);
                        break;
                    
                    case 2:
                        cout<<"Ingresa Escalar X : ";
                        cin>>x;
                        cout<<"Ingresa Escalar Y : ";
                        cin>>y;
                        num2->elevar(x,y);
                        break;
                    }                    
                break;
            }

        break;
        

        case 3:
            cout<<"\n\n\t\tMULTIPLICAR NUMERO COMPLEJO\n\n";
            cout<<"[1]. Multiplicar Complejo 1\n";
            cout<<"[2]. Multiplicar Complejo 2\n\n";
            cout<<"[-]. Ingresa una opcion : ";
            cin>>opc;
            switch (opc)
            {
                
                case 1:
                    cout<<"\n\n\t\t[ Multiplicar NUMERO COMPLEJO 1 ]\n\n";
                    cout<<"[1]. Multiplicar X/Y por un numero \n";
                    cout<<"[2]. Multiplicar X/Y por diferentes numeros\n";
                    cout<<"\n[-]. Ingresa una opcion : ";
                    cin>>opc;
                    switch (opc)
                    {
                    case 1:
                        cout<<"Ingresa Escalar : ";
                        cin>>x;
                        num1->escalar(x);
                        break;
                    
                    case 2:
                        cout<<"Ingresa Escalar X : ";
                        cin>>x;
                        cout<<"Ingresa Escalar Y : ";
                        num1->escalar(x,y);
                        break;
                    }
                break; 

                case 2:
                    cout<<"\n\n\t\t[ Multiplicar NUMERO COMPLEJO 2 ]\n\n";
                    cout<<"[1]. Multiplicar X/Y por un numero \n";
                    cout<<"[2]. Multiplicar X/Y por diferentes numeros\n";
                    cout<<"\n[-]. Ingresa una opcion : ";
                    cin>>opc;
                    switch (opc)
                    {
                    case 1:
                        cout<<"Ingresa Escalar : ";
                        cin>>x;
                        num2->escalar(x);
                        break;
                    
                    case 2:
                        cout<<"Ingresa Escalar X : ";
                        cin>>x;
                        cout<<"Ingresa Escalar Y : ";
                        num2->escalar(x,y);
                        break;
                    }                    
                break;
            }

            break;

        case 4:
            cout<<"\n\n\t\t[ IMPRIMIENDO X - Y PARA NUM COMPLEJO 1 ]\n\n";

            num1->imprimir();

            cout<<"\n\n\t\t[ IMPRIMIENDO X - Y PARA NUM COMPLEJO 2 ]\n\n";

            num2->imprimir();
            cout<<"\n\n";
            system("pause");
            break;
        
        case 5:
            cout<<"\n\n\t\t[ OPERACIONES DE COMPLEJOS]\n\n";
            cout<<"[1]. Sumar\n";
            cout<<"[2]. Restar\n";
            cout<<"[3]. Muiltiplicar\n";
            cout<<"[4]. Dividir\n";
            cout<<"[-]. Ingresa opcion : ";
            cin>>opc;

            numFinal = numFinal.resolver(*num1,*num2,opc);
            
            cout<<"\n\n\t\tRESULTADO\n\n";
            cout<<"Parte X : "<<numFinal.getX()<<endl;
            cout<<"OPeracion : "<<numFinal.getZ()<<endl;
            cout<<"Parte Y : "<<numFinal.getY()<<endl<<endl;

            system("pause");
            break;

        case 6:
            salir = true;
            cout<<"\n\n\t\tGRACIAS POR USAR EL PROGRAMA\n\n";
            break;
        }

    }while(salir != true);

    delete num1;
    delete num2;
}