#include "EstrategiaPeriferico.h"
#include "CampoDeJuego.h"

EstrategiaPeriferico::EstrategiaPeriferico(){
	nombre = "EstrategiaPeriferico";
}

EstrategiaPeriferico::~EstrategiaPeriferico(){
}

string EstrategiaPeriferico::getNombre(){
	return nombre;
}

void EstrategiaPeriferico::ejecutarEstrategia(CampoDeJuego* campo, Linea* ll){
	cout << "\nEjecutando la estrategia periferica\n\n";
	int filas = campo->getFilas();;
	int columnas = campo->getColumnas();
	fil = 0;
	col = 0;
	bool jugadaLista = false;


	if (filas % 2 == 0) {
		fil = (filas / 2);
	}
	else {
		fil = (filas / 2) + 1;
	}
	if (columnas % 2 == 0) {
		col = (columnas / 2);
	}
	else {
		col = (columnas / 2) + 1;
	}

	if (revisarCuadro(campo, ll)) {
		//se completo un cuadrado
	}

	else {
		for (int i = 0; i < fil; i++) {
			if (campo->hacerLinea(i, 0, i + 2, 0)) {
				ll->setF1(i);
				ll->setC1(0);
				ll->setF2(i + 2);
				ll->setC2(0);
				jugadaLista = true;
				break;
			}
		}
		if (!jugadaLista) {
			for (int i = 0; i < fil; i++) {
				if (campo->hacerLinea(i, col - 2, i + 2, col - 2)) {
					ll->setF1(i);
					ll->setC1(col - 2);
					ll->setF2(i + 2);
					ll->setC2(col - 2);
					jugadaLista = true;
					break;
				}
			}
		}

		if (!jugadaLista) {
			for (int j = 0; j < col; j++) {
				if (campo->hacerLinea(0, j, 0, j + 2)) {
					ll->setF1(0);
					ll->setC1(j);
					ll->setF2(0);
					ll->setC2(j + 2);
					jugadaLista = true;
					break;
				}
			}
		}

		if (!jugadaLista) {
			for (int j = 0; j < col; j++) {
				if (campo->hacerLinea(fil - 2, j, fil - 2, j + 2)) {
					ll->setF1(fil - 2);
					ll->setC1(j);
					ll->setF2(fil - 2);
					ll->setC2(j + 2);
					jugadaLista = true;
					break;
				}
			}
		}

		if (!jugadaLista) {
			//Se sale de la matriz
			cout << "No hay posiblidad de hacer un juego periferico, por lo tanto: \n";
			EstrategiaAleatoria().ejecutarEstrategia(campo, ll);
			Sleep(2000);
		}
	}
}
