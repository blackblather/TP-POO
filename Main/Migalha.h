#pragma once
#include "Elemento.h"
#define crumbSymbol 'm'

class Migalha : public Elemento
{
public:
	Migalha(posXY pos, const int& energiaMigalha);
	posXY GetPosMigalha() const;
	~Migalha();
};

