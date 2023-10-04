#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Clase Barco
class Barco {
public:
    string linea;
    int numContenedores;
    double pesoTotal;

public:
    // Constructor
    Barco(string linea) : linea(linea), numContenedores(0), pesoTotal(0) {}

    // Operador sobrecargado <<
    Barco &operator<<(double peso) {
        agregarContenedor(peso);
        return *this;
    }

    // Función para agregar un contenedor al barco
    void agregarContenedor(double peso) {
        numContenedores++;
        pesoTotal += peso;
    }

    // Operador sobrecargado de inserción (para mostrar el barco)
    friend ostream &operator<<(ostream &os, const Barco &barco) {
        os << "Linea: " << barco.linea << endl;
        os << "Num Contenedores: " << barco.numContenedores << endl;
        os << "Peso Total: " << barco.pesoTotal << "KG" << endl;
        return os;
    }
};

// Clase Puerto
class Puerto {
private:
    string nombre;
    string direccion;
    string ruc;
    vector<Barco> barcos;

public:
    // Constructor
    Puerto(string nombre, string direccion, string ruc) : nombre(nombre), direccion(direccion), ruc(ruc) {}

    // Función para ingresar un nuevo barco
    Barco &ingresarBarco(string linea) {
        Barco nuevoBarco(linea);
        barcos.push_back(nuevoBarco);
        return barcos.back();
    }

    // Función para mostrar el volumen de los contenedores
    void mostrarVolumenContenedores() {
        for (const Barco &barco: barcos) {
            cout << "Linea: " << barco.linea << endl;
            for (int i = 0; i < barco.numContenedores; i++) {
                double volumen = obtenerVolumen(barco.linea);
                cout << "Contenedor " << i + 1 << " - Volumen: " << volumen << endl;
            }
            cout << endl;
        }
    }

    // Función auxiliar para obtener el volumen de un contenedor
    double obtenerVolumen(string linea) {
        double longitud = 0.0;
        double ancho = 0.0;
        double alto = 0.0;

        if (linea == "HLC - Hapag Lloyd") {
            longitud = 6.06;
            ancho = 2.44;
            alto = 2.59;
        } else if (linea == "ONE - Ocean Network Express") {
            longitud = 6.05;
            ancho = 2.43;
            alto = 2.59;
        } else if (linea == "PIL - Pacific International Lines") {
            longitud = 6.05;
            ancho = 2.43;
            alto = 2.59;
        }

        double volumen = longitud * ancho * alto;
        return volumen;
    }

    // Función para guardar los datos en un archivo de texto
    void guardarDatos(string nombreArchivo) {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (const Barco &barco: barcos) {
                archivo << barco.linea << "," << barco.numContenedores << "," << barco.pesoTotal << "KG" << endl;
            }
        }
    }
};


int main() {
    Puerto puerto("Puerto del Callao", "Dirección del Puerto", "RUC del Puerto");

    puerto.ingresarBarco("HLC - Hapag Lloyd") << 48000 << 32000;
    puerto.ingresarBarco("ONE - Ocean Network Express") << 25000;
    puerto.ingresarBarco("PIL - Pacific International Lines") << 15000;

    puerto.mostrarVolumenContenedores();

    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de texto: ";
    cin >> nombreArchivo;
    puerto.guardarDatos(nombreArchivo);

    return 0;
}

