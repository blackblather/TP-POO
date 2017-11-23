#pragma once
#include "Mapa.h"
#include "Formiga.h"
#include "Migalha.h"
#include "Ninho.h"

class Simulacao
{
	int limiteMapa,
		energiaInitNinhos,
		energiaNinhoParaFormiga = 1,
		energiaNovasMigalhas,
		qtdMigalhasIniciais,	//(int)((limiteMapa*limiteMapa) * percentDeMigalhasIniciais/100) <-- AUX
		maxMigalhas;
	double percentEnergiaNovaFormiga,
		percentDeMigalhasIniciais;
	Mapa* mapa;
public:
	void SetConfigs();
	Simulacao();
	~Simulacao();
};

