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
			if (comandoPart[0] == "executa")
				sim.ExecutaFicheiro(comandoPart[1]);
			else if (comandoPart[0] == "inicia" && sim.TodasAsConfigIniciasEstaoDefinidas())
				break;
			else
				sim.SetConfigInicial(comandoPart);
		}
		Ecra::LimpaEcra();
	 } while (1);
	 //Só chega aqui se todas as configs estiverem definidas.
	 //Nota que a condição do loop é "1" (true) e só existe um "break"
	 Ecra::LimpaEcra();
	 sim.Start();

	_getch();
    return 0;
}

