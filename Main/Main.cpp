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

	try {
		sim.InicializaMapa();
	}
	catch (std::bad_alloc& ba) {
		Ecra::PrintTextoColorido("Erro: impossivel alocar memoria para o mapa!\r\nClique numa tecla para fechar o programa.", "vermelho", "default");
		_getch();
		goto FINISH;
	}
	/*
		executa configs/config_1.txt
	*/
	do {
		sim.PrintSimulacaoNoEstadoAtual();
		cout << "\r\n";
		sim.ScanConfig();
		comandoPart = sim.Explode(sim.Comando(), ' ');
		if (sim.SimComandoEValido(comandoPart)) {
			if (comandoPart[0] != "sair")
				sim.ExecutaComando(comandoPart);
			else
				break;
		}
		else {
			Ecra::PrintTextoColorido("Comando invalido!", "vermelho", "default");
			_getch();
		}
		Ecra::LimpaEcra();
	} while (1);

	//Fim da simulação
	_getch();
FINISH:
	return 0;
}

