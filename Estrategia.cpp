#include "Estrategia.h"
#include "CampoDeJuego.h"

Estrategia::Estrategia(){
	fil = 0;
	col = 0;
}

Estrategia::~Estrategia(){
	//el campo se destruye en otro lugar
}

bool Estrategia::revisarCuadro(CampoDeJuego* campo, Linea* ll){
	int x1 = ll->getF1();
	int y1 = ll->getC1();
	int x2 = ll->getF2();
	int y2 = ll->getC2();
	int lineasSinHacer = 0;
	int p1 = 0, p2 = 0;
	int fil = campo->getFilas();
	int col = campo->getColumnas();
	int n1 = 0, m1 = 0, n2 = 0, m2 = 0;

	p1 = Arbitro::obtenerPuntoFila(x1, x2);
	p2 = Arbitro::obtenerPuntoColumna(y1, y2);

	// primero se verifica si la linea que puso el jugador previamente es horizontal o vertical
	if (x1 == x2) { //linea en fila (la que se hizo antes)
		//Se revisa primero el cuadrado de un lado
		if (p1 - 1 < 0 || p2 - 1 < 0 || p2 + 1 >= col) {
			//Se sale de la matriz
		}
		else {
			if (campo->retornaMatriz()[p1 - 1][p2 - 1] == " ") {
				lineasSinHacer++;
				n1 = p1;
				m1 = p2 - 1;
				n2 = p1 - 2;
				m2 = p2 - 1;
			}
			if (campo->retornaMatriz()[p1 - 1][p2 + 1] == " ") {
				lineasSinHacer++;
				n1 = p1;
				m1 = p2 + 1;
				n2 = p1 - 2;
				m2 = p2 + 1;
			}
			if (campo->retornaMatriz()[p1 - 2][p2] == " ") {
				lineasSinHacer++;
				n1 = p1 - 2;
				m1 = p2 - 1;
				n2 = p1 - 2;
				m2 = p2 + 1;
			}

			if (lineasSinHacer == 1) {
				if (campo->hacerLinea(n1, m1, n2, m2)) {
					ll->setF1(n1);
					ll->setC1(m1);
					ll->setF2(n2);
					ll->setC2(m2);
					return true;
				}
			}
		}
		if (p1 + 1 >= fil || p2 + 1 >= col || p2 - 1 < 0) {
			//Se sale de la matriz
		}
		else {
			lineasSinHacer = 0;
			//Ahora se revisa el cuadrado del otro lado
			if (campo->retornaMatriz()[p1 + 1][p2 + 1] == " ") {
				lineasSinHacer++;
				n1 = p1;
				m1 = p2 + 1;
				n2 = p1 + 2;
				m2 = p2 + 1;
			}
			if (campo->retornaMatriz()[p1 + 1][p2 - 1] == " ") {
				lineasSinHacer++;
				n1 = p1 ;
				m1 = p2 + 1;
				n2 = p1 + 2;
				m2 = p2 - 1;
			}
			if (campo->retornaMatriz()[p1 + 2][p2] == " ") {
				lineasSinHacer++;
				n1 = p1 + 2;
				m1 = p2 - 1;
				n2 = p1 + 2;
				m2 = p2 + 1;
			}
			if (lineasSinHacer == 1) {
				if (campo->hacerLinea(n1, m1, n2, m2)) {
					ll->setF1(n1);
					ll->setC1(m1);
					ll->setF2(n2);
					ll->setC2(m2);
					return true;
				}
			}
		}
	}

	else {//linea en columna (la que se hizo antes)
		lineasSinHacer = 0;
		//Se revisa primero el cuadrado de un lado
		if (p1 - 1 < 0 || p1 + 1 >= fil || p2 + 1 >= col) {
			//Se sale de la matriz
		}
		else {
			if (campo->retornaMatriz()[p1 + 1][p2 + 1] == " ") {
				lineasSinHacer++;
				n1 = p1 + 1;
				m1 = p2;
				n2 = p1 + 1;
				m2 = p2 + 2;
			}
			if (campo->retornaMatriz()[p1 - 1][p2 + 1] == " ") {
				lineasSinHacer++;
				n1 = p1 - 1;
				m1 = p2;
				n2 = p1 - 1;
				m2 = p2 + 2;
			}
			if (campo->retornaMatriz()[p1][p2 + 2] == " ") {
				lineasSinHacer++;
				n1 = p1 - 1;
				m1 = p2 + 2;
				n2 = p1 + 2;
				m2 = p2 + 2;
			}
			if (lineasSinHacer == 1) {
				if (campo->hacerLinea(n1, m1, n2, m2)) {
					ll->setF1(n1);
					ll->setC1(m1);
					ll->setF2(n2);
					ll->setC2(m2);
					return true;
				}
			}

		}
		if (p1 - 1 < 0 || p2 - 1 < 0 || p1 + 1 >= fil) {
			//Se sale de la matriz
		}
		else {
			lineasSinHacer = 0;
			//Ahora se revisa el cuadrado del otro lado
			if (campo->retornaMatriz()[p1 - 1][p2 - 1] == " ") {
				lineasSinHacer++;
				n1 = p1 - 1;
				m1 = p2 - 2;
				n2 = p1 - 1;
				m2 = p2;
			}
			if (campo->retornaMatriz()[p1 + 1][p2 - 1] == " ") {
				lineasSinHacer++;
				n1 = p1 + 1;
				m1 = p2 - 2;
				n2 = p1 + 1;
				m2 = p2;
			}
			if (campo->retornaMatriz()[p1][p2 - 2] == " ") {
				lineasSinHacer++;
				n1 = p1 - 1;
				m1 = p2 - 2;
				n2 = p1 + 1;
				m2 = p2 - 2;
			}
			if (lineasSinHacer == 1) {
				if (campo->hacerLinea(n1, m1, n2, m2)) {
					ll->setF1(n1);
					ll->setC1(m1);
					ll->setF2(n2);
					ll->setC2(m2);
					return true;
				}
			}
		}
	}

	return false;
}
