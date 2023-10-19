#include "menu.h"

int Menu::choiceKeyboard(std::string mainMenu[], int size)
{
	int x, y, active_menu = 0;

	while (true)
	{
		
		x = 45, y = 14;

		for (int i = 0; i < size; i++)
		{
			if (i == active_menu)
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else 		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			Console::GoToXY(x, y++);
			std::cout << mainMenu[i] << std::endl;
		}

		char choice = _getch();
		if (choice == -32) choice = _getch(); // Îòëàâëèâàåì ñòðåëî÷êè

		switch (choice)
		{
		case Keyboard::ESCAPE:
			exit(0);

		case Keyboard::UP:
			if (active_menu > 0)
				--active_menu;
			break;

		case Keyboard::DOWN:
			if (active_menu < size - 1)
				++active_menu;
			break;

		case Keyboard::ENTER:
			switch (active_menu)
			{
			case 0:
				return -1;
			case 1:
				return 1;
			case 2:
				return 2;
			case 3:
				return 3;
			case 4:
				return 4;
			case 5:
				return 5;
			}
		}
	}
}

bool exitOrNot()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(40, 12);
	std::cout << "ÂÛ ÄÅÉÑÒÂÈÒÅËÜÍÎ ÕÎÒÈÒÅ ÂÛÉÒÈ?";

	std::string question[] = { " Îòìåíà", "  Âûéòè" };
	int active_menu = 0, x, y;
	char choice;
	bool flag = true;

	if (Menu::choiceKeyboard(question, size(question)))
		return true;
	else return false;

}

bool Menu::continueOrNot()
{
	system("cls");
	Console::GoToXY(30, 8);
	std::cout << "+--------------------------------------------------------+";
	Console::GoToXY(30, 9);
	std::cout << "|                                                        |";
	Console::GoToXY(30, 10);
	std::cout << "|    ÏÎÄÒÂÅÐÄÈÒÅ, ×ÒÎ ÂÛ ÕÎÒÈÒÅ ÑÎÇÄÀÒÜ ÍÎÂÛÉ ÀÊÊÀÓÍÒ    |";
	Console::GoToXY(30, 11);
	std::cout << "|                                                        |";
	Console::GoToXY(30, 12);
	std::cout << "+--------------------------------------------------------+";

	int x, y, option = 0;
	std::string line[] = { "Äà, ïîäòâåðæäàþ", "  Âûéòè" };

	while (true)
	{
		x = 50; y = 14;

		for (int i = 0; i < size(line); i++)
		{
			if (i == option)
				SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			else SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			Console::GoToXY(x, y++);
			std::cout << line[i] << std::endl;
		}

		char choice = _getch();

		if (choice == -32) choice = _getch(); // îòëàâëèâàåì ñòðåëî÷êè

		switch (choice)
		{
		case Keyboard::UP:
			if (option > 0)
				--option;
			break;

		case Keyboard::DOWN:
			if (option < size(line) - 1)
				++option;
			break;

		case Keyboard::ENTER:
			if (option == 0)
				return true;
			else if (option == 1)
				return false;
		}
	}
}

void Menu::menuAdmin(Vectors& vect, std::string username)
{
	int i, x, y;
	std::string adminMenu[] = { "        Óïðàâëÿòü àêêàóíòàìè", "  Ðàáîòàòü c äàííûìè ðàáîòíèêîâ",
		"   Ðàáîòàòü c äàííûìè îòäåëîâ","         Âûéòè èç àêêàóíòà" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		Console::GoToXY(40, 8);
		std::cout << "+---------------------------------------+";
		Console::GoToXY(40, 9);
		std::cout << "|                                       |";
		Console::GoToXY(40, 10);
		std::cout << "|      ÏÐÈÂÅÒÑÒÂÓÅÌ ÂÀÑ, " << std::setw(15) << std::left << username << "|";
		Console::GoToXY(40, 11);
		std::cout << "|                                       |";
		Console::GoToXY(40, 12);
		std::cout << "+---------------------------------------+";

		switch (Menu::choiceKeyboard(adminMenu, size(adminMenu)))
		{
		case 0:
			system("cls");
			//changeAccountMenu(v1, accountSymbol);
			break;
		case 1:
			system("cls");
			//workWithDataMenu(v2);
			break;
		case 2:
			system("cls");
			//workWithDepartmentsMenu(v2, v3);
			break;
		case 3:
			if (exitOrNot())
				return;
			else break;
		}
	}
}

void Menu::menuUser(Vectors& vect, std::string username)
{

}
