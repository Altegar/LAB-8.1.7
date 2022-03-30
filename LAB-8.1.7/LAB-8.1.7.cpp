// LAB-8.1.7.cpp
// Сушинський Ігор
// Лабораторна робота №8.1
// Пошук та заміна символів у літерному рядку.
// Варіант 20
// 2 завдання
// Використання стандартних функцій для рядків char[]

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* Change(char* s)
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;

	while (p = strchr(s + pos1, ','))
	{
		if (s[p - s + 2] == '-')
		{
			pos2 = p - s + 3;
			strncat(t, s + pos1, pos2 - pos1 - 3);
			strcat(t, "**");
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);

	strcpy(s, t);

	return t;
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	char str[101];

	cout << "Ввести лiтерний рядок:" << endl;
	cin.getline(str, 100);

	char* dest = new char[151];

	dest = Change(str);

	cout << "Модифiкований лiтерний рядок (param) : " << str << endl;
	cout << "Модифiкований лiтерний рядок (result): " << dest << endl;

	return 0;
}