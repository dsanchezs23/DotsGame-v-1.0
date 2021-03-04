#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class Fecha{
private:
	int dia;
	int mes;
	int anno;
	SYSTEMTIME* hoy;
public:
	Fecha();
	Fecha(int, int, int);
	virtual ~Fecha();
	void setDia(int);
	void setMes(int);
	void setAnno(int);
	int getDia();
	int getMes();
	int getAnno();
	void getFecha();
	void sumaAnno();
	void sumaMes();
	void sumaDia();
};

