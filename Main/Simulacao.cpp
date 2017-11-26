#include "stdafx.h"
#include "Simulacao.h"

//Apresenta os valores das configs iniciais com cores
void Simulacao::PrintValorPropInicial(string prop)
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

//Imprime o ecr� das configs iniciais
void Simulacao::PrintConfigsIniciais() {
	cout << "Configura" << (char)135 << (char)147 << "es iniciais:\r\n\nComandos:\r\n";

	cout << " -> defmundo     "; PrintValorPropInicial("defmundo"); cout << "\r\n";
	cout << " -> defen        "; PrintValorPropInicial("defen"); cout << "\r\n";
	cout << " -> defpc        "; PrintValorPropInicial("defpc"); cout << "\r\n";
	cout << " -> defvt        "; PrintValorPropInicial("defvt"); cout << "\r\n";
	cout << " -> defmi        "; PrintValorPropInicial("defmi"); cout << "\r\n";
	cout << " -> defme        "; PrintValorPropInicial("defme"); cout << "\r\n";
	cout << " -> defnm        "; PrintValorPropInicial("defnm"); cout << "\r\n";
	
	cout << " -> executa      <nomeficheiro>\r\n";
	cout << " -> inicio\r\n\n";
}

//Divide uma string por "del", retorna array
vector<string> Simulacao::explode(string str, char del)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : str)
	{
		if (n != del)
			buff += n;
		else if (n == del && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

//L� comando e guarda na var "comando" da classe
void Simulacao::ScanConfig() {
	cout << "Sintaxe: [COMANDO] [VALOR]\r\n";
	cout << "Escreva o comando a executar : \r\n";
	cin >> comando;
}

//TODO: Come�a simula��o
void Simulacao::Start() {
	cout << "COMECOU A SIMULACAO";
}

//Construtor Simula��o
Simulacao::Simulacao()
{
}

//Destrutor simula��o (Liberta mem�ria)
Simulacao::~Simulacao()
{
	delete mapa;
}