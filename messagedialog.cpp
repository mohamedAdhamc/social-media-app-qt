#include "messagedialog.h"
#include "user.h"

MessageDialog::MessageDialog(User* sender, User* reciever)
{
	this->sender = sender;
	this->reciever = reciever;
	QVBoxLayout* layout = new QVBoxLayout;

	// Viewer for displaying messages
	listWidget = new QListWidget;
	listWidget->setStyleSheet("QListWidget::item { border: 1px solid black; }");
	layout->addWidget(listWidget);

	for (std::string message:  sender->getMessages(reciever))
		listWidget->addItem(QString::fromStdString(message));

	// Area to write a new comment
	textEdit = new QTextEdit;
	layout->addWidget(textEdit);

	// Button to add the new comment
	QPushButton* addButton = new QPushButton("Send messsage");
	connect(addButton, &QPushButton::clicked, this, &MessageDialog::addMessage);
	layout->addWidget(addButton);

	setLayout(layout);

}

void MessageDialog::addMessage()
{
	QString message = textEdit->toPlainText();
	if (!message.isEmpty()) {
		std::string formattedM = sender->getUserName() +  ": "+ message.toStdString();
		sender->sendMessage(reciever->getUserName(), formattedM);
		listWidget->addItem(QString::fromStdString(formattedM));
		textEdit->clear();
	}
}
