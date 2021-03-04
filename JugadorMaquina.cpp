#include "JugadorMaquina.h"

JugadorMaquina::JugadorMaquina() : JugadorAbstracto("Maquina") {
	est = NULL;
}

JugadorMaquina::~JugadorMaquina(){
	delete est;
}

void JugadorMaquina::mostrarEstrategias(){

	cout  << "\n\t----Estrategias de la maquina----\n";
	cout << "\n1- Juego aleatorio";
	cout << "\n2- Juego cercano";
	cout << "\n3- Juego periferico";
	cout << "\n4- Juego central";
	cout << "\n5- Juego islas";
	cout << "\nOpcion: ";
	escogerEstrategia();
}

void JugadorMaquina::escogerEstrategia(){
	int opc = 0;
	cin >> opc;
	if (opc == 1)
		est = new EstrategiaAleatoria();
	else if (opc == 2)
		est = new EstrategiaCercano();
	else if (opc == 3)
		est = new EstrategiaPeriferico();
	else if (opc == 4)
		est = new EstrategiaCentral();
	else if (opc == 5)
		est = new EstrategiaIslas();
	else
		cout << "Error\n";
}

void JugadorMaquina::realizarJugada(CampoDeJuego* cam, Linea* lin){
	est->ejecutarEstrategia(cam, lin);
}

string JugadorMaquina::toString(){
	stringstream x;

	x << "\n" << nombre;
	x << "\n";

	return string();
}


