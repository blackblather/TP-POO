#pragma once
#include "Elemento.h"
#include "Formiga.h"
#define nestSymbol 'N'
class Ninho : Elemento
{
	static int N_ninho;
	int ID_ninho;
	vector<Formiga> formigas;
public:
	Ninho(posXY pos);
	~Ninho();
};

