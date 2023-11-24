#include "menu.h"

User::User(): FIO()
{
	this->SetUser("", 0, 0, 0);
}

void User::SetUser(std::string username, unsigned int password, int role, int access)
{
	this->username = username;
	this->password = password;
	this->role = role;
	this->access = access;
}

std::ostream& operator<<(std::ostream& stream, User& user)
{
	stream << user.GetUsername() << " " << user.GetPassword() << " " << user.GetRole() << " " << user.GetAccess()
		<< " " << user.GetSurname() << " " << user.GetName() << " " << user.GetOtch();
	return stream;
}

void User::GetFromFile(std::istream& in) 
{
	in >> this->username >> this->password >> this->role >> this->access;
	FIO::GetFromFile(in);
}

int User::EnterAccount(std::vector<std::shared_ptr<User>> vectorUser)
{
	std::string mainMenu[] = {"      �����������   ", "      �����������   ", "        �����    "};
	int i, x, y;

	while (true)
	{
		system("cls");
		x = 43; y = 8;
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::string line[] = { "+-------------------------+", "|                         |", "|    ���� � ����������    |",
			"|                         |", "+-------------------------+" };

		for (i = 0; i < size(line); i++)
		{
			Console::GoToXY(x, y++);
			std::cout << line[i] << std::endl;
		}

		switch (Menu::ChoiceKeyboard(mainMenu, size(mainMenu)))
		{
		case 0:
			return 0;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return 2;
		}
	}
}

std::shared_ptr<User>& User::FindUser(std::string username, std::vector<std::shared_ptr<User>>& vecUser)
{
	for (auto& element : vecUser)
		if (element->GetUsername() == username)
			return element;
}

void User::ShowAccounts(std::vector<std::shared_ptr<User>>& vectorUser)
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|                    ������ ���� ���������                     |" << std::endl;
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|  �  |       �����        |     ������     |       ����       |" << std::endl;
	std::cout << "+--------------------------------------------------------------+";

	for (int i = 0; unsigned(i) < vectorUser.size(); i++)
	{
		std::cout << "\n| " << std::setw(4) << std::left << (i + 1)
			<< "| " << std::setw(19) << std::left << vectorUser.at(i)->GetUsername();
		if (vectorUser.at(i)->GetAccess())
			std::cout << "| " << std::setw(15) << std::left << "��������";
		else
			std::cout << "| " << std::setw(15) << std::left << "��������";
		if (vectorUser.at(i)->GetRole())
			std::cout << "| " << std::setw(17) << std::left << "A������������" << "|";
		else
			std::cout << "| " << std::setw(17) << std::left << "������������" << "|";

		std::cout << "\n+--------------------------------------------------------------+";
	}
}

void User::AddNewAccount(std::vector<std::shared_ptr<User>>& vectorUser)
{
	std::shared_ptr<User> user = std::make_shared<User>();
	system("cls");
	Console::GoToXY(30, 7);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(30, 8);
	std::cout << "|                                      |";
	Console::GoToXY(30, 9);
	std::cout << "|      ���������� ������ ��������      |";
	Console::GoToXY(30, 10);
	std::cout << "|                                      |";
	Console::GoToXY(30, 11);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(50, 13);
	std::string username = Vectors::FindUsername(vectorUser);
	Console::GoToXY(50, 15);
	std::string password = Vectors::FindPassword();
	user->SetUsername(username);
	user->SetPassword(password);
	user->SetFullName();

	std::string line[] = { "�������������", "������������" };

	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(30, 7);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(30, 8);
	std::cout << "|                                      |";
	Console::GoToXY(30, 9);
	std::cout << "|      ���������� ������ ��������      |";
	Console::GoToXY(30, 10);
	std::cout << "|                                      |";
	Console::GoToXY(30, 11);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(45, 13);
	std::cout << "�������� ����";

	switch (Menu::ChoiceKeyboard(line, size(line)))
	{
	case 0:
		user->SetRole(1);
		break;
	case 1:
		user->SetRole(0);
		break;
	}

	user->SetAccess(1);

	if (!Menu::confirmOrNot())
		return;

	vectorUser.push_back(user);
	Vectors::AddAccountInFile(vectorUser);

	system("cls");
	Console::GoToXY(36, 11);
	std::cout << "+------------------------------------------+";
	Console::GoToXY(36, 12);
	std::cout << "|                                          |";
	Console::GoToXY(36, 13);
	std::cout << "|      ����� ������� ������� ��������      |";
	Console::GoToXY(36, 14);
	std::cout << "|                                          |";
	Console::GoToXY(36, 15);
	std::cout << "+------------------------------------------+";
	char ch = _getch();
}


std::shared_ptr<User>& User::FindAccount(std::vector<std::shared_ptr<User>>& vectorUser)
{
	char ch;
	while (true)
	{
		ShowAccounts(vectorUser);
		std::cout << std::endl << "������� ����� �������� " << std::endl;
		int number_user = Menu::CheckInt();
		if (number_user <= 0 || unsigned(number_user) > vectorUser.size())
		{
			system("cls");
			Console::GoToXY(25, 12);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- �� ��������. ������ �������� �� ����������. ���������� ����� -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
			system("cls");
			continue;
		}
		else return vectorUser.at(number_user-1);		
	}
}


void User::DeleteAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = FindAccount(vectorUser);
	for (int i = 0; i < vectorUser.size(); i++)
		if (user->GetUsername() == username)
		{
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << std::endl << "-!!!- ���������� ������� ���� ������� -!!!- ";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			char ch = _getch();
			return;
		}

	if (Menu::confirmOrNot())
	{
		for (int i = 0; i < vectorUser.size(); i++)
			if (user->GetUsername() == vectorUser.at(i)->GetUsername())
				vectorUser.erase(vectorUser.begin() + i);

		Vectors::AddAccountInFile(vectorUser);

		system("cls");
		Console::GoToXY(35, 11);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(35, 12);
		std::cout << "|                                           |";
		Console::GoToXY(35, 13);
		std::cout << "|      ������ �������� ������� �������      |";
		Console::GoToXY(35, 14);
		std::cout << "|                                           |";
		Console::GoToXY(35, 15);
		std::cout << "+-------------------------------------------+";
		char ch = _getch();
		return;
	}
}

void User::ChangeUsername(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user)
{
	char ch;
	system("cls");
	std::string new_login;

	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|          ��������� ������� ������           |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";

	Console::GoToXY(50, 14);
	std::cout << "������ �����";
	Console::GoToXY(53, 15);
	std::cout << user->GetUsername();
	ch = _getch();
	system("cls");

	while (true)
	{
		system("cls");
		Console::GoToXY(36, 8);
		std::cout << "+---------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                             |";
		Console::GoToXY(36, 10);
		std::cout << "|          ��������� ������� ������           |";
		Console::GoToXY(36, 11);
		std::cout << "|                                             |";
		Console::GoToXY(36, 12);
		std::cout << "+---------------------------------------------+";

		Console::GoToXY(55, 14);
		std::cout << "�������";
		Console::GoToXY(56, 15);
		new_login = Vectors::FindUsername(vectorUser);
		if (new_login == user->GetUsername())
		{
			Console::GoToXY(33, 17);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- ����� ����� ��������� �������. ���������� ����� -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
		}
		else
		{
			user->SetUsername(new_login);
			Vectors::AddAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+-------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                           |";
			Console::GoToXY(35, 13);
			std::cout << "|          ����� ������� ��������           |";
			Console::GoToXY(35, 14);
			std::cout << "|                                           |";
			Console::GoToXY(35, 15);
			std::cout << "+-------------------------------------------+";
			ch = _getch();
			return;
		}
	}
}

void User::ChangePassword(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user)
{
	char ch;
	system("cls");
	std::string new_password;

	while (true)
	{
		system("cls");
		Console::GoToXY(36, 8);
		std::cout << "+---------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                             |";
		Console::GoToXY(36, 10);
		std::cout << "|          ��������� ������� ������           |";
		Console::GoToXY(36, 11);
		std::cout << "|                                             |";
		Console::GoToXY(36, 12);
		std::cout << "+---------------------------------------------+";

		Console::GoToXY(55, 14);
		std::cout << "�������";
		Console::GoToXY(56, 15);
		new_password = Vectors::FindPassword();
		if (new_password == user->GetPassword())
		{
			Console::GoToXY(33, 17);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- ����� ������ ��������� �������. ���������� ����� -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
		}
		else
		{
			user->SetPassword(new_password);
			Vectors::AddAccountInFile(vectorUser);
			system("cls");

			Console::GoToXY(35, 11);
			std::cout << "+-------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                           |";
			Console::GoToXY(35, 13);
			std::cout << "|          ������ ������� ��������          |";
			Console::GoToXY(35, 14);
			std::cout << "|                                           |";
			Console::GoToXY(35, 15);
			std::cout << "+-------------------------------------------+";
			ch = _getch();
			return;
		}
	}
}

void User::ChangeAccess(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->GetUsername() == username)
	{
		Console::GoToXY(40, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ���������� �������� ������ ������ ������� -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|     ��������� ������� ������� ��������      |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";

	Console::GoToXY(50, 14);
	std::cout << "  ������ ������";
	Console::GoToXY(55, 15);
	if (user->GetAccess())
		std::cout << "������";
	else
		std::cout << "������";
	ch = _getch();
	system("cls");

	if (user->GetAccess() == 1)
	{
		Console::GoToXY(45, 13);
		std::cout << "������� ������� �������?";
		std::string line[] = { "  ��", "�����" };

		switch (Menu::ChoiceKeyboard(line, size(line)))
		{
		case 0:
			user->SetAccess(0);
			Vectors::AddAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       ���� �������� ������� ��������       |";
			Console::GoToXY(35, 14);
			std::cout << "|                                            |";
			Console::GoToXY(35, 15);
			std::cout << "+--------------------------------------------+";
			ch = _getch();
			return;
		case 1:
			return;
		}
	}
	else
	{
		Console::GoToXY(45, 13);
		std::cout << "������� ������� �������?";
		std::string line[] = { "  ��", "�����" };

		switch (Menu::ChoiceKeyboard(line, size(line)))
		{
		case 0:
			user->SetAccess(1);
			Vectors::AddAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       ���� �������� ������� ��������       |";
			Console::GoToXY(35, 14);
			std::cout << "|                                            |";
			Console::GoToXY(35, 15);
			std::cout << "+--------------------------------------------+";
			ch = _getch();
			return;
		case 1:
			return;
		}
	}
}



void User::ChangeRole(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->GetUsername() == username)
	{
		Console::GoToXY(40, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- ���������� �������� ���� ������ �������� -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|       ��������� ������ ���� ��������        |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";


	Console::GoToXY(50, 14);
	std::cout << "  ������ ����";
	Console::GoToXY(50, 15);
	if (user->GetRole())
		std::cout << "A������������";
	else
		std::cout << "������������";
	ch = _getch();
	system("cls");

	if (user->GetRole() == 1)
	{
		Console::GoToXY(40, 13);
		std::cout << "������� �������� ���� �� ������������?";
		std::string line[] = { "  ��", "�����" };

		switch (Menu::ChoiceKeyboard(line, size(line)))
		{
		case 0:
			user->SetRole(0);
			Vectors::AddAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       ���� �������� ������� ��������       |";
			Console::GoToXY(35, 14);
			std::cout << "|                                            |";
			Console::GoToXY(35, 15);
			std::cout << "+--------------------------------------------+";
			ch = _getch();
			return;
		case 1:
			return;
		}
	}
	else
	{
		Console::GoToXY(40, 13);
		std::cout << "������� �������� ���� �� ��������������?";
		std::string line[] = { "  ��", "�����" };

		switch (Menu::ChoiceKeyboard(line, size(line)))
		{
		case 0:
			user->SetRole(1);
			Vectors::AddAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       ���� �������� ������� ��������       |";
			Console::GoToXY(35, 14);
			std::cout << "|                                            |";
			Console::GoToXY(35, 15);
			std::cout << "+--------------------------------------------+";
			ch = _getch();
			return;
		case 1:
			return;
		}
	}
}

void User::ChangeAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = FindAccount(vectorUser);

	std::string menu[] = { "   �������� �����", "  �������� ������", "   �������� ����",
		"  �������� ������", "  ��������� �����" };

	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|          ��������� ������ ��������          |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";

	switch (Menu::ChoiceKeyboard(menu, size(menu)))
	{
	case 0:
		system("cls");
		ChangeUsername(vectorUser, user);
		break;
	case 1:
		system("cls");
		ChangePassword(vectorUser, user);
		break;
	case 2:
		system("cls");
		ChangeRole(vectorUser, user, username);
		break;
	case 3:
		system("cls");
		ChangeAccess(vectorUser, user, username);
		break;
	case 4:
		return;
	}
}

void User::ChangeMyAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	system("cls");
	std::shared_ptr<User> user = std::make_shared<User>();
	std::string menu[] = { " �������� �����", " �������� ������", " ��������� �����" };

	for (int i = 0; i < vectorUser.size(); i++)
	{
		if (username == vectorUser.at(i)->GetUsername())
		{
			user = vectorUser.at(i);
			break;
		}
	}

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(36, 8);
		std::cout << "+---------------------------------------------+";
		Console::GoToXY(36, 9);
		std::cout << "|                                             |";
		Console::GoToXY(36, 10);
		std::cout << "|          ��������� ������ ��������          |";
		Console::GoToXY(36, 11);
		std::cout << "|                                             |";
		Console::GoToXY(36, 12);
		std::cout << "+---------------------------------------------+";

		switch (Menu::ChoiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			ChangeUsername(vectorUser, user);
			break;
		case 1:
			system("cls");
			ChangePassword(vectorUser, user);
			break;
		case 2:
			return;
		}
	}
}
