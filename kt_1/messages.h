#pragma once

#ifndef MESSAGES_H
#define MESSAGES_H

#define _CRT_SECURE_NO_WARNINGS

#include "common.h"

class Messages
{
public: 

	static void SuccessAddAccount();
	static void AcountNotExist();
	static void ErrorDeleteMyAccount();
	static void SuccessDeleteAccount();
	static void ErrorLoginTheSame();
	static void ErrorPasswordTheSame();
	static void UpdatingWindow(std::string word);
	static void ErrorChangingAccess();
	static void ErrorChangingRole();
	static void ChangingAccess();
	static void ChangingRole();
	static void ChangingDataAccount();

	static void ErrorFindDepartment();
	static void DepartmentChangeWindow();
	static void ErrorFindEmployee();
	static void AddDepartmentWindow();
	static void ConfirmDeleting();
	static void AddEmployeeWindow();

	static void ChooseSortWindow();
	static void EndSortWindow();
	static void ErrorData();
	static void ErrorMonth();
	static void ErrorYear();
	static void ErrorInputHours();
	static void ChangingEmployeeData();
	static void DeleteDBEmployeeWindow();
	static void ErrorFindYou();
};

#endif 
