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

string decrypt(string text, string key)
{
	string k = key;
	for (auto& c : k)
	{
		c = tolower(c) - 'a' - 1;
		c = 'z' - c;
	}
	return encrypt(text, k);
}



void Vizh(string line, string key) {
	int choice = 0;
	int action = 0;
	string path, code;
	ofstream out;

	cout << "Исходный текст: " << line << endl;
	
	cout << "Вы хотите зашифровать или расшифровать текст? " << endl;
	cout << "1. Зашифровать " << endl;
	cout << "2. Расшифровать " << endl;
	cin >> action;
	switch (action) {
	case 1:
		code = encrypt(line, key);
		cout << "Зашифрованный текст: " << code << endl;
		break;
	case 2:
		code = decrypt(line, key);
		cout << "Расшифрованный текст: " << code << endl;
		break;
	default:
		cout << "Выберите один из двух вариантов! " << endl;
	}
	
	

	cout << "Хотите сохранить результат в файле? (1 - Да, 2 - Нет)" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Введите путь к файлу: " << endl;
		cin >> path;
		out.open(path);
		out << code;
		out.close();
		break;
	case 2:
		cout << endl;
		break;
	default:
		cout << "Выберите один из двух вариантов! " << endl;

	}
}