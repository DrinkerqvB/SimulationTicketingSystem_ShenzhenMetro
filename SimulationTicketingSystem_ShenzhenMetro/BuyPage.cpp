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

