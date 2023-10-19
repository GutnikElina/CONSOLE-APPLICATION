#include "menu.h"

FIO::FIO()
{
	this->set("NULL", "NULL", "NULL");
}

FIO::~FIO()
{
	this->name.clear();
	this->surname.clear();
	this->otch.clear();
}

void FIO::set()
{
	system("cls");
	Console::GoToXY(49, 9);
	std::cout << "ÂÂÅÄÈÒÅ ÔÀÌÈËÈÞ";
	Console::GoToXY(53, 10);
	this->surname = Vectors::checkInputUsername();
	Console::GoToXY(50, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÈÌß";
	Console::GoToXY(53, 13);
	this->name = Vectors::checkInputUsername();
	Console::GoToXY(48, 15);
	std::cout << "ÂÂÅÄÈÒÅ ÎÒ×ÅÑÒÂÎ";
	Console::GoToXY(53, 16);
	this->otch = Vectors::checkInputUsername();
}

void FIO::set(std::string name, std::string surname, std::string otch)
{
	this->name = name;
	this->surname = surname;
	this->otch = otch;
}
