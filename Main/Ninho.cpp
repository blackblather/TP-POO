#include "stdafx.h"
#include "Ninho.h"
//Construtor/Destrutor
int Ninho::N_ninho = 1;
Ninho::Ninho(posXY pos)
{
	simbolo = nestSymbol;
	posElemento = pos;
	ID_ninho = N_ninho;
	N_ninho++;
}
//Gets
int Ninho::GetNinhoID() const
{
	return this->ID_ninho;
}
posXY Ninho::GetPosNinho() const
{
	return this->posElemento;
}
//Show Info
void Ninho::InfoFormiga(posXY xy) const 
{
	for (auto it = formigas.begin(); it != formigas.end(); it++)
		if (xy.x == posElemento.x && xy.y == posElemento.y)
			it->GetAntInfo();
}
void Ninho::NinhoInfoDetailed() const
{
	cout << "Ninho ID: " << ID_ninho << endl;
	cout << "-Posicao: " << posElemento.x << "," << posElemento.y << endl;
	cout << "-Energia: " << energia << endl;
	cout << "-Formigas afiliadas ao ninho:" << endl;
	if (formigas.begin() != formigas.end())
		for (auto it = formigas.begin(); it != formigas.end(); it++)
			it->GetAntInfo();
	else
		cout << "--Nao foram encontradas formigas afiliadas a este ninho!" << endl;
}
void Ninho::NinhoInfoSimple() const
{
	int N_formigas = 0;
	cout << "Ninho ID: " << ID_ninho << endl;
	cout << "-Posicao: " << posElemento.x << "," << posElemento.y << endl;
	cout << "-Energia: " << energia << endl;
	vector<Formiga>::iterator it;
	if (formigas.begin() != formigas.end())
	{
		for (auto it = formigas.begin(); it != formigas.end(); it++)
		{
			N_formigas++;
		}
	}
	else
	{
		cout << "--Nao foram encontradas formigas afiliadas a este ninho!" << endl;
	}
	cout << "-Formigas afiliadas ao ninho:" << N_formigas << endl;
}