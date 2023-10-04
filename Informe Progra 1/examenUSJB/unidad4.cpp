#include <iostream>
#include <stdlib.h>
#include <string>
#define max 5
using namespace std;


void menu(){
    system("cls");
    cout<<"\n\n\t\t[ MATRICES ]\n\n";
    cout<<"[1]. Suma de Matrices\n";
    cout<<"[2]. Resta de Matrices\n";
    cout<<"[3]. Multiplicacion por escalar\n";
    cout<<"[4]. Salir\n\n[?]. Ingresa una opcion : ";

}

void sumarMatrices(int [][max],int [][max],int );
void restaMatrices(int [][max],int [][max],int );
void escalar(int [][max],int [][max],int );
void imprimirMatriz(int [][max],int);
int generarAleatorio(int ,int );

int main(){

    bool salir = false;
    int opc;
    bool correcto  =false;
    int matriz[max][max];
    int matriz2[max][max];
    int nuevoTam;

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            cout<<"\n\n\t\t[ SUMA DE MATRIZES ]\n\n";

            do{
                cout<<"\nIngresa Tamanio de La matriz : ";
                cin>>nuevoTam;

                if(nuevoTam >= 1  && nuevoTam <= 4){
                    correcto = true;
                }else{
                    cout<<"Ingresa un tamanio correcto\n";
                    correcto = false;
                }
            
            }while(!correcto);
            sumarMatrices(matriz,matriz2,nuevoTam);
            break;
        
        case 2:
            cout<<"\n\n\t\t[ RESTA DE MATRIZES ]\n\n";
            do{
                cout<<"\nIngresa Tamanio de La matriz : ";
                cin>>nuevoTam;

                if(nuevoTam >= 1  && nuevoTam <= 4){
                    correcto = true;
                }else{
                    cout<<"Ingresa un tamanio correcto\n";
                    correcto = false;
                }
            
            }while(!correcto);
            restaMatrices(matriz,matriz2,nuevoTam);
            break;  

        case 3:
            do{
                cout<<"\nIngresa Tamanio de La matriz : ";
                cin>>nuevoTam;

                if(nuevoTam >= 1  && nuevoTam <= 4){
                    correcto = true;
                }else{
                    cout<<"Ingresa un tamanio correcto\n";
                    correcto = false;
                }
            
            }while(!correcto);
            escalar(matriz,matriz2,nuevoTam);
            break;

        case 4:
            cout<<"\n\n\t\t[ GRACIAS POR USAR EL PROGRAMA ]\n\n";
            salir = true;
            break;

        }


    }while(!salir);


    return 0;
}


void sumarMatrices(int m1[][max],int m2[][max],int tam){

    int i,j;
    int matrizFinal[max][max];


    cout<<"\n\n\t\t[ Generando Aleatorios ]\n\n";
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            m1[i][j] = generarAleatorio(1,100);
            m2[i][j] = generarAleatorio(1,100);
        }
    }


    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            matrizFinal[i][j] = m1[i][j] + m2[i][j];
        }
    }

    cout<<"\n\n\t\t[ MATRIZ 1] \n\n";
    imprimirMatriz(m1,tam);
    cout<<"\n\n\t\t[ MATRIZ 2]";
    cout<<endl<<endl;
    imprimirMatriz(m2,tam);
    cout<<"\n\n\t\t[ MATRIZ FINAL]";
    cout<<endl<<endl;
    imprimirMatriz(matrizFinal,tam);
    
    cout<<endl;
    system("pause");
}

int generarAleatorio(int M,int N){

    int tam = rand() % (N-M+1) + M;
    return tam;
}

void imprimirMatriz(int m[][max],int tam){

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout<<m[i][j]<<"   ";
        }
        cout<<endl;
    }
    

}


void restaMatrices(int m1[][max],int m2[][max],int tam){

    int i,j;
    int matrizFinal[max][max];


    cout<<"\n\n\t\t[ Generando Aleatorios ]\n\n";
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            m1[i][j] = generarAleatorio(1,100);
            m2[i][j] = generarAleatorio(1,100);
        }
    }


    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            matrizFinal[i][j] = m1[i][j] - m2[i][j];
        }
    }

    cout<<"\n\n\t\t[ MATRIZ 1] \n\n";
    imprimirMatriz(m1,tam);
    cout<<"\n\n\t\t[ MATRIZ 2]";
    cout<<endl<<endl;
    imprimirMatriz(m2,tam);
    cout<<"\n\n\t\t[ MATRIZ FINAL]";
    cout<<endl<<endl;
    imprimirMatriz(matrizFinal,tam);
    
    cout<<endl;
    system("pause");
}

void escalar(int m1[][max],int m2[][max],int tam){

    int escalar,i,j;

    cout<<"\n\n\t\t [MULTIPLICANDO POR UN ESCALAR ]\n\n";
    cout<<"Ingresa escalar : ";
    cin>>escalar;

    cout<<"\n\n\t\t[ Generando Aleatorios ]\n\n";
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            m1[i][j] = generarAleatorio(1,100);
            m2[i][j] = generarAleatorio(1,100);
        }
    }

    cout<<"\n\nMatriz -> 1\n\n";
    imprimirMatriz(m1,tam);
    cout<<"\n\nMatriz -> 2\n\n";
    imprimirMatriz(m2,tam);

    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            m1[i][j] *= escalar;
            m2[i][j] *= escalar;
        }
    }
    cout<<"\n\n\t\t[ CON ESCALAR ]";
    cout<<"\n\nMatriz -> 1\n\n";
    imprimirMatriz(m1,tam);
    cout<<"\n\nMatriz -> 2\n\n";
    imprimirMatriz(m2,tam);

    cout<<endl;
    system("pause");
}