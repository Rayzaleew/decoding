#include "ciphers.h"



string code_tar(string &text) {
	const char* cch, * dch;

	for (auto &c : text) {
		if (isalpha(c)) {
			for (dch = DECODE_TAR, cch = CODE_TAR; *cch; *(cch)++, *(dch)++) {
				if (*cch == toupper(c)) {
					c = (isupper(c)) ? *dch : tolower(*dch);
					break;
				}
			}
		}
	}
	return text;
}

// ������� �������������
string decode_tar(string text) {
	//char* dst = src;
	const char* cch, * dch;

	for (auto &c : text) {
		if (isalpha(c)) {
			for (dch = DECODE_TAR, cch = CODE_TAR; *cch; *(cch)++, *(dch)++) {
				if (*dch == toupper(c)) {
					c = (isupper(c)) ? *cch : tolower(*cch);
					break;
				}
			}
		}
	}
	return text;
}

void tar() {
	int flag = 0;
	string line;
	string output;
	ofstream out, fout;
	ifstream in, fin;
	out.open("files/Tar.txt");
	while (true) {
		cout << "������� �����:  ";
		cin.ignore();
		getline(cin, line);
		if (checker(line)) break;
	}

	out << line << endl; //������ �������� ������ � ����
	in.open("files/Tar.txt");
	getline(in, line);
	fout.open("files/Tar_encrypted.txt");
	string code = code_tar(line);//������ ������������� ������ � ����
	fout << code;
	string decode = decode_tar(line);
	out.close();
	in.close();
	fout.close();
	fin.open("files/Tar_encrypted.txt");
	getline(fin, output);
	cout << "������������� �����:  ";
	cout << output << endl;
	cout << "�������������� �����:  ";
	cout << decode << endl;
}