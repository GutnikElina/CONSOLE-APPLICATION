#include "menu.h"

void Employee::getFromFile(std::istream& in)
{
	double sal;
	std::string hours;
	FIO::getFromFile(in);
	in >> this->id >> this->hourlyRate >> this->averageSalary >> this->amountOfMonths;
	this->hoursWorkedForMonth.resize(this->amountOfMonths);
	this->salary.resize(this->amountOfMonths);

	while (in >> sal >> hours)
	{
		salary.push_back(std::make_shared<double>(sal));
		hoursWorkedForMonth.push_back(std::make_shared<std::string>(hours));
	}
}
