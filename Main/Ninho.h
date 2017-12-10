#pragma once
#include "Elemento.h"
class Ninho : Elemento
{
	const int ID_ninho;
	vector<Formiga> formigas;
public:
	Ninho();
	~Ninho();
};

