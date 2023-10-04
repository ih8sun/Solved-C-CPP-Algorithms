#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#define tam 100
using namespace std;

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void redefinirCMD(){
    system("mode 130,30");   //Set mode to ensure window does not exceed buffer size
    SMALL_RECT WinRect = {0, 0, 130, 30};   //New dimensions for window in 8x12 pixel chars
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
}

//MENU Y TITULOS
int menu(){
    int opc;
    string x = "[ S I S T E M A - D E - C O M E R C I A L ] ";
    system("cls");

    cout<<"\n\n\t\t"<<x<<endl<<endl;

    cout<<"[1]. NUEVO CLIENTE\n";
    cout<<"[2]. BUSCAR CLIENTE\n";
    cout<<"[3]. NUEVOS VENDEDOR\n";
    cout<<"[4]. NUEVOS PRODUCTOS\n";
    cout<<"[5]. VENTA\n";
    cout<<"[6]. LISTA DE CLIENTE\n";
    cout<<"[7]. LISTA DE VENDEDORES\n";
    cout<<"[8]. LISTA DE PRODUCTOS\n";
    cout<<"[9]. LISTA DE VENTAS\n";
    cout<<"[10]. SALIR\n";
    cout<<"\n[?]. Ingresa una opcion : ";
    fflush(stdin);
    cin>>opc;

    return opc;
}

void tituloCliente(){
    system("cls");
    gotoxy(40,2);
    cout<<"[ DESPLEGANDO LISTADO CLIENTE ]";

    gotoxy(0,5);
    cout<<"Codigo";

    gotoxy(20,5);
    cout<<"Nombre";

    gotoxy(39,5);
    cout<<"Ruc";

    gotoxy(53,5);
    cout<<"Telefono[1]";

    gotoxy(73,5);
    cout<<"Telefono[2]";

    gotoxy(92,5);
    cout<<"Direccion";


}
void tituloVendedor(){

    system("cls");
    gotoxy(45,2);
    cout<<"[ DESPLEGANDO LISTADO VENDEDOR ]";


    gotoxy(20,5);
    cout<<"Codigo";


    gotoxy(53,5);
    cout<<"Nombre";


    gotoxy(92,5);
    cout<<"Salario";


}

void tituloProducto(){
    system("cls");
    gotoxy(40,2);
    cout<<"[ DESPLEGANDO LISTADO CLIENTE ]";

    gotoxy(0,7);
    cout<<"Codigo";

    gotoxy(20,7);
    cout<<"Descripcion";

    gotoxy(49,7);
    cout<<"Tipo";

    gotoxy(67,7);
    cout<<"Precio";

    gotoxy(83,7);
    cout<<"Stock";

    gotoxy(102,7);
    cout<<"Total Ventas";
}
void tituloVendidos(){

    system("cls");
    gotoxy(40,2);
    cout<<"[ DESPLEGANDO LISTADO DE PRODUCTOS VENDIDOS ]";

    gotoxy(20,5);
    cout<<"Codigo Producto";


    gotoxy(53,5);
    cout<<"Codigo Cliente";


    gotoxy(92,5);
    cout<<"Codigo Vendedor";
}

//PROTOTIPOS
void cargarPrimerosDatos(string[],string[],string[],string[],string[],string[]);
void ingresarCliente(string[],string[],string[],string[],string[],string[],int &);
bool comprobarCyV(string [],string ,int );
void buscarCliente(string[],string[],string[],string[],string[],string[],int );
void cargarPrimerosDatosVendedor(string[],string[],float []);
void ingresarVendedor(string[],string[],float [],int &);
void ingresarProducto(string[],string[],string[],float[],int[],int[],int&);
void listarClientes(string [],string [],string [],string [],string [],string [],int );
void listarVendedor(string[],string[],float [],int );
void listarProducto(string[],string[],string[],float[],int[],int[],int);
int realizarV(int &,string[],string[],string[],  string[],string[],string[],
              int [], int [],int,int,int);
void listaVendidos(string [],string [], string [], int );
void mayorStock(string [],string [],int [],int );
int main() {

    redefinirCMD();
    int x;

    //Variables de clientes-------------------------------------------------------
    string codigoCliente[tam],nombreCliente[tam],ruc[tam],telefono1Cliente[tam],telefono2Cliente[tam];
    string direccionCliente[tam];
    int contCliente = 3;
    cargarPrimerosDatos(codigoCliente,nombreCliente,ruc,telefono1Cliente,telefono2Cliente,direccionCliente);


    //Variables de Vendedores-------------------------------------------------------
    string codigoVendedor[tam],nombreVendedor[tam];
    float salario[tam];
    int contVendedor = 10;
    cargarPrimerosDatosVendedor(codigoVendedor,nombreVendedor,salario);

    //Variables de Productos---------------------------------------------------------
    string codigoProducto[tam],descripcionProducto[tam],tipoProducto[tam];
    float precioProducto[tam];
    int ventaProducto[tam],stockProducto[tam];
    int tamProducto = 0;

    //!Variables de Menu-------------------------------------------------------
    bool salir = false;
    int opc;

    //!Variables De Venta-------------------------------------------------------
    string VentaCodCLiente[tam],VentaCodProducto[tam],ventaCodVendedor[tam];
    int ventaCompletada = 0;


    do{
        opc = menu();
        switch (opc) {
            case 1:
                system("cls");
                if(contCliente < 6) {
                    ingresarCliente(codigoCliente, nombreCliente, ruc, telefono1Cliente,
                                    telefono2Cliente, direccionCliente, contCliente);
                }else{
                    cout<<"\n\n\t\t[ AGENDA LLENA ]\n\n";
                    system("pause");
                }
                break;

            case 2:
                system("cls");
                buscarCliente(codigoCliente, nombreCliente, ruc, telefono1Cliente,
                              telefono2Cliente, direccionCliente, contCliente);
                break;
            case 3:
                system("cls");
                if(contVendedor < 13){
                    ingresarVendedor(codigoVendedor,nombreVendedor,salario,contVendedor);
                }else{
                    cout<<"\n\n\t\t[  LLENO ]\n\n";
                    system("pause");
                }

                break;
            case 4:
                system("cls");
                ingresarProducto(codigoProducto,descripcionProducto,
                                 tipoProducto,precioProducto,
                                 stockProducto,ventaProducto,tamProducto);
                break;

            case 5:
                x = realizarV(ventaCompletada,VentaCodCLiente, VentaCodProducto, ventaCodVendedor,codigoCliente,
                              codigoVendedor,codigoProducto,  ventaProducto,stockProducto,
                              contCliente, contVendedor, tamProducto);

                if(x == 1){
                    cout<<"[ NO SE CONCRETO LA VENTA ]\n\n";
                    system("pause");
                }

                break;
            case 6:
                system("cls");
                listarClientes(codigoCliente, nombreCliente, ruc, telefono1Cliente,
                               telefono2Cliente, direccionCliente, contCliente);
                break;
            case 7:
                system("cls");
                listarVendedor(codigoVendedor,nombreVendedor,salario,contVendedor);
                break;
            case 8:
                listarProducto(codigoProducto,descripcionProducto,
                               tipoProducto,precioProducto,
                               stockProducto,ventaProducto,tamProducto);
                break;
            case 9:
                listaVendidos(VentaCodCLiente,ventaCodVendedor,VentaCodProducto,ventaCompletada);
                break;
            case 10:
                salir = true;
                break;
        }

    }while(!salir);

    return 0;

}

void cargarPrimerosDatos(string codigo[],string nombre[],string ruc[],
                         string telefono1[],string telefono2[],string direccion[]){

    codigo[0] = "n00229008";
    nombre[0] = "Alex Santiago";
    ruc[0] = "123456789012";
    telefono1[0] = "924176880";
    telefono2[0] = "924176880";
    direccion[0] = "Av Rio Manu 150. Urb Villa Hermosa";

    codigo[1] = "n00229002";
    nombre[1] = "Fano Vargas";
    ruc[1] = "126456589112";
    telefono1[1] = "968574569";
    telefono2[1] = "968574569";
    direccion[1] = "Av Coloniales 112. Urb El Laburo";

    codigo[2] = "n00229010";
    nombre[2] = "Paolo Guerrero";
    ruc[2] = "126466585172";
    telefono1[2] = "921123215";
    telefono2[2] = "921123215";
    direccion[2] = "Av Miraflores 112. La Planicie";
}

void ingresarCliente(string codigo[],string nombre[],string ruc[],
                     string telefono1[],string telefono2[],string direccion[],int &i){

    bool correcto = false; //0.1.2
    string aux;
    cout<<"\n\n\t\t [ INGRESO DE NUEVO REGISTRO DE CLIENTE ]\n\n";

    cout<<"Ingresa codigo de nuevo cliente : ";
    fflush(stdin);
    getline(cin,aux);

    //VERDAD O FALSEDAD

    if(!comprobarCyV(codigo,aux,i)){
        codigo[i] = aux;
        cout<<"Ingresa nombre de nuevo cliente : ";
        fflush(stdin);
        getline(cin,nombre[i]);

        //RUC
        do{
            cout<<"Ingresa RUC de Trabajador [11]. : ";
            fflush(stdin);
            getline(cin,aux); //alex123456789

            if(aux.length() == 11){
                correcto = true;
                ruc[i] = aux;
            }else{
                correcto = false;
                cout<<"El ruc debe tener 11 digitos de longitud..\n";
            }
        }while(!correcto);

        //TELEFONO 1
        do{
            cout<<"Ingresa Telefono [9]. : ";
            fflush(stdin);
            getline(cin,aux);

            if(aux.length() == 9){
                telefono1[i] = aux;
                correcto = true;
            }else{
                correcto = false;
                cout<<"El telefono debe tener 9 digitos de longitud..\n";
            }

        }while(!correcto);

        //TELEFONO 2
        do{
            cout<<"Ingresa Telefono 2 [9]. : ";
            fflush(stdin);
            getline(cin,aux);

            if(aux.length() == 9){
                telefono2[i] = aux;
                correcto = true;
            }else{
                correcto = false;
                cout<<"El telefono 2 debe tener 9 digitos de longitud..\n";
            }
        }while(!correcto);

        cout<<"Ingresa Direccion de nuevo cliente : ";
        fflush(stdin);
        getline(cin,aux);

        direccion[i] = aux;

        i++; //MUY IMPORTANTE => i++ == i = i+1;
        // Esto de aqui es super importante
        //y va a incrementarse en uno la posicion actual de todos los vectores que hayamos utilizado
        //Ejemplo--> ruc[i] ==> pos == 3    E=> 1++ .... pos3 == 4.. ==> 5..;

        //Sin i++;
        // Ruc[i] ==> pos == 3.. pos == 3 .. pos == 3

        cout<<"\n[ CLIENTE REGISTRADO CORRECTAMENTE ]\n";
    }else{
        cout<<"\n\n\t\t[ YA HAY UN CLIENTE CON EL CODIGO -> "<<aux<<" ]\n";
    }

    cout<<endl;
    system("pause");
}

bool comprobarCyV(string codigo[],string aux,int max){

    for(int i = 0; i < max; i++){
        if(codigo[i].compare(aux)==0){
            return true;
        }
    }

    return false;
}

void buscarCliente(string codigo[],string nombre[],string ruc[],
                   string telefono1[],string telefono2[],string direccion[],int max){

    int i;
    string aux;
    bool encontrado = false;

    cout<<"\n\n\t\t[ BUSQUEDA DE ALGUN CLIENTE ]\n\n";
    cout<<"Ingresa codigo de cliente a buscar : ";
    fflush(stdin);
    getline(cin,aux);

    for(i = 0; i < max; i++){ //0 //1 //2 //3
        if(codigo[i].compare(aux)==0){
            cout<<"\n[ MOSTRANDO CLIENTES ]\n\n";
            cout<<"Codigo       :  "<<codigo[i]<<endl;
            cout<<"Nombre       :  "<<nombre[i]<<endl;
            cout<<"Ruc          :  "<<ruc[i]<<endl;
            cout<<"Telefono 1   :  "<<telefono1[i]<<endl;
            cout<<"Telefono 2   :  "<<telefono2[i]<<endl;
            cout<<"Direccion 2   :  "<<direccion[i]<<endl;
            encontrado = true;
            cout<<endl;
            break;
        }
    }

    if(!encontrado){ //encontrado == false
        cout<<"\n\n\t\t[ NO SE ENCONTRO ALGUN CLIENTE CON EL CODIGO -> "<<aux<<" ]\n\n";
    }

    system("pause");

}

void cargarPrimerosDatosVendedor(string codigoV[],string nombreV[],float salario[]){

    codigoV[0] = "C102059";
    nombreV[0] = "San Bernardo S.A.C";
    salario[0] = 1500;

    codigoV[1] = "C102028";
    nombreV[1] = "San Fernando S.A.C";
    salario[1] = 3500;

    codigoV[2] = "C102030";
    nombreV[2] = "La Granja S.A.C";
    salario[2] = 1990;

    codigoV[3] = "C102033";
    nombreV[3] = "Josefino S.A.C";
    salario[3] = 1200;

    codigoV[4] = "C102033";
    nombreV[4] = "Nuevo Amanecer";
    salario[4] = 2500;

    codigoV[5] = "C102135";
    nombreV[5] = "Nestle P.E.R";
    salario[5] = 8540;

    codigoV[6] = "C102026";
    nombreV[6] = "Sinaloa Pedidos";
    salario[6] = 1801;

    codigoV[7] = "C102037";
    nombreV[7] = "Coca Cola Company";
    salario[7] = 3000;

    codigoV[8] = "C102038";
    nombreV[8] = "M & M EE.UU";
    salario[8] = 2460;

    codigoV[9] = "C102085";
    nombreV[9] = "Free Fire Asociation";
    salario[9] = 890;
}

void ingresarVendedor(string codigo[],string nombre[],float salario[],int &i){

    bool correcto = false;
    string aux;
    cout<<"\n\n\t\t [ INGRESO DE NUEVO REGISTRO DE VENDEDOR ]\n\n";

    cout<<"Ingresa nombre de nuevo Vendedor : ";
    fflush(stdin);
    getline(cin,aux);

    if(!comprobarCyV(nombre,aux,i)){
        nombre[i] = aux;

        cout<<"\nIngresa Codigo de nuevo Vendedor : ";
        fflush(stdin);
        getline(cin,aux);
        codigo[i] = aux;

        cout<<"\nIngresa Salario de nuevo Vendedor : ";
        cin>>salario[i];

        cout<<"\n[ VENDEDOR REGISTRADO CORRECTAMENTE ]\n\n";

        i++;

    }else{
        cout<<"\n\n\t\t[ YA HAY UN VENDEDOR CON EL NOMBRE -> "<<aux<<" ]\n\n";
    }

    system("pause");
}

void ingresarProducto(string codigo[],string descrip[],string tipo[],
                      float precio[],int stock[],int venta[],int &i){

    string aux;
    float precioF;
    int capF;
    bool correcto = false;

    cout<<"\n\n\t\t[ INGRESO DE PRODUCTOS ]\n\n";
    cout<<"Ingresa el codigo del nuevo producto a registrar : ";
    fflush(stdin);
    getline(cin,aux);

    if(!comprobarCyV(codigo,aux,i)){

        codigo[i] = aux;
        cout<<"\nIngresa la descripcion del nuevo producto a registrar : ";
        fflush(stdin);
        getline(cin,aux);
        descrip[i] = aux;

        cout<<"\nIngresa tipo de producto : ";
        fflush(stdin);
        getline(cin,aux);
        tipo[i] = aux;

        do {
            cout << "\nIngresa el precio del nuevo producto a registrar : ";
            cin>>precioF;
            if(precioF >=0){
                correcto = true;
                precio[i] = precioF;
            }else{
                cout<<"\nEl precio tiene que ser mayor o igual a 0\n";
                correcto = false;
            }
        }while(!correcto);

        cout<<"\nIngresa el stock de producto : ";
        cin>>stock[i];

        venta[i] = 0;

        cout<<"\n\n\t\t [ PRODUCTO REGISTRADO CON EXITO ]\n\n";
        i++;

    }else{
        cout<<"\n\n\t\t[ ESTE PRODUCTO YA HA SIDO REGISTRADO ]\n\n";
    }
    system("pause");

}

void listarClientes(string codigo[],string nombre[],string ruc[],
                    string telefono1[],string telefono2[],string direccion[],int max){

    int i,j, y = 8; //METODO BURBUJA

    string auxCod,auxNombre,auxRuc,auxTelf1,auxTelf2,auxDirec;

    for(i = 0; i < max; i++){ //! 3

        for(j = 0; j < max-1; j++){ //2
            if(codigo[j] >= codigo[j+1]){

                //Ordenando Codigo
                auxCod = codigo[j];
                codigo[j] = codigo[j+1];
                codigo[j+1] = auxCod;

                //Ordenando nombre
                auxNombre = nombre[j];
                nombre[j] = nombre[j+1];
                nombre[j+1] = auxNombre;

                //Ordenando Ruc
                auxRuc = ruc[j];
                ruc[j] = ruc[j+1];
                ruc[j+1] = auxRuc;

                //Ordenando Telefono 1
                auxTelf1 = telefono1[j];
                telefono1[j] = telefono1[j+1];
                telefono1[j+1] = auxTelf1;

                //Ordenando Telefono 2
                auxTelf2 = telefono2[j];
                telefono2[j] = telefono2[j+1];
                telefono2[j+1] = auxTelf2;

                //Odenando Direccion
                auxDirec = direccion[j];
                direccion[j] = direccion[j+1];
                direccion[j+1] = auxDirec;
            }
        }

    }

    tituloCliente();

    for(i = 0 ; i < max; i++){
        gotoxy(0,y);
        cout<<codigo[i];

        gotoxy(17,y);
        cout<<nombre[i];

        gotoxy(35,y);
        cout<<ruc[i];

        gotoxy(54,y);
        cout<<telefono1[i];

        gotoxy(74,y);
        cout<<telefono2[i];

        gotoxy(93,y);
        cout<<direccion[i];
        y++;
    }

    gotoxy(0,y+5);
    system("pause");
}

void listarVendedor(string codigo[],string nombre[],float salario[],int max){

    string auxCod,auxNombre;
    float auxSalario;
    int i,j, y = 8;

    //metodo burbuja
    for(i = 0 ; i < max; i++){
        for(j = 0; j < max-1; j++){

            if(codigo[j] >= codigo[j+1]) {
                auxCod = codigo[j];
                codigo[j] = codigo[j + 1];
                codigo[j + 1] = auxCod;

                auxNombre = nombre[j];
                nombre[j] = nombre[j + 1];
                nombre[j + 1] = auxNombre;

                auxSalario = salario[j];
                salario[j] = salario[j + 1];
                salario[j + 1] = auxSalario;
            }
        }
    }

    tituloVendedor();

    for(i = 0; i < max; i++){
        gotoxy(20,y);
        cout<<codigo[i];

        gotoxy(49,y);
        cout<<nombre[i];

        gotoxy(91,y);
        cout<<"S/. "<<salario[i];
        y++;
    }

    gotoxy(0,y+5);
    system("pause");
}


void mayorStock(string codigo [],string nombre [],int stock[],int max){

    int mayor = 0,menor = 9999,i;
    int posAux,posAux2;

    for(i = 0; i < max; i++){
        if(mayor < stock[i]){
            mayor = stock[i];
            posAux = i;
        }
    }

    for(i = 0; i < max; i++){
        if(menor > stock[i]){
            menor = stock[i];
            posAux2 = i;
        }
    }

    gotoxy(0,4);
    cout<<"PRODUCTO [ "<<nombre[posAux]<<" ] CON MAYOR STOCK -> "<<mayor;
    gotoxy(0,5);
    cout<<"PRODUCTO [ "<<nombre[posAux2]<<" ] CON MENOR STOCK -> "<<menor;

}

void listarProducto(string codigo[],string descrip[],string tipo[],
                    float precio[],int stock[],int venta[],int max){

    int i,j;
    string auxCod,auxDescrip,auxTipo;
    int auxStock,auxVenta;
    float auxPrecio;
    int y = 10;

    if(max != 0){

        for(i = 0; i < max; i++){
            for(j = 0; j < max-1; j++){
                if(codigo[j] >= codigo[j+1]){

                    auxDescrip = descrip[j];
                    descrip[j] = descrip[j+1];
                    descrip[j+1] = auxDescrip;

                    auxCod = codigo[j];
                    codigo[j] = codigo[j+1];
                    codigo[j+1] = auxCod;

                    auxTipo = tipo[j];
                    tipo[j] = tipo[j+1];
                    tipo[j+1] = auxTipo;

                    auxStock = stock[j];
                    stock[j] = stock[j+1];
                    stock[j+1] = auxStock;

                    auxPrecio = precio[j];
                    precio[j] = precio[j+1];
                    precio[j+1] = auxPrecio;

                    auxVenta = venta[j];
                    venta[j] = venta[j+1];
                    venta[j+1] = auxVenta;

                }
            }
        }
        tituloProducto();
        mayorStock(codigo,descrip,stock,max);

        for(i = 0 ; i < max; i++){
            gotoxy(0,y);
            cout<<codigo[i];

            gotoxy(20,y);
            cout<<descrip[i];

            gotoxy(49,y);
            cout<<tipo[i];

            gotoxy(65,y);
            cout<<"$/. "<<precio[i];

            gotoxy(84,y);
            cout<<stock[i];

            gotoxy(106,y);
            cout<<venta[i];
            y++;
        }
        gotoxy(0,y+5);
        system("pause");
    }else{
        cout<<"\n\n\t\t[ AUN NO HAY PRODUCTOS REGISTRADOS ]\n\n";
        system("pause");
    }


}


int realizarV(int &ventaCompletada,string VentaCodCLiente[],string VentaCodProducto[],string ventaCodVendedor[],
              string codigoCliente[], string codigoVendedor[],
              string codigoProducto[], int ventaProducto[],
              int stockProducto[],int maxCliente,int maxVendedor,int maxProducto){

    bool correcto = false;
    bool correcto2 = false;

    string auxCodCliente;
    string auxCodVendedor;
    string auxProducto;
    int capacidad;
    string zero ="0";

    int auxI = 0;

    if(maxProducto != 0){
        cout<<"\n\n\t\t[ VENTA DEL ALGUN PRODUCTO ]\n\n";
        cout<<"Escriba 0 para salir del menu de venta..\n";

        //CODIGO CLIENTE
        do{
            cout<<"\nIngresa codigo de Cliente : ";
            fflush(stdin);
            getline(cin,auxCodCliente);

            if(auxCodCliente.compare(zero)==0)
                return 1;

            if(comprobarCyV(codigoCliente,auxCodCliente,maxCliente)){

                cout<<"\n\n\t\t[ CLIENTE ENCONTRADO ]\n";
                correcto = true;
            }else{
                cout<<"No se encontro ningun cliente con ese codigo..\n";
                correcto = false;
            }

        }while(!correcto);

        //CODIGO CODIGO VENDEDOR
        do{
            cout<<"\nIngresa codigo de Vendedor : ";
            fflush(stdin);
            getline(cin,auxCodVendedor);

            if(auxCodVendedor.compare(zero)==0)
                return 1; //si es que lee un return , entonces se omite todo lo demas y regresa a la funcion main

            if(comprobarCyV(codigoVendedor,auxCodVendedor,maxVendedor)){

                cout<<"\n\n\t\t[ VENDEDOR ENCONTRADO ]\n";
                correcto = true;
            }else{
                cout<<"No se encontro ningun vendedor con ese codigo..\n";
                correcto = false;
            }
        }while(!correcto);

        //CODIGO PRODUCTO
        do{
            cout<<"\nIngresa codigo de Producto : ";
            fflush(stdin);
            getline(cin,auxProducto);

            if(auxProducto.compare(zero)==0)
                return 1;

            if(comprobarCyV(codigoProducto,auxProducto,maxProducto)){

                cout<<"\n\n\t\t[ PRODUCTO ENCONTRADO ]\n";
                correcto = true;
            }else{
                cout<<"No se encontro ningun cliente con ese codigo..\n";
                correcto = false;
            }

        }while(!correcto);

        //CANTIDAD DE PRODUCTOS
        do{
            auxI = 0;
            cout<<"\nIngresa Cuantos productos adquirira [Max 5] : ";
            cin>>capacidad;

            if(capacidad >= 1 && capacidad <= 5) {

                for (int i = 0; i < maxProducto; i++) {
                    if (codigoProducto[i].compare(auxProducto) == 0) {
                        auxI = i;
                        correcto2 = true;
                        break;
                    }
                }

            }else{
                cout<<"Debe ingresar un rango correcto\n";
                correcto2 = false;
            }
        }while(!correcto2);


        if(stockProducto[auxI]-capacidad >= 0){ //sotckProducto[aux1 == 3] = y su stock es 10
            cout<<"\n[ SE REALIZO LA VENTA ] \n\n";
            correcto = true;

            stockProducto[auxI] = stockProducto[auxI] - capacidad; // 10 y necesitabamos 4 == 6
            ventaProducto[auxI]++; // = VentaProducto[aux1 == 3] == 0 .. => 0 +1; == 1
            VentaCodCLiente[ventaCompletada] = auxCodCliente;
            ventaCodVendedor[ventaCompletada] = auxCodVendedor;
            VentaCodProducto[ventaCompletada] = auxProducto;
            ventaCompletada++;
            //Venta Completada inicia en 0...ventacodcliente,codvendedor, [0] = auxcodcliente,
            //VENTA COMPLETA SIGUE AUMENTANDODE UNO EN UNO
        }else{
            cout<<"No hay Suficiente Stock en el almacen.. :(\n";
            return 1;
            correcto = false;
        }

        system("pause");
    }else{
        cout<<"\n\n\t\t[ Aun no hay ningun registro de productos ] \n\n";
        system("pause");
    }


    return 0;
}

void listaVendidos(string VentaCodCLiente[],string ventaCodVendedor[],
                   string VentaCodProducto[], int max){

    int i,j, y = 8;

    string auxVcodCliente,auxVcodVendedor,auxVcodProducto;

    if(max != 0) {

        for(i = 0; i < max; i++){
            for(j = 0; j < max-1; j++){
                if(VentaCodProducto[j] >= VentaCodProducto[j+1]){

                    auxVcodProducto = VentaCodProducto[j];
                    VentaCodProducto[j] = VentaCodProducto[j+1];
                    VentaCodProducto[j+1] = auxVcodProducto;

                    auxVcodCliente = VentaCodCLiente[j];
                    VentaCodCLiente[j] = VentaCodCLiente[j+1];
                    VentaCodCLiente[j+1] = auxVcodCliente;

                    auxVcodVendedor = ventaCodVendedor[j];
                    ventaCodVendedor[j] = ventaCodVendedor[j+1];
                    ventaCodVendedor[j+1] = auxVcodVendedor;

                }
            }
        }

        tituloVendidos();
        for(i = 0; i < max; i++){
            gotoxy(23,y);
            cout<<VentaCodProducto[i];

            gotoxy(56,y);
            cout<<VentaCodCLiente[i];

            gotoxy(97,y);
            cout<<ventaCodVendedor[i];
            y++;
        }

        gotoxy(0,y+5);
        system("pause");

    }else{
        cout<<"\n[ Aun no existen ventas realizadas ] \n\n";
        system("pause");
    }


}
