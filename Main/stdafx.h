#pragma once

#include "targetver.h"
#include <Windows.h>
#include <vector>		//Para poder utilizar -> vetores dinâmicos
#include <iostream>		//Para poder utilizar -> "cin"s e "cout"s
#include <string>		//Para poder utilizar -> strings
#include <conio.h>		//Para poder utilizar -> _getch();
#include <fstream>
#include <time.h>
#include <stdlib.h>     /* abs */
#include <ctype.h>		/* toupper */

using namespace std;

/* NOTA: As estruturas abaixo não estão aqui para compilarem mais rápido,
 * mas porque são usadas em quase todas as classes do programa, e este
 * ficheiro é incluido em todos os ficheiros (*.cpp) do projecto.
 */
struct posXYStruct {
	int x, y;
} typedef posXY;