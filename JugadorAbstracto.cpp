#include "JugadorAbstracto.h"

JugadorAbstracto::JugadorAbstracto(string n){
	nombre = n;
	p1 = 0;
	p2 = 0;
	p3 = 0;
	p4 = 0;
	cuadrosCompletos = 0;
}

JugadorAbstracto::~JugadorAbstracto(){
}

void JugadorAbstracto::setNombre(string n){
	nombre = n;
}

string JugadorAbstracto::getNombre(){
	return nombre;
}

void JugadorAbstracto::setPunto(){
	cuadrosCompletos++;
}
int JugadorAbstracto::getPuntos() {
	return cuadrosCompletos;
}

void JugadorAbstracto::verPuntuacion(){
	cout << nombre << ": " << cuadrosCompletos;
}
