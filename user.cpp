#include "user.h"
#include <QMessageBox>
#include <iostream>

//STATIC MEMBERS//
std::set<User*> User::allUsers;
std::unordered_map<std::string, std::string> User::passMap;

//class definitions//

QPixmap* User::getProfilePic() const
{
	return profilePic;
}

User::User(std::string userName, std::string password)
	:
	  postVisibility (PostVisibility::ALL),
	  addVisibility (AddVisibility::ALL)
{
	this->userName = userName;
	this->password = password;

	profilePic = nullptr;

	allUsers.insert(this);
	passMap[userName] = password;
}

User* User::getUserFromUsername(std::string username)
{
	for (User* user : User::allUsers)
		if (user->getUserName() == username)
			return user;
	return nullptr;
}

void User::recieveMessage(std::string sender, std::string message)
{
	messages[sender].push_back(message);
}

void User::sendMessage(std::string reciever, std::string message)
{
	//get the user to whom we are sending the message
	User* Ureciever = User::getUserFromUsername(reciever);
	if (Ureciever == nullptr){
		QMessageBox msgBox(QMessageBox::Information, "Error", "User doesn't exist");
		msgBox.exec();
		return;
	}
	//so that us have a copy
	messages[reciever].push_back(message);

	//so that the reciever has a copy
	Ureciever->recieveMessage(userName, message);
}

std::vector<std::string> User::getMessages(User *user)
{
	return messages[user->getUserName()];
}

std::vector<std::string> User::getNamesOfMessagees()
{
	std::vector<std::string> ret;
	for (auto iter: messages)
		ret.push_back(iter.first);

	return ret;
}
