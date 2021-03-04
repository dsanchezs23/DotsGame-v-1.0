#pragma once
#include "CampoAbstracto.h"

class SeisPuntos : public CampoAbstracto {
public:
	SeisPuntos();
	virtual ~SeisPuntos();
	int getFilas();
	int getColumnas();
	string getCodigo();
};

