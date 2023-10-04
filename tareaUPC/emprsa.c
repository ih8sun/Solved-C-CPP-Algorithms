#include <stdio.h>
int main(){

    char nombre[40];
    int edad;
    char sexo;
    char estadoCivil;
    float ingresoObtenido;

    int tamEmpleados;
    int tamHombres = 0;

    float tamSolterosHombres = 0,tamCasadosMujeres = 0;
    int i;
    
    printf("\n\n\t\t[ CANTIDAD DE OBREROS ]\n\n");
    printf("Ingresa cantidad de empleados a registrar : ");
    scanf("%i",&tamEmpleados);

    printf("\n\n\t\t[ INGRESO DE DATOS DE EMPLEADOS ]\n\n");
    for(i = 0; i < tamEmpleados; i++){

        printf("\nEmpleado [ %i ]\n",i+1);
        printf("Ingresa Nombre de Empleado : ");
        fflush(stdin);
        gets(nombre);

        printf("Ingresa Edad de Empleado : ");
        scanf("%i",&edad);

        printf("Ingresa Sexo de Empleado [ M - F ]: ");
        fflush(stdin);
        scanf("%c",&sexo);
        
        printf("Ingresa ESTADO CIVIL de Empleado [ S(soltero) - C(casado) ] : ");
        fflush(stdin);
        scanf("%c",&estadoCivil);

        printf("Ingresa Sueldo Obtenido : " );
        scanf("%f",&ingresoObtenido);

        if(sexo == 'M'){
            tamHombres++;
            if(estadoCivil == 'S'){
                tamSolterosHombres++;
            }
        }

        if(sexo == 'F'){
            if(estadoCivil == 'C'){
                tamCasadosMujeres++;
            }
        }

    }

    float resp1 =(tamCasadosMujeres/100)*tamEmpleados;

    float resp2 =(tamSolterosHombres/100)*tamEmpleados;

    printf("\n\n\t\t[ MOSTRANDO RESULTADOS ]\n\n");
    printf("Cantidad de Hombres en la empresa -> %i\n",tamHombres);
    printf("Cantidad de Mujeres Casadas : %i\n",tamCasadosMujeres);
    printf("Cantidad de Hombres Solteros : %i\n",tamSolterosHombres);
    printf("Porcentaje de Mujeres Casadas : %.2f\n",resp1);
    printf("Porcentaje de Hombres Solteros : %.2f\n",resp2);




    return 0;
}