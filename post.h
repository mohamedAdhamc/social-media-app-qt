#ifndef POST_H
#define POST_H

#include <QWidget>
#include <string>
#include "user.h"
#include <QPixmap>
#include "user.h"

class Post
{
//	Q_OBJECT
	std::set<User*> likes;
	std::string caption;
	std::vector<std::string> comments;
	QPixmap* picture;
	User* poster;


public:
	//post needs picture, pointer to poster
	//toDo: do we need the parent thing ?
	explicit Post(User* poster, QPixmap* picture, std::string caption);

	int getNumLikes () const {return  likes.size();}
	void like(User* user);

	std::vector<std::string> getComments() { return comments; }
	void addComment(std::string comment) { comments.push_back(comment); }

	//toDo: method called bool isVisibleToUser(User* )
	//depending on users post visiblity
	bool isVisibleToUser(User* user);

	//in Qt you cant have the same widget
	//in a couple diffrent layouts.
	//so either we decouple the post data
	//from the post layout (better thing to do).
	//or do this to get around it
	Post* cloneForProfile();

	static std::set<Post*> allPosts;
	static std::set<Post*> myPosts;

	User *getPoster() const;

	QPixmap *getPicture() const;

signals:

};

#endif // POST_H
