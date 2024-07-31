#ifndef COMMENTDIALOG_H
#define COMMENTDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class Post;

class CommentDialog : public QDialog
{
private:

	QListWidget* listWidget;
	QTextEdit* textEdit;

	Post* post;

public:
	CommentDialog(Post* post);

private slots:
	void addComment();
};

#endif // COMMENTDIALOG_H
