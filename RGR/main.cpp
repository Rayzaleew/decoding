#include "ciphers.h"

void Prog() {
	int k = 1;
	while (k != 0) {
		cout << "Выберите шифр: " << endl;
		cout << "Нажмите <1> для выбора шифра Атбаш " << endl;
		cout << "Нажмите <2> для выбора шифра Виженера " << endl;
		cout << "Нажмите <3> для выбора шифра “Тарабарская грамота” " << endl;
		cout << "Нажмите <0> для выхода из программы " << endl;
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
			cout << "Выберите один из трёх предложенных шифров" << endl;
			break;
		};
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s;
	cout << "Пароль: ";
	cin >> s;
	if (s == "123456") {
		Prog();
	}
	else {
		cout << "Неверный пароль: " << endl;
		return 0;
	}
	system("pause");
	return 0;
}
