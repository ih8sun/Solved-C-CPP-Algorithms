#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct nuevoMantenimiento{

    char area[20];
    char maquinaria[40];
    char empresaEncargada[50];
    int dia,mes,anio;
    int duracion;
    float costo;
    char formaPago[15];

    bool Resultados;
};

void nuevoMantein(struct nuevoMantenimiento [], int i);
void reportePorArea(struct nuevoMantenimiento [], int i);
void reportePorMES(struct nuevoMantenimiento [], int i);
void reporteGastosMes(struct nuevoMantenimiento nuevo[], int max);
void reporteGastosArea(struct nuevoMantenimiento nuevo[], int max);

void menu(){
    system("cls");
    printf("\n\n\t\t[ MAQUINARIAS -> EL PEPE <- ]\n\n");
    printf("[1]. Ingresa Nuevo Reporte al sistema.\n");
    printf("[2]. Reporte General por Areas.\n");
    printf("[3]. Reporte de Mantenimiento por Mes.\n");
    printf("[4]. Reporte de Gastos por Mes.\n");
    printf("[5]. Reporte de Gastos por Area.\n");
    printf("[6]. Salir del Menu.\n");
    printf("\n[-]. Ingrese una opcion : ");
}

int main(){

    struct nuevoMantenimiento nuevo[100]; //Registro de 100 maquinas.
    bool salir = false;
    int opc;
    int i = 0;

    do{
        menu();
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:
            nuevoMantein(nuevo,i);
            i++;
            break;
        
        case 2:
            reportePorArea(nuevo,i);
            break;
        
        case 3:
            reportePorMES(nuevo,i);
            break;
        
        case 4:
            reporteGastosMes(nuevo,i);
            break;
        
        case 5:
            reporteGastosArea(nuevo,i);
            break;

        case 6:
            printf("\n\n\t\tGRACIAS POR USAR EL PROGRAMA\n\n");
            salir = true;
            break;
        }


    }while(salir != true);
    

}


void nuevoMantein(struct nuevoMantenimiento nuevo[], int i){

    bool correcto = false;
    int opc;

    char visa[4] = "Visa";
    char masterCard[10] = "MasterCard";
    char efectivo[8] = "Efectivo";

    system("cls");

    do{
        system("cls");
        printf("\n\n\t\t[ INGRESO DE ALGUN MANTENIMIENTO AL SISTEMA ]\n\n");
        printf("\nIngresa Area donde se realizo el mantenimiento\n\n");
        printf("[0]. Herreria\n");
        printf("[1]. Carpinteria\n");
        printf("[2]. Maquinarias\n");
        printf("[3]. Produccion\n");
        printf("[4]. Transporte\n");
        printf("[5]. Jefatura\n");
        printf("[6]. Electrica\n");
        printf("\n[=]. Ingresa una opcion : ");
        scanf("%i",&opc);
        switch (opc)
        {
        case 0:
            strcpy(nuevo[i].area,"Herreria");
            correcto = true;
            break;
        case 1:
            strcpy(nuevo[i].area,"Carpinteria");
            correcto = true;
            break;
        case 2:
            strcpy(nuevo[i].area,"Maquinarias");
            correcto = true;
            break;
        case 3:
            strcpy(nuevo[i].area,"Produccion");
            correcto = true;
            break;
        case 4:
            strcpy(nuevo[i].area,"Transporte");
            correcto = true;
            break;
        case 5:
            strcpy(nuevo[i].area,"Jefatura");
            correcto = true;
            break;
        case 6:
            strcpy(nuevo[i].area,"Electrica");
            correcto = true;
            break;
        default:
            system("cls");
            break;
        }
        
    }while(correcto != true);

    system("cls");
    correcto = false;

    printf("\n\n\t\t [ MAQUINARIA - MANTENIMIENTO ]\n\n");
    printf("Ingresa a que maquina se le realizo el mantenimiento : ");
    fflush(stdin);
    gets(nuevo[i].maquinaria);
    
    system("cls");

    do{
        system("cls");
        printf("\n\n\t\t [ MAQUINARIA - EMPRESA ]\n\n");
        printf("Ingresa Empresa que fue la encargada de este mantenimiento\n");
        printf("[1]. Mexico S.A.C \n");
        printf("[2]. Mecanicos Mex\n");
        printf("[3]. Duros y Furiosos\n");
        printf("[4]. Don Fierro S.A.C\n\n");
        printf("[-]. Ingresa : ");
        fflush(stdin);
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:
            strcpy(nuevo[i].empresaEncargada,"Mexico S.A.C");
            fflush(stdin);
            correcto = true;
            break;
        case 2:
            strcpy(nuevo[i].empresaEncargada,"Mecanicos Mex");
            fflush(stdin);
            correcto = true;
            break;
        case 3:
            strcpy(nuevo[i].empresaEncargada,"Duros y Furiosos");
            fflush(stdin);
            correcto = true;
            break;
        case 4:
            strcpy(nuevo[i].empresaEncargada,"Don Fierro S.A.C");
            fflush(stdin);
            correcto = true;
            break;
        }

    }while(correcto != true);
    fflush(stdin);
    correcto = false;
    system("cls");

    printf("\n[ Ingreso de Fechas ]\n\n");
    printf("Ingresa Dia de Mantenimiento : ");
    fflush(stdin);
    scanf("%i",&nuevo[i].dia);
    printf("Ingresa Mes de Mantenimiento : ");
    fflush(stdin);
    scanf("%i",&nuevo[i].mes);
    printf("Ingresa Anio de Mantenimiento : ");
    fflush(stdin);
    scanf("%i",&nuevo[i].anio);

    printf("Ingresa Duracion de Mantenimiento [Minutos] : ");
    scanf("%i",&nuevo[i].duracion);



    do{system("cls");
        printf("\n[ METODOS DE PAGO ] \n\n");
        
        printf("\nIngresa metodo de pago\n");
        printf("[1]. Visa\n");
        printf("[2]. MasterCard\n");
        printf("[3]. Efectivo\n");
        printf("\n[-]. Ingresa una opcion : ");
        scanf("%i",&opc);
        switch (opc)
        {
        case 1:
                strcpy(nuevo[i].formaPago,visa);
                correcto = true;
            break;
        
        case 2:
                strcpy(nuevo[i].formaPago,masterCard);
                correcto = true;
            break;
        
        case 3:
                strcpy(nuevo[i].formaPago,efectivo);
                correcto = true;
            break;
        
        default:correcto = false;
            break;
        }
    }while(correcto != true);

}

void reportePorArea(struct nuevoMantenimiento nuevo[], int max){

    int opc2,i;
    bool correcto = false;
    int opc;
    do{
        system("cls");
        printf("\n\n\t\t[ MANTENIMIENTO POR AREA ]\n\n");
        printf("\nIngresa area a mostrar registro : \n\n");
        printf("[0]. Herreria\n");
        printf("[1]. Carpinteria\n");
        printf("[2]. Maquinarias\n");
        printf("[3]. Produccion\n");
        printf("[4]. Transporte\n");
        printf("[5]. Jefatura\n");
        printf("[6]. Electrica\n");
        printf("\n[=]. Ingresa una opcion : ");
        scanf("%i",&opc2);
        switch (opc2)
        {
        case 0:correcto = true;
        for(i = 0; i < max; i++){
            if(strcmp(nuevo[i].area,"Herreria")== 0){
                printf("Area : %s\n",nuevo[opc].area);
                printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                printf("Duracion : %s\n",nuevo[opc].duracion);
                printf("Costo : %2.f\n", nuevo[opc].costo);
                printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
            }
        }
        break;
        case 1:correcto = true;
    for(i = 0; i < max; i++){
        if(strcmp(nuevo[i].area,"Carpinteria")== 0){
            printf("Area : %s\n",nuevo[opc].area);
            printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
            printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
            printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
            printf("Duracion : %s\n",nuevo[opc].duracion);
            printf("Costo : %2.f\n", nuevo[opc].costo);
            printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
        }
    }
        break;

        case 2:correcto = true;
    for(i = 0; i < max; i++){
        if(strcmp(nuevo[i].area,"Maquinarias")== 0){
            printf("Area : %s\n",nuevo[opc].area);
            printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
            printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
            printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
            printf("Duracion : %s\n",nuevo[opc].duracion);
            printf("Costo : %2.f\n", nuevo[opc].costo);
            printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
        }
    }
        break;

        case 3:correcto = true;
        for(i = 0; i < max; i++){
            if(strcmp(nuevo[i].area,"Produccion")== 0){
                printf("Area : %s\n",nuevo[opc].area);
                printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                printf("Duracion : %s\n",nuevo[opc].duracion);
                printf("Costo : %2.f\n", nuevo[opc].costo);
                printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
            }
        }
        break;

        case 4:correcto = true;
        for(i = 0; i < max; i++){
            if(strcmp(nuevo[i].area,"Transporte")== 0){
                printf("Area : %s\n",nuevo[opc].area);
                printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                printf("Duracion : %s\n",nuevo[opc].duracion);
                printf("Costo : %2.f\n", nuevo[opc].costo);
                printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
            }
        }
        break;

        case 5:correcto = true;
        for(i = 0; i < max; i++){
            if(strcmp(nuevo[i].area,"Jefatura")== 0){
                printf("Area : %s\n",nuevo[opc].area);
                printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                printf("Duracion : %s\n",nuevo[opc].duracion);
                printf("Costo : %2.f\n", nuevo[opc].costo);
                printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
            }
        }
        break;

        case 6:
            correcto = true;
        for(i = 0; i < max; i++){
            if(strcmp(nuevo[i].area,"Electrica")== 0){
                printf("Area : %s\n",nuevo[opc].area);
                printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                printf("Duracion : %s\n",nuevo[opc].duracion);
                printf("Costo : %2.f\n", nuevo[opc].costo);
                printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
            }
        }
            break;
        default:
            system("cls");
            break;
        }
        
    }while(correcto != true);



    system("pause");
}

void reportePorMES(struct nuevoMantenimiento nuevo[], int max){

    int opc2,i;
    bool correcto = false;
    int opc;
    do{
        system("cls");
        printf("\n\n\t\t[ MANTENIMIENTO POR MES ]\n\n");
        printf("\nIngresa mes a mostrar registro [1 - 12]: \n\n");
        printf("\n[=]. Ingresa una opcion : ");
        scanf("%i",&opc2);
        switch (opc2)
        {

        case 1:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 1){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;
        case 2:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 2){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;
        case 3:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 3){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;

        case 4:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 4){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;

        case 5:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 5){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;

        case 6:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 6){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;

        case 7:correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 7){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
        break;

        case 8:
            correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 8){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
            break;

        case 9:
            correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 9){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
            break;

        case 10:
            correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 10){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
            break;


        case 11:
            correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 11){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
            break;


        case 12:
            correcto = true;
            for(i = 0; i < max; i++){
                if(nuevo[i].mes== 12){
                    printf("Area : %s\n",nuevo[opc].area);
                    printf("Maquinaria : %s\n",nuevo[opc].maquinaria);
                    printf("Empresa Encargada : %s\n",nuevo[opc].empresaEncargada);
                    printf("Dia/Mes/Anio : %i/%i/%i\n",nuevo[opc].dia,nuevo[opc].mes,nuevo[opc].anio);
                    printf("Duracion : %s\n",nuevo[opc].duracion);
                    printf("Costo : %2.f\n", nuevo[opc].costo);
                    printf("Forma Pago : %s\n\n",nuevo[opc].formaPago);
                }
            }
            break;

        default:
            system("cls");
            break;
        }
        
    }while(correcto != true);



    system("pause"); 
    
}

void reporteGastosMes(struct nuevoMantenimiento nuevo[], int max){

    int opc;
    bool entro = false;
    int i,mes;
    system("cls");

    printf("\n\n\t\t[ REPORTE DE GASTOS POR MES ] \n\n");
    printf("Ingresa numero de mes : ");
    scanf("%i",&mes);


    for(i=  0 ; i < max; i++){
        if(nuevo[i].mes == mes){
            printf("\nMes del Mantenimiento : %i\n",mes);
            printf("Maquinaria reparada : %s\n",nuevo[i].maquinaria);
            printf("Costo del reparo : %f\n",nuevo[i].costo);
            printf("Fomra de Pago : %s\n",nuevo[i].formaPago);
        }
    }

    system("pause");
}

void reporteGastosArea(struct nuevoMantenimiento nuevo[], int max){

int opc;
    bool entro = false;
    int i,mes;
    system("cls");

    printf("\n\n\t\t[ REPORTE DE GASTOS POR AREA ] \n\n");
    printf("\nIngresa area a mostrar registro : \n\n");
    printf("[0]. Herreria\n");
    printf("[1]. Carpinteria\n");
    printf("[2]. Maquinarias\n");
    printf("[3]. Produccion\n");
    printf("[4]. Transporte\n");
    printf("[5]. Jefatura\n");
    printf("[6]. Electrica\n");
    printf("\n[=]. Ingresa una opcion : ");
    scanf("%i",&mes);

    for(i=  0 ; i < max; i++){
        if(nuevo[i].mes == mes){
            printf("\nMes del Mantenimiento : %i\n",mes);
            printf("Maquinaria reparada : %s\n",nuevo[i].maquinaria);
            printf("Costo del reparo : %f\n",nuevo[i].costo);
            printf("Fomra de Pago : %s\n",nuevo[i].formaPago);
        }
    }

    system("pause");
}