#include <iostream>
#include <string>
using namespace std;

const int totalVideos = 1000;     
const int totalInfluencers = 100; 


struct Video
{
    int codigo;
    string titulo;
    char calidad;
    int fechaEmision;
    float puntaje;
};

struct Influencer
{
    int codigo;
    string nombre;
    char nivelExperiencia;
};


Video videos[totalVideos];
int numVideos = 0;

Influencer influencers[totalInfluencers];
int numInfluencers = 0;

//protitos
void mostrarMenuPrincipal();
void mostrarMenuRegistrar();
void mostrarMenuReportes();
void registrarVideo();
void registrarInfluencer();
void mostrarCantidadVideosPorCalidad();
void mostrarVideosPorCalidad();
void mostrarPromedioPuntaje();
void mostrarReporteInfluencers();

int main()
{
    char opcion;

    do
    {
        cout << "MenU principal" << endl;
        cout << "A. Registrar" << endl;
        cout << "B. Reportes" << endl;
        cout << "C. Fin" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 'A':
            
            char opcionRegistrar;

            do
            {
                cout << "MenU Registrar" << endl;
                cout << "A. Registrar video" << endl;
                cout << "B. Registrar influencer" << endl;
                cout << "C. Fin" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcionRegistrar;

                switch (opcionRegistrar)
                {
                case 'A':
                    registrarVideo();
                    break;
                case 'B':
                    registrarInfluencer();
                    break;
                case 'C':
                    break;
                default:
                    cout << "Opción invalida. Intente nuevamente." << endl;
                    break;
                }
            } while (opcionRegistrar != 'C');

            break;
        case 'B':
            
            char opcionReportes;

            do
            {
                cout << "MenU Reportes" << endl;
                cout << "A. Mostrar el nUmero de videos de cada calidad registrada." << endl;
                cout << "B. Mostrar los datos de los videos de una determinada calidad emitidos entre 2018 y 2022." << endl;
                cout << "C. Mostrar el promedio del puntaje de los videos con calidad excelente o alta emitidos en los Ultimos 10 meses." << endl;
                cout << "D. Mostrar un reporte de los influencer ordenados por nivel de experiencia y código." << endl;
                cout << "E. Fin" << endl;
                cout << "Ingrese una opción: ";
                cin >> opcionReportes;
                switch (opcionReportes)
                {
                case 'A':
                    mostrarCantidadVideosPorCalidad();
                    break;
                case 'B':
                    mostrarVideosPorCalidad();
                    break;
                case 'C':
                    mostrarPromedioPuntaje();
                    break;
                case 'D':
                    mostrarReporteInfluencers();
                    break;
                case 'E':
                    break;
                default:
                    cout << "Opción invalida. Intente nuevamente." << endl;
                    break;
                }
            } while (opcionReportes != 'E');

            break;
        case 'C':
            cout << "Fin del programa. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción invalida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 'C');

    return 0;
}


void mostrarMenuPrincipal()
{
    cout << "=== MENU PRINCIPAL ===" << endl;
    cout << "A. Registrar" << endl;
    cout << "B. Reportes" << endl;
    cout << "C. Fin" << endl;
}


void mostrarMenuRegistrar()
{
    char opcion;

    do
    {
        cout << "=== MENU REGISTRAR ===" << endl;
        cout << "A. Registrar video" << endl;
        cout << "B. Registrar influencer" << endl;
        cout << "C. Fin" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 'A':
            registrarVideo();
            break;
        case 'B':
            registrarInfluencer();
            break;
        case 'C':
            cout << "Regreso al menu principal." << endl;
            break;
        default:
            cout << "Opción invalida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 'C');
}


void mostrarMenuReportes()
{
    char opcion;

    do
    {
        cout << "=== MENU REPORTES ===" << endl;
        cout << "A. Mostrar cantidad de videos por calidad" << endl;
        cout << "B. Mostrar videos por calidad entre 2018 y 2022" << endl;
        cout << "C. Mostrar promedio de puntaje de videos excelentes o altos en Ultimos 10 meses" << endl;
        cout << "D. Mostrar reporte de influencers ordenados por nivel de experiencia y código" << endl;
        cout << "E. Fin" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 'A':
            mostrarCantidadVideosPorCalidad();
            break;
        case 'B':
            mostrarVideosPorCalidad();
            break;
        case 'C':
            mostrarPromedioPuntaje();
            break;
        case 'D':
            mostrarReporteInfluencers();
            break;
        case 'E':
            cout << "Regreso al menU principal." << endl;
            break;
        default:
            cout << "Opción invalida. Intente nuevamente." << endl;
            break;
        }

        cout << endl;
    } while (opcion != 'E');
}


bool esCodigoVideoUnico(int codigo)
{
    for (int i = 0; i < numVideos; i++)
    {
        if (videos[i].codigo == codigo)
        {
            return false; 
        }
    }
    return true; 
}


bool esCodigoInfluencerUnico(int codigo)
{
    for (int i = 0; i < numInfluencers; i++)
    {
        if (influencers[i].codigo == codigo)
        {
            return false; 
        }
    }
    return true; 
}


bool esFechaEmisionValida(int fecha)
{
    int dia = fecha / 1000000;
    int mes = (fecha / 10000) % 100;
    int anio = fecha % 10000;

    
    if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 2015 && anio <= 2022)
    {
        return true;
    }

    return false;
}


void registrarVideo()
{
    Video video;

    
    cout << "Ingrese el código del video: ";
    cin >> video.codigo;

    
    if (!esCodigoVideoUnico(video.codigo))
    {
        cout << "Error: El código de video ya existe." << endl;
        return;
    }

    cout << "Ingrese el título del video: ";
    cin.ignore();
    getline(cin, video.titulo);

    cout << "Ingrese la calidad del video (A - Alta, B - Baja, M - Media, E - Excelente): ";
    cin >> video.calidad;

    
    if (video.calidad != 'A' && video.calidad != 'B' && video.calidad != 'M' && video.calidad != 'E')
    {
        cout << "Error: La calidad ingresada es invalida." << endl;
        return;
    }

    cout << "Ingrese la fecha de emisión del video (DDMMAAAA): ";
    cin >> video.fechaEmision;

    
    if (!esFechaEmisionValida(video.fechaEmision))
    {
        cout << "Error: La fecha de emisión ingresada es invalida." << endl;
        return;
    }

    cout << "Ingrese el puntaje del video: ";
    cin >> video.puntaje;

    
    if (video.puntaje < 0.1 || video.puntaje > 9.9)
    {
        cout << "Error: El puntaje ingresado esta fuera del rango valido." << endl;
        return;
    }

    
    videos[numVideos] = video;
    numVideos++;

    cout << "El video se ha registrado exitosamente." << endl;
}


void registrarInfluencer()
{
    Influencer influencer;

    
    cout << "Ingrese el código del influencer: ";
    cin >> influencer.codigo;

    
    if (!esCodigoInfluencerUnico(influencer.codigo))
    {
        cout << "Error: El código de influencer ya existe." << endl;
        return;
    }

    cout << "Ingrese el nombre del influencer: ";
    cin.ignore();
    getline(cin, influencer.nombre);

    cout << "Ingrese el nivel de experiencia del influencer (N - Novato, M - Medio, E - Experto): ";
    cin >> influencer.nivelExperiencia;

    
    if (influencer.nivelExperiencia != 'N' && influencer.nivelExperiencia != 'M' && influencer.nivelExperiencia != 'E')
    {
        cout << "Error: El nivel de experiencia ingresado es invalido." << endl;
        return;
    }

    
    influencers[numInfluencers] = influencer;
    numInfluencers++;

    cout << "El influencer se ha registrado exitosamente." << endl;
}


void mostrarCantidadVideosPorCalidad()
{
    int alta = 0, baja = 0, media = 0, excelente = 0;

    
    for (int i = 0; i < numVideos; i++)
    {
        switch (videos[i].calidad)
        {
        case 'A':
            alta++;
            break;
        case 'B':
            baja++;
            break;
        case 'M':
            media++;
            break;
        case 'E':
            excelente++;
            break;
        }
    }

    
    cout << "Cantidad de videos por calidad:" << endl;
    cout << "Alta: " << alta << endl;
    cout << "Baja: " << baja << endl;
    cout << "Media: " << media << endl;
    cout << "Excelente: " << excelente << endl;

    
    int menorCantidad = numVideos; 
    cout << "Calidad(es) con menor cantidad de videos: ";

    if (alta < menorCantidad)
    {
        menorCantidad = alta;
        cout << "Alta ";
    }
    if (baja < menorCantidad)
    {
        menorCantidad = baja;
        cout << "Baja ";
    }
    if (media < menorCantidad)
    {
        menorCantidad = media;
        cout << "Media ";
    }
    if (excelente < menorCantidad)
    {
        menorCantidad = excelente;
        cout << "Excelente ";
    }

    cout << endl;
}


void mostrarVideosPorCalidad()
{
    char calidad;
    int contador = 0;

    cout << "Ingrese la calidad de los videos (A - Alta, B - Baja, M - Media, E - Excelente): ";
    cin >> calidad;

    cout << "Videos de calidad " << calidad << " emitidos entre 2018 y 2022:" << endl;

    for (int i = 0; i < numVideos; i++)
    {
        if (videos[i].calidad == calidad && videos[i].fechaEmision >= 20180101 && videos[i].fechaEmision <= 20221231)
        {
            cout << "Código: " << videos[i].codigo << endl;
            cout << "Título: " << videos[i].titulo << endl;
            cout << "Calidad: " << videos[i].calidad << endl;
            cout << "Fecha de emisión: " << videos[i].fechaEmision << endl;
            cout << "Puntaje: " << videos[i].puntaje << endl;
            cout << "----------------------------------------" << endl;
            contador++;
        }
    }

    if (contador == 0)
    {
        cout << "No se encontraron videos con la calidad y período especificados." << endl;
    }
}


void mostrarPromedioPuntaje()
{
    int mesActual, anioActual;
    float sumaPuntajes = 0.0;
    int contador = 0;

    cout << "Ingrese el mes actual (1-12): ";
    cin >> mesActual;

    cout << "Ingrese el año actual: ";
    cin >> anioActual;

    cout << "Promedio del puntaje de videos con calidad excelente o alta emitidos en los Ultimos 10 meses:" << endl;

    for (int i = 0; i < numVideos; i++)
    {
        int mesEmision = (videos[i].fechaEmision / 10000) % 100;
        int anioEmision = videos[i].fechaEmision % 10000;

        if ((videos[i].calidad == 'E' || videos[i].calidad == 'A') &&
            (anioActual - anioEmision) * 12 + (mesActual - mesEmision) <= 10)
        {
            sumaPuntajes += videos[i].puntaje;
            contador++;
        }
    }

    if (contador > 0)
    {
        float promedio = sumaPuntajes / contador;
        cout << "El promedio es: " << promedio << endl;
    }
    else
    {
        cout << "No se encontraron videos con calidad excelente o alta en los Ultimos 10 meses." << endl;
    }
}


bool compararInfluencer(Influencer influencer1, Influencer influencer2)
{
    if (influencer1.nivelExperiencia != influencer2.nivelExperiencia)
    {
        return influencer1.nivelExperiencia > influencer2.nivelExperiencia;
    }
    else
    {
        return influencer1.codigo < influencer2.codigo;
    }
}


void mostrarReporteInfluencers()
{
    
    sort(influencers, influencers + numInfluencers, compararInfluencer);

    
    cout << "Reporte de influencer ordenados por nivel de experiencia y código:" << endl;
    for (int i = 0; i < numInfluencers; i++)
    {
        cout << "Código: " << influencers[i].codigo << endl;
        cout << "Nombre: " << influencers[i].nombre << endl;
        cout << "Nivel de experiencia: " << influencers[i].nivelExperiencia << endl;
        cout << "----------------------------------------" << endl;
    }
}
