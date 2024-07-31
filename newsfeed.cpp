#include "newsfeed.h"
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QApplication>
#include <iostream>
#include <string>
#include "user.h"
#include "postwidget.h"


bool NewsFeed::isPostInFeed(Post *post)
{
	for (int i = 0; i < vbox->count(); ++i) {
		QLayoutItem* item = vbox->itemAt(i);
		QWidget* layoutWidget = item->widget();
		//try to cast to PostWidget
		if (PostWidget* postWidget = dynamic_cast<PostWidget*>(layoutWidget)){
			if (postWidget->getPostData() == post) {
				return true;
			}
		}
	}
	return false;
}

NewsFeed::NewsFeed(QWidget *parent)
	: QWidget{parent}
{
	//init vbox which will contain the posts in this newsfeed
	vbox = new QVBoxLayout(this);

//	addPost(new Post(new User("momo", "3"), new QPixmap(*initialPosts[0]), "my first post"));
//	addPost(new Post(new User("desert_fox", ""), new QPixmap(*initialPosts[1]), "hmm"));
//	addPost(new Post(new User("night_warrior22", ""), new QPixmap(*initialPosts[2]), "funny"));
}

//real bad thing just for the sake of demo
int i = 1;

void NewsFeed::addPost(Post* post)
{
	//ToDO: use the below code as a template for creating
	//a post class and then this method would take a post as arg

	//post: vbox containing
	//		    	pic
	//hbox:	   like   comment
//	QWidget* post = new QWidget;
//	QVBoxLayout* postLayout = new QVBoxLayout(post);

//	// Create the picture label and set the image
//	QLabel* pictureLabel = new QLabel;
//	std::string postPath = "://resources/post" + std::to_string(i++) ;
//	QPixmap picturePixmap(QString::fromStdString(postPath));
//	pictureLabel->setPixmap(picturePixmap);
//	//set a max size for the label
//	pictureLabel->setMaximumSize(400 , 350);
//	pictureLabel->setScaledContents(true);

//	// Create the QHBoxLayout for the second element
//	QHBoxLayout* hboxLayout = new QHBoxLayout;
//	// Add widgets to the QHBoxLayout
//	QPushButton* likeButton = new QPushButton;
//	QPushButton* commentButton = new QPushButton;
//	likeButton->setMaximumWidth(100);
//	QIcon iconLike("://resources/like-icon");
//	likeButton->setIcon(iconLike);
//	commentButton->setMaximumWidth(100);
//	QIcon iconComment("://resources/comment-icon");
//	commentButton->setIcon(iconComment);
//	hboxLayout->addWidget(likeButton);
//	hboxLayout->addWidget(commentButton);

//	// Add the picture label and the QHBoxLayout to the original QVBoxLayout
//	postLayout->addWidget(pictureLabel);
//	postLayout->setAlignment(pictureLabel, Qt::AlignHCenter);
//	postLayout->addLayout(hboxLayout);

	vbox->insertWidget(0, new PostWidget(post));
}

void NewsFeed::deleteAllPosts()
{
	//delete all posts
	for (int i = 0; i < vbox->count(); ++i) {
		QLayoutItem* item = vbox->itemAt(i);
		QWidget* widget = item->widget();
		if (widget) {
			delete widget;
		}
	}
}

void NewsFeed::createFeedForUser(User *user)
{
	currentUser = user;
	//add initial posts
	refreshNewsFeed();
}

void NewsFeed::createProfileFeed(User* user)
{
	currentUser = user;
	refreshProfileFeed();
}

void NewsFeed::refreshNewsFeed()
{
	deleteAllPosts();

	//show any posts that can be shown (as per visibility rules of users)
	for (Post* post: Post::allPosts)
		if (post->isVisibleToUser(currentUser)){
			if(!isPostInFeed(post))
				addPost(post);
		}

}

void NewsFeed::refreshProfileFeed()
{
	deleteAllPosts();

	//show any posts that belong to us
	for (Post* post: Post::allPosts)
		if (post->getPoster() == currentUser){
			if(!isPostInFeed(post))
				addPost(post);
		}

}


