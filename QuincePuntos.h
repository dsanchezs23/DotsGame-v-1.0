#pragma once
#include "CampoAbstracto.h"

class QuincePuntos : public CampoAbstracto {
public:
	QuincePuntos();
	virtual ~QuincePuntos();
	int getFilas();
	int getColumnas();
	string getCodigo();
};

