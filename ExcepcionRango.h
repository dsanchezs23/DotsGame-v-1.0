#pragma once
#include "Excepcion.h"

class ExcepcionRango :public Excepcion {
public:
	ExcepcionRango(int, int);
	~ExcepcionRango();
	string toString();
};
