#include "utils.h"

#include <map>

using namespace std;

bool letra_existe(char chute, const string &palavra) {
	for (auto letra : palavra) {
		if (letra == chute) {
			return true;
		}
	}
	return false;
}

bool nao_acertou(const string &palavra_secreta,
						const map<char, bool> &chutou) {
	for (auto letra : palavra_secreta) {
		if (chutou.find(letra) == chutou.end() || !chutou.at(letra) ) {
			return true;
		}
	}

	return false;
}