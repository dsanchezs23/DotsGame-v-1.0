#include "Vista.h"

int Vista::VistaInicio(EmpresaDots*& empresa, Usuario*& u1){
	int opcionInicio = 0;
	bool validacionInicio = true;
	string nombre = "", cedula = "";
	while (validacionInicio) {
		try {
			system("cls");
			cout << "\t\t-------------------------------";
			cout << "\n\t\t| Bienvenido a la EmpresaDots |";
			cout << "\n\t\t-------------------------------";
			cout << "\n\n\n1- Iniciar sesion";
			cout << "\n2- Crear Usuario";
			cout << "\n\nOpcion: ";
			if (cin >> opcionInicio) {
				if (opcionInicio > 0 && opcionInicio < 3) {	
					//Esta bien ingresada la opcion
					validacionInicio = false;
				}
				else {
					//La opcion no esta en las opciones
					throw ExcepcionRango(1, 2);
				}
			}
			else {
				//No ingreso un entero
				throw ExcepcionValor(1, 2);
			}
		}
		catch (ExcepcionRango er) {
			cout << er.toString();
			Sleep(2000);
		}

		catch (ExcepcionValor ev) {
			cout << ev.toString();
			Sleep(2000);
			cin.clear();
			cin.ignore(255, '\n');
		}
	}//fin del while

	return opcionInicio;
}

bool Vista::VistaInicioOpc1(EmpresaDots*& empresa, Usuario*& u1){
	string nombre = "", cedula = "";
	cout << "\nIngrese la cedula: ";
	cin >> cedula;
	if (empresa->verificarUsuario(cedula)) {
		cout << "\nSe encontro el usuario";
		u1 = empresa->retornaUsuario(cedula);
		cout << "\nBienvenido/a " << u1->getNombre() << "\n";
		return true;
	}
	else {
		cout << "\nNo se encontro el usuario\n";
		Sleep(1500);
	}
	return false;
}

bool Vista::VistaInicioOpc2(EmpresaDots*& empresa, Usuario*& u1){
	string nombre = "", cedula = "";
	system("cls");
	cout << "---Creando un usuario";
	cout << "\n\nDigite el nombre: ";
	cin.clear();
	cin.ignore(255, '\n');
	getline(cin, nombre);
	cout << "\nDigite la cedula: ";
	getline(cin, cedula);
	u1 = new Usuario(nombre, cedula, false);
	empresa->aregarUsuario(u1);
	return true;
}

int Vista::VistaMenu(EmpresaDots*& empresa, Usuario*& u1){
	bool validacionMenu = true;
	int opcionMenu = 0;
	while (validacionMenu) {
		try {
			system("cls");
			cout << "\t\t-------------------------------";
			cout << "\n\t\t| Bienvenido a la EmpresaDots |";
			cout << "\n\t\t-------------------------------";
			cout << "\n\n\n\t---Menu principal---";
			cout << "\n\n\t 1-Suscribirse";
			cout << "\n\t 2-Jugar";
			cout << "\n\t 3-Reglas";
			cout << "\n\t 4-Siguiente dia";
			cout << "\n\t 5-Ver partida anterior";
			cout << "\n\t 6-Salir";
			cout << "\n\n\t Opcion: ";

			if (cin >> opcionMenu) {
				if (opcionMenu > 0 && opcionMenu < 7) {
					//Esta bien ingresada la opcion
					validacionMenu = false;
				}
				else {
					//La opcion no esta en las opciones
					throw ExcepcionRango(1, 6);
				}
			}
			else {
				//No ingreso un entero
				throw ExcepcionValor(1, 6);
			}
		}

		catch (ExcepcionRango er) {
			cout << er.toString();
			Sleep(2000);
		}

		catch (ExcepcionValor ev) {
			cout << ev.toString();
			Sleep(2000);
			cin.clear();
			cin.ignore(255, '\n');
		}
	}

	return opcionMenu;
}

void Vista::VistaMenuOpc1(EmpresaDots*& empresa, Usuario*& u1){
	system("cls");
	cout << "\t\t---Suscripcion---";
	cout << "\n\n---Pagando suscripcion de 500 colones";
	empresa->realizarPagoSuscripcion(u1->getCedula());
	cout << "\nSe realizo la suscripcion";
	cout << "\n\nEl codigo de hoy es: " << empresa->getCodigo() << "\n\n";
	system("pause");
}

void Vista::VistaMenuOpc2(EmpresaDots*& empresa, Usuario*& u1){
	system("cls");
	if (empresa->verificarSuscripcion(u1->getCedula())) {

		empresa->jugar(u1);
	}
	else {
		cout << "\n\nError, debe pagar la suscripcion primero\n\n";
		Sleep(1500);
	}
}

void Vista::VistaMenuOpc3(){
	system("cls");
	Arbitro::reglas();
	system("pause");
}

void Vista::VistaMenuOpc4(EmpresaDots*& empresa){
	system("cls");
	empresa->pasarAlSiguienteDia();
	cout << "\n\nEstamos en otro dia, por lo tanto, no hay usuarios suscritos ni campos de juegos\n\n";
	system("pause");
}

void Vista::VistaMenuOpc5(EmpresaDots*& empresa){
	system("cls");
	empresa->verCampoAnterior();
	cout << "\n---Lineas hechas durante el juego pasado---\n";
	cout << empresa->getListaLineas()->toString();
	system("pause");
}

void Vista::VistaMenuOpc6(EmpresaDots*& empresa){
	empresa->guardarEmpresa(true);
	cout << "\n\nGracias por usar nuestro producto\n\n";
}
