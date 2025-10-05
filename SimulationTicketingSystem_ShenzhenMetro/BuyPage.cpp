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
	ui->comboBox_startStation->addItems(metroLineGroup[index].lineStations);
}

void BuyPage::on_comboBox_endLine_currentTextChanged(const QString& text)
{
	int index = -1;
	do {
		index++;
	} while (metroLineGroup[index].lineName != text);
	ui->comboBox_endStation->addItems(metroLineGroup[index].lineStations);
}

