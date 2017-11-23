#include "stdafx.h"
#include "Simulacao.h"

void Simulacao::Start() {
	cout << "COMECOU A SIMULACAO";
}
void Simulacao::SetConfigs()
{
	//pede configs
}

Simulacao::Simulacao()
{
}


Simulacao::~Simulacao()
{
	delete mapa;
}