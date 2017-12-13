#include "stdafx.h"
#include "Mapa.h"

void Mapa::PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	int inseridas = 0;
	posXY posAux;
	while (inseridas < qtdMigalhasIniciais) {
		posAux.x = rand() % limite;
		posAux.y = rand() % limite;
		if (arrMapa[posAux.x][posAux.y] == ' ') {
			migalhas.push_back(*(new Migalha(posAux, percentDeMigalhasIniciais)));
			arrMapa[posAux.x][posAux.y] = crumbSymbol;
			inseridas++;
		}
	}
}

void Mapa::PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	for (int x = 0; x < limite; x++)
		for (int y = 0; y < limite; y++)
			arrMapa[x][y] = ' ';
	PreencheMapaComMigalhasIniciais(limite, qtdMigalhasIniciais, percentDeMigalhasIniciais);
}

bool Mapa::InicializaArrayMapa(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	try {
		arrMapa = new char*[limite];
		for (int i = 0; i < limite; i++)
			arrMapa[i] = new char[limite];
		PreencheMapaInicial(limite, qtdMigalhasIniciais, percentDeMigalhasIniciais);
		return true;
	}
	catch(std::bad_alloc& ba) {
		return false;
	}
}

void Mapa::DrawMap(const int& limite) {
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
	cout << "\n";
	for (int x = 0; x < limite; x++)
	{
		cout << "X ";
		for (int y = 0; y < limite; y++)
			cout << arrMapa[x][y] << ' ';
		cout << "X\n";
	}
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
}

Mapa::Mapa(const int& limiteMapa, const int& energiaNovasMigalhas, const int& percentDeMigalhasIniciais) {
	int qtdMigalhasIniciais = (int)((limiteMapa*limiteMapa) * percentDeMigalhasIniciais / 100);
	if (InicializaArrayMapa(limiteMapa, qtdMigalhasIniciais, percentDeMigalhasIniciais))
		DrawMap(limiteMapa); //Esta função não é daqui, só está aqui por uma questão de testes.
}