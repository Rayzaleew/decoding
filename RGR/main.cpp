#include "ciphers.h"

void Prog() {
	int cipher = 1;
	string line, key;
	int files = _mkdir("files");
	while (cipher) {

		cout << "Выберите шифр: " << endl;
		cout << "Нажмите <1> для выбора шифра Атбаш " << endl;
		cout << "Нажмите <2> для выбора шифра Виженера " << endl;
		cout << "Нажмите <3> для выбора шифра “Тарабарская грамота” " << endl;
		cout << "Нажмите <0> для выхода из программы " << endl;
		cin >> cipher;
		switch (cipher) {
		case 1:
			line = line_get(cipher, key);
			Atbash(line);
			cout << "----------------------------------------" << endl;
			break;
		case 2:
			line = line_get(cipher, key);
			Vizh(line, key);
			cout << "----------------------------------------" << endl;
			break;
		case 3:
			line = line_get(cipher, key);
			Tar(line);
			cout << "----------------------------------------" << endl;
			break;
		case 0:
			cout << "Всего доброго!" << endl;
			break;
		default:
			cout << "Выберите один из трёх предложенных шифров" << endl;
			break;
		};
	}
}



string line_get(int cipher, string &key) {
	int method = 0;
	int a = 0;
	string line, path;
	ifstream in;
	cout << "Вы хотите прочитать текст с файла или с клавиатуры? " << endl;
	cout << "1. С клавиатуры " << endl;
	cout << "2. С файла " << endl;
	cin >> method;
	switch (method) {
	case 1:
		while (true) {
			cout << "Введите текст:  ";
			cin.ignore();
			getline(cin, line);
			if (checker(line)) break;
		}
		if (cipher == 2) {
			while (true) {
				cout << "Введите ключ:  ";
				cin >> key;
				if (checker(key)) break;
			}
		}
		break;
	case 2:
		cout << "Введите путь к файлу: " << endl;
		cin >> path;
		in.open(path);
		if (cipher == 2) {
			while(true) {
				while (!in.eof()) {
					if (a == 1) {
						getline(in, key);
						break;
					}
					getline(in, line);
					a++;
				}
				if (checker(line) || checker(key)) break;
				
			}
			
		}
		else {
			while (true) {
				getline(in, line);
				if (checker(line)) break;
			}
		}
		in.close();
		break;
	default:
		cout << "Выберите один из двух вариантов!" << endl;
		break;
	}
	return line;
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
