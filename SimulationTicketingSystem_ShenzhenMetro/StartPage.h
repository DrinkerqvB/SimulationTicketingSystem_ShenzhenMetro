#pragma once

#include <QWidget>
#include "ui_StartPage.h"

#define INDEX_OF_STARTPAGE 0

QT_BEGIN_NAMESPACE
namespace Ui { class StartPageClass; };
QT_END_NAMESPACE

class StartPage : public QWidget
{
	Q_OBJECT

public:
	StartPage(QWidget *parent = nullptr);
	~StartPage();

private:
	Ui::StartPageClass *ui;


signals:
	void enterSystem(void);
	void exitSystem(void);


private slots:
	void on_pushButton_enterSystem_clicked(void);
	void on_pushButton_exitSystem_clicked(void);



};

