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