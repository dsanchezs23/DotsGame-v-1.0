#pragma once
#include <iostream>
#include <sstream>
#include "EmpresaDots.h"
#include "Usuario.h"
#include <fstream>
#include <string>

using namespace std;

class EmpresaDots; //Declaracion previa

class Suscripcion{//Este clase es el observer, observa a la empresa Dots
private:
	int codigo;
	EmpresaDots* emp;
	Usuario* usu;
public:
	Suscripcion(EmpresaDots*, Usuario*);
	virtual ~Suscripcion();
	int getCodigoEmpresa();
	string toString();
};

