#include "ciphers.h"
string encrypt(string text, string key)
{
	string result = text;
	int i = 0;
	for (auto& c : result)
	{
		if (islower(c))
		{
			c = (((c - 'a') + (key[i++ % key.size()] - 'a')) % 26) + 'a';
		}
		else if (isupper(c))
		{
			c = (((c - 'A') + (key[i++ % key.size()] - 'A')) % 26) + 'A';
		}
	}
	return result;
}

string decrypt(string str, string key)
{
	string k = key;
	for (auto& c : k)
	{
		c = tolower(c) - 'a' - 1;
		c = 'z' - c;
	}
	return encrypt(str, k);
}

void Vizh() {
	string text, key;
	int a = 0;
	string in_text, in_key, output;
	ifstream in, fin;
	ofstream out, fout;
	out.open("Vizh.txt");
	cout << "Введите текст:  ";
	cin >> text;
	out << text << endl;
	cout << "Введите ключ:  ";
	cin >> key;
	out << key << endl;
	in.open("Vizh.txt");
	while (!in.eof()) {
		if (a == 1) {
			getline(in, in_key);
			break;
		}
		getline(in, in_text);
		a++;
	}
	string cipher(encrypt(in_text, in_key));
	in.close();
	out.close();
	fout.open("Vizh_encrypted.txt");
	fout << cipher << endl;
	fout.close();
	fin.open("Vizh_encrypted.txt");
	getline(fin, output);
	cout << "Зашифрованный текст:  ";
	cout << output << endl;
	cout << "Расшифрованный текст:  ";
	cout << decrypt(cipher, key) << endl;
}