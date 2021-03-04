#include "Usuario.h"
#include "ExcepcionRango.h"
#include "ExcepcionValor.h"

Usuario::Usuario(string n, string c, bool s) : JugadorAbstracto(n){
	nombre = n;
	cedula = c;
	suscrito = s;
	cantUsu = 0;
}

Usuario::~Usuario(){
}

string Usuario::getCedula(){
	return cedula;
}

void Usuario::setSuscrito(bool s){
	suscrito = s;
}

bool Usuario::getSuscrito(){
	return suscrito;
}

void Usuario::setearPuntos(){
	cuadrosCompletos = 0;
}

Usuario* Usuario::leerElemento(istream& handle){
	string n, c, s;
	handle.clear();
	handle.ignore(255, '\n');
	getline(handle, n);
	getline(handle, c);
	getline(handle, s);

	if (s == "1")
		return new Usuario(n, c, true);
	else
		return new Usuario(n, c, false);
}

void Usuario::realizarJugada(CampoDeJuego*, Linea*){
	//para cumplir con la herencia
}

void Usuario::realizarJugadaPersonal(Linea* lin){
	bool validacion = true;
	while (validacion) {
		try {
			cout << "\n\nIngrese el valor del primer punto\n";
			cout << "\nFila: ";
			if (cin >> p1) {}//es un numero;
			else {
				throw ExcepcionValor(0, 0);
			}
			cout << "Columna: ";
			if (cin >> p2) {}
			else {
				throw ExcepcionValor(0, 0);
			}
			cout << "\nIngrese el valor del segundo punto\n ";
			cout << "\nFila: ";
			if (cin >> p3) {}
			else {
				throw ExcepcionValor(0, 0);
			}
			cout << "Columna: ";
			if (cin >> p4) {}
			else {
				throw ExcepcionValor(0, 0);
			}
			validacion = false;
		}
		catch (ExcepcionValor ev) {
			cout << "\n\nDebe ingrear un numero\n";
			Sleep(2000);
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	lin->setF1(p1);
	lin->setC1(p2);
	lin->setF2(p3);
	lin->setC2(p4);
}

string Usuario::toString() {
	stringstream x;

	x << "\n\tNombre del jugador: " << nombre;
	x << "\n\tCedula del jugador: " << cedula;
	x << "\n";

	return x.str();
}

