#include <iostream>
#include <cstring>
using namespace std;
const int MAX_EQUIPOS = 1000;  
const int MAX_PARTIDOS = 1000; 

struct Equipo
{
    char nombreEquipo[50];
    int codigoEquipo;
    char division;
    int fechaRegistro;
    int cantidadSocios;
};

struct Partido
{
    int codigoPartido;
    int nGolesEquipo1;
    int nGolesEquipo2;
    int fechaPartido;
};

Equipo equipos[MAX_EQUIPOS];
Partido partidos[MAX_PARTIDOS];
int numEquipos = 0;
int numPartidos = 0;

void mostrarMenuPrincipal();
void mostrarMenuRegistrar();
void mostrarMenuReportes();
void registrarEquipo();
void registrarPartido();
bool validarCodigoEquipo(int codigo);
bool validarDivision(char division);
bool validarFecha(int fecha);
void mostrarCantidadEquiposPorDivision();
void mostrarEquiposUltimosSeisMeses(char division);
void mostrarPromedioSociosSegundaTercera();
void mostrarReporteEquipos();

int main()
{
    int opcionPrincipal;

    do
    {
        cout << "\n--- Menu Principal ---" << endl;
        cout << "1. Registrar" << endl;
        cout << "2. Reportes" << endl;
        cout << "3. Fin" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcionPrincipal;
        cin.ignore();

        switch (opcionPrincipal)
        {
        case 1:
            mostrarMenuRegistrar();
            break;
        case 2:
            mostrarMenuReportes();
            break;
        case 3:
            cout << "Fin del programa." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (opcionPrincipal != 3);

    return 0;
}

void mostrarMenuPrincipal()
{
    cout << "\n--- Menu Principal ---" << endl;
    cout << "1. Registrar" << endl;
    cout << "2. Reportes" << endl;
    cout << "3. Fin" << endl;
}

void mostrarMenuRegistrar()
{
    int opcionRegistrar;

    do
    {
        cout << "\n--- Menu Registrar ---" << endl;
        cout << "1. Registrar equipo" << endl;
        cout << "2. Registrar partido" << endl;
        cout << "3. Fin" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcionRegistrar;
        cin.ignore();

        switch (opcionRegistrar)
        {
        case 1:
            registrarEquipo();
            break;
        case 2:
            registrarPartido();
            break;
        case 3:
            cout << "Fin del registro." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (opcionRegistrar != 3);
}

void mostrarMenuReportes()
{
    int opcionReportes;

    do
    {
        cout << "\n--- Menu Reportes ---" << endl;
        cout << "1. Mostrar numero de equipos por division" << endl;
        cout << "2. Mostrar datos de equipos por división en los últimos seis meses" << endl;
        cout << "3. Mostrar promedio de socios de equipos de segunda o tercera división en los últimos cinco años" << endl;
        cout << "4. Mostrar reporte de equipos ordenados por división y nombre" << endl;
        cout << "5. Fin" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcionReportes;
        cin.ignore();
        switch (opcionReportes)
        {
        case 1:
            mostrarCantidadEquiposPorDivision();
            break;
        case 2:
            char division;
            cout << "Ingrese la division: ";
            cin >> division;
            cin.ignore();
            mostrarEquiposUltimosSeisMeses(division);
            break;
        case 3:
            mostrarPromedioSociosSegundaTercera();
            break;
        case 4:
            mostrarReporteEquipos();
            break;
        case 5:
            cout << "Fin de los reportes." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (opcionReportes != 5);
}

void registrarEquipo()
{
    Equipo equipo;
    cout << "\n--- Registro de Equipo ---" << endl;
    cout << "Ingrese el nombre del equipo: ";
    cin.getline(equipo.nombreEquipo, 50);

    do
    {
        cout << "Ingrese el codigo del equipo (4 digitos): ";
        cin >> equipo.codigoEquipo;
        cin.ignore();
    } while (!validarCodigoEquipo(equipo.codigoEquipo));

    do
    {
        cout << "Ingrese la division del equipo (P, 5, T, @): ";
        cin >> equipo.division;
        cin.ignore();
    } while (!validarDivision(equipo.division));

    do
    {
        cout << "Ingrese la fecha de registro del equipo (DDMMAAAA): ";
        cin >> equipo.fechaRegistro;
        cin.ignore();
    } while (!validarFecha(equipo.fechaRegistro));

    do
    {
        cout << "Ingrese la cantidad de socios del equipo: ";
        cin >> equipo.cantidadSocios;
        cin.ignore();
    } while (equipo.cantidadSocios <= 0);

    for (int i = 0; i < numEquipos; i++)
    {
        if (equipos[i].codigoEquipo == equipo.codigoEquipo)
        {
            cout << "Ya existe un equipo con ese codigo. Registro cancelado." << endl;
            return;
        }
    }

    equipos[numEquipos++] = equipo;
    cout << "Equipo registrado exitosamente." << endl;
}

void registrarPartido()
{
    Partido partido;
    cout << "\n--- Registro de Partido ---" << endl;

    do
    {
        cout << "Ingrese el codigo del partido (entre 100 y 100000): ";
        cin >> partido.codigoPartido;
        cin.ignore();
    } while (partido.codigoPartido < 100 || partido.codigoPartido > 100000);

    do
    {
        cout << "Ingrese el número de goles del equipo 1: ";
        cin >> partido.nGolesEquipo1;
        cin.ignore();
    } while (partido.nGolesEquipo1 < 0);
    do
    {
        cout << "Ingrese el número de goles del equipo 2: ";
        cin >> partido.nGolesEquipo2;
        cin.ignore();
    } while (partido.nGolesEquipo2 < 0);

    do
    {
        cout << "Ingrese la fecha del partido (DDMMAAAA): ";
        cin >> partido.fechaPartido;
        cin.ignore();
    } while (!validarFecha(partido.fechaPartido));

    
    for (int i = 0; i < numPartidos; i++)
    {
        if (partidos[i].codigoPartido == partido.codigoPartido)
        {
            cout << "Ya existe un partido con ese codigo. Registro cancelado." << endl;
            return;
        }
    }

    partidos[numPartidos++] = partido;
    cout << "Partido registrado exitosamente." << endl;
}

bool validarCodigoEquipo(int codigo)
{
    return (codigo >= 1000 && codigo <= 9999);
}

bool validarDivision(char division)
{
    return (division == 'P' || division == '5' || division == 'T' || division == '@');
}
bool validarFecha(int fecha)
{
    int dia = fecha / 1000000;
    int mes = (fecha % 1000000) / 10000;
    int anio = fecha % 10000;
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12)
        return false;

    
    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        {
            if (dia > 29)
                return false;
        }
        else
        {
            if (dia > 28)
                return false;
        }
    }

    
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
            return false;
    }

    return true;
}

void mostrarCantidadEquiposPorDivision()
{
    int contadorPrimera = 0;
    int contadorSegunda = 0;
    int contadorTercera = 0;
    int contadorCuarta = 0;
    for (int i = 0; i < numEquipos; i++)
    {
        if (equipos[i].division == 'P')
            contadorPrimera++;
        else if (equipos[i].division == '5')
            contadorSegunda++;
        else if (equipos[i].division == 'T')
            contadorTercera++;
        else if (equipos[i].division == '@')
            contadorCuarta++;
    }

    cout << "\n--- Cantidad de equipos por division ---" << endl;
    cout << "Primera Division: " << contadorPrimera << " equipos" << endl;
    cout << "Segunda Division: " << contadorSegunda << " equipos" << endl;
    cout << "Tercera Division: " << contadorTercera << " equipos" << endl;
    cout << "Cuarta Division: " << contadorCuarta << " equipos" << endl;
    
    int maxEquipos = max({contadorPrimera, contadorSegunda, contadorTercera, contadorCuarta});

    cout << "Division(es) con la mayor cantidad de equipos: ";

    if (contadorPrimera == maxEquipos)
        cout << "Primera ";

    if (contadorSegunda == maxEquipos)
        cout << "Segunda ";

    if (contadorTercera == maxEquipos)
        cout << "Tercera ";

    if (contadorCuarta == maxEquipos)
        cout << "Cuarta ";

    cout << endl;
}

void mostrarEquiposUltimosSeisMeses(char division)
{
    int fechaActual = 5072023; 
    int fechaLimite = 1012023; 
    cout << "\n--- Equipos de la division " << division << " registrados en los ultimos seis meses ---" << endl;

    for (int i = 0; i < numEquipos; i++)
    {
        if (equipos[i].division == division && equipos[i].fechaRegistro >= fechaLimite && equipos[i].fechaRegistro <= fechaActual)
        {
            cout << "Nombre: " << equipos[i].nombreEquipo << endl;
            cout << "Codigo: " << equipos[i].codigoEquipo << endl;
            cout << "Fecha de registro: " << equipos[i].fechaRegistro << endl;
            cout << "Cantidad de socios: " << equipos[i].cantidadSocios << endl;
            cout << "--------------------------------------" << endl;
        }
    }
}

void mostrarPromedioSociosSegundaTercera()
{
    int anioActual = 2023;           
    int anioLimite = anioActual - 5; 

    int contadorEquipos = 0;
    int sumaSocios = 0;

    for (int i = 0; i < numEquipos; i++)
    {
        if ((equipos[i].division == '5' || equipos[i].division == 'T') && equipos[i].fechaRegistro / 10000 >= anioLimite)
        {
            contadorEquipos++;
            sumaSocios += equipos[i].cantidadSocios;
        }
    }

    if (contadorEquipos == 0)
    {
        cout << "\nNo hay equipos de segunda o tercera division registrados en los ultimos cinco años." << endl;
    }
    else
    {
        double promedio = static_cast<double>(sumaSocios) / contadorEquipos;

        cout << "\n--- Promedio de socios de equipos de segunda o tercera division registrados en los ultimos cinco años ---" << endl;
        cout << "Promedio: " << promedio << endl;
    }
}

void mostrarReporteEquipos()
{
    
    for (int i = 0; i < numEquipos - 1; i++)
    {
        for (int j = 0; j < numEquipos - 1 - i; j++)
        {
            
            if (equipos[j].division > equipos[j + 1].division)
            {
                
                Equipo temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
            
            else if (equipos[j].division == equipos[j + 1].division && strcmp(equipos[j].nombreEquipo, equipos[j + 1].nombreEquipo) < 0)
            {
                
                Equipo temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }
    cout << "\n--- Reporte de equipos ordenados por division y nombre ---" << endl;

    for (int i = 0; i < numEquipos; i++)
    {
        cout << "Nombre: " << equipos[i].nombreEquipo << endl;
        cout << "Codigo: " << equipos[i].codigoEquipo << endl;
        cout << "Division: " << equipos[i].division << endl;
        cout << "Fecha de registro: " << equipos[i].fechaRegistro << endl;
        cout << "Cantidad de socios: " << equipos[i].cantidadSocios << endl;
        cout << "--------------------------------------" << endl;
    }
}