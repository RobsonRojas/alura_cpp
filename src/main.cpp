#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <vector>
#include <fstream>

#include "linkedin_learning/linkedin.h"

using namespace std;

int nivel_dificuldade() {
	std::cout << "Escolha o seu nível de dificuldade: " << std::endl;
	std::cout << "Fácil (F), Médio (M) ou Difícil (C)" << std::endl;
	char dificuldade;
	std::cin >> dificuldade;

	if (dificuldade == 'F') {
		return 15;
	} else if (dificuldade == 'M') {
		return 10;
	} else if (dificuldade == 'C') {
		return 5;
	} else {
		return 5;
	}
}

void advinhacao() {
	std::cout << "***************************************" << std::endl;
	std::cout << "*  Bem vindo ao jogo de advinhação! *" << std::endl;
	std::cout << "***************************************" << std::endl;

	std::cout << "Escolha o seu nível de dificuldade: " << std::endl;
	std::cout << "Fácil (F), Médio (M) ou Difícil (C)" << std::endl;
	char dificuldade;
	std::cin >> dificuldade;

	int numero_tentativas = 0;

	if (dificuldade == 'F') {
		numero_tentativas = 15;
	} else if (dificuldade == 'M') {
		numero_tentativas = 10;
	} else if (dificuldade == 'C') {
		numero_tentativas = 5;
	} else {
		numero_tentativas = 5;
	}

	srand(time(NULL));
	const int NUMERO_SECRETO = rand() % 100 + 1;

	// std::cout << "NUMERO SECRETO: " << NUMERO_SECRETO << std::endl;

	int chute = 0;
	int tentativas = 0;
	double pontos = 1000.0;
	bool acertou = false;

	for (tentativas = 1; tentativas <= numero_tentativas; tentativas++) {
		std::cout << "Dê o chute: " << std::endl;
		
		std::cin >> chute;
		std::cout << "Chute: " << chute << std::endl;
		double pontos_perdidos = std::abs((chute - NUMERO_SECRETO) / 2.0);
		pontos -= pontos_perdidos;
		if (chute == NUMERO_SECRETO) {
			std::cout << "Parabéns! Você acertou o número secreto!" << std::endl;
			acertou = true;
			break;
		} else if (chute > NUMERO_SECRETO) {
			std::cout << "Seu chute foi maior que o número secreto!" << std::endl;	
		} else {
			std::cout << "Seu chute foi menor que o número secreto!" << std::endl;
		}
	}

	std::cout << "Fim de jogo!" << std::endl;
	if (acertou == false) {
		std::cout << "Você perdeu! Tente novamente." << std::endl;
	} else {
		std::cout << "Você acertou em " << tentativas << " tentativas!" << std::endl;
		std::cout.precision(2);
		std::cout << std::fixed;
		std::cout << "Sua pontuação foi de: " << pontos << std::endl;		
	}
}

bool letra_existe(char chute, string palavra) {
	for (auto letra : palavra) {
		if (letra == chute) {
			return true;
		}
	}
	return false;
}

map<char, bool> chutou {{'M', false}, {'E', false},
						{'L', false}, {'A', false},
						{'N', false}, {'C', false},
						{'I', false},{'A', false}};

bool nao_acertou(string palavra_secreta) {
	for (auto letra : palavra_secreta) {
		if (!chutou[letra]) {
			return true;
		}
	}

	return false;
}

vector<char> chutes_errados;

bool nao_enforcou() {
	return chutes_errados.size() < 5;
}


vector<string> le_arquivo() {
	ifstream arquivo;
	int quantidade_palavras;
	vector<string> palavras;

	arquivo.open("palavras.txt");

	if (arquivo.is_open() == false) {
		cout << "Não foi possível acessar o banco de palavras." << endl;
		exit(0);
	}
	arquivo >> quantidade_palavras;

	// cout << "O arquivo possui " << quantidade_palavras << " palavras" <<endl;

	for (int i=0; i < quantidade_palavras; i++) {
		string palava_lida;
		arquivo >> palava_lida;
		palavras.push_back(palava_lida);

		// cout << "linha: " << i << " palavra: " << palava_lida << endl;
	}

	return palavras;
}

string sorteia_palavra() {
	auto palavras = le_arquivo();
	srand(time(NULL));
	int numero = rand() % palavras.size();
	return palavras[numero];
}

void imprime_cabecalho_forca() {
	std::cout << "***************************************" << std::endl;
	std::cout << "*  Bem vindo ao jogo da forca! *" << std::endl;
	std::cout << "***************************************" << std::endl;
}

void imprime_erros() {
	cout << "Chutes errados: ";
	for (auto letra : chutes_errados) {
		cout << letra << " ";
	}
	cout << endl;
}

void imprime_palavra(string palavra_secreta) {

		for (auto letra : palavra_secreta) {
			if (chutou[letra]) {
				cout << letra << " ";
			} else {
				cout << "_ ";
			}
		}
		cout << endl;
}

void chuta(string palavra_secreta) {
	char chute = ' ';
	std::cout << "Seu chute: " << std::endl;
	
	std::cin >> chute;
	std::cout << "Chute: " << chute << std::endl;
	chutou[chute] = true;

	if (letra_existe(chute, palavra_secreta)) {
		cout << "Você acertou! Seu chute está na palavra." << endl;
	} else {
		cout << "Você errou! Seu chute não está na palavra." << endl;
		chutes_errados.push_back(chute);
	}
	cout << endl;
}

void salva_arquivo(vector<string> palavras) {
	ofstream arquivo;
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {
		arquivo <<  palavras.size() << endl;
		for (auto palavra : palavras) {
			arquivo << palavra << endl;
		}
	} else {
		cout << "Não foi possível acessar o banco de palavras." << endl;
		exit(0);
	}
}

void adiciona_palavra() {
	string palavra;
	cout << "Digite a nova palavra, usando letras maiúsculas." << endl;
	cin >> palavra;
	vector<string> lista_palavras = le_arquivo();
	lista_palavras.push_back(palavra);
	salva_arquivo(lista_palavras);

	

}

void forca() {
	imprime_cabecalho_forca();
	string palavra_secreta = sorteia_palavra();

	// cout << palavra_secreta << endl;

	// cout << nro_tentativas << endl;
	while (nao_acertou(palavra_secreta) && nao_enforcou()) {
		imprime_erros();
		imprime_palavra(palavra_secreta);

		chuta(palavra_secreta);
	}

	std::cout << "Fim de jogo!" << std::endl;
	cout << "A palavra secreta é: " << palavra_secreta << endl;

	if (nao_acertou(palavra_secreta)) {
		std::cout << "Você foi enforcado! Tente novamente." << std::endl;
	} else {
		std::cout << "Você acertou! " << std::endl;	
		cout << "Você deseja adicionar uma nova palavra ao banco? (S/N): " << endl;
		char resposta;
		cin >> resposta;

		if (resposta == 'S') {
			adiciona_palavra();
		}
	}

}

int main(int argc, char *argv[])
{
	// forca();
	// print_number_sufix();
	centered_text();

	return 0;
}