#pragma once

#ifndef USER_H
#define USER_H

#define _CRT_SECURE_NO_WARNINGS

#include "employee.h"

class Department: public Employee
{
private:

	std::string title;
	int number_projects;
	int number_employees;
	std::vector<std::shared_ptr<Employee>> employee;

public:

	Department() : title("NULL"), number_projects(0), number_employees(0), employee(0) {}
	~Department() { this->title.clear(); this->employee.clear(); }

	void SetTitle(std::string title) { this->title = title; }
	void SetNumberProjects(int number_projects) { this->number_projects = number_projects; };
	void SetNumberEmployees(int number_employees) { this->number_employees = number_employees; };
	void SetEmployees(std::vector<std::shared_ptr<Employee>> e) { this->employee = e; }

	std::string GetTitle() { return this->title; }
	int GetNumberProjects() { return this->number_projects; };
	int GetNumberEmployees() { return this->number_employees; };
	std::vector<std::shared_ptr<Employee>>& GetEmployees() { return this->employee; }

	static int FindDepartment(std::vector<std::shared_ptr<Department>>& dep);
	static int FindEmployeeInDepartment(std::vector<std::shared_ptr<Department>> dep, int number_department);
	static void DepartmentsDatabase(std::vector<std::shared_ptr<Department>> dep);

	static void ChangeTitle(std::vector<std::shared_ptr<Department>>& dep, int number_department);
	static void ChangeNumberOfProjects(std::vector<std::shared_ptr<Department>>& dep, int number_department);

	static void DeleteEmployeeFromDepartment(std::vector<std::shared_ptr<Department>>& dep, int number_projects);
	static void AddNewEmployeeInDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep, int number_department);
	static void ParticulatDepartmentDatabase(std::vector<std::shared_ptr<Department>>& dep, int number_department);
	static void DeleteDatabaseDepartment(std::vector<std::shared_ptr<Department>>& dep);
	static void AddNewDepartment(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep);
	static void DeleteDepartment(std::vector<std::shared_ptr<Department>>& dep);

	void GetFromFile(std::istream& in) override;
};


#endif 