#pragma once
#include "Estrategia.h"

class EstrategiaAleatoria : public Estrategia{
public:
	EstrategiaAleatoria();
	virtual ~EstrategiaAleatoria();
	//------------------------------
	string getNombre();
	void ejecutarEstrategia(CampoDeJuego*, Linea*);
};

