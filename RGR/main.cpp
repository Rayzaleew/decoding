#include "ciphers.h"

void Prog() {
	int k = 1;
	int files = _mkdir("files");
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

bool checker(string text) {
	for (auto& c : text) {
		if (c < 32 || c > 126) {
			cout << "Вы ввели недопустимые символы. Пожалуйста, повторите ввод" << endl;
			return 0;
		}
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "CHANGEEEEEES!!!!!" << endl;
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
