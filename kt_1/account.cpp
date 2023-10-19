#include "menu.h"

User::User(): FIO()
{
	this->set("NULL", 0, 0, 0);
}

void User::set(std::string username, unsigned int password, int role, int access)
{
	this->username = username;
	this->password = password;
	this->role = role;
	this->access = access;
}

std::ostream& operator<<(std::ostream& stream, User& user)
{
	stream << user.getUsername() << " " << user.getPassword() << " " << user.getRole() << " " << user.getAccess()
		<< " " << user.getSurname() << " " << user.getName() << " " << user.getOtch();
	return stream;
}

void User::getFromFile(std::istream& in)
{
	in >> this->username >> this->password >> this->role >> this->access;
	FIO::getFromFile(in);
}


void User::singUp(int role, std::vector<std::shared_ptr<User>>& vectorUser)
{
	std::shared_ptr<User> user = std::make_shared<User>();
	user->setRole(role);
	user->setAccess(1);
	system("cls");

	user->setUsername(Vectors::checkUsername(vectorUser));
	user->setPassword(Vectors::checkPassword());

	user->setFullName();

	if (Menu::continueOrNot())
		vectorUser.push_back(user);
}

int User::enterAccount(std::vector<std::shared_ptr<User>> vectorUser)
{
	std::string mainMenu[] = {"      Авторизация   ", "      Регистрация   ", "        Выход    "};
	int i, x, y;

	while (true)
	{
		system("cls");
		x = 43; y = 8;
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::string line[] = { "+-------------------------+", "|                         |", "|    ВХОД В ПРИЛОЖЕНИЕ    |",
			"|                         |", "+-------------------------+" };

		for (i = 0; i < size(line); i++)
		{
			Console::GoToXY(x, y++);
			std::cout << line[i] << std::endl;
		}

		switch (Menu::choiceKeyboard(mainMenu, size(mainMenu)))
		{
		case 0:
			return -1;
		case 1:
			return 1;
		case 2:
			return 2;
		}
	}
}

std::shared_ptr<User>& User::findUser(std::string username, std::vector<std::shared_ptr<User>>& vecUser)
{
	for (auto& element : vecUser)
		if (element->getUsername() == username)
			return element;
}