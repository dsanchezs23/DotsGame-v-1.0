#include "Linea.h"

Linea::Linea(int x1, int y1, int x2, int y2){
	f1 = x1;
	c1 = y1;
	f2 = x2;
	c2 = y1;
}

Linea::~Linea(){
}

//------------------------------------------------------------------------

void Linea::setF1(int x1){
	f1 = x1;
}

void Linea::setF2(int x2){
	f2 = x2;
}

void Linea::setC1(int y1){
	c1 = y1;
}

void Linea::setC2(int y2){
	c2 = y2;
}

//------------------------------------------------------------------------

int Linea::getF1(){
	return f1;
}

int Linea::getF2(){
	return f2;
}

int Linea::getC1(){
	return c1;
}

int Linea::getC2(){
	return c2;
}

bool Linea::verificarLinea(){
	return false;
}

string Linea::toString(){
	stringstream x;

	x << "\nF1:" << f1 << " C1:" << c1 << " F2:" << f2 << " C2:" << c2 << "\n";

	return x.str();
}
