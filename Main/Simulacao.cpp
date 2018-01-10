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

	Ecra::PrintTextoColorido(propVal, (propVal == "indefinido" ? "vermelho" : "verde"), "default");
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
	cout << "Escreva o comando a executar: \r\n";
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

void Simulacao::ExecutaFicheiro(const string& fileName) {
	vector<string> comandoPart;
	ifstream commandsFile(fileName);
	if (commandsFile.is_open())
	{
		while (getline(commandsFile, comando))
		{
			comandoPart = Explode(comando, ' ');
			if (ComandoEValido(comandoPart))
				SetConfigInicial(comandoPart);
		}
		commandsFile.close();
	}
}

bool Simulacao::ComandoEValido(const vector<string>& comandoPart) {
	try {
		if (comandoPart.size() == 2)
			if (comandoPart[0] != "executa") {
				int valor = stoi(comandoPart[1], nullptr, 10);
				if ((comandoPart[0] == "defmundo" && valor >= 10) ||
					((comandoPart[0] == "defen" || comandoPart[0] == "defvt" || comandoPart[0] == "defme" || comandoPart[0] == "defnm") && valor >= 1) ||
					((comandoPart[0] == "defpc" || comandoPart[0] == "defmi") && valor >= 0 && valor <= 100))
					return true;
			}
			else
				return true;
		else if (comandoPart.size() == 1 && comandoPart[0] == "inicio")
			return true;
		return false;
	}
	catch (...) { //(...) Representa todas as excepções.
		return false;
	}
}

bool Simulacao::is_number(const string& s)
{
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

bool Simulacao::SimComandoEValido(const vector<string>& comandoPart) {
	int valor = -1;
	int valoraux = -1;
	if (comandoPart.size() == 5 && comandoPart[0] == "cria1") 
	{
		bool isnum = is_number(comandoPart[2]);
		bool isnumaux = is_number(comandoPart[3]);
		bool isnumaux2 = is_number(comandoPart[4]);
		if (isnum && isnumaux && isnumaux2) {
			bool exists = this->mapa->Ninho_exists(comandoPart[2]);
			valor = stoi(comandoPart[3], nullptr, 10);
			valoraux = stoi(comandoPart[4], nullptr, 10);
			if (valor >= 0 && valor <= configsIniciais[limiteMapa] && valoraux >= 0 && valoraux <= configsIniciais[limiteMapa] && exists)
			{
				if (comandoPart[1] == "C" || comandoPart[1] == "V" || comandoPart[1] == "A" || comandoPart[1] == "E" || comandoPart[1] == "S" ||
					comandoPart[1] == "c" || comandoPart[1] == "v" || comandoPart[1] == "a" || comandoPart[1] == "e" || comandoPart[1] == "s")
					return true;
			}
		}
	}
	else if (comandoPart.size() == 4 && comandoPart[0] == "criaf")
	{
		bool isnum = is_number(comandoPart[3]);
		bool isnumaux = is_number(comandoPart[1]);
		if (isnum && isnumaux) {
			bool exists = this->mapa->Ninho_exists(comandoPart[3]);
			valor = stoi(comandoPart[1], nullptr, 10);
			if (exists && valor > 0 && valor < (configsIniciais[limiteMapa] * configsIniciais[limiteMapa]))
				//VER ESTE IF COMO DEVE SER (TER EM CONTA AS POSICOES OCUPADAS)
			{
				if (comandoPart[2] == "C" || comandoPart[2] == "V" || comandoPart[2] == "A" || comandoPart[2] == "E" || comandoPart[2] == "S" ||
					comandoPart[2] == "c" || comandoPart[2] == "v" || comandoPart[2] == "a" || comandoPart[2] == "e" || comandoPart[2] == "s")
					return true;
			}
		}
	}
	else if (comandoPart.size() == 4 && comandoPart[0] == "energformiga")
	{
		bool isnum = is_number(comandoPart[1]);
		bool isnumaux = is_number(comandoPart[2]);
		if (isnum && isnumaux) {
			valor = stoi(comandoPart[1], nullptr, 10);
			valoraux = stoi(comandoPart[2], nullptr, 10);
			if (valor >= 0 && valor <= configsIniciais[limiteMapa] && valoraux >= 0 && valoraux <= configsIniciais[limiteMapa])
			{
				bool isnumaux2 = is_number(comandoPart[3]);
				if (isnumaux2)
				if (stoi(comandoPart[3], nullptr, 10) >= 0)
				{
					bool isnum = is_number(comandoPart[3]);
					if (isnum == 1)
					{
						return true;
					}
				}
			}
		}
	}
	else if (comandoPart.size() == 3)
	{
		if (comandoPart[0] == "ninho" || comandoPart[0] == "migalha" || comandoPart[0] == "foca" ||
			comandoPart[0] == "mata"  || comandoPart[0] == "listaposicao") {
			if (is_number(comandoPart[1]) && is_number(comandoPart[2])) {
				valor = stoi(comandoPart[1], nullptr, 10);
				valoraux = stoi(comandoPart[2], nullptr, 10);
				if (valor >= 0 && valor <= configsIniciais[limiteMapa] &&
					valoraux >= 0 && valoraux <= configsIniciais[limiteMapa])
					return true;
			}
		}
		else if (comandoPart[0] == "energninho")
		{
			bool exists = this->mapa->Ninho_exists(comandoPart[1]);
			if (stoi(comandoPart[2], nullptr, 10) >= 0)
			{
				bool isnum = is_number(comandoPart[2]);
				if (isnum == 1 && exists)
				{
					return true;
				}
			}
		}
	}
	else if (comandoPart.size() == 2) {
		if (comandoPart[0] == "tempo" || comandoPart[0] == "inseticida" || comandoPart[0] == "listaninho") {
			bool exists;
			bool ret = is_number(comandoPart[1]);
			if (ret)
			{
				if (comandoPart[0] != "tempo") {
					exists = this->mapa->Ninho_exists(comandoPart[1]);
					if (exists)
						return true;
				}
				else {
					valor = stoi(comandoPart[1], nullptr, 10);
					if (valor >= 0)
						return true;
				}
			}
		}
		else if (comandoPart[0] == "guarda" || comandoPart[0] == "muda" || comandoPart[0] == "apaga")
			//para depois fazer a <guarda> <muda> e <apaga>
		{
			return true;
		}
	}
	else if (comandoPart.size() == 1 && comandoPart[0] == "sair" || comandoPart[0] == "listamundo" || comandoPart[0] == "tempo")
		return true;
	return false;
}

void Simulacao::SetConfigInicial(vector<string> comandoPart) {
	configsIniciais[PropNameToArrayIndex(comandoPart[0])] = stoi(comandoPart[1], nullptr, 10);

}

//Verifica se todas as configs iniciais estão definidas. Usado para verificar se pode começar a simulação.
bool Simulacao::TodasAsConfigIniciasEstaoDefinidas() {
	//Assume que as que não estão definidas, têm valor: -1
	int totalConfigsSet = 0;
	for (int i = 0; i != qtdConfigsInciais; i++)
		if (configsIniciais[i] != -1)
			totalConfigsSet++;
	if (totalConfigsSet == qtdConfigsInciais)
		return true;
	return false;
}

void Simulacao::InicializaMapa() {
	mapa = new Mapa(configsIniciais[limiteMapa],
		configsIniciais[energiaNovasMigalhas],
		configsIniciais[percentDeMigalhasIniciais]);
}

void Simulacao::PrintStatsAt(posXY posicaoInicial) {
	Ecra::gotoxy(posicaoInicial);
	cout << "Dimensoes: " << configsIniciais[limiteMapa] << " x " << configsIniciais[limiteMapa];
}

void Simulacao::PrintSimulacaoNoEstadoAtual() {
	//Vars auxiliares
	posXY posAux;
	//Desenha mapa
	(*mapa).DrawMap(configsIniciais[limiteMapa]);
	//Define as coords para escrever as stats
	posAux.x = 3 * configsIniciais[limiteMapa];
	posAux.y = 0;
	//Imprime stats
	PrintStatsAt(posAux);
	//Mete o cursor abaixo do mapa (com uma linha de espaço)
	posAux.x = 0;
	posAux.y = configsIniciais[limiteMapa] + 2;
	Ecra::gotoxy(posAux);
}

void Simulacao::Tick(int qtd) {
	for (int i = 0; i < qtd; i++) {
		//mapa->ActionNinhos();
		mapa->ActionFormigas();
		//mapa->ActionMigalhas();
	}
}

void Simulacao::ExecutaComando(vector<string> comandoPart) {
	if (comandoPart[0] == "ninho") {
		posXY pos{ stoi(comandoPart[1]) ,stoi(comandoPart[2]) };
		Ninho ninhoTmp = Ninho(pos);
		mapa->CriaNinho(ninhoTmp);
	}
	else if (comandoPart[0] == "criaf") {
		mapa->CriaF(stoi(comandoPart[1]), comandoPart[2].at(0), stoi(comandoPart[3]));
	}
	else if (comandoPart[0] == "cria1")
	{
		
	}
	else if (comandoPart[0] == "migalha")
	{
		
	}
	else if (comandoPart[0] == "foca")
	{
		
	}
	else if (comandoPart[0] == "tempo")
	{
		if (comandoPart.size() == 2) {}
		else {}
	}
	else if (comandoPart[0] == "energninho")
	{
		
	}
	else if (comandoPart[0] == "energformiga")
	{
		
	}
	else if (comandoPart[0] == "mata")
	{
		
	}
	else if (comandoPart[0] == "inseticida")
	{
		
	}
	else if (comandoPart[0] == "listamundo")
	{
		mapa->ListaElementos(configsIniciais[limiteMapa]);
		
	}
	else if (comandoPart[0] == "listaninho")
	{
		mapa->ListaNinho(stoi(comandoPart[1], nullptr, 10));
		
	}
	else if (comandoPart[0] == "listaposicao")
	{
		posXY xy;
		xy.x = stoi(comandoPart[1], nullptr, 10);
		xy.y = stoi(comandoPart[2], nullptr, 10);
		mapa->ListaPosicao(xy, configsIniciais[limiteMapa]);
	}
	else if (comandoPart[0] == "guarda")
	{

	}
	else if (comandoPart[0] == "muda")
	{
	}
	else if (comandoPart[0] == "apaga")
	{

	}
	else
	{

	}
}

int Simulacao::GetLimiteMapa() const
{
	return this->configsIniciais[limiteMapa];
}

//Construtor Simulação
Simulacao::Simulacao()
{
	//Inicializa as configs iniciais
	configsIniciais[limiteMapa] = -1;					// defmundo <limiteMapa>
	configsIniciais[energiaInitNinhos] = -1;			// defen <energiaInitNinhos>
	configsIniciais[energiaNinhoParaFormiga] = 1;		// defvt <energiaNinhoParaFormiga>
	configsIniciais[energiaNovasMigalhas] = -1;			// defme <energiaNovasMigalhas>
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