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

//Imprime o ecrã das configs iniciais
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

//Lê comando e guarda na var "comando" da classe
void Simulacao::ScanConfig() {
	cout << "Sintaxe: [COMANDO] [VALOR]\r\n";
	cout << "Escreva o comando a executar : \r\n";
	getline(cin, comando);
}

vector<string> Simulacao::Explode(string str, char del)
{
	vector<string> partAux;
	string buffer = "";
	int tam = str.length();
	char charHere;

	if (tam > 0)
	{
		for (int i = 0; i != tam; i++)
		{
			charHere = str.at(i);
			if (buffer != "" && charHere == del) {
				partAux.push_back(buffer);
				buffer = "";
			}
			else if (charHere != ' ')
				buffer += charHere;
		}
	}
	if (buffer != "")
		partAux.push_back(buffer);

	return partAux;
}

bool Simulacao::ComandoEValido(vector<string> comandoPart) {
	if (comandoPart.size() == 2)
		if (comandoPart[0] == "defmundo" && stoi(comandoPart[1], nullptr, 10) >= 10)
			return true;
		else if (comandoPart[0] == "defen" && stoi(comandoPart[1], nullptr, 10) >= 1)
				 return true;
		else if (comandoPart[0] == "defvt" && stoi(comandoPart[1], nullptr, 10) >= 1)
				 return true;
		else if (comandoPart[0] == "defme" && stoi(comandoPart[1], nullptr, 10) >= 1)
				 return true;
		else if (comandoPart[0] == "defnm" && stoi(comandoPart[1], nullptr, 10) >= 1)
				 return true;
		else if (comandoPart[0] == "defpc" && stod(comandoPart[1]) >= 0 && stod(comandoPart[1]) <= 100)
				 return true;
		else if (comandoPart[0] == "defmi" && stod(comandoPart[1]) >= 0 && stod(comandoPart[1]) <= 100)
				 return true;

	return false;
}

void Simulacao::ExecutaComando() {
	vector<string> comandoPart = Explode(comando, ' ');
	if (ComandoEValido(comandoPart))
	{
		//DOES STUFF
		cout << comandoPart[0] << endl;
		cout << comandoPart[1] << endl;
	}
}

//TODO: Começa simulação
void Simulacao::Start() {
	cout << "COMECOU A SIMULACAO";
}

//Construtor Simulação
Simulacao::Simulacao()
{
}

//Destrutor simulação (Liberta memória)
Simulacao::~Simulacao()
{
	delete mapa;
}