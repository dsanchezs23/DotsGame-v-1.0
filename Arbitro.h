#pragma once
#include <iostream>

using namespace std;

class CampoDeJuego;

class Arbitro{
public:
	static bool verificarLinea(int, int, int, int, CampoDeJuego*);
	static int obtenerPuntoFila(int, int);
	static int obtenerPuntoColumna(int, int);
	static void reglas();
};

