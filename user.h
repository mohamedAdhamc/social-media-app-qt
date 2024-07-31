#ifndef USER_H
#define USER_H

#include<string>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>
#include <QPixmap>

enum class PostVisibility {
	FOLLOWERS_ONLY,
	ALL
};

enum class AddVisibility {
	FOLLOWERS_ONLY,
	ALL
};


class User
{
	std::string userName;
	std::string password;

	QPixmap* profilePic;

	std::map<std::string, std::vector<std::string>> messages; //username of sender is key

	std::set<User*> followers;
	std::set<User*> following;

	void recieveMessage(std::string sender, std::string message);

public:
	PostVisibility postVisibility;
	AddVisibility addVisibility;

	User(std::string userName, std::string password);

	void addProfilePic (QPixmap* pic) { profilePic = pic; }

	void addFollower(User* friendo) { followers.insert(friendo); }
	void follow(User* user) { following.insert(user); }

	std::string getUserName() { return userName; }

	std::set<User*> getfollowers() { return followers; }

	std::set<User*> getfollowing() { return following; }


	std::set<User*> getAllUsers() { return allUsers; }

	static User* getUserFromUsername (std::string username);

	void sendMessage(std::string reciever, std::string message);

	std::vector<std::string> getMessages(User* user);

	std::vector<std::string> getNamesOfMessagees();

	static std::set<User*> allUsers;
	static std::unordered_map<std::string, std::string> passMap;

	QPixmap *getProfilePic() const;
};

#endif // USER_H
