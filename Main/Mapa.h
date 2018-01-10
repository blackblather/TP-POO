#pragma once
#include "Ecra.h"
#include "Ninho.h"
#include "Migalha.h"


class Mapa : Ecra
{
	char** arrMapa;
	int tamMapa;
	vector<Migalha> migalhas;
	vector<Ninho> ninhos;
	void PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
	void PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
	//void PreencheMapaComFormigas();
	void InicializaArrayMapa(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais);
public:
	void DrawMap(const int& limite);
	bool Ninho_exists(const string& s);
	Ninho* GetNinhoById(int id);
	void ListaElementos(int limiteMapa) const;
	void ListaNinho(int ID_ninho) const;
	void ListaPosicao(posXY xy, int limiteMapa) const;
	bool PosEstaLivre(posXY pos);
	void CriaNinho(Ninho ninho);
	bool Cria1(char tipo, int ID_ninho, int posX, int posY);
	void CriaF(int qtd, char tipo, int ID_ninho);
	//void ActionNinhos();
	void ActionFormigas();
	//void ActionMigalhas();
	Mapa(const int& limiteMapa, const int& energiaNovasMigalhas, const int& percentDeMigalhasIniciais);
};