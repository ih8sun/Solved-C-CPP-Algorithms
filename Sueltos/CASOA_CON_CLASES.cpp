#include <iostream>
#include <vector>
#include <string>

using namespace std;

// La empresa desarrolladora de software, SOFT-UPC, ha decidido contratarlo para desarrollar una 
//aplicación en una clínica de salud. La aplicación requiere registrar a los médicos, pacientes, citas, así 
//como las atenciones.

// Clase Paciente

class Paciente
{
private: // es como un backend, se ponen las variables 
    string dni;
    string nombres;
    string apellidos;
    string sexo;

public: // es como un frontend tipo de acceso 
    Paciente(string dni, string nombres, string apellidos, string sexo2) //es un costructor 
    {
        this->dni = dni;
        this->nombres = nombres;
        this->apellidos = apellidos;
        sexo = sexo2;
    }
    // Métodos getter y setter de private 

    string getDNI()
    {
        return dni;
    }
    string getNombres()
    {
        return nombres;
    }
    string getApellidos()
    {
        return apellidos;
    }
    string getSexo()
    {
        return sexo;
    }
};

// Clase Medico
class Medico
{
private:
    string numeroColegiatura;
    string nombres;
    string apellidos;
    string especialidadMedico;
    double honorarios;

public:
    Medico(string numeroColegiatura, string nombres, string apellidos, string especialidad, double honorarios2)
    {
        this->numeroColegiatura = numeroColegiatura;
        this->nombres = nombres;
        this->apellidos = apellidos;
        this->especialidadMedico = especialidad;
        honorarios = honorarios2;
    }
    // Métodos getter y setter
    string getNumeroColegiatura()
    {
        return numeroColegiatura;
    }
    string getNombres()
    {
        return nombres;
    }
    string getApellidos()
    {
        return apellidos;
    }
    string getEspecialidad()
    {
        return especialidadMedico;
    }
    double getHonorarios()
    {
        return honorarios;
    }
};

// Clase Cita
class Cita
{
private:
    string dniPaciente;
    string numeroColegiatura;
    string fechaHora;

public:
    Cita(string dniPaciente, string numeroColegiatura, string fechaHora)
    {
        this->dniPaciente = dniPaciente;
        this->numeroColegiatura = numeroColegiatura;
        this->fechaHora = fechaHora;
    }
    // Métodos getter y setter
    string getDniPaciente()
    {
        return dniPaciente;
    }
    string getNumeroColegiatura()
    {
        return numeroColegiatura;
    }
    string getFechaHora()
    {
        return fechaHora;
    }
};

// Clase Atencion
class Atencion
{
private:
    string dniPaciente;
    string numeroColegiatura;
    string fechaHora;
    string diagnostico;
    string medicamento;

public:
    Atencion(string dniPaciente, string numeroColegiatura, string fechaHora, string diagnostico, string medicamento)
    {
        this->dniPaciente = dniPaciente;
        this->numeroColegiatura = numeroColegiatura;
        this->fechaHora = fechaHora;
        this->diagnostico = diagnostico;
        this->medicamento = medicamento;
    }
    // Métodos getter y setter
    string getDniPaciente()
    {
        return dniPaciente;
    }
    string getNumeroColegiatura()
    {
        return numeroColegiatura;
    }
    string getFechaHora()
    {
        return fechaHora;
    }
    string getDiagnostico()
    {
        return diagnostico;
    }
    string getMedicamento()
    {
        return medicamento;
    }
};

// Clase Clinica, Contiene las clases
class Clinica
{
private:
    vector<Paciente> pacientes; // tipo de variable vector <paciente> 
    vector<Medico> medicos;
    vector<Cita> citas;
    vector<Atencion> atenciones;

public:
    // Métodos para gestionar pacientes
    void registrarPaciente(Paciente paciente)
    {
        pacientes.push_back(paciente);
    }

    bool existePaciente(string dni)
    {
        for (Paciente &paciente : pacientes)
        {
            if (paciente.getDNI() == dni)
            {
                return true;
            }
        }
        return false;
    }

    // Métodos para gestionar médicos
    void registrarMedico(Medico medico)
    {
        medicos.push_back(medico);
    };

    bool existeMedico(string numeroColegiatura)
    {
        for (int i = 0; i < medicos.size(); i++)
        {
            if (medicos[i].getNumeroColegiatura() == numeroColegiatura)
            {
                return true;
            }
        }
        return false;
    }

    // Métodos para gestionar citas
    void reservarCita(Cita cita)
    {
        citas.push_back(cita);
    }

    bool verificarDisponibilidadCita(string numeroColegiatura, string fechaHora)
    {
        for (int i = 0; i < citas.size(); i++)
        {
            if (citas[i].getNumeroColegiatura() == numeroColegiatura && citas[i].getFechaHora() == fechaHora)
            {
                return false; // La cita ya está reservada
            }
        }
        return true; // La cita está disponible
    }

    // Métodos para gestionar atenciones
    
    void registrarAtencion(Atencion atencion)
    {
        atenciones.push_back(atencion);
    }

    // Otros métodos para los reportes
    double obtenerRecaudacionMensual(int anio, int mes)
    {
        double totalRecaudado = 0.0;
        for (Atencion &atencion : atenciones)
        {
            // Obtener la fecha y hora de la atención
            string fechaHora = atencion.getFechaHora();
            // Extraer el año y mes de la fecha y hora
            int atencionAnio = stoi(fechaHora.substr(0, 4));
            int atencionMes = stoi(fechaHora.substr(5, 2));

            // Verificar si la atención ocurrió en el mes y año especificados
            if (atencionAnio == anio && atencionMes == mes)
            {
                string numeroColegiatura = atencion.getNumeroColegiatura();
                // Buscar el médico correspondiente en el vector de médicos
                for (Medico &medico : medicos)
                {
                    if (medico.getNumeroColegiatura() == numeroColegiatura)
                    {
                        double honorario = medico.getHonorarios();
                        totalRecaudado += honorario;
                        break;
                    }
                }
            }
        }
        return totalRecaudado;
    }

    double obtenerPorcentajeAtenciones(int anio, int mes, string sexo)
    {
        int totalAtenciones = 0;
        int atencionesSexo = 0;
        for (Atencion &atencion : atenciones)
        {
            // Obtener la fecha y hora de la atención
            string fechaHora = atencion.getFechaHora();
            // Extraer el año y mes de la fecha y hora
            int atencionAnio = stoi(fechaHora.substr(0, 4));
            int atencionMes = stoi(fechaHora.substr(5, 2));

            // Verificar si la atención ocurrió en el mes y año especificados
            if (atencionAnio == anio && atencionMes == mes)
            {
                string dniPaciente = atencion.getDniPaciente();
                // Buscar el paciente correspondiente en el vector de pacientes
                for (Paciente &paciente : pacientes)
                {
                    if (paciente.getDNI() == dniPaciente)
                    {
                        totalAtenciones++;
                        if (paciente.getSexo() == sexo)
                        {
                            atencionesSexo++;
                        }
                        break;
                    }
                }
            }
        }

        if (totalAtenciones == 0)
        {
            return 0.0; // Evitar división por cero
        }

        return (static_cast<double>(atencionesSexo) / totalAtenciones) * 100.0;
    }

    vector<Paciente> obtenerPacientesAtendidosPorMedicoEnMes(int anio, int mes, string numeroColegiatura)
    {
        vector<Paciente> pacientesAtendidos; // estos seran mis pacieeentes atendidos
        for (Atencion &atencion : atenciones)
        {
            // Obtener la fecha y hora de la atención
            string fechaHora = atencion.getFechaHora();
            // Extraer el año y mes de la fecha y hora
            int atencionAnio = stoi(fechaHora.substr(0, 4));
            int atencionMes = stoi(fechaHora.substr(5, 2));

            // Verificar si la atención ocurrió en el mes y año especificados y si coincide con el médico
            if (atencionAnio == anio && atencionMes == mes && atencion.getNumeroColegiatura() == numeroColegiatura)
            {
                //si ha cumplido el if de arribita entonces entra aqui
                
                //ahora obtengo el dni del paciente que se atendio
                string dniPaciente = atencion.getDniPaciente();
                
                //ahora busco el paciente por su numero de dni..
                for (Paciente &paciente : pacientes)
                {// es por eso muy importante el for ya que quiero buscar el paciente 
                    if (paciente.getDNI() == dniPaciente)// aqui si lo encontre
                    {
                        //y aqui voy a meter el paciente a la lista de pacientes atendidos.
                        pacientesAtendidos.push_back(paciente);
                        break;
                    }
                }
            }
        }

    // Ordenar los pacientes por apellido de forma ascendente (método de selección)

    // Obtener el tamaño de la lista de pacientes
        int n = pacientesAtendidos.size();

        // Implementar el algoritmo de ordenamiento burbuja
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Comparar los apellidos de dos pacientes
                if (pacientesAtendidos[j].getApellidos() < pacientesAtendidos[i].getApellidos())
                {
                    // Intercambiar los pacientes si están en orden incorrecto
                    swap(pacientesAtendidos[i], pacientesAtendidos[j]);
                }
            }
        }
};

int main()
{
    Clinica clinica;

    int opcion;
    int opcionReporte;
    do
    {
        cout << "=== SISTEMA ALUMNOS UPC SOFTWARE PARA CLINICAS Y/O HOSPITALES  ===" << endl;
        cout << "1. NUEVO PACIENTES" << endl;
        cout << "2. REGISTRO DEL MEDICO" << endl;
        cout << "3. Reservar cita" << endl;
        cout << "4. Registrar atención" << endl;
        cout << "5. Generar Reporte" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            cout << "\n\t[ INGRESO DE PACIENTE ]\n\n";
            string dni, nombres, apellidos, sexo;
            cout << "Ingrese el DNI del paciente: ";
            cin >> dni;
            cout << "Ingrese los nombres del paciente: ";
            cin.ignore(); // Limpiar el buffer del teclado antes de getline()
            getline(cin, nombres);
            cout << "Ingrese los apellidos del paciente: ";
            getline(cin, apellidos);
            cout << "Ingrese el sexo del paciente: ";
            cin >> sexo;

            Paciente paciente(dni, nombres, apellidos, sexo);
            clinica.registrarPaciente(paciente);
            cout << "Paciente registrado correctamente." << endl;
            break;
        }
        case 2:
        {
            cout << "\n\t[ INGRESO DE MEDICO ]\n\n";
            string numeroColegiatura, nombres, apellidos, especialidad;
            double honorarios;
            cout << "Ingrese el número de colegiatura del médico: ";
            cin >> numeroColegiatura;
            cout << "Ingrese los nombres del médico: ";
            cin.ignore();
            getline(cin, nombres);
            cout << "Ingrese los apellidos del médico: ";
            getline(cin, apellidos);
            cout << "Ingrese la especialidad del médico: ";
            getline(cin, especialidad);
            cout << "Ingrese los honorarios del médico: ";
            cin >> honorarios;

            Medico medico(numeroColegiatura, nombres, apellidos, especialidad, honorarios);
            clinica.registrarMedico(medico);
            cout << "Médico registrado correctamente." << endl;
            break;
        }

        case 3:
        {
            cout << "\n\t[ REGISTRO DE CITA ]\n\n";
            string dniPaciente, numeroColegiatura, fechaHora;
            cout << "Ingrese el DNI del paciente: ";
            cin >> dniPaciente;
            cout << "Ingrese el número de colegiatura del médico: ";
            cin >> numeroColegiatura;
            cout << "Ingrese la fecha y hora de la cita (YYYY-MM-DD HH:MM): ";
            cin.ignore();
            getline(cin, fechaHora);

            Cita cita(dniPaciente, numeroColegiatura, fechaHora);
            if (clinica.verificarDisponibilidadCita(numeroColegiatura, fechaHora))
            {
                clinica.reservarCita(cita);
                cout << "Cita reservada correctamente." << endl;
            }
            else
            {
                cout << "El médico ya tiene una cita reservada en esa fecha y hora." << endl;
            }
            break;
        }

        case 4:
        {
            cout << "\n\t[ REGISTRO DE ATENCION ]\n\n";
            string dniPaciente, numeroColegiatura, fechaHora, diagnostico, medicamento;
            cout << "Ingrese el DNI del paciente: ";
            cin >> dniPaciente;
            cout << "Ingrese el número de colegiatura del médico: ";
            cin >> numeroColegiatura;
            cout << "Ingrese la fecha y hora de la atención (YYYY-MM-DD HH:MM): ";
            cin.ignore();
            getline(cin, fechaHora);
            cout << "Ingrese el diagnóstico: ";
            getline(cin, diagnostico);
            cout << "Ingrese el medicamento recetado: ";
            getline(cin, medicamento);

            // Verificar si el paciente y médico existen en la clínica
            if (clinica.existePaciente(dniPaciente) && clinica.existeMedico(numeroColegiatura))
            {
                Atencion atencion(dniPaciente, numeroColegiatura, fechaHora, diagnostico, medicamento);
                clinica.registrarAtencion(atencion);
                cout << "Atención registrada correctamente." << endl;
            }
            else
            {
                cout << "El paciente o el médico no existen en la clínica." << endl;
            }
            break;
        }

        case 5:
        {
            cout << "\n\t[ REPORTES ]\n\n";
            cout << "Seleccione el reporte a generar:" << endl;
            cout << "1. Reporte de recaudación mensual" << endl;
            cout << "2. Reporte de porcentaje de atenciones por sexo" << endl;
            cout << "3. Reporte de pacientes atendidos por médico en un mes" << endl;
            cout << "Ingrese su opción: ";
            cin >> opcionReporte;
            double porcentaje;
            double recaudacion;
            int anio, mes;
            string numeroColegiatura, sexo;
            vector<Paciente> pacientesAtendidos;

            switch (opcionReporte)
            {
            case 1:
                cout << "Ingrese el año: ";
                cin >> anio;
                cout << "Ingrese el mes: ";
                cin >> mes;
                recaudacion = clinica.obtenerRecaudacionMensual(anio, mes);
                cout << "Recaudación mensual: $" << recaudacion << endl;
                break;

            case 2:
                cout << "Ingrese el año: ";
                cin >> anio;
                cout << "Ingrese el mes: ";
                cin >> mes;
                cout << "Ingrese el sexo (M/F): ";
                cin >> sexo;
                porcentaje = clinica.obtenerPorcentajeAtenciones(anio, mes, sexo);
                cout << "Porcentaje de atenciones: " << porcentaje << "%" << endl;
                break;

            case 3:
                cout << "Ingrese el año: ";
                cin >> anio;
                cout << "Ingrese el mes: ";
                cin >> mes;
                cout << "Ingrese el número de colegiatura del médico: ";
                cin >> numeroColegiatura;
                pacientesAtendidos = clinica.obtenerPacientesAtendidosPorMedicoEnMes(anio, mes, numeroColegiatura);
                cout << "Pacientes atendidos por el médico en el mes:" << endl;
                for (Paciente &paciente : pacientesAtendidos)
                {
                    cout << "DNI: " << paciente.getDNI() << ", Nombre: " << paciente.getNombres() << " " << paciente.getApellidos() << endl;
                }
                break;
            }
            break;
        }

        default:
            break;
        }

    } while (opcion != 6);

    return 0;
}

}