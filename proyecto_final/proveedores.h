#pragma once
#include "conection.h"
#include <iostream>
#include <string>
using namespace std;

class proveedores
{
private: string proveedor, nit, direccion;
	int telefono=0;
public:
	proveedores() {	}
	proveedores(string prov, string nt, string dir, int tel)
	{
		proveedor = prov;	nit = nt;	direccion = dir;	telefono = tel;
	}

	void setproveedor(string prov) { proveedor = prov; }
	void setnit(string nt) { nit = nt; }
	void setdireccion(string dir) { direccion = dir; }
	void settelefono(int tel) { telefono = tel; }

	string getproveedor() { return proveedor; }
	string getnit() { return nit; }
	string getdireccion() { return direccion; }
	int gettelefono() { return telefono; }

	/// <summary>
	/// ///////////////////////////
	/// </summary>

	void insert_proveedores() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO proveedores(proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "','" + nit + "','" + direccion + "','" + t + "')";
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

	/// <summary>
	/// /////////////////////////////
	/// </summary>

	void leer_proveedores()
	{
		int q_estado;
		conection cn = conection();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------- Datos de Proveedores ----------------------------" << endl;
			//cout << "idprov | proveedor |  nit  |  direccion  | telefono | " << endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select * from proveedores ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << endl << endl;
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
		cout << "-------------------- LISTADO DE DATOS DE LA TABLA PROVEEDORES --------------------" << endl;
		cout << "1. Proveedor" << endl;
		cout << "2. NIT" << endl;
		cout << "3. Direccion" << endl;
		cout << "4. Telefono" << endl;
		cout << "\tQue elemento desea modificar: ";
		cin >> opcion3;
		cin.ignore();
		return opcion3;
	}


	void update_proveedores(int opcion2, int id_prov)
	{
		int q_estado;
		string id_pro = to_string(id_prov);
		string tel = to_string(telefono);
		string consulta;
		conection cn = conection();
		cn.abrir_conexion();
		if (cn.getConectar())
		{

			switch (opcion2)
			{
			case 1:
				consulta = "update proveedores set proveedor='" + proveedor + "' where idproveedor=" + id_pro;
				break;
			case 2:
				consulta = "update proveedores set nit='" + nit + "' where idproveedor=" + id_pro;
				break;
			case 3:
				consulta = "update proveedores set direccion='" + direccion + "' where idproveedor=" + id_pro;
				break;
			case 4:
				consulta = "update proveedores set telefono='" + tel + "' where idproveedor=" + id_pro;
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

	/// <summary>
	/// ///////////////////////////////
	/// </summary>

	void eliminar_proveedores(int id_prov)
	{
		string id_pro = to_string(id_prov);
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "delete from proveedores where idproveedor= " + id_pro;
			const char* i = insertar.c_str();
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

