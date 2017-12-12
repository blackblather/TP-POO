#pragma once
#include "Ecra.h"
#include "Ninho.h"
#include "Migalha.h"


class Mapa : public Ecra
{
	char** arrMapa;
	vector<Migalha> migalhas;
	vector<Ninho> ninhos;
	vector<Formiga> formigas;
	void PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais);
	void PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais);
	//void PreencheMapaComFormigas();
	bool InicializaMapa(const int& limite, const int& qtdMigalhasIniciais);
public:
	void DrawMap(const int& limite);
	Mapa(const int& limite, const int& percentDeMigalhasIniciais);
};