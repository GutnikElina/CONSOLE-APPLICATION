#include "menu.h"

void Menu::FileNotOpened()
{
	system("cls");
	Console::GoToXY(50, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ОШИБКА ОТКРЫТИЯ ФАЙЛА -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	exit(1);
}

int Menu::CheckInt()
{
	char ch;
	while (1)
	{
		try
		{
			int number;
			std::cin >> number;
			if (std::cin.fail())
			{
				throw 1;
			}
			return number;
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

std::string Menu::CheckDouble()
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

std::string Menu::CheckString()
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


int Menu::ChoiceKeyboard(std::string mainMenu[], int size)
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

	if (Menu::ChoiceKeyboard(question, size(question)))
		return true;
	else return false;

}

bool Menu::continueOrNot()
{
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "ЖЕЛАЕТЕ ПРОДОЛЖИТЬ? ";

	std::string line[] = { " Да", "Нет" };

	switch (Menu::ChoiceKeyboard(line, size(line)))
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

	std::string line[] = { "Да, подтверждаю", "    Выйти" };

	switch (Menu::ChoiceKeyboard(line, size(line)))
	{
	case 0:
		return true;
	case 1:
		return false;
	}
}

void Menu::ChangeAccountMenu(std::vector<std::shared_ptr<User>>& vector_user, std::string username)
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

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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
	std::string admin_menu[] = { "        Управлять аккаунтами", "  Работать c данными работников",
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

		switch (Menu::ChoiceKeyboard(admin_menu, size(admin_menu)))
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
		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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
	char ch;
	if (!vector_employee.size())
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
		
		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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
		std::cout << "-!!!- БАЗА ДАННЫХ ПУСТА -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	int numberOfEmployee = Employee::FindEmployee(vector_employee);
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

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
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

	int number_department = Department::FindDepartment(dep);
	number_department--;

	std::string menu[] = { "    Изменение названия", "Изменение кол-ва проектов", "   Добавить работника",
		"   Удалить работника",  "    Вернуться назад" };

	switch (Menu::ChoiceKeyboard(menu, size(menu)))
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
	std::string user_menu[] = { " Посмотреть свою базу данных",  "Посмотреть базу данных отделов", "    Управлять аккаунтом", "     Выйти из аккаунта" };
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

		switch (Menu::ChoiceKeyboard(user_menu, size(user_menu)))
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
