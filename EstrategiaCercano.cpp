#include "EstrategiaCercano.h"
#include "CampoDeJuego.h"

EstrategiaCercano::EstrategiaCercano(){
	nombre = "EstrategiaCercano";
}

EstrategiaCercano::~EstrategiaCercano(){
}

string EstrategiaCercano::getNombre(){
	return nombre;
}

void EstrategiaCercano::ejecutarEstrategia(CampoDeJuego* campo, Linea* ll){
	cout << "\nEjecutando la estrategia de juego cercano\n\n";
	int f1 = 0, c1 = 0, f2=0, c2=0;
	bool jugadaLista = false;
	fil = campo->getFilas();
	col = campo->getColumnas();

	// en el objeto ll viene almacenada la ultima linea que dibujo el usuario
	f1 = ll->getF1();
	f2 = ll->getF2();
	c1 = ll->getC1();
	c2 = ll->getC2();
	

	//Se revisa primero el cuadrado de un lado
	if (revisarCuadro(campo, ll)) {
		//se completo un cuadrado
	}

	else {
		if (f1 + 2 >= fil) {
			//Se sale de la matriz
		}
		else {
			if (campo->hacerLinea(f1, c1, f1 + 2, c1)) {
				ll->setF1(f1);
				ll->setC1(c1);
				ll->setF2(f1 + 2);
				ll->setC2(c1);
				jugadaLista = true;
			}
		}

		if (f1 - 2 < 0 || jugadaLista) {
			//Se sale de la matriz o la jugada esta lista
		}
		else {
			if (campo->hacerLinea(f1, c1, f1 - 2, c1)) {
				ll->setF1(f1);
				ll->setC1(c1);
				ll->setF2(f1 - 2);
				ll->setC2(c1);
				jugadaLista = true;
			}
		}

		if (c1 + 2 >= fil || jugadaLista) {
			//Se sale de la matriz o la jugada esta lista
		}
		else {
			if (campo->hacerLinea(f1, c1, f1, c1 + 2)) {
				ll->setF1(f1);
				ll->setC1(c1);
				ll->setF2(f1);
				ll->setC2(c1 + 2);
				jugadaLista = true;
			}
		}

		if (c1 - 2 < 0 || jugadaLista) {
			//Se sale de la matriz  o la jugada esta lista
		}
		else {
			if (campo->hacerLinea(f1, c1, f1, c1 - 2)) {
				ll->setF1(f1);
				ll->setC1(c1);
				ll->setF2(f1);
				ll->setC2(c1 - 2);
				jugadaLista = true;
			}
		}

		if (!jugadaLista) {
			//Se sale de la matriz
			cout << "No hay posiblidad de hacer un juego cercano, por lo tanto: \n";
			EstrategiaAleatoria().ejecutarEstrategia(campo, ll);
			Sleep(2000);
		}
	}
}
