#include "stdafx.h"
#include "Simulacao.h"

int main()
{
	Simulacao sim = Simulacao();
	do {
		Ecra::LimpaEcra();
		sim.PrintConfigsIniciais();
		sim.ScanConfig();
		if (sim.Comando().substr(0, 7) == "executa") {
			//Faz umas validações aqui e abre o ficheiro
		} else if (sim.Comando().substr(0, 7) == "inicia") {
			//Faz umas validações aqui e abre o ficheiro
		}
		else
			sim.SetConfigInicial();
	//Trocar condição do loop
	 } while (1);
	 sim.Start();

	_getch();
    return 0;
}

