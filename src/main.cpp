#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include <vector>

#include "linkedin_learning/linkedin.h"
#include "alura/forca.h"

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


int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		cout << "argc: " << argc << endl;
		return 0;
	}
	
	// forca::forca();
	// print_number_sufix();
	// centered_text();
	// change_coins();

	// for (size_t i = 0; i < argc; i++)
	// {
	// 	cout << argv[i] << " ";
	// }
	// cout << endl;
	int arg = 0;
	
	try {
		arg = stoi(argv[1]);
		// cout << "arg " << arg << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid argment: " << argv[1] << '\n';
		return -1;
	}
	
	halistone_sequence(arg);

	return 0;
}