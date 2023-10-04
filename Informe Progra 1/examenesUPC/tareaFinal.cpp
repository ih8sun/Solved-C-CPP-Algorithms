#include <iostream>
#include <stdlib.h>

using namespace std;

void menu(){
    system("cls");
    cout<<"\n\t     EMPRESA EL PEPE (INDUSTRIA DE CALZADOS FINOS)\n";
    cout<<"\t      1er PROCESO. COSTO DE MATERIAS PRIMA\n";
    cout<<"[1]. ALGODON -> $600\n";
    cout<<"[2]. CUERO -> $1250\n";
    cout<<"[3]. GAMUSA -> $420\n";
    cout<<"[4]. POLIESTER -> $160\n";
    cout<<"[5]. CAUCHO -> $900\n";
    cout<<"[6]. PIELES -> $1250\n\n";

}
void pedirDatos(float [],int ,float [],float &, float &,  float &);
float costoProduccion(float ,float ,float );
float precioVenta(float ,float ,float );
float precioUnitario(float ,float ,float );

int main(){

    //variables
    float cd1[10],mat[3];
    int tam = 6;
    float manoObra,gastoF,MateriaPrima;
    
    menu();
    pedirDatos(cd1,tam,mat,MateriaPrima,manoObra,gastoF);
    cout<<"EL Costo de Produccion del Zapato es de : "<<costoProduccion(MateriaPrima,manoObra,gastoF);
    cout<<"\nPrecio de venta es de : "<<precioVenta(MateriaPrima,manoObra,gastoF);


    return 0;

}


void pedirDatos(float materiales[],int tam,float mat[],float &MP, float &MO,  float &GF){

    int opc;
    float suma = 0;
    float manoObra = 0;
    float gastosP = 0;
    float costoMat = 0;
    
    materiales[0] = 600;
    materiales[1] = 1250;
    materiales[2] = 420;
    materiales[3] = 160;
    materiales[4] = 900;
    materiales[5] = 1250;

    for(int i = 0 ; i < 6; i++){
        costoMat += materiales[i];
    }

    float x;
    
    x += costoMat * 0.08;
    x += costoMat * 0.02;
    x += costoMat * 0.03;
    x += costoMat * 0.05;
    x += costoMat * 0.08;
    x += costoMat * 0.10;

    costoMat = x;
    MP = x;

    cout<<"\n[ Elija almenos 3 materiales a fabricar ]\n";
    for(int i = 0; i < 3; i++){

        cout<<"Ingresa Material -> ";
        cin>>opc;
        opc = opc-1;
        mat[i] = opc;
        switch (opc)
        {
        case 1:
            suma += materiales[opc];
            break;
        
        case 2:
            suma += materiales[opc];
            break;
        
        case 3:
            suma += materiales[opc];
            break;
        
        case 4:
            suma += materiales[opc];
            break;
        
        case 5:
            suma += materiales[opc];
            break;
        }
    }

    //Mano de obra
    for(int i = 0; i < 3; i++){
        if(mat[i] == 2 || mat[i] == 3){
            manoObra +=   costoMat * 0.75;
        }
        if(mat[i] == 0 || mat[i] == 4){
            manoObra +=   costoMat * 0.75;
        }
        if(mat[i] == 1 || mat[i] == 5){
            manoObra +=   costoMat * 0.85;
        }

    }

    cout<<"\nCosto de mano de obra -> "<<manoObra<<endl;

    MO = manoObra;

    //* GASTOS DE PRODUCCION

    for(int i = 0; i < 3; i++){

        if(mat[i] == 1  || mat[i] == 4){
            gastosP += costoMat * 0.30;
        }
        if(mat[i] == 2 || mat[i] == 5){
            gastosP += costoMat * 0.35;
        }
        if(mat[i] == 0 || mat[i] == 3){
            gastosP += costoMat * 0.28;
        }
    }

    GF = gastosP;

    cout<<"Gastos de Produccion -> "<<manoObra<<endl;

}   


float costoProduccion(float MP,float MO,float GF){

    return MP+MO+GF;

}

float precioVenta(float MP,float MO,float GF){

    float costoP = costoProduccion(MP,MO,GF) - (costoProduccion(MP,MO,GF)* 0.45);

    return costoP; 

}
