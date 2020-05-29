#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string toUpper(string s) 
{
	for (char & c : s) {
		c -= (c >= 'a' && c <= 'z' ? 32 : 0);
	}

	return s;
}

string toString(int i)
{
	string s = "";
	switch (i) {
	case 0:
		return "0";
	case 1:
		return "1";
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	case 10:
		return "A";
	case 11:
		return "B";
	case 12:
		return "C";
	case 13:
		return "D";
	case 14:
		return "E";
	case 15:
		return "F";
	}
}

unsigned long long pow(int v, int e) 
{	
	unsigned long long r = 1;

	for (int i = 0; i < e; i++) {
		r *= v;
	}

	return r;
}

unsigned long long BinaryToDec(const string& binary)
{
	if (binary.size() > 64)
		throw runtime_error("numero muy grande");

	if ((binary.size()) % 4 != 0)
		throw runtime_error("bloques de 4 caracteres no validos");

	unsigned long long dec = 0;

	for (int i = 0; i < binary.size(); i++) {
		if (!(binary[binary.size() - i - 1] == '0' || binary[binary.size() - i - 1] == '1'))
			throw runtime_error("caracter binario no identificado");

		dec += (binary[binary.size() - i - 1] - '0') * pow(2, i);
	}

	return dec;
}

string charCount(int count, string s) {
	string ss = "";

	for (int i = 0; i < count; i++) {
		ss += s;
	}

	return ss;
}

string BinaryToHex(const string& binary)
{
	string hex = "";
	unsigned long long dec = BinaryToDec(binary);

	while (dec != 0) {
		for (int i = 0; i <= 15; i++) {
			if ((dec - i) % 16 == 0) {
				dec -= i;
				dec /= 16;
				hex = toString(i) + hex;
			}
		}
	}

	return hex;
}

unsigned long long HexToDec(const string& hex)
{
	if (hex.size() > 16)
		throw runtime_error("numero muy grande");

	unsigned long long dec = 0;

	for (int i = 0; i < hex.size(); i++) {
		if ((hex[hex.size() - i - 1] < '0' || hex[hex.size() - i - 1] > '9') && 
			(hex[hex.size() - i - 1] < 'A' || hex[hex.size() - i - 1] > 'F'))
			throw runtime_error("caracter hexadecimal no identificado");

		if (hex[hex.size() - i - 1] >= '0' && hex[hex.size() - i - 1] <= '9') {
			dec += (hex[hex.size() - i - 1] - '0') * pow(16, i);
		}
		else {
			dec += (hex[hex.size() - i - 1] - 'A' + 10) * pow(16, i);
		}
	}

	return dec;
}

string HexToBinary(const string& hex) 
{
	string binary = "";
	unsigned long long dec = HexToDec(hex);

	while (dec != 0) {
		binary = toString(dec % 2) + binary;
		dec -= dec % 2;
		dec /= 2;
	}

	return charCount((4 - (binary.size() % 4)) % 4, "0") + binary;
}

int main() {
	bool play = true;

	while (play)
	{
		try {
			cout << "Quieres: " << endl;
			cout << " [1] Binario a Hexadecimal" << endl;
			cout << " [2] Hexadecimal a Binario" << endl;
			cout << " [3] Salir" << endl;

			int des = 0;

			if (cin >> des) {
				system("cls");
				string s;

				switch (des)
				{
				case 1:
					cout << "Introduce tu valor binario a convertir" << endl << endl;
					cin >> s;
					cout << "Tu valor en hexadecimal es:" << endl;

					cout << BinaryToHex(s) << endl;
					break;
				case 2:
					cout << "Introduce tu valor hexadecimal a convertir" << endl << endl;
					cin >> s;
					cout << "Tu valor en binario es:" << endl;

					cout << HexToBinary(toUpper(s)) << endl;
					break;
				case 3:
					play = false;
					break;
				default:
					break;
				}

				system("pause");
			}
			else {
				cin.clear();
				cin.ignore(10000000, '\n');
			}

			system("cls");
		}
		catch (runtime_error e) {
			cerr << e.what() << endl;

			system("pause");
		}

		system("cls");
	}
}