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
	this->metroLineGroup = metroLineGroup;
	for (int i = 0; i < NUM_OF_METROLINES; i++) {
		ui->comboBox_startLine->addItem(metroLineGroup[i].lineName);
		ui->comboBox_endLine->addItem(metroLineGroup[i].lineName);
	}
}

void BuyPage::on_comboBox_startLine_currentTextChanged(const QString& text)
{
	int index = -1;
	do {
		index++;
	} while (metroLineGroup[index].lineName != text);
	ui->comboBox_startStation->clear();
	ui->comboBox_startStation->addItems(metroLineGroup[index].lineStations);
}

void BuyPage::on_comboBox_endLine_currentTextChanged(const QString& text)
{
	int index = -1;
	do {
		index++;
	} while (metroLineGroup[index].lineName != text);
	ui->comboBox_endStation->clear();
	ui->comboBox_endStation->addItems(metroLineGroup[index].lineStations);
}


//void BuyPage::setCostCalculator(PaymentCalculation* costCalculator)
//{
//	this->costCalculator = costCalculator;
//}

void BuyPage::connectToPaymentCalculation(void)
{
	emit stationChanged(ui->comboBox_startLine->currentText(),
		ui->comboBox_startStation->currentText(),
		ui->comboBox_endLine->currentText(),
		ui->comboBox_endStation->currentText(),
		ui->spinBox_numOfTicket->value(),
		ui->checkBox_isBusiness->isChecked()
	);
}

void BuyPage::on_comboBox_startStation_currentTextChanged(const QString& text)
{
	connectToPaymentCalculation();
}

void BuyPage::on_comboBox_endStation_currentTextChanged(const QString& text)
{
	connectToPaymentCalculation();
}

void BuyPage::on_spinBox_numOfTicket_valueChanged(int i)
{
	connectToPaymentCalculation();
}

void BuyPage::on_checkBox_isBusiness_toggled(bool checked)
{
	connectToPaymentCalculation();
}

void BuyPage::receivePrice(float singlePrice, float totalPrice)
{
	ui->lineEdit_singleCost->setText(QString::number(singlePrice,'f',2));
	ui->lineEdit_totalCost->setText(QString::number(totalPrice, 'f', 2));
}
