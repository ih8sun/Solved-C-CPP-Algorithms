#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

float determinar_Puntos(float x2,float x1,float y2,float y1){

    float d;

    d = sqrt( (pow(x2-x1,2)) + pow(y2-y1,2) );

    return d;
}

int main(){

    float x1,x2,y1,y2,d;
    cout<<"\n\n[ RECOGIENDO PUNTOS ]\n\n";

    cout<<"Ingresa Valor de X1 ->";
    cin>>x1;
    cout<<"Ingresa Valor de X2 ->";
    cin>>x2;
    cout<<"Ingresa Valor de Y1 ->";
    cin>>y1;
    cout<<"Ingresa Valor de Y2 ->";
    cin>>y2;
    
    d = determinar_Puntos(x2,x1,y2,y1);

    cout<<"La Distancia entre estos puntos es de -> "<<d<<endl;
    return 0;
}