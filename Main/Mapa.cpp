#include "stdafx.h"
#include "Mapa.h"

//Inicialização do estado inicial do mapa
void Mapa::PreencheMapaComMigalhasIniciais(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	int inseridas = 0;
	posXY posAux;
	while (inseridas < qtdMigalhasIniciais) {
		posAux.x = rand() % limite;
		posAux.y = rand() % limite;
		if (arrMapa[posAux.y][posAux.x] == ' ') {
			migalhas.push_back(*(new Migalha(posAux, percentDeMigalhasIniciais)));
			arrMapa[posAux.y][posAux.x] = crumbSymbol;
			inseridas++;
		}
	}
}
void Mapa::PreencheMapaInicial(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	for (int x = 0; x < limite; x++)
		for (int y = 0; y < limite; y++)
			arrMapa[x][y] = ' ';
	PreencheMapaComMigalhasIniciais(limite, qtdMigalhasIniciais, percentDeMigalhasIniciais);
}
void Mapa::InicializaArrayMapa(const int& limite, const int& qtdMigalhasIniciais, const int& percentDeMigalhasIniciais) {
	arrMapa = new char*[limite];
	for (int i = 0; i < limite; i++)
		arrMapa[i] = new char[limite];
	PreencheMapaInicial(limite, qtdMigalhasIniciais, percentDeMigalhasIniciais);
}
//Imprimir mapa
void Mapa::DrawMap(const int& limite) {
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
	cout << "\r\n";
	for (int x = 0; x < limite; x++)
	{
		cout << "X ";
		for (int y = 0; y < limite; y++)
			cout << arrMapa[x][y] << ' ';
		cout << "X\r\n";
	}
	for (int i = 0; i < limite + 2; i++)
		cout << "X ";
}
//Verificacoes
bool Mapa::PosEstaLivre(posXY pos) {
	if (arrMapa[pos.y][pos.x] == ' ')
		return true;
	return false;
}
//Listagens
void Mapa::ListaElementos(int limiteMapa) const
{
	posXY xy;
	for (xy.x = 0; xy.x < limiteMapa; xy.x++)
		for (xy.y = 0; xy.y < limiteMapa; xy.y++)
			if (arrMapa[xy.y][xy.x] == crumbSymbol)
				cout << "Migalha!" << " (x=" << xy.x << ";y=" << xy.y << ")" << endl;
			else if (arrMapa[xy.y][xy.x] == nestSymbol)
			{
				cout << "Ninho!" << " (x=" << xy.x << ";y=" << xy.y << ")" << endl;
				for (auto it = ninhos.begin(); it != ninhos.end(); it++)
					if (it->GetPosNinho().x == xy.x && it->GetPosNinho().y == xy.y)
						it->NinhoInfoSimple();
			}
}
void Mapa::ListaNinho(int ID_ninho) const
{
	for (auto it = ninhos.begin(); it != ninhos.end(); it++)
		if (ID_ninho == it->GetNinhoID())
			it->NinhoInfoDetailed();
}
void Mapa::ListaPosicao(posXY xy, int limiteMapa) const
{
	if (xy.x > 0 && xy.x <= limiteMapa && xy.y > 0 && xy.y <= limiteMapa)
	{
		if (arrMapa[xy.y][xy.x] == ' ')
			cout << "Posicao vazia!" << endl;
		else if (arrMapa[xy.y][xy.x] == crumbSymbol)
			cout << "Migalha!" << endl;
		else if (arrMapa[xy.y][xy.x] == 'C' || arrMapa[xy.y][xy.x] == 'V' || arrMapa[xy.y][xy.x] == 'A' || arrMapa[xy.y][xy.x] == 'E' || arrMapa[xy.y][xy.x] == 'S' ||
				 arrMapa[xy.y][xy.x] == 'c' || arrMapa[xy.y][xy.x] == 'v' || arrMapa[xy.y][xy.x] == 'a' || arrMapa[xy.y][xy.x] == 'e' || arrMapa[xy.y][xy.x] == 's') {
			cout << "Formiga!" << endl;
			for (auto it = ninhos.begin(); it != ninhos.end(); it++)
				it->InfoFormiga(xy);
		}
		else if (arrMapa[xy.y][xy.x] == nestSymbol) 
		{ 
			cout << "Ninho!" << endl; 
			for (auto it = ninhos.begin(); it != ninhos.end(); it++)
				if (it->GetPosNinho().x == xy.x && it->GetPosNinho().y == xy.y)
					it->NinhoInfoDetailed();
		}
	}
}
//Ninhos
bool Mapa::Ninho_exists(const string& s)
{
	for (auto it = ninhos.begin(); it != ninhos.end(); it++)
		if (stoi(s, nullptr, 10) == it->GetNinhoID())
			return true;
	return false;
}
Ninho* Mapa::GetNinhoById(int id) {
	for (vector<Ninho>::iterator it = ninhos.begin(); it != ninhos.end(); it++)
		if(it->GetNinhoID() == id)
			return &(*it);
	return nullptr;
}
void Mapa::CriaNinho(posXY posNinho) {
	if (PosEstaLivre(posNinho)) {
		ninhos.push_back(*(new Ninho(posNinho)));
		arrMapa[posNinho.y][posNinho.x] = ninhos.back().simbolo;
	}
}
void Mapa::ActionNinhos() {}														//TODO
//Formigas
bool Mapa::Cria1(char tipo, int ID_ninho, int posX, int posY) {
	posXY posFormiga { posX, posY };
	Ninho* ninho = GetNinhoById(ID_ninho);
	if (PosEstaLivre(posFormiga) && ninho != nullptr) {
		Formiga formigaAux = Formiga(posFormiga, tipo, ninho);
		(*ninho).formigas.push_back(formigaAux);
		arrMapa[posFormiga.y][posFormiga.x] = formigaAux.simbolo;
		return true;
	}
	return false;
}
void Mapa::CriaF(int qtd, char tipo, int ID_ninho) {
	for (int i = 0; i < qtd; (Cria1(tipo, ID_ninho, rand() % tamMapa, rand() % tamMapa) ? i++ : i=i));
}
void Mapa::ActionFormigas() {
	/*Precorre os vectores "ninhos" e "formigas" sequencialmente*/
	for (auto itN = ninhos.begin(); itN != ninhos.end(); itN++)
		for (auto itF = itN->formigas.begin(); itF != itN->formigas.end(); itF++)
			itF->ActionFormiga(arrMapa, tamMapa, &ninhos, &migalhas);
}
//Migalhas
bool Mapa::Cria1Migalha(int x, int y) {
	if (PosEstaLivre({x,y})) {
		migalhas.push_back(*(new Migalha({x,y}, energiaMigalhas)));
		arrMapa[y][x] = crumbSymbol;
		return true;
	}
	return false;
}
void Mapa::CriaNMigalhas() {
	int qtd = rand() % maxMigalhasItr;
	for (int i = 0; i < qtd; (Cria1Migalha(rand() % tamMapa, rand() % tamMapa) ? i++ : i = i));
}
void Mapa::DecayOldMigalhas() {
	auto it = migalhas.begin();
	while (it != migalhas.end()) {
		it->energia--;
		if ((it->energia / (double)energiaMigalhas) < 0.1) {
			arrMapa[it->posElemento.y][it->posElemento.x] = ' ';
			it = migalhas.erase(it);
		}
		else
			it++;
	}
}
void Mapa::ActionMigalhas() {
	DecayOldMigalhas();
	CriaNMigalhas();
}
//Construtor/Destrutor
Mapa::Mapa(const int& limiteMapa, const int& energiaNovasMigalhas, const int& percentDeMigalhasIniciais, const int& maxMigalhasPorIteracao) {
	tamMapa = limiteMapa;
	maxMigalhasItr = maxMigalhasPorIteracao;
	energiaMigalhas = energiaNovasMigalhas;
	int qtdMigalhasIniciais = (int)((tamMapa*tamMapa) * percentDeMigalhasIniciais / 100);
	InicializaArrayMapa(tamMapa, qtdMigalhasIniciais, percentDeMigalhasIniciais);
}