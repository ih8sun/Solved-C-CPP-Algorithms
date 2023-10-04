#include <iostream>
#include <stdlib.h>

using namespace std;

void menu();
void pedirDatos(int [],int,float &,float &);
float costo_Produccion(int [],int ,float);

int main(){

    //variables
    int cd1[10],tam = 6;
    float manoObra,gastoF;
    menu();
    pedirDatos(cd1,tam,manoObra,gastoF);
    cout<<"\n\n\t\t[ RESULTADOS ]\n\n";
    cout<<"\n\nCosto de Produccion -> ";
    return 0;

}


void menu(){
    system("cls");
    cout<<"\n\t     EMPRESA EL PEPE (INDUSTRIA DE CALZADOS)\n";
    cout<<"\t      1er PROCESO. COSTO DE MATERIAS PRIMA\n";
    cout<<"[1]. ALGODON\n";
    cout<<"[2]. CUERO\n";
    cout<<"[3]. GAMUSA\n";
    cout<<"[4]. POLIESTER\n";
    cout<<"[5]. CAUCHO\n";
    cout<<"[6]. PIELES\n\n";

}

void pedirDatos(int cd1[],int tam,float &manoObra,float &GastoF){

    cout<<"\n\n\t[ PEDIDA DE DATOS ]\n\n";
    float sum = 0;
    for(int i = 0; i < tam; i++){
        cout<<"Ingreas Precio de Materia Prima de ["<<i+1<<"] -> $/.";
        cin>>cd1[i];
    }

    //*Hallando Mano de Obra\n

    sum += cd1[2] * 0.75;
    sum += cd1[3] * 0.75;
    sum += cd1[0] * 0.80;
    sum += cd1[4] * 0.80;
    sum += cd1[1] * 0.85;
    sum += cd1[5] * 0.85;

    GastoF = sum;

    cout<<"\nEl Costo de la mano de obra -> "<<GastoF<<endl;
    

    //*Hallando Gasto de Fabricacion\n

    

}

float costo_Produccion(int cd1[],int tam,float manoObra){

    float sum;

    return manoObra;
}