#include "menu.h"

void Department::getFromFile(std::istream& in)
{
	in >> this->title >> this->numberOfProjects >> this->numberOfEmployees;
	this->employee.resize(this->numberOfEmployees);
	std::string surname{}, name{}, otch{};
	int id{};
	std::string hourlyRate{};
	for (int i = 0; i < this->employee.size(); i++)
	{

		in >> surname >> name >> otch >> id >> hourlyRate;

		this->employee.at(i)->setSurname(surname);
		this->employee.at(i)->setName(name);
		this->employee.at(i)->setOtch(otch);
		this->employee.at(i)->setId(id);
		this->employee.at(i)->setHourlyRate(hourlyRate);
	}
}

int Department::findDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	char ch;
	std::string title{};
	int flag;
	int i;
	while (true)
	{
		flag = 0;
		databaseDepartment(dep);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ" << std::endl;
		title = Menu::checkString();

		for (i = 0; i < dep.size() && flag == 0; i++)
		{
			if (title == dep.at(i)->getTitle())
			{
				flag++;
			}
		}

		if (flag == 0)
		{
			system("cls");
			Console::GoToXY(35, 14);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- ÒÀÊÎÃÎ ÍÀÇÂÀÍÈß ÎÒÄÅËÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
			system("cls");
			continue;
		}
		else
			return i;
	}
}

void Department::databaseDepartment(std::vector<std::shared_ptr<Department>> dep)
{
	for (int amount = 0; amount < dep.size(); amount++)
	{
		std::cout << std::endl << "+-----------------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                           ÁÀÇÀ ÄÀÍÍÛÕ ÎÒÄÅËÀ - " << std::setw(35) << std::left << dep.at(amount)->getTitle() << "| " << std::endl;
		std::cout << "+-------------+-----+---------------------------------------+-----------+-----------+" << std::endl;
		std::cout << "|    Êîë-âî   |  ¹  |              ÔÈÎ ðàáîòíèêà            | Òàáåëüíûé | Ïî÷àñîâîé |" << std::endl;
		std::cout << "|   ïðîåêòîâ  |     |                                       |   íîìåð   |   òàðèô   |" << std::endl;
		std::cout << "+-------------+-----+---------------------------------------+-----------+-----------+";

		std::cout << "\n " << "    " << std::setw(9) << dep.at(amount)->getNumberOfProjects();
		if (dep.at(amount)->getEmployees().size() > 0)
		{
			for (int i = 0; i < dep.at(amount)->getEmployees().size(); i++)
			{
				if (i == 0)
				{
					std::cout << "| " << std::setw(4) << std::left << (i + 1)
						<< "| " << std::setw(12) << std::left << dep.at(amount)->getEmployees().at(i)->getSurname()
						<< std::setw(12) << std::left << dep.at(amount)->getEmployees().at(i)->getName()
						<< std::setw(14) << std::left << dep.at(amount)->getEmployees().at(i)->getOtch()
						<< "| " << std::setw(10) << std::left << dep.at(amount)->getEmployees().at(i)->getId()
						<< "| " << std::setw(8) << std::left << dep.at(amount)->getEmployees().at(i)->getHourlyRate() << "$ |";
					std::cout << std::endl << "              +-----+---------------------------------------+-----------+-----------+" << std::endl;
				}
				else
				{
					std::cout << "              | " << std::setw(4) << std::left << (i + 1)
						<< "| " << std::setw(12) << std::left << dep.at(amount)->getEmployees().at(i)->getSurname()
						<< std::setw(12) << std::left << dep.at(amount)->getEmployees().at(i)->getName()
						<< std::setw(14) << std::left << dep.at(amount)->getEmployees().at(i)->getOtch()
						<< "| " << std::setw(10) << std::left << dep.at(amount)->getEmployees().at(i)->getId()
						<< "| " << std::setw(8) << std::left << dep.at(amount)->getEmployees().at(i)->getHourlyRate() << "$ |";
					std::cout << std::endl << "              +-----+---------------------------------------+-----------+-----------+" << std::endl;
				}
			}
		}
		else std::cout << std::endl;
	}
}

void Department::changeTitle(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment)
{
	std::string title;
	char ch;
	system("cls");
	Console::GoToXY(45, 13);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ";
	Console::GoToXY(55, 14);
	title = Menu::checkString();
	dep.at(numberOfDepartment)->getTitle() = title;
	Vectors::addDepartmentInFile(dep);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Department::changeNumberOfProjects(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment)
{
	int numb;
	char ch;
	system("cls");
	Console::GoToXY(40, 13);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÊÎË-ÂÎ ÏÐÎÅÊÒÎÂ Ó ÎÒÄÅËÀ";
	Console::GoToXY(55, 14);
	numb = Menu::checkInt();
	dep.at(numberOfDepartment)->setNumberOfProjects(numb);
	Vectors::addDepartmentInFile(dep);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}


void Department::addNewEmployeeInDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment)
{
	system("cls");
	std::shared_ptr<Employee> copy = std::make_shared<Employee>();
	bool flag_1 = true;
	char ch;
	int flag;
	int numbOfEmployees = dep.at(numberOfDepartment)->getEmployees().size();

	while (true)
	{
		flag = 0;
		flag_1 = true;;
		system("cls");
		Console::GoToXY(36, 8);
		std::cout << "+-----------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                               |";
		Console::GoToXY(36, 10);
		std::cout << "|      ÄÎÁÀÂËÅÍÈÅ ÍÎÂÛÕ ÐÀÁÎÒÍÈÊÎÂ Â ÎÒÄÅË      |";
		Console::GoToXY(36, 11);
		std::cout << "|                                               |";
		Console::GoToXY(36, 12);
		std::cout << "+-----------------------------------------------+";

		copy->setFullName();

		for (int j = 0; j < emp.size() && flag == 0; j++)
		{
			if (copy->getSurname() == emp.at(j)->getSurname() &&
				copy->getName() == emp.at(j)->getName() &&
				copy->getOtch() == emp.at(j)->getOtch())
			{
				flag++;
				numbOfEmployees++;
				dep.at(numberOfDepartment)->getEmployees().push_back(emp.at(j));
			}
		}


		if (flag == 0)
		{
			system("cls");
			Console::GoToXY(30, 14);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- ÂÂÅÄÅÍÍÛÉ ÐÀÁÎÒÍÈÊ ÍÅ ÍÀÉÄÅÍ Â ÁÀÇÅ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
			system("cls");
		}
		else
		{
			dep.at(numberOfDepartment)->setNumberOfEmployees(numbOfEmployees);
			Vectors::addDepartmentInFile(dep);

			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+-------------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                                 |";
			Console::GoToXY(35, 13);
			std::cout << "|     ÍÎÂÛÉ ÐÀÁÎÒÍÈÊ ÓÑÏÅØÍÎ ÄÎÁÀÂËÅÍ Â ÎÒÄÅË     |";
			Console::GoToXY(35, 14);
			std::cout << "|                                                 |";
			Console::GoToXY(35, 15);
			std::cout << "+-------------------------------------------------+";
			ch = _getch();
		}

		system("cls");
		Console::GoToXY(36, 8);
		std::cout << "+-----------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                               |";
		Console::GoToXY(36, 10);
		std::cout << "|      ÄÎÁÀÂËÅÍÈÅ ÍÎÂÛÕ ÐÀÁÎÒÍÈÊÎÂ Â ÎÒÄÅË      |";
		Console::GoToXY(36, 11);
		std::cout << "|                                               |";
		Console::GoToXY(36, 12);
		std::cout << "+-----------------------------------------------+";
		Console::GoToXY(38, 14);

		if (Menu::continueOrNot())
		{
			flag_1 = false;
			break;
		}
		else return;
	}
}

void Department::deleteEmployeeFromDepartment(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment)
{
	char  ch;
	if (!dep.size())
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

	int numbOfEmployee = findEmployeeInDepartment(dep, numberOfDepartment);

	if (Menu::confirmOrNot())
	{
		if (numbOfEmployee > 0 && numbOfEmployee <= dep.at(numberOfDepartment)->getNumberOfEmployees()) 
		{
			if (numbOfEmployee == dep.at(numberOfDepartment)->getNumberOfEmployees())
				dep.at(numberOfDepartment)->getEmployees().pop_back();
			else
				dep.at(numberOfDepartment)->getEmployees().erase(dep.at(numberOfDepartment)->getEmployees().begin() + (numberOfDepartment - 1));

			int count = dep.at(numberOfDepartment)->getNumberOfEmployees();
			count--;
			dep.at(numberOfDepartment)->setNumberOfEmployees(count);
			Vectors::addDepartmentInFile(dep);

			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+------------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                                |";
			Console::GoToXY(35, 13);
			std::cout << "|       ÄÀÍÍÛÅ Î ÐÀÁÎÒÍÈÊÅ ÓÑÏÅØÍÎ ÓÄÀËÅÍÛ       |";
			Console::GoToXY(35, 14);
			std::cout << "|                                                |";
			Console::GoToXY(35, 15);
			std::cout << "+------------------------------------------------+";
			ch = _getch();
			return;
		}
	}
	else return;
}

int Department::findEmployeeInDepartment(std::vector<std::shared_ptr<Department>> dep, int numberOfDepartment)
{
	char ch;
	int flag, number;
	while (true)
	{
		flag = 0;
		databaseOfParticularDepartment(dep, numberOfDepartment);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ" << std::endl;
		number = Menu::checkInt();
		if (number <= 0 || unsigned(number) > dep.at(numberOfDepartment)->getEmployees().size())
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
			return number;
	}
}

void Department::databaseOfParticularDepartment(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment)
{
	std::cout << "+---------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                   ÁÀÇÀ ÄÀÍÍÛÕ ÎÒÄÅËÀ - " << std::setw(35) << std::left << dep.at(numberOfDepartment)->getTitle() << "| " << std::endl;
	std::cout << "+-------------+-----+-------------------------------+-----------+-----------+" << std::endl;
	std::cout << "|    Êîë-âî   |  ¹  |        ÔÈÎ ðàáîòíèêà          | Òàáåëüíûé | Ïî÷àñîâîé |" << std::endl;
	std::cout << "|   ïðîåêòîâ  |     |                               |   íîìåð   |   òàðèô   |" << std::endl;
	std::cout << "+-------------+-----+-------------------------------+-----------+-----------+";

	std::cout << "\n " << "    " << std::setw(9) << dep.at(numberOfDepartment)->getNumberOfProjects();

	if (dep.at(numberOfDepartment)->getEmployees().size() > 0)
	{
		for (int i = 0; i < dep.at(numberOfDepartment)->getEmployees().size(); i++)
		{
			if (i == 0)
			{
				std::cout << "| " << std::setw(4) << std::left << (i + 1)
					<< "| " << std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getSurname()
					<< std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getName()
					<< std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getOtch()
					<< "| " << std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getId()
					<< "| " << std::setw(8) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getHourlyRate() << "$ |";
				std::cout << std::endl << "              +-----+-------------------------------+-----------+-----------+" << std::endl;
			}
			else
			{
				std::cout << "              | " << std::setw(4) << std::left << (i + 1)
					<< "| " << std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getSurname()
					<< std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getName()
					<< std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getOtch()
					<< "| " << std::setw(10) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getId()
					<< "| " << std::setw(8) << std::left << dep.at(numberOfDepartment)->getEmployees().at(i)->getHourlyRate() << "$ |";
				std::cout << std::endl << "              +-----+-------------------------------+-----------+-----------+" << std::endl;
			}
		}
	}
	else std::cout << std::endl;
}

void Department::deleteDatabaseDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	char ch;
	system("cls");
	if (!dep.size())
	{
		Console::GoToXY(45, 14);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ÁÀÇÀ ÄÀÍÍÛÕ ÏÓÑÒÀ -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÏÎÄÒÂÅÐÄÈÒÅ, ×ÒÎ ÂÛ ÕÎÒÈÒÅ ÓÄÀËÈÒÜ ÂÑÞ ÁÀÇÓ ÄÀÍÍÛÕ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	if (Menu::continueOrNot())
	{
		dep.clear();
		std::ofstream file("department.txt", std::ios::trunc);
		file << "";
		file.close();
		system("cls");
		Console::GoToXY(35, 11);
		std::cout << "+-------------------------------------------------+";
		Console::GoToXY(35, 12);
		std::cout << "|                                                 |";
		Console::GoToXY(35, 13);
		std::cout << "|       ÁÀÇÀ ÄÀÍÍÛÕ ÎÒÄÅËÎÂ ÓÑÏÅØÍÎ ÓÄÀËÅÍÀ       |";
		Console::GoToXY(35, 14);
		std::cout << "|                                                 |";
		Console::GoToXY(35, 15);
		std::cout << "+-------------------------------------------------+";
		ch = _getch();
		return;
	}
	else return;
}

void Department::addNewDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep)
{
	char ch;
	while (true)
	{
		int flag = 0;
		std::shared_ptr<Department> d = std::make_shared<Department>();

		system("cls");
		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|         ÄÎÁÀÂËÅÍÈÅ ÍÎÂÎÃÎ ÎÒÄÅËÀ          |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(46, 14);
		std::cout << "ÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ ";
		Console::GoToXY(52, 15);
		d->setTitle(Menu::checkString());

		system("cls");
		Console::GoToXY(36, 8);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                           |";
		Console::GoToXY(36, 10);
		std::cout << "|         ÄÎÁÀÂËÅÍÈÅ ÍÎÂÎÃÎ ÎÒÄÅËÀ          |";
		Console::GoToXY(36, 11);
		std::cout << "|                                           |";
		Console::GoToXY(36, 12);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(40, 14);
		std::cout << "ÂÂÅÄÈÒÅ ÊÎËÈ×ÅÑÒÂÎ ÏÐÎÅÊÒÎÂ Ó ÎÒÄÅËÀ";
		Console::GoToXY(53, 15);
		d->setNumberOfProjects(Menu::checkInt());

		dep.push_back(d);
		Vectors::addDepartmentInFile(dep);

		system("cls");
		Console::GoToXY(35, 11);
		std::cout << "+--------------------------------------------+";
		Console::GoToXY(35, 12);
		std::cout << "|                                            |";
		Console::GoToXY(35, 13);
		std::cout << "|        ÍÎÂÛÉ ÎÒÄÅË ÓÑÏÅØÍÎ ÄÎÁÀÂËÅÍ        |";
		Console::GoToXY(35, 14);
		std::cout << "|                                            |";
		Console::GoToXY(35, 15);
		std::cout << "+--------------------------------------------+";
		ch = _getch();
		return;
	}
}

void Department::deleteDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	char  ch;
	if (!dep.size())
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

	int numberDepartment = findDepartment(dep);

	if (Menu::confirmOrNot())
	{
		if (numberDepartment > 0 && numberDepartment <= dep.size())
		{
			if (numberDepartment == dep.size())
				dep.pop_back();
			else
				dep.erase(dep.begin() + (numberDepartment - 1));
			Vectors::addDepartmentInFile(dep);

			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+------------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                                |";
			Console::GoToXY(35, 13);
			std::cout << "|        ÄÀÍÍÛÅ ÎÁ ÎÒÄÅËÅ ÓÑÏÅØÍÎ ÓÄÀËÅÍÛ        |";
			Console::GoToXY(35, 14);
			std::cout << "|                                                |";
			Console::GoToXY(35, 15);
			std::cout << "+------------------------------------------------+";
			ch = _getch();
			return;
		}
	}
	else return;
}
