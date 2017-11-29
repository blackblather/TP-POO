#pragma once
#include "Mapa.h"

class Simulacao
{
	//VARS
	string comando;
	enum configsIniciais { 
		limiteMapa,
		energiaInitNinhos,
		energiaNinhoParaFormiga,
		energiaNovasMigalhas,
		qtdMigalhasIniciais,
		maxMigalhasPorIteracao,
		percentEnergiaNovaFormiga,
		percentDeMigalhasIniciais,
		qtdConfigsInciais
	};
	int configsIniciais[qtdConfigsInciais];
	Mapa* mapa;

	//FUNÇÕES
	int PropNameToArrayIndex(const string& str);
	void PrintValorPropInicial(const string& prop);
	vector<string> Explode(const string& str, const char& del);
	bool ComandoEValido(const vector<string>& comandoPart);

public:
	void PrintConfigsIniciais();
	void ScanConfig();
	void SetConfigInicial();
	void Start();
	Simulacao();
	~Simulacao();
};