#pragma once
#include "Ecra.h"
#include "Formiga.h"
#include "Migalha.h"
#include "Ninho.h"

class Mapa : public Ecra
{
	char** arrMapa;
	vector<Migalha> migalhas;
	void PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais);
	void PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais);
	bool InicializaMapa(const int& limite, const int& qtdMigalhasIniciais);
public:
	void DrawMap(const int& limite);
	Mapa(const int& limite, const int& percentDeMigalhasIniciais);
};

 