#include "menu.h"

std::string Vectors::CheckInputUsername()
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

std::string Vectors::FindUsername(std::vector<std::shared_ptr<User>> vectorUser)
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
			username = CheckInputUsername();
			if (username.size() < 5)
			{
				throw "-!!!- œŒœ–Œ¡”…“≈ «¿ÕŒ¬Œ. ÀŒ√»Õ ƒŒÀ∆≈Õ ¡€“‹ Õ≈  Œ–Œ◊≈ 5 —»Ã¬ŒÀŒ¬ -!!!-";
			}
			else
			{
				for (int i = 0; i < vectorUser.size(); i++)
				{
					if (username == vectorUser.at(i)->GetUsername())
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


std::string Vectors::CheckInputPassword()
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

std::string Vectors::FindPassword()
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
			password = CheckInputPassword();
			std::string hashed_password = HashPassword(password);

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

std::string Vectors::HashPassword(const std::string& password)
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

int Vectors::CountLengthFile(std::string nameFile)
{
	int counter = 0;
	std::string buf_string;
	std::ifstream fin(nameFile);
	while (getline(fin, buf_string))
	{
		counter++;
	}
	fin.close();
	return counter;
}

void Vectors::GetVectorUsers()
{
	int count = CountLengthFile("users.txt");
	for (int i = 0; i < count; i++)
		this->vector_user.push_back(std::make_shared<User>());
	std::ifstream file("users.txt", std::ios::in);
	if (!file.is_open())
	{
		Menu::FileNotOpened();
	}

	if (!vector_user.size())
	{
		std::shared_ptr<User> user = std::make_shared<User>();
		user->SetRole(1);
		user->SetAccess(1);
		user->SetUsername("admin");
		user->SetPassword(Vectors::HashPassword("12345"));
		user->SetSurname("Gutnik");
		user->SetName("Elina");
		user->SetOtch("Andreevna");
		this->vector_user.push_back(user);
	}
	else
	{
		for (auto& element : this->vector_user)
			element->GetFromFile(file);
	}
	file.close();
}

void Vectors::GetVectorEmployees()
{
	std::ifstream file("employees.txt", std::ios::in);

	if (!file.is_open())
	{
		Menu::FileNotOpened();
	}

	std::string surname, name, otch, month, hourly_rate;
	double salry, hours, average_salary;
	int id, amount_months;
	while (true)
	{
		if (!(file >> surname >> name >> otch >> id >> hourly_rate >> average_salary >> amount_months))
			break;
		std::shared_ptr<Employee> emp = std::make_shared<Employee>();
		std::vector<double> salary;
		std::vector<std::pair<std::string, double>> hours_worked;
		emp->SetSurname(surname);
		emp->SetName(name);
		emp->SetOtch(otch);
		emp->SetId(id);
		emp->SetHourlyRate(hourly_rate);
		emp->SetAverageSalary(average_salary);
		emp->SetAmountMonths(amount_months);

		for (int i = 0; i < amount_months; i++)
		{
			file >> salry >> month >> hours;
			salary.push_back(salry);
			hours_worked.emplace_back(month, hours);
		}
		emp->SetSalary(salary);
		emp->SetHoursWorkedForMonth(hours_worked);
		this->vector_employee.push_back(emp);
	}
	file.close();
}

void Vectors::GetVectorDepartment()
{
	std::ifstream fin("department.txt", std::ios::in);
	if (!fin.is_open())
	{
		Menu::FileNotOpened();
	}

	std::string title, surname, name, otch, hourly_rate;
	int number_projects, number_employees, id;
	while (true)
	{
		if (!(fin >> title >> number_projects >> number_employees))
			break;
		std::shared_ptr<Department> dep = std::make_shared<Department>();
		std::vector<std::shared_ptr<Employee>> employee;
		dep->SetTitle(title);
		dep->SetNumberProjects(number_projects);
		dep->SetNumberEmployees(number_employees);

		for (int i = 0; i < number_employees; i++)
		{
			fin >> surname >> name >> otch >> id >> hourly_rate;
			std::shared_ptr<Employee> emp = std::make_shared<Employee>();
			emp->SetSurname(surname);
			emp->SetName(name);
			emp->SetOtch(otch);
			emp->SetId(id);
			emp->SetHourlyRate(hourly_rate);
			employee.push_back(emp);
		}
		dep->SetEmployees(employee);
		this->vector_department.push_back(dep);
	}
	fin.close();
}

void Vectors::AddAccountInFile(std::vector<std::shared_ptr<User>> vector_user)
{
	std::ofstream file("users.txt", std::ios::out);
	if (!file.is_open())
	{
		Menu::FileNotOpened();
	}
	for (auto& element : vector_user)
		file << element->GetUsername() << "\t" << element->GetPassword() << "\t" <<
		element->GetRole() << "\t" << element->GetAccess() << "\t" << element->GetSurname() << 
		"\t" << element->GetName() << "\t" << element->GetOtch() << "\t" << std:: endl;
	file.close();
}

std::string Vectors::SingIn(std::vector<std::shared_ptr<User>>& vector_user)
{
	system("cls");
	Console::GoToXY(50, 12);
	std::cout << "¬¬≈ƒ»“≈ ÀŒ√»Õ";
	Console::GoToXY(53, 13);
	std::string username = CheckInputUsername();
	system("cls"); 
	Console::GoToXY(50, 12);
	std::cout << "¬¬≈ƒ»“≈ œ¿–ŒÀ‹";
	Console::GoToXY(54, 13);
	std::string password = FindPassword();
	system("cls");

	for (int i = 0; i < vector_user.size(); i++)
		if (username == vector_user.at(i)->GetUsername() && password == vector_user.at(i)->GetPassword())
		{
			if (!vector_user.at(i)->GetAccess())
			{
				system("cls");
				Console::GoToXY(42, 12);
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "-!!!- ”◊≈“Õ¿ﬂ «¿œ»—‹ «¿¡ÀŒ »–Œ¬¿Õ¿ -!!!-";
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				char ch = _getch();
				return "null";
			}
			else return vector_user.at(i)->GetUsername();
		}
	system("cls");
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- “¿ Œ… ”◊≈“ÕŒ… «¿œ»—» Õ≈ —”Ÿ≈—“¬”≈“ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return "NULL";
}

void Vectors::SingUp(int role, std::vector<std::shared_ptr<User>>& vector_user, Vectors& vect)
{
	std::shared_ptr<User> user = std::make_shared<User>();
	user->SetRole(role);
	user->SetAccess(1);
	system("cls");

	user->SetUsername(Vectors::FindUsername(vector_user));
	user->SetPassword(Vectors::FindPassword());

	user->SetFullName();

	if (Menu::confirmOrNot())
		vector_user.push_back(user);

	vect.AddAccountInFile(vector_user);
}


void Vectors::AddEmployeeInFile(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	std::ofstream fout("employees.txt", std::ios_base::trunc);
	if (!fout.is_open())
	{
		Menu::FileNotOpened();
	}
	for (auto& element : vector_employee)
	{
		fout << element->GetSurname() << "\t" << element->GetName() << "\t" << element->GetOtch() <<
			"\t" << element->GetId() << "\t" << element->GetHourlyRate() << "\t" << element->GetAverageSalary() <<
			"\t" << element->GetAmountMonths();
		for (int j = 0; j < element->GetAmountMonths(); j++)
		{
			fout << "\t" << element->GetSalary().at(j)
				<< "\t" << element->GetHoursWorkedForMonth().at(j).first
				<< "\t" << element->GetHoursWorkedForMonth().at(j).second;
		}
		fout << "\n";
	}
	fout.close();
}

void Vectors::AddDepartmentInFile(std::vector<std::shared_ptr<Department>> vector_department)
{
	std::ofstream fout("department.txt", std::ios_base::trunc);
	if (!fout.is_open())
	{
		Menu::FileNotOpened();
	}
	for (auto& element : vector_department)
	{
		fout << "\n" << element->GetTitle() << "\t" << element->GetNumberProjects() << "\t" << element->GetNumberEmployees();
		for (int j = 0; j < element->GetEmployees().size(); j++)
		{
			fout << "\n\t" << element->GetEmployees().at(j)->GetSurname()
				<< "\t" << element->GetEmployees().at(j)->GetName()
				<< "\t" << element->GetEmployees().at(j)->GetOtch()
				<< "\t" << element->GetEmployees().at(j)->GetId()
				<< "\t" << element->GetEmployees().at(j)->GetHourlyRate();
		}
	}
	fout << "\n";
	fout.close();
}