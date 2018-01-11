#include "stdafx.h"
#include "Ninho.h"
#include "Formiga.h"
#include "Migalha.h"

//Regras
bool Formiga::RegraFoge(char** arrMapa, int tamMapa, vector<Ninho>* pNinhos) {
	for (auto itN = (*pNinhos).begin(); itN != (*pNinhos).end(); itN++)
		for (auto itF = itN->formigas.begin(); itF != itN->formigas.end(); itF++) {
			if (itF->motherLand != motherLand &&
				max(abs(posElemento.x - itF->posElemento.x), abs(posElemento.y - itF->posElemento.y)) <= raioVisao) {
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
	return false;
}			//TODO
bool Formiga::RegraPersegue(char** arrMapa, vector<Ninho>* pNinhos) {
	vector<Formiga> inimigos_percecionados;
	for (auto itN = (*pNinhos).begin(); itN != (*pNinhos).end(); itN++)
		for (auto itF = itN->formigas.begin(); itF != itN->formigas.end(); itF++)
			if (max(abs(posElemento.x - itF->posElemento.x), abs(posElemento.y - itF->posElemento.y)) <= raioVisao) {
				if (itF->ID_formiga != ID_formiga && itF->motherLand != motherLand) {
					//encontrou enimigo no campo de visao
					inimigos_percecionados.push_back(*itF);
				}

			}
	vector<Formiga>::iterator best = inimigos_percecionados.end();
	for (auto itP = inimigos_percecionados.begin(); itP != inimigos_percecionados.end(); itP++)
	{
		if (itP == inimigos_percecionados.begin())
			best = itP;
		else if (itP->energia > best->energia) //assim escolhe sempre o primeiro que encontrar com mais energia
			best = itP;
	}
	if (best != inimigos_percecionados.end()) {
		arrMapa[posElemento.y][posElemento.x] = ' ';
		if (posElemento.x < best->posElemento.x && posElemento.x > 0)
			posElemento.x++;
		if (posElemento.y < best->posElemento.y && posElemento.y > 0)
			posElemento.y++;
		arrMapa[posElemento.y][posElemento.x] = simbolo;
		return true;
	}
	return false;
}
bool Formiga::RegraAssalta(char** arrMapa, int tamMapa, vector<Ninho>* pNinhos) { return false; }		//TODO
bool Formiga::RegraProtege(char** arrMapa, vector<Ninho>* pNinhos) {
	vector<Formiga> inimigos_percecionados;
	vector<Formiga> aliados_percecionados;
	for (auto itN = (*pNinhos).begin(); itN != (*pNinhos).end(); itN++)
		for (auto itF = itN->formigas.begin(); itF != itN->formigas.end(); itF++)
			if (max(abs(posElemento.x - itF->posElemento.x), abs(posElemento.y - itF->posElemento.y)) <= raioVisao) {
				if (itF->ID_formiga != ID_formiga && itF->motherLand != motherLand) {
					//encontrou enimigo no campo de visao
					inimigos_percecionados.push_back(*itF);
				}
				else if (itF->ID_formiga != ID_formiga && itF->motherLand == motherLand) 
				{
					aliados_percecionados.push_back(*itF);
				}

			}
	if (inimigos_percecionados.begin() != inimigos_percecionados.end() && aliados_percecionados.begin() != aliados_percecionados.end())
	{
		float x_med = (inimigos_percecionados.begin()->posElemento.x + aliados_percecionados.begin()->posElemento.x) / 2;
		int Int_x = (int)(x_med + 0.5);
		float y_med = (inimigos_percecionados.begin()->posElemento.y + aliados_percecionados.begin()->posElemento.y) / 2;
		int Int_y = (int)(y_med + 0.5);
		int moves_x = 0;
		int moves_y = 0;
		arrMapa[posElemento.y][posElemento.x] = ' ';
		for (int i = 0; i < raioMovimento && moves_x != raioMovimento; i++) 
		{
			if (posElemento.x <= Int_x) 
			{
				if (posElemento.x != Int_x)
				{
					posElemento.x++;
					moves_x++;
				}
			}
			else {
				posElemento.x--;
				moves_x++;
			}
		}
		for (int i = 0; i < raioMovimento && moves_y != raioMovimento; i++)
		{
			if (posElemento.y <= Int_y)
			{
				if (posElemento.y != Int_y)
				{
					posElemento.y++;
					moves_y++;
				}
			}
			else {
				posElemento.y--;
				moves_y++;
			}
		}
		arrMapa[posElemento.y][posElemento.x] = simbolo;
		return true;
	}
	else
	{
		return false;
	}
}
bool Formiga::RegraProcuraMigalha(char** arrMapa) { return false; }	//TODO
bool Formiga::RegraComeMigalha(char** arrMapa, vector<Migalha>* pMigalhas) {
	bool eat = false;
	posXY aux;
	for (auto itM = (*pMigalhas).begin(); itM != (*pMigalhas).end(); itM++)
	{
		if (itM->posElemento.x == posElemento.x && itM->posElemento.y == posElemento.y)
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true; 
		}
		else if (itM->posElemento.x == posElemento.x +1 && itM->posElemento.y == posElemento.y) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x +1 && itM->posElemento.y == posElemento.y +1) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x && itM->posElemento.y == posElemento.y +1) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x -1 && itM->posElemento.y == posElemento.y +1) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x -1 && itM->posElemento.y == posElemento.y) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x -1 && itM->posElemento.y == posElemento.y -1) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x && itM->posElemento.y == posElemento.y -1) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		else if (itM->posElemento.x == posElemento.x +1 && itM->posElemento.y == posElemento.y -1) 
		{
			aux.x = itM->posElemento.x; aux.y = itM->posElemento.y; eat = true;
		}
		if (eat) {
			if (simbolo == 'C' || simbolo == 'c')
			{
				energia = energia + (itM->energia / 2);
				itM->energia = (itM->energia / 2);
			}
			else if (simbolo == 'V' || simbolo == 'v')
			{
				energia = energia + ((3*itM->energia) / 4);
				itM->energia = (itM->energia / 4);
			}
			else if (simbolo == 'A' || simbolo == 'a')
			{
				energia = energia + (itM->energia / 4);
				itM->energia = ((3*itM->energia) / 4);
			}
			else if (simbolo == 'E' || simbolo == 'e')
			{
				energia = energia + itM->energia;
				itM->energia = 0;
			}
		}
	}
	return false; 
}
bool Formiga::RegraVaiParaNinho(char** arrMapa) { return false; }	//TODO
bool Formiga::RegraPasseia(char** arrMapa) { return false; }
//Prioridades das regras / Execução das regras
void Formiga::ActionFormiga(char** arrMapa, int tamMapa, vector<Ninho>* pNinhos, vector<Migalha>* pMigalhas) {
	if (is_in_nest) {
		//Does whatever it is ants do in nests
	}
	else {
		//Executa regras de acordo com o tipo de formiga até uma função retornar "true"
		if (simbolo == 'C' || simbolo == 'c')
			RegraFoge(arrMapa, tamMapa, pNinhos) || RegraComeMigalha(arrMapa, pMigalhas) || RegraProcuraMigalha(arrMapa) || RegraVaiParaNinho(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'V' || simbolo == 'v')
			RegraProtege(arrMapa, pNinhos) || RegraComeMigalha(arrMapa, pMigalhas) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'A' || simbolo == 'a')
		RegraAssalta(arrMapa, tamMapa, pNinhos) || RegraPersegue(arrMapa, pNinhos) || RegraComeMigalha(arrMapa, pMigalhas) || RegraProcuraMigalha(arrMapa) || RegraPasseia(arrMapa);
		else if (simbolo == 'E' || simbolo == 'e')
			RegraComeMigalha(arrMapa, pMigalhas) || RegraPasseia(arrMapa);
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