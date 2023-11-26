#include "menu.h"

void Menu::FileNotOpened()
{
	system("cls");
	Console::GoToXY(50, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ������ �������� ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	exit(1);
}

void Menu::EmptyDatabase()
{
	system("cls");
	Console::GoToXY(45, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ���� ������ ����� -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return;
}

int Menu::CheckInt()
{
	std::string result;
	char ch;

	while (true)
	{
		ch = _getch();
		if (std::isdigit(ch) || ch == 13 || ch == 8 )
		{
			if (ch == 13 && !result.empty())
				break;
			else if (ch == 8 && !result.empty())
			{
				std::cout << "\b \b";
				result.pop_back();
			}
			else
			{
				std::cout << ch;
				result += ch;
			}
		}
	}
	std::cout << std::endl;
	int number = std::stoi(result);
	return number;
}

std::string Menu::CheckDouble() 
{
	std::string result;
	char ch;

	while (true) 
	{
		ch = _getch();
		if (std::isdigit(ch) || ch == 13 || ch == 8 || ch == 46) 
		{
			if (ch == 13 && !result.empty())
				break;
			else if (ch == 8 && !result.empty()) 
			{
				std::cout << "\b \b";
				result.pop_back();
			}
			else 
			{
				std::cout << ch;
				result += ch;
			}
		}
	}
	std::cout << std::endl;
	return result;
}

std::string Menu::CheckString()
{
	int ch;
	std::string result;
	while (true)
	{
		ch = _getch();
		if (std::isalpha(ch) || ch == 13 || ch == 8)
		{
			if (ch == 13 && !result.empty())
				break;
			else if (ch == 8 && !result.empty())
			{
				std::cout << "\b \b";
				result.pop_back();
			}
			else
			{
				std::cout << static_cast<char>(ch);
				result += static_cast<char>(ch);
			}
		}
	}
	std::cout << std::endl;
	return result;
}

int Menu::ChoiceKeyboard(std::string main_menu[], int size)
{
	int x, y, active_menu = 0;
	while (true)
	{
		
		x = 45, y = 14;
		for (int i = 0; i < size; i++)
		{
			if (i == active_menu)
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else 		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			Console::GoToXY(x, y++);
			std::cout << main_menu[i] << std::endl;
		}

		char choice = _getch();
		if (choice == -32) choice = _getch(); // ����������� ���������

		switch (choice)
		{
		case Keyboard::ESCAPE:
			exit(0);

		case Keyboard::UP:
			if (active_menu > 0)
				--active_menu;
			break;

		case Keyboard::DOWN:
			if (active_menu < size - 1)
				++active_menu;
			break;

		case Keyboard::ENTER:
			switch (active_menu)
			{
			case 0:
				return 0;
				break;
			case 1:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 3;
				break;
			case 4:
				return 4;
				break;
			case 5:
				return 5;
				break;
			}
		}
	}
}

bool Menu::exitOrNot()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 12);
	std::cout << "�� ������������� ������ �����?";
	std::string question[] = { " ������", "  �����" };
	if (Menu::ChoiceKeyboard(question, (int)size(question)))
		return true;
	else return false;
}

bool Menu::continueOrNot()
{
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "������� ����������? ";
	std::string line[] = { " ��", "���" };
	if (Menu::ChoiceKeyboard(line, (int)size(line)))
		return false;
	else return true;
}

bool Menu::confirmOrNot()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(30, 8);
	std::cout << "+--------------------------------------------------------+";
	Console::GoToXY(30, 9);
	std::cout << "|                                                        |";
	Console::GoToXY(30, 10);
	std::cout << "|    �����������, ��� �� ������ ��������� ��������       |";
	Console::GoToXY(30, 11);
	std::cout << "|                                                        |";
	Console::GoToXY(30, 12);
	std::cout << "+--------------------------------------------------------+";
	std::string line[] = { "��, �����������", "    �����" };
	if (Menu::ChoiceKeyboard(line, (int)size(line)))
		return false;
	else return true;
}

void Menu::ChangeAccountMenu(std::vector<std::shared_ptr<User>>& vector_user, std::string username)
{
	std::string menu[] = { "     ���������� ��� ��������", "      �������� ����� �������", "        ������� �������",
		"   ������������� ������ ��������", "        ��������� �����" };
	char ch;

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|           ���������� ����������           |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			User::ShowAccounts(vector_user);
			ch = _getch();
			break;
		case 1:
			system("cls");
			User::AddNewAccount(vector_user);
			break;
		case 2:
			system("cls");
			User::DeleteAccount(vector_user, username);
			break;
		case 3:
			system("cls");
			User::ChangeAccount(vector_user, username);
			break;
		case 4:
			return;
		}
	}
}

void Menu::MenuAdmin(Vectors& vect, std::string username)
{
	std::string admin_menu[] = { "        ��������� ����������", "  �������� c ������� ����������",
		"   �������� c ������� �������","         ����� �� ��������" };
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(40, 8);
		std::cout << "+---------------------------------------+";
		Console::GoToXY(40, 9);
		std::cout << "|                                       |";
		Console::GoToXY(40, 10);
		std::cout << "|      ������������ ���, " << std::setw(15) << std::left << username << "|";
		Console::GoToXY(40, 11);
		std::cout << "|                                       |";
		Console::GoToXY(40, 12);
		std::cout << "+---------------------------------------+";

		switch (Menu::ChoiceKeyboard(admin_menu, (int)size(admin_menu)))
		{
		case 0:
			system("cls");
			ChangeAccountMenu(vect.GetUsers(), username);
			break;
		case 1:
			system("cls");
			WorkWithDataMenu(vect.GetEmployees());
			break;
		case 2:
			system("cls");
			WorkWithDepartmentsMenu(vect.GetEmployees(), vect.GetDepartment());
			break;
		case 3:
			if (exitOrNot())
				return;
			else break;
		}
	}
}

void Menu::WorkWithDataMenu(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	std::string menu[] = { " ���������� ������", "������������� ������", "   ��������� �����" };
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|        ������ � ������� ����������        |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";
		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			DataProcessingMenu(vector_employee);
			break;
		case 1:
			system("cls");
			ChangeDataMenu(vector_employee);
			break;
		case 2:
			return;
		}
	}
}

void Menu::DataProcessingMenu(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	std::string menu[] = { "      ����� ���������", "   ����������� ����������", "�������� �������� �� ���-� �����", "      ��������� �����" };
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|            ��������� ������            |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			FindMenu(vector_employee);
			break;
		case 1:
			system("cls");
			SortMenu(vector_employee);
			break;
		case 2:
			system("cls");
			Employee::SalaryData(vector_employee);
			break;
		case 3:
			return;
		}
	}
}


void Menu::FindMenu(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) EmptyDatabase();
	
	std::string menu[] = { "     ����� ��������� �� ���", "����� ��������� �� ���������� ������",
		"����� ��������� �� ���������� ������", "        ��������� �����" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|            ����� ���������             |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";
		
		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			Employee::FindByName(vector_employee);
			break;
		case 1:
			system("cls");
			Employee::FindById(vector_employee);
			break;
		case 2:
			system("cls");
			Employee::FindByHourlyRate(vector_employee);
			break;
		case 3:
			return;
		}
	}
}

void Menu::SortMenu(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	char ch;
	if (!vector_employee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ���� ������ ����� -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::string menu[] = { "    ����������� ���������� �� �������", "����������� ���������� �� ���������� ������",
		"����������� ���������� �� ���������� ������", "              ��������� �����" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|          ���������� ����������         |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			Employee::SortBySurname(vector_employee);
			break;
		case 1:
			system("cls");
			Employee::SortByID(vector_employee);
			break;
		case 2:
			system("cls");
			Employee::SortByHourlyRate(vector_employee);
			break;
		case 3:
			return;
		}
	}
}

void Menu::ChangeDataMenu(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	std::string menu[] = { "  �������� ������ ����������", "������� ��� ���� ������ ����������", "      �������� ���������",
		"���������� ���� ������ ����������", "      ������� ���������", "       ��������� �����" };
	char ch;

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|          �������������� ������         |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			EditDatabaseMenu(vector_employee);
			break;
		case 1:
			system("cls");
			Employee::DeleteDatabase(vector_employee);
			break;
		case 2:
			system("cls");
			Employee::AddEmployeeDatabase(vector_employee);
			break;
		case 3:
			system("cls");
			Employee::DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 4:
			system("cls");
			Employee::DeleteEmployee(vector_employee);
			break;
		case 5:
			return;
		}
	}

}

void Menu::EditDatabaseMenu(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	char ch;
	if (!vector_employee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ���� ������ ����� -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	int numberOfEmployee = Employee::FindEmployee(vector_employee);
	numberOfEmployee--;

	std::string menu[] = { "    ��������� �������", "     ��������� �����", "   ��������� ��������",
		"��������� ���������� ������", "��������� ���������� ������", "    ��������� �����" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+-----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                         |";
		Console::GoToXY(36, 10);
		std::cout << "|       ��������� ������ � ���������      |";
		Console::GoToXY(36, 11);
		std::cout << "|                                         |";
		Console::GoToXY(36, 12);
		std::cout << "+-----------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			Employee::ChangeSurname(vector_employee, numberOfEmployee);
			break;
		case 1:
			system("cls");
			Employee::ChangeName(vector_employee, numberOfEmployee);
			break;
		case 2:
			system("cls");
			Employee::ChangeOtch(vector_employee, numberOfEmployee);
			break;
		case 3:
			system("cls");
			Employee::ChangeId(vector_employee, numberOfEmployee);
			break;
		case 4:
			system("cls");
			Employee::ChangeHourlyRate(vector_employee, numberOfEmployee);
			break;
		case 5:
			return;
		}
	}
}

void Menu::WorkWithDepartmentsMenu(std::vector<std::shared_ptr<Employee>>& empl, std::vector<std::shared_ptr<Department>>& dep)
{
	char ch;
	std::string menu[] = { "    �������� ������ ������", "������� ��� ���� ������ �������", "���������� ���� ������ �������",
		"        �������� �����", "         ������� �����", "        ��������� �����" };
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|       �������������� ������ �������       |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			EditDatabaseDepartmentMenu(empl, dep);
			break;
		case 1:
			system("cls");
			Department::DeleteDatabaseDepartment(dep);
			break;
		case 2:
			system("cls");
			Department::DepartmentsDatabase(dep);
			ch = _getch();
			break;
		case 3:
			system("cls");
			Department::AddNewDepartment(empl, dep);
			break;
		case 4:
			system("cls");
			Department::DeleteDepartment(dep);
			break;
		case 5:
			return;
		}
	}
}

void Menu::EditDatabaseDepartmentMenu(std::vector<std::shared_ptr<Employee>>& empl, std::vector<std::shared_ptr<Department>>& dep)
{
	if (!dep.size()) EmptyDatabase();
	int number_department = Department::FindDepartment(dep);
	number_department--;
	std::string menu[] = { "    ��������� ��������", "��������� ���-�� ��������", "   �������� ���������",
		"   ������� ���������",  "    ��������� �����" };

	switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
	{
	case 0:
		system("cls");
		Department::ChangeTitle(dep, number_department);
		break;
	case 1:
		system("cls");
		Department::ChangeNumberOfProjects(dep, number_department);
		break;
	case 2:
		system("cls");
		Department::AddNewEmployeeInDepartment(empl, dep, number_department);
		break;
	case 3:
		system("cls");
		Department::DeleteEmployeeFromDepartment(dep, number_department);
		break;
	case 4:
		return;
	}
}

void Menu::MenuUser(Vectors& vect, std::string username)
{
	std::string user_menu[] = { " ���������� ���� ���� ������",  "���������� ���� ������ �������", "    ��������� ���������", "     ����� �� ��������" };
	char ch;
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(40, 9);
		std::cout << "+---------------------------------------+";
		Console::GoToXY(40, 10);
		std::cout << "|      ������������ ���, " << std::setw(15) << std::left << username << "|";
		Console::GoToXY(40, 11);
		std::cout << "+---------------------------------------+";

		switch (Menu::ChoiceKeyboard(user_menu, (int)size(user_menu)))
		{
		case 0:
			system("cls");
			Employee::DatabaseForUser(vect.GetUsers(), vect.GetEmployees(), username);
			ch = _getch();
			break;
		case 1:
			system("cls");
			Department::DepartmentsDatabase(vect.GetDepartment());
			ch = _getch();
			break;
		case 2:
			system("cls");
			User::ChangeMyAccount(vect.GetUsers(), username);
			break;
		case 3:
			if (!exitOrNot())
				break;
			else return;
		}
	}
}
