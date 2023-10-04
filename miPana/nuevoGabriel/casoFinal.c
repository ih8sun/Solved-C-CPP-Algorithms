#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define pi 3.14
#define tamCam 4//Tamanio de carros
#define tamCal 11//Tamanio de resultados

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}  

void titulo(){

    int y = 2;

        gotoxy(50,0);
        printf("TABLA DE RESULTADOS");

        gotoxy(1,y);
        printf("Camion");

        gotoxy(11,y);
        printf("Capacidad");

        gotoxy(24,y);
        printf("RPM");

        gotoxy(30,y);
        printf("Tiempo_T_V");

        gotoxy(43,y);
        printf("Diametro Rueda");

        gotoxy(60,y);
        printf("Costo Total");

        gotoxy(73,y);
        printf("Can_Di_Via");

        gotoxy(85,y);
        printf("Rendimiento");

        gotoxy(100,y);
        printf("D_T_R");

        gotoxy(110,y);
        printf("Costo/(t*km)");

        gotoxy(125,y);
        printf("Velocidad P(km/h)");



}


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

    system("cls");
    titulo();


    for(i = 0; i < tamCam; i++){
        y = i+5;

        gotoxy(1,y);
        printf("Camion %0.f",camion[i][0]);

        gotoxy(15,y);
        printf("%.0f",camion[i][1]);

        gotoxy(23,y);
        printf("%.2f",camion[i][2]);

        gotoxy(32,y);
        printf("%.2f",camion[i][3]);

        gotoxy(47,y);
        printf("%.2f",camion[i][4]);

        gotoxy(62,y);
        printf("%.0f",camion[i][5]);

        gotoxy(77,y);
        printf("%.0f",camion[i][6]);

        gotoxy(88,y);
        printf("%.2f",camion[i][7]);

        gotoxy(100,y);
        printf("%.2f",camion[i][8]);

        gotoxy(112,y);
        printf("%.2f",camion[i][9]);

        gotoxy(130,y);
        printf("%.2f",camion[i][10]);

    }
    
    for(i = 0; i < tamCam; i++){
        if(mayorRe < camion[i][7]){
            posRe = i;
            mayorRe = camion[i][7];
        }
    }

    gotoxy(1,y+3);
    printf("El Camion [ %0.f ] tuvo el mejor rendimiento\n\n",camion[posRe][0]);

    for(i = 0; i < tamCam; i++){
        if(costoMenor > camion[i][9]){
            posMe = i;
            costoMenor = camion[i][9];
        }
    }

    gotoxy(1,y+4);
    printf("El Camion [ %0.f ] tuvo el menor Costo\n\n",camion[posMe][0]);



    return 0;
}