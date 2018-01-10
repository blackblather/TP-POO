#pragma once
#include "Elemento.h"
class Ninho;
class Formiga : public Elemento
{
	static int N_formiga;
	int ID_formiga;
	bool is_in_nest;
	Ninho* motherLand;
	bool RegraFoge(char** arrMapa);			//#0
	bool RegraPersegue(char** arrMapa);		//#1
	bool RegraAssalta(char** arrMapa);		//#2
	bool RegraProtege(char** arrMapa);		//#3
	bool RegraProcuraMigalha(char** arrMapa);	//#4
	bool RegraComeMigalha(char** arrMapa);	//#5
	bool RegraVaiParaNinho(char** arrMapa);	//#6
	bool RegraPasseia(char** arrMapa);		//#7

public:
	Formiga(posXY pos, char type, Ninho* ninho);
	void ActionFormiga(char** arrMapa);
	posXY GetPosFormiga() const;
	void GetAntInfo() const;
};