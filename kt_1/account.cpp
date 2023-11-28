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
	std::string main_menu[] = {"      Àâòîğèçàöèÿ   ", "      Ğåãèñòğàöèÿ   ", "        Âûõîä    "};
	int x, y;

	while (true)
	{
		system("cls");
		x = 43; y = 8;
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::string line[] = { "+-------------------------+", "|                         |", "|    ÂÕÎÄ Â ÏĞÈËÎÆÅÍÈÅ    |",
			"|                         |", "+-------------------------+" };

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
	std::cout << "|                    ÑÏÈÑÎÊ ÂÑÅÕ ÀÊÊÀÓÍÒÎÂ                     |" << std::endl;
	std::cout << "+--------------------------------------------------------------+" << std::endl;
	std::cout << "|  ¹  |       Ëîãèí        |     Äîñòóï     |       Ğîëü       |" << std::endl;
	std::cout << "+--------------------------------------------------------------+";

	for (int i = 0; i < (int)vector_user.size(); i++)
	{
		std::cout << "\n| " << std::setw(4) << std::left << (i + 1)
			<< "| " << std::setw(19) << std::left << vector_user.at(i)->GetUsername();
		if (vector_user.at(i)->GetAccess())
			std::cout << "| " << std::setw(15) << std::left << "Îòêğûòûé";
		else
			std::cout << "| " << std::setw(15) << std::left << "Çàêğûòûé";
		if (vector_user.at(i)->GetRole())
			std::cout << "| " << std::setw(17) << std::left << "Aäìèíèñòğàòîğ" << "|";
		else
			std::cout << "| " << std::setw(17) << std::left << "Ïîëüçîâàòåëü" << "|";

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
	std::string line[] = { "Àäìèíèñòğàòîğ", "Ïîëüçîâàòåëü" };
	system("cls");
	Console::GoToXY(45, 13);
	std::cout << "ÂÛÁÅĞÈÒÅ ĞÎËÜ";
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
		std::cout << std::endl << "ÂÂÅÄÈÒÅ ÍÎÌÅĞ ÀÊÊÀÓÍÒÀ " << std::endl;
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
		if (user->GetUsername() == username)
			Messages::ErrorDeleteMyAccount();

	if (Menu::confirmOrNot())
	{
		for (int i = 0; i < (int)vector_user.size(); i++)
			if (user->GetUsername() == vector_user.at(i)->GetUsername())
				vector_user.erase(vector_user.begin() + i);
		Vectors::AddAccountInFile(vector_user);

		Messages::SuccessDeleteAccount();
	}
}

void User::ChangeUsername(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user)
{
	char ch;
	std::string new_login, word = "ËÎÃÈÍ";
	Messages::ChangingDataAccount();
	Console::GoToXY(50, 15);
	std::cout << "ÑÒÀĞÛÉ ËÎÃÈÍ";
	Console::GoToXY(53, 16);
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
			Messages::UpdatingWindow(word);
			return;
		}
	}
}

void User::ChangePassword(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user)
{
	system("cls");
	std::string new_password, word = "ÏÀĞÎËÜ";
	while (true)
	{
		new_password = Vectors::FindPassword();
		if (new_password == user->GetPassword())
			Messages::ErrorPasswordTheSame();
		else
		{
			user->SetPassword(new_password);
			Vectors::AddAccountInFile(vector_user);
			Messages::UpdatingWindow(word);
			return;
		}
	}
}

void User::ChangeAccess(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->GetUsername() == username) { Messages::ErrorChangingAccess(); return; }

	Messages::ChangingDataAccount();
	Console::GoToXY(50, 14);
	std::cout << "  ÑÒÀĞÛÉ ÄÎÑÒÓÏ";
	Console::GoToXY(55, 15);
	if (user->GetAccess())
		std::cout << "Îòêğûò";
	else
		std::cout << "Çàêğûò";
	ch = _getch();
	system("cls");

	if (user->GetAccess() == 1)
	{
		Console::GoToXY(45, 13);
		std::cout << "ÆÅËÀÅÒÅ ÇÀÊĞÛÒÜ ÀÊÊÀÓÍÒ?";
		std::string line[] = { "  Äà", "Âûéòè" };
		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			user->SetAccess(0);
			Vectors::AddAccountInFile(vector_user);
			Messages::ChangingAccess();
			return;
		case 1:
			return;
		}
	}
	else
	{
		Console::GoToXY(45, 13);
		std::cout << "ÆÅËÀÅÒÅ ÎÒÊĞÛÒÜ ÀÊÊÀÓÍÒ?";
		std::string line[] = { "  Äà", "Âûéòè" };

		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			user->SetAccess(1);
			Vectors::AddAccountInFile(vector_user);
			Messages::ChangingAccess();
			return;
		case 1:
			return;
		}
	}
}

void User::ChangeRole(std::vector<std::shared_ptr<User>>& vector_user, std::shared_ptr<User>& user, std::string username)
{
	system("cls");
	char ch;
	if (user->GetUsername() == username) Messages::ErrorChangingRole();
	Messages::ChangingDataAccount();
	Console::GoToXY(50, 14);
	std::cout << "  ÑÒÀĞÀß ĞÎËÜ";
	Console::GoToXY(50, 15);
	if (user->GetRole())
		std::cout << "Aäìèíèñòğàòîğ";
	else
		std::cout << "Ïîëüçîâàòåëü";
	ch = _getch();
	system("cls");
	if (user->GetRole() == 1)
	{
		Console::GoToXY(40, 13);
		std::cout << "ÆÅËÀÅÒÅ ÈÇÌÅÍÈÒÜ ĞÎËÜ ÍÀ ÏÎËÜÇÎÂÀÒÅËß?";
		std::string line[] = { "  Äà", "Âûéòè" };

		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			user->SetRole(0);
			Vectors::AddAccountInFile(vector_user);
			Messages::ChangingRole();
			return;
		case 1:
			return;
		}
	}
	else
	{
		Console::GoToXY(40, 13);
		std::cout << "ÆÅËÀÅÒÅ ÈÇÌÅÍÈÒÜ ĞÎËÜ ÍÀ ÀÄÌÈÍÈÑÒĞÀÒÎĞÀ?";
		std::string line[] = { "  Äà", "Âûéòè" };

		switch (Menu::ChoiceKeyboard(line, (int)size(line)))
		{
		case 0:
			user->SetRole(1);
			Vectors::AddAccountInFile(vector_user);
			Messages::ChangingRole();
			return;
		case 1:
			return;
		}
	}
}

void User::ChangeAccount(std::vector<std::shared_ptr<User>>& vector_user, std::string username)
{
	system("cls");
	std::shared_ptr<User>& user = FindAccount(vector_user);
	std::string menu[] = { "   Èçìåíèòü ëîãèí", "  Èçìåíèòü ïàğîëü", "   Èçìåíèòü ğîëü",
		"  Èçìåíèòü äîñòóï", "  Âåğíóòüñÿ íàçàä" };
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
	std::string menu[] = { " Èçìåíèòü ëîãèí", " Èçìåíèòü ïàğîëü", " Âåğíóòüñÿ íàçàä" };

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
