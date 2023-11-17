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

	void getFromFile(std::istream& in) override;

	void setTitle(std::string title) { this->title = title; }
	void setNumberOfProjects(int numberOfProjects) { this->numberOfProjects = numberOfProjects; };
	void setNumberOfEmployees(int numberOfEmployees) { this->numberOfEmployees = numberOfEmployees; };
	void setEmployees(std::vector<std::shared_ptr<Employee>> e) { this->employee = e; }

	std::string getTitle() { return this->title; }
	int getNumberOfProjects() { return this->numberOfProjects; };
	int getNumberOfEmployees() { return this->numberOfEmployees; };
	std::vector<std::shared_ptr<Employee>>& getEmployees() { return this->employee; }

	static int findDepartment(std::vector<std::shared_ptr<Department>>& dep);
	static int findEmployeeInDepartment(std::vector<std::shared_ptr<Department>> dep, int numberOfDepartment);
	static void databaseDepartment(std::vector<std::shared_ptr<Department>> dep);

	static void changeTitle(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment);
	static void changeNumberOfProjects(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment);

	static void deleteEmployeeFromDepartment(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment);
	static void addNewEmployeeInDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment);
	static void databaseOfParticularDepartment(std::vector<std::shared_ptr<Department>>& dep, int numberOfDepartment);
	static void deleteDatabaseDepartment(std::vector<std::shared_ptr<Department>>& dep);
	static void addNewDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep);
	static void deleteDepartment(std::vector<std::shared_ptr<Department>>& dep);
};


#endif 