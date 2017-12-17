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
		qtdConfigsInciais
	};
	int configsIniciais[qtdConfigsInciais];
	Mapa* mapa;

	int PropNameToArrayIndex(const string& str);
	void PrintValorPropInicial(const string& prop);

public:
	/*Gets/Sets*/
	const string Comando() const;
	/***************/
	bool TodasAsConfigIniciasEstaoDefinidas();
	void ExecutaFicheiro(const string& fileName);
	bool ComandoEValido(const vector<string>& comandoPart);
	bool is_number(const string& s);
	bool SimComandoEValido(const vector<string>& comandoPart);
	vector<string> Explode(const string& str, const char& del);
	void PrintConfigsIniciais();
	void ScanConfig();
	void SetConfigInicial(vector<string> comandoPart);
	void InicializaMapa();
	int GetLimiteMapa();
	Simulacao();
	~Simulacao();
};