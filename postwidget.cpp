#include "postwidget.h"
#include <QPushButton>
#include <QBoxLayout>
#include "mainwindow.h"
#include "commentdialog.h"


Post *PostWidget::getPostData() const
{
	return postData;
}

//ToDo: add the diff widget parents here to avoid mem leaks
PostWidget::PostWidget(Post *postData)
{
	this->postData = postData;

	//testing to see if layout can be safely added here
	QVBoxLayout* postLayout = new QVBoxLayout(this);

	// Create the picture label and set the image
	QLabel* pictureLabel = new QLabel;
	QPixmap picturePixmap(*(postData->getPicture()));
	pictureLabel->setPixmap(picturePixmap);
	//set a max size for the label
	pictureLabel->setMaximumSize(400 , 350);
	pictureLabel->setScaledContents(true);

	// Create the QHBoxLayout for the second element
	QHBoxLayout* hboxLayout = new QHBoxLayout;
	// Add widgets to the QHBoxLayout
	QPushButton* likeButton = new QPushButton;
	QLabel* likeNum = new QLabel(QString::number(postData->getNumLikes()));
	likeNum->setAlignment(Qt::AlignRight);
	likeNum->setStyleSheet("border: 1px solid black;");
	QObject::connect(likeButton, &QPushButton::clicked , [=]() {
		//like method handles double like
		postData->like(MainWindow::currentUser);
		likeNum->setText(QString::number(postData->getNumLikes()));
	});

	QPushButton* commentButton = new QPushButton;

	QObject::connect(commentButton, &QPushButton::clicked , [=]() {
		CommentDialog* comments = new CommentDialog(postData);
		comments->exec();
		delete comments;
	});

	QHBoxLayout* likeBox = new QHBoxLayout;
	likeBox->setSpacing(5);
//	likeBox->setContentsMargins(0,0,0,0);

	likeButton->setMaximumWidth(100);
	likeNum->setMaximumWidth(50);
	QIcon iconLike("://resources/like-icon");
	likeButton->setIcon(iconLike);
	likeBox->addWidget(likeNum);
	likeBox->addWidget(likeButton);
	commentButton->setMaximumWidth(100);
	QIcon iconComment("://resources/comment-icon");
	commentButton->setIcon(iconComment);
	hboxLayout->addLayout(likeBox);
	hboxLayout->addWidget(commentButton);

	// Add the picture label and the QHBoxLayout to the original QVBoxLayout
	postLayout->addWidget(pictureLabel);
	postLayout->setAlignment(pictureLabel, Qt::AlignHCenter);
	postLayout->addLayout(hboxLayout);

}
