#include "stdafx.h"
#include "Mapa.h"

void Mapa::PreencheMapaComMigalhas(const int& limite, const int& qtdMigalhasIniciais) {
	for (int x = 0; x < limite; x++) {
		for (int y = 0; y < limite; y++) {

		}
	}
}

bool Mapa::InicializaMapaVazio(const int& limite) {
	try {
		arrMapa = new char*[limite];
		for (int i = 0; i < limite; i++)
			arrMapa[i] = new char[limite];
		for (int x = 0; x < limite; x++)
			for (int y = 0; y < limite; y++)
				arrMapa[x][y] = 'x';
		return true;
	}
	catch(int ex) {
		return false;
	}
}

void Mapa::DrawMap(const int& limite) {
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
	cout << "\n";
	for (int l = 0; l < limite; l++)
	{
		cout << "X ";
		for (int h = 0; h < limite; h++)
			cout << arrMapa[l][h] << ' ';
		cout << "X\n";
	}

	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
}

Mapa::Mapa(const int& limite, const int& percentDeMigalhasIniciais)
{
	/* Converter a percentagem de migalhas para uma quantidade aqui dentro.
	 * É para evitar ter um if em "Simulacao::SetConfigInicial(...)".
	 */
	 //qtdMigalhasIniciais	AUX -> (int)((limiteMapa*limiteMapa) * percentDeMigalhasIniciais/100)
	int qtdMigalhasIniciais;
	if (InicializaMapaVazio(limite)) {
		DrawMap(limite);
		//PreencheMapaComMigalhas(limite, qtdMigalhasIniciais);
	}
}