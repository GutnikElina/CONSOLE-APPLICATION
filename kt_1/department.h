#pragma once

#ifndef USER_H

#define USER_H

#include "employee.h"

class Department: public Employee
{
private:

	std::string title{};
	int numberOfProjects{};
	int numberOfEmployees{};
	std::vector<std::shared_ptr<Employee>> employee{};

public:

	Department() : title("NULL"), numberOfProjects(0), numberOfEmployees(0), employee(0) {};
	~Department() { this->title.clear(); };

	void getFromFile(std::istream& in);

	void setTitle(std::string title) { this->title = title; }
	void setNumberOfProjects(int numberOfProjects) { this->numberOfProjects = numberOfProjects; };
	void setNumberOfEmployees(int numberOfEmployees) { this->numberOfEmployees = numberOfEmployees; };

	std::string getTitle() { return this->title; }
	int getNumberOfProjects() { return this->numberOfProjects; };
	int getNumberOfEmployees() { return this->numberOfEmployees; };
	std::vector<std::shared_ptr<Employee>>& getEmployees() { return this->employee; }
};


#endif 