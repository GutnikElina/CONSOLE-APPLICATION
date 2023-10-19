#include "menu.h"

std::string Vectors::checkInputUsername()
{
	int ch;
	std::string result;
	while (true)
	{
		bool flag = true;
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >=
			48 && ch <= 57) || ch == 13 || ch == 8)
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

std::string Vectors::checkUsername(std::vector<std::shared_ptr<User>> vectorUser)
{
	std::string username;

	while (true)
	{
		try
		{
			system("cls");
			Console::GoToXY(50, 12);
			std::cout << "¬¬≈ƒ»“≈ ÀŒ√»Õ ";
			Console::GoToXY(40, 13);
			std::cout << "(ˆËÙ˚, ·ÛÍ‚˚ Î‡ÚËÌÒÍÓ„Ó ‡ÎÙ‡‚ËÚ‡)";
			Console::GoToXY(55, 15);
			username = checkInputUsername();
			if (username.size() < 5)
			{
				throw "-!!!- œŒœ–Œ¡”…“≈ «¿ÕŒ¬Œ. ÀŒ√»Õ ƒŒÀ∆≈Õ ¡€“‹ Õ≈  Œ–Œ◊≈ 5 —»Ã¬ŒÀŒ¬ -!!!-";
			}
			else
			{
				for (int i = 0; i < vectorUser.size(); i++)
				{
					if (username == vectorUser.at(i)->getUsername())
					{
						throw "-!!!- œŒœ–Œ¡”…“≈ «¿ÕŒ¬Œ. “¿ Œ… ¿  ¿”Õ“ ”∆≈ —”Ÿ≈—“¬”≈“ -!!!-";
					}
				}
			}
			return username;
		}
		catch (const char* m)
		{
			system("cls");
			Console::GoToXY(30, 12);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << m;
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			char ch = _getch();
		}
	}
}


std::string Vectors::checkInputPassword()
{
	int ch;
	std::string result;
	while (true)
	{
		ch = _getch();
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >=
			48 && ch <= 57) || ch == 13 || ch == 8)
		{
			if (ch == 13)
			{
				if (result.size() != 0)
					break;
			}
			if (ch == 8)
			{
				std::cout << (char)8 << ' ' << char(8);
				if (!result.empty())
					result.erase(result.length() - 1);
			}
			else
			{
				std::cout << '*';
				result += (char)ch;
			}
		}
	}
	std::cout << std::endl;
	return result;
}

std::string Vectors::checkPassword()
{
	std::string password;

	while(true)
	{
		try
		{
			system("cls");
			Console::GoToXY(50, 12);
			std::cout << "¬¬≈ƒ»“≈ œ¿–ŒÀ‹";
			Console::GoToXY(40, 13);
			std::cout << "(ˆËÙ˚, ·ÛÍ‚˚ Î‡ÚËÌÒÍÓ„Ó ‡ÎÙ‡‚ËÚ‡)";
			Console::GoToXY(55, 15);
			password = checkInputPassword();
			std::string hashed_password = hash_password(password);

			if (password.size() < 5)
			{
				throw "-!!!- œŒœ–Œ¡”…“≈ «¿ÕŒ¬Œ. œ¿–ŒÀ‹ ƒŒÀ∆≈Õ ¡€“‹ Õ≈  Œ–Œ◊≈ 5 —»Ã¬ŒÀŒ¬ -!!!-";
			}
			return hashed_password;
		}
		catch (const char* m)
		{
			system("cls");
			Console::GoToXY(30, 12);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << m;
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			char ch = _getch();
		}
	}
}

std::string Vectors::hash_password(const std::string& password)
{
	unsigned int hash = 0;
	int i = 0;
	for (char c : password)
	{
		if (i == 1)
		{
			hash += static_cast<unsigned int>(c);
		}
		if (i == password.size() - 1)
		{
			hash += static_cast<unsigned int>(c);
		}
		i++;
	}
	return std::to_string(hash);
}

int Vectors::countLengthFile(std::string nameFile)
{
	int counter = 0;
	std::string bufString;
	std::ifstream fin(nameFile);
	while (getline(fin, bufString))
	{
		counter++;
	}
	fin.close();
	return counter;
}

void Vectors::getVectorUsers()
{
	for (int i = 0; i < countLengthFile("users.txt"); i++)
		this->vectorUser.push_back(std::make_shared<User>());
	std::ifstream fin("users.txt");
	if (!fin.is_open())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
	else
	{
		if (!vectorUser.size())
		{
			std::shared_ptr<User> user = std::make_shared<User>();
			user->setRole(1);
			user->setAccess(1);
			user->setUsername("admin");
			user->setPassword(Vectors::hash_password("12345"));
			user->setSurname("Gutnik");
			user->setName("Elina");
			user->setOtch("Andreevna");
			this->vectorUser.push_back(user);
		}
		else
		{
			for (auto& element : this->vectorUser)
				element->getFromFile(fin);
		}
		fin.close();
	}
}

void Vectors::getVectorEmployees()
{
	for (int i = 0; i < countLengthFile("employees.txt"); i++)
		this->vectorEmployee.push_back(std::make_shared<Employee>());
	std::ifstream fin("employees.txt");
	if (!fin.is_open())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
	else
	{
		for (auto& element : this->vectorEmployee)
			element->getFromFile(fin);
		fin.close();
	}
}

void Vectors::getVectorDepartment()
{
	for (int i = 0; i < countLengthFile("department.txt"); i++)
		this->vectorDepartment.push_back(std::make_shared<Department>());
	std::ifstream fin("department.txt");
	if (!fin.is_open())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
	else
	{
		for (auto& element : this->vectorDepartment)
			element->getFromFile(fin);
		fin.close();
	}
}

void Vectors::addAccountInFile()
{
	std::ofstream fout("users.txt", std::ios_base::trunc);
	for (auto& element : this->vectorUser)
		fout << element->getUsername() << "\t" << element->getPassword() << "\t" << element->getRole() << "\t" << element->getAccess() << "\t" <<
		element->getSurname() << "\t" << element->getName() << "\t" << element->getOtch() << "\t" << std:: endl;
	fout.close();
}

std::string Vectors::singIn(std::vector<std::shared_ptr<User>>& vectorUser)
{
	system("cls");
	Console::GoToXY(50, 12);
	std::string username = checkInputUsername();
	system("cls");
	Console::GoToXY(50, 12);
	std::string password = checkPassword();
	system("cls");

	for (int i = 0; i < vectorUser.size(); i++)
		if (username == vectorUser.at(i)->getUsername() && password == vectorUser.at(i)->getPassword())
		{
			if (vectorUser.at(i)->getAccess())
			{
				system("cls");
				Console::GoToXY(50, 12);
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "-!!!- ”◊≈“Õ¿ﬂ «¿œ»—‹ «¿¡ÀŒ »–Œ¬¿Õ¿ -!!!-";
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				system("pause");
				return "null";
			}
			else return vectorUser.at(i)->getUsername();
		}
	system("cls");
	Console::GoToXY(50, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- “¿ Œ… ”◊≈“ÕŒ… «¿œ»—» Õ≈ —”Ÿ≈—“¬”≈“ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("pause");
	return "null";
}

void Vectors::addEmployeeInFile()
{
	std::ofstream fout("employees.txt", std::ios_base::trunc);
	if (!fout.is_open())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
	for (auto& element : this->vectorEmployee)
	{
		fout << element->getSurname() << "\t" << element->getName() << "\t" << element->getOtch() <<
			"\t" << element->getId() << "\t" << element->getHourlyRate() << "\t" << element->getAverageSalary() <<
			"\t" << element->getAmountOfMonths();
		for (int j = 0; j < element->getHoursWorkedForMonth().size(); j++)
		{
			fout << "\t" << element->getSalary().at(j)
				<< "\t" << element->getHoursWorkedForMonth().at(j);
		}
	}
	fout.close();
}



