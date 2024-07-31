#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QStackedWidget>
#include <iostream>
#include <QDir>
#include <QScrollArea>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include "messagedialog.h"
#include "searchdialog.h"

//GLOBALS//
//initial posts
std::vector<QPixmap*> initialPosts;

// DEFINITNIONS //

User* MainWindow::currentUser = nullptr;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->stackedWidget->setCurrentWidget(ui->sign_up);

	initHomePage();
	initSignupPage();
	initLoginPage();
	initSettingsPage();
	initProfilePage();
	initMessagePage();

}

MainWindow::~MainWindow()
{
	delete ui;
}

QPixmap *MainWindow::getPicFromUser()
{
	QString fileName = QFileDialog::getOpenFileName(
		this, "Select Picture File", "", "Image Files (*.png *.jpg *.jpeg)");

	if (!fileName.isEmpty()) {
		QPixmap* pixmap = new QPixmap(fileName);
		if (!pixmap->isNull()) {
			return pixmap;
		}
	}

	return nullptr;
}

void MainWindow::initHomePage()
{
	QPushButton* message = ui->messageButton;
	QPushButton* profile = ui->profileButton;
	QPushButton* settings = ui->settingsButton;
	QPushButton* addPost = ui->addPostButton;
	QPushButton* search = ui->searchButton;
	//connect button signals
	QObject::connect(message, &QPushButton::clicked, [=]() {
		ui->MinboxListWidget->clear();
		for (std::string messagee: currentUser->getNamesOfMessagees())
			ui->MinboxListWidget->addItem(QString::fromStdString(messagee));
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->messages);
	});
	QObject::connect(profile, &QPushButton::clicked, [=]() {
		updateProfileLabels();
		profileFeed->refreshProfileFeed();
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->profile);
	});
	QObject::connect(settings, &QPushButton::clicked, [=]() {
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->settings);
	});

	QObject::connect(addPost, &QPushButton::clicked, this, &MainWindow::onAddPost);

	QObject::connect(search, &QPushButton::clicked, this, &MainWindow::onSearch);

	QScrollArea* feedScrollArea = ui->newsFeed;
	feed = new NewsFeed(ui->newsFeed);
	feedScrollArea->setWidget(feed);

	if (initialPosts.empty()){
		initialPosts = {  new QPixmap(QString::fromStdString("://resources/post1")),
						  new QPixmap(QString::fromStdString("://resources/post2")),
						  new QPixmap(QString::fromStdString("://resources/post3"))};
	}

	//add initial posts
	feed->addPost(new Post(new User("momo", "3"), new QPixmap(*initialPosts[0]), "my first post"));
	feed->addPost(new Post(new User("desert_fox", ""), new QPixmap(*initialPosts[1]), "hmm"));
	feed->addPost(new Post(new User("night_warrior22", ""), new QPixmap(*initialPosts[2]), "funny"));
}

void MainWindow::initSignupPage()
{
	QPushButton* signupButton = ui->SPsignupButton;
	QObject::connect(signupButton, &QPushButton::clicked, this, &MainWindow::onSignUpPressed);

	//alternative log in button
	QPushButton* loginButton = ui->SPloginButton;
	//connect login button signal to method
	QObject::connect(loginButton, &QPushButton::clicked,  [=]() {
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->login);
	});

}

void MainWindow::initLoginPage()
{
	QPushButton* login = ui->LloginButton;
	QObject::connect(login , &QPushButton::clicked, this, &MainWindow::onLogInPressed);

	//alternative signup button
	QPushButton* signup =  ui->LsignupButton;
	QObject::connect(signup, &QPushButton::clicked, [=]() {
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->sign_up);
	});
}

void MainWindow::initProfilePage()
{
	QPushButton* back = ui->profile_back_button;
	QObject::connect(back, &QPushButton::clicked, [=]() {
		feed->refreshNewsFeed();
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->home);
	});
	QScrollArea* profileFeedArea = ui->profileFeed;
	profileFeed = new NewsFeed(ui->profileFeed);
	profileFeedArea->setWidget(profileFeed);
}

void MainWindow::initSettingsPage()
{
	QPushButton* back = ui->settingsBackButton;
	QObject::connect(back, &QPushButton::clicked, [=]() {
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->home);
	});

	QPushButton* signout = ui->signoutButton;
	QObject::connect(signout, &QPushButton::clicked, [=]() {
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Question);
		msgBox.setText("Are you sure you want to sign out?");
		msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::No);
		int response = msgBox.exec();

		// Process the user's response
		if (response == QMessageBox::Yes) {
			QStackedWidget* stack = ui->stackedWidget;
			stack->setCurrentWidget(ui->login);
		}
	});

	QComboBox* a = ui->followPrivacy;
	QComboBox* b = ui->postVIsibility;
	QComboBox* c = ui->shownPosts;
	a->addItem("All");
	a->addItem("Friends of friends only");
	a->setCurrentIndex(0);

	b->addItem("All");
	b->addItem("Friends only");
	b->setCurrentIndex(0);

	c->addItem("All");
	c->addItem("Friends only");
	c->setCurrentIndex(0);
}

void MainWindow::initMessagePage()
{
	//back button
	QPushButton* back = ui->MbackButton;
	QObject::connect(back, &QPushButton::clicked, [=]() {
		feed->refreshNewsFeed();
		QStackedWidget* stack = ui->stackedWidget;
		stack->setCurrentWidget(ui->home);
	});

	//message is clicked
	// check if user sent to is present
	// send it
	QPushButton* message = ui->MsendMessageButton;
	QObject::connect(message, &QPushButton::clicked, this, &MainWindow::onSendMessage);


	//clear up
	ui->MinboxListWidget->clear();
	//fill up the listview with the names of the people we have messages with
//	for (std::string messagee: currentUser->getNamesOfMessagees())
//		ui->MinboxListWidget->addItem(QString::fromStdString(messagee));

	//show the conversation when we click on any of the conversations we have
	QObject::connect(ui->MinboxListWidget, &QListWidget::itemClicked, [&](QListWidgetItem* item){
		QString userName = item->text();
		User* user = User::getUserFromUsername(userName.toStdString());
		if (user == nullptr){
			QMessageBox msgBox(QMessageBox::Information, "Error", "Username doesn't exist");
			msgBox.exec();
			return;
		}
		//everything is good now create the dialog
		MessageDialog* message = new MessageDialog(currentUser, user);
		message->exec();
		delete message;

	});
}

void MainWindow::updateProfileLabels()
{
	QLabel *followers = ui->numFollowersLabel, *following = ui->numFollowingLabel, *profilePic = ui->profilePicLabel;
	followers->setText(QString::number(currentUser->getfollowers().size()));
	following->setText(QString::number(currentUser->getfollowing().size()));
	ui->usernameLabel->setText(QString::fromStdString(currentUser->getUserName()));
	if (currentUser->getProfilePic() != nullptr)
		profilePic->setPixmap(*currentUser->getProfilePic());
}

void MainWindow::onLogInPressed()
{
	QTextEdit* username = ui->Lusername;
	QTextEdit* password = ui->Lpassword;

	//check if username and password combination is correct
	if (User::passMap.find(username->toPlainText().toStdString()) == User::passMap.end()){
		QMessageBox msgBox(QMessageBox::Information, "Error", "Username doesn't exist");
		msgBox.exec();
		return;
	}

	if (User::passMap[username->toPlainText().toStdString()] !=
			password->toPlainText().toStdString()){
		QMessageBox msgBox(QMessageBox::Information, "Error", "password is incorrect");
		msgBox.exec();
		return;
	}

	currentUser = User::getUserFromUsername(username->toPlainText().toStdString());
	if (currentUser == nullptr){
		QMessageBox msgBox(QMessageBox::Information, "Error", "User doesn't exist");
		msgBox.exec();
		return;
	}

	//update feed
	feed->createFeedForUser(currentUser);
	//update profile page
	profileFeed->createProfileFeed(currentUser);

	updateProfileLabels();

	QStackedWidget* stack = ui->stackedWidget;
	stack->setCurrentWidget(ui->home);
}

void MainWindow::onSignUpPressed()
{
	QTextEdit* username = ui->SPusername;
	QTextEdit* password = ui->SPpassword;
	QTextEdit* passwordConfirm = ui->SPpasswordConfirm;
	//check if username isn't already used
	if (User::passMap.find(username->toPlainText().toStdString()) !=
			User::passMap.end()){
		QMessageBox msgBox(QMessageBox::Information, "Error", "Username is already used.");
		msgBox.exec();
		return;
	}
	//check if passwords dont match
	if (password->toPlainText() != passwordConfirm->toPlainText()){
		QMessageBox msgBox(QMessageBox::Information, "Error", "Passwords don't match");
		msgBox.exec();
		return;
	}

	if (password->toPlainText().toStdString().size() < 4){
		QMessageBox msgBox(QMessageBox::Information, "Error", "Password must contain more than 3 characters");
		msgBox.exec();
		return;
	}

	//Create user == added to allusers and the passMap
	currentUser = new User(username->toPlainText().toStdString(), password->toPlainText().toStdString());

	//update feed
	feed->createFeedForUser(currentUser);
	//update profile page
	profileFeed->createProfileFeed(currentUser);

	//if signup succeded
	QStackedWidget* stack = ui->stackedWidget;
	stack->setCurrentWidget(ui->home);
}

void MainWindow::onAddPost()
{
	//to add a post we need the following info from user
	//1- picture 2- caption

	QPixmap* pic = getPicFromUser();

	if (pic == nullptr){
		QMessageBox msgBox(QMessageBox::Information, "Error", "picture is invalid");
		msgBox.exec();
		return;
	}

	bool ok;
	QString caption = "";
	caption = QInputDialog::getText(this, "Enter Caption", "Caption:", QLineEdit::Normal, "", &ok);

	Post* newPost = new Post(currentUser, pic, caption.toStdString());
	feed->addPost(newPost);
	profileFeed->addPost(newPost);

}

void MainWindow::onSendMessage()
{
	//if username doesnt refer to a use throw an error dialog
	std::string username = ui->Musername->toPlainText().toStdString();

	User* reciever = User::getUserFromUsername(username);

	if (reciever == nullptr){
		QMessageBox msgBox(QMessageBox::Information, "Error", "username doesn't belong to a user");
		msgBox.exec();
		return;
	}

	MessageDialog* message = new MessageDialog(currentUser, reciever);
	message->exec();
	delete message;
	ui->MinboxListWidget->clear();
	for (std::string messagee: currentUser->getNamesOfMessagees())
		ui->MinboxListWidget->addItem(QString::fromStdString(messagee));
}

void MainWindow::onSearch()
{
	SearchDialog* search = new SearchDialog();
	search->exec();
	delete search;
}

