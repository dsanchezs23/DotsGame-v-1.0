#include "ExcepcionValor.h"

ExcepcionValor::ExcepcionValor(int min, int max) :Excepcion(min, max) {
}

ExcepcionValor::~ExcepcionValor() {
}

string ExcepcionValor::toString() {
	stringstream x;

	x << "\nDebe ingresar un numero\n";
	x << "Este debe estar entre " << minimo << " y " << maximo << endl;

	return x.str();
}
