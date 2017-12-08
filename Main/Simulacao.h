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
		maxMigalhasPorIteracao,
		percentEnergiaNovaFormiga,
		percentDeMigalhasIniciais,
		qtdMigalhasIniciais,		//AUX
		qtdConfigsInciais
	};
	int configsIniciais[qtdConfigsInciais];
	Mapa* mapa;

	//FUNÇÕES
	int PropNameToArrayIndex(const string& str);
	void PrintValorPropInicial(const string& prop);

public:
	void ExecutaFicheiro(string fileName);
	bool ComandoEValido(const vector<string>& comandoPart);
	vector<string> Explode(const string& str, const char& del);
	const string Comando() const;
	void PrintConfigsIniciais();
	void ScanConfig();
	void SetConfigInicial(vector<string> comandoPart);
	void Start();
	Simulacao();
	~Simulacao();
};