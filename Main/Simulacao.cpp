#include "stdafx.h"
#include "Simulacao.h"

const string Simulacao::Comando() const {
	return comando;
}

int Simulacao::PropNameToArrayIndex(const string& str)
{
	if (str == "defmundo") return limiteMapa;
	else if (str == "defen") return energiaInitNinhos;
	else if (str == "defpc") return percentEnergiaNovaFormiga;
	else if (str == "defvt") return energiaNinhoParaFormiga;
	else if (str == "defmi") return percentDeMigalhasIniciais;
	else if (str == "defme") return energiaNovasMigalhas;
	else if (str == "defnm") return maxMigalhasPorIteracao;
	return -1;
}

//Apresenta os valores das configs iniciais com cores
void Simulacao::PrintValorPropInicial(const string& prop)
{
	string propVal = "indefinido";

	if (prop == "defmundo" || prop == "defen" || prop == "defpc" || prop == "defvt" || prop == "defmi" || prop == "defme" || prop == "defnm")
		if (configsIniciais[PropNameToArrayIndex(prop)] != -1)
			propVal = to_string(configsIniciais[PropNameToArrayIndex(prop)]);
	
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

vector<string> Simulacao::Explode(const string& str, const char& del)
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
			else if (charHere != del)
				buffer += charHere;
		}
	}
	if (buffer != "")
		partAux.push_back(buffer);

	return partAux;
}

bool Simulacao::ComandoEValido(const vector<string>& comandoPart) {
	if (comandoPart.size() == 2) {
		int valor = stoi(comandoPart[1], nullptr, 10);
		if ((comandoPart[0] == "defmundo" && valor >= 10) ||
			((comandoPart[0] == "defen" || comandoPart[0] == "defvt" || comandoPart[0] == "defme" || comandoPart[0] == "defnm") && valor >= 1) || 
			((comandoPart[0] == "defpc" || comandoPart[0] == "defmi") && valor >= 0 && valor <= 100))
			return true;
	}
	return false;
}

void Simulacao::SetConfigInicial() {
	vector<string> comandoPart = Explode(comando, ' ');
	if (ComandoEValido(comandoPart)) {
		configsIniciais[PropNameToArrayIndex(comandoPart[0])] = stoi(comandoPart[1], nullptr, 10);
	}
}

//TODO: Começa simulação
void Simulacao::Start() {
	cout << "COMECOU A SIMULACAO";
}

//Construtor Simulação
Simulacao::Simulacao()
{
	//Inicializa as configs iniciais
	configsIniciais[limiteMapa] = -1;					// defmundo <limiteMapa>
	configsIniciais[energiaInitNinhos] = -1;			// defen <energiaInitNinhos>
	configsIniciais[energiaNinhoParaFormiga] = 1;		// defvt <energiaNinhoParaFormiga>
	configsIniciais[energiaNovasMigalhas] = -1;			// defme <energiaNovasMigalhas>
	configsIniciais[qtdMigalhasIniciais] = -1;			/*AUX -> (int)((limiteMapa*limiteMapa) * percentDeMigalhasIniciais/100)*/
	configsIniciais[maxMigalhasPorIteracao] = -1;		// defnm <maxMigalhas>
	configsIniciais[percentEnergiaNovaFormiga] = -1;	// defpc <percentEnergiaNovaFormiga>
	configsIniciais[percentDeMigalhasIniciais] = -1;	// defmi <percentDeMigalhasIniciais>
}

//Destrutor simulação
Simulacao::~Simulacao()
{
	//Liberta memória
	delete mapa;
}