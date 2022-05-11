#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define  CODE_TAR		"AZXWEVTSIRQPNMOLKJHGUFDCYB"
#define  DECODE_TAR     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

using namespace std;

string line_get(int cipher, string &key);
bool checker(const string &text);
void Atbash(string line);
void Vizh(string line, string key);
void Tar(string line);

