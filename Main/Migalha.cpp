#include "stdafx.h"
#include "Migalha.h"

Migalha::Migalha(posXY pos, const int& energiaMigalha)
{
	simbolo = crumbSymbol;
	posElemento = pos;
	energia = energiaMigalha;
}

posXY Migalha::GetPosMigalha() const
{
	return this->posElemento;
}


Migalha::~Migalha()
{
}
