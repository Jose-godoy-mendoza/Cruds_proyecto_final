#pragma once
#include "persona.h"
#include <iostream>
#include "conection.h"
#include <string>
using namespace std;

class empleados : persona
{
private: string direccion, dpi, fecha_nacimiento, inicio_labores;
	   int idpuesto = 0, genero=0;
public:
	empleados()
	{
	}
	empleados(string nom, string ape, string dir, int tel, string dp, int gen, string fena, int idp, string inlab, string fein) : persona(nom,ape,fein, tel, gen)
	{
		dpi = dp;	direccion = dir;	fecha_nacimiento = fena;	inicio_labores = inlab;		idpuesto = idp;		genero = gen;
	}

	void setnombres(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setdireccion(string dir) { direccion = dir; }
	void settelefono(int tel) { telefono = tel; }
	void setdpi(string dp) { dpi = dp; }
	void setgenero(int gen) { genero = gen; }
	void setfechanacimiento(string fena) { fecha_nacimiento = fena; }
	void setidpuesto(int idp) { idpuesto = idp; }
	void setiniciolabores(string inlab) { inicio_labores = inlab; }
	void setfechaingreso(string fein) { fechaingreso = fein; }


	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getdireccion() { return direccion; }
	int gettelefono() { return telefono; }
	string getdpi() { return dpi; }
	int getgenero() { return genero; }
	string getfechanacimiento() { return fecha_nacimiento; }
	int getidpuesto() { return idpuesto; }
	string getiniciolabores() { return inicio_labores; }
	string getfechaingreso() { return fechaingreso; }


	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 
	
	void insert_empleados() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string g = to_string(genero);
		string id = to_string(idpuesto);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO empleados(nombres,apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, fecha_inicio_labores, fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "','" + t + "','" + dpi + "'," + g + ",'" + fecha_nacimiento + "'," + id + ",'" + inicio_labores + "','" + fechaingreso + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void leer_empleados()
	{
		int q_estado;
		conection cn = conection();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------- Datos de Empleados ----------------------------" << endl;
			//cout << "idemp | nombres |  apellidos  |  direccion  | telefono |   dpi   | genero | fecha_nacimiento  | idpuesto | inicio_labores | fechaingreso" << endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select e.idempleado,e.nombres,e.apellidos,e.direccion,e.telefono, e.DPI, e.genero, e.fecha_nacimiento, p.puesto, e.fecha_inicio_labores, e.fechaingreso from empleados as e inner join puestos as p on e.idpuesto = p.idpuesto; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << ", " << fila[9] << ", " << fila[10] << endl << endl;
				}
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	int datos_modificar()
	{
		int opcion3;

		system("cls");
		cout << "-------------------- LISTADO DE DATOS DE LA TABLA Empleados --------------------" << endl;
		cout << "1. Nombres" << endl;
		cout << "2. Apellidos" << endl;
		cout << "3. Direccion" << endl;
		cout << "4. Telefono" << endl;
		cout << "5. DPI" << endl;
		cout << "6. Genero" << endl;
		cout << "7. Fecha de Nacimiento " << endl;
		cout << "8. Id puesto " << endl;
		cout << "9. Fecha inicio labores" << endl;
		cout << "10. Fecha ingreso" << endl<<endl;
		cout << "\tQue elemento desea modificar: ";
		cin >> opcion3;
		cin.ignore();
		return opcion3;
	}

	void update_empleados(int opcion2, int id_emp)
	{
		int q_estado;
		string id_e = to_string(id_emp);
		string tel = to_string(telefono);
		string gen = to_string(genero);
		string id_p = to_string(idpuesto);
		string consulta;
		conection cn = conection();
		cn.abrir_conexion();
		if (cn.getConectar())
		{

			switch (opcion2)
			{
			case 1:
				consulta = "update empleados set nombres='" + nombres + "' where idempleado=" + id_e;
				break;
			case 2:
				consulta = "update empleados set apellidos='" + apellidos + "' where idempleado=" + id_e;
				break;
			case 3:
				consulta = "update empleados set direccion='" + direccion + "' where idempleado=" + id_e;
				break;
			case 4:
				consulta = "update empleados set telefono='" + tel + "' where idempleado=" + id_e;
				break;
			case 5:
				consulta = "update empleados set dpi= '" + dpi + "' where idempleado=" + id_e;
				break;
			case 6:
				consulta = "update empleados set genero=" + gen + " where idempleado=" + id_e;
				break;
			case 7:
				consulta = "update empleados set fecha_nacimiento='" + fecha_nacimiento + "' where idempleado=" + id_e;
				break;
			case 8:
				consulta = "update empleados set idpuesto=" + id_p + " where idempleado=" + id_e;
				break;
			case 9:
				consulta = "update empleados set fecha_inicio_labores= '" + inicio_labores + "' where idempleado=" + id_e;
				break;
			case 10:
				consulta = "update empleados set fechaingreso='" + fechaingreso + "' where idempleado=" + id_e;
				break;
			}

			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado)
			{
				cout << "update exitoso" << endl;
			}
			else
			{
				cout << "error en el update" << endl;
			}
		}
		cn.cerrar_conexion();
	}

	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void eliminar_empleados(int id_emp)
	{
		string id_e = to_string(id_emp);
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "delete from empleados where idempleado= " + id_e;
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "delete Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error en el delete  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};
