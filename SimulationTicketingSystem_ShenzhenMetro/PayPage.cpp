#include "PayPage.h"

PayPage::PayPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::PayPageClass())
{
	ui->setupUi(this);
}

PayPage::~PayPage()
{
	delete ui;
}

