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
	std::vector<std::shared_ptr<double>> salary;
	std::vector<std::shared_ptr<std::string>> hoursWorkedForMonth;

public:

	Employee() : id(0), hourlyRate("NULL"), averageSalary(0), salary(0), hoursWorkedForMonth(0), amountOfMonths(0) {}
	~Employee() { this->hourlyRate.clear(); }

	void getFromFile(std::istream& in);

	void setId(int& id) { this->id = id; }
	void setHourlyRate(std::string& hourlyRate) { this->hourlyRate = hourlyRate; }
	void setAverageSalary(double& averageSalary) { this->averageSalary = averageSalary; }
	void setAmountOfMonths(int& amountOfMonths) { this->amountOfMonths = amountOfMonths; }

	int getId() { return this->id; }
	std::string getHourlyRate() { return this->hourlyRate; }
	double getAverageSalary() { return this->averageSalary; }
	int getAmountOfMonths() { return this->amountOfMonths; }
	std::vector<std::shared_ptr<double>>& getSalary() { return this->salary; }
	std::vector<std::shared_ptr<std::string>>& getHoursWorkedForMonth() { return this->hoursWorkedForMonth; }
};

#endif