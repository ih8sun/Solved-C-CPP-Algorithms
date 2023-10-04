#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

class Figura{

    public:
    virtual void setArea();
    virtual void setVolumen(); 

};

class TrianguloEquilatero : public Figura{

    public:
        float lT;
    public:
        TrianguloEquilatero(float x){
            lT = x;
        }
        void setArea(){
            float newX = lT*lT;
            cout<<newX<<endl;
        }
        void setVolumen(){
            float newX = lT /= lT * lT;
            cout<<newX<<endl;
        }

};

class Rectangulo : public Figura{

    public:
        float bR,hR;
    public:
        Rectangulo(float x,float y){
            bR = x;
            hR = y;
        }
        void setArea(){
            cout<<bR*hR<<endl;
        }
        void setVolumen(){
            cout<<bR+hR<<endl;
        }
};

class Prisma : public TrianguloEquilatero{

    public:
        float Lp;
        float hP;
    public:
        Prisma(float x,float y,float z) : TrianguloEquilatero(x){
            Lp = y;
            hP = z;
        }
        void setArea(){
            float Area = Lp*((3*hP)+((Lp*sqrt(3))/2));
            cout<<"El Area de un Prisma Triangula : "<<Area<<endl<<endl;
        }
        void setVolumen(){
            float volumen = ((hP)*pow(Lp,2)*(sqrt(3)))/4;
            cout<<"El Voluemn de un Prisma Triangular : "<<volumen<<endl;
        }

};

class Paralelepipedo : public Rectangulo{

    public:
        float b;
        float h;
        float d;
    public:
        Paralelepipedo(float x,float y,float b1,float h1,float d1) : Rectangulo(x,y){
            b = b1;
            h = h1;
            d = d1;
        }
        void setArea(){
            float Area = (b*d)+(2*d*h)+(2*b*h);
            cout<<"Area de Paralelepipedo : "<<Area<<endl;
        }
        void setVolumen(){
            float Volumen = (b*d*h);
            cout<<"Volumen de Paralelepipedo : "<<Volumen<<endl;
        }
};

class PrismaHueco : public Prisma{

    public:
        float _despesor;
    public:
        PrismaHueco(float _l,float _h,float _Despesor) : Prisma(_l,_h,_Despesor){
            _despesor = _Despesor;
        }
        void getPrismaHueco(){

            cout<<"EL Area de un Prisma Hueco es : "<<2*(Lp+hP+_despesor)<<endl;
        }
        void getVolumen(){
            cout<<"El volumen de un prisma Hueco es : "<<(Lp*hP*_despesor)<<endl<<endl;
        }
};

class ParalelepipedoHueco : public Paralelepipedo{

    protected:
        float _despesorP;
    public:
        ParalelepipedoHueco(float b,float h,float d,float _Despensor) : Paralelepipedo(b,h,d,_Despensor,1){

            _despesorP = _Despensor;
        }

        void getPrismaHueco(){

            cout<<"EL Area de un Paralelepipedo Hueco es : "<<2*(b+h+_despesorP)<<endl;
        }
        void getVolumen(){
            cout<<"El volumen de un prisma Hueco es : "<<(b*h*_despesorP)<<endl<<endl;
        }
};

int main(){

    Figura *obj1 = new Prisma(10,3,5);
    Figura *obj2 = new Paralelepipedo(15,2,5,1,7);
    Figura *obj3 = new PrismaHueco(15,2,6);
    Figura *obj4 = new ParalelepipedoHueco(2,5,5,3);
    obj1->setArea();
    obj1->setVolumen();
    obj2->setVolumen();
    obj2->setArea();
    obj3->setVolumen();
    obj3->setArea();
    obj4->setVolumen();
    obj4->setArea();
    return 0;
}
