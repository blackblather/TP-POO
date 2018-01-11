#pragma once
#include "Elemento.h"

class Ninho;
class Migalha;
class Formiga : public Elemento
{
	static int N_formiga;
	int ID_formiga, raioVisao = 3, raioMovimento=5;
	bool is_in_nest;
	Ninho* motherLand;
	bool RegraFoge(char** arrMapa, vector<Ninho>* pNinhos);
	bool RegraPersegue(char** arrMapa, vector<Ninho>* pNinhos);
	bool RegraAssalta(char** arrMapa);
	bool RegraProtege(char** arrMapa, vector<Ninho>* pNinhos);
	bool RegraProcuraMigalha(char** arrMapa);
	bool RegraComeMigalha(char** arrMapa, vector<Migalha>* pMigalhas);
	bool RegraVaiParaNinho(char** arrMapa);
	bool RegraPasseia(char** arrMapa);
public:
	void ActionFormiga(char** arrMapa, vector<Ninho>* pNinhos, vector<Migalha>* pMigalhas);
	posXY GetPosFormiga() const;
	void GetAntInfo() const;
	Formiga(posXY pos, char type, Ninho* ninho);
};