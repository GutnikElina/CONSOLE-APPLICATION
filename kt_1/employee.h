#pragma once

#ifndef EMPLOYEE_H

#define EMPLOYEE_H

#include "account.h"

class Employee : public FIO
{
private:

	FIO fio{};
	int id{};
	std::string hourlyRate{};
	double averageSalary{};
	int amountOfMonths{};
	std::vector<double> salary{};
	std::vector<std::pair<std::string, double>> hoursWorkedForMonth{};

public:

	Employee() : id(0), hourlyRate("NULL"), averageSalary(0), salary(0), hoursWorkedForMonth(0), amountOfMonths(0) {}
	~Employee() { this->hourlyRate.clear(); }

	void setFullName() { this->FIO::set(); }
	void setId(int& id) { this->id = id; }
	void setHourlyRate(std::string& hourlyRate) { this->hourlyRate = hourlyRate; }
	void setAverageSalary(double& averageSalary) { this->averageSalary = averageSalary; }
	void setAmountOfMonths(int& amountOfMonths) { this->amountOfMonths = amountOfMonths; }
	void setSalary(std::vector<double> salary) { this->salary = salary; }
	void setHoursWorkedForMonth(std::vector<std::pair<std::string, double>> hoursWorkedForMonth) 
	{ this->hoursWorkedForMonth = hoursWorkedForMonth; }

	int getId() { return this->id; }
	std::string getHourlyRate() { return this->hourlyRate; }
	double getAverageSalary() { return this->averageSalary; }
	int getAmountOfMonths() { return this->amountOfMonths; }
	std::vector<double> getSalary() { return this->salary; }
	std::vector<std::pair<std::string, double>> getHoursWorkedForMonth() { return this->hoursWorkedForMonth; }

	void getFromFile(std::istream& in) override;

	static double calculateSalary(double hours, std::string hourlyRate);
	static double calculateAverageSalary(std::vector<double> s);
	static void database(std::vector<std::shared_ptr<Employee>> employee);

	static int findEmployee(std::vector<std::shared_ptr<Employee>> vectorEmployee);

	static void findByName(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void findById(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void findByHourlyRate(std::vector<std::shared_ptr<Employee>> vectorEmployee);

	static void sortBySurname(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void sortByID(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void sortByHourlyRate(std::vector<std::shared_ptr<Employee>>& vectorEmployee);

	static bool sortBySurnameCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>&  second);
	static bool sortBySurnameCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool sortByIdCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool sortByIdCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool sortByHourlyRatCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool sortByHourlyRatCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);

	static void salaryData(std::vector<std::shared_ptr<Employee>> vectorEmploye);

	static void changeSurname(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);
	static void changeName(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);
	static void changeOtch(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);  
	static void changeId(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);
	static void changeHourlyRate(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);

	static void deleteDatabase(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void addEmployeeDatabase(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void deleteEmployee(std::vector<std::shared_ptr<Employee>>& vectorEmployee);

	static void databaseForUser(std::vector<std::shared_ptr<User>> vectorUser, std::vector<std::shared_ptr<Employee>> vectorEmployee, std::string username);
};

#endif