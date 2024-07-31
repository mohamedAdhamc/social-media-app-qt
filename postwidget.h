#ifndef POSTWIDGET_H
#define POSTWIDGET_H

#include <QWidget>
#include "post.h"
#include <QLabel>

class PostWidget : public QWidget
{
	Q_OBJECT

	Post* postData;

public:
	explicit PostWidget(Post* postData);

	Post *getPostData() const;

signals:

};

#endif // POSTWIDGET_H
