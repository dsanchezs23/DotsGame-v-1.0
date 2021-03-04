#include "CampoDeJuego.h"

CampoDeJuego::CampoDeJuego() {
	filas = 0;
	columnas = 0;
	cantJugadas = 0;
	mat = NULL;
	cantCam = 0;
	vec = new CampoAbstracto * [10];
	codigo = "campo de juego";
	cantEle = 0;
	linea = new Linea(0, 0, 0, 0);
	ll = new Lista<Linea>();
	cuadroHecho = false;
}

CampoDeJuego::~CampoDeJuego() {
	for (int i = 0; i < filas; i++) {
		delete[] mat[i];
	}
	delete[] mat;
	delete vec;
	delete linea;
	delete ll;
}

//-----------------------------------------------------------------------------

void CampoDeJuego::ingresaCampo(CampoAbstracto* ca) {
	if (filas < ca->getFilas())
		filas = ca->getFilas();

	columnas += ca->getColumnas();
	vec[cantEle++] = ca;
}

void CampoDeJuego::crearCampo() {
	ProcesaCompuesto pc(mat);
	for (int i = 0; i < cantEle; i++) {
		if (i % 2 != 0)
			columnas += 2;
	}
	pc.crearMatriz(filas, columnas, vec, cantEle);
	mat = pc.getMat();
	contarJugadas();
}

string CampoDeJuego::campoDibujado(){
	stringstream x;
	//Enumerando columnas
	x << "   ";
	for (int j = 0; j < columnas; j++) {
		if (j % 2 == 0)
			if (j > 8)
				x << j;
			else
				x << j << " ";
	}
	x << "\n   ";
	for (int j = 0; j < columnas; j++) {
		if (j % 2 == 0)
			x << "- ";
	}
	x << "\n";
	for (int i = 0; i < filas; i++) {
		if (i % 2 == 0)
			x << i << "- ";
		else
			x << "   ";
		for (int j = 0; j < columnas; j++) {
			x << mat[i][j];
		}
		x << "\n";
	}
	return x.str();
}

void CampoDeJuego::jugarVsMaquina(Usuario* u1, JugadorMaquina* u2) {
	bool validacionJ1 = true;
	bool validacionJ2 = true;
	u1->setearPuntos();
	while (juegoSinFinalizar()) {
		validacionJ1 = true;
		validacionJ2 = true;
		while (validacionJ1) {
			system("cls");
			cout << campoDibujado();
			cout << "\n";
			u1->verPuntuacion();
			cout << "\n";
			u2->verPuntuacion();
			cout << "\n\nTurno de: " << u1->getNombre() << "\n";
			u1->realizarJugadaPersonal(linea);
			if (hacerLinea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()) && (linea->getF1() < filas, linea->getC1() < columnas, linea->getF2() < filas, linea->getC2() < columnas)) {
				validacionJ1 = false;
				cantJugadas--;
				ll->insertarFinal(new Linea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()));
				if (cuadroHecho) {
					u1->setPunto();
					if (juegoSinFinalizar()) {
						validacionJ1 = true;//para que siga jugando
						cout << "\nHa hecho un cuadrado, puede jugar otra vez\n\n";
						Sleep(1500);
					}
				}
				cuadroHecho = false;
			}
			else {
				cout << "\nError en la jugada\n";
				Sleep(1000);
			}
		}
		while (validacionJ2) {
			if (juegoSinFinalizar()) {
				system("cls");
				cout << campoDibujado();
				cout << "\n";
				u1->verPuntuacion();
				cout << "\n";
				u2->verPuntuacion();
				cout << "\n\nTurno de: " << u2->getNombre() << "\n";
				u2->realizarJugada(this, linea);
				validacionJ2 = false;
				cantJugadas--;
				ll->insertarFinal(new Linea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()));
				if (cuadroHecho) {
					u2->setPunto();
					if (juegoSinFinalizar()) {
						validacionJ2 = true; //para que siga jugando
						cout << "\nLa maquina ha hecho un cuadrado, puede jugar otra vez\n\n";
						Sleep(1500);
					}
				}
				cuadroHecho = false;
				//Es posible mandar las lista de lineas en las jugadas de la maquina para que guarde las jugadas
				//verificar si hace un cuadrado
			}
			else {
				validacionJ2 = false;
			}
		}

	}
	system("cls");
	cout << campoDibujado();
	cout << "\n\nJuego finalizado\n\n";
	// verificar puntos;
	if (u1->getPuntos() > u2->getPuntos())
		cout << u1->getNombre() << " es el/la ganador/a\n\n";
	else if (u2->getPuntos() > u1->getPuntos())
		cout << u2->getNombre() << " es el/la ganador/a\n\n";
	else
		cout << "Es un empate\n\n";
	system("pause");
}

void CampoDeJuego::JugarVsJugador(Usuario* u1, Usuario* u2){
	bool validacionJ1 = true;
	bool validacionJ2 = true;
	u1->setearPuntos();
	u2->setearPuntos();
	while (juegoSinFinalizar()) {
		validacionJ1 = true;
		validacionJ2 = true;
		while (validacionJ1) {
			system("cls");
			cout << campoDibujado();
			cout << "\n";
			u1->verPuntuacion();
			cout << "\n";
			u2->verPuntuacion();
			cout << "\n\nTurno de: " << u1->getNombre() << "\n";
			u1->realizarJugadaPersonal(linea);
			if (hacerLinea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()) && (linea->getF1() < filas, linea->getC1() < columnas, linea->getF2() < filas, linea->getC2() <  columnas)) {
				validacionJ1 = false;
				cantJugadas--;
				ll->insertarFinal(new Linea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()));
				if (cuadroHecho) {
					u1->setPunto();
					if (juegoSinFinalizar()) {
						validacionJ1 = true;//para que siga jugando
						cout << "\nHa hecho un cuadrado, puede jugar otra vez\n\n";
						Sleep(1500);
					}
				}
				cuadroHecho = false;
			}
			else {
				cout << "\nError en la jugada\n";
				Sleep(1000);
			}
		}
		while (validacionJ2) {
			if (juegoSinFinalizar()) {
				system("cls");
				cout << campoDibujado();
				cout << "\n";
				u1->verPuntuacion();
				cout << "\n";
				u2->verPuntuacion();
				cout << "\n\nTurno de: " << u2->getNombre() << "\n";
				u2->realizarJugadaPersonal(linea);
				if (hacerLinea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()) && (linea->getF1() < filas, linea->getC1() < columnas, linea->getF2() < filas, linea->getC2() < columnas)) {
					validacionJ2 = false;
					cantJugadas--;
					ll->insertarFinal(new Linea(linea->getF1(), linea->getC1(), linea->getF2(), linea->getC2()));
					if (cuadroHecho) {
						u2->setPunto();
						if (juegoSinFinalizar()) {
							validacionJ2 = true;//para que siga jugando
							cout << "\nHa hecho un cuadrado, puede jugar otra vez\n\n";
							Sleep(1500);
						}
					}
					cuadroHecho = false;
				}
				else {
					cout << "\nError en la jugada\n";
					Sleep(1000);
				}
			}
			else {
				validacionJ2 = false;
			}
		}

	}
	system("cls");
	cout << campoDibujado();
	cout << "\n\nJuego finalizado\n";
	// verificar puntos;
	if (u1->getPuntos() > u2->getPuntos())
		cout << u1->getNombre() << " es el/la ganador/a\n";
	else if (u2->getPuntos() > u1->getPuntos())
		cout << u2->getNombre() << " es el/la ganador/a\n";
	else
		cout << "Es un empate\n";
	system("pause");
}

bool CampoDeJuego::hacerLinea(int x1, int y1, int x2, int y2){
	if (Arbitro::verificarLinea(x1, y1, x2, y2, this)) {
		if (x1 == x2) { //linea en fila
			if (mat[Arbitro::obtenerPuntoFila(x1, x2)][Arbitro::obtenerPuntoColumna(y1, y2)] == " ") {// Espacio dispobible
				mat[Arbitro::obtenerPuntoFila(x1, x2)][Arbitro::obtenerPuntoColumna(y1, y2)] = "-";
				cuadroHechoVertical(Arbitro::obtenerPuntoFila(x1, x2), Arbitro::obtenerPuntoColumna(y1, y2));
			}
			else {
				return false; //linea hecha previamente
			}
		}
		else {//linea en columna
			if (mat[Arbitro::obtenerPuntoFila(x1, x2)][Arbitro::obtenerPuntoColumna(y1, y2)] == " ") {// Espacio dispobible
				mat[Arbitro::obtenerPuntoFila(x1, x2)][Arbitro::obtenerPuntoColumna(y1, y2)] = "|";
				cuadroHechoHorizontal(Arbitro::obtenerPuntoFila(x1, x2), Arbitro::obtenerPuntoColumna(y1, y2));
			}
			else {
				return false; //linea hecha previamente
			}
		}
		
		return true;
	}
	
	return false;
}

//-----------------------------------------------------------------------------

int CampoDeJuego::getFilas() {
	return filas;
}

int CampoDeJuego::getColumnas() {
	return columnas;
}

string** CampoDeJuego::retornaMatriz(){
	return mat;
}

string CampoDeJuego::getCodigo(){
	return codigo;
}

CampoAbstracto** CampoDeJuego::retornaVector(){
	return vec;
}

int CampoDeJuego::retornarCantElementos(){
	return cantEle;
}

Lista<Linea>* CampoDeJuego::getListaLinea(){
	return ll;
}

//-----------------------------------------------------------------------------

void CampoDeJuego::contarJugadas(){
	int f = 0;
	int c = 0;
	if (filas % 2 == 0) {
		f = (filas / 2);
	}
	else {
		f = (filas / 2) + 1;
	}
	if (columnas % 2 == 0) {
		c = (columnas / 2);
	}
	else {
		c = (columnas / 2) + 1;
	}

	int quitar = 0;
	for(int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (mat[i][j] == " ")
					quitar += 2;
			}
		}
	}
	cantJugadas = c*(2 * f - 1) - f;
	cantJugadas -= quitar;
}

int CampoDeJuego::getCantJugadas(){
	return cantJugadas;
}

//-----------------------------------------------------------------------------

bool CampoDeJuego::juegoSinFinalizar(){
	return cantJugadas != 0 ? true : false;
}

void CampoDeJuego::jugadasHechas(int x1, int y1, int x2, int y2){
	
}

void CampoDeJuego::cuadroHechoHorizontal(int x, int y){
	int lineasHechas1 = 0;
	int lineasHechas2 = 0;

	//Se revisa primero el cuadrado de un lado
	if (x - 1 < 0 || x + 1 >= filas || y + 1 >= columnas) {
		//Se sale de la matriz
	}
	else {
		if (mat[x + 1][y + 1] == "-")
			lineasHechas1++;
		if (mat[x - 1][y + 1] == "-")
			lineasHechas1++;
		if (mat[x][y + 2] == "|")
			lineasHechas1++;
		if (lineasHechas1 == 3)
			cuadroHecho = true;
	}
	if (x - 1 < 0 || y - 1 < 0 || x + 1 >= filas) {
		//Se sale de la matriz
	}
	else {
		//Ahora se revisa el cuadrado del otro lado
		if (mat[x - 1][y - 1] == "-")
			lineasHechas2++;
		if (mat[x + 1][y - 1] == "-")
			lineasHechas2++;
		if (mat[x][y - 2] == "|")
			lineasHechas2++;
		if (lineasHechas2 == 3)
			cuadroHecho = true;
	}
}

void CampoDeJuego::cuadroHechoVertical(int x, int y){
	int lineasHechas1 = 0;
	int lineasHechas2 = 0;

	//Se revisa primero el cuadrado de un lado
	if (x - 1 < 0 || y - 1 < 0 || y + 1 >= columnas) {
		//Se sale de la matriz
	}
	else {
		if (mat[x - 1][y - 1] == "|")
			lineasHechas1++;
		if (mat[x - 1][y + 1] == "|")
			lineasHechas1++;
		if (mat[x - 2][y] == "-")
			lineasHechas1++;
		if (lineasHechas1 == 3)
			cuadroHecho = true;
	}
	if (x + 1 >= filas || y + 1 >= columnas || y - 1 < 0) {
		//Se sale de la matriz
	}
	else{
		//Ahora se revisa el cuadrado del otro lado
		if (mat[x + 1][y + 1] == "|")
			lineasHechas2++;
		if (mat[x + 1][y - 1] == "|")
			lineasHechas2++;
		if (mat[x + 2][y] == "-")
			lineasHechas2++;
		if (lineasHechas2 == 3)
			cuadroHecho = true;
	}
}


//-----------------------------------------------------------------------------

CampoDeJuego* CampoDeJuego::leerElemento(istream& handle) {
	string n = "0", m = "0";
	int r = 0, s = 0;
	getline(handle, n, '\t');
	getline(handle, m, '\n');

	r = stoi(n);
	s = stoi(m);

	//Buscar forma de arreglarlo
	return NULL;
}

