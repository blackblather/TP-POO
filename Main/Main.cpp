#include "stdafx.h"
#include "Simulacao.h"

int main()
{
	//Gera uma nova seed para usar em rand()
	srand(time(NULL));
	Simulacao sim = Simulacao();
	vector<string> comandoPart;
	do {
		sim.PrintConfigsIniciais();
		sim.ScanConfig();
		comandoPart = sim.Explode(sim.Comando(), ' ');
		if (sim.ComandoEValido(comandoPart)) {
			if (comandoPart[0] == "executa")
				sim.ExecutaFicheiro(comandoPart[1]);
			else if (comandoPart[0] == "inicio" && sim.TodasAsConfigIniciasEstaoDefinidas())
				break;
			else
				sim.SetConfigInicial(comandoPart);
		}
		Ecra::LimpaEcra();
	 } while (1);
	 //Só chega aqui se todas as configs estiverem definidas.
	 //Nota que a condição do loop é "1" (true) e só existe um "break"
	 Ecra::LimpaEcra();
	 sim.InicializaMapa();
	 do {
		 /*AQUI VAI HAVER OUTRO LOOP TIPO O DE CIMA, MAS PARA METER A SIMULACAO A "CORRER"*/
		 
		 cout << endl;
		 sim.ScanConfig();
		 comandoPart = sim.Explode(sim.Comando(), ' ');
		 if (sim.SimComandoEValido(comandoPart)) {
			 cout << "true!" << endl;
			 if (comandoPart[0] == "sair") 
			 {
				 break;
			 }
		 }
		 else 
		 {
			 cout << "false!" << endl;
		 }
	 } while (1);
	 //Fim da simulação
	_getch();
    return 0;
}

