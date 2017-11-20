#pragma once
class Mapa : public Ecra
{

public:
	static void DrawMap(int limite = limiteMapa) {
		for (int i = 0; i < limite + 2; i++)
			cout << "X ";
		cout << "\n";

		for (int l = 0; l < limite; l++)
		{
			cout << "X ";
			for (int h = 0; h < limite; h++)
			{
				if ((rand() % 100 + 1) <= 90)
					cout << "  ";
				else
					cout << "O ";
			}
			cout << "X\n";
		}

		for (int i = 0; i < limite + 2; i++)
			cout << "X ";
	}
	Mapa();
};

