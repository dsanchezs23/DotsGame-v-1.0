#pragma once
#include "CampoAbstracto.h"

using namespace std;

class ProcesaCompuesto {
private:
	/*ContenedorV* contVec;
	ContenedorM* contMat;
	int separador;*/
	string** matPr;
	int totalF;
	int totalC;
public:
	ProcesaCompuesto(string**&);
	virtual ~ProcesaCompuesto();
	void crearMatriz(int, int, CampoAbstracto**, int);
	void matSeis();
	void matNueve();
	void matQuince();
	string** getMat();
};
