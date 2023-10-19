#pragma once

#ifndef ACCOUNT_H

#define ACCOUNT_H

#include "fio.h"

class User : public FIO
{
private:

	std::string username{};
	std::string password{};
	int role{};
	int access{};

public:

	User();
	~User() { this->username.clear(); }

	void set(std::string username, unsigned int password, int role, int access);
	void getFromFile(std::istream& in);

	void setUsername(std::string username) { this->username = username; }
	void setPassword(std::string password) { this->password = password; }
	void setRole(int role) { this->role = role; }
	void setAccess(int access) { this->access = access; }

	void setFullName() { this->FIO::set(); }

	std::string getUsername() { return this->username; }
	std::string getPassword() { return this->password; }
	int getRole() { return this->role; }
	int getAccess() { return this->access; }

	static void singUp(int role, std::vector<std::shared_ptr<User>>& vectorUser);
	static int enterAccount(std::vector<std::shared_ptr<User>> vectorUser);
	static std::shared_ptr<User>& findUser(std::string username, std::vector<std::shared_ptr<User>>& vecUser);

	friend std::ostream& operator<<(std::ostream& stream, User& user);
};

#endif