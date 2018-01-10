#pragma once
#include "Elemento.h"
class Ninho;
class Formiga : public Elemento
{
	static int N_formiga;
	int ID_formiga;
	bool is_in_nest;
	Ninho* motherLand;
	bool RegraFoge();			//#0
	bool RegraPersegue();		//#1
	bool RegraAssalta();		//#2
	bool RegraProtege();		//#3
	bool RegraProcuraMigalha();	//#4
	bool RegraComeMigalha();	//#5
	bool RegraVaiParaNinho();	//#6
	bool RegraPasseia();		//#7

public:
	Formiga(posXY pos, char type, Ninho* ninho);
	void ActionFormiga(char** arrMapa);
	posXY GetPosFormiga() const;
	void GetAntInfo() const;
};