#include "User.h"
#include <ostream>

User::User(std::string username, std::string password) : username(username), password(password){}

std::ostream& operator<<(std::ostream& stream, const User& user)
{
	stream << user.username << " : " << user.password << std::endl;
	return stream;
}
