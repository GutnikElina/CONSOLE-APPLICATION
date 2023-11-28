#include "menu.h"

void Messages::UpdatingWindow(std::string word)
{
	system("cls");
	Console::GoToXY(36, 11);
	std::cout << "+-------------------------------------------+";
	Console::GoToXY(36, 12);
	std::cout << "|                                           |";
	Console::GoToXY(36, 13);
	std::cout << "|          " << std::setw(6) << std::left << word << " ������� ��������          |";
	Console::GoToXY(36, 14);
	std::cout << "|                                           |";
	Console::GoToXY(36, 15);
	std::cout << "+-------------------------------------------+";
	char ch = _getch();
}

void Messages::ErrorChangingAccess()
{
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ���������� �������� ������ ������ ������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ChangingAccess()
{
	system("cls");
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|      ������ �������� ������� �������       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}


void Messages::ChangingRole()
{
	system("cls");
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       ���� �������� ������� ��������       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::ErrorChangingRole()
{
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ���������� �������� ���� ������ �������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return;
}

void Messages::ChangingDataAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|          ��������� ������ ��������          |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";
}

void Messages::ErrorFindDepartment()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ������ �������� ������ �� ����������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::DepartmentChangeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+----------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                        |";
	Console::GoToXY(35, 13);
	std::cout << "|           �������� ���������           |";
	Console::GoToXY(35, 14);
	std::cout << "|                                        |";
	Console::GoToXY(35, 15);
	std::cout << "+----------------------------------------+";
	char ch = _getch();
}

void Messages::AddEmployeeWindow()
{
	system("cls");
	Console::GoToXY(36, 8);
	std::cout << "+-----------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                               |";
	Console::GoToXY(36, 10);
	std::cout << "|      ���������� ����� ���������� � �����      |";
	Console::GoToXY(36, 11);
	std::cout << "|                                               |";
	Console::GoToXY(36, 12);
	std::cout << "+-----------------------------------------------+";
}

void Messages::ErrorFindEmployee()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ������ ��������� �� ����������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

void Messages::ConfirmDeleting()
{
	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- �����������, ��� �� ������ ������� ��� ���� ������ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::AddDepartmentWindow()
{
	system("cls");
	Console::GoToXY(36, 8);
	std::cout << "+-------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                           |";
	Console::GoToXY(36, 10);
	std::cout << "|         ���������� ������ ������          |";
	Console::GoToXY(36, 11);
	std::cout << "|                                           |";
	Console::GoToXY(36, 12);
	std::cout << "+-------------------------------------------+";
}

void Messages::ChooseSortWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+-----------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                         |";
	Console::GoToXY(36, 10);
	std::cout << "|           �������� ����������           |";
	Console::GoToXY(36, 11);
	std::cout << "|                                         |";
	Console::GoToXY(36, 12);
	std::cout << "+-----------------------------------------+";
}

void Messages::EndSortWindow()
{
	system("cls");
	std::cout << std::endl << std::endl << "------------------------ ���������� ������� ��������� -------------------------------" << std::endl;
	char ch = _getch();
	return;
}

void Messages::ChangingEmployeeData()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 14);
	std::cout << "+------------------------------------------+";
	Console::GoToXY(35, 15);
	std::cout << "|                                          |";
	Console::GoToXY(35, 16);
	std::cout << "|             �������� ���������           |";
	Console::GoToXY(35, 17);
	std::cout << "|                                          |";
	Console::GoToXY(35, 18);
	std::cout << "+------------------------------------------+";
	char ch = _getch();
}

void Messages::DeleteDBEmployeeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(20, 11);
	std::cout << "+----------------------------------------------------+";
	Console::GoToXY(20, 12);
	std::cout << "|                                                    |";
	Console::GoToXY(20, 13);
	std::cout << "|       ���� ������ ���������� ������� �������       |";
	Console::GoToXY(20, 14);
	std::cout << "|                                                    |";
	Console::GoToXY(20, 15);
	std::cout << "+----------------------------------------------------+";
	char ch = _getch();
}

void Messages::ErrorFindYou()
{
	system("cls");
	Console::GoToXY(35, 13);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- �� �� ��������� � ���� ������ ���������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::SuccessAddAccount()
{
	system("cls");
	Console::GoToXY(36, 11);
	std::cout << "+------------------------------------------+";
	Console::GoToXY(36, 12);
	std::cout << "|                                          |";
	Console::GoToXY(36, 13);
	std::cout << "|      ����� ������� ������� ��������      |";
	Console::GoToXY(36, 14);
	std::cout << "|                                          |";
	Console::GoToXY(36, 15);
	std::cout << "+------------------------------------------+";
	char ch = _getch();
}

void Messages::AcountNotExist()
{
	system("cls");
	Console::GoToXY(25, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- �� ��������. ������ �������� �� ����������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorDeleteMyAccount()
{
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << std::endl << "-!!!- ���������� ������� ���� ������� -!!!- ";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return;
}

void Messages::SuccessDeleteAccount()
{
	system("cls");
	Console::GoToXY(35, 11);
	std::cout << "+-------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                           |";
	Console::GoToXY(35, 13);
	std::cout << "|      ������ �������� ������� �������      |";
	Console::GoToXY(35, 14);
	std::cout << "|                                           |";
	Console::GoToXY(35, 15);
	std::cout << "+-------------------------------------------+";
	char ch = _getch();
	return;
}

void Messages::ErrorLoginTheSame()
{
	Console::GoToXY(33, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << " -!!!- ����� ����� ��������� �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorPasswordTheSame()
{
	Console::GoToXY(33, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ����� ������ ��������� �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorData()
{
	system("cls");
	Console::GoToXY(15, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ����� ���� � ���� ������ �� ����������, ���� �� �������� ���� ����. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

void Messages::ErrorMonth()
{
	system("cls");
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ����� ������ �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorYear()
{
	system("cls");
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ��� ������ �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 13);
	std::cout << "[������ 2016 ���� ���������� �������� � ���� ������]";
	char ch = _getch();
}

void Messages::ErrorInputHours()
{
	system("cls");
	Console::GoToXY(25, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ����� ������� ���-�� ������������ ����� ������ �� 12 ������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}