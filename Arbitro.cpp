#include "Arbitro.h"
#include "CampoDeJuego.h"

bool Arbitro::verificarLinea(int x1, int y1, int x2, int y2, CampoDeJuego* campo){
	if (x1 % 2 != 0 || y1 % 2 != 0 || x2 % 2 != 0 || y2 % 2 != 0)
		return false;// numeros invalidos
	if ((x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) && (x1 >= campo->getFilas() || x2 >= campo->getFilas() || y1 >= campo->getColumnas() || y2 >= campo->getColumnas()))
		return false;//verificar para que no se salga de las filas o columnas
	if (campo->retornaMatriz()[x1][y1] == "*" && campo->retornaMatriz()[x2][y2] == "*") { //verificar que es una posicion valida en el tablero
		if ((x1 == x2 || y1 == y2) && ((x1 - x2 == 2 || x2 - x1 == 2) || (y1 - y2 == 2 || y2 - y1 == 2))) {//Verificar que sea una linea valida
			return true; //linea permitida
		}
		else {
			return false; //linea no permitida
		}
	}
	else {
		return false; //posision no permitida en el tablero
	}
	return false;
}

int Arbitro::obtenerPuntoFila(int x1, int x2){
	if (x1 - x2 == 2)
		return x2 + 1;
	else if(x2 - x1 == 2)
		return x1 + 1;
	else //son iguales
		return x1;
}

int Arbitro::obtenerPuntoColumna(int y1, int y2){
	if (y1 - y2 == 2)
		return y2 + 1;
	else if (y2 - y1 == 2)
		return y1 + 1;
	else //son iguales
		return y1;
}

void Arbitro::reglas(){
	cout << "\t\t-------------------------------";
	cout << "\n\t\t|      Reglas del juego       |";
	cout << "\n\t\t-------------------------------";
	cout << "\n\n\n1- Se debe seleccionar un campo de juego este puede ser de seis, nueve o quince puntos\n"
		 << "o una combinacion deseada entre estos tres";
	cout << "\n\n2-  juegan dos oponentes (la maquina u otro usuario) y cada uno, en su turno va uniendo puntos\n"
		<< "de esta forma hace una linea entre los puntos, ya sea dos puntos verticales o dos puntos horizontales(nunca inclinados).\n"
		<< "Puede empezar por donde se deseé ";
	cout << "\n\n3- Al ir haciendo lineas, se hacen cuadros, el que mas cuadros haga al final, ganara\n\n";
}
