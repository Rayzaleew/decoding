#include "ciphers.h"

void Prog() {
	int k = 1;
	while (k != 0) {
		cout << "�������� ����: " << endl;
		cout << "������� <1> ��� ������ ����� ����� " << endl;
		cout << "������� <2> ��� ������ ����� �������� " << endl;
		cout << "������� <3> ��� ������ ����� ������������ �������� " << endl;
		cout << "������� <0> ��� ������ �� ��������� " << endl;
		cin >> k;

		switch (k) {
		case 1:
			Atbash();
			cout << "----------------------------------------" << endl;
			break;
		case 2:
			Vizh();
			cout << "----------------------------------------" << endl;
			break;
		case 3:
			tar();
			cout << "----------------------------------------" << endl;
			break;
		case 0:
			k = 0;
			break;
		default:
			cout << "�������� ���� �� ��� ������������ ������" << endl;
			break;
		};
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	cout << "������: ";
	cin >> s;
	if (s == "123456") {
		Prog();
	}
	else {
		cout << "�������� ������: " << endl;
		return 0;
	}
	system("pause");
	return 0;
}