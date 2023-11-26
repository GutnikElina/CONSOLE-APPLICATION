#include "menu.h"

FIO::FIO()
{
	this->Set("NULL", "NULL", "NULL");
}

void FIO::Set(std::string name, std::string surname, std::string otch)
{
	this->name = name;
	this->surname = surname;
	this->otch = otch;
}

FIO::~FIO()
{
	this->name.clear();
	this->surname.clear();
	this->otch.clear();
}

void FIO::SetFullName()
{
	system("cls");
	Console::GoToXY(49, 9);
	std::cout << "ÂÂÅÄÈÒÅ ÔÀÌÈËÈÞ";
	Console::GoToXY(53, 10);
	this->surname = Menu::CheckString();
	Console::GoToXY(50, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÈÌß";
	Console::GoToXY(53, 13);
	this->name = Menu::CheckString();
	Console::GoToXY(48, 15);
	std::cout << "ÂÂÅÄÈÒÅ ÎÒ×ÅÑÒÂÎ";
	Console::GoToXY(53, 16);
	this->otch = Menu::CheckString();
}

void FIO::GetFromFile(std::istream& in) 
{ 
	in >> this->surname >> this->name >> this->otch; 
}
