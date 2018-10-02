// BaseConverter.cpp: define o ponto de entrada para o aplicativo.

#include "BaseConverter.h"

int main()
{
	int input = 0;
	int base = 0;
	//cout << "Insira um valor: " << endl;
	initialize_alphabet();

	int control = 0;
	while (control != 1)
	{
		clear_screen();
		cout << "Insira o valor a ser convertido: ";
		cin >> input;

		cout << "Insira a base a ser convertida: ";
		cin >> base;
		if ((base < 2) || (base > 36)) {
			cerr << "Base inválida!" << endl;
			continue;
		}
		
		string final_value = invert_string(convert(input, base));

		cout << input << " na base " << base << " = " << 
			final_value << endl << endl;

		cin.clear();
		cin.ignore();

		cout << "(1) para sair do programa.." << endl;
		cout << "Qualquer outro valor para continuar..." << endl;
		cin >> control;
	}
	

	//Mantem a janela do console aberta ate que seja pressionado o enter
	cin.get();
	
	return 0;
}

string convert(int input, int base) {
	int n = input;
	string result;
	do {
		result.push_back((((n % base) < 10) ? ((n % base) + '0') : (alphabet[(n % base)])));
		n = (int)(n / base);
	} while (n != 0);
	return result;
}

/* @func Funcao que inicializa um map com todas as letras do alfabeto como valores a serem mapeados, sendo que suas chaves são os valores 
os quais elas correspondem
*/
void initialize_alphabet() {
	char val = 'A';
	for (int i = 10; i < 36; i++) {
		alphabet[i] = val++;
	}
}

string invert_string(string s) {
	int start = 0, end = s.size() - 1;

	while (start < end) {
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}

	return s;
}