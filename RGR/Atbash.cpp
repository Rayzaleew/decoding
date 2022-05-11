#include "ciphers.h"

// ������� �����������/�������������
string code_atbash(string text) {


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



void Atbash(string line) {
	int choice = 0;
	string path;
	ofstream out;

	cout << "�������� �����: " << line << endl;
	string code = code_atbash(line);
	cout << "�������������/�������������� �����: " << code << endl;

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