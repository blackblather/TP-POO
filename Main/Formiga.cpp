#include "stdafx.h"
#include "Ninho.h"
#include "Formiga.h"

//Regras
bool Formiga::RegraFoge(char** arrMapa, int tamMapa, vector<Ninho>* pNinhos) {
	for (auto itN = (*pNinhos).begin(); itN != (*pNinhos).end(); itN++)
		for (auto itF = itN->formigas.begin(); itF != itN->formigas.end(); itF++) {
			if (itF->ID_formiga != ID_formiga && itF->motherLand != motherLand) {
				if (max(abs(posElemento.x - itF->posElemento.x), abs(posElemento.y - itF->posElemento.y)) <= raioVisao) {
				//encontrou enimigo no campo de visao
					arrMapa[posElemento.y][posElemento.x] = ' ';
					if (posElemento.x < itF->posElemento.x && posElemento.x > 0)
						posElemento.x--;
					else if (posElemento.x > itF->posElemento.x && posElemento.x < tamMapa - 1)
						posElemento.x++;
					if (posElemento.y < itF->posElemento.y && posElemento.y > 0)
						posElemento.y--;
					else if (posElemento.y > itF->posElemento.y && posElemento.y < tamMapa - 1)
						posElemento.y++;
					arrMapa[posElemento.y][posElemento.x] = simbolo;
					return true;
				}
			}
		}
	return false;
}			//Should be done
bool Formiga::RegraPersegue(char** arrMapa) { return false; }
bool Formiga::RegraAssalta(char** arrMapa, int tamMapa, vector<Ninho>* pNinhos) {
	return false;
}		//TODO
bool Formiga::RegraProtege(char** arrMapa) { return false; }
bool Formiga::RegraProcuraMigalha(char** arrMapa) { return false; }	//TODO
bool Formiga::RegraComeMigalha(char** arrMapa) { return false; }
bool Formiga::RegraVaiParaNinho(char** arrMapa) { return false; }	//TODO
bool Formiga::RegraPasseia(char** arrMapa) { return false; }
//Prioridades das regras / Execução das regras
void Formiga::ActionFormiga(char** arrMapa, int tamMapa, vector<Ninho>* pNinhos) {
	if (is_in_nest) {
		//Does whatever it is ants do in nests
	}
	else {
		//Executa regras de acordo com o tipo de formiga até uma função retornar "true"
		if (simbolo == 'C' || simbolo == 'c')
			RegraFoge(arrMapa, tamMapa, pNinhos) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraVaiParaNinho(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'V' || simbolo == 'v')
			RegraProtege(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'A' || simbolo == 'a')
			RegraAssalta(arrMapa, tamMapa, pNinhos) || RegraPersegue(arrMapa) || RegraComeMigalha(arrMapa) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
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
		simbolo = toupper(type);
		switch (simbolo) {
			case 'C': {
				raioVisao = 5;
				raioMovimento = 3;
				energia = 100;
			} break;
			case 'V': {
				raioVisao = 7;
				raioMovimento = 5;
				energia = 150;
			} break;
			case 'A': {
				raioVisao = 8;
				raioMovimento = 4;
				energia = 80;
			} break;
			case 'E': {
				raioVisao = 10;
				raioMovimento = 8;
				energia = 200;
			} break;
			case 'S': {
				raioVisao = 6;
				raioMovimento = 8;
				energia = 500;
			} break;
		}
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