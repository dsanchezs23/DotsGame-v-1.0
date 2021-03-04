#pragma once
#include <time.h>
#include "Suscripcion.h"
//#include "Lista.h"
//#include "CampoDeJuego.h"
/*#include "SeisPuntos.h"
#include "NuevePuntos.h"
#include "QuincePuntos.h"*/
#include "Fecha.h"
//#include "Usuario.h"
#include "JugadorMaquina.h"
#include <string>
#include "Archivos.h"
#include "ExcepcionRango.h"
#include "ExcepcionValor.h"

using namespace std;

class Suscripcion; //Declaracion previa

class EmpresaDots{//clase subject, este es observado por la clase suscripcion
private:
	int codigo;
	Suscripcion* sus;
	Lista<Usuario>* lusu;
	CampoDeJuego* cam;
	Fecha* fHoy;
	Fecha* fDigitada;
	Lista<Linea>* lLin;
public:
	EmpresaDots(int, Lista<Usuario>*, CampoDeJuego*, Fecha*, Lista<Linea>*);
	virtual ~EmpresaDots();
	//--------------------------------------------
	void generaCodigo();
	int getCodigo();
	void pasarAlSiguienteDia();
	//--------------------------------------------
	void aregarUsuario(Usuario*);
	bool verificarUsuario(string);
	Usuario* retornaUsuario(string);
	bool verificarSuscripcion(string);
	bool realizarPagoSuscripcion(string);
	void attach(Suscripcion*);//Agrega la suscripcion
	void jugar(Usuario*);
	void verificarDia();
	void verCampoAnterior();
	//--------------------------------------------
	static EmpresaDots* cargarEmpresa();
	void guardarEmpresa(bool);
	//------------------------------------------------
	Lista<Usuario>* getListaUsu();
	CampoDeJuego* getCam();
	Lista<Linea>* getListaLineas();
	string toString();
};

