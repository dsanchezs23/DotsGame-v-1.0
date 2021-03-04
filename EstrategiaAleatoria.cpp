#include "EstrategiaAleatoria.h"
#include "CampoDeJuego.h"

EstrategiaAleatoria::EstrategiaAleatoria(){
	nombre = "EstrategiaAleatoria";
}

EstrategiaAleatoria::~EstrategiaAleatoria(){
}

//------------------------------------------------------------------

string EstrategiaAleatoria::getNombre(){
	return nombre;
}

void EstrategiaAleatoria::ejecutarEstrategia(CampoDeJuego* campo, Linea* ll){
	cout << "\nEjecutando la estrategia aleatoria\n\n";
	fil = campo->getFilas();
	col = campo->getColumnas();
	bool jugadaLista = false;
	
	if (revisarCuadro(campo, ll)) {
		//se completo un cuadrado
	}

	else {
		for (int i = 0; i < fil; i++) {
			if (jugadaLista)
				break;
			else {
				for (int j = 0; j < col; j++) {
					if (campo->hacerLinea(i, j, i, j + 2) && (j + 2) < col) {
						jugadaLista = true;
						ll->setF1(i);
						ll->setC1(j);
						ll->setF2(i);
						ll->setC2(j + 2);
						break;
					}
					else if (campo->hacerLinea(i, j, i + 2, j) && (i + 2) < fil) {
						jugadaLista = true;
						ll->setF1(i);
						ll->setC1(j);
						ll->setF2(i + 2);
						ll->setC2(j);
						break;
					}
				}
			}
		}
	}

}
