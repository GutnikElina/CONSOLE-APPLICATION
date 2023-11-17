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
	std::ifstream fin("users.txt", std::ios::in);
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
	std::ifstream fin("employees.txt", std::ios::in);
	
	if (fin.is_open())
	{
		std::string surname, name, otch, month, hourlyRate;
		double sal, hours, averageSalary;
		int id, amountOfMonths;
		while (true)
		{
			if (!(fin >> surname >> name >> otch >> id >> hourlyRate >> averageSalary >> amountOfMonths))
				break;
			std::shared_ptr<Employee> emp = std::make_shared<Employee>();
			std::vector<double> salary;
			std::vector<std::pair<std::string, double>> hoursWorkedForMonth;
			emp->setSurname(surname);
			emp->setName(name);
			emp->setOtch(otch);
			emp->setId(id);
			emp->setHourlyRate(hourlyRate);
			emp->setAverageSalary(averageSalary);
			emp->setAmountOfMonths(amountOfMonths);

			for (int i = 0; i < amountOfMonths; i++)
			{
				fin >> sal >> month >> hours;
				salary.push_back(sal);
				hoursWorkedForMonth.emplace_back(month, hours);
			}
			emp->setSalary(salary);
			emp->setHoursWorkedForMonth(hoursWorkedForMonth);
			this->vectorEmployee.push_back(emp);
		}
		fin.close();
	}
	else
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
}

void Vectors::getVectorDepartment()
{
	std::ifstream fin("department.txt", std::ios::in);
	if (fin.is_open())
	{
		std::string title, surname, name, otch, hourlyRate;
		int numberOfProjects, numberOfEmployees, id;
		while (true)
		{
			if (!(fin >> title >> numberOfProjects >> numberOfEmployees))
				break;
			std::shared_ptr<Department> dep = std::make_shared<Department>();
			std::vector<std::shared_ptr<Employee>> employee;
			dep->setTitle(title);
			dep->setNumberOfProjects(numberOfProjects);
			dep->setNumberOfEmployees(numberOfEmployees);

			for (int i = 0; i < numberOfEmployees; i++)
			{
				fin >> surname >> name >> otch >> id >> hourlyRate;
				std::shared_ptr<Employee> emp = std::make_shared<Employee>();
				emp->setSurname(surname);
				emp->setName(name);
				emp->setOtch(otch);
				emp->setId(id);
				emp->setHourlyRate(hourlyRate);
				employee.push_back(emp);
			}
			dep->setEmployees(employee);
			this->vectorDepartment.push_back(dep);
		}
		fin.close();
	}
	else
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
}

void Vectors::addAccountInFile(std::vector<std::shared_ptr<User>> vectorUser)
{
	std::ofstream fout("users.txt", std::ios::out);
	if (!fout.is_open())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
	for (auto& element : vectorUser)
		fout << element->getUsername() << "\t" << element->getPassword() << "\t" << element->getRole() << "\t" << element->getAccess() << "\t" <<
		element->getSurname() << "\t" << element->getName() << "\t" << element->getOtch() << "\t" << std:: endl;
	fout.close();
}

std::string Vectors::singIn(std::vector<std::shared_ptr<User>>& vectorUser)
{
	system("cls");
	Console::GoToXY(50, 12);
	std::cout << "¬¬≈ƒ»“≈ ÀŒ√»Õ";
	Console::GoToXY(53, 13);
	std::string username = checkInputUsername();
	system("cls"); 
	Console::GoToXY(50, 12);
	std::cout << "¬¬≈ƒ»“≈ œ¿–ŒÀ‹";
	Console::GoToXY(54, 13);
	std::string password = checkPassword();
	system("cls");

	for (int i = 0; i < vectorUser.size(); i++)
		if (username == vectorUser.at(i)->getUsername() && password == vectorUser.at(i)->getPassword())
		{
			if (!vectorUser.at(i)->getAccess())
			{
				system("cls");
				Console::GoToXY(42, 12);
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "-!!!- ”◊≈“Õ¿ﬂ «¿œ»—‹ «¿¡ÀŒ »–Œ¬¿Õ¿ -!!!-";
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				char ch = _getch();
				return "null";
			}
			else return vectorUser.at(i)->getUsername();
		}
	system("cls");
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- “¿ Œ… ”◊≈“ÕŒ… «¿œ»—» Õ≈ —”Ÿ≈—“¬”≈“ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return "null";
}

void Vectors::singUp(int role, std::vector<std::shared_ptr<User>>& vectorUser, Vectors& vect)
{
	std::shared_ptr<User> user = std::make_shared<User>();
	user->setRole(role);
	user->setAccess(1);
	system("cls");

	user->setUsername(Vectors::checkUsername(vectorUser));
	user->setPassword(Vectors::checkPassword());

	user->setFullName();

	if (Menu::confirmOrNot())
		vectorUser.push_back(user);

	vect.addAccountInFile(vectorUser);
}


void Vectors::addEmployeeInFile(std::vector<std::shared_ptr<Employee>> vectorEmployee)
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
	for (auto& element : vectorEmployee)
	{
		fout << element->getSurname() << "\t" << element->getName() << "\t" << element->getOtch() <<
			"\t" << element->getId() << "\t" << element->getHourlyRate() << "\t" << element->getAverageSalary() <<
			"\t" << element->getAmountOfMonths();
		for (int j = 0; j < element->getAmountOfMonths(); j++)
		{
			fout << "\t" << element->getSalary().at(j)
				<< "\t" << element->getHoursWorkedForMonth().at(j).first
				<< "\t" << element->getHoursWorkedForMonth().at(j).second;
		}
		fout << "\n";
	}
	fout.close();
}

void Vectors::addDepartmentInFile(std::vector<std::shared_ptr<Department>> vectorDepartment)
{
	std::ofstream fout("department.txt", std::ios_base::trunc);
	if (!fout.is_open())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- Œÿ»¡ ¿ Œ“ –€“»ﬂ ‘¿…À¿ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		exit(1);
	}
	for (auto& element : vectorDepartment)
	{
		fout << "\n" << element->getTitle() << "\t" << element->getNumberOfProjects() << "\t" << element->getNumberOfEmployees();
		for (int j = 0; j < element->getEmployees().size(); j++)
		{
			fout << "\n\t" << element->getEmployees().at(j)->getSurname()
				<< "\t" << element->getEmployees().at(j)->getName()
				<< "\t" << element->getEmployees().at(j)->getOtch()
				<< "\t" << element->getEmployees().at(j)->getId()
				<< "\t" << element->getEmployees().at(j)->getHourlyRate();
		}
	}
	fout << "\n";
	fout.close();
}