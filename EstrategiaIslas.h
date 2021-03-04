#pragma once
#include "Estrategia.h"

class EstrategiaIslas : public Estrategia{
public:
	EstrategiaIslas();
	virtual ~EstrategiaIslas();
	//-------------------------------------
	string getNombre();
	void ejecutarEstrategia(CampoDeJuego*, Linea*);
};

