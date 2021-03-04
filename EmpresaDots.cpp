#include "EmpresaDots.h"


EmpresaDots::EmpresaDots(int cod, Lista<Usuario>* lu, CampoDeJuego* c, Fecha* f, Lista<Linea>* ll){
	codigo = cod;
	sus = NULL;
	lusu = lu;
	cam = c;
	fHoy = new Fecha();
	fDigitada = f;
	lLin = ll;

	verificarDia();
}

EmpresaDots::~EmpresaDots(){
	guardarEmpresa(true);
	delete sus;
	delete lusu;
	delete cam;
	delete fHoy;
}

//------------------------------------------------------------------

void EmpresaDots::generaCodigo(){
	srand(time(NULL));
	codigo = 1 + rand()%(101 - 1);
}

int EmpresaDots::getCodigo() {
	return codigo;
}

void EmpresaDots::pasarAlSiguienteDia(){
	fDigitada->sumaDia();
	guardarEmpresa(false);
	lusu = new Lista<Usuario>();;
	cam = new CampoDeJuego();
	lLin = new Lista<Linea>();
	generaCodigo();
}

//------------------------------------------------------------------

void EmpresaDots::aregarUsuario(Usuario* u){
	lusu->insertarFinal(u);
}

bool EmpresaDots::verificarUsuario(string c){
	lusu->Primero();
	while (lusu->recorrido()) {
		if (lusu->valorActual()->getCedula() == c)
			return true;
		lusu->siguiente();
	}
	return false;
}

Usuario* EmpresaDots::retornaUsuario(string ced){
	lusu->Primero();
	while (lusu->recorrido()) {
		if (lusu->valorActual()->getCedula() == ced)
			return new Usuario(lusu->valorActual()->getNombre(), lusu->valorActual()->getCedula(), lusu->valorActual()->getSuscrito());
		lusu->siguiente();
	}
	return NULL;
}

bool EmpresaDots::verificarSuscripcion(string ced){
	int c = 0;
	lusu->Primero();
	while (lusu->recorrido()) {
		if (lusu->valorActual()->getCedula() == ced && lusu->valorActual()->getSuscrito() == true) {
			cout << "Ingrese el codigo: ";
			cin >> c;
			if (c == codigo)
				return true;
			else {
				cout << "\n\nCodigo incorrecto\n\n";
				return false;
			}
		}
		lusu->siguiente();
	}
	return false;
}


bool EmpresaDots::realizarPagoSuscripcion(string ced){
	lusu->Primero();
	while (lusu->recorrido()) {
		if (lusu->valorActual()->getCedula() == ced) {
			lusu->valorActual()->setSuscrito(true);
			return true;
		}
		lusu->siguiente();
	}
	return false;
}

void EmpresaDots::attach(Suscripcion* s){
	sus = s;
}

void EmpresaDots::jugar(Usuario* usuario){
	bool validacionCampo = true, validacionJugador = true;
	int opcionCampo = 0, opcionJugador = 0;
	string nombre2 = "";
	cam = new CampoDeJuego();
	JugadorMaquina* jm = new JugadorMaquina();
	Usuario* j2 = NULL;

	system("cls");
	cout << "El primer caso es escoger un campo de juego, presione la opcion 4 cuando este satisfecho con el campo creado";
	while (validacionCampo) {
		try {
			cout << "\n\n\t1- Campo de seis puntos";
			cout << "\n\t2- Campo de nueve puntos";
			cout << "\n\t3- Campo de quince puntos";
			cout << "\n\t4- Listo";
			cout << "\n\tOpcion: ";
			if (cin >> opcionCampo) {
				if (opcionCampo > 0 && opcionCampo < 5) {
					//Esta bien ingresada la opcion
					if (opcionCampo == 1) {
						cam->ingresaCampo(new SeisPuntos());
					}
					else if (opcionCampo == 2) {
						cam->ingresaCampo(new NuevePuntos());
					}
					else if (opcionCampo == 3) {
						cam->ingresaCampo(new QuincePuntos());
					}

					else {//opcion 4
						validacionCampo = false;
						cam->crearCampo();
					}
				}
				else {
					//La opcion no esta en las opciones
					throw ExcepcionRango(1, 4);
				}
			}
			else {
				//No ingreso un entero
				throw ExcepcionValor(1, 4);
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
		system("cls");
	}

	while (validacionJugador) {
		try {
			system("cls");
			cout << "El segundo paso es escoger su rival";
			cout << "\n1- Maquina";
			cout << "\n2- Otro usuario";
			cout << "\nOpcion: ";

			if (cin >> opcionJugador) {
				if (opcionJugador > 0 && opcionJugador < 3) {
					//Esta bien ingresada la opcion
					if (opcionJugador == 1) {
						jm->mostrarEstrategias();
						cam->jugarVsMaquina(usuario, jm);
						validacionJugador = false;
					}
					else {
						cout << "\n\nIngrese el nombre del segundo jugador: ";
						cin.clear();
						cin.ignore(255, '\n');
						getline(cin, nombre2);
						j2 = new Usuario(nombre2, "cedulaGenerica", true);
						cam->JugarVsJugador(usuario, j2);
						validacionJugador = false;
					}
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
	}

	lLin = cam->getListaLinea();
	guardarEmpresa(true);
	delete jm;
	delete j2;

}

void EmpresaDots::verificarDia(){
	if (fDigitada->getDia() == fHoy->getDia() && fDigitada->getMes() == fHoy->getMes() && fDigitada->getAnno() == fHoy->getAnno()) {
		//
	}
	else {
		Archivos a;
		a.borrar();
		lusu = new Lista<Usuario>();;
		cam = new CampoDeJuego();
		generaCodigo();
	}
}

void EmpresaDots::verCampoAnterior(){
	cout << cam->campoDibujado();
}

//------------------------------------------------------------------

EmpresaDots* EmpresaDots::cargarEmpresa(){
	//Tiene que cargar todos los datos y variables
	//
	Archivos a;
	string c = "0";
	int cod = 0;
	ifstream handle("Archivos.txt");
	handle >> c;
	handle.close();
	Fecha* f = a.cargarFecha();
	Lista<Usuario>* lus = a.cargarUsuarios();
	Lista<Linea>* ll = new Lista<Linea>();
	CampoDeJuego* ca = a.cargarCampo(ll);
	
	cod = stoi(c);
	handle.close();

	return new EmpresaDots(cod, lus, ca, f, ll);
}

void EmpresaDots::guardarEmpresa(bool g){
	Archivos a;
	ofstream handle;
	handle.open("Archivos.txt");
	if (g) { //guardar normal
		handle << codigo << endl;
		handle.close();
		fDigitada = fHoy;
		a.guardarFecha(fDigitada);
		a.guardarUsuarios(lusu);
		a.guardarCampo(cam, lLin);
	}
	else {
		a.borrar();
	}
}

//------------------------------------------------------------------

Lista<Usuario>* EmpresaDots::getListaUsu(){
	return lusu;
}

CampoDeJuego* EmpresaDots::getCam(){
	return cam;
}

Lista<Linea>* EmpresaDots::getListaLineas(){
	return lLin;
}

string EmpresaDots::toString(){
	stringstream x;

	x << sus->toString();//cambiar

	return x.str();
}
