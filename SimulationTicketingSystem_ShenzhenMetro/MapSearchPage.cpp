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

