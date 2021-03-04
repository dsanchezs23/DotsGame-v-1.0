#include "SeisPuntos.h"

SeisPuntos::SeisPuntos() {
	filas = 5;
	columnas = 3; //esto para que se puedan dibujar las lineas entre los espacios
	codigo = "seis puntos";
}

SeisPuntos::~SeisPuntos() {
}

int SeisPuntos::getFilas() {
	return filas;
}

int SeisPuntos::getColumnas() {
	return columnas;
}

string SeisPuntos::getCodigo() {
	return codigo;
}

