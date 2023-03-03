/*HERENCIA MULTIPLE PARTE 2 */

/* Relajar tu mente significa poder "elevarte". En realidad vas más profundo, pero al mismo tiempo
 * te elevas. Debo decirte que me encantó tu proyecto. Tienes mucho talento, y salvo tu mejor
 * opinión, tienes madera de programador. Espero poder estar a la altura de lo que necesitas para
 * brillar.
 *
 * Es un proyecto muy interesante. Cuando te elevas, siempre puedes ver un cuadro más grande, un
 * big picture, y sabrías que un híbrido entre una "persona" y una "clase escolar" sería digna
 * de la película 'La Mosca'. Más que un objeto "compuesto" me parece la Abominación de Hulk jeje,
 * pero te salió al puro pedo. Mi experiencia con herencia múltiple me hace pensar que lo adecuado
 * es combinar objetos con objetos y no objetos con servicios o elementos intangibles (clases,
 * empleos, etc). Aquí se hubiera resuelto de manera más sencilla con herencia simple, pero lograste
 * el fenómeno :P y te felicito. De verdad me emocionan mucho tus posibilidades decidas lo que
 * decidas hacer
 *
 * En otro aspecto, quisiera ver cómo estás configurando VSCode. Hay una opción que te convierte
 * tabuladores en espacios. Esto resulta adecuado para visualizar tu código en editores no muy
 * pro (GitHub, Discord, etc) pero resulta contraproducente entre editores profesionales (Vim,
 * VSCode, etc), y casi fatal a la hora de producir un makefile (recuerda que la sintaxis está
 * basada en el caracter TAB: Nadie quiere que desaparezcan por "espacios". Te encargo mucho
 * homogeneizar la identación con Tabuladores reales para poder seguir trabajándolo. Por ahorita
 * con esto comenzamos para no abrumarnos */

// Vamos a meter espacio entre #include y la librería
#include<iostream>
#include<string>

/* Declarativa -using- inutilizada. Hay que eliminarla o usarla. Si instalas LLVM con Chocolatey
 * y compilas con clang++ verás que te brinca al compilar. */
// using std::cin;
using std::cout;
using std::string;

/* Te sugiero el nombre -Persona-, porqe "Personas" se referiría a VARIAS y no representa
 * fielmente al "objeto".
 *
 * Te recomiendo también nombres con guiones_bajos en lugar de tipo camelCase. Así está construido
 * el lenguaje. Además te recomiendo identaciones sencillas. Lo modificaré para trabajar a gusto */
class Personas {
	public:
		void setNombre( string Nombre ) { NombrePersona = Nombre; }
		void setApellido( string Apellido ) { ApellidoPersona = Apellido; }
		void setGenero( string Genero ) { GeneroPersona = Genero; }
		void setPeso( float Peso ) { PesoPersona = Peso; }
		void setEstatura( float Estatura ) { EstaturaPesona = Estatura; }
		void setEdad( int Edad ) { EdadPersona = Edad; }
		string getNombrePersona() const { return NombrePersona; }
		string getApellidoPersona() const { return ApellidoPersona; }
		string getGeneroPersona() const { return GeneroPersona; }
		float getPesoPersona() const { return PesoPersona; }
		float getEstaturaPersona() const { return EstaturaPesona; }
		int getEdadPersona() const { return EdadPersona; }
		void PersonaInfo(); // Esto se debería llamar imprimir_info() o algo así
	private:
		/* Porque nombrePersona si la clase YA ES persona?
		 *
		 * En los atributos se recomienda que las variablew tengan su propio renglón */
		string NombrePersona, ApellidoPersona, GeneroPersona;
		float PesoPersona, EstaturaPesona;
		int EdadPersona;
};

class Carreras {
	//CARRERAS PARA EL ESTUDIANTE
	/* El título anterior no me gusta. Se supone que apenas la vas a heredar para que los métodos
	 * set y get formen parte de la clase hija Estudiantes. El confinarlo desde ahora "para
	 * estudiantes" no lo hace muy bien visto */
	public:
		void setCarreraEstudiante(string Carrera) { CarreraEstudiante = Carrera; }
		string getCarreraEstudiante()const { return CarreraEstudiante; }
	private:
		string CarreraEstudiante;
};

class Areas {
	//AREAS DONDE TRABAJA EL EMPLEADO
	public:
		void setAreaEmpleado(string Area) { AreaEmpleado = Area; }
		string getAreaEmpleado() const { return AreaEmpleado; }
	private:
		string AreaEmpleado;
	};

class Estudiantes: public Personas, public Carreras {
	// Clase Hija Estudiantes
	public:
		void setTurno(string Turno) { TurnoEstudiante = Turno; }
        void setSemestre(int Semestre) { SemestreEstudiante = Semestre; }
        string getTurnoEstudiante() const { return TurnoEstudiante; }
        int getSemestreEstudiante() const { return SemestreEstudiante; }
        void EstudianteInfo(); // Igual esto se debería llamar también imprimir_info()
    private:
        string TurnoEstudiante;
        int SemestreEstudiante;
};

class Empleados: public Personas, public Areas
{
	public:
		void setSueldoEmpleado(float Sueldo) { SueldoEmpleado = Sueldo; }
		void setFechaIngreso(string Ingreso) { FechaIngresoEmpleado = Ingreso; }
        float getSueldoEmpledo() const { return SueldoEmpleado; }
        string getFechaEmpleado() const { return FechaIngresoEmpleado; }
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


int main(void)
{
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
