// Main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Simulacao.h"

int main()
{
	Simulacao simulacao = Simulacao();
	simulacao.SetConfigs();

	/*
	srand((unsigned int)time(NULL));
	Mapa* mapa = new Mapa();
	mapa = new Mapa();
	while (1)
	{
		(*mapa).DrawMap();
		_getch();
		Ecra::LimpaEcra();
	}*/

    return 0;
}

