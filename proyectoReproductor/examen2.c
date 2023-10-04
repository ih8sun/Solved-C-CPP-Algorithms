#include <stdio.h> //Importamos libreria de entrada y salida de datos


float hallarFahrenheit(float C){//Creamos funcion de hallar fahrenheit

    float F;//creamos F que luego la retornaremos

    F = (C * 9/5) + 32;//Formula dada

    return F;//retornamos F para guardarla en una variable

}

float hallarKelvin(float C){//Creamos funcion de hallar kelvin

    float K;//creamos K

    K = (C + 273.15);//guardamos en K el resultado de la formula

    return K;//retornamos K para guardalo en una variable

}

int main(){


    float celsius,fa,ke;//varibales para calcular
    int salir = 1;//variables para salir y corregir
    int correcto = 0;

    printf("\n\n\t\t[ HALLANDO TEMPERATURAS ]\n\n");

    while(salir != 0){//mientras que salir sea diferente de 0 , estre continuara funcionando
        
        do{//pedira datos gasta que correcta sea 1
            printf("\nIngresa la temperatura en Celsius : ");
            scanf("%f",&celsius);//pedimos el celsius

            if(celsius >= -5 && celsius <= 5){
                correcto = 1;//si esta en el rango, correcto pasa a 1
            }else{
                correcto = 0;//si no lo esta correcta seguira siendo 0
                printf("Elija un rango de -5 a 5\n");
            }

        }while(correcto != 1);//hara hasta que correcto llegue a ser 1
        
        fa = hallarFahrenheit(celsius);//guardamos resultado de la funcion fahrenheti
        ke = hallarKelvin(celsius);//guardamos resultado de la funcion kelvin
        printf("\nCelsius\t\t  Fahrenheit\t\t  Kelvin\n\n");//imprimimos con formato
        printf("%.2f\t\t   %.2f\t\t   %.2f",celsius,fa,ke);//imprimimos



        printf("\n\nDesea Seguir ? [1] Si. [0] No : ");//preguntamos si desea seguir
        scanf("%i",&salir);//depende de eso es que seguira

    }

    printf("\n\n\t\t[ HASTA LUEGO ]\n\n");

    return 0;
}