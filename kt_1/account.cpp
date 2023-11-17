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

int User::enterAccount(std::vector<std::shared_ptr<User>> vectorUser)
{
	std::string mainMenu[] = {"      юБРНПХГЮЖХЪ   ", "      пЕЦХЯРПЮЖХЪ   ", "        бШУНД    "};
	int i, x, y;

	while (true)
	{
		system("cls");
		x = 43; y = 8;
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::string line[] = { "+-------------------------+", "|                         |", "|    бунд б опхкнфемхе    |",
			"|                         |", "+-------------------------+" };

		for (i = 0; i < size(line); i++)
		{
			Console::GoToXY(x, y++);
			std::cout << line[i] << std::endl;
		}

		switch (Menu::choiceKeyboard(mainMenu, size(mainMenu)))
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

std::shared_ptr<User>& User::findUser(std::string username, std::vector<std::shared_ptr<User>>& vecUser)
{
	for (auto& element : vecUser)
		if (element->getUsername() == username)
			return element;
}

void User::showAccounts(std::vector<std::shared_ptr<User>>& vectorUser)
{
	char ch;
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|                    яохянй бяеу юййюсмрнб                     |" << std::endl;
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|  ╧  |       кНЦХМ        |     дНЯРСО     |       пНКЭ       |" << std::endl;
	std::cout << "+--------------------------------------------------------------+";

	for (int i = 0; unsigned(i) < vectorUser.size(); i++)
	{
		std::cout << "\n| " << std::setw(4) << std::left << (i + 1)
			<< "| " << std::setw(19) << std::left << vectorUser.at(i)->getUsername();
		if (vectorUser.at(i)->getAccess())
			std::cout << "| " << std::setw(15) << std::left << "нРЙПШРШИ";
		else
			std::cout << "| " << std::setw(15) << std::left << "гЮЙПШРШИ";
		if (vectorUser.at(i)->getRole())
			std::cout << "| " << std::setw(17) << std::left << "AДЛХМХЯРПЮРНП" << "|";
		else
			std::cout << "| " << std::setw(17) << std::left << "оНКЭГНБЮРЕКЭ" << "|";

		std::cout << "\n+--------------------------------------------------------------+";
	}
}

void User::addNewAccount(std::vector<std::shared_ptr<User>>& vectorUser)
{
	std::shared_ptr<User> user = std::make_shared<User>();
	system("cls");
	Console::GoToXY(30, 7);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(30, 8);
	std::cout << "|                                      |";
	Console::GoToXY(30, 9);
	std::cout << "|      днаюбкемхе мнбнцн юййюсмрю      |";
	Console::GoToXY(30, 10);
	std::cout << "|                                      |";
	Console::GoToXY(30, 11);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(50, 13);
	std::string username = Vectors::checkUsername(vectorUser);
	Console::GoToXY(50, 15);
	std::string password = Vectors::checkPassword();
	user->setUsername(username);
	user->setPassword(password);
	user->setFullName();

	std::string line[] = { "юДЛХМХЯРПЮРНП", "оНКЭГНБЮРЕКЭ" };

	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(30, 7);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(30, 8);
	std::cout << "|                                      |";
	Console::GoToXY(30, 9);
	std::cout << "|      днаюбкемхе мнбнцн юййюсмрю      |";
	Console::GoToXY(30, 10);
	std::cout << "|                                      |";
	Console::GoToXY(30, 11);
	std::cout << "+--------------------------------------+";
	Console::GoToXY(45, 13);
	std::cout << "бшаепхре пнкэ";

	switch (Menu::choiceKeyboard(line, size(line)))
	{
	case 0:
		user->setRole(1);
		break;
	case 1:
		user->setRole(0);
		break;
	}

	user->setAccess(1);

	if (!Menu::confirmOrNot())
		return;

	vectorUser.push_back(user);
	Vectors::addAccountInFile(vectorUser);

	system("cls");
	Console::GoToXY(36, 11);
	std::cout << "+------------------------------------------+";
	Console::GoToXY(36, 12);
	std::cout << "|                                          |";
	Console::GoToXY(36, 13);
	std::cout << "|      мнбши юййюсмр сяоеьмн днаюбкем      |";
	Console::GoToXY(36, 14);
	std::cout << "|                                          |";
	Console::GoToXY(36, 15);
	std::cout << "+------------------------------------------+";
	char ch = _getch();
}


std::shared_ptr<User>& User::findAccount(std::vector<std::shared_ptr<User>>& vectorUser)
{
	char ch;
	while (true)
	{
		showAccounts(vectorUser);
		std::cout << std::endl << "ббедхре мнлеп юййюсмрю " << std::endl;
		int number_user = Menu::checkInt();
		if (number_user <= 0 || unsigned(number_user) > vectorUser.size())
		{
			system("cls");
			Console::GoToXY(25, 12);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- бш ньхакхяэ. рюйнцн юййюсмрю ме ясыеярбсер. онопнасире ямнбю -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
			system("cls");
			continue;
		}
		else return vectorUser.at(number_user-1);		
	}
}


void User::deleteAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = findAccount(vectorUser);
	for (int i = 0; i < vectorUser.size(); i++)
		if (user->getUsername() == username)
		{
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << std::endl << "-!!!- мебнглнфмн сдюкхрэ ябни юййюсмр -!!!- ";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			char ch = _getch();
			return;
		}

	if (Menu::confirmOrNot())
	{
		for (int i = 0; i < vectorUser.size(); i++)
			if (user->getUsername() == vectorUser.at(i)->getUsername())
				vectorUser.erase(vectorUser.begin() + i);

		Vectors::addAccountInFile(vectorUser);

		system("cls");
		Console::GoToXY(35, 11);
		std::cout << "+-------------------------------------------+";
		Console::GoToXY(35, 12);
		std::cout << "|                                           |";
		Console::GoToXY(35, 13);
		std::cout << "|      дюммше юййюсмрю сяоеьмн сдюкемш      |";
		Console::GoToXY(35, 14);
		std::cout << "|                                           |";
		Console::GoToXY(35, 15);
		std::cout << "+-------------------------------------------+";
		char ch = _getch();
		return;
	}
}

void User::changeUsername(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user)
{
	char ch;
	system("cls");
	std::string new_login;

	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|          хглемемхе ярюпнцн кнцхмю           |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";

	Console::GoToXY(50, 14);
	std::cout << "ярюпши кнцхм";
	Console::GoToXY(53, 15);
	std::cout << user->getUsername();
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
		std::cout << "|          хглемемхе ярюпнцн кнцхмю           |";
		Console::GoToXY(36, 11);
		std::cout << "|                                             |";
		Console::GoToXY(36, 12);
		std::cout << "+---------------------------------------------+";

		Console::GoToXY(55, 14);
		std::cout << "ббедхре";
		Console::GoToXY(56, 15);
		new_login = Vectors::checkUsername(vectorUser);
		if (new_login == user->getUsername())
		{
			Console::GoToXY(33, 17);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- мнбши кнцхм хдемрхвем ярюпнлс. онопнасире ямнбю -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
		}
		else
		{
			user->setUsername(new_login);
			Vectors::addAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+-------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                           |";
			Console::GoToXY(35, 13);
			std::cout << "|          кнцхм сяоеьмн намнбкем           |";
			Console::GoToXY(35, 14);
			std::cout << "|                                           |";
			Console::GoToXY(35, 15);
			std::cout << "+-------------------------------------------+";
			ch = _getch();
			return;
		}
	}
}

void User::changePassword(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user)
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
		std::cout << "|          хглемемхе ярюпнцн оюпнкъ           |";
		Console::GoToXY(36, 11);
		std::cout << "|                                             |";
		Console::GoToXY(36, 12);
		std::cout << "+---------------------------------------------+";

		Console::GoToXY(55, 14);
		std::cout << "ббедхре";
		Console::GoToXY(56, 15);
		new_password = Vectors::checkPassword();
		if (new_password == user->getPassword())
		{
			Console::GoToXY(33, 17);
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "-!!!- мнбши оюпнкэ хдемрхвем ярюпнлс. онопнасире ямнбю -!!!-";
			SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			ch = _getch();
		}
		else
		{
			user->setPassword(new_password);
			Vectors::addAccountInFile(vectorUser);
			system("cls");

			Console::GoToXY(35, 11);
			std::cout << "+-------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                           |";
			Console::GoToXY(35, 13);
			std::cout << "|          оюпнкэ сяоеьмн намнбкем          |";
			Console::GoToXY(35, 14);
			std::cout << "|                                           |";
			Console::GoToXY(35, 15);
			std::cout << "+-------------------------------------------+";
			ch = _getch();
			return;
		}
	}
}

void User::changeAccess(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->getUsername() == username)
	{
		Console::GoToXY(40, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- мебнглнфмн хглемхрэ днярсо ябнецн юййюсмр -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|     хглемемхе ярюпнцн днярсою юййюсмрю      |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";

	Console::GoToXY(50, 14);
	std::cout << "  ярюпши днярсо";
	Console::GoToXY(55, 15);
	if (user->getAccess())
		std::cout << "нРЙПШР";
	else
		std::cout << "гЮЙПШР";
	ch = _getch();
	system("cls");

	if (user->getAccess() == 1)
	{
		Console::GoToXY(45, 13);
		std::cout << "фекюере гюйпшрэ юййюсмр?";
		std::string line[] = { "  дЮ", "бШИРХ" };

		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			user->setAccess(0);
			Vectors::addAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       пнкэ юййюсмрю сяоеьмн хглемемю       |";
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
		std::cout << "фекюере нрйпшрэ юййюсмр?";
		std::string line[] = { "  дЮ", "бШИРХ" };

		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			user->setAccess(1);
			Vectors::addAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       пнкэ юййюсмрю сяоеьмн хглемемю       |";
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



void User::changeRole(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->getUsername() == username)
	{
		Console::GoToXY(40, 12);
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "-!!!- мебнглнфмн хглемхрэ пнкэ ябнецн юййюсмрю -!!!-";
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ch = _getch();
		return;
	}

	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|       хглемемхе ярюпни пнкх юййюсмрю        |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";


	Console::GoToXY(50, 14);
	std::cout << "  ярюпюъ пнкэ";
	Console::GoToXY(50, 15);
	if (user->getRole())
		std::cout << "AДЛХМХЯРПЮРНП";
	else
		std::cout << "оНКЭГНБЮРЕКЭ";
	ch = _getch();
	system("cls");

	if (user->getRole() == 1)
	{
		Console::GoToXY(40, 13);
		std::cout << "фекюере хглемхрэ пнкэ мю онкэгнбюрекъ?";
		std::string line[] = { "  дЮ", "бШИРХ" };

		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			user->setRole(0);
			Vectors::addAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       пнкэ юййюсмрю сяоеьмн хглемемю       |";
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
		std::cout << "фекюере хглемхрэ пнкэ мю юдлхмхярпюрнпю?";
		std::string line[] = { "  дЮ", "бШИРХ" };

		switch (Menu::choiceKeyboard(line, size(line)))
		{
		case 0:
			user->setRole(1);
			Vectors::addAccountInFile(vectorUser);
			system("cls");
			Console::GoToXY(35, 11);
			std::cout << "+--------------------------------------------+";
			Console::GoToXY(35, 12);
			std::cout << "|                                            |";
			Console::GoToXY(35, 13);
			std::cout << "|       пнкэ юййюсмрю сяоеьмн хглемемю       |";
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

void User::changeAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = findAccount(vectorUser);

	std::string menu[] = { "   хГЛЕМХРЭ КНЦХМ", "  хГЛЕМХРЭ ОЮПНКЭ", "   хГЛЕМХРЭ ПНКЭ",
		"  хГЛЕМХРЭ ДНЯРСО", "  бЕПМСРЭЯЪ МЮГЮД" };

	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|          хглемемхе дюммшу юййюсмрю          |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";

	switch (Menu::choiceKeyboard(menu, size(menu)))
	{
	case 0:
		system("cls");
		changeUsername(vectorUser, user);
		break;
	case 1:
		system("cls");
		changePassword(vectorUser, user);
		break;
	case 2:
		system("cls");
		changeRole(vectorUser, user, username);
		break;
	case 3:
		system("cls");
		changeAccess(vectorUser, user, username);
		break;
	case 4:
		return;
	}
}

void User::changeMyAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username)
{
	system("cls");
	std::shared_ptr<User> user = std::make_shared<User>();
	std::string menu[] = { " хГЛЕМХРЭ КНЦХМ", " хГЛЕМХРЭ ОЮПНКЭ", " бЕПМСРЭЯЪ МЮГЮД" };

	for (int i = 0; i < vectorUser.size(); i++)
	{
		if (username == vectorUser.at(i)->getUsername())
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
		std::cout << "|          хглемемхе дюммшу юййюсмрю          |";
		Console::GoToXY(36, 11);
		std::cout << "|                                             |";
		Console::GoToXY(36, 12);
		std::cout << "+---------------------------------------------+";

		switch (Menu::choiceKeyboard(menu, size(menu)))
		{
		case 0:
			system("cls");
			changeUsername(vectorUser, user);
			break;
		case 1:
			system("cls");
			changePassword(vectorUser, user);
			break;
		case 2:
			return;
		}
	}
}
