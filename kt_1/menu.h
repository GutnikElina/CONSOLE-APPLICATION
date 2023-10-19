#pragma once

#ifndef MENU_H

#define MENU_H

#include "vectors.h"

class Menu
{
public:

	static int choiceKeyboard(std::string mainMenu[], int size);
	static bool continueOrNot();
	static void menuAdmin(Vectors& vect, std::string username);
	static void menuUser(Vectors& vect, std::string username);
};

#endif