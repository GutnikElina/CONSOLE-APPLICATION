#pragma once

#ifndef VECTORS_H

#define VECTORS_H

#include "department.h"

class Vectors
{
private:

	std::vector<std::shared_ptr<User>> vectorUser;
	std::vector<std::shared_ptr<Employee>> vectorEmployee;
	std::vector<std::shared_ptr<Department>>  vectorDepartment;

public:

	Vectors() : vectorUser(0), vectorEmployee(0), vectorDepartment(0) {}
	~Vectors() {}

	int countLengthFile(std::string nameFile);
	static std::string hash_password(const std::string& password);

	std::vector<std::shared_ptr<User>>& getUsers() { return this->vectorUser; }
	std::vector<std::shared_ptr<Employee>>& getEmployees() { return this->vectorEmployee; }
	std::vector<std::shared_ptr<Department>>& getDepartment() { return this->vectorDepartment; }

	void getVectorUsers();
	void getVectorEmployees();
	void getVectorDepartment();

	static std::string checkInputUsername();
	static std::string checkInputPassword();
	static std::string checkUsername(std::vector<std::shared_ptr<User>> vectorUser);
	static std::string checkPassword();

	static std::string singIn(std::vector<std::shared_ptr<User>>& vectorUser);

	void addAccountInFile();
	void addEmployeeInFile();

};

#endif