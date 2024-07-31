#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "newsfeed.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	static User* currentUser;

	QPixmap* getPicFromUser();

private:
	Ui::MainWindow *ui;
	NewsFeed* feed;
	//posts in profile page
	NewsFeed* profileFeed;


	void initHomePage();
	void initSignupPage();
	void initLoginPage();
	void initProfilePage();
	void initSettingsPage();
	void initMessagePage();

	void updateProfileLabels();


private slots:
	void onLogInPressed();
	void onSignUpPressed();
	void onAddPost();
	void onSendMessage();
	void onSearch();
};
#endif // MAINWINDOW_H
