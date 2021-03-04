#pragma once
#include "JugadorAbstracto.h"
#include "Linea.h"

using namespace std;

class Usuario : public JugadorAbstracto {
private:
	string cedula;
	int cantUsu;
	bool suscrito;
public:
	Usuario(string, string, bool);
	virtual ~Usuario();
	string getCedula();
	void setSuscrito(bool);
	bool getSuscrito();
	void setearPuntos();
	static Usuario* leerElemento(istream&);
	void realizarJugada(CampoDeJuego*, Linea*);//para herencia del jugadorAbstracto
	void realizarJugadaPersonal(Linea*);
	string toString();
};

