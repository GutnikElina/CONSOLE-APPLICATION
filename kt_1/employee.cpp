#include "menu.h"

double Employee::calculateSalary(double hours, std::string hourlyRate)
{
	double salary = 0;
	double rate = stod(hourlyRate);
	salary = hours * rate;

	if (hours > 144)
	{
		salary += (hours - 144) * rate;
	}
	salary -= salary * 0.12;
	return salary;
}

double Employee::calculateAverageSalary(std::vector<double> s)
{
	double averageSalary = 0;
	double sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sum += s.at(i);
	}

	averageSalary = sum / (s.size());
	return averageSalary;
}

void Employee::getFromFile(std::istream& in)
{
	double sal, hours;
	std::string month;
	FIO::getFromFile(in);
	in >> this->id >> this->hourlyRate >> this->averageSalary >> this->amountOfMonths;
	this->hoursWorkedForMonth.resize(this->amountOfMonths);
	this->salary.resize(this->amountOfMonths);

	while (in >> sal >> month >> hours)
	{
		this->salary.push_back(sal);
		this->hoursWorkedForMonth.emplace_back(month, hours);
	}
}

void Employee::database(std::vector<std::shared_ptr<Employee>> employee)
{
	std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                         ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÏÐÅÄÏÐÈßÒÈß                        |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
	std::cout << "|  ¹  |            ÔÈÎ ðàáîòíèêà              | Òàáåëüíûé | Ïî÷àñîâîé |   Ñðåäíÿÿ   |" << std::endl;
	std::cout << "|     |                                       |   íîìåð   |   òàðèô   |   çàðïëàòà  |" << std::endl;
	std::cout << "+-----------------------------------------------------------------------------------+";

	for (int i = 0; i < employee.size(); i++)
	{
		std::cout << "\n| " << std::setw(4) << std::left << i + 1
			<< "| " << std::setw(12) << std::left << employee.at(i)->getSurname()
			<< std::setw(12) << std::left << employee.at(i)->getName()
			<< std::setw(14) << std::left << employee.at(i)->getOtch()
			<< "| " << std::setw(10) << std::left << employee.at(i)->getId()
			<< "| " << std::setw(7) << std::left << employee.at(i)->getHourlyRate()
			<< "$  | " << std::setw(9) << std::left << employee.at(i)->getAverageSalary() << "$  |";
		std::cout << std::endl << "+-----------------------------------------------------------------------------------+";
	}
}

void Employee::findByName(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::vector<std::shared_ptr<Employee>> vectEmp;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	
	empl->setFullName();

	for (int i = 0; i < vectorEmployee.size(); i++)
	{
		if (empl->getName() == vectorEmployee.at(i)->getName() &&
			empl->getSurname() == vectorEmployee.at(i)->getSurname() &&
			empl->getOtch() == vectorEmployee.at(i)->getOtch())
		{
			flag = false;
			empl = vectorEmployee.at(i);
			vectEmp.push_back(empl);
		}
	}

	if (flag)
	{
		Console::GoToXY(35, 18);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÂÂÅÄÅÍÍÛÉ ÐÀÁÎÒÍÈÊ ÍÅ ÍÀÉÄÅÍ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else
	{
		system("cls");
		database(vectEmp);
	}
	ch = _getch();
}

void Employee::findById(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::vector<std::shared_ptr<Employee>> vectEmp;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	system("cls");
	Console::GoToXY(45, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ ";
	Console::GoToXY(55, 14);
	int id = Menu::checkInt();

	empl->setId(id);

	for (int i = 0; i < vectorEmployee.size(); i++)
	{
		if (empl->getId() == vectorEmployee.at(i)->getId())
		{
			flag = false;
			empl = vectorEmployee.at(i);
			vectEmp.push_back(empl);
		}
	}

	if (flag)
	{
		Console::GoToXY(35, 16);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÂÂÅÄÅÍÍÛÉ ÐÀÁÎÒÍÈÊ ÍÅ ÍÀÉÄÅÍ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else
	{
		system("cls");
		database(vectEmp);
	}
	ch = _getch();
}

void Employee::findByHourlyRate(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::vector<std::shared_ptr<Employee>> vectEmp;
	std::shared_ptr<Employee> empl = std::make_shared<Employee>();
	bool flag = true;
	system("cls");
	Console::GoToXY(40, 12);
	std::cout << "ÂÂÅÄÈÒÅ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(55, 14);
	std::string hourlyRate = Menu::checkDouble();
	empl->setHourlyRate(hourlyRate);

	for (int i = 0; i < vectorEmployee.size(); i++)
	{
		if (empl->getHourlyRate() == vectorEmployee.at(i)->getHourlyRate())
		{
			flag = false;
			empl = vectorEmployee.at(i);
			vectEmp.push_back(empl);
		}
	}

	if (flag)
	{
		Console::GoToXY(35, 16);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÂÂÅÄÅÍÍÛÉ ÐÀÁÎÒÍÈÊ ÍÅ ÍÀÉÄÅÍ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else
	{
		system("cls");
		database(vectEmp);
	}
	ch = _getch();
}

void Employee::sortBySurname(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	system("cls");
	char ch;
	std::string line[] = { "Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "    Âåðíóòüñÿ íàçàä" };

	while (true)
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

		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			sort(vectorEmployee.begin(), vectorEmployee.end(), sortBySurnameCompDown);
			system("cls");
			database(vectorEmployee);
			std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
			ch = _getch();
			return;
			break;
		case 1:
			sort(vectorEmployee.begin(), vectorEmployee.end(), sortBySurnameCompUp);
			system("cls");
			database(vectorEmployee);
			std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
			ch = _getch();
			return;
			break;
		case 2:
			return;
		}
	}
}

void Employee::sortByID(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	system("cls");
	char ch;
	std::string line[] = { "Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "    Âåðíóòüñÿ íàçàä" };

	while (true)
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

		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			sort(vectorEmployee.begin(), vectorEmployee.end(), sortByIdCompDown);
			system("cls");
			database(vectorEmployee);
			std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
			ch = _getch();
			return;
			break;
		case 1:
			sort(vectorEmployee.begin(), vectorEmployee.end(), sortByIdCompUp);
			system("cls");
			database(vectorEmployee);
			std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
			ch = _getch();
			return;
			break;
		case 2:
			return;
		}
	}
}

void Employee::sortByHourlyRate(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	system("cls");
	char ch;
	bool flag = true;
	std::string line[] = { "Ñîðòèðîâêà ïî óáûâàíèþ", "Ñîðòèðîâêà ïî âîçðàñòàíèþ", "    Âåðíóòüñÿ íàçàä" };

	while (true)
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
		
		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			sort(vectorEmployee.begin(), vectorEmployee.end(), sortByHourlyRatCompDown);
			system("cls");
			database(vectorEmployee);
			std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
			ch = _getch();
			return;
			break;
		case 1:
			sort(vectorEmployee.begin(), vectorEmployee.end(), sortByHourlyRatCompUp);
			system("cls");
			database(vectorEmployee);
			std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
			ch = _getch();
			return;
			break;
		case 2:
			return;
		}
	}
}

bool Employee::sortBySurnameCompUp( std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->getSurname() < second->getSurname();
}

bool Employee::sortBySurnameCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->getSurname() > second->getSurname();
}

bool Employee::sortByIdCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->getId() > second->getId();
}

bool Employee::sortByIdCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->getId() < second->getId();
}

bool Employee::sortByHourlyRatCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->getHourlyRate() > second->getHourlyRate();
}

bool Employee::sortByHourlyRatCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second)
{
	return first->getHourlyRate() < second->getHourlyRate();
}

void Employee::salaryData(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(50, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::string date;
	bool flag_1;
	while (true)
	{
		int flag = 0;
		flag_1 = true;
		system("cls");
		int numberOfEmployee = findEmployee(vectorEmployee);
		system("cls");
		Console::GoToXY(40, 12);
		std::cout << "ÂÂÅÄÈÒÅ ÌÅÑßÖ ÇÀ ÊÎÒÎÐÛÉ ÕÎÒÈÒÅ ÓÇÍÀÒÜ ÇÀÐÏËÀÒÓ";
		Console::GoToXY(60, 13);
		int month = Menu::checkInt();

		Console::GoToXY(40, 15);
		std::cout << "ÂÂÅÄÈÒÅ ÃÎÄ ÇÀ ÊÎÒÎÐÛÉ ÕÎÒÈÒÅ ÓÇÍÀÒÜ ÇÀÐÏËÀÒÓ";
		Console::GoToXY(60, 16);
		int year = Menu::checkInt();

		date = std::to_string(month) + "." + std::to_string(year);

		for (int i = 0; i < vectorEmployee.at(numberOfEmployee - 1)->getHoursWorkedForMonth().size(); i++)
		{
			if (date == vectorEmployee.at(numberOfEmployee - 1)->getHoursWorkedForMonth().at(i).first)
			{
				system("cls");
				Console::GoToXY(40, 13);
				std::cout << "+----------------------------------------+";
				Console::GoToXY(40, 14);
				std::cout << "| " << date << " | ÇÀÐÏËÀÒÀ: " << std::setw(18) << std::left << vectorEmployee.at(numberOfEmployee - 1)->getSalary().at(i) << "$ |";
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

		switch (Menu::choiceKeyboard(line, size(line)))
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

int Employee::findEmployee(std::vector<std::shared_ptr<Employee>> vectorEmployee)
{
	char ch;
	while (true)
	{
		database(vectorEmployee);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ" << std::endl;
		int numberEmployee = Menu::checkInt();
		if (numberEmployee <= 0 || unsigned(numberEmployee) > vectorEmployee.size())
		{
			system("cls");
			Console::GoToXY(35, 14);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- ÒÀÊÎÃÎ ÍÎÌÅÐÀ ÐÀÁÎÒÍÈÊÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
			system("cls");
			continue;
		}
		else
			return numberEmployee;
	}
}

void Employee::changeSurname(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number)
{
	std::string surname;
	char ch;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÓÞ ÔÀÌÈËÈÞ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	surname = Menu::checkString();
	vectorEmployee.at(number)->setSurname(surname);
	Vectors::addEmployeeInFile(vectorEmployee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::changeName(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number)
{
	std::string name;
	char ch;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÈÌß ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	name = Menu::checkString();;
	vectorEmployee.at(number)->setName(name);
	Vectors::addEmployeeInFile(vectorEmployee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::changeOtch(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number)
{
	std::string otch;
	char ch;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÎÒ×ÅÑÒÂÎ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	otch = Menu::checkString();;
	vectorEmployee.at(number)->setOtch(otch);
	Vectors::addEmployeeInFile(vectorEmployee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::changeId(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number)
{
	char ch;
	system("cls");
	Console::GoToXY(35, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÒÀÁÅËÜÍÛÉ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(54, 12);
	int id = Menu::checkInt();
	vectorEmployee.at(number)->setId(id);
	Vectors::addEmployeeInFile(vectorEmployee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::changeHourlyRate(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number)
{
	char ch;
	std::string hourlyRate;
	system("cls");
	Console::GoToXY(45, 10);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÛÉ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ ÐÀÁÎÒÍÈÊÀ";
	Console::GoToXY(50, 12);
	hourlyRate = Menu::checkDouble();
	vectorEmployee.at(number)->setHourlyRate(hourlyRate);
	Vectors::addEmployeeInFile(vectorEmployee);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Employee::deleteDatabase(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	char ch;
	system("cls");
	std::ofstream fout("employees.txt", std::ios::out);

	if (!vectorEmployee.size())
	{
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	std::string line[] = { "Äà, óäàëèòü", "    Âûéòè" };

	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÏÎÄÒÂÅÐÄÈÒÅ, ×ÒÎ ÂÛ ÕÎÒÈÒÅ ÓÄÀËÈÒÜ ÂÑÞ ÁÀÇÓ ÄÀÍÍÛÕ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	switch (Menu::choiceKeyboard(line, size(line)))
	{
	case 0:
		vectorEmployee.clear();
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

void Employee::addEmployeeDatabase(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	system("cls");
	std::shared_ptr<Employee> copy = std::make_shared<Employee>();
	std::vector<std::pair<std::string, double>> hoursWorked;
	std::vector<double> slry{};
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

	copy->setFullName();

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
	int id = Menu::checkInt();
	copy->setId(id);
	Console::GoToXY(45, 15);
	std::cout << "ÂÂÅÄÈÒÅ ÏÎ×ÀÑÎÂÎÉ ÒÀÐÈÔ";
	Console::GoToXY(50, 16);
	std::string hourlyRate = Menu::checkDouble();
	copy->setHourlyRate(hourlyRate);

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
			month = Menu::checkInt();
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
			year = Menu::checkInt();
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
		hours = Menu::checkInt();

		slry.push_back(calculateSalary(hours, copy->getHourlyRate()));
		copy->setSalary(slry);
		hoursWorked.push_back(make_pair(time, hours));
		copy->setHoursWorkedForMonth(hoursWorked);

		amount++;
		copy->setAmountOfMonths(amount);

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


		switch (Menu::choiceKeyboard(line, size(line)))
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

	double av = calculateAverageSalary(copy->getSalary());
	copy->setAverageSalary(av);

	vectorEmployee.push_back(copy);
	Vectors::addEmployeeInFile(vectorEmployee);

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

void Employee::deleteEmployee(std::vector<std::shared_ptr<Employee>>& vectorEmployee)
{
	char  ch;
	if (!vectorEmployee.size())
	{
		system("cls");
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}
	system("cls");

	int numberEmployee = findEmployee(vectorEmployee);
	system("cls");
	Console::GoToXY(30, 12);
	std::cout << "ÂÛ ÒÎ×ÍÎ ÆÅËÀÅÒÅ ÓÄÀËÈÒÜ ÐÀÁÎÒÍÈÊÀ ÈÇ ÁÀÇÛ ÄÀÍÍÛÕ ÏÐÅÄÏÐÈßÒÈß?";

	std::string line[] = { "Äà, óäàëèòü", "  Âûéòè" };

	switch (Menu::choiceKeyboard(line, size(line)))
	{
	case 0:
		if (numberEmployee > 0 && numberEmployee <= vectorEmployee.size()) {
			if (numberEmployee == vectorEmployee.size())
				vectorEmployee.pop_back();
			else
				vectorEmployee.erase(vectorEmployee.begin() + (numberEmployee - 1));
			Vectors::addEmployeeInFile(vectorEmployee);

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

void Employee::databaseForUser(std::vector<std::shared_ptr<User>> vectorUser, std::vector<std::shared_ptr<Employee>> vectorEmployee, std::string  username)
{
	char ch;
	for (int i = 0; i < vectorUser.size(); i++)
	{
		if (username == vectorUser.at(i)->getUsername() && vectorUser.at(i)->getSurname() == vectorEmployee.at(i)->getSurname() &&
			vectorUser.at(i)->getName() == vectorEmployee.at(i)->getName() &&
			vectorUser.at(i)->getOtch() == vectorEmployee.at(i)->getOtch())
		{
			std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
			std::cout << "|                     ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÏÐÅÄÏÐÈßÒÈß                      |" << std::endl;
			std::cout << "+-----------------------------------------------------------------------------+" << std::endl;
			std::cout << "|            ÔÈÎ ðàáîòíèêà              | Òàáåëüíûé | Ïî÷àñîâîé |   Ñðåäíÿÿ   |" << std::endl;
			std::cout << "|                                       |   íîìåð   |   òàðèô   |   çàðïëàòà  |" << std::endl;
			std::cout << "+-----------------------------------------------------------------------------+";

			std::cout << "\n| " << std::setw(12) << std::left << vectorEmployee.at(i)->getSurname()
				<< std::setw(12) << std::left << vectorEmployee.at(i)->getName()
				<< std::setw(14) << std::left << vectorEmployee.at(i)->getOtch()
				<< "| " << std::setw(10) << std::left << vectorEmployee.at(i)->getId()
				<< "| " << std::setw(7) << std::left << vectorEmployee.at(i)->getHourlyRate()
				<< "$  | " << std::setw(9) << std::left << vectorEmployee.at(i)->getAverageSalary() << "$  |";
			std::cout << std::endl << "+-----------------------------------------------------------------------------+" << std::endl;

			std::cout << std::endl << "--- ÌÅÑßÖ --- ÇÀÐÏËÀÒÀ ---" << std::endl;
			int amount = vectorEmployee.at(i)->getAmountOfMonths();
			vectorEmployee.at(i)->getHoursWorkedForMonth().resize(amount - 1);
			vectorEmployee.at(i)->getSalary().resize(amount - 1);
			for (int j = 0; j < amount - 1; j++)
			{
				std::cout << "   " << vectorEmployee.at(i)->getHoursWorkedForMonth().at(j).first << "     " <<
					vectorEmployee.at(i)->getSalary().at(j) << std::endl;;
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