#include "menu.h"

//����� ����� ��� �����: username - admin; password - 12345;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"������ ����� ���������, ������ 272301");    // �������� ��������� ���� ����������
	Console::ConsoleCursorVisible(false, 100);                    // ��������� ���������� ������� � �������

	std::string username;
	int role;

	Vectors vect;
	vect.GetVectorUsers();              // ��������� �� ����� ��� ������ ���������
	vect.GetVectorEmployees();          // ��������� �� ����� ��� ������ ����������
	vect.GetVectorDepartment();		    // ��������� �� ����� ��� ������ �������

	while (true)
	{
		int my_choice = User::EnterAccount();                       // ���� � ����������

		if (my_choice == 0)
		{
			username = Vectors::SingIn(vect.GetUsers());            //�����������
			if (username != "NULL")
			{
				role = User::FindUser(username, vect.GetUsers())->GetRole();
				if (role == 1) Menu::MenuAdmin(vect, username);
				else Menu::MenuUser(vect, username);
			}
		}
		else if (my_choice == 1)
		{
			Vectors::SingUp(0, vect.GetUsers(), vect);               //�����������
		}
		else 
			if(Menu::exitOrNot()) exit(0);                           //����� �� ����������
	}
}

