#include "menu.h"

int Menu::checkInt()
{
	char ch;
	while (1)
	{
		try
		{
			int num;
			std::cin >> num;
			if (std::cin.fail())
			{
				throw 1;
			}
			return num;
		}
		catch (int)
		{
			system("cls");
			Console::GoToXY(50, 12);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << " -!!!- ПОПРОБУЙТЕ СНОВА -!!!-\n";
			std::cin.clear();
			std::cin.ignore();
			ch = _getch();
			system("cls");
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
	}
}

std::string Menu::checkDouble()
{
	int ch;
	std::string result;
	while (true)
	{
		bool flag = true;
		ch = _getch();
		if ((ch >= 48 && ch <= 57) || ch == 13 || ch == 8 || ch == 46)
		{
			if (ch == 13)
			{
				if (result.size() != 0)
					break;
			}
			else
				if (ch == 8)
				{
					std::cout << (char)8 << ' ' << char(8);
					if (!result.empty())
						result.erase(result.length() - 1);
				}
				else
				{
					std::cout << (char)ch;
					result += (char)ch;
				}
		}
	}
	std::cout << std::endl;
	return result;
}

std::string Menu::checkString()
{
	int ch;
	std::string result;
	while (true)
	{
		bool flag = true;
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == 13 || ch == 8)
		{
			if (ch == 13)
			{
				if (result.size() != 0)
					break;
			}
			else
				if (ch == 8)
				{
					std::cout << (char)8 << ' ' << char(8);
					if (!result.empty())
						result.erase(result.length() - 1);
				}
				else
				{
					std::cout << (char)ch;
					result += (char)ch;
				}
		}
	}
	std::cout << std::endl;
	return result;
}


int Menu::choiceKeyboard(std::string mainMenu[], int size)
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
			std::cout << mainMenu[i] << std::endl;
		}

		char choice = _getch();
		if (choice == -32) choice = _getch(); // Отлавливаем стрелочки

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
	std::cout << "ВЫ ДЕЙСТВИТЕЛЬНО ХОТИТЕ ВЫЙТИ?";

	std::string question[] = { " Отмена", "  Выйти" };
	int active_menu = 0;
	bool flag = true;

	if (Menu::choiceKeyboard(question, size(question)))
		return true;
	else return false;

}

bool Menu::continueOrNot()
{
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "ЖЕЛАЕТЕ ПРОДОЛЖИТЬ? ";

	std::string line[] = { " Да", "Нет" };

	switch (Menu::choiceKeyboard(line, size(line)))
	{
	case 0:
		return true;
	case 1:
		return false;
	}
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
	std::cout << "|    ПОДТВЕРДИТЕ, ЧТО ВЫ ХОТИТЕ ВЫПОЛНИТЬ ДЕЙСТВИЕ       |";
	Console::GoToXY(30, 11);
	std::cout << "|                                                        |";
	Console::GoToXY(30, 12);
	std::cout << "+--------------------------------------------------------+";

	int x, y, option = 0;
	std::string line[] = { "Да, подтверждаю", "    Выйти" };

	switch (Menu::choiceKeyboard(line, size(line)))
	{
	case 0:
		return true;
	case 1:
		return false;
	}
}

void Menu::changeAccountMenu(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	std::string menu[] = { "     Посмотреть все аккаунты", "      Добавить новый аккаунт", "        Удалить аккаунт",
		"   Редактировать данные аккаунта", "        Вернуться назад" };
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
		std::cout << "|           УПРАВЛЕНИЕ АККАУНТАМИ           |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			User::showAccounts(vectorUser);
			ch = _getch();
			break;
		case 1:
			system("cls");
			User::addNewAccount(vectorUser);
			break;
		case 2:
			system("cls");
			User::deleteAccount(vectorUser, username);
			break;
		case 3:
			system("cls");
			User::changeAccount(vectorUser, username);
			break;
		case 4:
			return;
		}
	}
}

void Menu::menuAdmin(Vectors& vect, std::string username)
{
	std::string adminMenu[] = { "        Управлять аккаунтами", "  Работать c данными работников",
		"   Работать c данными отделов","         Выйти из аккаунта" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(40, 8);
		std::cout << "+---------------------------------------+";
		Console::GoToXY(40, 9);
		std::cout << "|                                       |";
		Console::GoToXY(40, 10);
		std::cout << "|      ПРИВЕТСТВУЕМ ВАС, " << std::setw(15) << std::left << username << "|";
		Console::GoToXY(40, 11);
		std::cout << "|                                       |";
		Console::GoToXY(40, 12);
		std::cout << "+---------------------------------------+";

		switch (Menu::choiceKeyboard(adminMenu, size(adminMenu)))
		{
		case 0:
			system("cls");
			changeAccountMenu(vect.getUsers(), username);
			break;
		case 1:
			system("cls");
			workWithDataMenu(vect.getEmployees());
			break;
		case 2:
			system("cls");
			workWithDepartmentsMenu(vect.getEmployees(), vect.getDepartment());
			break;
		case 3:
			if (exitOrNot())
				return;
			else break;
		}
	}
}

void Menu::workWithDataMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	std::string menu[] = { " Обработать данные", "Редактировать данные", "   Вернуться назад" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|        РАБОТА С ДАННЫМИ РАБОТНИКОВ        |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";
		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			dataProcessingMenu(vectorEmployee);
			break;
		case 1:
			system("cls");
			changeDataMenu(vectorEmployee);
			break;
		case 2:
			return;
		}
	}
}

void Menu::dataProcessingMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	std::string menu[] = { "      Найти работника", "   Сортировать работников", "Показать зарплату за опр-й месяц", "      Вернуться назад" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|            ОБРАБОТКА ДАННЫХ            |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			findMenu(vectorEmployee);
			break;
		case 1:
			system("cls");
			sortMenu(vectorEmployee);
			break;
		case 2:
			system("cls");
			Employee::salaryData(vectorEmployee);
			break;
		case 3:
			return;
		}
	}
}


void Menu::findMenu(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- БАЗА ДАННЫХ ПУСТА -!!!-" << std::endl;
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}
	
	std::string menu[] = { "     Найти работника по ФИО", "Найти работника по табельному номеру",
		"Найти работника по почасовому тарифу", "        Вернуться назад" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|            ПОИСК РАБОТНИКА             |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";
		
		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			Employee::findByName(vectorEmployee);
			break;
		case 1:
			system("cls");
			Employee::findById(vectorEmployee);
			break;
		case 2:
			system("cls");
			Employee::findByHourlyRate(vectorEmployee);
			break;
		case 3:
			return;
		}
	}
}

void Menu::sortMenu(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- БАЗА ДАННЫХ ПУСТА -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::string menu[] = { "    Сортировать работников по фамилии", "Сортировать работников по табельному номеру",
		"Сортировать работников по почасовому тарифу", "              Вернуться назад" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                        |";
		Console::GoToXY(36, 10);
		std::cout << "|          СОРТИРОВКА РАБОТНИКОВ         |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			Employee::sortBySurname(vectorEmployee);
			break;
		case 1:
			system("cls");
			Employee::sortByID(vectorEmployee);
			break;
		case 2:
			system("cls");
			Employee::sortByHourlyRate(vectorEmployee);
			break;
		case 3:
			return;
		}
	}
}

void Menu::changeDataMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	std::string menu[] = { "  Изменить данные работников", "Удалить всю базу данных работников", "      Добавить работника",
		"Посмотреть базу данных работников", "      Удалить работника", "       Вернуться назад" };
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
		std::cout << "|          РЕДАКТИРОВАНИЕ ДАННЫХ         |";
		Console::GoToXY(36, 11);
		std::cout << "|                                        |";
		Console::GoToXY(36, 12);
		std::cout << "+----------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			editDatabaseMenu(vectorEmployee);
			break;
		case 1:
			system("cls");
			Employee::deleteDatabase(vectorEmployee);
			break;
		case 2:
			system("cls");
			Employee::addEmployeeDatabase(vectorEmployee);
			break;
		case 3:
			system("cls");
			Employee::database(vectorEmployee);
			ch = _getch();
			break;
		case 4:
			system("cls");
			Employee::deleteEmployee(vectorEmployee);
			break;
		case 5:
			return;
		}
	}

}

void Menu::editDatabaseMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- БАЗА ДАННЫХ ПУСТА -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	int numberOfEmployee = Employee::findEmployee(vectorEmployee);
	numberOfEmployee--;

	std::string menu[] = { "    Изменение фамилии", "     Изменение имени", "   Изменение отчества",
		"Изменение табельного номера", "Изменение почасового тарифа", "    Вернуться назад" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+-----------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                         |";
		Console::GoToXY(36, 10);
		std::cout << "|       ИЗМЕНЕНИЕ ДАННЫХ О РАБОТНИКЕ      |";
		Console::GoToXY(36, 11);
		std::cout << "|                                         |";
		Console::GoToXY(36, 12);
		std::cout << "+-----------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			Employee::changeSurname(vectorEmployee, numberOfEmployee);
			break;
		case 1:
			system("cls");
			Employee::changeName(vectorEmployee, numberOfEmployee);
			break;
		case 2:
			system("cls");
			Employee::changeOtch(vectorEmployee, numberOfEmployee);
			break;
		case 3:
			system("cls");
			Employee::changeId(vectorEmployee, numberOfEmployee);
			break;
		case 4:
			system("cls");
			Employee::changeHourlyRate(vectorEmployee, numberOfEmployee);
			break;
		case 5:
			return;
		}
	}
}

void Menu::workWithDepartmentsMenu(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep)
{
	int x, y, option = 0;
	char choice, ch;
	bool flag = true;
	std::string menu[] = { "    Изменить данные отдела", "Удалить всю базу данных отделов", "Посмотреть базу данных отделов",
		"        Добавить отдел", "         Удалить отдел", "        Вернуться назад" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|       РЕДАКТИРОВАНИЕ ДАННЫХ ОТДЕЛОВ       |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			editDatabaseDepartmentMenu(emp, dep);
			break;
		case 1:
			system("cls");
			Department::deleteDatabaseDepartment(dep);
			break;
		case 2:
			system("cls");
			Department::databaseDepartment(dep);
			ch = _getch();
			break;
		case 3:
			system("cls");
			Department::addNewDepartment(emp, dep);
			break;
		case 4:
			system("cls");
			Department::deleteDepartment(dep);
			break;
		case 5:
			return;
		}
	}
}

void Menu::editDatabaseDepartmentMenu(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep)
{
	char ch;
	if (!dep.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- БАЗА ДАННЫХ ПУСТА -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	int numberOfDepartment = Department::findDepartment(dep);
	numberOfDepartment--;

	std::string menu[] = { "    Изменение названия", "Изменение кол-ва проектов", "   Добавить работника",
		"   Удалить работника",  "    Вернуться назад" };

	switch (Menu::choiceKeyboard(menu, size(menu)))
	{
	case 0:
		system("cls");
		Department::changeTitle(dep, numberOfDepartment);
		break;
	case 1:
		system("cls");
		Department::changeNumberOfProjects(dep, numberOfDepartment);
		break;
	case 2:
		system("cls");
		Department::addNewEmployeeInDepartment(emp, dep, numberOfDepartment);
		break;
	case 3:
		system("cls");
		Department::deleteEmployeeFromDepartment(dep, numberOfDepartment);
		break;
	case 4:
		return;
	}
}

void Menu::menuUser(Vectors& vect, std::string username)
{
	std::string userMenu[] = { " Посмотреть свою базу данных",  "Посмотреть базу данных отделов", "    Управлять аккаунтом", "     Выйти из аккаунта" };
	char ch;

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(40, 9);
		std::cout << "+---------------------------------------+";
		Console::GoToXY(40, 10);
		std::cout << "|      ПРИВЕТСТВУЕМ ВАС, " << std::setw(15) << std::left << username << "|";
		Console::GoToXY(40, 11);
		std::cout << "+---------------------------------------+";

		switch (Menu::choiceKeyboard(userMenu, size(userMenu)))
		{
		case 0:
			system("cls");
			Employee::databaseForUser(vect.getUsers(), vect.getEmployees(), username);
			ch = _getch();
			break;
		case 1:
			system("cls");
			Department::databaseDepartment(vect.getDepartment());
			ch = _getch();
			break;
		case 2:
			system("cls");
			User::changeMyAccount(vect.getUsers(), username);
			break;
		case 3:
			if (!exitOrNot())
				break;
			else return;
		}
	}
}
