#include "Fecha.h"

Fecha::Fecha() {
	hoy = new SYSTEMTIME();
	GetSystemTime(hoy);
	dia = hoy->wDay;
	mes = hoy->wMonth;
	anno = hoy->wYear;
}

Fecha::Fecha(int d, int m, int a){
	hoy = new SYSTEMTIME();
	GetSystemTime(hoy);
	dia = d;
	mes = m;
	anno = a;
}

Fecha::~Fecha(){
	delete hoy;
}

void Fecha::setDia(int d){
	dia = d;
}

void Fecha::setMes(int m){
	mes = m;
}

void Fecha::setAnno(int a){
	anno = a;
}

int Fecha::getDia(){
	return dia;
}

int Fecha::getMes(){
	return mes;
}

int Fecha::getAnno(){
	return anno;
}

void Fecha::getFecha(){

	cout << dia << "/" << mes << "/" << anno << "\n";
}

void Fecha::sumaAnno(){
	anno++;
	dia = 1;
	mes = 1;
}

void Fecha::sumaMes() {
	if ((mes % 2 == 0 || mes == 11) && (mes != 8 && mes != 10 && mes != 12)) {//ver los meses con 30 dias
		if (dia == 31) {//Esto por si suma un mes estando en otro que si puede tener 31 dias
			dia = 1;
		}
	}
	if (mes == 12)
		sumaAnno();
	else
		mes++;
}

void Fecha::sumaDia(){
	if ((mes % 2 == 0 || mes == 11) && (mes != 8 && mes != 10 && mes !=12) ) {//ver los meses con 30 dias
		if (dia == 30) {
			dia = 1;
			sumaMes();
		}
		else {
			dia++;
		}
	}
	else {//meses con 31 dias
		if (dia == 31) {
			dia = 1;
			sumaMes();
		}
		
		else {
			dia++;
		}
	}
}

