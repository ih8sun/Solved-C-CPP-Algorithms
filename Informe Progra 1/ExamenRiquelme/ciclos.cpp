#include <iostream>
#include <stdlib.h>

using namespace std;



int main(){

    int opc,i;
    float montoInter = 0,montoNacional = 0, montoLocal = 0;
    int localIntento = 0, minutos, llamadas = 0;

    do{
        system("cls");
        cout<<"\n\n\t\t [ MENU DE LLAMADAS ]\n\n";
        cout<<"[1]. Internacional -> $ 10.59\n";
        cout<<"[2]. Nacional -> $ 7.20\n";
        cout<<"[3]. Local -> $ 0.50\n";
        cout<<"[4]. Salir\n\n[?]. Ingresa opcion : ";
        cin>>opc;
        switch (opc)
        {
        case 1:
            montoInter = 0;
            cout<<"\n\n\t\t[ LLAMADA INTERNACIONAL ]\n\n";
            cout<<"3 primeros minutos -> $. 10.59\n";
            cout<<"Cada minuto adicional + -> $ 4.03 ";
            cout<<"\n\nIngresa total de minutos : ";
            cin>>minutos;

            if( minutos < 3){
                montoInter = 10.59;
            }else{
                montoInter = 10.59;
                minutos = minutos - 3;

                for(i = 0; i < minutos; i++){
                    montoInter += 4.03;
                }
            }
            
            cout<<"\nMonto total a pagar -> $. "<<montoInter<<endl<<endl;
            system("pause");
            break;
        
        case 2:
            montoNacional = 0;
            cout<<"\n\n\t\t[ LLAMADA NACIONAL ]\n\n";
            cout<<"3 primeros minutos -> $. 7.20\n";
            cout<<"Cada minuto adicional + -> $ 0.50 ";
            cout<<"\n\nIngresa total de minutos : ";
            cin>>minutos;

            if( minutos < 3){
                montoNacional = 7.20;
            }else{
                montoNacional = 7.20;
                minutos = minutos - 3;

                for(i = 0; i < minutos; i++){
                    montoNacional += 0.50;
                }
            }
            
            cout<<"\nMonto total a pagar -> $. "<<montoNacional<<endl<<endl;
            system("pause");
            break;
        
        case 3:
            montoLocal = 0;
            cout<<"\n\n\t\t[ LLAMADA LOCAL ]\n\n";
            cout<<"10 Llamadas -> Gratis\n";
            cout<<"Luego cada llamada adicional + -> $ 0.50 ";
            cout<<"\n\nIngresa total de llamadas : ";
            cin>>llamadas;

            for(i = 0; i < llamadas; i++){
                if(i >= 10){
                    montoLocal += 0.5;
                }
            }

            if(montoLocal == 0){
                cout<<"\nMonto total a pagar -> $. "<<"Gratis"<<endl<<endl;
            }else{
                cout<<"\nMonto total a pagar -> $. "<<montoLocal<<endl;
            }
            system("pause");
            break;

        case 4:
            cout<<"\n\n\t\t[ HASTA LA PROXIMA ]\n\n";
            break;
        }

    }while(opc != 4);


    return 0;
}