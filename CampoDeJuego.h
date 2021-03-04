#pragma once
#include "CampoAbstracto.h"
#include "ProcesaCompuesto.h"
#include "Arbitro.h"
#include "JugadorMaquina.h"
#include "Usuario.h"

class CampoDeJuego : public CampoAbstracto {
protected:
	int cantJugadas;
	string** mat;//no posee objetos dinamicos
	int cantCam;
	CampoAbstracto** vec;
	int cantEle;
	Linea* linea;
	Lista<Linea>* ll;
	bool cuadroHecho;
public:
	CampoDeJuego();
	virtual ~CampoDeJuego();
	//--------------------------------------------
	void ingresaCampo(CampoAbstracto*);
	void crearCampo();
	string campoDibujado();
	void jugarVsMaquina(Usuario*, JugadorMaquina*);
	void JugarVsJugador(Usuario*, Usuario*);
	bool hacerLinea(int, int, int, int);
	//--------------------------------------------
	int getFilas();
	int getColumnas();
	string** retornaMatriz();
	string getCodigo();
	CampoAbstracto** retornaVector();
	int retornarCantElementos();
	Lista<Linea>* getListaLinea();
	//--------------------------------------------
	void contarJugadas();
	int getCantJugadas();
	//--------------------------------------------
	bool juegoSinFinalizar();
	void jugadasHechas(int, int, int, int);	
	void cuadroHechoHorizontal(int, int);
	void cuadroHechoVertical(int, int);
	//--------------------------------------------
	static CampoDeJuego* leerElemento(istream&);
};

