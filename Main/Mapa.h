#pragma once
class Mapa
{
public:
	Mapa();
	static void DrawMap(int lenght = 10, int height = 10) {
		for (int i = 0; i < lenght + 2; i++)
			printf("X ");
		printf("\n");

		for (int l = 0; l < lenght; l++)
		{
			printf("X ");
			for (int h = 0; h < height; h++)
			{

				printf("  ");
			}
			printf("X\n");
		}

		for (int i = 0; i < lenght + 2; i++)
			printf("X ");
	}
};

