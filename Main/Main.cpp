#include "stdafx.h"
#include "Simulacao.h"

int main()
{
	Simulacao sim = Simulacao();
	do {
		Ecra::LimpaEcra();
		sim.PrintConfigsIniciais();
		sim.ScanConfig();
		_getch();
	//Trocar condição do loop
	 } while (1);
	 sim.Start();

	_getch();
    return 0;
}

