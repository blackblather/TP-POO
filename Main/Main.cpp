// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Simulacao.h"

int main()
{
	Simulacao sim = Simulacao();
	do {
		Ecra::LimpaEcra();
		sim.PrintConfigsIniciais();

		_getch();
	 } while (1);
	 sim.Start();

	_getch();
    return 0;
}

