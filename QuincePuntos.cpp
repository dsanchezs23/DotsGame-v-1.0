#include "QuincePuntos.h"

QuincePuntos::QuincePuntos() {
	filas = 9;
	columnas = 5;//esto para que se puedan dibujar las lineas entre los espacios
	codigo = "quince puntos";
}

QuincePuntos::~QuincePuntos() {
}

int QuincePuntos::getFilas() {
	return filas;
}

int QuincePuntos::getColumnas() {
	return columnas;
}

string QuincePuntos::getCodigo() {
	return codigo;
}

