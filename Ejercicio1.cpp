/*HERENCIA MULTIPLE PARTE 2

Clase padre:
Persona Carrera Area

Clase hija:
    Estudiantes: Personas, Carrera
    Empleado: Personas, Areas*/

#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::string;

class Personas
{
    public: 

        void setNombre(string Nombre)
        {
            NombrePersona = Nombre;
        }

        void setApellido(string Apellido)
        {
            ApellidoPersona = Apellido;
        }

        void setGenero(string Genero)
        {
            GeneroPersona = Genero;
        }

        void setPeso(float Peso)
        {
            PesoPersona = Peso;
        }

        void setEstatura(float Estatura)
        {
            EstaturaPesona = Estatura;
        }

        void setEdad(int Edad)
        {
            EdadPersona=Edad;
        }

        string getNombrePersona()const
        {
            return NombrePersona;
        }

        string getApellidoPersona()const
        {
            return ApellidoPersona;
        }

        string getGeneroPersona()const
        {
            return GeneroPersona;
        }

        float getPesoPersona()const
        {
            return PesoPersona;
        }

        float getEstaturaPersona()const
        {
            return EstaturaPesona;
        }

        int getEdadPersona()const
        {
            return EdadPersona;
        }


        void PersonaInfo();

    private:    //DATOS GENERALES DE PERSONA
        string NombrePersona, ApellidoPersona, GeneroPersona;
        float PesoPersona, EstaturaPesona;
        int EdadPersona;
};

//CARRERAS PARA EL ESTUDIANTE
class Carreras
{
    
    public: 
        void setCarreraEstudiante(string Carrera)
        {
            CarreraEstudiante = Carrera;
        }

        string getCarreraEstudiante()const
        {
            return CarreraEstudiante;
        }

    private:
        string CarreraEstudiante;
};

//AREAS DONDE TRABAJA EL EMPLEADO
class Areas
{
    public: 
        void setAreaEmpleado(string Area)
        {
            AreaEmpleado = Area;
        }

        string getAreaEmpleado()const
        {
            return AreaEmpleado;
        }


    private: 
        string AreaEmpleado;
};

//Clase Hija Estudiantes
class Estudiantes: public Personas, public Carreras
{
    public:
        void setTurno(string Turno)
        {
            TurnoEstudiante = Turno;
        }

        void setSemestre(int Semestre)
        {
            SemestreEstudiante = Semestre;
        }   

        string getTurnoEstudiante()const
        {
            return TurnoEstudiante;
        }

        int getSemestreEstudiante()const
        {
            return SemestreEstudiante;
        }

        void EstudianteInfo();

    private:
        string TurnoEstudiante;
        int SemestreEstudiante;
};

class Empleados: public Personas, public Areas
{
    public: 
        void setSueldoEmpleado(float Sueldo)
        {
            SueldoEmpleado = Sueldo;
        }
        
        void setFechaIngreso(string Ingreso)
        {
            FechaIngresoEmpleado = Ingreso;
        }

        float getSueldoEmpledo()const
        {
            return SueldoEmpleado;
        }

        string getFechaEmpleado()const
        {
            return FechaIngresoEmpleado;
        }

        void EmpleadoInfo();

    private: 
        float SueldoEmpleado;
        string FechaIngresoEmpleado;
};

//METODOS
void Personas::PersonaInfo() 
{
            cout<<"NOMBRE: "<< getNombrePersona() << '\n'
                <<"APELLIDO: "<< getApellidoPersona() << '\n'
                <<"EDAD: "<< getEdadPersona() << '\n'
                <<"PESO: "<< getPesoPersona() << '\n'
                <<"ESTATURA: "<< getEstaturaPersona() << '\n'
                <<"GENERO: "<<getGeneroPersona() << '\n';
}

void Estudiantes::EstudianteInfo()
{
            PersonaInfo();
            cout<<"CARRERA: "<< getCarreraEstudiante() << '\n'
                <<"SEMESTRE: "<< getSemestreEstudiante() << '\n'
                <<"TURNO: " << getTurnoEstudiante() <<'\n';
}

void Empleados::EmpleadoInfo()
{
            PersonaInfo();
            cout<<"AREA: "<< getAreaEmpleado() << '\n'
                <<"SUELDO: " << getSueldoEmpledo() << '\n'
                <<"FECHA DE INGRESO: " << getFechaEmpleado(); 
}


int main(void){
    Estudiantes xEstudiante;
    Empleados xEmpleado;
    cout<<"****HERENCIA MULTIPLE EN C++****\n";

    xEstudiante.setNombre("JULIO");
    xEstudiante.setApellido("APELLIDO");
    xEstudiante.setGenero("MASCULINO");
    xEstudiante.setEdad(18);
    xEstudiante.setPeso(85.50);
    xEstudiante.setEstatura(1.75);
    xEstudiante.setCarreraEstudiante("INGENIERIA EN SOFTWARE");
    xEstudiante.setSemestre(1);
    xEstudiante.setTurno("MATUTINO");


    cout<<"INFORMACION PERSONAL DEL ESTUDIANTE: \n";
        xEstudiante.PersonaInfo();

    cout<<"\n\nINFORMACION COMPLETA DEL ESTUDIANTE: \n";
        xEstudiante.EstudianteInfo();

    xEmpleado.setNombre("ERNESTO");
    xEmpleado.setApellido("VAZQUEZ");
    xEmpleado.setGenero("MASCULINO");
    xEmpleado.setEdad(46);
    xEmpleado.setPeso(90.40);
    xEmpleado.setEstatura(1.90);
    xEmpleado.setAreaEmpleado("DOCENCIA");
    xEmpleado.setSueldoEmpleado(1200);
    xEmpleado.setFechaIngreso("14-09-1987");

    cout<<"\n\nINFORMACION PERSONAL DEL EMPLEADO: \n";
        xEmpleado.PersonaInfo();

    cout<<"\n\nDATOS COMPLETOS DEL EMPLEADO: \n";
        xEmpleado.EmpleadoInfo();

}