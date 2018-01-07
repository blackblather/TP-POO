#pragma once
#include "Mapa.h"

class Simulacao
{
	/*Vars*/
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
	/*Funções privadas*/
	int PropNameToArrayIndex(const string& str);
	void PrintValorPropInicial(const string& prop);

public:
	/*Gets/Sets*/
	const string Comando() const;
	/*Funções*/
	bool TodasAsConfigIniciasEstaoDefinidas();
	void ExecutaFicheiro(const string& fileName);
	bool ComandoEValido(const vector<string>& comandoPart);
	vector<string> Explode(const string& str, const char& del);
	void PrintConfigsIniciais();
	void ScanConfig();
	void SetConfigInicial(vector<string> comandoPart);
	void InicializaMapa();
	void PrintStatsAt(posXY posicaoInicial);
	void PrintSimulacaoNoEstadoAtual();
	/*Construtor/Destrutor*/
	Simulacao();
	~Simulacao();
	/***************/
};