#pragma once
#include <iostream>
#include "conection.h"
#include <string>
using namespace std;

class marcas
{
private: string marca;
public:
	marcas() {	}
	marcas(string mar)
	{
		marca = mar;
	}
	void setmarca(string mar) { marca = mar; }
	string getmarca() { return marca; }


	void insert_marcas() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO marcas(marca) VALUES ('" + marca + "')";
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

	void leer_marcas()
	{
		int q_estado;
		conection cn = conection();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "----------------------------  Datos de marcas  ----------------------------" << endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select * from marcas";
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

	void update_marcas(int id_mar)
	{
		string id_m = to_string(id_mar);
		int q_estado;
		conection cn = conection();
		cn.abrir_conexion();

		if (cn.getConectar())
		{
			string update = "update marcas set marca= '" + marca + "' where idmarca= " + id_m;
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

	void eliminar_marcas(int id_mar)
	{
		string id_m = to_string(id_mar);
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "delete from marcas where idmarca= " + id_m;
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

