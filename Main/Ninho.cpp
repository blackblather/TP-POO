#include "stdafx.h"
#include "Ninho.h"

int Ninho::N_ninho = 1;
Ninho::Ninho(posXY pos)
{
	simbolo = nestSymbol;
	posElemento = pos;
	ID_ninho = N_ninho;
	N_ninho++;
}


Ninho::~Ninho()
{
}
