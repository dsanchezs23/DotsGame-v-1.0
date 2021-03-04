#pragma once
#include "EstrategiaAleatoria.h"
#include "EstrategiaCentral.h"
#include "EstrategiaCercano.h"
#include "EstrategiaIslas.h"
#include "EstrategiaPeriferico.h"
#include "Linea.h"

using namespace std;

class JugadorAbstracto{
protected:
	string nombre;
	int p1;
	int p2;
	int p3;
	int p4;
	int cuadrosCompletos;
public:
	JugadorAbstracto(string);
	virtual ~JugadorAbstracto();
	void setNombre(string);
	string getNombre();
	void setPunto();
	int getPuntos();
	void verPuntuacion();
	virtual void realizarJugada(CampoDeJuego*, Linea*) = 0;
	virtual string toString() = 0;
};

