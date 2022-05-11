#include "ciphers.h"

void Prog() {
    char cipher = 1;
    string line, key;
    int files = _mkdir("files");

    while (cipher) {
        cout << "Выберите шифр: " << endl
             << "Нажмите <1> для выбора шифра Атбаш " << endl
             << "Нажмите <2> для выбора шифра Виженера " << endl
             << "Нажмите <3> для выбора шифра “Тарабарская грамота” " << endl
             << "Нажмите <0> для выхода из программы " << endl;
        // лучше убрать лишнее cout'ы

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

string line_get(int cipher, string& key) {
    int method = 0;
    int a = 0;  // Так называть переменные не стоит
    string line, path;
    ifstream in;
    // ifstream in и path лучше объявить в кейсе

    cout << "Вы хотите прочитать текст с файла или с клавиатуры? " << endl
         << "1. С клавиатуры " << endl
         << "2. С файла " << endl;

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
            if (cipher == 2) {  // и почему для этого шифра нужен отдельный метод считывания файла?
                while (true) {
                    while (!in.eof()) {
                        if (a == 1) {
                            getline(in, key);
                            break;
                        }
                        /*Слишком большая вложенность
                        Лучше выделить в функцию*/
                        getline(in, line);
                        a++;
                    }
                    if (checker(line) || checker(key)) break;
                }

            } else {
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

/*Не стоит каждой функции позволять делать вывод в stdout
За вывод должен отвечать какойто 1 логический элемент
checker должен возвращать только true или false

+ Если придерживаешься структурного программирования
в каждой функции желательно должен быть 1 вход и 1 выход

+ Здесь лучше передавать константую ссылку
    bool checker(const string& text)
*/

bool checker(string text) {
    for (auto& c : text) {
        if (c < 32 || c > 126) {
            cout << "Вы ввели недопустимые символы. Пожалуйста, повторите ввод" << endl;
            return 0;
        }
    }
    return 1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string s;  // s = password

    cout << "Пароль: ";
    cin >> s;

    if (s == "123456") {
        // Безопасно)
        Prog();
    } else {
        cout << "Неверный пароль: " << endl;
        return 0;
    }

    system("pause");
    return 0;
}
