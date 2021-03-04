#include "EstrategiaIslas.h"
#include "CampoDeJuego.h"

EstrategiaIslas::EstrategiaIslas(){
	nombre = "EstrategiaIslas";
}

EstrategiaIslas::~EstrategiaIslas(){
}

string EstrategiaIslas::getNombre(){
	return nombre;
}

void EstrategiaIslas::ejecutarEstrategia(CampoDeJuego* campo, Linea* ll) {
	cout << "\nEjecutando la estrategia de juego de islas\n\n";
	bool jugadaLista = false;

	if (revisarCuadro(campo, ll)) {
		//Completo un cuadrado
	}
	else {
		int x1 = ll->getF1();
		int y1 = ll->getC1();
		int x2 = ll->getF2();
		int y2 = ll->getC2();
		//bool linea1 = false, bool linea2 = false, bool linea3 = false, bool linea4 = false, bool linea5 = false, bool linea6 = false;
		int p1 = 0, p2 = 0;
		int fil = campo->getFilas();
		int col = campo->getColumnas();
		int n1 = 0, m1 = 0, n2 = 0, m2 = 0;

		p1 = Arbitro::obtenerPuntoFila(x1, x2);
		p2 = Arbitro::obtenerPuntoColumna(y1, y2);

		// primero se verifica si la linea que puso el jugador previamente es horizontal o vertical
		if (x1 == x2) { //linea en fila (la que se hizo antes)
			//Se hace primero el cuadrado de un lado
			if (p1 - 1 < 0 || p2 - 1 < 0 || p2 + 1 >= col) {
				//Se sale de la matriz
			}
			else {
				if (campo->retornaMatriz()[p1 - 1][p2 - 1] == " ") {
					n1 = p1;
					m1 = p2 - 1;
					n2 = p1 - 2;
					m2 = p2 - 1;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}

				}
				if (campo->retornaMatriz()[p1 - 1][p2 + 1] == " " && !jugadaLista) {
					n1 = p1;
					m1 = p2 + 1;
					n2 = p1 - 2;
					m2 = p2 + 1;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1 - 2][p2] == " " && !jugadaLista) {
					n1 = p1 - 2;
					m1 = p2 - 1;
					n2 = p1 - 2;
					m2 = p2 + 1;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
			}
			if (p1 + 1 >= fil || p2 + 1 >= col || p2 - 1 < 0 || jugadaLista) {
				//Se sale de la matriz
			}
			else {
				//Ahora se hace el cuadrado del otro lado
				if (campo->retornaMatriz()[p1 + 1][p2 + 1] == " ") {
					n1 = p1;
					m1 = p2 + 1;
					n2 = p1 + 2;
					m2 = p2 + 1;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1 + 1][p2 - 1] == " " && !jugadaLista) {
					n1 = p1;
					m1 = p2 + 1;
					n2 = p1 + 2;
					m2 = p2 - 1;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1 + 2][p2] == " " && !jugadaLista) {
					n1 = p1 + 2;
					m1 = p2 - 1;
					n2 = p1 + 2;
					m2 = p2 + 1;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
			}
		}

		else {//linea en columna (la que se hizo antes)
			//Se hace primero el cuadrado de un lado
			if (p1 - 1 < 0 || p1 + 1 >= fil || p2 + 1 >= col || jugadaLista) {
				//Se sale de la matriz
			}
			else {
				if (campo->retornaMatriz()[p1 + 1][p2 + 1] == " ") {
					n1 = p1 + 1;
					m1 = p2;
					n2 = p1 + 1;
					m2 = p2 + 2;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1 - 1][p2 + 1] == " " && !jugadaLista) {
					n1 = p1 - 1;
					m1 = p2;
					n2 = p1 - 1;
					m2 = p2 + 2;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1][p2 + 2] == " " && !jugadaLista) {
					n1 = p1 - 1;
					m1 = p2 + 2;
					n2 = p1 + 2;
					m2 = p2 + 2;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}

			}
			if (p1 - 1 < 0 || p2 - 1 < 0 || p1 + 1 >= fil || jugadaLista) {
				//Se sale de la matriz
			}
			else {
				//Ahora se revisa el cuadrado del otro lado
				if (campo->retornaMatriz()[p1 - 1][p2 - 1] == " ") {
					n1 = p1 - 1;
					m1 = p2 - 2;
					n2 = p1 - 1;
					m2 = p2;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1 + 1][p2 - 1] == " " && !jugadaLista) {
					n1 = p1 + 1;
					m1 = p2 - 2;
					n2 = p1 + 1;
					m2 = p2;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
				if (campo->retornaMatriz()[p1][p2 - 2] == " " && !jugadaLista) {
					n1 = p1 - 1;
					m1 = p2 - 2;
					n2 = p1 + 1;
					m2 = p2 - 2;
					if (campo->hacerLinea(n1, m1, n2, m2)) {
						ll->setF1(n1);
						ll->setF1(m1);
						ll->setF1(n2);
						ll->setF1(m2);
						jugadaLista = true;
					}
				}
			}
		}
		if (!jugadaLista) {
			cout << "No hay posiblidad de hacer un juego en islas, por lo tanto: \n";
			EstrategiaAleatoria().ejecutarEstrategia(campo, ll);
			Sleep(2000);
		}
	}
}
