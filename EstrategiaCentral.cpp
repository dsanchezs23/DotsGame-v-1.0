#include "EstrategiaCentral.h"
#include "CampoDeJuego.h"

EstrategiaCentral::EstrategiaCentral(){
	nombre = "EstrategiaCentral";
}

EstrategiaCentral::~EstrategiaCentral(){
}

string EstrategiaCentral::getNombre(){
	return nombre;
}

void EstrategiaCentral::ejecutarEstrategia(CampoDeJuego* campo, Linea* ll){
	cout << "\nEjecutando la estrategia de juego central\n\n";

	fil = campo->getFilas() / 2;
	col = campo->getColumnas() / 2;
	bool jugadaLista = false;

	if (fil % 2 != 0)//para saber si queda en una posicion par
		fil++;
	if (col % 2 != 0)
		col++;

	if (revisarCuadro(campo, ll)) {
		//se completo un cuadrado
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (campo->hacerLinea(fil, col, fil, col + 2)) {
				ll->setF1(fil);
				ll->setC1(col);
				ll->setF2(fil);
				ll->setC2(col + 2);
				jugadaLista = true;
				break;
			}
			if (!jugadaLista) {
				if (campo->hacerLinea(fil, col, fil + 2, col)) {
					ll->setF1(fil);
					ll->setC1(col);
					ll->setF2(fil + 2);
					ll->setC2(col);
					jugadaLista = true;
					break;
				}
			}
			if (!jugadaLista) {
				if (campo->hacerLinea(fil, col, fil, col - 2)) {
					ll->setF1(fil);
					ll->setC1(col);
					ll->setF2(fil);
					ll->setC2(col - 2);
					jugadaLista = true;
					break;
				}
			}
			if (!jugadaLista) {
				if (campo->hacerLinea(fil, col, fil - 2, col)) {
					ll->setF1(fil);
					ll->setC1(col);
					ll->setF2(fil - 2);
					ll->setC2(col);
					jugadaLista = true;
					break;
				}
			}
			if (i == 0)
				fil -= 2;
			else if (i == 1)
				col += 2;
			else if (i == 2)
				fil += 2;
			else
				col -= 2;
		}

		if (!jugadaLista) {
			//Se sale de la matriz
			cout << "No hay posiblidad de hacer un juego central, por lo tanto: \n";
			EstrategiaAleatoria().ejecutarEstrategia(campo, ll);
			Sleep(2000);
		}
	}
}
