#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class User;

class MessageDialog : public QDialog
{
	QListWidget* listWidget;
	QTextEdit* textEdit;

	User *sender, *reciever;

public:
	MessageDialog(User* sender, User* reciever);

private slots:
	void addMessage();
};

#endif // MESSAGEDIALOG_H
