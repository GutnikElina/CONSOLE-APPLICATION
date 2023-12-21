#include "menu.h"

void Messages::FileNotOpened()
{
	system("cls");
	Console::GoToXY(50, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ������ �������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	exit(1);
}

void Messages::EmptyDatabase()
{
	system("cls");
	Console::GoToXY(45, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ���� ������ ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorChangingAccess()
{
	Console::GoToXY(38, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ���������� �������� ������ ������ ������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorChangingRole()
{
	Console::GoToXY(38, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ���������� �������� ���� ������ �������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorFindDepartment()
{
	system("cls");
	Console::GoToXY(30, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ������ �������� ������ �� ����������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorFindEmployee()
{
	system("cls");
	Console::GoToXY(30, 14);
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

void Messages::ErrorFindYou()
{
	system("cls");
	Console::GoToXY(35, 13);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- �� �� ��������� � ���� ������ ���������� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::AcountNotExist()
{
	system("cls");
	Console::GoToXY(25, 13);
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
}

void Messages::ErrorLoginTheSame()
{
	Console::GoToXY(30, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << " -!!!- ����� ����� ��������� �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorPasswordTheSame()
{
	Console::GoToXY(30, 17);
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
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ����� ������ �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorYear()
{
	system("cls");
	Console::GoToXY(38, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ��� ������ �������. ���������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 13);
	std::cout << "[ < 2016 ��� > 2023 ���������� �������� � ���� ������]";
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

void Messages::ChangingAccess()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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

void Messages::SuccessAddDepartment()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|        ����� ����� ������� ��������        |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessAddEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|      ����� �������� ������� ��������       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessDeleteDepartment()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|            ����� ������� ������            |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessDeleteEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|          �������� ������� ������           |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::ChangingRole()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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

void Messages::DepartmentChangeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(32, 11);
	std::cout << "+-----------------------------------------------+";
	Console::GoToXY(32, 12);
	std::cout << "|                                               |";
	Console::GoToXY(32, 13);
	std::cout << "|      ���� ������ ������� ������� �������      |";
	Console::GoToXY(32, 14);
	std::cout << "|                                               |";
	Console::GoToXY(32, 15);
	std::cout << "+-----------------------------------------------+";
	char ch = _getch();
}

void Messages::EndSortWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|        ���������� ������� ���������        |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15); 
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::ChangingEmployeeData()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|             �������� ���������             |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::DeleteDBEmployeeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(31, 11);
	std::cout << "+------------------------------------------------+";
	Console::GoToXY(31, 12);
	std::cout << "|                                                |";
	Console::GoToXY(31, 13);
	std::cout << "|     ���� ������ ���������� ������� �������     |";
	Console::GoToXY(31, 14);
	std::cout << "|                                                |";
	Console::GoToXY(31, 15);
	std::cout << "+------------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessAddAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       ����� ������� ������� ��������       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15); 
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessDeleteAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       ������ �������� ������� �������      |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::AccountManagement()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|         ���������� ����������         |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChangeRole()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|            ��������  ����             |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}


void Messages::WorkWithDataEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|      ������ � ������� ����������      |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::DataProcessing()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|           ��������� ������            |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::FindingEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|           ����� ���������             |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::SortingWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|          ���������� ����������        |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::EditingDataWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|         �������������� ������         |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::AddEmployeeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|  ���������� ����� ���������� � �����  |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::AddDepartmentWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|       ���������� ������ ������        |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChooseSortWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|          �������� ����������          |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChangingDataAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|       ��������� ������ ��������       |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChangingDataDepartment()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|        ��������� ������ ������        |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}