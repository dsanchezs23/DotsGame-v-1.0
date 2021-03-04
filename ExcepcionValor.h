#pragma once
#include "Excepcion.h"
class ExcepcionValor :public Excepcion {
public:
	ExcepcionValor(int, int);
	~ExcepcionValor();
	string toString();
};

