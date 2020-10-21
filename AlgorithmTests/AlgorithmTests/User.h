#pragma once
#include <string>
#include <ostream>

struct User
{
	const std::string username;
		std::string password;
		User(std::string username, std::string password);
		


};
std::ostream& operator<<(std::ostream& stream, const User& user);


