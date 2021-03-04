#include "Controladora.h"

Controladora::Controladora(){
	empresa = EmpresaDots::cargarEmpresa();
	u1 = NULL;
	controlInicio(0);
}

Controladora::~Controladora(){
	delete empresa; //aqui se borra el usuario
}

void Controladora::controlInicio(int opc){
	int opcionInicio = 0;
	bool validacionOpc1 = false;
	
	do {
		opcionInicio = Vista::VistaInicio(empresa, u1);

		if (opcionInicio == 1)
			validacionOpc1 = Vista::VistaInicioOpc1(empresa, u1);
		else
			validacionOpc1 = Vista::VistaInicioOpc2(empresa, u1);

	} while (!validacionOpc1);

	controlMenu(opc);
}

void Controladora::controlMenu(int opc){
	int opcionMenu = opc;	
	while (opcionMenu != 6){
		opcionMenu = Vista::VistaMenu(empresa, u1);
		switch (opcionMenu) {
		case 1: controlMenu1(); break;
		case 2: controlMenu2(); break;
		case 3: controlMenu3(); break;
		case 4: controlMenu4();	break;
		case 5: controlMenu5(); break;
		case 6: controlMenu6();
		}
	} 
}

void Controladora::controlMenu1(){
	Vista::VistaMenuOpc1(empresa, u1);
}

void Controladora::controlMenu2(){
	Vista::VistaMenuOpc2(empresa, u1);
}

void Controladora::controlMenu3(){
	Vista::VistaMenuOpc3();
}

void Controladora::controlMenu4(){
	Vista::VistaMenuOpc4(empresa);
	controlInicio(6);
}

void Controladora::controlMenu5(){
	Vista::VistaMenuOpc5(empresa);
}

void Controladora::controlMenu6(){
	Vista::VistaMenuOpc6(empresa);
}
