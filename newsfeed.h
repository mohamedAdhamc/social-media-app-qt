#ifndef NEWSFEED_H
#define NEWSFEED_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include "post.h"
#include "user.h"

class NewsFeed : public QWidget
{
private:
	QVBoxLayout* vbox;
	//set from createFeedForUser
	//must be called on user login
	User* currentUser;

	bool isPostInFeed(Post* post);

	Q_OBJECT
public:
	explicit NewsFeed(QWidget *parent = nullptr);

	void addPost(Post *post);

	void deleteAllPosts();

	void createFeedForUser(User* user);

	void createProfileFeed(User *user);

	//define just basically go over posts again
	void refreshNewsFeed();
	void refreshProfileFeed();

signals:

};

#endif // NEWSFEED_H
