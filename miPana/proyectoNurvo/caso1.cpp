#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){

    //MENU
    int opc;
    char op;
    string newOPC;
    bool salir = false;
    bool correcto = false;

    int num,i,j,tabla,sumatoria = 0;


    do{
        cout<<"\nDesea Continuar con el programa? [SI - NO ] : ";
        fflush(stdin);
        getline(cin,newOPC);
        if(newOPC == "si" || newOPC == "SI"){
            correcto = true;
        }
        else if(newOPC == "no" or newOPC == "NO"){
            
            salir = false;
            return 0;
            system("pause");
        }
        else{
            cout<<"\n\n\t\tERROR\n\n";
            system("pause");
        }

    }while(correcto != true);


        cout<<"\n\n\t\tCONJETURA DE ULAM\n\n";
        cout<<"\nIngresa numero inicial : ";
        cin>>num;

        cout<<"\n\n\t\t[ SECUENCIA DE NUMEROS ]\n\n";
        cout<<num<<"   ";

        while(num != 1){
            if(num % 2 == 0){
                num /= 2;
                cout<<num<<"   ";
            }else{
                num = (num*3)+1;
                cout<<num<<"   ";
            }
        }

        cout<<endl;
        system("pause");

            
        cout<<"\n\n\t\tMULTIPLICACIONES\n\n";
        cout<<"Que tabla desea multiplicar ? ";
        cin>>tabla;

        cout<<"Hasta donde quiere que se detenga ? ";
        cin>>j;

        cout<<"\n\n\t\tIMPRIMIENDO TABLA \n\n";
        for(i = 0; i <= j; i++){
            cout<<"\t"<<i<<"  x  "<<tabla<<" :  "<<i*tabla<<endl;
            sumatoria += (i*tabla);
        }

        cout<<"\nSumatoria Total : "<<sumatoria<<endl;
        cout<<endl;
        system("pause");



    return 0;
}

