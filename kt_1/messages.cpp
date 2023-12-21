#include "menu.h"

void Messages::FileNotOpened()
{
	system("cls");
	Console::GoToXY(50, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ньхайю нрйпшрхъ тюикю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	exit(1);
}

void Messages::EmptyDatabase()
{
	system("cls");
	Console::GoToXY(45, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- аюгю дюммшу осярю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorChangingAccess()
{
	Console::GoToXY(38, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- мебнглнфмн хглемхрэ днярсо ябнецн юййюсмр -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorChangingRole()
{
	Console::GoToXY(38, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- мебнглнфмн хглемхрэ пнкэ ябнецн юййюсмрю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorFindDepartment()
{
	system("cls");
	Console::GoToXY(30, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- рюйнцн мюгбюмхъ нрдекю ме ясыеярбсер. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorFindEmployee()
{
	system("cls");
	Console::GoToXY(30, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- рюйнцн пюанрмхйю ме ясыеярбсер. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

void Messages::ConfirmDeleting()
{
	system("cls");
	Console::GoToXY(30, 10);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- ондрбепдхре, врн бш унрхре сдюкхрэ бяч аюгс дюммшу -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::ErrorFindYou()
{
	system("cls");
	Console::GoToXY(35, 13);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- бш ме днаюбкемш б аюгс дюммшу пюанрмхйнб -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Messages::AcountNotExist()
{
	system("cls");
	Console::GoToXY(25, 13);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- бш ньхакхяэ. рюйнцн юййюсмрю ме ясыеярбсер. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorDeleteMyAccount()
{
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << std::endl << "-!!!- мебнглнфмн сдюкхрэ ябни юййюсмр -!!!- ";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorLoginTheSame()
{
	Console::GoToXY(30, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << " -!!!- мнбши кнцхм хдемрхвем ярюпнлс. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorPasswordTheSame()
{
	Console::GoToXY(30, 17);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- мнбши оюпнкэ хдемрхвем ярюпнлс. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorData()
{
	system("cls");
	Console::GoToXY(15, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- рюйни дюрш б аюге дюммшу ме ясыеярбсер, кхан фе мебепмши ббнд дюрш. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
	system("cls");
}

void Messages::ErrorMonth()
{
	system("cls");
	Console::GoToXY(35, 14);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- леяъж ббедем мебепмн. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ErrorYear()
{
	system("cls");
	Console::GoToXY(38, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- цнд ббедем мебепмн. онопнасире ямнбю -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 13);
	std::cout << "[ < 2016 ХКХ > 2023 МЕБНГЛНФМН ГЮОХЯЮРЭ Б АЮГС ДЮММШУ]";
	char ch = _getch();
}

void Messages::ErrorInputHours()
{
	system("cls");
	Console::GoToXY(25, 12);
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "-!!!- лнфмн ббндхрэ йнк-бн нрпюанрюммшу вюянб рнкэйн гю 12 леяъжеб -!!!-";
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	char ch = _getch();
}

void Messages::ChangingAccess()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|      днярсо юййюсмрю сяоеьмн хглемем       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessAddDepartment()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|        мнбши нрдек сяоеьмн днаюбкем        |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessAddEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|      мнбши пюанрмхй сяоеьмн днаюбкем       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessDeleteDepartment()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|            нрдек сяоеьмн сдюкем            |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessDeleteEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|          пюанрмхй сяоеьмн сдюкем           |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::ChangingRole()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
	char ch = _getch();
}

void Messages::DepartmentChangeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(32, 11);
	std::cout << "+-----------------------------------------------+";
	Console::GoToXY(32, 12);
	std::cout << "|                                               |";
	Console::GoToXY(32, 13);
	std::cout << "|      аюгю дюммшу нрдекнб сяоеьмн сдюкемю      |";
	Console::GoToXY(32, 14);
	std::cout << "|                                               |";
	Console::GoToXY(32, 15);
	std::cout << "+-----------------------------------------------+";
	char ch = _getch();
}

void Messages::EndSortWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|        янпрхпнбйю сяоеьмн гюбепьемю        |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15); 
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::ChangingEmployeeData()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|             сяоеьмне хглемемхе             |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::DeleteDBEmployeeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(31, 11);
	std::cout << "+------------------------------------------------+";
	Console::GoToXY(31, 12);
	std::cout << "|                                                |";
	Console::GoToXY(31, 13);
	std::cout << "|     аюгю дюммшу пюанрмхйнб сяоеьмн сдюкемю     |";
	Console::GoToXY(31, 14);
	std::cout << "|                                                |";
	Console::GoToXY(31, 15);
	std::cout << "+------------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessAddAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       мнбши юййюсмр сяоеьмн днаюбкем       |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15); 
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::SuccessDeleteAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(35, 11);
	std::cout << "+--------------------------------------------+";
	Console::GoToXY(35, 12);
	std::cout << "|                                            |";
	Console::GoToXY(35, 13);
	std::cout << "|       дюммше юййюсмрю сяоеьмн сдюкемш      |";
	Console::GoToXY(35, 14);
	std::cout << "|                                            |";
	Console::GoToXY(35, 15);
	std::cout << "+--------------------------------------------+";
	char ch = _getch();
}

void Messages::AccountManagement()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|         сопюбкемхе юййюсмрюлх         |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChangeRole()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|            бшаепхре  пнкэ             |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}


void Messages::WorkWithDataEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|      пюанрю я дюммшлх пюанрмхйнб      |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::DataProcessing()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|           напюанрйю дюммшу            |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::FindingEmployee()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|           онхяй пюанрмхйю             |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::SortingWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|          янпрхпнбйю пюанрмхйнб        |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::EditingDataWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|         педюйрхпнбюмхе дюммшу         |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::AddEmployeeWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|  днаюбкемхе мнбшу пюанрмхйнб б нрдек  |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::AddDepartmentWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|       днаюбкемхе мнбнцн нрдекю        |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChooseSortWindow()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|          бшаепхре янпрхпнбйс          |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChangingDataAccount()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|       хглемемхе дюммшу юййюсмрю       |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}

void Messages::ChangingDataDepartment()
{
	system("cls");
	SetConsoleTextAttribute(Console::hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	Console::GoToXY(38, 8);
	std::cout << "+---------------------------------------+";
	Console::GoToXY(38, 9);
	std::cout << "|                                       |";
	Console::GoToXY(38, 10);
	std::cout << "|        хглемемхе дюммшу нрдекю        |";
	Console::GoToXY(38, 11);
	std::cout << "|                                       |";
	Console::GoToXY(38, 12);
	std::cout << "+---------------------------------------+";
}