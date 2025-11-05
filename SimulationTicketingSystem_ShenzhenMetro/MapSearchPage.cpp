#include "MapSearchPage.h"

MapSearchPage::MapSearchPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::MapSearchPageClass())
{
	ui->setupUi(this);
}

MapSearchPage::~MapSearchPage()
{
	delete ui;
}


void MapSearchPage::on_pushButton_search_clicked(void)
{
	emit searchLines(ui->lineEdit_stationName->text());
}

void MapSearchPage::on_pushButton_buyTicket_clicked(void)
{
	emit gotoBuyPage();
}

void MapSearchPage::on_pushButton_returnHome_clicked(void)
{
	emit returnHome();
}

void MapSearchPage::receiveAndShowStationLines(QStringList stationLines)
{
	QString answer;
	answer = stationLines.join("  ");
	ui->lineEdit_answerLinesName->clear();
	ui->lineEdit_answerLinesName->setText(answer);
}

