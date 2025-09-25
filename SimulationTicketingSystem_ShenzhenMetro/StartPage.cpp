#include "StartPage.h"

StartPage::StartPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::StartPageClass())
{
	ui->setupUi(this);
}

StartPage::~StartPage()
{
	delete ui;
}


void StartPage::on_pushButton_enterSystem_clicked(void)
{
	//stackedWidget->setCurrentWidget(homePage);
	emit enterSystem();
}

void StartPage::on_pushButton_exitSystem_clicked(void)
{
	emit exitSystem();
}
