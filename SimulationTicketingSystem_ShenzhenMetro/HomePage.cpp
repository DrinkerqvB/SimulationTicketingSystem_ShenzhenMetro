#include "HomePage.h"

HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::HomePageClass())
{
	ui->setupUi(this);
	lineMap = QPixmap(":/images/SZMetroMap/SZMetroMap.jpg");
	//ui->textEdit_linesMap->
}

HomePage::~HomePage()
{
	delete ui;
}

