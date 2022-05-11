#include "ciphers.h"


//������� �����������/�������������
string code_tar(string text) {
	const char* input_index, * output_index;
	

	for (auto &c : text) {
		if (isalpha(c)) {
			for (input_index = DECODE_TAR, output_index = CODE_TAR;*input_index; input_index++, output_index++) {
				if (*input_index == toupper(c)) {
					c = (isupper(c)) ? *output_index : tolower(*output_index);
					break;
				}
			}
		}
	}
	return text;
}



void Tar(string line) {
	int choice = 0;
	string path;
	ofstream out;

	cout << "�������� �����: " << line << endl;
	string code = code_tar(line);
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