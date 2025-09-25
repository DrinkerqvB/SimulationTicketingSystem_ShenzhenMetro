#include "HomePage.h"

HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::HomePageClass())
{
	ui->setupUi(this);

	linesMap = new QPixmap(":/images/SZMetroMap/SZMetroMap.jpg");
	linesMap_pixmapItem = new QGraphicsPixmapItem(*linesMap);

	linesMap_pixmapItem->setScale(0.16);

	scene_map = new QGraphicsScene;
	scene_map->addItem(linesMap_pixmapItem);

	ui->graphicsView_linesMap->setScene(scene_map);
	ui->graphicsView_linesMap->show();
}

HomePage::~HomePage()
{
	delete ui;
}

