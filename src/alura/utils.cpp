#include "utils.h"

#include <map>

using namespace std;

map<char, bool> chutou {{'M', false}, {'E', false},
						{'L', false}, {'A', false},
						{'N', false}, {'C', false},
						{'I', false},{'A', false}};
vector<char> chutes_errados;

bool letra_existe(char chute, string palavra) {
	for (auto letra : palavra) {
		if (letra == chute) {
			return true;
		}
	}
	return false;
}

bool nao_acertou(string palavra_secreta) {
	for (auto letra : palavra_secreta) {
		if (!chutou[letra]) {
			return true;
		}
	}

	return false;
}


bool nao_enforcou() {
	return chutes_errados.size() < 5;
}