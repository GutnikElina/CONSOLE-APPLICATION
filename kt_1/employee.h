#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define _CRT_SECURE_NO_WARNINGS

#include "account.h"

class Employee : public FIO
{
private:

	FIO fio;
	int id;
	std::string hourly_rate;
	double average_salary;
	int amount_months;
	std::vector<double> salary;
	std::vector<std::pair<std::string, double>> hours_worked_for_month;

public:

	Employee() : id(0), hourly_rate("NULL"), average_salary(0), salary(0), hours_worked_for_month(0), amount_months(0) {}
	~Employee() { this->hourly_rate.clear(); }

	int GetId() { return this->id; }
	std::string GetHourlyRate() { return this->hourly_rate; }
	double GetAverageSalary() { return this->average_salary; }
	int GetAmountMonths() { return this->amount_months; }
	std::vector<double> GetSalary() { return this->salary; }
	std::vector<std::pair<std::string, double>> GetHoursWorkedForMonth() { return this->hours_worked_for_month; }

	void SetId(int id) { this->id = id; }
	void SetHourlyRate(std::string hourly_rate) { this->hourly_rate = hourly_rate; }
	void SetAverageSalary(double average_salary) { this->average_salary = average_salary; }
	void SetAmountMonths(int amount_months) { this->amount_months = amount_months; }
	void SetSalary(std::vector<double> salary) { this->salary = salary; }
	void SetHoursWorkedForMonth(std::vector<std::pair<std::string, double>> hours)
	{ this->hours_worked_for_month = hours; }

	static double CalculateSalary(double hours, std::string hourly_rate);
	static double CalculateAverageSalary(std::vector<double> salary);
	static void DatabaseEmployee(std::vector<std::shared_ptr<Employee>> employee);

	static int FindEmployee(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void FindByName(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void FindById(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void FindByHourlyRate(std::vector<std::shared_ptr<Employee>> vectorEmployee);

	static void ChooseSortWindow();
	static void EndSortWindow();

	static void SortBySurname(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void SortByID(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void SortByHourlyRate(std::vector<std::shared_ptr<Employee>>& vectorEmployee);

	static bool SortBySurnameCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>&  second);
	static bool SortBySurnameCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool SortByIdCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool SortByIdCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool SortByHourlyRatCompDown(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);
	static bool SortByHourlyRatCompUp(std::shared_ptr<Employee>& first, std::shared_ptr<Employee>& second);

	static void SalaryData(std::vector<std::shared_ptr<Employee>> vectorEmploye);

	static void ChangeSurname(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);
	static void ChangeName(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);
	static void ChangeOtch(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);  
	static void ChangeId(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);
	static void ChangeHourlyRate(std::vector<std::shared_ptr<Employee>>& vectorEmployee, int number);

	static void DeleteDatabase(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void AddEmployeeDatabase(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void DeleteEmployee(std::vector<std::shared_ptr<Employee>>& vectorEmployee);

	static void DatabaseForUser(std::vector<std::shared_ptr<User>> vectorUser, 
		std::vector<std::shared_ptr<Employee>> vectorEmployee, std::string username);

	void GetFromFile(std::istream& in) override;
};

#endif