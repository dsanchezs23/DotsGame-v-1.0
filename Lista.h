#pragma once
#include "Nodo.h"

using namespace std;

template <class DATO>
class Lista {
	Nodo<DATO>* primero;
	Nodo<DATO>* actual;
public:
	Lista();
	~Lista();
	void insertarFinal(DATO*);
	DATO* retornaElemento(int);// se pasa la posicion
	void borrarActual();
	bool listaVacia();
	DATO* valorActual();
	void Primero();
	void siguiente();
	bool recorrido();
	static Lista<DATO>* leerLista(istream&);
	string toString();
};

//-------------------------------------------------------------------------------

template <class DATO>
Lista<DATO>::Lista() {
	primero = nullptr;
	actual = nullptr;
}

template <class DATO>
Lista<DATO>::~Lista() {
	while (!listaVacia()) {
		actual = primero;
		primero = primero->siguiente;
		delete actual;
	}
}

template<class DATO>
void Lista<DATO>::insertarFinal(DATO* dat) {
	Nodo<DATO>* ultimo;

	if (listaVacia())
		primero = new Nodo<DATO>(dat, primero);
	else {
		ultimo = primero;
		while (ultimo->siguiente) ultimo = ultimo->siguiente;
		ultimo->siguiente = new Nodo<DATO>(dat, NULL);
	}
}

template<class DATO>
DATO* Lista<DATO>::retornaElemento(int lug) {
	int cont = 1;
	Nodo<DATO>* p = primero;
	while (p != NULL && cont < lug) {
		p = p->getS();
		cont++;
	}
	if (cont == lug) {
		return p->getDato();
	}
}

template<class DATO>
void Lista<DATO>::borrarActual() {
	Nodo<DATO>* anterior;

	if (actual && actual == primero) {
		primero = actual->siguiente;
		delete actual;
		actual = NULL;
	}
	else
		if (actual && !listaVacia()) {
			anterior = primero;
			while (anterior && anterior->siguiente != actual)
				anterior = anterior->siguiente;
			anterior->siguiente = actual->siguiente;
			delete actual;
			actual = NULL;
		}
}

template <class DATO>
bool Lista<DATO>::listaVacia() {
	return  (primero == NULL) ? true : false;
}

template <class DATO>
DATO* Lista<DATO>::valorActual() {
	return actual->dato;
}

template <class DATO>
void Lista<DATO>::Primero() {
	actual = primero;
}

template <class DATO>
void Lista<DATO>::siguiente() {
	if (actual) actual = actual->siguiente;
}

template<class DATO>
bool Lista<DATO>::recorrido() {
	if (actual != NULL) { return true; }
	return false;
}

template<class DATO>
Lista<DATO>* Lista<DATO>::leerLista(istream& handle){
	Lista<DATO>* ld = new Lista<DATO>();
	string c = "0";
	int cant = 0;
	getline(handle, c, '\n');
	cant = stoi(c);

	for (int i = 0; i < cant; i++) {
		ld->insertarFinal(DATO::leerElemento(handle));
	}

	return ld;
}

template <class DATO>
string Lista<DATO>::toString() {
	stringstream s;
	actual = primero;
	s << endl << "Contenido de la lista:" << endl;
	while (actual != NULL) {
		s << actual->tostringNodo() << endl;
		actual = actual->getS();
	}
	return s.str();
}
