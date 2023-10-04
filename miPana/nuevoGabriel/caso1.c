#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define pi 3.14
#define tamCam 4//Tamanio de carros
#define tamCal 11//Tamanio de resultados


int main(){

    float camion[tamCam][tamCal];
    int i,j = 0,y;

    float mayorRe = 0;
    int posRe = 0;
    int posMe = 0;
    float costoMenor = 999999;
    

    printf("\n\n\t\t[ INGRESO DE DATOS AL CAMION ]\n\n");

    for( i = 0; i < tamCam; i++){
        j = 0;
        camion[i][j] = (i+1)*1.0;

        printf("\n\n\t\tINGRESO DE CAMION N -> %i\n\n",i+1);
        for(j = 1; j < tamCal; j++){
            if(j == 1){
            printf("Ingresa la capacidad (T.Toneladas) : ");
            scanf("%f",&camion[i][j]);
            }
            if(j == 2){
            printf("Ingresa RPM ruedas : ");
            scanf("%f",&camion[i][j]);
            
            }
            if(j == 3){
            printf("Ingresa tiempo total de viaje (H): ");
            scanf("%f",&camion[i][j]);
            }
            if(j == 4){
            printf("Ingresa Diametro de la rueda (cm) : ");
            scanf("%f",&camion[i][j]);
            }
            if(j == 5){
            printf("Ingresa Costo Total : ");
            scanf("%f",&camion[i][j]);
            }
            if(j == 6){
            printf("Ingresa Cantidad de diesel por viaje (L) : ");
            scanf("%f",&camion[i][j]);
            }
        }
    }

    for(i = 0; i < tamCam; i++){
        
        //Distancia Total recorrida CM
        camion[i][8] = camion[i][2] * pi * camion[i][4] * (camion[i][3] * 60);
        //Convirtiendo distancia total Recorrida CM a KM
        camion[i][8] /= 100000;  

        camion[i][9] =  camion[i][5]/(camion[i][1] * camion[i][8]); 

        //RENDIMIENTO
        camion[i][7] = camion[i][8] / camion[i][6];

        //Velocidad Promedio
        camion[i][10] = camion[i][8]/camion[i][3];
    }

    
    for(i = 0 ; i < tamCam; i++){
        printf("\n\n\t\t[ CAMION -> %i ]<-\n\n",i+1);
        for(j = 0; j < tamCal; j++){

            if(j == 1){
            printf("(T.Toneladas) : %.2f\n",camion[i][j]);
            }

            if(j == 2){
            printf("RPM ruedas : %.2f\n",camion[i][j]);
            }

            if(j == 3){
            printf("tiempo total de viaje (H): %.2f\n",camion[i][j]);
            }

            if(j == 4){
            printf("Diametro de la rueda (cm) : %.2f\n",camion[i][j]);
            }

            if(j == 5){
            printf("Costo Total : %.2f\n",camion[i][j]);
            }

            if(j == 6){
            printf("Cantidad de diesel por viaje (L) : %.2f\n",camion[i][j]);
            }

            if(j == 7){
            printf("Rendimiento (Km/L) : %.2f\n",camion[i][j]);
            }

            if(j == 8){
            printf("Distancia total Recorrida(Km) : %.2f\n",camion[i][j]);
            }

            if(j == 9){
            printf("Costo/(T*Km) : %.2f\n",camion[i][j]);
            }

            if(j == 10){
            printf("Velocidad Promedio (Km/h) : %.2f\n",camion[i][j]);
            }

        }
    }
    

    for(i = 0; i < tamCam; i++){
        if(mayorRe < camion[i][7]){
            posRe = i;
            mayorRe = camion[i][7];
        }
    }



    printf("\nEl Camion [ %0.f ] tuvo el mejor rendimiento\n",camion[posRe][0]);

    for(i = 0; i < tamCam; i++){
        if(costoMenor > camion[i][9]){
            posMe = i;
            costoMenor = camion[i][9];
        }
    }

    printf("El Camion [ %0.f ] tuvo el menor Costo\n\n",camion[posMe][0]);



    return 0;
}