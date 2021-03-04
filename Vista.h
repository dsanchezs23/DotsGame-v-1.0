#pragma once
#include "EmpresaDots.h"

class Vista{
public:
	static int VistaInicio(EmpresaDots*&, Usuario*&);
	static bool VistaInicioOpc1(EmpresaDots*&, Usuario*&);
	static bool VistaInicioOpc2(EmpresaDots*&, Usuario*&);
	static int VistaMenu(EmpresaDots*&, Usuario*&);
	static void VistaMenuOpc1(EmpresaDots*&, Usuario*&);
	static void VistaMenuOpc2(EmpresaDots*&, Usuario*&);
	static void VistaMenuOpc3();
	static void VistaMenuOpc4(EmpresaDots*&);
	static void VistaMenuOpc5(EmpresaDots*&);
	static void VistaMenuOpc6(EmpresaDots*&);
};

