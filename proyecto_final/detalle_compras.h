#pragma once
#include <iostream>
#include "conection.h"
#include <string>
using namespace std;

class detalle_compras
{
private: int idcompra = 0, idproducto = 0, cantidad = 0; 
	   double precio_costo_unitario = 0;
public:
	detalle_compras(){
	}
	detalle_compras(int idcom, int idprod, int cant, double precio_unit)
	{
		idcompra = idcom;	idproducto = idprod;	cantidad = cant;	precio_costo_unitario = precio_unit;
	}

	void setidcompra(int idcom) { idcompra = idcom; }
	void setidproducto(int idprod) { idproducto = idprod; }
	void setcantidad(int cant) { cantidad = cant; }
	void setprecio_costo_unitario(double precio_unit) { precio_costo_unitario = precio_unit; }


	int getidcompra() { return idcompra; }
	int getidproducto() { return idproducto; }
	int getcantidad() { return cantidad; }
	double getprecio_costo_unitario() { return precio_costo_unitario; }


	///
	/// ////////////////////////////////////////////////////////////////////////////////////////////
	/// 

	void insert_compras_detalle() {
		int q_estado;
		conection cn = conection();

		cn.abrir_conexion();
		string id_com = to_string(idcompra);
		string id_prod = to_string(idproducto);
		string cant = to_string(cantidad);
		string precio_unit = to_string(precio_costo_unitario);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO compras_detalle(idcompra, idproducto, cantidad, precio_costo_unitario) VALUES (" + id_com + "," + id_prod + "," + cant + "," + precio_unit + ")";
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

	void update_compras_detalle(int opcion2, int id_com)
	{
		int q_estado;
		string id_comp = to_string(idcompra);
		string idprod = to_string(idproducto);
		string cant = to_string(cantidad);
		string precio_cost = to_string(precio_costo_unitario);
		string idcompra_det = to_string(id_com);
		string consulta;
		conection cn = conection();
		cn.abrir_conexion();
		if (cn.getConectar())
		{

			switch (opcion2)
			{
			case 5:
				consulta = "update compras_detalle set idcompra=" + id_comp + " where idcompra_detalle=" + idcompra_det;
				break;
			case 6:
				consulta = "update compras_detalle set idproducto=" + idprod + " where idcompra_detalle=" + idcompra_det;
				break;
			case 7:
				consulta = "update compras_detalle set cantidad=" + cant + " where idcompra_detalle=" + idcompra_det;
				break;
			case 8:
				consulta = "update compras_detalle set precio_costo_unitario=" + precio_cost + " where idcompra_detalle=" + idcompra_det;
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
};

