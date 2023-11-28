#include "menu.h"

void Messages::UpdatingWindow(std::string word)
{
	system("cls");
	Console::GoToXY(36, 11);
	std::cout << "+-------------------------------------------+";
	Console::GoToXY(36, 12);
	std::cout << "|                                           |";
	Console::GoToXY(36, 13);
	std::cout << "|          " << std::setw(6) << std::left << word << " ÓÑÏÅØÍÎ ÎÁÍÎÂËÅÍ          |";
	Console::GoToXY(36, 14);
	std::cout << "|                                           |";
	Console::GoToXY(36, 15);
	std::cout << "+-------------------------------------------+";
	char ch = _getch();
}

void Messages::ErrorChangingAccess()
{
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÍÅÂÎÇÌÎÆÍÎ ÈÇÌÅÍÈÒÜ ÄÎÑÒÓÏ ÑÂÎÅÃÎ ÀÊÊÀÓÍÒ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ChangingAccess()
{
	system("cls");
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|      ÄÎÑÒÓÏ ÀÊÊÀÓÍÒÀ ÓÑÏÅØÍÎ ÈÇÌÅÍÅÍ       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}


void Messages::ChangingRole()
{
	system("cls");
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       ÐÎËÜ ÀÊÊÀÓÍÒÀ ÓÑÏÅØÍÎ ÈÇÌÅÍÅÍÀ       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::ErrorChangingRole()
{
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÍÅÂÎÇÌÎÆÍÎ ÈÇÌÅÍÈÒÜ ÐÎËÜ ÑÂÎÅÃÎ ÀÊÊÀÓÍÒÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return;
}

void Messages::ChangingDataAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+---------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                             |";
	Console::GoToXY(36, 10);
	std::cout << "|          ÈÇÌÅÍÅÍÈÅ ÄÀÍÍÛÕ ÀÊÊÀÓÍÒÀ          |";
	Console::GoToXY(36, 11);
	std::cout << "|                                             |";
	Console::GoToXY(36, 12);
	std::cout << "+---------------------------------------------+";
}

void Messages::ErrorFindDepartment()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÒÀÊÎÃÎ ÍÀÇÂÀÍÈß ÎÒÄÅËÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::DepartmentChangeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+----------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                        |";
	Console::GoToXY(35, 13);
	std::cout << "|           ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ           |";
	Console::GoToXY(35, 14);
	std::cout << "|                                        |";
	Console::GoToXY(35, 15);
	std::cout << "+----------------------------------------+";
	char ch = _getch();
}

void Messages::AddEmployeeWindow()
{
	system("cls");
	Console::GoToXY(36, 8);
	std::cout << "+-----------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                               |";
	Console::GoToXY(36, 10);
	std::cout << "|      ÄÎÁÀÂËÅÍÈÅ ÍÎÂÛÕ ÐÀÁÎÒÍÈÊÎÂ Â ÎÒÄÅË      |";
	Console::GoToXY(36, 11);
	std::cout << "|                                               |";
	Console::GoToXY(36, 12);
	std::cout << "+-----------------------------------------------+";
}

void Messages::ErrorFindEmployee()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÒÀÊÎÃÎ ÐÀÁÎÒÍÈÊÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

void Messages::ConfirmDeleting()
{
	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÏÎÄÒÂÅÐÄÈÒÅ, ×ÒÎ ÂÛ ÕÎÒÈÒÅ ÓÄÀËÈÒÜ ÂÑÞ ÁÀÇÓ ÄÀÍÍÛÕ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::AddDepartmentWindow()
{
	system("cls");
	Console::GoToXY(36, 8);
	std::cout << "+-------------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                           |";
	Console::GoToXY(36, 10);
	std::cout << "|         ÄÎÁÀÂËÅÍÈÅ ÍÎÂÎÃÎ ÎÒÄÅËÀ          |";
	Console::GoToXY(36, 11);
	std::cout << "|                                           |";
	Console::GoToXY(36, 12);
	std::cout << "+-------------------------------------------+";
}

void Messages::ChooseSortWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(36, 8);
	std::cout << "+-----------------------------------------+";
	Console::GoToXY(36, 9);
	std::cout << "|                                         |";
	Console::GoToXY(36, 10);
	std::cout << "|           ÂÛÁÅÐÈÒÅ ÑÎÐÒÈÐÎÂÊÓ           |";
	Console::GoToXY(36, 11);
	std::cout << "|                                         |";
	Console::GoToXY(36, 12);
	std::cout << "+-----------------------------------------+";
}

void Messages::EndSortWindow()
{
	system("cls");
	std::cout << std::endl << std::endl << "------------------------ ÑÎÐÒÈÐÎÂÊÀ ÓÑÏÅØÍÎ ÇÀÂÅÐØÅÍÀ -------------------------------" << std::endl;
	char ch = _getch();
	return;
}

void Messages::ChangingEmployeeData()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 14);
	std::cout << "+------------------------------------------+";
	Console::GoToXY(35, 15);
	std::cout << "|                                          |";
	Console::GoToXY(35, 16);
	std::cout << "|             ÓÑÏÅØÍÎÅ ÈÇÌÅÍÅÍÈÅ           |";
	Console::GoToXY(35, 17);
	std::cout << "|                                          |";
	Console::GoToXY(35, 18);
	std::cout << "+------------------------------------------+";
	char ch = _getch();
}

void Messages::DeleteDBEmployeeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(20, 11);
	std::cout << "+----------------------------------------------------+";
	Console::GoToXY(20, 12);
	std::cout << "|                                                    |";
	Console::GoToXY(20, 13);
	std::cout << "|       ÁÀÇÀ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ ÓÑÏÅØÍÎ ÓÄÀËÅÍÀ       |";
	Console::GoToXY(20, 14);
	std::cout << "|                                                    |";
	Console::GoToXY(20, 15);
	std::cout << "+----------------------------------------------------+";
	char ch = _getch();
}

void Messages::ErrorFindYou()
{
	system("cls");
	Console::GoToXY(35, 13);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÂÛ ÍÅ ÄÎÁÀÂËÅÍÛ Â ÁÀÇÓ ÄÀÍÍÛÕ ÐÀÁÎÒÍÈÊÎÂ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::SuccessAddAccount()
{
	system("cls");
	Console::GoToXY(36, 11);
	std::cout << "+------------------------------------------+";
	Console::GoToXY(36, 12);
	std::cout << "|                                          |";
	Console::GoToXY(36, 13);
	std::cout << "|      ÍÎÂÛÉ ÀÊÊÀÓÍÒ ÓÑÏÅØÍÎ ÄÎÁÀÂËÅÍ      |";
	Console::GoToXY(36, 14);
	std::cout << "|                                          |";
	Console::GoToXY(36, 15);
	std::cout << "+------------------------------------------+";
	char ch = _getch();
}

void Messages::AcountNotExist()
{
	system("cls");
	Console::GoToXY(25, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÂÛ ÎØÈÁËÈÑÜ. ÒÀÊÎÃÎ ÀÊÊÀÓÍÒÀ ÍÅ ÑÓÙÅÑÒÂÓÅÒ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorDeleteMyAccount()
{
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << std::endl << "-!!!- ÍÅÂÎÇÌÎÆÍÎ ÓÄÀËÈÒÜ ÑÂÎÉ ÀÊÊÀÓÍÒ -!!!- ";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	return;
}

void Messages::SuccessDeleteAccount()
{
	system("cls");
	Console::GoToXY(35, 11);
	std::cout << "+-------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                           |";
	Console::GoToXY(35, 13);
	std::cout << "|      ÄÀÍÍÛÅ ÀÊÊÀÓÍÒÀ ÓÑÏÅØÍÎ ÓÄÀËÅÍÛ      |";
	Console::GoToXY(35, 14);
	std::cout << "|                                           |";
	Console::GoToXY(35, 15);
	std::cout << "+-------------------------------------------+";
	char ch = _getch();
	return;
}

void Messages::ErrorLoginTheSame()
{
	Console::GoToXY(33, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << " -!!!- ÍÎÂÛÉ ËÎÃÈÍ ÈÄÅÍÒÈ×ÅÍ ÑÒÀÐÎÌÓ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorPasswordTheSame()
{
	Console::GoToXY(33, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÍÎÂÛÉ ÏÀÐÎËÜ ÈÄÅÍÒÈ×ÅÍ ÑÒÀÐÎÌÓ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorData()
{
	system("cls");
	Console::GoToXY(15, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÒÀÊÎÉ ÄÀÒÛ Â ÁÀÇÅ ÄÀÍÍÛÕ ÍÅ ÑÓÙÅÑÒÂÓÅÒ, ËÈÁÎ ÆÅ ÍÅÂÅÐÍÛÉ ÂÂÎÄ ÄÀÒÛ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

void Messages::ErrorMonth()
{
	system("cls");
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÌÅÑßÖ ÂÂÅÄÅÍ ÍÅÂÅÐÍÎ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorYear()
{
	system("cls");
	Console::GoToXY(40, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÃÎÄ ÂÂÅÄÅÍ ÍÅÂÅÐÍÎ. ÏÎÏÐÎÁÓÉÒÅ ÑÍÎÂÀ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 13);
	std::cout << "[ðàíüøå 2016 ãîäà íåâîçìîæíî çàïèñàòü â áàçó äàííûõ]";
	char ch = _getch();
}

void Messages::ErrorInputHours()
{
	system("cls");
	Console::GoToXY(25, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ÌÎÆÍÎ ÂÂÎÄÈÒÜ ÊÎË-ÂÎ ÎÒÐÀÁÎÒÀÍÍÛÕ ×ÀÑÎÂ ÒÎËÜÊÎ ÇÀ 12 ÌÅÑßÖÅÂ -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}