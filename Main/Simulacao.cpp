#include "stdafx.h"
#include "Simulacao.h"


void Simulacao::PrintValorProp(string prop)
{
	string propVal = "indefinido";

	if (prop == "defmundo")
	{
		if (limiteMapa != -1)
			propVal = to_string(limiteMapa);
	}
	else if (prop == "defen")
	{
		if (energiaInitNinhos != -1)
			propVal = to_string(energiaInitNinhos);
	}
	else  if (prop == "defpc")
	{
		if (percentEnergiaNovaFormiga != -1)
			propVal = to_string(percentEnergiaNovaFormiga);
	}
	else  if (prop == "defvt")
	{
		if (energiaNinhoParaFormiga != -1)
			propVal = to_string(energiaNinhoParaFormiga);
	}
	else  if (prop == "defmi")
	{
		if (percentDeMigalhasIniciais != -1)
			propVal = to_string(percentDeMigalhasIniciais);
	}
	else  if (prop == "defme")
	{
		if (energiaNovasMigalhas != -1)
			propVal = to_string(energiaNovasMigalhas);
	}
	else  if (prop == "defnm")
	{
		if (maxMigalhasPorIteracao != -1)
			propVal = to_string(maxMigalhasPorIteracao);
	}
	
	Ecra::PrintTextoColorido(propVal, (propVal == "indefinido"?"vermelho":"verde") , "default");
}

void Simulacao::PrintConfigsIniciais() {
	cout << "Configura" << (char)135 << (char)147 << "es iniciais:\r\n\nComandos:\r\n";

	cout << " -> defmundo     "; PrintValorProp("defmundo"); cout << "\r\n";
	cout << " -> defen        "; PrintValorProp("defen"); cout << "\r\n";
	cout << " -> defpc        "; PrintValorProp("defpc"); cout << "\r\n";
	cout << " -> defvt        "; PrintValorProp("defvt"); cout << "\r\n";
	cout << " -> defmi        "; PrintValorProp("defmi"); cout << "\r\n";
	cout << " -> defme        "; PrintValorProp("defme"); cout << "\r\n";
	cout << " -> defnm        "; PrintValorProp("defnm"); cout << "\r\n";
	
	cout << " -> executa      <nomeficheiro>\r\n";
	cout << " -> inicio\r\n\n";
}


void Simulacao::ScanConfig() {
		cout << "Sintaxe: [COMANDO] [VALOR]\r\n";
		cout << "Escreva o comando a executar : \r\n";
}

void Simulacao::Start() {
	cout << "COMECOU A SIMULACAO";
}

Simulacao::Simulacao()
{
}

Simulacao::~Simulacao()
{
	delete mapa;
}