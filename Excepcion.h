#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Excepcion {
protected:
	int minimo;
	int maximo;
public:
	Excepcion(int, int);
	virtual ~Excepcion();
	virtual string toString() = 0;
};

