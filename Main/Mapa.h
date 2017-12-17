#pragma once
#include "Ecra.h"
#include "Ninho.h"
#include "Migalha.h"


class Mapa : public Ecra
{
	char** arrMapa;
	vector<Migalha> migalhas;
	vector<Ninho> ninhos;
	void PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
	void PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
	//void PreencheMapaComFormigas();
	void InicializaArrayMapa(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
public:
	void DrawMap(const int& limite);
	bool Ninho_exists(const string& s);
	void ListaElementos(int limiteMapa) const;
	void ListaNinho(int ID_ninho) const;
	void ListaPosicao(posXY xy, int limiteMapa) const;
	Mapa(const int& limiteMapa, const int& energiaNovasMigalhas, const int& percentDeMigalhasIniciais);
};