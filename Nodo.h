#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

template<class DATON>
class Nodo {
public:
	DATON* dato;
	Nodo <DATON>* siguiente;
	Nodo(DATON*, Nodo<DATON>*);
	virtual ~Nodo();
	void  setS(Nodo<DATON>*);
	Nodo <DATON>* getS();
	string tostringNodo();
};

//------------------------------------------------

template<class DATON>
Nodo<DATON>::Nodo(DATON* dat, Nodo<DATON>* sig) {
	dato = dat;
	siguiente = sig;
}

template<class DATON>
Nodo<DATON>::~Nodo() {
	delete dato;
}

template<class DATON>
void Nodo<DATON>::setS(Nodo<DATON>* s) {
	siguiente = s;
}

template<class DATON>
Nodo<DATON>* Nodo<DATON>::getS() {
	return siguiente;
}

template<class DATON>
string Nodo<DATON>::tostringNodo() {
	return dato->toString();
}

