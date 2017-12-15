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
	void PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
	void PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
	//void PreencheMapaComFormigas();
	void InicializaArrayMapa(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
public:
	void DrawMap(const int& limite);
	bool Ninho_exists(const string& s);
	Mapa(const int& limiteMapa, const int& energiaNovasMigalhas, const int& percentDeMigalhasIniciais);
};