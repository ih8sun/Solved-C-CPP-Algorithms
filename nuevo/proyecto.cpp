#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

#include <cstdlib>
#include <string>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

//PROTOTIPO DE LAS FUNCIONES
void cambio(char a[]);
void CursorOn(bool visible, DWORD size);
void CursorOff();
void gotoxy(int x, int y);
void dibujarCuadro(int x1, int y1, int x2, int y2);
void limpia();
void menu();
//void comprar();
void login();
void leerPasw(char frase[]);

//CLASE CLIENTE: SE CREA LA CLASE CLIENTE, Y DEFINIMOS LOS ATRIBUTOS Y MÉTODOS
class Persona
{
public:
    char nombre[35];
    char numCuenta[15];

public:
    void crear();
    void leer();
    void actualizar();
    void eliminar();
};

//CLASE DERIVADA CLIENTE, HEREDA TODOS LOS ATRIBUTOS DE LA CLASE PERSONA
class Cliente : public Persona
{
public:
    void crear();
    void leer();
    void actualizar();
    void eliminar();
};
class Cosmeticos
{
private:
    string nombre;
    double precio;

public:
    Cosmeticos(string, double); //constructor
    void setNombre(string nuevoNombre)
    {
        nombre = nuevoNombre;
    };

    string getNombre()
    {
        return nombre;
    };

    void setPrecio(double nuevoPrecio)
    {
        precio = nuevoPrecio;
    };

    double getPrecio()
    {
        return precio;
    };

    virtual void comprar();

    void mostrarProductos();

    Costmeticos(string miNombre = " ", double miPrecio = 0.00)
    {
        setNombre(miNombre);
        setPrecio(miPrecio);
    }
};
class ProdHigiene : public Cosmeticos
{
public:
    string marca;

public:
    void setMarca(string nuevaMarca)
    {
        marca = nuevaMarca;
    };

    string getMarca()
    {
        return marca;
    };
    void mostrarProductos();
    //polimorfismo
    void comprar();
    ProdHigiene(string miNombre = " ", double miPrecio = 0.00, string mimarca = " ") : Cosmeticos(miNombre, miPrecio)
    {
        setMarca(mimarca);
    }
};
/*	void ProdHigiene::compra(){
				Cosmeticos::compra();
				cout << " Ingreso de la persona a la tienda" << endl;
					
	}*/
//Cree esta clase para mostrar el titulo
class Titulo
{
    char nombre[40];

public:
    Titulo()
    {
        strcpy(nombre, "     T I E N D A  D E  C O S M E T I C O S       ");
    }
    friend void mostrarTitulo(Titulo);
};

int main()
{
    //	ProdHigiene prod1("xxx", 500.00, "yyy");

    //diseño del cuadro en pantalla
    system("mode con: cols=80 lines=25");
    Titulo Ti;
    system("COLOR 70");
    dibujarCuadro(1, 1, 78, 24); //Cuadro grande
    dibujarCuadro(2, 2, 77, 4);  //Cuadro titulo
    mostrarTitulo(Ti);
    login();

    return 0;
}
void mostrarTitulo(Titulo T)
{
    gotoxy(16, 3);
    printf(T.nombre);
}

void menu()
{
    Cliente Cl; //hacer instancia de la clase cliente
    ProdHigiene ph;
    ProdHigiene mostrarP;
    char op, op2;
    limpia();
    CursorOn(1, 10);
    do
    {
        gotoxy(4, 6);
        printf("CLIENTES");
        gotoxy(4, 9);
        printf("MENU PRINCIPAL");
        gotoxy(4, 11);
        printf("(1) Registro de clientes");
        gotoxy(4, 13);
        printf("(2) Mostrar productos ");
        gotoxy(4, 15);
        printf("(3) Hacer pedido ");
        gotoxy(4, 17);
        printf("(4) Cerrar");
        gotoxy(4, 18);
        printf("Ingrese opcion: ");
        scanf("%s", &op);

        if (op != '1' && op != '2' && op != '3' && op != '4')
        {
            gotoxy(4, 22);
            printf("error...ingrese de nuevo");
            CursorOff();
            getch();
            //	gotoxy(4,22); printf("                                                                       ");
            //	gotoxy(4,18); printf("                                                                       ");
            CursorOn(1, 10);
        }

    } while (op != '1' && op != '2' && op != '2');
    if (op == '1')
    {
        limpia();
        do
        {
            gotoxy(4, 6);
            cout << "Registro de clientes";
            gotoxy(4, 8);
            printf("1. crear");
            gotoxy(4, 10);
            printf("2. leer");
            gotoxy(4, 12);
            printf("3. Actualizar");
            gotoxy(4, 14);
            printf("4. Eliminar");
            gotoxy(4, 16);
            printf("5. Volver");
            gotoxy(4, 20);
            printf("Ingrese opcion: ");
            scanf("%s", &op2);

            if (op2 != '1' && op2 != '2' && op2 != '3' && op2 != '4' && op2 != '5')
            {
                gotoxy(4, 22);
                printf("opcion no valida intente de nuevo");
                CursorOff();
                getch();
                gotoxy(4, 22);
                printf("          ");
                gotoxy(4, 20);
                printf("            ");
                CursorOn(1, 10);
            }

        } while (op2 != '1' && op2 != '2' && op2 != '3' && op2 != '4' && op2 != '5');

        if (op2 == '1')
            Cl.crear();
        if (op2 == '2')
            Cl.leer();
        if (op2 == '3')
            Cl.actualizar();
        if (op2 == '4')
            Cl.eliminar();
        if (op2 == '5')
            menu();
    }

    if (op == '2')
    {
        limpia();
        do
        {

            gotoxy(4, 6);
            cout << "los productos en marcas disponible son:";
            gotoxy(4, 8);
            printf("1. L oreal");
            gotoxy(4, 10);
            printf("2. chinique");
            gotoxy(4, 12);
            printf("3. revlon");
            gotoxy(4, 12);
            printf("ingrese su opcion");
            scanf("%s", &op2);

            //gotoxy(4,20); printf("si usted escoge productos de la marca L oreal ");

        } while (op2 != '1' && op2 != '2' && op2 != '3');

        if (op2 == '1')
            mostrarP.mostrarProductos();
        if (op2 == '2')
            mostrarP.mostrarProductos();
        if (op2 == '3')
            mostrarP.mostrarProductos();
    }
    else
    {
        gotoxy(4, 6);
        cout << "intente nuevamente....";
        return menu();
    }

    /*	if(op2!='1' && op2!='2'){
				gotoxy(4,22); printf("esta opcion no es validad..intente de nuevo");
				CursorOff();
				getch();
				gotoxy(4,22); printf("        ");
				gotoxy(34,13); printf("       ");
				CursorOn(1,10);	
			}*/

    if (op == '3')
    {
        limpia();
        do
        {
            gotoxy(4, 6);
            printf("hacer pedido");
            gotoxy(4, 8);
            printf("1. Comprar");
            gotoxy(4, 10);
            printf("2. Volver");

            gotoxy(37, 13);
            printf("Ingrese opcion: ");
            scanf("%s", &op2);

            if (op2 != '1' && op2 != '2')
            {
                gotoxy(4, 22);
                printf("esta opcion no es validad..intente de nuevo");
                CursorOff();
                getch();
                gotoxy(4, 22);
                printf("        ");
                gotoxy(34, 13);
                printf("       ");
                CursorOn(1, 10);
            }

        } while (op2 != '1' && op2 != '2');

        if (op2 == '1')
            ph.comprar();
        if (op2 == '2')
            menu();
    }
    if (op == '2')
        exit(0);
}

//llamada a los metodos de la clase cliente
void Cliente::crear()
{
    FILE *pa, *pa2;
    char r;
    Cliente nuevo, lista[50];
    limpia();
    //creacion de archivos binarios y de texto
    /*if (((pa = fopen("Archivo Binario","a+b"))==NULL) || ((pa2 = fopen("Archivo Datos","a+b"))==NULL)) { 
		printf("No se puede abrir el archivo.\n");
		exit (0);
	}*/
    int encontro = 1, i, ultimo, res;

    rewind(pa);
    i = 0;
    while (!feof(pa))
    {
        if (fread(&nuevo, sizeof(Cliente), 1, pa))
        {
            lista[i] = nuevo;
            i++;
        }
    }
    fflush(stdin);
    gotoxy(4, 8);
    printf("Crear cliente");
    gotoxy(4, 10);
    printf("ingrese su nombre:  ");
    gets(nuevo.nombre);

    gotoxy(4, 12);
    printf("Ingrese su NumCuenta:                  ");
    res = i;

    do
    {
        gotoxy(26, 12);
        gets(nuevo.numCuenta);
        ultimo = res - 1;
        i = 0;
        encontro = 1;
        while (i <= ultimo && encontro)
        {
            if (strcmp(lista[i].numCuenta, nuevo.numCuenta) == 0)
                encontro = 0;
            else
                i++;
        }

        if (i <= ultimo)
        {
            gotoxy(26, 12);
            printf("                              ");
            gotoxy(4, 22);
            printf("Esta cuenta ya no es valida. Ingrese nuevamente.");
        }
        else
        {
            gotoxy(4, 22);
            printf("                                               ");
        }
    } while (i <= ultimo);

    CursorOff();
    gotoxy(4, 22);
    printf("¨Desea Registrar este Cliente? : ");
    r = getch();

    while (r != 'S' && r != 's' && r != 'N' && r != 'n')
        ;

    if (r == 's' || r == 'S')
    {
        fwrite(&nuevo, sizeof(Cliente), 1, pa);
        fprintf(pa2, "%s %s %s %s\n", nuevo.nombre, nuevo.numCuenta);
        gotoxy(4, 22);
        printf("                                              ");
        gotoxy(4, 22);
        printf("registro con exito");
    }

    else
    {
        gotoxy(4, 22);
        printf("lo sentimos, intente de nuevo");
    }
    fclose(pa);
    fclose(pa2);
    CursorOff();
    getch();
    limpia();
    menu();
}

// modificar los datos
void Cliente::actualizar()
{
    Cliente nuevo, lista[50];
    char NumCuenta[15];
    int encontro = 1, linea, i, ultimo;
    char r;
    FILE *pa, *pa2;
    limpia();

    /*	if (((pa = fopen("Archivo Binario","a+b"))==NULL))        
	{ 
		printf("No se puede abrir el archivo.\n");
		exit (0);
	}*/
    rewind(pa);
    i = 0;

    while (!feof(pa))
    {
        if (fread(&nuevo, sizeof(Cliente), 1, pa))
        {
            lista[i] = nuevo;
            i++;
        }
    }

    fclose(pa);

    gotoxy(4, 8);
    printf("Actualizar");
    gotoxy(4, 10);
    fflush(stdin);
    printf("Ingrese su NumCuenta: ");
    gets(numCuenta);
    ultimo = i - 1;
    i = 0;

    while (i <= ultimo && encontro)
    {
        if (strcmp(lista[i].numCuenta, numCuenta) == 0)
            encontro = 0;
        else
            i++;
    }

    if (i <= ultimo)
    {
        do
        {
            CursorOn(1, 10);
            limpia();
            gotoxy(4, 8);
            printf("ACTUALIZAR DATOS");
            gotoxy(4, 10);
            printf("1. Nombre:                 %s\n", lista[i].nombre);
            gotoxy(4, 12);
            printf("2. su NumCuenta:                    %s\n", lista[i].numCuenta);

            gotoxy(4, 20);
            printf("Que desea modificar? : ");

            do
            {
                gotoxy(34, 20);
                scanf("%d", &linea);
                if (linea < 1 || linea > 2)
                {
                    gotoxy(34, 20);
                    printf("          ");
                    gotoxy(4, 22);
                    printf("Opcion no valida. Ingrese nuevamente..");
                }
            } while (linea < 1 || linea > 4);
            gotoxy(4, 22);
            printf("                                            ");

            fflush(stdin);

            switch (linea)
            {
            case 1:
                gotoxy(4, 10);
                printf("                                                       ");
                gotoxy(4, 22);
                printf("                                           ");
                gotoxy(4, 10);
                printf("1. Nombre:                 ");
                gets(lista[i].nombre);
                break;
            case 2:
                gotoxy(4, 12);
                printf("                                            ");
                gotoxy(4, 22);
                printf("                                           ");
                gotoxy(4, 12);
                printf("2. numCuenta:                    ");
                gets(lista[i].numCuenta);
                break;
            }
            gotoxy(4, 20);
            printf("Actualizacion con exito.                  ");

            do
            {
                CursorOff();
                gotoxy(4, 22);
                printf("¨Desea hacer una nueva actualizacion");
                r = getch();
            } while (r != 'S' && r != 's' && r != 'N' && r != 'n');

        } while (r != 'n' && r != 'N');

        /* if (((pa = fopen("Archivo Binario", "wb"))== NULL) || ((pa2 = fopen("Archivo Datos", "wb"))== NULL)) 
	      { printf("No se puede abrir el archivo.\n");
		return;
	      }*/
        i = 0;

        while (i <= ultimo)
        {
            fwrite(&lista[i], sizeof(Cliente), 1, pa);
            fprintf(pa2, "%s  %s\n", lista[i].nombre, lista[i].numCuenta);
            i++;
        }

        fclose(pa);
        fclose(pa2);
        gotoxy(4, 20);
        printf("                    ");
        gotoxy(4, 22);
        printf(".....                   ");
        CursorOff();
        getch();
        limpia();
        menu();
    }

    else
    {
        fclose(pa);
        gotoxy(4, 22);
        printf("no esta en el registro... ");
        CursorOff();
        getch();
        limpia();
        menu();
    }
}

//metodo para eliminar un cliente
void Cliente::eliminar()
{
    Cliente nuevo, lista[50];
    char dni[15];
    char r;
    int encontro = 1, linea, i, ultimo;
    FILE *pa, *pa2;
    limpia();

    /*if ((pa = fopen("Archivo Binario", "a+b"))== NULL){ 
		printf("No se puede abrir el archivo.\n");
		return;
    }*/

    rewind(pa);
    i = 0;
    while (!feof(pa))
    {
        if (fread(&nuevo, sizeof(Cliente), 1, pa))
        {
            lista[i] = nuevo;
            i++;
        }
    }
    fclose(pa);

    gotoxy(4, 8);
    printf("Elimando datos cliente");
    gotoxy(4, 10);
    fflush(stdin);
    printf("Ingrese NunCuenta: ");
    gets(numCuenta);
    ultimo = i - 1;
    i = 0;

    while (i <= ultimo && encontro)
    {
        if (strcmp(lista[i].numCuenta, numCuenta) == 0)
            encontro = 0;
        else
            i++;
    }

    if (i <= ultimo)
    {
        limpia();
        gotoxy(4, 8);
        printf("ELIMINAR DATOS");
        gotoxy(4, 10);
        printf("1. Nombre:                 %s\n", lista[i].nombre);
        gotoxy(4, 12);
        printf("2. NumCuenta:                    %s\n", lista[i].numCuenta);

        do
        {
            CursorOff();
            gotoxy(4, 22);
            printf("¨Seguro que desea eliminar cliente ");
            r = getch();
        } while (r != 'S' && r != 's' && r != 'N' && r != 'n');

        if (r == 's' || r == 'S')
        {
            while (i < ultimo)
            {
                lista[i] = lista[i + 1];
                i++;
            }

            ultimo = i - 1;

            if (((pa = fopen("Archivo Binario", "wb")) == NULL) || ((pa2 = fopen("Archivo Datos", "wb")) == NULL))
            {
                printf("No se puede abrir el archivo.\n");
                return;
            }

            i = 0;

            while (i <= ultimo)
            {
                fwrite(&lista[i], sizeof(Cliente), 1, pa);
                fprintf(pa2, "%s %s\n", lista[i].nombre, lista[i].numCuenta);
                i++;
            }
            fclose(pa);
            fclose(pa2);
            gotoxy(4, 22);
            printf("                                        ");
            gotoxy(4, 22);
            printf("Cliente Eliminado con exito. Presione una tecla para volver..");
            CursorOff();
            getch();
            limpia();
            menu();
        }

        else
        {
            gotoxy(4, 22);
            printf("                                    ");
            gotoxy(4, 22);
            printf("Lo sentimos intente de nuevo. Presione una tecla para volver..");
            CursorOff();
            getch();
            limpia();
            menu();
        }
    }

    else
    {
        gotoxy(4, 22);
        printf("Este cliente no esta registrado..... Presione una tecla para volver..");
        CursorOff();
        getch();
        limpia();
        menu();
    }
}

void Cliente::leer()
{
    Cliente nuevo, lista[50];
    char dni[15];
    int encontro = 1, linea, i, ultimo;
    FILE *pa;
    limpia();
    /*if ((pa = fopen("Archivo Binario", "a+b"))== NULL)
      { printf("No se puede abrir el archivo.\n");
	return;
      }*/
    rewind(pa);
    i = 0;
    while (!feof(pa))
    {
        if (fread(&nuevo, sizeof(Cliente), 1, pa))
        {
            lista[i] = nuevo;
            i++;
        }
    }
    fclose(pa);

    //proceso de busqueda de la informaci¢n
    gotoxy(4, 8);
    printf("leyendo datos");
    gotoxy(4, 10);
    fflush(stdin);
    printf("Ingrese NumCuenta: ");
    gets(numCuenta);
    ultimo = i - 1;
    i = 0;
    while (i <= ultimo && encontro)
    {
        if (strcmp(lista[i].numCuenta, numCuenta) == 0)
            encontro = 0;
        else
            i++;
    }
    if (i <= ultimo)
    {
        limpia();
        gotoxy(4, 8);
        printf("CONSULTA DE CLIENTES");
        gotoxy(4, 10);
        printf("1. Nombre:                 %s\n", lista[i].nombre);
        gotoxy(4, 12);
        printf("2. NumCuenta:                    %s\n", lista[i].numCuenta);

        gotoxy(4, 22);
        printf("Presione una tecla para volver...                   ");
        CursorOff();
        getch();
        limpia();
        menu();
    }
    else
    {
        gotoxy(4, 22);
        printf("Usuario NO registrado. Presione una tecla para volver... ");
        CursorOff();
        getch();
        limpia();
        menu();
    }
}

ProdHigiene::mostrarProductos()
{

    //ProdHigiene mostrarP;
    /*char marc1[]="chanel", marc2[]="l oreal";
		string nom1="labial", nom2="desmaquillante";
		double pr1=500.00, pr2=350.40;*/
    char res = 'S';
    int opcion;
    string Nombre;

    while ((res == 'S') || (res == 's'))
    {
        gotoxy(4, 8);
        cout << "bienvenido a continuacion se mostrará marcas de los productos";
        gotoxy(4, 10);
        cout << " 1. marca chaenl\n";
        gotoxy(4, 12);
        cout << " 2. marca l oreal \n";
        gotoxy(4, 14);
        cout << " 3. marca revlon\n";
        gotoxy(4, 16);
        cout << " Ingrese su opcion: ";
        gotoxy(4, 17);
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            gotoxy(4, 19);
            cout << " bienvenido luego se mostrara los prductos" << endl;
            gotoxy(4, 20);
            cout << "\n Su Nombre: ";
            gotoxy(4, 21);
            cin >> Nombre;
            gotoxy(4, 22);
            cout << "\nBienvenido : "
                 << "   " << Nombre << " los productos son los siguientes";
            gotoxy(4, 23);
            cout << "\n  A: ";
            gotoxy(4, 24);
            cout << "\n  C: ";
            gotoxy(4, 25);
            cout << "\n  B: ";
        }
        break;
        case 2:
        {
            gotoxy(4, 19);
            cout << " bienvenido luego se mostrara los prductos" << endl;
            gotoxy(4, 20);
            cout << "\n Su Nombre: ";
            gotoxy(4, 21);
            cin >> Nombre;
            gotoxy(4, 22);
            cout << "\nBienvenido : "
                 << "   " << Nombre << " los productos son los siguientes";
            gotoxy(4, 23);
            cout << "\n  d: ";
            gotoxy(4, 24);
            cout << "\n  F: ";
            gotoxy(4, 25);
            cout << "\n  G: ";
        }
        break;
        case 3:
        {
            gotoxy(4, 19);
            cout << " bienvenido luego se mostrara los prductos" << endl;
            gotoxy(4, 20);
            cout << "\n Su Nombre: ";
            gotoxy(4, 21);
            cin >> Nombre;
            gotoxy(4, 22);
            cout << "\nBienvenido : "
                 << "   " << Nombre << " los productos son los siguientes";
            gotoxy(4, 23);
            cout << "\n  H: ";
            gotoxy(4, 24);
            cout << "\n  I: ";
            gotoxy(4, 25);
            cout << "\n  J: ";
        }
        break;
        }

        void ProdHigiene::comprar()
        {
            limpia();
            gotoxy(4, 8);
            printf("Usted va realizar compra >> ");
            char res = 'S', confirmacion;
            int opcion, cant;
            char op2, op3;
            float total = 0, total2 = 0, cambio, tc, sumacred, desc = 0;

            float pago = 0;
            FILE *pa;
            //ProdHigiene nuevo, lista[50];
            char marca[15];
            while ((res == 'S') || (res == 's'))
            {
                gotoxy(4, 11);
                cout << "Productos disponibles por marca";
                gotoxy(4, 8);
                cout << "   Marca Chanel ";
                gotoxy(4, 9);
                printf("1) Labial                          $ 350.50  ");
                gotoxy(4, 10);
                printf("2) Desmaquillante                   $ 10.00 ");
                gotoxy(4, 11);
                printf("   L´oreal                            ");
                gotoxy(4, 12);
                printf("3) Rubor                         $ 205.8");
                gotoxy(4, 13);
                printf("4) Polvos                       $ 100.40");
                gotoxy(4, 14);
                printf("  Chinique                     	");
                gotoxy(4, 15);
                printf("5) queita esmete                  $ 200.00");
                gotoxy(4, 16);
                printf("6) cepillo                      $ 150.00");
                gotoxy(47, 18);
                printf("Ingrese opcion del menu: ");
                cin >> opcion;

                fflush(stdin);
                switch (opcion)
                {
                case 1:

                    gotoxy(47, 13);
                    printf("Ingrese cantidad: ");
                    //scanf("%f",&cant);
                    cin >> cant;
                    tc = cant * 350.50;
                    total += tc;
                    break;

                case 2:
                    gotoxy(47, 13);
                    printf("Ingrese cantidad: ");
                    scanf("%f", &cant);
                    tc = cant * 1.25;
                    total += tc;
                    break;

                case 3:
                    gotoxy(47, 13);
                    printf("Ingrese cantidad: ");
                    scanf("%f", &cant);
                    tc = cant * 1.50;
                    total += tc;
                    break;

                case 4:
                    gotoxy(47, 13);
                    printf("Ingrese cantidad: ");
                    scanf("%f", &cant);
                    tc = cant * 1.75;
                    total += tc;
                    break;

                case 5:
                    gotoxy(47, 13);
                    printf("Ingrese cantidad: ");
                    scanf("%f", &cant);
                    tc = cant * 1.75;
                    total += tc;
                    break;

                case 6:
                    gotoxy(47, 13);
                    printf("Ingrese cantidad: ");
                    scanf("%f", &cant);
                    tc = cant * 0.50;
                    total += tc;
                    break;
                }

                do
                {
                    CursorOff();
                    gotoxy(47, 19);
                    printf("¨Desea Seguir Pidiendo?");
                    gotoxy(47, 21);
                    printf("Si[s] / No[n]: ");
                    op3 = getch();
                } while (op3 != 'S' && op3 != 's' && op3 != 'N' && op3 != 'n');

                if (op3 == 'S' || op3 == 's')
                {
                    gotoxy(47, 11);
                    printf("                               ");
                    gotoxy(47, 19);
                    printf("                               ");
                    gotoxy(47, 21);
                    printf("                               ");
                    CursorOn(1, 10);
                }
            }
            while (op3 != 'n' && op3 != 'N')
                ;

            gotoxy(47, 11);
            printf("                               ");
            gotoxy(47, 13);
            printf("                               ");
            gotoxy(47, 19);
            printf("                               ");
            gotoxy(47, 21);
            printf("                               ");
            gotoxy(47, 11);
            printf("Valor del Pedido:  $ %6.2f", total);

            do
            {
                CursorOff();
                gotoxy(47, 17);
                printf("Pagar con:");
                gotoxy(47, 19);
                printf("1.Efectivo");

                gotoxy(47, 21);
                printf("<2> Tarjeta");
                op2 = getch();
            } while (op2 != '1' && op2 != '2');

            if (op2 == '1')
            {
                CursorOn(1, 10);
                gotoxy(47, 17);
                printf("                         ");
                gotoxy(47, 19);
                printf("                         ");
                gotoxy(47, 21);
                printf("                         ");
                gotoxy(47, 19);
                printf("Ingresar valor en efectivo:");
                gotoxy(47, 21);
                printf("$  ");
                scanf("%f", &pago);

                if (total > pago)
                {
                    gotoxy(4, 23);
                    printf("Dinero insuficiente para realizar el pedido..");
                    CursorOff();
                    getch();
                }

                else
                {
                    cambio = pago - total;

                    fflush(stdin);
                    limpia();

                    dibujarCuadro(13, 8, 66, 19);
                    gotoxy(20, 10);
                    printf("              R E C I B O  ");
                    gotoxy(20, 14);
                    printf("Valor del Pedido:   $ %6.2f", total);
                    gotoxy(20, 15);
                    printf("Descuento:          $ %6.2f", desc);
                    gotoxy(20, 16);
                    printf("Su cambio es:       $ %6.2f", cambio);
                }
            }

            if (op2 == '2')
            {
                CursorOn(1, 10);
                gotoxy(47, 17);
                printf("                         ");
                gotoxy(47, 19);
                printf("                         ");
                gotoxy(47, 21);
                printf("                         ");
                gotoxy(47, 19);
                printf("Ingresar valor de la tarjeta:");
                gotoxy(47, 21);
                printf("$  ");
                scanf("%f", &pago);

                if (total > pago)
                {
                    gotoxy(4, 23);
                    printf("Dinero insuficiente para realizar el pedido");
                    CursorOff();
                    getch();
                }

                else
                {
                    desc = total * 0.05;
                    cambio = pago - (total - desc);

                    fflush(stdin);
                    limpia();

                    dibujarCuadro(13, 8, 66, 19);
                    gotoxy(20, 10);
                    printf("              R E C I B O  ");
                    //	gotoxy(20,12);printf("DNI:                %s",lista[i].dni);

                    gotoxy(20, 14);
                    printf("Valor del Pedido:   $ %6.2f", total);
                    gotoxy(20, 15);
                    printf("Descuento:          $ %6.2f", desc);
                    gotoxy(20, 16);
                    printf("Total a pagar:      $ %6.2f", total - desc);
                    gotoxy(20, 17);
                    printf("Su cambio es:       $ %6.2f", cambio);
                }

                gotoxy(4, 23);
                printf("                                                           ");
                gotoxy(4, 23);
                printf("Presione una tecla para volver... ");
                CursorOff();
                getch();
                limpia();
                menu();
            }
            else
            {
                CursorOff();
                gotoxy(4, 20);
                printf("Cliente NO registrado en el sistema.");
                gotoxy(4, 22);
                printf("Presione una tecla para volver... ");
                CursorOff;
                getch();
                limpia();
                menu();
            }
        }

        //FUNCION QUE MUESTRA VENTANA DE LOGIN , Y PERMITE INGRESAR USUARIO Y CONTRASEÑA
        void login()
        {
            CursorOn(1, 10);
            char user[15];
            char contra[20];
            //char user[] = "Admin"; //Modificar colocando el usuario que deseean
            //	char contra[] = "12345"; //Modificar contraseña que deseen
            char user2[20], contra2[20];
            int x = 600;
            int f = 41;

            gotoxy(35, 6);
            printf("LOGIN");
            dibujarCuadro(18, 9, 60, 15);
            gotoxy(23, 13);
            printf("Clave:   ");
            gotoxy(23, 11);
            printf("Usuario: ");
            fgets(user, 15, stdin);
            cambio(user2);

            gotoxy(23, 13);
            printf("Clave:   ");
            leerPasw(contra2);

            CursorOff();

            for (int i = 0; i < 3; i++)
            {
                gotoxy(33, 19);
                printf("Cargando");
                gotoxy(f, 19);
                printf(".");
                f += 1;
                Sleep(x);
            }

            f = 51;

            if ((strcmp(user2, user)) == 0 && (strcmp(contra2, contra)) == 0)
            {
                gotoxy(30, 19);
                printf("                                     ");
                for (int i = 0; i < 3; i++)
                {
                    gotoxy(30, 19);
                    printf("Accediendo al Sistema");
                    gotoxy(f, 19);
                    printf(".");
                    f += 1;
                    Sleep(x);
                }
                limpia();
                menu();
            }

            else
            {
                gotoxy(35, 19);
                printf("                                     ");
                gotoxy(30, 19);
                printf("Datos incorrectos");
                gotoxy(18, 20);
                printf("Presione una tecla para volver a ingresar..");
                getch();
                limpia();
                login();
            }
        }

        //FUNCION LEER CONTRASEÑA: proceso que permite mostrar asteriscos en la contraseña
        void leerPasw(char frase[])
        {
            int i = 0;
            cout.flush();
            int aux = 0;

            do
            {
                frase[i] = (unsigned char)getch();

                if (frase[i] != 8) // no es retroceso
                {
                    cout << '*'; // muestra por pantalla
                    i++;

                    if (frase[i - 1] == 13)
                    {
                        printf("\b \b");
                    }
                }

                else if (i > 0) // es retroceso y hay caracteres
                {
                    cout << (char)8 << (char)32 << (char)8;
                    i--; //el caracter a borrar e el backspace
                }

                cout.flush();

            } while (frase[i - 1] != 13); // si presiona ENTER

            frase[i - 1] = 0;
        }

        //FUNCION QUE DIBUJA UN CUADRO, SE PASAN LOS VALORES DONDE QUEREMOS QUE SE FORME EL CUADRO, EJEMPLO dibujarCuadro(1,1,78,24);
        void dibujarCuadro(int x1, int y1, int x2, int y2)
        {

            int i;
            for (i = x1; i < x2; i++)
            {
                gotoxy(i, y1);
                printf("Ä"); //linea horizontal superior
                gotoxy(i, y2);
                printf("Ä"); //linea horizontal inferior
            }

            for (i = y1; i < y2; i++)
            {
                gotoxy(x1, i);
                printf("³"); //linea vertical izquierda
                gotoxy(x2, i);
                printf("³"); //linea vertical derecha
            }
            gotoxy(x1, y1);
            printf("Ú");
            gotoxy(x1, y2);
            printf("À");
            gotoxy(x2, y1);
            printf("¿");
            gotoxy(x2, y2);
            printf("Ù");
        }

        //FUNCIÓN CAMBIO
        void cambio(char a[])
        {
            int aux;
            aux = strlen(a);
            a[aux - 1] = '\0';
        }

        //FUNCION QUE OCULTA EL CURSOR
        void CursorOff()
        {
            CONSOLE_CURSOR_INFO cursor = {1, FALSE};
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
        }

        //FUNCION PARA QUE APAREZCA EL CURSOR
        void CursorOn(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
        {
            if (size == 0)
            {
                size = 20;
            }
            CONSOLE_CURSOR_INFO lpCursor;
            lpCursor.bVisible = visible;
            lpCursor.dwSize = size;
            SetConsoleCursorInfo(console, &lpCursor);
        }

        //FUNCION GOTOXY, SIRVE PARA POSICIONAR LOS MENSAJES EN UNA DETERMINADA ZONA DE LA PANTALLA, SE INGRESA COLUMNA Y FILA DE LA PANTALLA, EJEMPLO: gotoxy(4,10); printf("HOla"); ESTE MENSAJE SE IMPRIMIRÁ EN LA POSICIÓN COLUMNA 4, FILA 10
        void gotoxy(int x, int y)
        {
            HANDLE hcon;
            hcon = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD dwPos;
            dwPos.X = x;
            dwPos.Y = y;
            SetConsoleCursorPosition(hcon, dwPos);
        }

        //FUNCION QUE LIMPIA EL AREA DE LA PANTALLA
        void limpia()
        {
            int i, j;
            for (i = 8; i <= 23; i++)
            {
                for (j = 4; j <= 75; j++)
                {
                    gotoxy(j, i);
                    printf(" ");
                }
            }
        }
