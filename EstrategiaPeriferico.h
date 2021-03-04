#pragma once
#include "Estrategia.h"
class EstrategiaPeriferico : public Estrategia{
public:
	EstrategiaPeriferico();
	virtual ~EstrategiaPeriferico();
	//---------------------------------------
	string getNombre();
	void ejecutarEstrategia(CampoDeJuego*, Linea*);
};

