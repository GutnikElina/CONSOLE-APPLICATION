#pragma once

#ifndef FIO_H

#define FIO_H

#include "common.h"

namespace Keyboard
{
	static const char ESCAPE = 27;
	static const char UP = 72;
	static const char DOWN = 80;
	static const char ENTER = 13;
}

namespace Console
{
	static HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // получаем дескриптор консоли

	static void GoToXY(short x, short y)   // текстовый курсор в точку x,y
	{
		SetConsoleCursorPosition(hStdOut, { x, y });
	}

	static void ConsoleCursorVisible(bool show, short size)
	{
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(hStdOut, &structCursorInfo);
		structCursorInfo.bVisible = show; // изменяем видимость курсора
		structCursorInfo.dwSize = size;  // изменяем размер курсора
		SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	}
}

class FIO
{
private:

	std::string name{};
	std::string surname{};
	std::string otch{};

public:

	FIO();
	~FIO();

	void set();
	void set(std::string name, std::string surname, std::string otch);
	virtual void getFromFile(std::istream& in) { in >> this->surname >> this->name >>  this->otch; };

	void setName(std::string name) { this->name = name; }
	void setSurname(std::string surname) { this->surname = surname; };
	void setOtch(std::string otch) { this->otch = otch; };

	std::string getName() { return this->name; }
	std::string getSurname() { return this->surname; }
	std::string getOtch() { return this->otch; }
};

#endif 
