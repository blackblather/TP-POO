#pragma once
#include "Elemento.h"
#include "Formiga.h"
#define nestSymbol 'N'
class Ninho : public Elemento
{
	static int N_ninho;
	int ID_ninho;
public:
	vector<Formiga> formigas;
	Ninho(posXY pos);
	int GetNinhoID() const;
	posXY GetPosNinho() const;
	void InfoFormiga(posXY xy) const;
	void NinhoInfoDetailed() const;
	void NinhoInfoSimple() const;
};

