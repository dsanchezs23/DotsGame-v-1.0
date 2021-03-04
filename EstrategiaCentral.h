#pragma once
#include "Estrategia.h"

class EstrategiaCentral : public Estrategia{
public:
	EstrategiaCentral();
	virtual ~EstrategiaCentral();
	//--------------------------------------
	string getNombre();
	void ejecutarEstrategia(CampoDeJuego*, Linea*);
};

