#include "stdafx.h"
#include "Formiga.h"

bool Formiga::RegraFoge(char** arrMapa) { return false; }
bool Formiga::RegraPersegue(char** arrMapa) { return false; }
bool Formiga::RegraAssalta(char** arrMapa) { return false; }
bool Formiga::RegraProtege(char** arrMapa) { return false; }
bool Formiga::RegraProcuraMigalha(char** arrMapa) { return false; }
bool Formiga::RegraComeMigalha(char** arrMapa) { return false; }
bool Formiga::RegraVaiParaNinho(char** arrMapa) { return false; }
bool Formiga::RegraPasseia(char** arrMapa) { return false; }

void Formiga::ActionFormiga(char** arrMapa) {
	if (is_in_nest) {

	}
	else {
		//Executa regras de acordo com o tipo de formiga até uma função retornar "true"
		if (simbolo == 'C' || simbolo == 'c')
			RegraFoge(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraVaiParaNinho(arrMapa) || RegraPasseia(arrMapa);
		if (simbolo == 'V' || simbolo == 'v')
			RegraProtege(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		if (simbolo == 'A' || simbolo == 'a')
			RegraAssalta(arrMapa) || RegraPersegue(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		if (simbolo == 'E' || simbolo == 'e')
			RegraComeMigalha(arrMapa) || RegraPasseia(arrMapa);
		//POR DEFINIR
		/*if (simbolo == 'S' || simbolo == 's')
		RegraFoge() || RegraComeMigalha() || RegraProcuraMigalha() || RegraVaiParaNinho() || RegraPasseia();*/
	}
}

int Formiga::N_formiga = 1;
Formiga::Formiga(posXY pos, char type, Ninho* ninho)
{
	//Inicializa vars
		posElemento = pos;
		simbolo = type;
		motherLand = ninho;
		ID_formiga = N_formiga;
	//Incrementa ID para a próxima formiga a ser criada
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
