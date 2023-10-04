#include <iostream>
#include <windows.h>

using namespace std;

string nombre(int x){

    switch (x)
    {

    case 0: return "Lunes";
        break;

    case 1:
        return "Martes";
        break;
    
    case 2:return "Miercoles";
        break;

    case 3:return "Jueves";
        break;
    
    case 4:return "Viernes";
        break;

    case 5:return "Sabado";
        break;

    case 6:return "Domingo";
        break;

    }
    return " ";
}

int main(){

    int i,j;
    double dias[7];
    double x; 
    double mayor = 0;
    double menor = 9999;
    double posMayor,posMenor;

    cout<<"\n\n\t\t[ CAPTURANDO DATOS ] \n\n";
    for(int i = 0; i < 7; i++){
        
        cout<<"Capture la temperatura promedio del dia [ "<<nombre(i)<<" ] : ";
        cin>>dias[i];

    }

    for(i = 0; i < 7 ; i++){
        if(mayor < dias[i]){
            posMayor = i;
            mayor = dias[i];

        }
    }

    for(i = 0; i < 7 ; i++){
        if(menor > dias[i]){
            posMenor = i;
            menor = dias[i];

        }
    }
    
    cout<<"\n\nLos valores ordenados de forma ascendente son : \n";

    for( i = 0; i < 7; i++){
        for( j = 0; j < 7-1; j++){
            if(dias[j] > dias[j+1]){
                x = dias[j];
                dias[j] = dias[j+1];
                dias[j+1] = x; 
            }
        }
    } 

    for(i = 0; i < 7; i++){
        cout<<"   "<<dias[i];
    }

    cout<<"\nLos valores ordenados de forma descendente son : \n";

    for( i = 0; i < 7; i++){
        for( j = 0; j < 7-1; j++){
            if(dias[j] < dias[j+1]){
                x = dias[j];
                dias[j] = dias[j+1];
                dias[j+1] = x; 
            }
        }
    } 

    for(i = 0; i < 7; i++){
        cout<<"   "<<dias[i];
    }




    cout<<"\n\nEl dia mas caluroso fue el "<<nombre(posMayor)<<endl;
    cout<<"El dia mas frio fue el "<<nombre(posMenor)<<endl<<endl;

    system("pause");
    return 0;
}