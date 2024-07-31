#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

class QTextEdit;
class QListWidget;
class QListWidgetItem;

class SearchDialog : public QDialog
{

	QTextEdit* textEdit;
	QListWidget* listView;

public:
	SearchDialog();

private slots:
	void searchButtonClicked();
	void onUserClicked(QListWidgetItem *item);

};

#endif // SEARCHDIALOG_H
