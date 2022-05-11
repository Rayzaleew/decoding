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

	cout << "�������� �����: " << line << endl;
	
	cout << "�� ������ ����������� ��� ������������ �����? " << endl;
	cout << "1. ����������� " << endl;
	cout << "2. ������������ " << endl;
	cin >> action;
	switch (action) {
	case 1:
		code = encrypt(line, key);
		cout << "������������� �����: " << code << endl;
		break;
	case 2:
		code = decrypt(line, key);
		cout << "�������������� �����: " << code << endl;
		break;
	default:
		cout << "�������� ���� �� ���� ���������! " << endl;
	}
	
	

	cout << "������ ��������� ��������� � �����? (1 - ��, 2 - ���)" << endl;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "������� ���� � �����: " << endl;
		cin >> path;
		out.open(path);
		out << code;
		out.close();
		break;
	case 2:
		cout << endl;
		break;
	default:
		cout << "�������� ���� �� ���� ���������! " << endl;

	}
}