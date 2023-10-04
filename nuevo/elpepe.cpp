#include <iostream>
using namespace std;


int main(){

    bool salir = false;
    int panSemita = 0,cacho = 0,marga = 0,con = 0, quesa = 0;
    int pan,total = 0;

    cout<<"\n\n\t\t[ TIPOS DE PAN A COMPRAR ]\n\n";
    do{
        cout<<"\nIngresa el tipo de pan que comprara\n";
        cout<<"[1]. Semita\n[2]. Cacho\n[3]. Margarita\n[4]. concha\n";
        cout<<"[5]. Quesadilla\n[6]. Salir\n\n[-]. Ingresa opcion : ";
        cin>>pan;
        switch (pan)
        {
        case 1:
            cout<<"\nIngrese cuantos panes comprara : ";
            cin>>pan;
            panSemita += pan;
            break;
        
        case 2:
            cout<<"\nIngrese cuantos panes comprara : ";
            cin>>pan;
            cacho += pan;
            break;
        
        case 3:
            cout<<"\nIngrese cuantos panes comprara : ";
            cin>>pan;
            marga += pan;
            break;
        
        case 4:
            cout<<"\nIngrese cuantos panes comprara : ";
            cin>>pan;
            con += pan;
            break;
            
        case 5:
            cout<<"\nIngrese cuantos panes comprara : ";
            cin>>pan;
            quesa += pan;
            break;

        case 6:
            salir = true;
            break;
        }

    }while(salir != true);

    total = panSemita + cacho + marga + con + quesa;

    cout<<"\n\n\t\t[ RESULTADOS FINALES ]\n\n";
    cout<<"Total de panes vendidos de hoy : "<<total<<endl;
    cout<<"Pan semita -> "<<panSemita<<endl;
    cout<<"Pan Cacho  -> "<<cacho<<endl;
    cout<<"Pan Margarita -> "<<marga<<endl;
    cout<<"Pan Concha -> "<<con<<endl;
    cout<<"Pan Quesadilla -> "<<quesa<<endl;


    return 0;
}