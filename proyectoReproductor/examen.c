#include <stdio.h> //Importamos libreria de entrada y salida de datos


void menu(){ //menu de opciones, que luego importarmeos
    printf("\n\n\t[ MENU ]\n\n");
    printf("[1]. Area del rectangulo\n");
    printf("[2]. Area del Triangulo\n");
    printf("[3]. Volumen del Cubo\n");
    printf("[?]. Ingresa una opcion : ");
}


float areaRectangulo(float b,float h){//funcion que recibe dos parametros

    return b*h;//retornara b por h y sera guardado en una variable posteriormente

}

void volumen(){// procedimiento que no recibe parametros y hara su ejecucion y pasos aqui mismo

    float l;
    printf("\n\n\t\t[ VOLUMEN DE UN CUBO ]\n\n");
    printf("Ingresa Lado del cubo : ");
    scanf("%f",&l);//guardamos l
    
    l = l*l*l;// multiplicamos l 3 veces para hallar el volumen egun la formula

    printf("\nEl volumen del cubo es %.2f\n\n",l);//imprimimos

}

int main(){

    int opc;//opciones del menu
    float b,h,areaR,areaT;//variables para la resolucion


    do{//hacemos esto hasta que opcion sea igual a 3
        menu();
        scanf("%i",&opc);//guardamos
        switch (opc)
        {
        case 1:
            printf("\n\n\t\t[ AREA DE RECTANGULO ]\n\n");//imprimimos
            printf("\nIngresa la base : ");//pedimmos la base
            scanf("%f",&b);
            printf("Ingresa la Altura : ");//pedimos la altura
            scanf("%f",&h);
            areaR = areaRectangulo(b,h);//guardamos el resultado de la funcion en areaR
            printf("\nEl Area del rectangulo es %2.f\n",areaR);//imprimimos
            break;
        
        case 2:
            printf("\n\n\t\t[ AREA DE TRIANGULO ]\n\n");
            printf("\nIngresa la base : ");//imprimimos, pedimos la base
            scanf("%f",&b);
            printf("Ingresa la Altura : ");//pedimos la altura
            scanf("%f",&h);
            areaT = areaRectangulo(b,h) /2;//calculamos el area, recibiendo el resultado y diviendoloo entre 2
            printf("\nEl area del triangulo es %2.f\n",areaT);//imprimnimos
            break;

        case 3:
            volumen();//mandamos a llamar al procedimiento
            break;

        default:
            printf("Ingrese una opcion correcta..\n");//nos advertira sobre una posible mala entrada
            break;
        }



    }while(opc != 3);//repetira hasta que opcion sea 3.



    return 0;//retorna 0
}