#pragma once
#include "Vista.h"

class Controladora{
private:
	EmpresaDots* empresa;
	Usuario* u1;

public:
	Controladora();
	virtual ~Controladora();
	void controlInicio(int);
	void controlMenu(int);
	void controlMenu1();
	void controlMenu2();
	void controlMenu3();
	void controlMenu4();
	void controlMenu5();
	void controlMenu6();
};

