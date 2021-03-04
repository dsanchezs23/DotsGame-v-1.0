#pragma once
#include "Estrategia.h"

class EstrategiaCercano :  public Estrategia{
public:
	EstrategiaCercano();
	virtual ~EstrategiaCercano();
	//--------------------------------------
	string getNombre();
	void ejecutarEstrategia(CampoDeJuego*, Linea*);
};

