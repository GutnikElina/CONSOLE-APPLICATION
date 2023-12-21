#include "menu.h"

User::User(): FIO()
{
	this->SetUser("NULL", "NULL", 0, 0);
}

User::~User() 
{ 
	this->username.clear(); 
	this->password.clear(); 
}

void User::SetUser(std::string username, std::string password, int role, int access)
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

int User::EnterAccount()
{
	std::string main_menu[] = {"      Авторизация   ", "      Регистрация   ", "         Выход    "};
	int x, y;

	while (true)
	{
		system("cls");
		x = 41; y = 8;
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::string line[] = { "+-----------------------------+", 
			"|                             |", "|      ВХОД В ПРИЛОЖЕНИЕ      |",
			"|                             |", "+-----------------------------+" };
		for (int i = 0; i < (int)size(line); i++)
		{
			Console::GoToXY(x, y++);
			std::cout << line[i] << std::endl;
		}
		switch (Menu::ChoiceKeyboard(main_menu, (int)size(main_menu)))
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

std::shared_ptr<User>& User::FindUser(std::string username, std::vector<std::shared_ptr<User>>& vector_user)
{
	for (auto& element : vector_user)
		if (element->GetUsername() == username)
			return element;
}

void User::ShowAccounts(std::vector<std::shared_ptr<User>>& vector_user)
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|                    СПИСОК ВСЕХ АККАУНТОВ                     |" << std::endl;
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|  №  |       Логин        |     Доступ     |       Роль       |" << std::endl;
	std::cout << "+--------------------------------------------------------------+";

	for (int i = 0; i < (int)vector_user.size(); i++)
	{
		std::cout << "\n| " << std::setw(4) << std::left << (i + 1)
			<< "| " << std::setw(19) << std::left << vector_user.at(i)->GetUsername();
		if (vector_user.at(i)->GetAccess())
			std::cout << "| " << std::setw(15) << std::left << "Открытый";
		else
			std::cout << "| " << std::setw(15) << std::left << "Закрытый";
		if (vector_user.at(i)->GetRole())
			std::cout << "| " << std::setw(17) << std::left << "Aдминистратор" << "|";
		else
			std::cout << "| " << std::setw(17) << std::left << "Пользователь" << "|";

		std::cout << "\n+--------------------------------------------------------------+";
	}
}

void User::AddNewAccount(std::vector<std::shared_ptr<User>>& vector_user)
{
	std::shared_ptr<User> user = std::make_shared<User>();
	system("cls");
	Console::GoToXY(50, 13);
	std::string username = Vectors::FindUsername(vector_user);
	Console::GoToXY(50, 15);
	std::string password = Vectors::FindPassword();
	user->SetUsername(username);
	user->SetPassword(password);
	user->SetFullName();
	user->SetAccess(1);
	std::string line[] = { "       Администратор", "       Пользователь" };
	Messages::ChangeRole();

	switch (Menu::ChoiceKeyboard(line, (int)size(line)))
	{
	case 0:
		user->SetRole(1);
		break;
	case 1:
		user->SetRole(0);
		break;
	}

	if (!Menu::confirmOrNot()) return;
	vector_user.push_back(user);
	Vectors::AddAccountInFile(vector_user);
	Messages::SuccessAddAccount();
}


std::shared_ptr<User>& User::FindAccount(std::vector<std::shared_ptr<User>>& vector_user)
{
	while (true)
	{
		ShowAccounts(vector_user);
		std::cout << std::endl << "ВВЕДИТЕ НОМЕР АККАУНТА " << std::endl;
		int number_user = Menu::CheckInt();
		if (number_user <= 0 || number_user > (int)vector_user.size())
			Messages::AcountNotExist();
		else return vector_user.at(number_user-1);
	}
}

void User::DeleteAccount(std::vector<std::shared_ptr<User>>& vector_user, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = FindAccount(vector_user);
	for (int i = 0; i < (int)vector_user.size(); i++)
		if (user->GetUsername() == username) { Messages::ErrorDeleteMyAccount(); return; }

	if (Menu::confirmOrNot())
	{
		for (int i = 0; i < (int)vector_user.size(); i++)
			if (user->GetUsername() == vector_user.at(i)->GetUsername())
				vector_user.erase(vector_user.begin() + i);
		Vectors::AddAccountInFile(vector_user);

		Messages::SuccessDeleteAccount();
		char ch = _getch();
	}
}

void User::ChangeUsername(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user)
{
	char ch;
	std::string new_login;
	Messages::ChangingDataAccount();
	Console::GoToXY(52, 14);
	std::cout << "СТАРЫЙ ЛОГИН";
	Console::GoToXY(55, 15);
	std::cout << user->GetUsername();
	ch = _getch();
	while (true)
	{
		new_login = Vectors::FindUsername(vector_user);
		if (new_login == user->GetUsername())
			Messages::ErrorLoginTheSame();
		else
		{
			user->SetUsername(new_login);
			Vectors::AddAccountInFile(vector_user);
			AbstractClass::UpdatingWindow(std::string("ЛОГИН"));
			return;
		}
	}
}

void User::ChangePassword(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user)
{
	system("cls");
	std::string new_password;
	while (true)
	{
		new_password = Vectors::FindPassword();
		if (new_password == user->GetPassword())
			Messages::ErrorPasswordTheSame();
		else
		{
			user->SetPassword(new_password);
			Vectors::AddAccountInFile(vector_user);
			AbstractClass::UpdatingWindow(std::string("ПАРОЛЬ"));
			return;
		}
	}
}

void User::ChangeAccess(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->GetUsername() == username) { Messages::ErrorChangingAccess();	return; }

	Messages::ChangingDataAccount();
	Console::GoToXY(50, 14);
	std::cout << "  СТАРЫЙ ДОСТУП";
	Console::GoToXY(55, 15);
	std::cout << (user->GetAccess() ? "Открыт" : "Закрыт");
	ch = _getch();
	system("cls");
	Console::GoToXY(48, 12);
	std::string access_question;
	std::cout << ((user->GetAccess() == 1) ? "ЖЕЛАЕТЕ ЗАКРЫТЬ АККАУНТ?" : "ЖЕЛАЕТЕ ОТКРЫТЬ АККАУНТ?");
	std::string line[] = { "              Да", "            Выйти" };
	int choice = Menu::ChoiceKeyboard(line, (int)size(line));
	if (choice == 0) 
	{
		user->SetAccess(!user->GetAccess());
		Vectors::AddAccountInFile(vector_user);
		Messages::ChangingAccess();
	}
	return;
}

void User::ChangeRole(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user, std::string username) 
{
	system("cls");
	if (user->GetUsername() == username) {	Messages::ErrorChangingRole(); return; }

	Messages::ChangingDataAccount();
	Console::GoToXY(50, 14);
	std::cout << "  СТАРАЯ РОЛЬ";
	Console::GoToXY(50, 15);
	std::cout << (user->GetRole() ? "  Aдминистратор" : "  Пользователь");

	char ch = _getch();
	system("cls");
	Console::GoToXY(40, 12);
	std::cout << ((user->GetRole() == 1) ? "ЖЕЛАЕТЕ ИЗМЕНИТЬ РОЛЬ НА ПОЛЬЗОВАТЕЛЯ?" : "ЖЕЛАЕТЕ ИЗМЕНИТЬ РОЛЬ НА АДМИНИСТРАТОРА?");
	std::string line[] = { "            Да", "          Выйти" };

	switch (Menu::ChoiceKeyboard(line, (int)size(line))) 
	{
	case 0:
		user->SetRole((user->GetRole() == 1) ? 0 : 1);
		Vectors::AddAccountInFile(vector_user);
		Messages::ChangingRole();
		break;
	case 1:
		break;
	}
}

void User::ChangeAccount(std::vector<std::shared_ptr<User>>& vector_user, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = FindAccount(vector_user);
	std::string menu[] = { "       Изменить логин", "      Изменить пароль", 
		"       Изменить роль", "      Изменить доступ", "      Вернуться назад" };
	Messages::ChangingDataAccount();
	switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
	{
	case 0:
		system("cls");
		ChangeUsername(vector_user, user);
		break;
	case 1:
		system("cls");
		ChangePassword(vector_user, user);
		break;
	case 2:
		system("cls");
		ChangeRole(vector_user, user, username);
		break;
	case 3:
		system("cls");
		ChangeAccess(vector_user, user, username);
		break;
	case 4:
		return;
	}
}

void User::ChangeMyAccount(std::vector<std::shared_ptr<User>>& vector_user, std::string username)
{
	system("cls");
	std::shared_ptr<User> user = std::make_shared<User>();
	std::string menu[] = { " Изменить логин", " Изменить пароль", " Вернуться назад" };

	for (int i = 0; i < vector_user.size(); i++)
	{
		if (username == vector_user.at(i)->GetUsername())
		{
			user = vector_user.at(i);
			break;
		}
	}
	while (true)
	{
		Messages::ChangingDataAccount();
		switch (Menu::ChoiceKeyboard(menu, (int)size(menu)))
		{
		case 0:
			system("cls");
			ChangeUsername(vector_user, user);
			break;
		case 1:
			system("cls");
			ChangePassword(vector_user, user);
			break;
		case 2:
			return;
		}
	}
}
