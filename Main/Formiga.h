#pragma once
#include "Elemento.h"
class Ninho;
class Formiga : public Elemento
{
	static int N_formiga;
	int ID_formiga;
	bool is_in_nest;
	Ninho* motherLand;
public:
	Formiga(posXY pos, char type, Ninho* ninho);
	posXY GetPosFormiga() const;
	void GetAntInfo() const;
};