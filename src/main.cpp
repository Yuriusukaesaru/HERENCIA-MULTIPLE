/*HERENCIA MULTIPLE PARTE 2 */

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Persona {/*{{{*/
	public:
		void set_nombre( string _Nombre )		{ nombre = _Nombre; }
		void set_apellido( string _Apellido )	{ apellido = _Apellido; }
		void set_genero( string _Genero )		{ genero = _Genero; }
		void set_peso( float _Peso )			{ peso = _Peso; }
		void set_estatura( float _Estatura )	{ estatura = _Estatura; }
		void set_edad( int _Edad )				{ edad = _Edad; }

		string get_nombre() const { return nombre; }
		string get_apellido() const { return apellido; }
		string get_genero() const { return genero; }
		float get_peso() const { return peso; }
		float get_estatura() const { return estatura; }
		int get_edad() const { return edad; }

		void imprimir_info()
		{
			cout << "NOMBRE: "		<< get_nombre() << '\n'
				 << "APELLIDO: "	<< get_apellido() << '\n'
				 << "EDAD: "		<< get_edad() << '\n'
				 << "PESO: "		<< get_peso() << '\n'
				 << "ESTATURA: "	<< get_estatura() << '\n'
				 << "GENERO: "		<< get_genero() << '\n';
		}

	private:
		string nombre;
		string apellido;
		string genero;
		float peso;
		float estatura;
		std::int16_t edad;
};/*}}}*/

class Matriculado {/*{{{*/
	public:
		void set_carrera( string _Carrera ) { carrera = _Carrera; }
		string get_carrera() const { return carrera; }
	private:
		string carrera;
};/*}}}*/

class Empleado {/*{{{*/
	public:
		void set_area( string _Area) { area = _Area; }
		string get_area() const { return area; }
	private:
		string area;
};/*}}}*/

class Estudiante: public Persona, public Matriculado {/*{{{*/
	public:
		void set_turno(string _Turno) { turno = _Turno; }
        void set_semestre(int _Semestre) { semestre = _Semestre; }

        string get_turno() const { return turno; }
        int get_semestre() const { return semestre; }

        void imprimir_info() {
			Persona::imprimir_info();
			cout	<< "CARRERA: "	<< get_carrera() << '\n'
					<< "SEMESTRE: "	<< get_semestre() << '\n'
					<< "TURNO: "	<< get_turno() <<'\n';
		}

    private:
        string turno;
        int semestre;
};/*}}}*/

class Trabajador: public Persona, public Empleado {/*{{{*/
	public:
		void set_sueldo( float _Sueldo ) { sueldo = _Sueldo; }
		void set_fecha_ingreso( string _Fecha ) { fecha_ingreso = _Fecha; }

		float get_sueldo() const { return sueldo; }
		string get_fecha_ingreso() const { return fecha_ingreso; }

		void imprimir_info()
		{
			Persona::imprimir_info();
			cout	<< "AREA: "				<< get_area() << '\n'
					<< "SUELDO: "			<< get_sueldo() << '\n'
					<< "FECHA DE INGRESO: " << get_fecha_ingreso(); 
		}

	  private:
		float sueldo;
		string fecha_ingreso;
};/*}}}*/

int main()/*{{{*/
{
    Estudiante estudiante;
    Trabajador trabajador;

    cout << "****HERENCIA MULTIPLE EN C++****\n\n";

	// ESTUDIANTE
    estudiante.set_nombre("JULIO");
    estudiante.set_apellido("APELLIDO");
    estudiante.set_genero("MASCULINO");
    estudiante.set_edad(18);
    estudiante.set_peso(85.50);
    estudiante.set_estatura(1.75);
    estudiante.set_carrera("INGENIERIA EN SOFTWARE");
    estudiante.set_semestre(1);
    estudiante.set_turno("MATUTINO");

    cout << "INFORMACION PERSONAL DEL ESTUDIANTE: \n";
    estudiante.Persona::imprimir_info();

    cout << "\n\nINFORMACION COMPLETA DEL ESTUDIANTE: \n";
	estudiante.imprimir_info();

	// TRABAJADOR
    trabajador.set_nombre("ERNESTO");
    trabajador.set_apellido("VAZQUEZ");
    trabajador.set_genero("MASCULINO");
    trabajador.set_edad(46);
    trabajador.set_peso(90.40);
    trabajador.set_estatura(1.90);
    trabajador.set_area("DOCENCIA");
    trabajador.set_sueldo(1200);
    trabajador.set_fecha_ingreso("14-09-1987");

    cout << "\n\nINFORMACION PERSONAL DEL EMPLEADO: \n";
    trabajador.Persona::imprimir_info();

    cout << "\n\nDATOS COMPLETOS DEL EMPLEADO: \n";
trabajador.imprimir_info();

	std::cout << '\n';
}/*}}}*/
