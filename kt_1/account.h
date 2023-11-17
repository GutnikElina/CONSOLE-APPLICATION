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
	void getFromFile(std::istream& in) override;

	void setUsername(std::string username) { this->username = username; }
	void setPassword(std::string password) { this->password = password; }
	void setRole(int role) { this->role = role; }
	void setAccess(int access) { this->access = access; }

	void setFullName() { this->FIO::set(); }

	std::string getUsername() { return this->username; }
	std::string getPassword() { return this->password; }
	int getRole() { return this->role; }
	int getAccess() { return this->access; }

	static int enterAccount(std::vector<std::shared_ptr<User>> vectorUser);
	static std::shared_ptr<User>& findUser(std::string username, std::vector<std::shared_ptr<User>>& vecUser);
	static void showAccounts(std::vector<std::shared_ptr<User>>& vectorUser);
	static void addNewAccount(std::vector<std::shared_ptr<User>>& vectorUser);
	static void deleteAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username);
	static std::shared_ptr<User>& findAccount(std::vector<std::shared_ptr<User>>& vectorUser);
	static void changeAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username);
	static void changeUsername(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user);
	static void changePassword(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user);
	static void changeRole(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username);
	static void changeAccess(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username);
	static void changeMyAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string  username);

	friend std::ostream& operator<<(std::ostream& stream, User& user);
};

#endif