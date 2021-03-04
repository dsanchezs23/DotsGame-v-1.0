#pragma once
#include <iostream>
#include <sstream>

using namespace std;

class Linea{
protected:
	int f1;
	int f2;
	int c1;
	int c2;
public:
	Linea(int, int, int, int);
	virtual ~Linea();
	//--------------------------
	void setF1(int);
	void setF2(int);
	void setC1(int);
	void setC2(int);
	//--------------------------
	int getF1();
	int getF2();
	int getC1();
	int getC2();
	bool verificarLinea();
	//--------------------------
	string toString();
};

