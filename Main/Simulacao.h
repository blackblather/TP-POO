#pragma once
#include "Mapa.h"

class Simulacao
{
	//VARS
	string comando;
	map<string, boost::variant<int, double>> configsIniciais;
	int limiteMapa = -1,					// defmundo <limiteMapa>
		energiaInitNinhos = -1,				// defen <energiaInitNinhos>
		energiaNinhoParaFormiga = 1,		// defvt <energiaNinhoParaFormiga>
		energiaNovasMigalhas = -1,			// defme <energiaNovasMigalhas>
		qtdMigalhasIniciais = -1,			/*AUX -> (int)((limiteMapa*limiteMapa) * percentDeMigalhasIniciais/100)*/
		maxMigalhasPorIteracao = -1;		// defnm <maxMigalhas>
	
	double percentEnergiaNovaFormiga = -1,	// defpc <percentEnergiaNovaFormiga>
		percentDeMigalhasIniciais = -1;		// defmi <percentDeMigalhasIniciais>
	Mapa* mapa;

	//FUNÇÕES
	void PrintValorPropInicial(string prop);
	vector<string> Explode(string str, char del);
	bool ComandoEValido(vector<string> comandoPart);
public:
	void PrintConfigsIniciais();
	void ScanConfig();
	void ExecutaComando();
	void Start();
	Simulacao();
	~Simulacao();
};