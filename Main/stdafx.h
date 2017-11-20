// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <Windows.h>	//Para poder utilizar estrutura "COORD"
#include <iostream>		//Para poder utilizar "cin"s e "cout"s
#include <string>		//Para poder utilizar strings
#include <stdio.h>
#include <conio.h>		//Para poder utilizar _getch();

using namespace std;

//Estruturas específicas do programa em si, e não de uma classe em específico
struct posXYStruct {
	int x, y;
} typedef posXY;

//Defines (TODO -> As 2 primeiras constantes só são conhecidas em runtime)
#define limiteMapa 10												 //Tamanho limite, de uma das dimensões, do mapa (o mapa é quadrado)
#define qtdMigalhasIniciail (int) (limiteMapa*limiteMapa*0.10)		 //10% do mapa vai ser preenchido com migalhas
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define energiaRecebidaDoNinhoPorIteracao (int) 1.0/3.3				 //Energia que as formigas recebem quando estão no ninho
#define percentagemDeEnergiaNecessariaNoNinhoParaCriarNovaFormiga 80




//Header Files específicos do programa
#include "Ecra.h"
#include "Mapa.h"
#include "Elemento.h"
#include "Formiga.h"

