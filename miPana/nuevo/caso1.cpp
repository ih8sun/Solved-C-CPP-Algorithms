#include <iostream>
#include <stdlib.h>
#define tamMaximo 100
using namespace std;


int main(){

    int opc;
    char op;
    string newOPC;
    bool salir = false;

    //HALLAR PROMEDIO PESO
    int n,promM = 0,promF = 0,j = 0;
    string RM;
    float peso[tamMaximo];
    float altura[tamMaximo];
    char sexo[tamMaximo];
    int edad[tamMaximo];

    //HALLAR PROMEDIO METEOROLOGICO ANUAL
    float Centro[tamMaximo];
    float Sur[tamMaximo];
    float Golfo[tamMaximo];
    float Pacifico[tamMaximo];
    float Caribe[tamMaximo];

    float promCentro = 0,promSur = 0,promGolfo = 0,promPacifico = 0,promCaribe = 0;
    int x = 0,y = 0;
    int mayor = 0;
    int menor = 99999;
    int pos;

    

    do{
        system("cls");
        cout<<"\n\n\t\t[ MENU DE OPCIONES ]\n\n";
        cout<<"a) Promedio del peso\n";
        cout<<"b) Promedio Meteorologico anual\n";
        cout<<"c) salir\n";
        cout<<"[-]. Ingrese una opcion : ";
        cin>>op;
        switch (op)
        {
        case 'a':
            cout<<"\n\n\t\t[ DEFINIENDO DATOS ]\n\n";
            cout<<"Ingrese numero de personas a elegir : ";
            cin>>n;
            cout<<"Ingresa estado de la Repulbica Mexicana : ";
            fflush(stdin);
            getline(cin,RM);

            cout<<"\n\n\t\t\t[ MENU DE VACACIONES [ "<<RM<<" ]\n\n";

            for(int i = 0; i < n; i++){
                cout<<"Ingrese Peso : ";
                cin>>peso[i];
                cout<<"Ingrese Altura : ";
                cin>>altura[i];
                cout<<"Ingrese Sexo (M - F): ";
                fflush(stdin);
                cin>>sexo[i];
                cout<<"Ingresa Edad : ";
                cin>>edad[i];
                cout<<endl;
            }

            cout<<"Persona\tPeso\tAltura\tSexo\tEdad\t\n\n";
            for(int i = 0; i < n; i++){
                cout<<" ["<<i+1<<"]  -   "<<peso[i]<<" -   "<<altura[i]<<" -   "<<sexo[i];
                cout<<" -   "<<edad[i]<<endl;
            }

            cout<<"\nMostrando Promedio de Pesos de Mayores de 18 anios Masculino\n\n";
            for(int i = 0; i < n; i++){
                if(sexo[i] == 'M' && peso[i] >= 18){
                    cout<<" ["<<i+1<<"]  -   "<<peso[i]<<" -   "<<altura[i]<<" -   "<<sexo[i];
                    cout<<" -   "<<edad[i]<<endl;        
                    promM +=  peso[i];    
                    j++;     
                }
            }
            
            if(j != 0){
                cout<<"Promedio es "<<promM/j<<endl;
            }else{
                cout<<"No se encontraron Registros\n";
            }
            j = 0;

            cout<<"\nMostrando Promedio de Pesos de Mayores de 18 anios Femenino\n\n";
            for(int i = 0; i < n; i++){
                if(sexo[i] == 'F' && peso[i] >= 18){
                    cout<<" ["<<i+1<<"]  -   "<<peso[i]<<" -   "<<altura[i]<<" -   "<<sexo[i];
                    cout<<" -   "<<edad[i]<<endl;       
                    promF +=  peso[i];    
                    j++;                  
                }
            }
            if(j != 0){
                cout<<"Promedio es "<<promF/j<<endl;
            }else{
                cout<<"No se encontraron Registros\n";
            }
            cout<<"\n\n";
            system("pause");

            break;
        
        case 'b':


            cout<<"\n\n\t\tLLENANDO CENTRO ANUAL\n\n";
            for(int i = 0; i < 12; i++){
                cout<<"Ingresa registro Mes ["<<i+1<<"] : ";
                cin>>Centro[i];
                promCentro += Centro[i];
            }
            cout<<"\n\n\t\tLLENANDO SUR ANUAL\n\n";
            for(int i = 0; i < 12; i++){
                cout<<"Ingresa registro Mes ["<<i+1<<"] : ";
                cin>>Sur[i];
                promSur += Sur[i];
            }
            cout<<"\n\n\t\tLLENANDO GOLFO ANUAL\n\n";
            for(int i = 0; i < 12; i++){
                cout<<"Ingresa registro Mes ["<<i+1<<"] : ";
                cin>>Golfo[i];
                promGolfo += Golfo[i];
            }
            
            cout<<"\n\n\t\tLLENANDO PACIFICO ANUAL\n\n";
            for(int i = 0; i < 12; i++){
                cout<<"Ingresa registro Mes ["<<i+1<<"] : ";
                cin>>Pacifico[i];
                promPacifico += Pacifico[i];
                
            }
            
            cout<<"\n\n\t\tLLENANDO CARIBE ANUAL\n\n";
            for(int i = 0; i < 12; i++){
                cout<<"Ingresa registro Mes ["<<i+1<<"] : ";
                cin>>Caribe[i];
                promCaribe += Caribe[i];
            }

            cout<<"\n\n\t\tPROMEDIO ANUAL DE REGIONES\n\n";
            cout<<"Centro   -> "<<promCentro/12<<endl;
            cout<<"Sur      -> "<<promSur/12<<endl;
            cout<<"Golfo    -> "<<promGolfo/12<<endl;
            cout<<"Pacifico -> "<<promPacifico/12<<endl;
            cout<<"Caribe   -> "<<promCaribe/12<<endl;
            
            int RegistroRegion;

            cout<<"\n\n\t\tMAYOR Y MENOR TEMPERATURA CENTRO\n\n";
            for(int i = 0; i < 12; i++){
                if(mayor < Centro[i]){
                    mayor = Centro[i];
                    pos = i;
                    RegistroRegion = 1;
                }
                if(mayor < Sur[i]){
                    mayor = Sur[i];
                    pos = i;           
                    RegistroRegion = 2;         
                }
                if(mayor < Golfo[i]){
                    mayor = Golfo[i];
                    pos = i;
                    RegistroRegion = 3;
                }
                if(mayor < Pacifico[i]){
                    mayor = Pacifico[i];
                    pos = i;           
                    RegistroRegion = 4;         
                }
                if(mayor < Caribe[i]){
                    mayor = Caribe[i];
                    pos = i;
                    RegistroRegion = 5;
                }
            }
            cout<<"Temperatura Mayor fue de : "<<mayor<<endl;
            switch (pos)
            {
            case 0:cout<<"Enero\n";
                break;
            case 1:cout<<"Febrero\n";
                break;
            case 2:cout<<"Marzo\n";
                break;
            case 3:cout<<"Abril\n";
                break;
            case 4:cout<<"Mayo\n";
                break;
            case 5:cout<<"Junio\n";
                break;
            case 6:cout<<"Julio\n";
                break;
            case 7:cout<<"Agosto\n";
                break;
            case 8:cout<<"Septiembre\n";
                break;
            case 9:cout<<"Octubre\n";
                break;
            case 10:cout<<"Noviembre\n";
                break;
            case 11:cout<<"Diciembre\n";
                break;
            }

            switch (RegistroRegion)
            {
            case 1:cout<<"Centro\n";
                break;
            case 2:cout<<"Sur\n";
                break;
            case 3:cout<<"Golfo\n";
                break;
            case 4:cout<<"Pacifico\n";
                break;
            case 5:cout<<"Caribe\n";
                break;
            }

            for(int i = 0; i < 12; i++){
                if(menor > Centro[i]){
                    menor = Centro[i];
                    pos = i;
                    RegistroRegion = 1;
                }
                if(menor > Sur[i]){
                    menor = Sur[i];
                    pos = i;           
                    RegistroRegion = 2;         
                }
                if(menor > Golfo[i]){
                    menor = Golfo[i];
                    pos = i;
                    RegistroRegion = 3;
                }
                if(menor > Pacifico[i]){
                    menor = Pacifico[i];
                    pos = i;           
                    RegistroRegion = 4;         
                }
                if(menor > Caribe[i]){
                    menor = Caribe[i];
                    pos = i;
                    RegistroRegion = 5;
                }
            }
            cout<<"Temperatura Menor fue de : "<<menor<<endl;
            switch (pos)
            {
            case 0:cout<<"Enero\n";
                break;
            case 1:cout<<"Febrero\n";
                break;
            case 2:cout<<"Marzo\n";
                break;
            case 3:cout<<"Abril\n";
                break;
            case 4:cout<<"Mayo\n";
                break;
            case 5:cout<<"Junio\n";
                break;
            case 6:cout<<"Julio\n";
                break;
            case 7:cout<<"Agosto\n";
                break;
            case 8:cout<<"Septiembre\n";
                break;
            case 9:cout<<"Octubre\n";
                break;
            case 10:cout<<"Noviembre\n";
                break;
            case 11:cout<<"Diciembre\n";
                break;
            }

            switch (RegistroRegion)
            {
            case 1:cout<<"Centro\n";
                break;
            case 2:cout<<"Sur\n";
                break;
            case 3:cout<<"Golfo\n";
                break;
            case 4:cout<<"Pacifico\n";
                break;
            case 5:cout<<"Caribe\n";
                break;
            }            
            
            if(Sur > Pacifico && Sur > Caribe){
                cout<<"\n\nLa region con un promedio de temperatua anual mayor es Sur -> "<<promSur/12<<endl;

            }else if(Pacifico > Sur && Pacifico > Caribe){
                cout<<"\n\nLa region con un promedio de temperatura anual mayor es Pacifico-> "<<promPacifico/12<<endl;
            }
            else{
                cout<<"\n\nLa region con un promedio de temperatura anual mayor es Caribe-> "<<promCaribe/12<<endl;
            }

            cout<<"\n";
            system("pause");
            break;

        case 'c':
            cout<<"\nDesea Salir del programa? [SI - NO ] : ";
            fflush(stdin);
            getline(cin,newOPC);
            if(newOPC == "si" || newOPC == "SI"){
                salir = true;
            }
            else if(newOPC == "no" or newOPC == "NO"){
                cout<<"Decidio quedarse en el programa\n";
                salir = false;
                system("pause");
            }
            else{
                cout<<"\n\n\t\tIntroduzca un valor correcto\n\n";
                system("pause");
            }
            break;
        }


    }while(salir != true);

    return 0;
}