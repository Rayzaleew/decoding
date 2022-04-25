#include "ciphers.h"

// функция декодирования
string code_atbash(string &text) {
	

	for (auto& c : text) {
		if (islower(c))
		{
			c = 26 - (c - 'a' + 1) + 'a';
		}
		else if (isupper(c))
		{
			c = 26 - (c - 'A' + 1) + 'A';
		}
	}
	return text;
}
void Atbash() {
	string line;
	string output;
	ofstream out, fout;
	ifstream in, fin;

	out.open("Atbash.txt");
	cout << "Введите текст:  ";
	cin >> line;
	out << line << endl; 

	in.open("Atbash.txt");
	getline(in, line);

	fout.open("Atbash_encrypted.txt");
	string code = code_atbash(line);
	fout << code;
	string decode = code_atbash(line);

	out.close();
	in.close();
	fout.close();

	fin.open("Atbash_encrypted.txt");
	getline(fin, output);

	cout << "Зашифрованный текст:  ";
	cout << output << endl;
	cout << "Расшифрованный текст:  ";
	cout << decode << endl;

}