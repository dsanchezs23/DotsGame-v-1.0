#include "ExcepcionRango.h"

ExcepcionRango::ExcepcionRango(int min, int max) :Excepcion(min, max) {
}

ExcepcionRango::~ExcepcionRango() {
}

string ExcepcionRango::toString() {
	stringstream x;

	x << "\nEl valor ingresado no es valido " << endl;
	x << "Debe estar entre " << minimo << " y " << maximo << endl;

	return x.str();
}
