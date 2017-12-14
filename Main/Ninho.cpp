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

int Ninho::GetNinhoID() 
{
	return this->ID_ninho;
}


Ninho::~Ninho()
{
}
