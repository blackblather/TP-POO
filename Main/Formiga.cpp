#include "stdafx.h"
#include "Formiga.h"

bool Formiga::RegraFoge() { return false; }
bool Formiga::RegraPersegue() { return false; }
bool Formiga::RegraAssalta() { return false; }
bool Formiga::RegraProtege() { return false; }
bool Formiga::RegraProcuraMigalha() { return false; }
bool Formiga::RegraComeMigalha() { return false; }
bool Formiga::RegraVaiParaNinho() { return false; }
bool Formiga::RegraPasseia() { return false; }

void Formiga::ActionFormiga(char** arrMapa) {
	if (is_in_nest) {

	}
	else {
		//Executa regras de acordo com o tipo de formiga até uma função retornar "true"
		if (simbolo == 'C' || simbolo == 'c')
			RegraFoge() || RegraComeMigalha() || RegraProcuraMigalha() || RegraVaiParaNinho() || RegraPasseia();
		if (simbolo == 'V' || simbolo == 'v')
			RegraProtege() || RegraComeMigalha() || RegraProcuraMigalha() || RegraPasseia();
		if (simbolo == 'A' || simbolo == 'a')
			RegraAssalta() || RegraPersegue() || RegraComeMigalha() || RegraProcuraMigalha() || RegraPasseia();
		if (simbolo == 'E' || simbolo == 'e')
			RegraComeMigalha() || RegraPasseia();
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
