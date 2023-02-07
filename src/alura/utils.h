#pragma once

#include <string>
#include <map>
#include <vector>

bool letra_existe(const char chute, const std::string &palavra);

bool nao_acertou(const std::string &palavra_secreta,
                    const std::map<char, bool> &chutou);
