#pragma once

#ifndef MESSAGES_H
#define MESSAGES_H

#define _CRT_SECURE_NO_WARNINGS

#include "common.h"

class Messages
{
public: 

	static void FileNotOpened();
	static void EmptyDatabase();

	static void ErrorLoginTheSame();
	static void ErrorDeleteMyAccount();
	static void ErrorChangingAccess();
	static void ErrorChangingRole();
	static void AcountNotExist();
	static void ErrorPasswordTheSame();
	static void ErrorFindDepartment();
	static void ErrorFindEmployee();
	static void ErrorData();
	static void ErrorMonth();
	static void ErrorYear();
	static void ErrorInputHours();
	static void ErrorFindYou();

	static void ConfirmDeleting();
	static void SuccessAddDepartment();
	static void SuccessDeleteEmployee();
	static void SuccessAddEmployee();
	static void SuccessDeleteDepartment();
	static void ChangingDataDepartment();
	static void ChangeRole();
	static void EditingDataWindow();
	static void SortingWindow();
	static void FindingEmployee();
	static void DataProcessing();
	static void WorkWithDataEmployee();
	static void AccountManagement();
	static void SuccessAddAccount();
	static void SuccessDeleteAccount();
	static void ChangingAccess();
	static void ChangingRole();
	static void ChangingDataAccount();
	static void DepartmentChangeWindow();
	static void AddDepartmentWindow();
	static void AddEmployeeWindow();
	static void ChooseSortWindow();
	static void EndSortWindow();
	static void ChangingEmployeeData();
	static void DeleteDBEmployeeWindow();
};

#endif 
