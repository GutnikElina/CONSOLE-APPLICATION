#include "menu.h"

//����� ����� ��� �����: username - admin; password - 12345;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"������ ����� ���������, ������ 272301");    // �������� ��������� ���� ����������
	Console::ConsoleCursorVisible(false, 100);

	Vectors vect{};
	std::string username{};
	int role{};
	bool flag = true;

	vect.getVectorUsers();              // ��������� �� ����� ��� ������ ���������
	vect.getVectorEmployees();          // ��������� �� ����� ��� ������ ����������
	vect.getVectorDepartment();		    // ��������� �� ����� ��� ������ �������

	while (true)
	{
		int myChoice = User::enterAccount(vect.getUsers());        // ���� � ����������

		if (myChoice == 0)
		{
			username = Vectors::singIn(vect.getUsers());           //�����������
			if (username != "null")
			{
				role = User::findUser(username, vect.getUsers())->getRole();
				if (role == 1) Menu::menuAdmin(vect, username);
				else Menu::menuUser(vect, username);
			}
		}
		else if (myChoice == 1)
		{
			Vectors::singUp(0, vect.getUsers(), vect);                     //�����������
		}
		else exit(0);
	}
}

