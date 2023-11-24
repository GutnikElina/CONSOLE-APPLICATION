#include "menu.h"

void Department::GetFromFile(std::istream& in)
{
	in >> this->title >> this->number_projects >> this->number_employees;
	this->employee.resize(this->number_employees);
	std::string surname{}, name{}, otch{};
	int id{};
	std::string hourlyRate{};
	for (int i = 0; i < this->employee.size(); i++)
	{

		in >> surname >> name >> otch >> id >> hourlyRate;

		this->employee.at(i)->SetSurname(surname);
		this->employee.at(i)->SetName(name);
		this->employee.at(i)->SetOtch(otch);
		this->employee.at(i)->SetId(id);
		this->employee.at(i)->SetHourlyRate(hourlyRate);
	}
}

int Department::FindDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	char ch;
	std::string title{};
	int flag;
	int i;
	while (true)
	{
		flag = 0;
		DepartmentsDatabase(dep);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ" << std::endl;
		title = Menu::CheckString();

		for (i = 0; i < dep.size() && flag == 0; i++)
		{
			if (title == dep.at(i)->GetTitle())
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

void Department::DepartmentsDatabase(std::vector<std::shared_ptr<Department>> dep)
{
	for (int amount = 0; amount < dep.size(); amount++)
	{
		std::cout << std::endl << "+-----------------------------------------------------------------------------------+" << std::endl;
		std::cout << "|                           ÁÀÇÀ ÄÀÍÍÛÕ ÎÒÄÅËÀ - " << std::setw(35) << std::left << dep.at(amount)->GetTitle() << "|" << std::endl;
		std::cout << "+-------------+-----+---------------------------------------+-----------+-----------+" << std::endl;
		std::cout << "|    Êîë-âî   |  ¹  |              ÔÈÎ ðàáîòíèêà            | Òàáåëüíûé | Ïî÷àñîâîé |" << std::endl;
		std::cout << "|   ïðîåêòîâ  |     |                                       |   íîìåð   |   òàðèô   |" << std::endl;
		std::cout << "+-------------+-----+---------------------------------------+-----------+-----------+";

		std::cout << "\n " << "    " << std::setw(9) << dep.at(amount)->GetNumberProjects();
		if (dep.at(amount)->GetEmployees().size() > 0)
		{
			for (int i = 0; i < dep.at(amount)->GetEmployees().size(); i++)
			{
				if (i == 0)
				{
					std::cout << "| " << std::setw(4) << std::left << (i + 1)
						<< "| " << std::setw(12) << std::left << dep.at(amount)->GetEmployees().at(i)->GetSurname()
						<< std::setw(12) << std::left << dep.at(amount)->GetEmployees().at(i)->GetName()
						<< std::setw(14) << std::left << dep.at(amount)->GetEmployees().at(i)->GetOtch()
						<< "| " << std::setw(10) << std::left << dep.at(amount)->GetEmployees().at(i)->GetId()
						<< "| " << std::setw(8) << std::left << dep.at(amount)->GetEmployees().at(i)->GetHourlyRate() << "$ |";
					std::cout << std::endl << "              +-----+---------------------------------------+-----------+-----------+" << std::endl;
				}
				else
				{
					std::cout << "              | " << std::setw(4) << std::left << (i + 1)
						<< "| " << std::setw(12) << std::left << dep.at(amount)->GetEmployees().at(i)->GetSurname()
						<< std::setw(12) << std::left << dep.at(amount)->GetEmployees().at(i)->GetName()
						<< std::setw(14) << std::left << dep.at(amount)->GetEmployees().at(i)->GetOtch()
						<< "| " << std::setw(10) << std::left << dep.at(amount)->GetEmployees().at(i)->GetId()
						<< "| " << std::setw(8) << std::left << dep.at(amount)->GetEmployees().at(i)->GetHourlyRate() << "$ |";
					std::cout << std::endl << "              +-----+---------------------------------------+-----------+-----------+" << std::endl;
				}
			}
		}
		else std::cout << std::endl;
	}
}

void Department::ChangeTitle(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	std::string title;
	char ch;
	system("cls");
	Console::GoToXY(45, 13);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ";
	Console::GoToXY(55, 14);
	title = Menu::CheckString();
	dep.at(number_department)->GetTitle() = title;
	Vectors::AddDepartmentInFile(dep);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}

void Department::ChangeNumberOfProjects(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	int numb;
	char ch;
	system("cls");
	Console::GoToXY(40, 13);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÊÎË-ÂÎ ÏÐÎÅÊÒÎÂ Ó ÎÒÄÅËÀ";
	Console::GoToXY(55, 14);
	numb = Menu::CheckInt();
	dep.at(number_department)->SetNumberProjects(numb);
	Vectors::AddDepartmentInFile(dep);
	system("cls");
	Console::GoToXY(35, 14);
	std::cout << " --------------- ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ --------------- ";
	ch = _getch();
	return;
}


void Department::AddNewEmployeeInDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	system("cls");
	std::shared_ptr<Employee> copy = std::make_shared<Employee>();
	bool flag_1 = true;
	char ch;
	int flag;
	int number_employee = dep.at(number_department)->GetEmployees().size();

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

		copy->SetFullName();

		for (int j = 0; j < emp.size() && flag == 0; j++)
		{
			if (copy->GetSurname() == emp.at(j)->GetSurname() &&
				copy->GetName() == emp.at(j)->GetName() &&
				copy->GetOtch() == emp.at(j)->GetOtch())
			{
				flag++;
				number_employee++;
				dep.at(number_department)->GetEmployees().push_back(emp.at(j));
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
			dep.at(number_department)->SetNumberEmployees(number_employee);
			Vectors::AddDepartmentInFile(dep);

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

void Department::DeleteEmployeeFromDepartment(std::vector<std::shared_ptr<Department>>& dep, int number_department)
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

	int number_employee = FindEmployeeInDepartment(dep, number_department);

	if (Menu::confirmOrNot())
	{
		if (number_employee > 0 && number_employee <= dep.at(number_department)->GetNumberEmployees())
		{
			if (number_employee == dep.at(number_department)->GetNumberEmployees())
				dep.at(number_department)->GetEmployees().pop_back();
			else
				dep.at(number_department)->GetEmployees().erase(dep.at(number_department)->GetEmployees().begin() + (number_department - 1));

			int count = dep.at(number_department)->GetNumberEmployees();
			count--;
			dep.at(number_department)->SetNumberEmployees(count);
			Vectors::AddDepartmentInFile(dep);

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

int Department::FindEmployeeInDepartment(std::vector<std::shared_ptr<Department>> dep, int number_department)
{
	char ch;
	int flag, number;
	while (true)
	{
		flag = 0;
		ParticulatDepartmentDatabase(dep, number_department);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ" << std::endl;
		number = Menu::CheckInt();
		if (number <= 0 || unsigned(number) > dep.at(number_department)->GetEmployees().size())
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

void Department::ParticulatDepartmentDatabase(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	std::cout << "+---------------------------------------------------------------------------+" << std::endl;
	std::cout << "|                   ÁÀÇÀ ÄÀÍÍÛÕ ÎÒÄÅËÀ - " << std::setw(35) << std::left << 
		dep.at(number_department)->GetTitle() << "| " << std::endl;
	std::cout << "+-------------+-----+-------------------------------+-----------+-----------+" << std::endl;
	std::cout << "|    Êîë-âî   |  ¹  |        ÔÈÎ ðàáîòíèêà          | Òàáåëüíûé | Ïî÷àñîâîé |" << std::endl;
	std::cout << "|   ïðîåêòîâ  |     |                               |   íîìåð   |   òàðèô   |" << std::endl;
	std::cout << "+-------------+-----+-------------------------------+-----------+-----------+";

	std::cout << "\n " << "    " << std::setw(9) << dep.at(number_department)->GetNumberProjects();

	if (dep.at(number_department)->GetEmployees().size() > 0)
	{
		for (int i = 0; i < dep.at(number_department)->GetEmployees().size(); i++)
		{
			if (i == 0)
			{
				std::cout << "| " << std::setw(4) << std::left << (i + 1)
					<< "| " << std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetSurname()
					<< std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetName()
					<< std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetOtch()
					<< "| " << std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetId()
					<< "| " << std::setw(8) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetHourlyRate() << "$ |";
				std::cout << std::endl << "              +-----+-------------------------------+-----------+-----------+" << std::endl;
			}
			else
			{
				std::cout << "              | " << std::setw(4) << std::left << (i + 1)
					<< "| " << std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetSurname()
					<< std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetName()
					<< std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetOtch()
					<< "| " << std::setw(10) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetId()
					<< "| " << std::setw(8) << std::left << dep.at(number_department)->GetEmployees().at(i)->GetHourlyRate() << "$ |";
				std::cout << std::endl << "              +-----+-------------------------------+-----------+-----------+" << std::endl;
			}
		}
	}
	else std::cout << std::endl;
}

void Department::DeleteDatabaseDepartment(std::vector<std::shared_ptr<Department>>& dep)
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

void Department::AddNewDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep)
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
		d->SetTitle(Menu::CheckString());

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
		d->SetNumberProjects(Menu::CheckInt());

		dep.push_back(d);
		Vectors::AddDepartmentInFile(dep);

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

void Department::DeleteDepartment(std::vector<std::shared_ptr<Department>>& dep)
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

	int number_department = FindDepartment(dep);

	if (Menu::confirmOrNot())
	{
		if (number_department > 0 && number_department <= dep.size())
		{
			if (number_department == dep.size())
				dep.pop_back();
			else
				dep.erase(dep.begin() + (number_department - 1));
			Vectors::AddDepartmentInFile(dep);

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
