#pragma once
#include "JugadorAbstracto.h"

class JugadorMaquina : public JugadorAbstracto{
private:
	Estrategia* est;
public:
	JugadorMaquina();
	virtual ~JugadorMaquina();
	void mostrarEstrategias();
	void escogerEstrategia();
	void realizarJugada(CampoDeJuego*, Linea*);
	string toString();
};

