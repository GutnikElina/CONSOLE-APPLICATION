#include "menu.h"

double Employee::CalculateSalary(double hours, std::string hourly_rate)
{
	double salary = 0;
	double rate = stod(hourly_rate);
	salary = hours * rate;
	if (hours > 144)
	{
		salary += (hours - 144) * rate;
	}
	salary -= salary * 0.12;
	return salary;
}

double Employee::CalculateAverageSalary(std::vector<double> salary)
{
	double average_salary = 0;
	double sum = 0;
	for (int i = 0; i < (int)salary.size(); i++)
		sum += salary.at(i);
	average_salary = sum / (salary.size());
	return average_salary;
}

void Employee::GetFromFile(std::istream& in)
{
	double salary, hours;
	std::string month;
	FIO::GetFromFile(in);
	in >> this->id >> this->hourly_rate >> this->average_salary >> this->amount_months;
	this->hours_worked_for_month.resize(this->amount_months);
	this->salary.resize(this->amount_months);
	while (in >> salary >> month >> hours)
	{
		this->salary.push_back(salary);
		this->hours_worked_for_month.emplace_back(month, hours);
	}
}

void Employee::DatabaseEmployee(std::vector<std::shared_ptr<Employee>> employee)
{
	system("cls");
	std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                         ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÏÐÅÄÏÐÈßÒÈß                        |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
	std::cout << "|  ¹  |            ÔÈÎ ðàáîòíèêà              | Òàáåëüíûé | Ïî÷àñîâîé |   Ñðåäíÿÿ   |" << std::endl;
	std::cout << "|     |                                       |   íîìåð   |   òàðèô   |   çàðïëàòà  |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------------+";
	for (int i = 0; i < employee.size(); i++)
	{
		std::cout << "\n| " << std::setw(4) << std::left << i + 1
			<< "| " << std::setw(12) << std::left << employee.at(i)->GetSurname()
			<< std::setw(12) << std::left << employee.at(i)->GetName()
			<< std::setw(14) << std::left << employee.at(i)->GetOtch()
			<< "| " << std::setw(10) << std::left << employee.at(i)->GetId()
			<< "| " << std::setw(7) << std::left << employee.at(i)->GetHourlyRate()
			<< "$  | " << std::setw(9) << std::left << employee.at(i)->GetAverageSalary() << "$  |";
		std::cout << std::endl << "+-----------------------------------------------------------------------------------+";
	}
}

void Employee::FindByName(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) { Messages::EmptyDatabase(); return; }
	std::vector<std::shared_ptr<Employee>> vect_employee;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	empl->SetFullName();
	for (int i = 0; i < vector_employee.size(); i++)
		if (empl->GetFullName() == vector_employee.at(i)->GetFullName())
		{
			flag = false;
			empl = vector_employee.at(i);
			vect_employee.push_back(empl);
		}
	if (flag)
		Messages::ErrorFindEmployee();
	else
	{
		system("cls");
		DatabaseEmployee(vect_employee);
		char ch = _getch();
	}
}

void Employee::FindById(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) { Messages::EmptyDatabase(); return; }
	std::vector<std::shared_ptr<Employee>> vect_employee;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	system("cls");
	Console::GoToXY(45, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ ";
	Console::GoToXY(58, 14);
	empl->SetId(Menu::CheckInt());
	for (int i = 0; i < vector_employee.size(); i++)
		if (empl->GetId() == vector_employee.at(i)->GetId())
		{
			flag = false;
			empl = vector_employee.at(i);
			vect_employee.push_back(empl);
		}
	if (flag)
		Messages::ErrorFindEmployee();
	else
	{
		system("cls");
		DatabaseEmployee(vect_employee);
		char ch = _getch();
	}
}

void Employee::FindByHourlyRate(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) { Messages::EmptyDatabase(); return; }
	std::vector<std::shared_ptr<Employee>> vect_employee;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	system("cls");
	Console::GoToXY(40, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(55, 14);
	std::string hourly_rate = Menu::CheckDouble();
	empl->SetHourlyRate(hourly_rate);
	for (int i = 0; i < vector_employee.size(); i++)
	{
		if (empl->GetHourlyRate() == vector_employee.at(i)->GetHourlyRate())
		{
			flag = false;
			empl = vector_employee.at(i);
			vect_employee.push_back(empl);
		}
	}
	if (flag)
		Messages::ErrorFindEmployee();
	else
	{
		system("cls");
		DatabaseEmployee(vect_employee);
		char ch = _getch();
	}
}

void Employee::SortBySurname(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	char ch;
	std::string line[] = { "  Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "     Âåðíóòüñÿ íàçàä" };
	while (true)
	{
		Messages::ChooseSortWindow();
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			sort(vector_employee.begin(), vector_employee.end(), SortBySurnameCompDown);
			Messages::EndSortWindow();
			DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 1:
			sort(vector_employee.begin(), vector_employee.end(), SortBySurnameCompUp);
			Messages::EndSortWindow();
			DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 2:
			return;
		}
	}
}

void Employee::SortByID(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	char ch;
	std::string line[] = { "  Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "     Âåðíóòüñÿ íàçàä" };
	while (true)
	{
		Messages::ChooseSortWindow();
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			sort(vector_employee.begin(), vector_employee.end(), SortByIdCompDown);
			Messages::EndSortWindow();
			DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 1:
			sort(vector_employee.begin(), vector_employee.end(), SortByIdCompUp);
			Messages::EndSortWindow();
			DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 2:
			return;
		}
	}
}

void Employee::SortByHourlyRate(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	char ch;
	std::string line[] = { "  Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "     Âåðíóòüñÿ íàçàä" };
	while (true)
	{
		Messages::ChooseSortWindow();
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			sort(vector_employee.begin(), vector_employee.end(), SortByHourlyRatCompDown);
			Messages::EndSortWindow();
			DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 1:
			sort(vector_employee.begin(), vector_employee.end(), SortByHourlyRatCompUp);
			Messages::EndSortWindow();
			DatabaseEmployee(vector_employee);
			ch = _getch();
			break;
		case 2:
			return;
		}
	}
}

bool Employee::SortBySurnameCompUp( std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->GetSurname() < second->GetSurname();
}

bool Employee::SortBySurnameCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->GetSurname() > second->GetSurname();
}

bool Employee::SortByIdCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->GetId() > second->GetId();
}

bool Employee::SortByIdCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->GetId() < second->GetId();
}

bool Employee::SortByHourlyRatCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->GetHourlyRate() > second->GetHourlyRate();
}

bool Employee::SortByHourlyRatCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->GetHourlyRate() < second->GetHourlyRate();
}

void Employee::SalaryData(std::vector<std::shared_ptr<Employee>> vector_employee) 
{
	char ch;
	std::string date;
	bool flag_1;
	if (vector_employee.empty()) { Messages::EmptyDatabase();	return; }

	while (true) 
	{
		flag_1 = true;
		int number_employee = FindEmployee(vector_employee);
		if (number_employee != -1)
		{
			system("cls");
			Console::GoToXY(40, 12);
			std::cout << "ÂÂÅÄÈÒÅ ÌÅÑßÖ ÇÀ ÊÎÒÎÐÛÉ ÕÎÒÈÒÅ ÓÇÍÀÒÜ ÇÀÐÏËÀÒÓ";
			Console::GoToXY(60, 13);
			int month = Menu::CheckInt();

			Console::GoToXY(40, 15);
			std::cout << "ÂÂÅÄÈÒÅ ÃÎÄ ÇÀ ÊÎÒÎÐÛÉ ÕÎÒÈÒÅ ÓÇÍÀÒÜ ÇÀÐÏËÀÒÓ";
			Console::GoToXY(60, 16);
			int year = Menu::CheckInt();

			date = std::to_string(month) + "." + std::to_string(year);

			for (int i = 0; i < vector_employee.at(number_employee - 1)->GetHoursWorkedForMonth().size(); i++)
			{
				if (date == vector_employee.at(number_employee - 1)->GetHoursWorkedForMonth().at(i).first)
				{
					system("cls");
					Console::GoToXY(40, 13);
					std::cout << "+----------------------------------------+";
					Console::GoToXY(40, 14);
					std::cout << "| " << date << " | ÇÀÐÏËÀÒÀ: " << std::setw(16) << std::left <<
						vector_employee.at(number_employee - 1)->GetSalary().at(i) << "$  |";
					Console::GoToXY(40, 15);
					std::cout << "+----------------------------------------+";
					ch = _getch();
					flag_1 = false;
					system("cls");
					break;
				}
			}

			if (flag_1)
				Messages::ErrorData();

			Console::GoToXY(35, 12);
			std::cout << "ÆÅËÀÅÒÅ ÏÐÎÄÎËÆÈÒÜ ÏÎÈÑÊ ÇÀÐÏËÀÒÛ ÏÎ ÌÅÑßÖÀÌ?";
			std::string line[] = { "           Äà", "       Íåò, âûéòè" };
			if (Menu::ChoiceKeyboard(line, static_cast<int>(std::size(line))) == 1)
				return;
		}
		else return;
	}
}

int Employee::FindEmployee(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	while (true)
	{
		system("cls");
		DatabaseEmployee(vector_employee);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ" << std::endl;
		int number_employee = Menu::CheckInt();
		if (number_employee <= 0 || number_employee > (int)vector_employee.size())
		{
			Messages::ErrorFindEmployee();
			return -1;
		}
		else
			return number_employee;
	}
}

void Employee::ChangeSurname(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string surname;
	system("cls");
	Console::GoToXY(40, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÓÞ ÔÀÌÈËÈÞ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 14);
	surname = Menu::CheckString();
	vector_employee.at(number)->SetSurname(surname);
	Vectors::AddEmployeeInFile(vector_employee);
	Messages::ChangingEmployeeData();
	return;
}

void Employee::ChangeName(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string name;
	system("cls");
	Console::GoToXY(40, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÈÌß ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 14);
	name = Menu::CheckString();;
	vector_employee.at(number)->SetName(name);
	Vectors::AddEmployeeInFile(vector_employee);
	Messages::ChangingEmployeeData();
	return;
}

void Employee::ChangeOtch(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string otch;
	system("cls");
	Console::GoToXY(40, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÎÒ×ÅÑÒÂÎ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 14);
	otch = Menu::CheckString();;
	vector_employee.at(number)->SetOtch(otch);
	Vectors::AddEmployeeInFile(vector_employee);
	Messages::ChangingEmployeeData();
	return;
}

void Employee::ChangeId(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	system("cls");
	Console::GoToXY(38, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 14);
	int id = Menu::CheckInt();
	vector_employee.at(number)->SetId(id);
	Vectors::AddEmployeeInFile(vector_employee);
	Messages::ChangingEmployeeData();
	return;
}

void Employee::ChangeHourlyRate(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string hourly_rate;
	system("cls");
	Console::GoToXY(38, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(55, 14);
	hourly_rate = Menu::CheckDouble();
	vector_employee.at(number)->SetHourlyRate(hourly_rate);
	Vectors::AddEmployeeInFile(vector_employee);
	Messages::ChangingEmployeeData();
	return;
}

void Employee::DeleteDatabase(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	if (!vector_employee.size()) { Messages::EmptyDatabase(); return; }

	Messages::ConfirmDeleting();
	if (Menu::continueOrNot())
	{
		vector_employee.clear();
		std::ofstream fout("employees.txt", std::ios::trunc);
		fout << "";
		fout.close();
		Messages::DeleteDBEmployeeWindow();
		return;
	}
	else return;
}

void Employee::AddEmployeeDatabase(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	std::shared_ptr<Employee> copy = std::make_shared<Employee>();
	std::vector<std::pair<std::string, double>> hours_worked;
	std::vector<double> salary{};
	int month, year, amount = 0;
	double hours;
	std::string time;
	bool flag_1 = true;

	system("cls");
	copy->SetFullName();
	system("cls");
	Console::GoToXY(45, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ";
	Console::GoToXY(50, 13);
	int id = Menu::CheckInt();
	copy->SetId(id);
	Console::GoToXY(45, 15);
	std::cout << "ÂÂÅÄÈÒÅ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ";
	Console::GoToXY(50, 16);
	std::string hourly_rate = Menu::CheckDouble();
	copy->SetHourlyRate(hourly_rate);

	while (flag_1)
	{
		do {
			system("cls");
			Console::GoToXY(45, 12);
			std::cout << "ÂÂÅÄÈÒÅ ×ÈÑËÎ ÌÅÑßÖÀ ";
			Console::GoToXY(52, 13);
			month = Menu::CheckInt();
			if (month < 1 || month > 12)
				Messages::ErrorMonth();
		} while (month < 1 || month > 12);

		do {
			system("cls");
			Console::GoToXY(50, 12);
			std::cout << "ÂÂÅÄÈÒÅ ÃÎÄ ";
			Console::GoToXY(54, 13);
			year = Menu::CheckInt();
			if (year < 2016 || year > 2023)
				Messages::ErrorYear();
		} while (year < 2016 || year > 2023);

		time = std::to_string(month) + "." + std::to_string(year);
		system("cls");
		Console::GoToXY(35, 12);
		std::cout << "ÂÂÅÄÈÒÅ ÊÎË-ÂÎ ÎÒÐÀÁÎÒÀÍÍÛÕ ×ÀÑÎÂ ÇÀ ÝÒÎÒ ÌÅÑßÖ";
		Console::GoToXY(53, 13);
		hours = Menu::CheckInt();

		salary.push_back(CalculateSalary(hours, copy->GetHourlyRate()));
		copy->SetSalary(salary);
		hours_worked.push_back(std::make_pair(time, hours));
		copy->SetHoursWorkedForMonth(hours_worked);

		amount++;
		copy->SetAmountMonths(amount);
		system("cls");
		Console::GoToXY(28, 12);
		std::cout << "ÆÅËÀÅÒÅ ÏÐÎÄÎËÆÈÒÜ ÇÀÏÎËÍßÒÜ ÊÎË-ÂÎ ÎÒÐÀÁÎÒÀÍÍÛÕ ×ÀÑÎÂ ÏÎ ÌÅÑßÖÀÌ?";
		std::string line[] = { "             Äà", "             Íåò" };

		switch (Menu::ChoiceKeyboard(line, static_cast<int>(std::size(line))))
		{
		case 0:
			if (amount >= 12)
			{
				Messages::ErrorInputHours();
				flag_1 = false;
				break;
			}
			break;
		case 1:
			flag_1 = false;
			break;
		}
		double avarage_salary = CalculateAverageSalary(copy->GetSalary());
		copy->SetAverageSalary(avarage_salary);
		vector_employee.push_back(copy);
	}
	Vectors::AddEmployeeInFile(vector_employee);
	Messages::SuccessAddEmployee();
}


void Employee::DeleteEmployee(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	if (!vector_employee.size()) { Messages::EmptyDatabase(); return; }

	int number_employee = FindEmployee(vector_employee);
	if (number_employee != -1)
	{
		system("cls");
		Console::GoToXY(30, 12);
		std::cout << "ÂÛ ÒÎ×ÍÎ ÆÅËÀÅÒÅ ÓÄÀËÈÒÜ ÐÀÁÎÒÍÈÊÀ ÈÇ ÁÀÇÛ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß?";

		std::string line[] = { "      Äà, óäàëèòü", "        Âûéòè" };
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			if (number_employee > 0 && number_employee <= vector_employee.size()) {
				if (number_employee == vector_employee.size())
					vector_employee.pop_back();
				else
					vector_employee.erase(vector_employee.begin() + (number_employee - 1));
				Vectors::AddEmployeeInFile(vector_employee);
				Messages::SuccessDeleteEmployee();
				return;
			}
		case 1:
			return;
		}
	}
	else return;
}

void Employee::DatabaseForUser(std::vector<std::shared_ptr<User>> vector_user, 
	std::vector<std::shared_ptr<Employee>> vector_employee, std::string  username)
{
	char ch;
	for (int i = 0; i < vector_user.size(); i++)
	{
		for (int j = 0; j < vector_employee.size(); j++)
		{
			if (username == vector_user.at(i)->GetUsername() &&
				vector_user.at(i)->GetSurname() == vector_employee.at(j)->GetSurname() &&
				vector_user.at(i)->GetName() == vector_employee.at(j)->GetName() &&
				vector_user.at(i)->GetOtch() == vector_employee.at(j)->GetOtch())
			{
				std::cout << "+------------------------------------------------2-----------------------------+" << std::endl;
				std::cout << "|                     ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÏÐÅÄÏÐÈßÒÈß                      |" << std::endl;
				std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
				std::cout << "|            ÔÈÎ ðàáîòíèêà              | Òàáåëüíûé | Ïî÷àñîâîé |   Ñðåäíÿÿ   |" << std::endl;
				std::cout << "|                                       |   íîìåð   |   òàðèô   |   çàðïëàòà  |" << std::endl;
				std::cout << "+-----------------------------------------------------------------------------+";

				std::cout << "\n| " << std::setw(12) << std::left << vector_employee.at(j)->GetSurname()
					<< std::setw(12) << std::left << vector_employee.at(j)->GetName()
					<< std::setw(14) << std::left << vector_employee.at(j)->GetOtch()
					<< "| " << std::setw(10) << std::left << vector_employee.at(j)->GetId()
					<< "| " << std::setw(7) << std::left << vector_employee.at(j)->GetHourlyRate()
					<< "$  | " << std::setw(9) << std::left << vector_employee.at(j)->GetAverageSalary() << "$  |";
				std::cout << std::endl << "+-----------------------------------------------------------------------------+" << std::endl;

				std::cout << std::endl << "--- ÌÅÑßÖ --- ÇÀÐÏËÀÒÀ ---" << std::endl;
				int amount = vector_employee.at(j)->GetAmountMonths();
				vector_employee.at(j)->GetHoursWorkedForMonth().resize(amount - 1);
				vector_employee.at(j)->GetSalary().resize(amount - 1);
				for (int k = 0; k < amount - 1; k++)
				{
					std::cout << "   " << vector_employee.at(j)->GetHoursWorkedForMonth().at(k).first << "     " <<
						vector_employee.at(j)->GetSalary().at(k) << std::endl;;
				}
				ch = _getch();
				return;
			}
		}
	}
	Messages::ErrorFindYou();
}