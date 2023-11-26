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
	char ch = _getch();
}

void Employee::FindByName(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) Menu::EmptyDatabase();
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
		Department::ErrorFindEmployee();
	else
	{
		system("cls");
		DatabaseEmployee(vect_employee);
	}
}

void Employee::FindById(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) Menu::EmptyDatabase();
	std::vector<std::shared_ptr<Employee>> vect_employee;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	system("cls");
	Console::GoToXY(45, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ ";
	Console::GoToXY(55, 14);
	int id = Menu::CheckInt();
	for (int i = 0; i < vector_employee.size(); i++)
		if (empl->GetId() == vector_employee.at(i)->GetId())
		{
			flag = false;
			empl = vector_employee.at(i);
			vect_employee.push_back(empl);
		}
	if (flag)
		Department::ErrorFindEmployee();
	else
	{
		system("cls");
		DatabaseEmployee(vect_employee);
	}
}

void Employee::FindByHourlyRate(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	if (!vector_employee.size()) Menu::EmptyDatabase();
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
		Department::ErrorFindEmployee();
	else
	{
		system("cls");
		DatabaseEmployee(vect_employee);
	}
}

void Employee::ChooseSortWindow() 
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+-----------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                         |";
	Console::GoToXY(36, 10);
	std::cout << "|           ÂÛÁÅÐÈÒÅ ÑÎÐÒÈÐÎÂÊÓ           |";
	Console::GoToXY(36, 11);
	std::cout << "|                                         |";
	Console::GoToXY(36, 12);
	std::cout << "+-----------------------------------------+";
}

void Employee::EndSortWindow()
{
	system("cls");
	std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
	char ch = _getch();
	return;
}

void Employee::SortBySurname(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	std::string line[] = { "Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "    Âåðíóòüñÿ íàçàä" };
	while (true)
	{
		ChooseSortWindow();
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			sort(vector_employee.begin(), vector_employee.end(), SortBySurnameCompDown);
			EndSortWindow();
			DatabaseEmployee(vector_employee);
		case 1:
			sort(vector_employee.begin(), vector_employee.end(), SortBySurnameCompUp);
			EndSortWindow();
			DatabaseEmployee(vector_employee);
		case 2:
			return;
		}
	}
}

void Employee::SortByID(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	char ch;
	std::string line[] = { "Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "    Âåðíóòüñÿ íàçàä" };

	while (true)
	{
		ChooseSortWindow();
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			sort(vector_employee.begin(), vector_employee.end(), SortByIdCompDown);
			DatabaseEmployee(vector_employee);
			EndSortWindow();
		case 1:
			sort(vector_employee.begin(), vector_employee.end(), SortByIdCompUp);
			DatabaseEmployee(vector_employee);
			EndSortWindow();
		case 2:
			return;
		}
	}
}

void Employee::SortByHourlyRate(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	char ch;
	std::string line[] = { "Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "    Âåðíóòüñÿ íàçàä" };

	while (true)
	{
		ChooseSortWindow();
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			sort(vector_employee.begin(), vector_employee.end(), SortByHourlyRatCompDown);
			DatabaseEmployee(vector_employee);
			EndSortWindow();
		case 1:
			sort(vector_employee.begin(), vector_employee.end(), SortByHourlyRatCompUp);
			DatabaseEmployee(vector_employee);
			EndSortWindow();
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
	if (!vector_employee.size()) Menu::EmptyDatabase();

	std::string date;
	bool flag_1;
	while (true)
	{
		int flag = 0;
		flag_1 = true;
		system("cls");
		int number_employee = FindEmployee(vector_employee);
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
				std::cout << "| " << date << " | ÇÀÐÏËÀÒÀ: " << std::setw(18) << std::left << 
					vector_employee.at(number_employee - 1)->GetSalary().at(i) << "$ |";
				Console::GoToXY(40, 15);
				std::cout << "+----------------------------------------+";
				ch = _getch();
				flag++;
				system("cls");
				break;
			}
		}

		if (flag == 0)
		{
			system("cls");
			Console::GoToXY(15, 14);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- ÒÀÊÎÉ ÄÀÒÛ Â ÁÀÇÅ ÄÀÍÍÛÕ ÍÅ ÑÓÙÅÑÒÂÓÅÒ, ËÈÁÎ ÆÅ ÍÅÂÅÐÍÛÉ ÂÂÎÄ ÄÀÒÛ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
			system("cls");
		}

		system("cls");
		Console::GoToXY(35, 12);
		std::cout << "ÆÅËÀÅÒÅ ÏÐÎÄÎËÆÈÒÜ ÏÎÈÑÊ ÇÀÐÏËÀÒÛ ÏÎ ÌÅÑßÖÀÌ?";

		std::string line[] = { "   Äà", "Íåò, âûéòè" };

		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			flag_1 = false;
			break;
		case 1:
			return;
		case 2:
			return;
		}
	}
}

int Employee::FindEmployee(std::vector<std::shared_ptr<Employee>> vector_employee)
{
	char ch;
	while (true)
	{
		DatabaseEmployee(vector_employee);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ" << std::endl;
		int number_employee = Menu::CheckInt();
		if (number_employee <= 0 || unsigned(number_employee) > vector_employee.size())
			Department::ErrorFindEmployee();
		else
			return number_employee;
	}
}

void Employee::ChangeSurname(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string surname;
	char ch;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÓÞ ÔÀÌÈËÈÞ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	surname = Menu::CheckString();
	vector_employee.at(number)->SetSurname(surname);
	Vectors::AddEmployeeInFile(vector_employee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::ChangeName(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string name;
	char ch;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÈÌß ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	name = Menu::CheckString();;
	vector_employee.at(number)->SetName(name);
	Vectors::AddEmployeeInFile(vector_employee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::ChangeOtch(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	std::string otch;
	char ch;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÎÒ×ÅÑÒÂÎ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	otch = Menu::CheckString();;
	vector_employee.at(number)->SetOtch(otch);
	Vectors::AddEmployeeInFile(vector_employee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::ChangeId(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	char ch;
	system("cls");
	Console::GoToXY(35, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(54, 12);
	int id = Menu::CheckInt();
	vector_employee.at(number)->SetId(id);
	Vectors::AddEmployeeInFile(vector_employee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::ChangeHourlyRate(std::vector<std::shared_ptr<Employee>>& vector_employee, int number)
{
	char ch;
	std::string hourly_rate;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	hourly_rate = Menu::CheckDouble();
	vector_employee.at(number)->SetHourlyRate(hourly_rate);
	Vectors::AddEmployeeInFile(vector_employee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::DeleteDatabase(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	char ch;
	system("cls");
	std::ofstream fout("employees.txt", std::ios::out);

	if (!vector_employee.size()) Menu::EmptyDatabase();

	std::string line[] = { "Äà, óäàëèòü", "    Âûéòè" };

	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÏÎÄÒÂÅÐÄÈÒÅ, ×ÒÎ ÂÛ ÕÎÒÈÒÅ ÓÄÀËÈÒÜ ÂÑÞ ÁÀÇÓ ÄÀÍÍÛÕ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (Menu::ChoiceKeyboard(line, (int)size(line)))
	{
	case 0:
		vector_employee.clear();
		fout << "";
		fout.close();
		system("cls");
		Console::GoToXY(20, 11);
		std::cout << "+----------------------------------------------------+";
		Console::GoToXY(20, 12);
		std::cout << "|                                                    |";
		Console::GoToXY(20, 13);
		std::cout << "|       ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÓÑÏÅØÍÎ ÓÄÀËÅÍÀ       |";
		Console::GoToXY(20, 14);
		std::cout << "|                                                    |";
		Console::GoToXY(20, 15);
		std::cout << "+----------------------------------------------------+";
		ch = _getch();
		return;
	case 1:
		return;
	}
}

void Employee::AddEmployeeDatabase(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	system("cls");
	std::shared_ptr<Employee> copy = std::make_shared<Employee>();
	std::vector<std::pair<std::string, double>> hours_worked;
	std::vector<double> salary{};
	bool flag = true, flag_1 = true;
	char ch;
	int month, year, amount = 0;
	double hours;
	std::string time;

	Console::GoToXY(25, 6);
	std::cout << "+--------------------------------------------------------+";
	Console::GoToXY(25, 7);
	std::cout << "|                                                        |";
	Console::GoToXY(25, 8);
	std::cout << "|     ÄÎÁÀÂËÅÍÈÅ ÐÀÁÎÒÍÈÊÀ Â ÁÀÇÓ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß     |";
	Console::GoToXY(25, 9);
	std::cout << "|                                                        |";
	Console::GoToXY(25, 10);
	std::cout << "+--------------------------------------------------------+";

	copy->SetFullName();

	system("cls");
	Console::GoToXY(25, 6);
	std::cout << "+--------------------------------------------------------+";
	Console::GoToXY(25, 7);
	std::cout << "|                                                        |";
	Console::GoToXY(25, 8);
	std::cout << "|     ÄÎÁÀÂËÅÍÈÅ ÐÀÁÎÒÍÈÊÀ Â ÁÀÇÓ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß     |";
	Console::GoToXY(25, 9);
	std::cout << "|                                                        |";
	Console::GoToXY(25, 10);
	std::cout << "+--------------------------------------------------------+";

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

	for (int j = 0; j < 12 && flag_1 == true; j++)
	{
		bool flag = true;
		do
		{
			system("cls");
			Console::GoToXY(25, 6);
			std::cout << "+--------------------------------------------------------+";
			Console::GoToXY(25, 7);
			std::cout << "|                                                        |";
			Console::GoToXY(25, 8);
			std::cout << "|     ÄÎÁÀÂËÅÍÈÅ ÐÀÁÎÒÍÈÊÀ Â ÁÀÇÓ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß     |";
			Console::GoToXY(25, 9);
			std::cout << "|                                                        |";
			Console::GoToXY(25, 10);
			std::cout << "+--------------------------------------------------------+";
			Console::GoToXY(45, 12);
			std::cout << "ÂÂÅÄÈÒÅ ×ÈÑËÎ ÌÅÑßÖÀ ";
			Console::GoToXY(50, 13);
			month = Menu::CheckInt();
			if (month != 1 && month != 2 && month != 3 && month != 4 && month != 5 && month != 6 && month != 7 &&
				month != 8 && month != 9 && month != 10 && month != 11 && month != 12)
			{
				system("cls");
				Console::GoToXY(40, 12);
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "-!!!- ÌÅÑßÖ ÂÂÅÄÅÍ ÍÅÂÅÐÍÎ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				ch = _getch();
			}
		} while (month != 1 && month != 2 && month != 3 && month != 4 && month != 5 && month != 6 && month != 7 &&
			month != 8 && month != 9 && month != 10 && month != 11 && month != 12);

		do
		{
			system("cls");
			Console::GoToXY(25, 6);
			std::cout << "+--------------------------------------------------------+";
			Console::GoToXY(25, 7);
			std::cout << "|                                                        |";
			Console::GoToXY(25, 8);
			std::cout << "|     ÄÎÁÀÂËÅÍÈÅ ÐÀÁÎÒÍÈÊÀ Â ÁÀÇÓ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß     |";
			Console::GoToXY(25, 9);
			std::cout << "|                                                        |";
			Console::GoToXY(25, 10);
			std::cout << "+--------------------------------------------------------+";
			Console::GoToXY(45, 12);
			std::cout << "ÂÂÅÄÈÒÅ ÃÎÄ ";
			Console::GoToXY(50, 13);
			year = Menu::CheckInt();
			if (year != 2023 && year != 2022 && year != 2021 && year != 2020 && year != 2019
				&& year != 2018 && year != 2017 && year != 2016)
			{
				system("cls");
				Console::GoToXY(40, 12);
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "-!!!- ÃÎÄ ÂÂÅÄÅÍ ÍÅÂÅÐÍÎ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				Console::GoToXY(35, 13);
				std::cout << "[ðàíüøå 2016 ãîäà íåâîçìîæíî çàïèñàòü â áàçó äàííûõ]";
				ch = _getch();
			}
		} while (year != 2023 && year != 2022 && year != 2021 && year != 2020 && year != 2019
			&& year != 2018 && year != 2017 && year != 2016);

		time = std::to_string(month) + "." + std::to_string(year);

		system("cls");
		Console::GoToXY(25, 6);
		std::cout << "+--------------------------------------------------------+";
		Console::GoToXY(25, 7);
		std::cout << "|                                                        |";
		Console::GoToXY(25, 8);
		std::cout << "|     ÄÎÁÀÂËÅÍÈÅ ÐÀÁÎÒÍÈÊÀ Â ÁÀÇÓ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß     |";
		Console::GoToXY(25, 9);
		std::cout << "|                                                        |";
		Console::GoToXY(25, 10);
		std::cout << "+--------------------------------------------------------+";
		Console::GoToXY(30, 12);
		std::cout << "ÂÂÅÄÈÒÅ ÊÎË-ÂÎ ÎÒÐÀÁÎÒÀÍÍÛÕ ×ÀÑÎÂ ÇÀ ÝÒÎÒ ÌÅÑßÖ";
		Console::GoToXY(53, 13);
		hours = Menu::CheckInt();

		salary.push_back(CalculateSalary(hours, copy->GetHourlyRate()));
		copy->SetSalary(salary);
		hours_worked.push_back(make_pair(time, hours));
		copy->SetHoursWorkedForMonth(hours_worked);

		amount++;
		copy->SetAmountMonths(amount);

		system("cls");
		Console::GoToXY(25, 6);
		std::cout << "+--------------------------------------------------------+";
		Console::GoToXY(25, 7);
		std::cout << "|                                                        |";
		Console::GoToXY(25, 8);
		std::cout << "|     ÄÎÁÀÂËÅÍÈÅ ÐÀÁÎÒÍÈÊÀ Â ÁÀÇÓ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß     |";
		Console::GoToXY(25, 9);
		std::cout << "|                                                        |";
		Console::GoToXY(25, 10);
		std::cout << "+--------------------------------------------------------+";
		Console::GoToXY(28, 12);
		std::cout << "ÆÅËÀÅÒÅ ÏÐÎÄÎËÆÈÒÜ ÇÀÏÎËÍßÒÜ ÊÎË-ÂÎ ÎÒÐÀÁÎÒÀÍÍÛÕ ×ÀÑÎÂ ÏÎ ÌÅÑßÖÀÌ?";
		std::string line[] = { " Äà", "Íåò" };


		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			if (j >= 11)
			{
				system("cls");
				Console::GoToXY(25, 12);
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << "-!!!- ÌÎÆÍÎ ÂÂÎÄÈÒÜ ÊÎË-ÂÎ ÎÒÐÀÁÎÒÀÍÍÛÕ ×ÀÑÎÂ ÒÎËÜÊÎ ÇÀ 12 ÌÅÑßÖÅÂ -!!!-";
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				ch = _getch();
				flag = false;
				flag_1 = false;
				break;
			}
			else if (j < 11)
			{
				flag = false;
				break;
			}
		case 1:
			flag = false;
			flag_1 = false;
			break;

		}
	}

	double avarage_salary = CalculateAverageSalary(copy->GetSalary());
	copy->SetAverageSalary(avarage_salary);

	vector_employee.push_back(copy);
	Vectors::AddEmployeeInFile(vector_employee);

	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	system("cls");

	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       ÍÎÂÛÉ ÐÀÁÎÒÍÈÊ ÓÑÏÅØÍÎ ÄÎÁÀÂËÅÍ      |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	ch = _getch();
}

void Employee::DeleteEmployee(std::vector<std::shared_ptr<Employee>>& vector_employee)
{
	char  ch;
	if (!vector_employee.size()) Menu::EmptyDatabase();

	system("cls");
	int number_employee = FindEmployee(vector_employee);
	system("cls");
	Console::GoToXY(30, 12);
	std::cout << "ÂÛ ÒÎ×ÍÎ ÆÅËÀÅÒÅ ÓÄÀËÈÒÜ ÐÀÁÎÒÍÈÊÀ ÈÇ ÁÀÇÛ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß?";

	std::string line[] = { "Äà, óäàëèòü", "  Âûéòè" };

	switch (Menu::ChoiceKeyboard(line, (int)size(line)))
	{
	case 0:
		if (number_employee > 0 && number_employee <= vector_employee.size()) {
			if (number_employee == vector_employee.size())
				vector_employee.pop_back();
			else
				vector_employee.erase(vector_employee.begin() + (number_employee - 1));
			Vectors::AddEmployeeInFile(vector_employee);

			system("cls");
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			Console::GoToXY(35, 11);
			std::cout << "+-----------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                               |";
			Console::GoToXY(35, 13);
			std::cout << "|       ÄÀÍÍÛÅ Î ÐÀÁÎÒÍÈÊÅ ÓÑÏÅØÍÎ ÓÄÀËÅÍÛ      |";
			Console::GoToXY(35, 14);
			std::cout << "|                                               |";
			Console::GoToXY(35, 15);
			std::cout << "+-----------------------------------------------+";
			ch = _getch();
			return;
		}
	case 1:
		return;
	}
}

void Employee::DatabaseForUser(std::vector<std::shared_ptr<User>> vector_user, 
	std::vector<std::shared_ptr<Employee>> vector_employee, std::string  username)
{
	char ch;
	for (int i = 0; i < vector_user.size(); i++)
	{
		if (username == vector_user.at(i)->GetUsername() &&
			vector_user.at(i)->GetSurname() == vector_employee.at(i)->GetSurname() &&
			vector_user.at(i)->GetName() == vector_employee.at(i)->GetName() &&
			vector_user.at(i)->GetOtch() == vector_employee.at(i)->GetOtch())
		{
			std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
			std::cout << "|                     ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÏÐÅÄÏÐÈßÒÈß                      |" << std::endl;
			std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
			std::cout << "|            ÔÈÎ ðàáîòíèêà              | Òàáåëüíûé | Ïî÷àñîâîé |   Ñðåäíÿÿ   |" << std::endl;
			std::cout << "|                                       |   íîìåð   |   òàðèô   |   çàðïëàòà  |" << std::endl;
			std::cout << "+-----------------------------------------------------------------------------+";

			std::cout << "\n| " << std::setw(12) << std::left << vector_employee.at(i)->GetSurname()
				<< std::setw(12) << std::left << vector_employee.at(i)->GetName()
				<< std::setw(14) << std::left << vector_employee.at(i)->GetOtch()
				<< "| " << std::setw(10) << std::left << vector_employee.at(i)->GetId()
				<< "| " << std::setw(7) << std::left << vector_employee.at(i)->GetHourlyRate()
				<< "$  | " << std::setw(9) << std::left << vector_employee.at(i)->GetAverageSalary() << "$  |";
			std::cout << std::endl << "+-----------------------------------------------------------------------------+" << std::endl;

			std::cout << std::endl << "--- ÌÅÑßÖ --- ÇÀÐÏËÀÒÀ ---" << std::endl;
			int amount = vector_employee.at(i)->GetAmountMonths();
			vector_employee.at(i)->GetHoursWorkedForMonth().resize(amount - 1);
			vector_employee.at(i)->GetSalary().resize(amount - 1);
			for (int j = 0; j < amount - 1; j++)
			{
				std::cout << "   " << vector_employee.at(i)->GetHoursWorkedForMonth().at(j).first << "     " <<
					vector_employee.at(i)->GetSalary().at(j) << std::endl;;
			}
			ch = _getch();
			return;
		}
	}
	system("cls");
	Console::GoToXY(35, 13);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÂÛ ÍÅ ÄÎÁÀÂËÅÍÛ Â ÁÀÇÓ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}