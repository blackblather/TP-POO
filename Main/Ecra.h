#pragma once	//Para poder utilizar estrutura "COORD"

class Ecra
{
public:
	//Mete cursor na posição XY
	static void gotoxy(posXY pos)
	{
		COORD coord;
		coord.X = pos.x;
		coord.Y = pos.y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	//Limpa o ecrã
	static void LimpaEcra() {
		COORD topLeft = { 0, 0 };
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO screen;
		DWORD written;

		GetConsoleScreenBufferInfo(console, &screen);
		FillConsoleOutputCharacterA(
			console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		FillConsoleOutputAttribute(
			console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
			screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
		SetConsoleCursorPosition(console, topLeft);
	}
	//Muda a cor do texto (a partir da posição do cursor)
	static void SetCorTexto(char* cor)
	{
		/*
		 * 0   BLACK
		 * 1   BLUE
		 * 2   GREEN
		 * 3   CYAN
		 * 4   RED
		 * 5   MAGENTA
		 * 6   BROWN
		 * 7   LIGHTGRAY
		 * 8   DARKGRAY
		 * 9   LIGHTBLUE
		 * 10  LIGHTGREEN
		 * 11  LIGHTCYAN
		 * 12  LIGHTRED
		 * 13  LIGHTMAGENTA
		 * 14  YELLOW
		 * 15  WHITE
		 */

		if (cor == "vermelho")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 | 0);
		else if (cor == "verde")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 0);
		else if (cor == "azul")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 | 0);
		else if (cor == "default")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 | 0);
	}
	//Imprime uma string de uma cor (corNova) e volta à cor inicial (corAntiga)
	static void PrintTextoColorido(string txt, char* corNova, char* corAntiga) {
		if (txt.length() > 0)
		{
			SetCorTexto(corNova);
			cout << txt;
			SetCorTexto(corAntiga);
		}
	}
	Ecra();
};

