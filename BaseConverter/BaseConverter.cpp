// BaseConverter.cpp: define o ponto de entrada para o aplicativo.

#include "BaseConverter.h"

int main()
{
	int input = 0;
	int base = 0;
	initialize_alphabet();

	//Loop de execução
	int control = 0;
	while (control != 1)
	{
		clear_screen();
		cout << "Insira o valor a ser convertido: ";
		cin >> input;

		cout << "Insira a base a ser convertida: ";
		cin >> base;
		//Verifica se a base é válida
		if ((base < 2) || (base > 36)) {
			cerr << "Base invalida!" << endl;
			continue;
		}
		
		string final_value = convert(input, base);

		cout << input << " na base " << base << " = " << 
			final_value << endl << endl;

		//Evita que o buffer do cin possa causar problema em instâncias futuras do loop.
		cin.clear();
		cin.ignore();

		cout << "(1) para sair do programa.." << endl;
		cout << "Insira outro valor para continuar a execucao..." << endl;
		cin >> control;
	}
	
	return 0;
}

/* Algoritmo que, através de divisões sucessivas e comparações dos valores de resto, converte um valor x (input) representado na base decimal
para uma representação na base b (base).
*/
string convert(int input, int base) {
	int n = input;
	string result;
	do {
		result.push_back((((n % base) < 10) ? ((n % base) + '0') : (alphabet[(n % base)])));
		n = (int)(n / base);
	} while (n != 0);
	return invert_string(result);
}

/* Funcao que inicializa um map com todas as letras do alfabeto como valores a serem mapeados, sendo que suas chaves são os valores 
os quais elas correspondem.
*/
void initialize_alphabet() {
	char val = 'A';
	for (int i = 10; i < 36; i++) {
		alphabet[i] = val++;
	}
}

/* Função para inverter uma string, necessária pois a função convert retorna como resultado o número ao contrário.
*/
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