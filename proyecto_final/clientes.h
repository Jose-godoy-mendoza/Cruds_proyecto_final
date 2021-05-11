#pragma once
#include "persona.h"
#include <iostream>
#include "conection.h"
#include <string>
using namespace std;

class clientes : persona
{
    private: string nit, correo_electronico;
public:
    clientes()
    {
    }
    clientes(string nom, string ape, string nt, int gen, int tel, string correo, string fein ) : persona(nom, ape, fein, tel, gen)
    {
        nit = nt;   correo_electronico = correo;
    }

	void setnombres(string nom) { nombres = nom; }
	void setapellidos(string ape) { apellidos = ape; }
	void setnit(string nt) { nit = nt; }
	void setgenero(int gen) { genero = gen; }
	void settelefono(int tel) { telefono = tel; }
	void setcorreo_electronico(string correo) { correo_electronico = correo; }
	void setfechaingreso(string fein) { fechaingreso = fein; }


	string getnombres() { return nombres; }
	string getapellidos() { return apellidos; }
	string getnit() { return nit; }
	int getgenero() { return genero; }
	int gettelefono() { return telefono; }
	string gercorreo_electronico() { return correo_electronico; }
	string getfechaingreso() { return fechaingreso; }

	/// <summary>
	/// /////////////////////////////////
	/// </summary>

	void insert_clientes() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string g = to_string(genero);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO clientes(nombres, apellidos, nit, genero, telefono, correo_electronico, fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + nit + "'," + g + ",'" + t + "','" + correo_electronico + "','"  + fechaingreso + "')";
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
	/// ////////////////////////////
	/// </summary>
	
	void leer_clientes()
	{
		int q_estado;
		conection cn = conection();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------- Datos de Clientes ----------------------------" << endl;
			//cout << "idcli | nombres |  apellidos  |  NIT  | Genero |   Telefono   | Correo Electronico | fecha Ingreso  | "<< endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select * from clientes ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << endl << endl;
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

	/// <summary>
	/// ///////////////////////////////////
	/// </summary>

	int datos_modificar()
	{
		int opcion3;

		system("cls");
		cout << "-------------------- LISTADO DE DATOS DE LA TABLA Clientes --------------------" << endl;
		cout << "1. Nombres" << endl;
		cout << "2. Apellidos" << endl;
		cout << "3. NIT" << endl;
		cout << "4. Genero" << endl;
		cout << "5. Telefono" << endl;
		cout << "6. Correo Electronico" << endl;
		cout << "7. Fecha ingreso" << endl<<endl;
		cout << "\tQue elemento desea modificar: ";
		cin >> opcion3;
		cin.ignore();
		return opcion3;
	}

	void update_clientes(int opcion2, int id_cli)
	{
		int q_estado;
		string id_c = to_string(id_cli);
		string tel = to_string(telefono);
		string gen = to_string(genero);
		string consulta;
		conection cn = conection();
		cn.abrir_conexion();
		if (cn.getConectar())
		{

			switch (opcion2)
			{
			case 1:
				consulta = "update clientes set nombres='" + nombres + "' where idcliente=" + id_c;
				break;
			case 2:
				consulta = "update clientes set apellidos='" + apellidos + "' where idcliente=" + id_c;
				break;
			case 3:
				consulta = "update clientes set nit='" + nit + "' where idcliente=" + id_c;
				break;
			case 4:
				consulta = "update clientes set genero=" + gen + " where idcliente=" + id_c;
				break;
			case 5:
				consulta = "update clientes set telefono= '" + tel + "' where idcliente=" + id_c;
				break;
			case 6:
				consulta = "update clientes set correo_electronico='" + correo_electronico + "' where idcliente=" + id_c;
				break;
			case 7:
				consulta = "update clientes set fechaingreso='" + fechaingreso + "' where idcliente=" + id_c;
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
	/// 
	/// </summary>

	void eliminar_clientes(int id_cli)
	{
		string id_c = to_string(id_cli);
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "delete from clientes where idcliente= " + id_c;
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

