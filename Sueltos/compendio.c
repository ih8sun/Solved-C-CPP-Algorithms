#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
typedef char string[100];

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 

int Bienvenido(){
    system("cls");
    int num;
    int i;

    for(i = 20; i < 100; i++){//* Titulo
        Sleep(1);
        gotoxy(i,3);
        printf("*");
    }

    for(i = 3; i < 12; i++){//todo Esquinas
        Sleep(2);
        gotoxy(20,i);
        printf("*");
    }

    for(i = 20; i < 100; i++){//* Titulo
        gotoxy(i,12);
        Sleep(1);
        printf("*");
    }

    for(i = 3; i < 12; i++){//todo Esquinas
        gotoxy(100,i);
        Sleep(2);
        printf("*");
    }

    gotoxy(45,7);
    printf("Ingrese Fichas [Menor a 50] : ");
    scanf("%i",&num);


    return num;
}

void menu(int fichas,int puntaje){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t[ -> MENU DE JUEGOS <-]\n\n");
    printf("\t\t\t\t\t\t=> Fichas Actuales %i\n\n",fichas);
    printf("\t\t\t\t\t\t=> Puntaje Actual %i\n\n",puntaje);
    printf("\t\t\t\t[1]. Jugar Bingo - Precio 2 fichas\n");
    printf("\t\t\t\t[2]. Jugar Adivina - Precio 2 fichas\n");
    printf("\t\t\t\t[3]. Donde quedo la bolita? - Precio 3 fichas\n");
    printf("\t\t\t\t[4]. Salir\n");
    printf("\t\t\t\t[-]. Ingresa opcion : ");
}

void Bingo(int *, int *, bool *);

void Adivina(int *, int *, bool *);

void Bolita(int *, int *, bool *);

void inicializar(int [],int);

int main(){

    srand (time(NULL));

    int intentos = 0;
    int fichas,opc;
    int dinero = 0;

    bool salir = false;
    int puntaje = 0;
    do{
        fichas = Bienvenido();

        if(fichas >= 50){
            salir = false;
        }else{
            salir = true;
        }

    }while(salir != true);
    salir = false;
    
    do{
        menu(fichas,puntaje);
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:intentos++;
            Bingo(&fichas,&puntaje, &salir);

            break;
        
        case 2:intentos++;
            Adivina(&fichas,&puntaje,&salir);
            break;
        
        case 3:intentos++;
            Bolita(&fichas,&puntaje,&salir);
            break;
        
        case 4:
            printf("\n\n\t\tSALIENDO DEL MENU\n\n");
            system("pause");
            salir = true;
            break;
        
        default:
            salir = false;
            break;
        }

    }while(salir != true );

    if(puntaje <= 999){
        dinero = puntaje  * 0.1;
    }
    if(puntaje >= 1000 && puntaje <= 2999){
        dinero = puntaje * 0.2;
    }
    if(puntaje >= 3000 && puntaje <= 3999){
        dinero = puntaje * 0.5;
    }
    if(puntaje >= 4000){
        dinero = puntaje * 1;
    }

    printf("\n\n\t\t[ RESULTADOS FINALES ]\n\n");
    printf("\t\tDinero Ganado : %i\n",dinero);
    printf("\t\tFichas Actuales : %i\n",fichas);

    return 0;
}


void Bingo(int *f1, int *p1, bool *salir){

    int fichas = *f1;

    int numeros[3];

    int bombo[3];

    int puntajeObtenido = 0;
    int puntajeFinal = *p1;


    int i,j;
    int menor;
    int coincidir = 0;

    bool correcto = false;
    bool Ac1 = false;
    bool Ac2 = false;
    bool Ac3 = false;


    if(fichas >= 3){
        fichas -= 2;
        for(i = 0; i < 3; i++){

            Ac1 = false;
            Ac2 = false;
            Ac3 = false;
            coincidir = 0;

            system("cls");
            correcto = false;
            printf("\n\n\t\t[ JUEGO DE BINGO ]\n");
            printf("\t\t -> R O N D A %i <-\n\n",i+1);

            for(j = 0; j < 3; j++){
                do{
                    printf("\nIngresa numero 1 [1 - 20] : ");
                    scanf("%i",&numeros[j]);

                    if(numeros[j] >= 1 && numeros[j] <=20){
                        correcto = true;
                    }else{
                        printf("Ingrese un numero correcto!!\n");
                        correcto = false;
                    }
                }while(correcto != true);

            }

            menor = numeros[0];

            printf("\n\nOBTENIENDO RESULTADOS DE BOMBOS\n\n");
            bombo[0] = rand () % (20-1+1)+1;
            printf("Resultado Pelota [1]-> %i\n",bombo[0]);
            bombo[1] = rand () % (20-1+1)+1;
            printf("Resultado Pelota [2]-> %i\n",bombo[1]);
            bombo[2] = rand () % (20-1+1)+1;
            printf("Resultado Pelota [3]-> %i\n\n",bombo[2]);

            for(j = 0; j < 3; j++){
                if(numeros[0] == bombo[j]){
                    Ac1 = true;
                }
            }
            for(j = 0; j < 3; j++){
                if(numeros[1] == bombo[j]){
                    Ac2 = true;
                }
            }
            for(j = 0; j < 3; j++){
                if(numeros[2] == bombo[j]){
                    Ac3 = true;
                }
            }

            if(Ac1 && Ac2 && Ac3){
                puntajeObtenido += 1000;
            }else{
                
                for(j = 0; j < 3; j++){
                    if(menor > numeros[j]){
                        menor = numeros[j];
                    }
                }

                for(j = 0; j < 3; j++){
                    if(numeros[0] == bombo[j]){
                        coincidir++;
                        break;
                    }
                }
                for(j = 0; j < 3; j++){
                    if(numeros[1] == bombo[j]){
                        coincidir++;
                        break;
                    }
                }
                for(j = 0; j < 3; j++){
                    if(numeros[2] == bombo[j]){
                        coincidir++;
                        break;
                    }
                }
            
                if(coincidir == 2){
                    puntajeObtenido += 500;
                }else{
                    puntajeObtenido -= menor;
                }
            }

            printf("\n\n[ Puntaje Actual ] : %i\n",puntajeObtenido);

            system("pause");
        }


        *p1 += puntajeObtenido;
        

    }else{
            printf("\n\nFaltan Fichas Para poder Jugar :( \n\n");
            *salir = true;
    }

    *f1 = fichas;
    if(*p1 < 0){
        *p1 = 0;
    }
}

void Adivina(int *f1, int *p1, bool *salir){

    int fichas = *f1;

    string predicciones[25] = {"Tendras un buen dia",
    "Sera un dia malo", "morira un ser amado","sera una semana dura",
    "Juega al 10 en la loteria","Moriras","no cenaras hoy","no comas carne hoy",
    "el proximo partido lo ganara Barcelona","el vino se derrama","el camion se estallara",
    "la comida tendra mal olor","la cama caera","el avion no vendra","el agua se revalsara"};

    int rondas = 3;
    int i,j;
    char nombre[10];
    char signo[10];
    char pregunta[50];
    int contador = 0;
    int opc;
    bool salir2 = false;
    
    
    if(fichas >= 2){

        fichas -= 2;
        *f1 = fichas;

        do{
            system("cls");
            printf("\n\n\t\t [ CUARTO DE PREDICCIONES ] \n\n");
            
            printf("Puntaje Actual -> %i\n\n",contador);
            printf("Ingresa tu nombre : ");
            fflush(stdin);
            gets(nombre);

            printf("Ingresa tu signo zodiacal : ");
            fflush(stdin);
            gets(signo);

            printf("\n-----------------------\n");
            printf("Hazle una pregunta a la adivina : ");
            fflush(stdin);
            gets(pregunta);
            
            j = rand () % (20-1+1)+1;

            printf("Prediccion -> %s",predicciones[j]);

            printf("\nDesea hacer otra pregunta ? \n");
            printf("[1]. Si\n");
            printf("[2]. No\n");
            contador += 100;
            printf("\n[=]. Elija opcion : ");
            scanf("%i",&opc);
            switch (opc)
            {
                case 1:
                    salir2 = false;
                    break;
                
                case 2:
                    salir2 = true;
                    break;
                
                default:salir2 = true;
                break;
            }


        }while(salir2 != true);

        *p1 += contador;

    }else{
        printf("\n\nFICHAS INSUFICIENTES\n\n");
    }

}

void inicializar(int hueco[],int n){
    
    int i = 0;

    for(i = 0; i < 10; i++){
        hueco[i] = 0;
    }
}

void Bolita(int *f1, int *p1, bool *salir){
    
    system("cls");
    int fichas = *f1; //! 15
    int rondas = 3;
    int i,x;
    int hueco[10],intento,j;
    int pos;
    int ptjObtenido = 0;
    

    if(fichas >= 3){
        
        fichas -= 3; //! 15 - 3 = 12;
        *f1 = fichas; 
        
        for(i = 0; i < rondas; i++){

            system("cls");
            inicializar(hueco, 10);
            pos = 1+rand()%(11-1); //1 al 10; *5
            hueco[pos] = 1;
			
			printf("Hueco : %i\n\n",pos);
            for(x = 0; x < 10; x++){
                printf("hueco %i : %i\n",x,hueco[x]);
            }

            printf("\n\n\t\t[ DONDE QUEDO LA BOLITA ] ? \n");
            printf("\t\tPuntaje Global -> %i\n\n",*p1);
            printf("Puntaje Actual : %i\n\n",ptjObtenido);
            
            printf("Ingrese Numero de hueco de [0 - 9 ] : ");
            scanf("%i",&intento);

            if(hueco[intento] == 1 ){
                printf("\nAcerto En esta ronda :)!! + 1000 pts.\n\n");
                ptjObtenido += 1000;
            }else{
                printf("\nNo Acerto En esta ronda!! :)- 500 pts.\n\n");
                ptjObtenido -= 500;
            }
            system("pause");
        }

        if(*p1 < 0){
            ptjObtenido = 0;
            *p1 += ptjObtenido;
        }else{
            *p1 += ptjObtenido; 
        }

    printf("\n\n El puntaje obtenido en este juego es de %i\n\n",ptjObtenido);
    system("pause");

    }else{
        printf("\n\nFICHAS INSUFICIENTES\n\n");
        *salir = true;
    }
}
