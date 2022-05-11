#ifndef _CIPHERS_H_
#define _CIPHERS_H_
// этот макрос надо прописывать чтобы хедер не включался несколько раз 


#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h> 
#include <fstream>
#include <direct.h>
#include <Windows.h>
#define  CODE_TAR		"AZXWEVTSIRQPNMOLKJHGUFDCYB"
#define  DECODE_TAR     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

using namespace std; 
/*
 вот так в хедере никогда нельзя делать ты засоряешь поле имен
 Лучше использовать std::cout 
 Или прописывать namespace в .cpp
*/  

string line_get(int cipher, string &key);
bool checker(string text);
void Atbash(string line);
void Vizh(string line, string key);
void Tar(string line);
// названия функции должны быть в одном стиле лучше snake_case или camelCase

#endif // _CIPHERS_H_