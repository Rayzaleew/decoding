#include "ciphers.h"
char* code_tar(char* src) {
	char* dst = src;
	const char* cch, * dch;

	while (*src) {
		if (isalpha(*src)) {
			for (dch = DECODE_TAR, cch = CODE_TAR; *cch; *cch++, *dch++) {
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

// ������� �������������
char* decode_tar(char* src) {
	char* dst = src;
	const char* cch, * dch;

	while (*src) {
		if (isalpha(*src)) {
			for (dch = DECODE_TAR, cch = CODE_TAR; *cch; *cch++, *dch++) {
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
void tar() {
	char line[64];
	char str[64];
	string output;
	ofstream out, fout;
	ifstream in, fin;
	out.open("Tar.txt");
	cout << "������� �����:  ";
	cin >> line;

	out << line << endl; //������ �������� ������ � ����
	in.open("Tar.txt");
	in.getline(str, 64);
	fout.open("Tar_encrypted.txt");
	string code = code_tar(str);//������ ������������� ������ � ����
	fout << code;
	string decode = decode_tar(str);
	out.close();
	in.close();
	fout.close();
	fin.open("Tar_encrypted.txt");
	getline(fin, output);
	cout << "������������� �����:  ";
	cout << output << endl;
	cout << "�������������� �����:  ";
	cout << decode << endl;
}