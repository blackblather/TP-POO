#include "stdafx.h"
#include "Formiga.h"

int Formiga::N_formiga = 1;
Formiga::Formiga(posXY pos)
{
	simbolo = antSymbol;
	posElemento = pos;
	ID_formiga = N_formiga;
	N_formiga++;
}

posXY Formiga::GetPosFormiga() const
{
	return this->posElemento;
}

void Formiga::GetAntInfo() const
{
	cout << "--Formiga: " << this->ID_formiga << endl;
	cout << "---Energia: " << this->energia << endl;
	cout << "---Posicao: " << posElemento.x << "," << posElemento.y << endl;
	cout << "---Esta no ninho?: " << this->is_in_nest << endl;
}
