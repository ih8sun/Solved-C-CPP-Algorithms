#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
    int nro;
    string codAvion;
    string tipoVuelo;
    struct nodo *sgte;
    string destino;
    int dia,mes,anio,hora;
    int llegadaD,llegadaM,LlegadaA,horaL;
};
 
struct cola{
    nodo *frente;
    nodo *atras  ;
};

void encolar(cola &q){
    nodo *aux = new(nodo);

    int num,opc,d,m,a,hS,hL;
    string nomA,codA,tipV,des;

    cout<<"Ingresa Numero de Avion : ";
    cin>>num;
    aux->nro = num;

    cout<<"Ingresa Codigo de Avion : ";
    fflush(stdin);
    getline(cin,codA);
    aux->codAvion = codA;

    cout<<"\nTipo de Vuelo de Avion\n\n";
    cout<<"[1]. Nacional\n";
    cout<<"[2]. Internacional\n";
    cout<<"\n[-]. Ingresa opcion : ";
    cin>>opc;
    switch (opc)
    {
    case 1:
        fflush(stdin);
        aux->tipoVuelo = "Nacional";
        break;
    
    case 2:
        fflush(stdin);
        aux->tipoVuelo = "Internacional";
        break;
    }

    cout<<"\nIngresa Destino de Avion : ";
    fflush(stdin);
    getline(cin,des);
    aux->destino = des;

    cout<<"\n\n[ Salida De Avion ]\n\n";
    cout<<"Ingresa Dia : ";
    cin>>d;
    cout<<"Ingresa Mes : ";
    cin>>m;
    cout<<"Ingresa anio : ";
    cin>>a;
    cout<<"Ingresa Hora de partida : ";
    cin>>hS;
    


    aux->dia = d;
    aux->mes = m;
    aux->anio = a; 
    aux->hora = hS;

    cout<<"\n\n[ LLegada De Avion ]\n\n";

    cout<<"Ingresa Dia Llegada : ";
    cin>>d;
    cout<<"Ingresa Mes Llegada : ";
    cin>>m;
    cout<<"Ingresa Hora Llegada Aprox : ";
    cin>>hL;

    aux->llegadaD = d;
    aux->llegadaM = m;
    aux->LlegadaA = a; 
    aux->horaL = hL;


    aux->sgte = NULL;
    
    if( q.frente == NULL)
        q.frente = aux;
    else
        (q.atras)->sgte = aux;
        
    q.atras = aux;  
     
}

int desencolar( struct cola &q ){
     int num ;
     struct nodo *aux ;
     
     aux = q.frente; 
     num = aux->nro;
     q.frente = (q.frente)->sgte;
     delete(aux);        
     
     return num;
}

void muestraCola( struct cola q ){

    struct nodo *aux;
    
    aux = q.frente;
        
    while( aux != NULL )
    { 
        cout<<"\nIngresa Numero de Avion : "<<aux->nro<<endl;
        cout<<"Codigo de avion : "<<aux->codAvion<<endl;
        cout<<"Tipo de vuelo : "<<aux->tipoVuelo<<endl;
        cout<<"Destino de Vuelo : "<<aux->destino<<endl;
        cout<<"Fecha Salida  : "<<aux->dia<<"/"<<aux->mes<<"/"<<aux->anio<<" "<<aux->hora<<" : 00"<<endl;
        cout<<"Fecha LLegada  : "<<aux->llegadaD<<"/"<<aux->llegadaM<<"/"<<aux->LlegadaA<<" "<<aux->horaL<<" : 00"<<endl;
        cout<<"\n";
        aux = aux->sgte;
    }    
}

void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.frente != NULL)
     {
            aux = q.frente;
            q.frente = aux->sgte;
            delete(aux);
     }
     q.frente = NULL;
     q.atras   = NULL;
     
}


int main(){

    int i;
    struct cola Avion;
    Avion.frente = NULL;
    Avion.atras = NULL;

    for(i = 0; i < 2; i++){
        system("cls");
        cout<<"\n\n\t\t[ REGISTRO DE AVION ] \n\n";
        encolar(Avion);
        system("pause");
    }

    cout<<"\n\n\t\t[ SALIDA DE AVIONES ] \n\n";
    muestraCola(Avion);

    return 0;
}