#pragma once
#include "Elemento.h"
#define antSymbol 'f'
class Formiga : Elemento
{
	static int N_formiga;
	int ID_formiga;
	bool is_in_nest;
public:
	Formiga(posXY pos);
	posXY GetPosFormiga();
	void GetAntInfo();
};

