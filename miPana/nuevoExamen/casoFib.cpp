#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n == 0 || n == 1)
       return n;
    else
       return fibo(n - 2) + fibo(n - 1);
}

int main()
{
    cout<<"\n\t\t SERIE FIBONACCI \n\n";
    
    int i, num,j = 0;
    bool correcto = false;
    bool salir = false;
    int opc;
    do
    {
        cout<<"Ingrese un numero entero y positivo (1-40): ";
        cin>>num;
        if(num >= 1 && num < 40){
            correcto = true;
        }else{
            correcto = false;
        }
        
    }while(correcto != true);

    int array[num];
    
    
    for(i=0; i<num; i++)
    {
    //    if(fibo(i) != 0){
    //       cout<< ", "; 
    //    }
        
        //cout<< fibo(i);       
        array[j] = fibo(i);
        j++;
    }
    
    cout<<"\n\n\t\tIMPRIMIENDO SERIE\n\n";
    for(i = 0; i < num; i++){

        if(i != num-1){
            cout<<array[i]<<"  ->  ";
        }else{           
            cout<<array[i];   
        }
    }

    cout<<"\n\n\t\tENCONTRANDO ELEMENTOS\n\n";
    do{
        cout<<"Ingresa posicion de Elemento a encontrar (0 - "<<num-1<<")\n";
        cout<<"-1 para Salir\nIngresa : ";
        cin>>opc;
        if(opc != -1){
            if(opc >= 0 && opc <= num-1){
                cout<<"Es: "<<array[opc]<<endl<<endl;
            }else{
                cout<<"\nIngresa una posicion valida\n\n";
            }
        }else{
            salir = true;
            cout<<"\n\nGracias por usar el Programa\n\n";
        }
    }while(salir != true);
    

    cout<<"\n\n";    
    return 0;
}