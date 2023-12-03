#include "menu.h"

//чтобы войти как админ: username - admin; password - 12345;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"√утник Ёлина јндреевна, группа 272301");    // измен€ем заголовок окна приложени€
	Console::ConsoleCursorVisible(false, 100);                    // управл€ем видимостью курсора в консоли

	std::string username;
	int role;

	Vectors vect;
	vect.GetVectorUsers();              // считываем из файла все данные аккаунтов
	vect.GetVectorEmployees();          // считываем из файла все данные работников
	vect.GetVectorDepartment();		    // считываем из файла все данные отделов

	while (true)
	{
		int my_choice = User::EnterAccount();                       // вход в приложение

		if (my_choice == 0)
		{
			username = Vectors::SingIn(vect.GetUsers());            //авторизаци€
			if (username != "NULL")
			{
				role = User::FindUser(username, vect.GetUsers())->GetRole();
				if (role == 1) Menu::MenuAdmin(vect, username);
				else Menu::MenuUser(vect, username);
			}
		}
		else if (my_choice == 1)
		{
			Vectors::SingUp(0, vect.GetUsers(), vect);               //регистраци€
		}
		else 
			if(Menu::exitOrNot()) exit(0);                           //выход из приложени€
	}
}

