#pragma once

#ifndef MENU_H
#define MENU_H

#define _CRT_SECURE_NO_WARNINGS

#include "vectors.h"

class Menu
{
public:

	static void FileNotOpened();
	static void EmptyDatabase();

	static bool IsDigitKey(char key);
	static int CheckInt();
	static std::string CheckDouble();
	static std::string CheckString();

	static int ChoiceKeyboard(std::string mainMenu[], int size);

	static bool confirmOrNot();
	static bool continueOrNot();
	static bool exitOrNot();

	static void MenuAdmin(Vectors& vect, std::string username);
	static void MenuUser(Vectors& vect, std::string username);

	static void ChangeAccountMenu(std::vector<std::shared_ptr<User>>& vectorUser, std::string username);
	static void WorkWithDataMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void WorkWithDepartmentsMenu(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep);

	static void DataProcessingMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void ChangeDataMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);

	static void FindMenu(std::vector<std::shared_ptr<Employee>> vectorEmployee);
	static void SortMenu(std::vector<std::shared_ptr<Employee>> vectorEmployee);

	static void EditDatabaseMenu(std::vector<std::shared_ptr<Employee>>& vectorEmployee);
	static void EditDatabaseDepartmentMenu(std::vector<std::shared_ptr<Employee>>& emp, std::vector<std::shared_ptr<Department>>& dep);
};

#endif