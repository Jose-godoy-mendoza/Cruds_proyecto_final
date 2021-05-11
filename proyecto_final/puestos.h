#pragma once
#include <iostream>
#include "conection.h"
#include <string>
using namespace std;

class puestos
{
private: string puesto;
public:
	puestos()
	{
	}
	puestos(string pue)
	{
		puesto = pue;
	}

	void setpuesto(string pue) { puesto = pue; }

	string getpuesto() { return puesto; }


	void insert_puestos() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "')";
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

	void leer_puestos()
	{
		int q_estado;
		conection cn = conection();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------- Datos de Puestos ----------------------------" << endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << endl << endl;
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

	void update_puestos(int id_pues)
	{
		string id_p = to_string(id_pues);
		int q_estado;
		conection cn = conection();
		cn.abrir_conexion();

		if (cn.getConectar())
		{
			string update = "update puestos set puesto= '" + puesto + "' where idpuesto= " + id_p;
			const char* i = update.c_str();
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
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void eliminar_puestos(int id_pue)
	{
		string id_p = to_string(id_pue);
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "delete from puestos where idpuesto= " + id_p;
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

