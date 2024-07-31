#include "commentdialog.h"
#include "post.h"
#include "mainwindow.h"

CommentDialog::CommentDialog(Post *post)
{
	this->post = post;
	QVBoxLayout* layout = new QVBoxLayout;

	// Viewer for displaying comments
	listWidget = new QListWidget;
	listWidget->setStyleSheet("QListWidget::item { border: 1px solid black; }");
	layout->addWidget(listWidget);

	for (const std::string &comm:  post->getComments())
		listWidget->addItem(QString::fromStdString(comm));

	// Area to write a new comment
	textEdit = new QTextEdit;
	layout->addWidget(textEdit);

	// Button to add the new comment
	QPushButton* addButton = new QPushButton("Add Comment");
	connect(addButton, &QPushButton::clicked, this, &CommentDialog::addComment);
	layout->addWidget(addButton);

	setLayout(layout);
}

void CommentDialog::addComment()
{
	QString comment = textEdit->toPlainText();
	if (!comment.isEmpty()) {
		std::string formattedComment = MainWindow::currentUser->getUserName() + ": " + comment.toStdString();
		post->addComment(formattedComment);
		listWidget->addItem(QString::fromStdString(formattedComment));
		textEdit->clear();
	}
}
