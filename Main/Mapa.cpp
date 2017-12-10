#include "stdafx.h"
#include "Mapa.h"

void Mapa::PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais) {
	int inseridas = 0, x, y;
	posXY posAux;
	while (inseridas < qtdMigalhasIniciais) {
		posAux.x = rand() % limite;
		posAux.y = rand() % limite;
		if (arrMapa[x][y] != crumbSymbol) {
			migalhas.push_back(*(new Migalha(posAux)));
			arrMapa[x][y] = crumbSymbol;
		}
	}
}

void Mapa::PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais) {
	for (int x = 0; x < limite; x++)
		for (int y = 0; y < limite; y++)
			arrMapa[x][y] = ' ';
	PreencheMapaComMigalhasIniciais(limite, qtdMigalhasIniciais);
}

bool Mapa::InicializaMapa(const int& limite, const int& qtdMigalhasIniciais) {
	try {
		arrMapa = new char*[limite];
		for (int i = 0; i < limite; i++)
			arrMapa[i] = new char[limite];
		PreencheMapaInicial(limite, qtdMigalhasIniciais);
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

Mapa::Mapa(const int& limite, const int& percentDeMigalhasIniciais) {
   //int qtdMigalhasIniciais = (int)((limite*limite) * percentDeMigalhasIniciais / 100));
	if (InicializaMapa(limite, (int)((limite*limite) * percentDeMigalhasIniciais / 100))) {
		DrawMap(limite);
		//PreencheMapaComMigalhas(limite, qtdMigalhasIniciais);
	}
}