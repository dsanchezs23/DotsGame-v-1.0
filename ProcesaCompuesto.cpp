#include "ProcesaCompuesto.h"

ProcesaCompuesto::ProcesaCompuesto(string**& m) {
	matPr = m;
	totalF = 0;
	totalC = 0;
}

ProcesaCompuesto::~ProcesaCompuesto() {
}

void ProcesaCompuesto::crearMatriz(int fil, int col, CampoAbstracto** vec, int c) {
	int i = 0;
	matPr = new string * [fil];

	for (int i = 0; i < fil; i++) {
		matPr[i] = new string[col];
	}

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			matPr[i][j] = " ";
		}
	}
	while (i < c) {
		if (vec[i]->getCodigo() == "seis puntos") {
			matSeis();
		}
		else if (vec[i]->getCodigo() == "nueve puntos") {
			matNueve();
		}
		else if (vec[i]->getCodigo() == "quince puntos") {
			matQuince();
		}
		i++;
	}
}

void ProcesaCompuesto::matSeis() {
	bool sumaruno = false;
	int j = 0;

	//int i = posFila;
	for (int i = 0; i < 5; i++) {
		if (i % 2 != 0) {
			//son espacios
		}
		else {
			if (totalC % 2 == 0 && totalC != 0) {//Esto es para arreglar problema de union
				sumaruno = true;
				j = totalC + 1;
				for (j; j <= totalC + 4; j++) {
					if (j % 2 != 0) {
						//son espacios
					}
					else {
						matPr[i][j] = "*";
					}
				}
			}
			else {
				j = totalC;
				for (j; j <= totalC + 3; j++) {
					if (j % 2 != 0) {
						//son espacios
					}
					else {
						matPr[i][j] = "*";
					}
				}
			}
		}
	}
	if (totalF < 5)
		totalF = 5;
	totalC += 3;
	if (sumaruno)
		totalC++;
}

void ProcesaCompuesto::matNueve() {
	bool sumaruno = false;
	int j = 0;

	//int i = posFila;
	for (int i = 0; i < 5; i++) {
		if (i % 2 != 0) {
			//son espacios
		}
		else {
			if (totalC % 2 == 0 && totalC != 0) {//Esto es para arreglar problema de union
				sumaruno = true;
				j = totalC + 1;
				for (j; j <= totalC + 6; j++) {
					if (j % 2 != 0) {
						//son espacios
					}
					else {
						matPr[i][j] = "*";
					}
				}
			}
			else {
				j = totalC;
				for (j; j <= totalC + 5; j++) {
					if (j % 2 != 0) {
						//son espacios
					}
					else {
						matPr[i][j] = "*";
					}
				}
			}
		}
	}
	if (totalF < 5)
		totalF = 5;
	totalC += 5;
	if (sumaruno)
		totalC++;
}

void ProcesaCompuesto::matQuince() {
	bool sumaruno = false;
	int j = 0;

	//int i = posFila;
	for (int i = 0; i < 9; i++) {
		if (i % 2 != 0) {
			//son espacios
		}
		else {
			if (totalC % 2 == 0 && totalC != 0) {//Esto es para arreglar problema de union
				sumaruno = true;
				j = totalC + 1;
				for (j; j <= totalC + 6; j++) {
					if (j % 2 != 0) {
						//son espacios
					}
					else {
						matPr[i][j] = "*";
					}
				}
			}
			else {
				j = totalC;
				for (j; j <= totalC + 5; j++) {
					if (j % 2 != 0) {
						//son espacios
					}
					else {
						matPr[i][j] = "*";
					}
				}
			}
		}
	}
	if (totalF < 9)
		totalF = 9;
	totalC += 5;
	if (sumaruno)
		totalC++;
}

string** ProcesaCompuesto::getMat() {
	return matPr;
}

