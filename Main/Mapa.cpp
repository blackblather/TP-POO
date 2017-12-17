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

void Mapa::InicializaArrayMapa(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	arrMapa = new char*[limite];
	for (int i = 0; i < limite; i++)
		arrMapa[i] = new char[limite];
	PreencheMapaInicial(limite, qtdMigalhasIniciais, percentDeMigalhasIniciais);
}

void Mapa::DrawMap(const int& limite) {
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
	cout << "\r\n";
	for (int x = 0; x < limite; x++)
	{
		cout << "X ";
		for (int y = 0; y < limite; y++)
			cout << arrMapa[x][y] << ' ';
		cout << "X\r\n";
	}
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
}

bool Mapa::Ninho_exists(const string& s)
{
	vector<Ninho>::iterator it;
	if (ninhos.begin() != ninhos.end())
	{
		for (auto it = ninhos.begin(); it != ninhos.end(); it++)
		{
			int aux = it->GetNinhoID();
			if (stoi(s, nullptr, 10) == aux) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else 
	{
		return false;
	}
}

void Mapa::ListaElementos(int limiteMapa) const
{
	posXY xy;
	for (xy.x = 0; xy.x < limiteMapa; xy.x++)
	{
		for (xy.y = 0; xy.y < limiteMapa; xy.y++)
		{
			if (arrMapa[xy.x][xy.y] == crumbSymbol)
			{
				cout << "Migalha!" << endl;
			}
			else if (arrMapa[xy.x][xy.y] == nestSymbol)
			{
				cout << "Ninho!" << endl;
				vector<Ninho>::iterator it;
				if (ninhos.begin() != ninhos.end())
				{
					for (auto it = ninhos.begin(); it != ninhos.end(); it++)
					{
						if (it->GetPosNinhos().x == xy.x && it->GetPosNinhos().y == xy.y)
							it->NinhoInfoSimplex();
					}
				}
			}
		}
	}

}
void Mapa::ListaNinho(int ID_ninho) const
{
	vector<Ninho>::iterator it;
	if (ninhos.begin() != ninhos.end())
	{
		for (auto it = ninhos.begin(); it != ninhos.end(); it++)
		{
			int aux = it->GetNinhoID();
			if (ID_ninho == aux)
			{
				it->NinhoInfo();
			}
		}
	}
}
void Mapa::ListaPosicao(posXY xy, int limiteMapa) const
{
	if (xy.x > 0 && xy.x <= limiteMapa && xy.y > 0 && xy.y <= limiteMapa)
	{
		if (arrMapa[xy.x][xy.y] == ' ') cout << "Posicao vazia!" << endl;
		else if (arrMapa[xy.x][xy.y] == crumbSymbol) 
		{
			cout << "Migalha!" << endl; 
		}
		else if (arrMapa[xy.x][xy.y] == antSymbol) 
		{ 
			cout << "Formiga!" << endl; 
			vector<Ninho>::iterator it;
			if (ninhos.begin() != ninhos.end())
			{
				for (auto it = ninhos.begin(); it != ninhos.end(); it++)
				{
					it->InfoFormiga(xy);
				}
			}
		}
		else if (arrMapa[xy.x][xy.y] == nestSymbol) 
		{ 
			cout << "Ninho!" << endl; 
			vector<Ninho>::iterator it;
			if (ninhos.begin() != ninhos.end())
			{
				for (auto it = ninhos.begin(); it != ninhos.end(); it++)
				{
					if (it->GetPosNinhos().x == xy.x && it->GetPosNinhos().y == xy.y)
						it->NinhoInfo();
				}
			}
		}
	}
	
}

Mapa::Mapa(const int& limiteMapa, const int& energiaNovasMigalhas, const int& percentDeMigalhasIniciais) {
	int qtdMigalhasIniciais = (int)((limiteMapa*limiteMapa) * percentDeMigalhasIniciais / 100);
	InicializaArrayMapa(limiteMapa, qtdMigalhasIniciais, percentDeMigalhasIniciais);
}