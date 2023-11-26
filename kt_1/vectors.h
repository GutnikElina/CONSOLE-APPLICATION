#pragma once

#ifndef VECTORS_H
#define VECTORS_H

#define _CRT_SECURE_NO_WARNINGS

#include "department.h"

class Vectors
{
private:

	std::vector<std::shared_ptr<User>> vector_user;
	std::vector<std::shared_ptr<Employee>> vector_employee;
	std::vector<std::shared_ptr<Department>>  vector_department;

public:

	Vectors() : vector_user(0), vector_employee(0), vector_department(0) {}
	~Vectors() {}

	int CountLengthFile();
	static std::string HashPassword(std::string password);

	std::vector<std::shared_ptr<User>>& GetUsers() { return this->vector_user; }
	std::vector<std::shared_ptr<Employee>>& GetEmployees() { return this->vector_employee; }
	std::vector<std::shared_ptr<Department>>& GetDepartment() { return this->vector_department; }

	void GetVectorUsers();
	void GetVectorEmployees();
	void GetVectorDepartment();

	static std::string CheckInputUsername();
	static std::string CheckInputPassword();
	static std::string FindUsername(std::vector<std::shared_ptr<User>> vector_user);
	static std::string FindPassword();

	static std::string SingIn(std::vector<std::shared_ptr<User>>& vector_user);
	static void SingUp(int role, std::vector<std::shared_ptr<User>>& vector_user, Vectors& vect);

	static void AddAccountInFile(std::vector<std::shared_ptr<User>> vector_user);
	static void AddEmployeeInFile(std::vector<std::shared_ptr<Employee>> vector_employee);
	static void AddDepartmentInFile(std::vector<std::shared_ptr<Department>> vector_department);
};

#endif