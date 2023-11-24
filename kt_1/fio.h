#pragma once

#ifndef FIO_H

#define FIO_H

#include "common.h"

namespace Keyboard  // ���������������� ������������ ����, �������� ����������� ���������� ���� ������
{
	static const char ESCAPE = 27;
	static const char UP = 72;
	static const char DOWN = 80;
	static const char ENTER = 13;
}

namespace Console
{
	static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������

	static void GoToXY(short x, short y)   // ��������� ������ � ����� x,y
	{
		SetConsoleCursorPosition(hStdOut, { x, y });
	}

	static void ConsoleCursorVisible(bool show, short size)
	{
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = show; // �������� ��������� �������
		structCursorInfo.dwSize = size;  // �������� ������ �������
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	}
}

class FIO
{
private:

	std::string name;
	std::string surname;
	std::string otch;

public:

	FIO();
	~FIO();

	void Set();
	void SetFio(std::string name, std::string surname, std::string otch);
	void SetName(std::string name) { this->name = name; }
	void SetSurname(std::string surname) { this->surname = surname; };
	void SetOtch(std::string otch) { this->otch = otch; };
	void SetFullName() { this->FIO::Set(); }

	std::string GetName() { return this->name; }
	std::string GetSurname() { return this->surname; }
	std::string GetOtch() { return this->otch; }

	virtual void GetFromFile(std::istream& in) { in >> this->surname >> this->name >>  this->otch; }
};

#endif 
