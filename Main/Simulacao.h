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
		//qtdMigalhasIniciais,		//AUX
		qtdConfigsInciais
	};
	int configsIniciais[qtdConfigsInciais];
	Mapa* mapa;

	int PropNameToArrayIndex(const string& str);
	void PrintValorPropInicial(const string& prop);

public:
	//Gets
	const string Comando() const;
	//Funções
	bool TodasAsConfigIniciasEstaoDefinidas();
	void ExecutaFicheiro(const string& fileName);
	bool ComandoEValido(const vector<string>& comandoPart);
	vector<string> Explode(const string& str, const char& del);
	void PrintConfigsIniciais();
	void ScanConfig();
	void SetConfigInicial(vector<string> comandoPart);
	void Start();
	Simulacao();
	~Simulacao();
};