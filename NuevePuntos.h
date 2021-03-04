#pragma once
#include "CampoAbstracto.h"

class NuevePuntos : public CampoAbstracto {
public:
	NuevePuntos();
	virtual ~NuevePuntos();
	int getFilas();
	int getColumnas();
	string getCodigo();
};
