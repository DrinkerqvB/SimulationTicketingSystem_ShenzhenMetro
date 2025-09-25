#pragma once

#include <QWidget>
#include "ui_HomePage.h"
#include <QGraphicsPixmapItem>

#define INDEX_OF_HOMEPAGE 1

QT_BEGIN_NAMESPACE
namespace Ui { class HomePageClass; };
QT_END_NAMESPACE

class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = nullptr);
	~HomePage();

private:
	Ui::HomePageClass *ui;
	QPixmap* linesMap;
	QGraphicsPixmapItem* linesMap_pixmapItem;
	QGraphicsScene* scene_map;


signals:


private slots:


};

