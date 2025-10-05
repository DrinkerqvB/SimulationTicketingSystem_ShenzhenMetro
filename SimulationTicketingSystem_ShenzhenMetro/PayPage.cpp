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

void PayPage::on_pushButton_cancelPay_clicked(void)
{
	emit cancelPay();
}

//void PayPage::setCostCalculator(PaymentCalculation* costCalculator)
//{
//	this->costCalculator = costCalculator;
//}
