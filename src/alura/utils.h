#include <string>
#include <map>
#include <vector>

using namespace std;

extern map<char, bool> chutou;
extern vector<char> chutes_errados;

bool letra_existe(char chute, string palavra);

bool nao_acertou(string palavra_secreta);

bool nao_enforcou();