#pragma once
#include <map>
#include "Mapa.h"
#include "Formiga.h"
#include "Migalha.h"
#include "Ninho.h"

class Simulacao
{
	//VARS
	string comando;
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
	vector<string> explode(string s, char c);
	bool ComandoEValido()
	{
		return false;
	}
public:
	void PrintConfigsIniciais();
	void ScanConfig();
	void Start();
	Simulacao();
	~Simulacao();
};

