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
