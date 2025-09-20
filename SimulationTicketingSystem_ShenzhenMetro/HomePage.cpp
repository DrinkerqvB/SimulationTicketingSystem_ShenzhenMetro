#include "HomePage.h"

HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::HomePageClass())
{
	ui->setupUi(this);
	lineMap = QPixmap(":/images/SZMetroMap/SZMetroMap.jpg");
	
}

HomePage::~HomePage()
{
	delete ui;
}

