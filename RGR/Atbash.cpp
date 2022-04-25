#include "ciphers.h"



// функция кодирования
char* code_atbash(char* src) {
	char* dst = src;
	const char* cch, * dch;

	while (*src) {
		if (isalpha(*src)) {
			for (dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
				if (*cch == toupper(*src)) {
					*src = (isupper(*src)) ? *dch : tolower(*dch);
					break;
				}
			}
		}
		*src++;
	}
	return dst;
}

// функция декодирования
char* decode_atbash(char* src) {
	char* dst = src;
	const char* cch, * dch;

	while (*src) {
		if (isalpha(*src)) {
			for (dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
				if (*dch == toupper(*src)) {
					*src = (isupper(*src)) ? *cch : tolower(*cch);
					break;
				}
			}
		}
		*src++;
	}
	return dst;
}
void Atbash() {
	char line[64];
	char str[64];
	string output;
	ofstream out, fout;
	ifstream in, fin;

	out.open("Atbash.txt");
	cout << "Введите текст:  ";
	cin >> line;
	out << line << endl; 

	in.open("Atbash.txt");
	in.getline(str, 64);

	fout.open("Atbash_encrypted.txt");
	string code = code_atbash(str);
	fout << code;
	string decode = decode_atbash(str);

	out.close();
	in.close();
	fout.close();

	fin.open("Atbash_encrypted.txt");
	getline(fin, output);

	cout << "Зашифрованный текст:  ";
	cout << output << endl;
	cout << "Расшифрованный текст:  ";
	cout << decode << endl;

}