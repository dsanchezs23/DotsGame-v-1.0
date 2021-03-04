#include "NuevePuntos.h"

NuevePuntos::NuevePuntos() {
	filas = 5;
	columnas = 5;//esto para que se puedan dibujar las lineas entre los espacios
	codigo = "nueve puntos";
}

NuevePuntos::~NuevePuntos() {
}

int NuevePuntos::getFilas() {
	return filas;
}

int NuevePuntos::getColumnas() {
	return columnas;
}

string NuevePuntos::getCodigo() {
	return codigo;
}

