#pragma once

#include <QWidget>
#include "ui_StartPage.h"

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
	void StartPage_enterSystem(void);


private slots:
	void on_pushButton_enterSystem_clicked(void);
	void on_pushButton_exitSystem_clicked(void);



};

