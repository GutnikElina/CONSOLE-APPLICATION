#pragma once

#ifndef ACCOUNT_H

#define ACCOUNT_H

#include "fio.h"

class User : public FIO
{
private:

	std::string username;
	std::string password;
	int role;
	int access;

public:

	User();
	~User() { this->username.clear(); this->password.clear(); }

	void SetUser(std::string username, unsigned int password, int role, int access);
	void SetUsername(std::string username) { this->username = username; }
	void SetPassword(std::string password) { this->password = password; }
	void SetRole(int role) { this->role = role; }
	void SetAccess(int access) { this->access = access; }

	std::string GetUsername() { return this->username; }
	std::string GetPassword() { return this->password; }
	int GetRole() { return this->role; }
	int GetAccess() { return this->access; }

	static int EnterAccount(std::vector<std::shared_ptr<User>> vectorUser);
	static std::shared_ptr<User>& FindUser(std::string username, std::vector<std::shared_ptr<User>>& vecUser);
	static void ShowAccounts(std::vector<std::shared_ptr<User>>& vectorUser);
	static void AddNewAccount(std::vector<std::shared_ptr<User>>& vectorUser);
	static void DeleteAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username);
	static std::shared_ptr<User>& FindAccount(std::vector<std::shared_ptr<User>>& vectorUser);
	static void ChangeAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string username);
	static void ChangeUsername(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user);
	static void ChangePassword(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user);
	static void ChangeRole(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username);
	static void ChangeAccess(std::vector<std::shared_ptr<User>>& vectorUser, std::shared_ptr<User>& user, std::string username);
	static void ChangeMyAccount(std::vector<std::shared_ptr<User>>& vectorUser, std::string  username);

	void GetFromFile(std::istream& in) override;

	friend std::ostream& operator<<(std::ostream& stream, User& user);
};

#endif