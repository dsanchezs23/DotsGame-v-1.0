#pragma once
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Linea.h"

using namespace std;

class CampoDeJuego;

class Estrategia{
protected:
	int fil;
	int col;
	string nombre;
public:
	Estrategia();
	virtual ~Estrategia();
	//-------------------------------------
	virtual string getNombre() = 0;
	virtual void ejecutarEstrategia(CampoDeJuego*, Linea*) = 0;
	bool revisarCuadro(CampoDeJuego*, Linea*);
};
