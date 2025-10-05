#include "BuyPage.h"

BuyPage::BuyPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::BuyPageClass())
{
	ui->setupUi(this);

	
}

BuyPage::~BuyPage()
{
	delete ui;
}


void BuyPage::on_pushButton_gotoPayPage_clicked(void)
{
	emit gotoPayPage();
}

void BuyPage::on_pushButton_returnHomePage_clicked(void)
{
	emit returnHomePage();
}

void BuyPage::loadComboBox(MetroLine* metroLineGroup)
{

}

