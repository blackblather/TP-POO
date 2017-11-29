#include "stdafx.h"
#include "Simulacao.h"

int main()
{
	Simulacao sim = Simulacao();
	vector<string> comandoPart;
	do {
		sim.PrintConfigsIniciais();
		sim.ScanConfig();
		comandoPart = sim.Explode(sim.Comando(), ' ');
		if (sim.ComandoEValido(comandoPart)) {
			if (comandoPart[0] == "executa") {
				//Faz umas validações aqui e abre o ficheiro
				break;
			}
			else if (comandoPart[0] == "inicia") {
				//Faz umas validações aqui e começa a simulação
				break;
			}
			else
				sim.SetConfigInicial(comandoPart);
		}
		Ecra::LimpaEcra();
	//Trocar condição do loop
	 } while (1);
	 Ecra::LimpaEcra();
	 sim.Start();

	_getch();
    return 0;
}

