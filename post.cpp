#include "post.h"

std::set<Post*> Post::allPosts;
std::set<Post*> Post::myPosts;


User *Post::getPoster() const
{
	return poster;
}

QPixmap *Post::getPicture() const
{
	return picture;
}

Post::Post(User* poster, QPixmap* picture, std::string caption)
{
	this->poster = poster;
	this->picture = picture;
	this->caption = caption;


	allPosts.insert(this);
}

void Post::like(User *user)
{
	//if user is not in like set then add idk
	if (!likes.count(user))
		likes.insert(user);
}

bool Post::isVisibleToUser(User *user)
{
	if (poster->postVisibility == PostVisibility::ALL)
		return true;
	//check if user is a friend
	if (poster->getfollowers().find(user) != poster->getfollowers().end())
		return true;

	return false;
}

