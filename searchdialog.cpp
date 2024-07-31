#include "searchdialog.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QStringListModel>
#include <QMessageBox>
#include "user.h"
#include "mainwindow.h"

SearchDialog::SearchDialog()
{
	setWindowTitle("Search Dialog");

	QVBoxLayout* layout = new QVBoxLayout(this);

	QWidget* topWidget = new QWidget(this);
	QHBoxLayout* topLayout = new QHBoxLayout(topWidget);

	textEdit = new QTextEdit(topWidget);
	QPushButton* searchButton = new QPushButton(topWidget);
	searchButton->setIcon(QIcon(":/resources/search-icon.png"));  // Replace with the path to your search icon
	searchButton->setFixedSize(32, 32);  // Set the size of the search button

	topLayout->addWidget(textEdit);
	topLayout->addWidget(searchButton);

	listView = new QListWidget(this);

	layout->addWidget(topWidget);
	layout->addWidget(listView);

	connect(searchButton, &QPushButton::clicked, this, &SearchDialog::searchButtonClicked);
	connect(listView, &QListWidget::itemClicked, this, &SearchDialog::onUserClicked);
	//QListWidgetItem*
}

void SearchDialog::searchButtonClicked()
{
	QString searchText = textEdit->toPlainText();
	listView->clear();
	//loop over all users and if the username contains this string then show it
	for (User* user: User::allUsers)
		if (user->getUserName().find(searchText.toStdString()) != std::string::npos)
			listView->addItem(QString::fromStdString(user->getUserName()));
}

void SearchDialog::onUserClicked(QListWidgetItem* item)
{
	//create a dialog that has a button called follow
	QMessageBox::StandardButton response = QMessageBox::question(
		this,
		"Follow User",
		"Follow " + item->text() + "?",
		QMessageBox::Yes | QMessageBox::No
	);

	if (response == QMessageBox::Yes){
		User* user = User::getUserFromUsername(item->text().toStdString());
		if (user == nullptr){
			QMessageBox msgBox(QMessageBox::Information, "Error", "User doesn't exist");
			msgBox.exec();
			return;
		}
		MainWindow::currentUser->follow(user);
		user->addFollower(MainWindow::currentUser);
	}
}
