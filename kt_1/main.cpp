#include "menu.h"

//чтобы войти как админ: username - admin; password - 12345;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"√утник Ёлина јндреевна, группа 272301");    // измен€ем заголовок окна приложени€
	Console::ConsoleCursorVisible(false, 100);

	Vectors vect{};
	std::string username{};
	int role{};
	bool flag = true;

	vect.getVectorUsers();              // считываем из файла все данные аккаунтов
	vect.getVectorEmployees();          // считываем из файла все данные работников
	vect.getVectorDepartment();		    // считываем из файла все данные отделов

	while (true)
	{
		int myChoice = User::enterAccount(vect.getUsers());        // вход в приложение

		if (myChoice == 0)
		{
			username = Vectors::singIn(vect.getUsers());           //авторизаци€
			if (username != "null")
			{
				role = User::findUser(username, vect.getUsers())->getRole();
				if (role == 1) Menu::menuAdmin(vect, username);
				else Menu::menuUser(vect, username);
			}
		}
		else if (myChoice == 1)
		{
			Vectors::singUp(0, vect.getUsers(), vect);                     //регистраци€
		}
		else exit(0);
	}
}

