#pragma once
#include "Ecra.h"
#include "Formiga.h"
#include "Migalha.h"
#include "Ninho.h"

class Mapa : public Ecra
{

public:
	/*Pensar se vale a pena usar este código, ou gerar um array e desenhar o mapa a partir desse array*/
	/*static void DrawMap(int limite = 10) {
		for (int i = 0; i < limite + 2; i++)
			cout << "X ";
		cout << "\n";
		for (int l = 0; l < limite; l++)
		{
			cout << "X ";
			for (int h = 0; h < limite; h++)
			{
				if (rand() % (100 + 1) < 50)
					
					cout << "  ";
				else
					cout << "O ";
			}
			cout << "X\n";
		}

		for (int i = 0; i < limite + 2; i++)
			cout << "X ";
	}*/
	Mapa();
};

