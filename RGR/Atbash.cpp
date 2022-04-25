#include "ciphers.h"

// функция кодирования/декодирования
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
	int flag = 0;
	string line;
	string output;
	ofstream out, fout;
	ifstream in, fin;
	out.open("files/Atbash.txt");
	cin.ignore();
	while (true) {
		cout << "Введите текст:  ";
		getline(cin, line);
		if (checker(line)) break;
	}
	out << line << endl; 

	in.open("files/Atbash.txt");
	getline(in, line);

	fout.open("files/Atbash_encrypted.txt");
	string code = code_atbash(line);
	fout << code;
	string decode = code_atbash(line);

	out.close();
	in.close();
	fout.close();

	fin.open("files/Atbash_encrypted.txt");
	getline(fin, output);

	cout << "Зашифрованный текст:  ";
	cout << output << endl;
	cout << "Расшифрованный текст:  ";
	cout << decode << endl;

}