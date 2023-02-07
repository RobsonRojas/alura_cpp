#include "forca.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

#include "utils.h"

void imprime_cabecalho_forca() {
	std::cout << "***************************************" << std::endl;
	std::cout << "*  Bem vindo ao jogo da forca! *" << std::endl;
	std::cout << "***************************************" << std::endl;
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