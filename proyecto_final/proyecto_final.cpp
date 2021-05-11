#include <mysql.h>
#include <iostream>
#include "empleados.h"
#include "conection.h"
#include "clientes.h"
#include "puestos.h"
#include "marcas.h"
#include "proveedores.h"
#include "producto.h"
#include "Maestro_compras.h"
#include "detalle_compras.h"
using namespace std;


void repetir();

void opciones()
{
	system("cls");
	cout << "_______________ Opciones _______________" << endl;
	cout << "1. Leer registros" << endl;
	cout << "2. Insertar registros" << endl;
	cout << "3. Modificar registros" << endl;
	cout << "4. Eliminar registros" << endl;
}

void menu()
{
	string puesto, nombre, apellido, direccion, dpi, fecha_nacimiento, inicio_labores, fechaingreso, nit, correo_electronico, marca, proveedor, productos, descripcion, imagen, fecha_orden;
	int opcion, opcion2, idpuesto, genero, telefono, id_empleado, id_cliente, idmarca, idproveedor, existencia, idproducto, no_orden_compra, idcompra, cantidad;
	double precio_costo, precio_venta, precio_costo_unitario;

	empleados e = empleados();
	puestos p = puestos();
	clientes c = clientes();
	marcas m = marcas();
	proveedores pro = proveedores();
	producto prod = producto();
	Maestro_compras Mc = Maestro_compras();
	detalle_compras dc = detalle_compras();

	cout << "_______________ Menu de Tablas _______________" << endl;
	cout << "1. Tabla Puestos" << endl;
	cout << "2. Tabla Empleados" << endl;
	cout << "3. Tabla Clientes" << endl;
	cout << "4. Tabla Marcas" << endl;
	cout << "5. Tabla Proveedores" << endl;
	cout << "6. Tabla Productos" << endl;
	cout << "7. Maestro detalle compras" << endl;
	cout << "\n\tingrese la tabla que desea: ";
	cin >> opcion;
	cin.ignore();
	if (opcion == 1)
	{
		system("cls");
		cout << "_______________ TABLA DE PUESTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			p.leer_puestos();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "ingrese el puesto: ";
			getline(cin, puesto);
			p = puestos(puesto);
			p.insert_puestos();
			repetir();
			break;
		case 3:
			system("cls");
			p.leer_puestos();
			cout << endl << endl;
			cout << "ingrese el id del registro a modificar: ";
			cin >> idpuesto;
			cin.ignore();
			cout << "ingrese el nuevo puesto: ";
			getline(cin, puesto);
			p = puestos(puesto);
			p.update_puestos(idpuesto);
			repetir();
			break;
		case 4:
			system("cls");
			p.leer_puestos();
			cout << endl << endl;
			cout << "ingrese el id del registro a eliminar: ";
			cin >> idpuesto;
			cin.ignore();
			p.eliminar_puestos(idpuesto);
			repetir();
			break;
		}
	}

	/// <summary>
	/// //////////////////////////////////
	/// </summary>

	if (opcion == 2)
	{
		system("cls");
		cout << "_______________ TABLA DE PUESTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			e.leer_empleados();
			repetir();
			break;

		case 2:
			system("cls");
			cout << "\nIngrese nombres: ";
			getline(cin, nombre);
			cout << "\nIngrese apellidos: ";
			getline(cin, apellido);
			cout << "\nIngrese direccion: ";
			getline(cin, direccion);
			cout << "\nIngrese telefono: ";
			cin >> telefono;
			cin.ignore();
			cout << "\nIngrese DPI:";
			getline(cin, dpi);
			cout << "\ningrese Genero (0 = mujer, 1= hombre): ";
			cin >> genero;
			cin.ignore();
			cout << "\nIngrese fecha de nacimiento: ";
			getline(cin, fecha_nacimiento);
			cout << "\nIngrese id_puesto:";
			cin >> idpuesto;
			cin.ignore();
			cout << "\nIngrese fecha inicio labores: ";
			getline(cin, inicio_labores);
			cout << "\nIngrese fecha de ingreso (anio/mes/dia hora:minuto:segundo) ";
			getline(cin, fechaingreso);

			e = empleados(nombre, apellido, direccion, telefono, dpi, genero, fecha_nacimiento, idpuesto, inicio_labores, fechaingreso);
			e.insert_empleados();
			repetir();
			break;

		case 3:
			system("cls");
			e.leer_empleados();
			cout << endl << endl;
			cout << "ingrese id empleado del registro a modificar: "; cin >> id_empleado;
			opcion2 = e.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo nombre: "; getline(cin, nombre);
				e.setnombres(nombre);
				break;
			case 2:
				cout << "\ningrese el nuevo apellido: "; getline(cin, apellido);
				e.setapellidos(apellido);
				break;
			case 3:
				cout << "\ningrese la nueva direccion: "; getline(cin, direccion);
				e.setdireccion(direccion);
				break;
			case 4:
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				e.settelefono(telefono);
				break;
			case 5:
				cout << "\ningrese el nuevo dpi: "; getline(cin, dpi);
				e.setdpi(dpi);
				break;
			case 6:
				cout << "\ningrese el nuevo genero  (0 = mujer, 1= hombre): "; cin >> genero; cin.ignore();
				e.setgenero(genero);
				break;
			case 7:
				cout << "\ningrese la nueva fecha de nacimiento "; getline(cin, fecha_nacimiento);
				e.setfechanacimiento(fecha_nacimiento);
				break;
			case 8:
				cout << "\ningrese el nuevo id puesto "; cin >> idpuesto; cin.ignore();
				e.setidpuesto(idpuesto);
				break;
			case 9:
				cout << "\ningrese la nueva fecha de inicio de labores "; getline(cin, inicio_labores);
				e.setiniciolabores(inicio_labores);
				break;
			case 10:
				cout << "\ningrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				e.setfechaingreso(fechaingreso);
				break;
			}
				e.update_empleados(opcion2, id_empleado);
			repetir();
			break;

		case 4:
			system("cls");
			e.leer_empleados();
			cout << endl << endl;
			cout << "ingrese el id empleado del registro que desea eliminar: "; cin >> id_empleado;
			e.eliminar_empleados(id_empleado);
			repetir();
			break;
		}
	}

	/// <summary>
	/// //////////////////////////
	/// </summary>
	
	if (opcion == 3)
	{
		system("cls");
		cout << "_______________ TABLA DE Clientes _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			c.leer_clientes();
			repetir();
			break;
		case 2:

			system("cls");
			cout << "\nIngrese nombres: ";
			getline(cin, nombre);
			cout << "\nIngrese apellidos: ";
			getline(cin, apellido);
			cout << "\nIngrese nit: ";
			getline(cin, nit);
			cout << "\nIngrese genero (0=mujer, 1=hombre): ";
			cin >> genero;
			cin.ignore();
			cout << "\nIngrese telefono:";
			cin>>telefono;
			cin.ignore();
			cout << "\nIngrese correo electronico: ";
			getline(cin, correo_electronico);
			cout << "\nIngrese fecha de ingreso (anio/mes/dia hora:minuto:segundo) ";
			getline(cin, fechaingreso);

			c = clientes(nombre, apellido, nit, genero, telefono, correo_electronico, fechaingreso);
			c.insert_clientes();
			repetir();
			break;

		case 3:
			system("cls");
			c.leer_clientes();
			cout << endl << endl;
			cout << "ingrese id cliente del registro a modificar: "; cin >> id_cliente;
			opcion2 = c.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo nombre: "; getline(cin, nombre);
				c.setnombres(nombre);
				break;
			case 2:
				cout << "\ningrese el nuevo apellido: "; getline(cin, apellido);
				c.setapellidos(apellido);
				break;
			case 3:
				cout << "\ningrese el nuevo nit: "; getline(cin, nit);
				c.setnit(nit);
				break;
			case 4:
				cout << "\ningrese el nuevo genero (0=mujer, 1=hombre): "; cin >> genero; cin.ignore();
				c.setgenero(genero);
				break;
			case 5:
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				c.settelefono(telefono);
				break;
			case 6:
				cout << "\ningrese el nuevo correo electronico: "; getline(cin, correo_electronico);
				c.setcorreo_electronico(correo_electronico);
				break;
			case 7:
				cout << "\ningrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				c.setfechaingreso(fechaingreso);
				break;
			}
			c.update_clientes(opcion2, id_cliente);
			repetir();

			break;
		case 4: 
			system("cls");
			c.leer_clientes();
			cout << endl << endl;
			cout << "ingrese el id cliente del registro que desea eliminar: "; cin >> id_cliente;
			c.eliminar_clientes(id_cliente);
			repetir();
			break;
		}
	}

	/// <summary>
	/// ///////////////////////////////////////
	/// </summary>

	if (opcion == 4)
	{
		system("cls");
		cout << "_______________ TABLA DE MARCAS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
			case 1:
				system("cls");
				m.leer_marcas();
				repetir();
				break;
			case 2:
				system("cls");
				cout << "ingrese la marca: ";
				getline(cin, marca);
				m = marcas(marca);
				m.insert_marcas();
				repetir();
				break;
			case 3:
				system("cls");
				m.leer_marcas();
				cout << endl << endl;
				cout << "ingrese el id del registro a modificar: ";
				cin >> idmarca;
				cin.ignore();
				cout << "ingrese la nueva marca: ";
				getline(cin, marca);
				m = marcas(marca);
				m.update_marcas(idmarca);
				repetir();
				break;
			case 4:
				system("cls");
				m.leer_marcas();
				cout << endl << endl;
				cout << "ingrese el id del registro a eliminar: ";
				cin >> idmarca;
				cin.ignore();
				m.eliminar_marcas(idmarca);
				repetir();
				break;
		}
	}

	////
	//// //////////////////////////
	////

	if (opcion == 5)
	{
		system("cls");
		cout << "_______________ TABLA DE PROVEEDORES _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			pro.leer_proveedores();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "\nIngrese proveedor: ";
			getline(cin, proveedor);
			cout << "\nIngrese nit: ";
			getline(cin, nit);
			cout << "\nIngrese direccion: ";
			getline(cin, direccion);
			cout << "\nIngrese telefono: ";
			cin >> telefono;
			cin.ignore();

			pro = proveedores(proveedor, nit, direccion, telefono);
			pro.insert_proveedores();
			repetir();
			break;
		case 3:

			system("cls");
			pro.leer_proveedores();
			cout << endl << endl;
			cout << "ingrese id proveedor del registro a modificar: "; cin >> idproveedor;
			opcion2 = pro.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo proveedor: "; getline(cin, proveedor);
				pro.setproveedor(proveedor);
				break;
			case 2:
				cout << "\ningrese el nuevo nit: "; getline(cin, nit);
				pro.setnit(nit);
				break;
			case 3:
				cout << "\ningrese la nueva direccion: "; getline(cin, direccion);
				pro.setdireccion(direccion);
				break;
			case 4:
				cout << "\ningrese el nuevo telefono: "; cin >> telefono; cin.ignore();
				pro.settelefono(telefono);
				break;
			}
			pro.update_proveedores(opcion2, idproveedor);
			repetir();

			break;
		case 4:
			system("cls");
			pro.leer_proveedores();
			cout << endl << endl;
			cout << "ingrese el id proveedor del registro que desea eliminar: "; cin >> idproveedor;
			pro.eliminar_proveedores(idproveedor);
			repetir();
			break;
		}
	}

	/// <summary>
	/// ///////////////////////////////
	/// </summary>

	if (opcion == 6)
	{
		system("cls");
		cout << "_______________ TABLA DE PRODUCTOS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			prod.leer_productos();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "\nIngrese producto: ";
			getline(cin, productos);
			cout << "\nIngrese idmarca: ";
			cin >> idmarca;	cin.ignore();
			cout << "\nIngrese descripcion: ";
			getline(cin, descripcion);
			cout << "\nIngrese imagen: ";
			getline(cin, imagen);
			cout << "\ningrese Precio Costo: ";
			cin >> precio_costo;	cin.ignore();
			cout << "\nIngrese Precio Venta: ";
			cin >> precio_venta;	cin.ignore();
			cout << "\nIngrese Existencias: ";
			cin >> existencia;	cin.ignore();
			cout << "\nIngrese Fecha de Ingreso (anio/mes/dia hora:minuto:segundo): ";
			getline(cin, fechaingreso);

			prod = producto(productos, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso);
			prod.insert_producto();
			repetir();
			break;
		case 3:

			system("cls");
			prod.leer_productos();
			cout << endl << endl;
			cout << "ingrese id producto del registro a modificar: "; cin >> idproducto;
			opcion2 = prod.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo producto: "; getline(cin, productos);
				prod.setproductos(productos);
				break;
			case 2:
				cout << "\ningrese el nuevo idmarca "; cin >> idmarca;	cin.ignore();
				prod.setidmarca(idmarca);
				break;
			case 3:
				cout << "\ningrese la nueva descripcion: "; getline(cin, descripcion);
				prod.setdescripcion(descripcion);
				break;
			case 4:
				cout << "\ningrese la nueva imagen: "; getline(cin, imagen);
				prod.setimagen(imagen);
				break;
			case 5:
				cout << "\ningrese el nuevo precio costo: "; cin >> precio_costo; cin.ignore();
				prod.setprecio_costo(precio_costo);
				break;
			case 6:
				cout << "\ningrese el nuevo precio venta: "; cin >> precio_venta; cin.ignore();
				prod.setprecio_venta(precio_venta);
				break;
			case 7:
				cout << "\ningrese la nueva cantidad de existencias: "; cin >> existencia; cin.ignore();
				prod.setexistencias(existencia);
				break;
			case 8:
				cout << "\ingrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				prod.setfecha_ingreso(fechaingreso);
				break;
			}
			prod.update_productos(opcion2,idproducto);
			repetir();

			break;
		case 4:
			system("cls");
			prod.leer_productos();
			cout << endl << endl;
			cout << "ingrese el id producto del registro que desea eliminar: "; cin >> idproducto;
			prod.eliminar_productos(idproducto);
			repetir();
			break;
		}
	}
	if (opcion == 7)
	{
		system("cls");
		cout << "_______________ MAESTRO DETALLE DE COMPRAS _______________" << endl;
		opciones();
		cout << "ingrese la opcion que desea: ";
		cin >> opcion2;
		cin.ignore();
		switch (opcion2)
		{
		case 1:
			system("cls");
			Mc.leer_compras();
			repetir();
			break;
		case 2:
			system("cls");
			cout << "\nIngrese numero de orden de compra: ";
			cin >> no_orden_compra; cin.ignore();
			cout << "\nIngrese el id proveedor: ";
			cin >> idproveedor;	cin.ignore();
			cout << "\nIngrese la fecha de orden: ";
			getline(cin, fecha_orden);
			cout << "\nIngrese la fecha de ingreso (anio/mes/dia hora:minuto:segundo): ";
			getline(cin, fechaingreso);
			cout << "\ningrese id compra: ";
			cin >> idcompra;	cin.ignore();
			cout << "\nIngrese id producto: ";
			cin >> idproducto;	cin.ignore();
			cout << "\nIngrese cantidad: ";
			cin >> cantidad;	cin.ignore();
			cout << "\nIngrese el precio costo unitario: ";
			cin >> precio_costo_unitario; cin.ignore();

			Mc = Maestro_compras(no_orden_compra, idproveedor, fecha_orden, fechaingreso);
			//prod = producto(productos, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso);
			Mc.insert_compras();
			dc = detalle_compras(idcompra, idproducto, cantidad, precio_costo_unitario);
			dc.insert_compras_detalle();
			repetir();
			break;

		case 3:
			system("cls");
			Mc.leer_compras();
			cout << endl << endl;
			cout << "ingrese id producto del registro a modificar: "; cin >> idcompra;
			opcion2 = Mc.datos_modificar();
			switch (opcion2)
			{
			case 1:
				cout << "\ningrese el nuevo numero de orden de compra: "; cin >> no_orden_compra; cin.ignore();
				Mc.setno_orden_compra(no_orden_compra);
				break;
			case 2:
				cout << "\ningrese el nuevo id proveedor "; cin >> idproveedor; cin.ignore();
				prod.setidmarca(idmarca);
				break;
			case 3:
				cout << "\ningrese la nueva fecha de orden: "; getline(cin, fecha_orden);
				Mc.setfecha_orden(fecha_orden);
				break;
			case 4:
				cout << "\ningrese la nueva fecha de ingreso (anio/mes/dia hora:minuto:segundo): "; getline(cin, fechaingreso);
				Mc.setfechaingreso(fechaingreso);
				break;
			case 5:
				cout << "\ningrese el nuevo id compra: "; cin >> idcompra; cin.ignore();
				dc.setidcompra(idcompra);
				break;
			case 6:
				cout << "\ningrese el id producto: "; cin >> idproducto; cin.ignore();
				dc.setidproducto(idproducto);
				break;
			case 7:
				cout << "\ningrese la nueva cantidad: "; cin >> cantidad; cin.ignore();
				dc.setcantidad(cantidad);
				break;
			case 8:
				cout << "\ingrese el nuevo precio costo unitario: "; cin >> precio_costo_unitario;
				dc.setprecio_costo_unitario(precio_costo_unitario);
				break;
			}
			Mc.update_compras(opcion2, idcompra);
			dc.update_compras_detalle(opcion2, idcompra);
			repetir();

			
		}		
	}
}


/// <summary>
/// ///////////////////////////////////
/// </summary>


void repetir()
{
	string opc;
	cout << endl << endl << "Desea probar otra opcion (s/n): ";
	cin >> opc;
	cin.ignore();
	if (opc == "S" || opc == "s")
	{
		system("cls");
		menu();
	}
}

int main()
{
	menu();
}

