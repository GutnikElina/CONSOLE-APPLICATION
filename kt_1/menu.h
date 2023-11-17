#pragma once

#ifndef MENU_H

#define MENU_H

#include "vectors.h"

class Menu
{
public:

	static int checkInt();
	static std::string checkDouble();
	static std::string checkString();
	static int choiceKeyboard(std::string mainMenu[], int size);
	static bool confirmOrNot();
	static bool continueOrNot();
	static bool exitOrNot();

	static void menuAdmin(Vectors& vect, std::string username);
	static void menuUser(Vectors& vect, std::string username);

	static void changeAccountMenu(std::vector<std::shared_ptr<User>>& vectorUser, std::string username);
	static void workWithDataMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void workWithDepartmentsMenu(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep);

	static void dataProcessingMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void changeDataMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);

	static void findMenu(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void sortMenu(std::vector<std::shared_ptr<Employee>> vectorEmployee);

	static void editDatabaseMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void editDatabaseDepartmentMenu(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep);
};

#endif