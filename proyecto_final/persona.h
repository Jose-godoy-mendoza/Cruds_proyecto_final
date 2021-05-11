#pragma once
#include <iostream>
using namespace std;

class persona
{
protected: string nombres, apellidos, fechaingreso;
		 int telefono = 0, genero=0;
protected:
	persona()
	{
	}
	persona(string nom, string ape, string fein, int tel, int gen)
	{
		nombres = nom;	apellidos = ape;	fechaingreso = fein;	 telefono = tel;	genero = gen;
	}

};