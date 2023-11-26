#include "menu.h"

void Department::GetFromFile(std::istream& in)
{
	in >> this->title >> this->number_projects >> this->number_employees;
	this->employee.resize(this->number_employees);
	std::string surname, name, otch;
	int id;
	std::string hourlyRate;
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

void Department::ErrorFindDepartment()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÒÀÊÎÃÎ ÍÀÇÂÀÍÈß ÎÒÄÅËÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

int Department::FindDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	int i, flag = 0;
	while (true)
	{
		DepartmentsDatabase(dep);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ" << std::endl;
		std::string title = Menu::CheckString();
		for (i = 0; i < dep.size() && flag == 0; i++)
			if (title == dep.at(i)->GetTitle())
				flag++;
		if (flag == 0) ErrorFindDepartment();
		else
			return i;
	}
}

void Department::DepartmentsDatabase(std::vector<std::shared_ptr<Department>> dep)
{
	system("cls");
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

void Department::DepartmentChangeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+----------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                        |";
	Console::GoToXY(35, 13);
	std::cout << "|           ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ           |";
	Console::GoToXY(35, 14);
	std::cout << "|                                        |";
	Console::GoToXY(35, 15);
	std::cout << "+----------------------------------------+";
	char ch = _getch();
}

void Department::ChangeTitle(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	std::string title;
	system("cls");
	Console::GoToXY(45, 13);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ";
	Console::GoToXY(55, 14);
	title = Menu::CheckString();
	dep.at(number_department)->GetTitle() = title;
	Vectors::AddDepartmentInFile(dep);
	DepartmentChangeWindow();
	return;
}

void Department::ChangeNumberOfProjects(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	int numb;
	system("cls");
	Console::GoToXY(40, 13);
	std::cout << "ÂÂÅÄÈÒÅ ÍÎÂÎÅ ÊÎËÈ×ÅÑÒÂÎ ÏÐÎÅÊÒÎÂ Ó ÎÒÄÅËÀ";
	Console::GoToXY(55, 14);
	numb = Menu::CheckInt();
	dep.at(number_department)->SetNumberProjects(numb);
	Vectors::AddDepartmentInFile(dep);
	DepartmentChangeWindow();
	return;
}

void Department::AddEmployeeWindow()
{
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
}

void Department::AddNewEmployeeInDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	system("cls");
	std::shared_ptr<Employee> copy = std::make_shared<Employee>();
	int number_employee = (int)dep.at(number_department)->GetEmployees().size();

	while (true)
	{
		bool found = false;
		AddEmployeeWindow();
		copy->SetFullName();
		for (const auto& employee : emp)
		{
			if (copy->GetFullName() == employee->GetFullName())
			{
				found = true;
				number_employee++;
				dep.at(number_department)->GetEmployees().push_back(employee);
				break;
			}
		}
		if (!found)
			ErrorFindEmployee();
		else
		{
			dep.at(number_department)->SetNumberEmployees(number_employee);
			Vectors::AddDepartmentInFile(dep);
			DepartmentChangeWindow();
		}
		AddEmployeeWindow();
		Console::GoToXY(38, 14);
		if (Menu::continueOrNot())
			break;
		else
			return;
	}
}

void Department::DeleteEmployeeFromDepartment(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	if (!dep.size()) Menu::EmptyDatabase();
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
			DepartmentChangeWindow();
			return;
		}
	}
	else return;
}
void Department::ErrorFindEmployee()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÒÀÊÎÃÎ ÐÀÁÎÒÍÈÊÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

int Department::FindEmployeeInDepartment(std::vector<std::shared_ptr<Department>> dep, int number_department)
{
	int number;
	while (true)
	{
		ParticulatDepartmentDatabase(dep, number_department);
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÐÀÁÎÒÍÈÊÀ" << std::endl;
		number = Menu::CheckInt();
		if (number <= 0 || number > (int)dep.at(number_department)->GetEmployees().size())
			ErrorFindEmployee();
		else
			return number;
	}
}

void Department::ParticulatDepartmentDatabase(std::vector<std::shared_ptr<Department>>& dep, int number_department)
{
	system("cls");
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

void Department::ConfirmDeleting()
{
	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÏÎÄÒÂÅÐÄÈÒÅ, ×ÒÎ ÂÛ ÕÎÒÈÒÅ ÓÄÀËÈÒÜ ÂÑÞ ÁÀÇÓ ÄÀÍÍÛÕ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Department::DeleteDatabaseDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	if (!dep.size()) Menu::EmptyDatabase();
		
	ConfirmDeleting();
	if (Menu::continueOrNot())
	{
		dep.clear();
		std::ofstream file("department.txt", std::ios::trunc);
		file << "";
		file.close();
		DepartmentChangeWindow();
		return;
	}
	else return;
}

void Department::AddDepartmentWindow()
{
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
}

void Department::AddNewDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep)
{
	while (true)
	{
		std::shared_ptr<Department> d = std::make_shared<Department>();
		AddDepartmentWindow();
		Console::GoToXY(46, 14);
		std::cout << "ÂÂÅÄÈÒÅ ÍÀÇÂÀÍÈÅ ÎÒÄÅËÀ ";
		Console::GoToXY(52, 15);
		d->SetTitle(Menu::CheckString());
		AddDepartmentWindow();
		Console::GoToXY(40, 14);
		std::cout << "ÂÂÅÄÈÒÅ ÊÎËÈ×ÅÑÒÂÎ ÏÐÎÅÊÒÎÂ Ó ÎÒÄÅËÀ";
		Console::GoToXY(53, 15);
		d->SetNumberProjects(Menu::CheckInt());
		dep.push_back(d);
		Vectors::AddDepartmentInFile(dep);
		DepartmentChangeWindow();
		return;
	}
}

void Department::DeleteDepartment(std::vector<std::shared_ptr<Department>>& dep)
{
	if (!dep.size()) Menu::EmptyDatabase();
	
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
			DepartmentChangeWindow();
			return;
		}
	}
	else return;
}
