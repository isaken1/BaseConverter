// BaseConverter.h: arquivo de inclusão para arquivos de inclusão padrão do sistema,
// ou arquivos de inclusão específicos a um projeto.

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

// TODO: Referencie os cabeçalhos adicionais de que seu programa precisa aqui.
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

map<char, int> alphabet;

string convert(int input, int base);
void initialize_alphabet();
string invert_string(string s);
void clear_screen() { if (system("CLS")) system("clear"); }

