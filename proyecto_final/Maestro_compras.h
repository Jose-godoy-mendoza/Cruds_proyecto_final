#pragma once
#include <iostream>
#include <string>
#include "conection.h"
using namespace std;


class Maestro_compras
{
private: string fecha_orden, fechaingreso;
	   int no_orden_compra=0, idproveedor=0;
public:
	Maestro_compras()
	{
	}
	Maestro_compras(int no_compra, int idprov, string fecha_ord, string fein)
	{
		no_orden_compra = no_compra;	idproveedor = idprov;	fecha_orden = fecha_ord;	fechaingreso = fein;
	}

	void setno_orden_compra(int no_compra) { no_orden_compra = no_compra; }
	void setidproveedor(int idprov) { idproveedor = idprov; }
	void setfecha_orden(string fecha_ord) { fecha_orden = fecha_ord; }
	void setfechaingreso(string fein) { fechaingreso = fein; }


	int getno_orden_compra() { return no_orden_compra; }
	int getidproveedor() { return idproveedor; }
	string getfecha_orden() { return fecha_orden; }
	string getfechaingreso() { return fechaingreso; }


	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void insert_compras() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		string no_orden = to_string(no_orden_compra);
		string idprov = to_string(idproveedor);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras(no_orden_compra, idproveedor, fecha_orden, fechaingreso) VALUES (" + no_orden + "," + idprov + ",'" + fecha_orden + "','" + fechaingreso + "')";
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

	void leer_compras()
	{
		int q_estado;
		conection cn = conection();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "---------------------------- Datos de Compras, Compras Detalle ----------------------------" << endl;
			//cout << "idemp | nombres |  apellidos  |  direccion  | telefono |   dpi   | genero | fecha_nacimiento  | idpuesto | inicio_labores | fechaingreso" << endl;
			cout << "___________________________________________________________________________" << endl;
			string consulta = "select cd.idcompra_detalle, c.idcompra, c.no_orden_compra, c.fecha_orden, c.fechaingreso, p.producto, cd.cantidad, cd.precio_costo_unitario from compras_detalle as cd INNER JOIN compras c on cd.idcompra_detalle=c.idcompra INNER JOIN productos as p on cd.idcompra_detalle=p.idproducto";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8]<< endl << endl;
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

	//// 
	//// /////////////////////
	////

	int datos_modificar()
	{
		int opcion3;

		system("cls");
		cout << "-------------------- LISTADO DE DATOS DE LA TABLA Compras --------------------" << endl;
		cout << "1. no_orden_compra" << endl;
		cout << "2. idproveedor" << endl;
		cout << "3. fecha_orden" << endl;
		cout << "4. fechaingreso" << endl;
		cout << "5. idcompra" << endl;
		cout << "6. idproducto" << endl;
		cout << "7. cantidad" << endl;
		cout << "8. precio_costo_unitario" << endl << endl;
		cout << "\tQue elemento desea modificar: ";
		cin >> opcion3;
		cin.ignore();
		return opcion3;
	}

	void update_compras(int opcion2, int id_com)
	{
		int q_estado;
		string no_orden = to_string(no_orden_compra);
		string idprov = to_string(idproveedor);
		string id_compra = to_string(id_com);
		string consulta;
		conection cn = conection();
		cn.abrir_conexion();
		if (cn.getConectar())
		{

			switch (opcion2)
			{
			case 1:
				consulta = "update compras set no_orden_compra=" + no_orden + " where idcompra=" + id_compra;
				break;
			case 2:
				consulta = "update compras set idproveedor=" + idprov + " where idcompra=" + id_compra;
				break;
			case 3:
				consulta = "update compras set fecha_orden='" + fecha_orden + "' where idcompra=" + id_compra;
				break;
			case 4:
				consulta = "update compras set fechaingreso='" + fechaingreso + "' where idcompra=" + id_compra;
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


	void eliminar_compras(int id_compras)
	{
		string idc = to_string(id_compras);
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string  insertar = "delete from compras where idproducto= " + idc;
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

