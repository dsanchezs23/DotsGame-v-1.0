#include "Suscripcion.h"

Suscripcion::Suscripcion(EmpresaDots* es, Usuario* u){
	emp = es;
	codigo = es->getCodigo();
	usu = u;
	//Agregando el observador al sujeto
	emp->attach(this);
}

Suscripcion::~Suscripcion(){
}

int Suscripcion::getCodigoEmpresa(){
	return emp->getCodigo();
}

string Suscripcion::toString(){
	stringstream x;

	x << "\nHola " << usu->getNombre()
	  << ", el codigo de la empresa Dots para el dia de hoy es: " << emp->getCodigo() << endl;

	return x.str();
}

