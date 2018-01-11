#include "stdafx.h"
#include "Ninho.h"
#include "Formiga.h"

//Regras
bool Formiga::RegraFoge(char** arrMapa, vector<Ninho>* pNinhos) {
	for (auto itN = (*pNinhos).begin(); itN != (*pNinhos).end(); itN++)
		for (auto itF = itN->formigas.begin(); itF != itN->formigas.end(); itF++)
			if (max(abs(posElemento.x - itF->posElemento.x), abs(posElemento.y - itF->posElemento.y)) <= raioVisao) {
				//encontrou enimigo no campo de visao
				arrMapa[posElemento.x][posElemento.y] = ' ';
				if (posElemento.x < itF->posElemento.x && posElemento.x > 0)
					posElemento.x--;
				if (posElemento.y < itF->posElemento.y && posElemento.y > 0)
					posElemento.y--;
				arrMapa[posElemento.x][posElemento.y] = simbolo;
				return true;
			}
	return false;
}			//TODO
bool Formiga::RegraPersegue(char** arrMapa) { return false; }
bool Formiga::RegraAssalta(char** arrMapa) { return false; }		//TODO
bool Formiga::RegraProtege(char** arrMapa) { return false; }
bool Formiga::RegraProcuraMigalha(char** arrMapa) { return false; }	//TODO
bool Formiga::RegraComeMigalha(char** arrMapa) { return false; }
bool Formiga::RegraVaiParaNinho(char** arrMapa) { return false; }	//TODO
bool Formiga::RegraPasseia(char** arrMapa) { return false; }
//Prioridades das regras / Execução das regras
void Formiga::ActionFormiga(char** arrMapa, vector<Ninho>* pNinhos) {
	if (is_in_nest) {
		//Does whatever it is ants do in nests
	}
	else {
		//Executa regras de acordo com o tipo de formiga até uma função retornar "true"
		if (simbolo == 'C' || simbolo == 'c')
			RegraFoge(arrMapa, pNinhos) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraVaiParaNinho(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'V' || simbolo == 'v')
			RegraProtege(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'A' || simbolo == 'a')
			RegraAssalta(arrMapa) || RegraPersegue(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'E' || simbolo == 'e')
			RegraComeMigalha(arrMapa) || RegraPasseia(arrMapa);
		//POR DEFINIR
		/*if (simbolo == 'S' || simbolo == 's')
		RegraFoge() || RegraComeMigalha() || RegraProcuraMigalha() || RegraVaiParaNinho() || RegraPasseia();*/
	}
}
//Construtor/Destrutor
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
//Gets
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