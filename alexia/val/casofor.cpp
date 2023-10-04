#include <iostream>
using namespace std;

int main(){

    int i = 0, sumaTotal = 0;
    //Creamos un for que sera (inicia en 1, va de 1 hasta 30; y se incremen de 1en 1
    
    for(i = 1; i <= 30 ; i++){

        //dentro de ese for preguntaremos si el valor de actual de i
        // es par o impar

        if(i % 2 != 0){// si la division de i entre 2 es distinta a 0
        //significa que es impar

            //Entonces agregamos lo que tiene i con suma 
            sumaTotal += i; //Esto es lo mismo que sumaTotal = sumaTotal + 1
            //*Podemos imprimir sumatotal para ver como va aumentando
            cout<<sumaTotal<<endl;
        }else{//Podemos obviar el else ya que no necesitamos
        //numeros pares para este programa, solo impares
        }

    }

    cout<<"\nSuma total es  : "<<sumaTotal<<endl;

    return 0;
}